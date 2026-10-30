#include <iostream>
#include <vector>
#include <string>
#include <new> // Necessário para std::bad_alloc e ::operator new

// --- 1. Empty Base Optimization (EBO) ---

// Um alocador customizado vazio. Não tem membros de dados.
template <typename T>
struct AlocadorVazio {
  using value_type = T;
  T* allocate(size_t n) { return static_cast<T*>(::operator new(n * sizeof(T))); }
  void deallocate(T* p, size_t) noexcept { ::operator delete(p); }
};

// Classe que NÃO usa EBO.
// O membro 'alocador_' ocupa pelo menos 1 byte, mesmo sendo vazio.
template <typename T, typename Allocator>
class ListaSemEBO {
private:
  T* dados_;
  Allocator alocador_; // Ocupa espaço
public:
  // ... implementação ...
};

// Classe que USA EBO.
// Herdar de um tipo sem membros de dados geralmente não aumenta o tamanho da classe.
template <typename T, typename Allocator>
class ListaComEBO : private Allocator { // Herda do alocador
private:
  T* dados_;
public:
  // ... implementação ...
};


// --- 2. Exemplo de Alocador de Arena (Arena Allocator) ---

// Um alocador de arena simples e não thread-safe para fins de demonstração.
// Pré-aloca um grande bloco de memória e serve pedaços dele rapidamente.
class Arena {
  static constexpr size_t TAMANHO_ARENA = 1024 * 1024; // 1 MB
  char* buffer_;
  char* ponteiro_atual_;

public:
  Arena() : buffer_(new char[TAMANHO_ARENA]), ponteiro_atual_(buffer_) {
    std::cout << "  [+] Arena de 1MB criada.\n";
  }
  ~Arena() {
    delete[] buffer_;
    std::cout << "  [-] Arena destruída.\n";
  }

  // Proíbe cópias para simplificar o gerenciamento de posse.
  Arena(const Arena&) = delete;
  Arena& operator=(const Arena&) = delete;

  void* alocar(size_t bytes) {
    // Alinhamento simples para garantir que os ponteiros sejam válidos.
    size_t espaco_restante = buffer_ + TAMANHO_ARENA - ponteiro_atual_;
    if (bytes > espaco_restante) {
      throw std::bad_alloc();
    }
    void* resultado = ponteiro_atual_;
    ponteiro_atual_ += bytes;
    return resultado;
  }

  void reset() { ponteiro_atual_ = buffer_; }
};

// Um alocador compatível com a STL que usa nossa Arena.
template <typename T>
class AlocadorDeArena {
public:
  using value_type = T;
  Arena* arena_; // Ponteiro para a arena que será usada.

  AlocadorDeArena(Arena& arena) noexcept : arena_(&arena) {}

  // Construtor de template para permitir que contêineres rebindem o alocador.
  template <typename U>
  AlocadorDeArena(const AlocadorDeArena<U>& outro) noexcept : arena_(outro.arena_) {}

  T* allocate(size_t n) {
    return static_cast<T*>(arena_->alocar(n * sizeof(T)));
  }

  void deallocate(T* p, size_t n) noexcept {
    // O alocador de arena não desaloca individualmente, então esta função não faz nada.
    // A memória é liberada de uma só vez quando a arena é destruída ou resetada.
  }
};

// Operador de igualdade necessário para alocadores STL.
template <typename T, typename U>
bool operator==(const AlocadorDeArena<T>& a, const AlocadorDeArena<U>& b) {
    return a.arena_ == b.arena_;
}
template <typename T, typename U>
bool operator!=(const AlocadorDeArena<T>& a, const AlocadorDeArena<U>& b) {
    return a.arena_ != b.arena_;
}


int main() {
  std::cout << "--- 1. Demonstrando Empty Base Optimization (EBO) ---\n";
  AlocadorVazio<int> alocador_vazio;
  std::cout << "Tamanho de um alocador vazio: " << sizeof(alocador_vazio) << " byte\n";
  std::cout << "Tamanho de ListaSemEBO: " << sizeof(ListaSemEBO<int, AlocadorVazio<int>>) << " bytes\n";
  std::cout << "Tamanho de ListaComEBO: " << sizeof(ListaComEBO<int, AlocadorVazio<int>>) << " bytes (menor!)\n";

  std::cout << "\n--- 2. Usando o Alocador de Arena ---\n";
  Arena minha_arena;
  // Cria um std::vector que usará nossa arena para todas as suas alocações de memória.
  std::vector<int, AlocadorDeArena<int>> vetor_na_arena{AlocadorDeArena<int>(minha_arena)};

  // Adiciona esta linha para pré-reservar a capacidade e evitar múltiplas realocações.
  vetor_na_arena.reserve(100000);

  std::cout << "  Inserindo 100.000 inteiros no vetor...\n";
  for (int i = 0; i < 100000; ++i) {
    vetor_na_arena.push_back(i); // Alocações rápidas, sem chamar 'new' repetidamente.
  }
  std::cout << "  Capacidade do vetor: " << vetor_na_arena.capacity() << "\n";
  std::cout << "  Tamanho do vetor: " << vetor_na_arena.size() << "\n";

  std::cout << "\nFim do programa. A arena sera destruida, liberando toda a memoria de uma vez.\n";
  return 0;
}

/* 
    Explicação: EBO e Alocadores Customizados


  Este exemplo introduz dois conceitos avançados de gerenciamento de memória, cruciais para otimizações de baixo nível.


   1. Empty Base Optimization (EBO):
       * O Problema: Em C++, mesmo uma classe ou struct sem membros de dados deve ter um tamanho de pelo menos 1 byte. Isso garante que dois objetos diferentes tenham
         endereços de memória diferentes. Se você tem uma classe que contém um membro que é um objeto de uma classe vazia (como um alocador sem estado), esse membro ocupará 1
         byte desnecessariamente.
       * A Solução: O compilador C++ pode aplicar uma otimização chamada EBO. Se você herdar de uma classe base que não tem membros de dados, o compilador pode otimizar o
         layout de memória para que a classe base não ocupe nenhum espaço extra no objeto derivado.
       * Aplicação: É uma técnica comum usada em implementações da STL. std::vector, por exemplo, pode herdar de seu alocador para economizar espaço se o alocador for um tipo
         vazio.


   2. Alocadores Customizados (Custom Allocators):
       * O Problema: O alocador padrão do C++ (::operator new) é de propósito geral. Ele precisa ser thread-safe e lidar com alocações de todos os tamanhos, o que o torna
         relativamente lento e uma fonte de contenção em sistemas multithreaded. Para HFT, essa latência e contenção são inaceitáveis.
       * A Solução: A STL permite que você forneça seu próprio alocador para os contêineres. Um alocador é uma classe que encapsula a estratégia de gerenciamento de memória.
       * Alocador de Arena (Arena Allocator): O exemplo demonstra um alocador de arena (também chamado de "region-based" ou "linear allocator").
           * Como Funciona: Ele pré-aloca um grande bloco de memória (a "arena") de uma só vez. Cada chamada a allocate simplesmente avança um ponteiro dentro desse bloco,
             retornando um pedaço da memória. Isso é extremamente rápido (apenas uma adição de ponteiro).
           * Desalocação: A desalocação individual (deallocate) geralmente não faz nada. A memória inteira é liberada de uma só vez quando a arena é destruída ou "resetada".
           * Uso: Ideal para tarefas que fazem muitas alocações pequenas e cuja vida útil é bem definida (ex: processar uma mensagem de rede, construir uma cena em um frame
             de jogo).

  Implicações para HFT:


   * EBO: É uma micro-otimização, mas em HFT, cada byte conta. Reduzir o tamanho de objetos pode melhorar a utilização do cache da CPU, levando a um código mais rápido.
   * Alocadores Customizados: Este é um tópico fundamental em HFT. Substituir o alocador padrão por um alocador de arena ou um "pool allocator" (que gerencia blocos de
     tamanho fixo) é uma das otimizações mais importantes para alcançar latência baixa e determinística, eliminando o overhead e a imprevisibilidade do new padrão.

*/