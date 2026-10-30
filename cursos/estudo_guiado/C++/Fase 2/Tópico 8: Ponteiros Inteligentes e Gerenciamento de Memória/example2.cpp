#include <iostream>
#include <memory> // Para std::shared_ptr, std::weak_ptr, std::make_shared
#include <string>
#include <vector>

// Classe base para nossos exemplos
class Entidade {
public:
  Entidade(const std::string& nome) : nome_(nome) {
    std::cout << "  [+] Entidade '" << nome_ << "' criada.\n";
  }
  ~Entidade() {
    std::cout << "  [-] Entidade '" << nome_ << "' destruída.\n";
  }
  std::string getNome() const { return nome_; }

  // Membros para demonstrar ciclos de referência
  std::shared_ptr<Entidade> parceiro_shared;
  std::weak_ptr<Entidade> parceiro_weak;

private:
  std::string nome_;
};

void demonstrarSharedPtr() {
  std::cout << "--- 1. Demonstrando std::shared_ptr ---\n";

  // Cria um shared_ptr. O contador de referência é 1.
  // std::make_shared é preferível a 'new' por ser mais eficiente (uma única alocação).
  std::shared_ptr<Entidade> ptr1 = std::make_shared<Entidade>("Recurso Compartilhado");
  std::cout << "  Contagem de referencia: " << ptr1.use_count() << '\n';

  {
    // Cria um segundo shared_ptr a partir do primeiro.
    std::shared_ptr<Entidade> ptr2 = ptr1;
    std::cout << "  ptr2 criado. Contagem de referencia: " << ptr1.use_count() << '\n';
    std::cout << "  Recurso acessado via ptr2: " << ptr2->getNome() << '\n';
  } // ptr2 sai do escopo, o contador de referência diminui.

  std::cout << "  ptr2 saiu do escopo. Contagem de referencia: " << ptr1.use_count() << '\n';
  // O recurso ainda existe porque ptr1 ainda o possui.
} // ptr1 sai do escopo, o contador vai a 0, e o recurso é destruído.

void demonstrarCicloDeReferencia() {
  std::cout << "\n--- 2. O Perigo: Ciclos de Referencia com std::shared_ptr ---\n";
  // Cria duas entidades
  std::shared_ptr<Entidade> alice = std::make_shared<Entidade>("Alice");
  std::shared_ptr<Entidade> Amelia = std::make_shared<Entidade>("Amelia");

  // Alice aponta para Amelia, e Amelia aponta para Alice.
  alice->parceiro_shared = Amelia;
  Amelia->parceiro_shared = alice;

  std::cout << "  Contagem de Alice: " << alice.use_count() << " (Alice e Amelia)\n";
  std::cout << "  Contagem de Amelia: " << Amelia.use_count() << " (Amelia e Alice)\n";

  std::cout << "  Fim da funcao. 'alice' e 'Amelia' saem do escopo...\n";
} // 'alice' e 'Amelia' saem do escopo. A contagem de cada um vai de 2 para 1.
  // Como a contagem não chega a 0, NENHUM dos dois é destruído.
  // ISSO É UM VAZAMENTO DE MEMÓRIA (MEMORY LEAK)!

void demonstrarWeakPtr() {
  std::cout << "\n--- 3. A Solucao: Usando std::weak_ptr para quebrar ciclos ---\n";
  // Cria duas entidades
  std::shared_ptr<Entidade> carol = std::make_shared<Entidade>("Carol");
  std::shared_ptr<Entidade> david = std::make_shared<Entidade>("David");

  // Carol tem um ponteiro forte para David.
  carol->parceiro_shared = david;
  // David tem um ponteiro FRACO para Carol. Isso não aumenta a contagem de referência.
  david->parceiro_weak = carol;

  std::cout << "  Contagem de Carol: " << carol.use_count() << " (apenas Carol)\n";
  std::cout << "  Contagem de David: " << david.use_count() << " (David e Carol)\n";

  // Para usar um weak_ptr, você deve "travá-lo" (lock) para obter um shared_ptr temporário.
  std::cout << "  David tentando acessar seu parceiro...\n";
  if (auto parceiro = david->parceiro_weak.lock()) {
    // O lock() foi bem-sucedido, o objeto ainda existe.
    std::cout << "    Parceiro de David e: " << parceiro->getNome() << '\n';
    std::cout << "    Contagem de Carol durante o lock: " << carol.use_count() << '\n';
  } else {
    std::cout << "    Parceiro de David nao existe mais.\n";
  }

  std::cout << "  Fim da funcao. 'carol' e 'david' saem do escopo...\n";
} // 1. 'carol' sai do escopo. Contagem de Carol vai a 0. Carol é destruída.
  // 2. Ao destruir Carol, seu 'parceiro_shared' (para David) é destruído.
  // 3. A contagem de David vai a 0. David é destruído.
  // Nenhum vazamento de memória!

int main() {
  demonstrarSharedPtr();
  demonstrarCicloDeReferencia();
  demonstrarWeakPtr();
  return 0;
}

/*
  Explicação: std::shared_ptr e std::weak_ptr

  Este exemplo aborda os ponteiros inteligentes para gerenciamento de memória com
  propriedade compartilhada.

  1.  **std::shared_ptr (Propriedade Compartilhada):**
      -   Permite que múltiplos `shared_ptr`s "possuam" o mesmo objeto alocado
          dinamicamente.
      -   Ele mantém um **bloco de controle** separado que armazena um **contador
          de referência**. Cada vez que um novo `shared_ptr` é criado para o
          mesmo objeto (por cópia), o contador é incrementado. Quando um
          `shared_ptr` é destruído, o contador é decrementado.
      -   O objeto gerenciado só é destruído (com `delete`) quando o contador de
          referência chega a zero.
      -   **`std::make_shared`:** É a forma preferida de criação. É mais
          eficiente porque aloca memória para o objeto e para o bloco de controle
          em uma única operação, melhorando a localidade de cache.

  2.  **O Problema: Ciclos de Referência:**
      -   A grande fraqueza do `shared_ptr` é a possibilidade de ciclos de
          referência. Se o Objeto A tem um `shared_ptr` para o Objeto B, e o
          Objeto B tem um `shared_ptr` para o Objeto A, seus contadores de
          referência nunca chegarão a zero, mesmo quando todas as referências
          externas a eles desaparecerem. Isso resulta em um vazamento de memória.

  3.  **std::weak_ptr (A Solução para Ciclos):**
      -   `std::weak_ptr` é um ponteiro "observador" não-proprietário. Ele aponta
          para um objeto gerenciado por um `shared_ptr`, mas **não incrementa** o
          contador de referência.
      -   Seu principal objetivo é quebrar ciclos de referência. No padrão de
          design "pai-filho", o pai pode ter um `shared_ptr` para o filho, mas o
          filho deve ter apenas um `weak_ptr` para o pai.
      -   **`lock()`:** Como um `weak_ptr` não garante que o objeto ainda exista,
          você não pode acessá-lo diretamente. Você deve chamar o método `lock()`,
          que retorna um `shared_ptr`. Se o objeto ainda existir, o `shared_ptr`
          retornado será válido. Se o objeto já foi destruído, ele será nulo.
          Isso torna o acesso seguro.

  **Implicações para HFT:**
  -   **Custo de Performance do `shared_ptr`:**
      1.  **Contagem Atômica:** O contador de referência deve ser atualizado de
          forma atômica para ser seguro em ambientes multithread. Operações
          atômicas são mais lentas que operações normais, pois exigem
          sincronização entre os núcleos da CPU.
      2.  **Alocação Dupla:** Usar `std::shared_ptr<T>(new T())` resulta em duas
          alocações de memória separadas (uma para `T`, outra para o bloco de
          controle), o que é ruim para a localidade de cache. `std::make_shared`
          mitiga isso, mas o bloco de controle ainda existe.
  -   **Uso em HFT:** Devido a esse overhead, `shared_ptr` é usado com **muita
      cautela** em caminhos de código de baixa latência. `std::unique_ptr` é
      fortemente preferido por ter zero overhead. `shared_ptr` é mais adequado
      para gerenciar o tempo de vida de objetos de nível mais alto, onde a
      flexibilidade da propriedade compartilhada supera o custo de performance.
  -   **`weak_ptr`:** É a ferramenta correta para resolver ciclos, mas o uso de
      `lock()` também tem um custo (uma operação atômica para verificar e
      incrementar o contador). O design do sistema deve, idealmente, evitar
      estruturas de propriedade complexas que exijam `weak_ptr` em caminhos
      críticos.
*/