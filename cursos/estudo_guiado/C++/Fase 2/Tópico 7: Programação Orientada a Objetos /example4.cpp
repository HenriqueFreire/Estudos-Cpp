#include <iostream>
#include <string>
#include <algorithm> // Para std::copy

// Este exemplo implementa a "Regra dos Três" para corrigir o bug do example3.

class BufferSimples {
public:
  // 1. Construtor Padrão
  BufferSimples(size_t tamanho) : tamanho_(tamanho), dados_(new int[tamanho]) {
    std::cout << "  [+] BufferSimples(" << tamanho_
              << ") alocado no endereco " << dados_ << " (Construtor)\n";
  }

  // 2. Destrutor (Parte 1 da Regra dos Três)
  ~BufferSimples() {
    std::cout << "  [-] BufferSimples(" << tamanho_
              << ") no endereco " << dados_ << " sendo liberado (Destrutor)\n";
    delete[] dados_;
  }

  // 3. Construtor de Cópia (Parte 2 da Regra dos Três)
  // Chamado em: BufferSimples copia = original;
  BufferSimples(const BufferSimples& outro)
      : tamanho_(outro.tamanho_), dados_(new int[outro.tamanho_]) {
    std::cout << "  [C] Construtor de COPIA chamado. Realizando copia profunda.\n";
    std::cout << "      Novo buffer alocado no endereco " << dados_ << ".\n";
    // Copia o CONTEÚDO da memória, não apenas o ponteiro.
    std::copy(outro.dados_, outro.dados_ + outro.tamanho_, dados_);
  }

  // 4. Operador de Atribuição por Cópia (Parte 3 da Regra dos Três)
  // Chamado em: copia = original; (onde 'copia' já existe)
  BufferSimples& operator=(const BufferSimples& outro) {
    std::cout << "  [=] Operador de ATRIBUICAO por copia chamado.\n";

    // Proteção contra auto-atribuição (ex: b1 = b1;)
    if (this == &outro) {
      return *this;
    }

    // Libera a memória antiga que este objeto possuía.
    delete[] dados_;

    // Aloca nova memória e copia os dados do outro objeto (copia profunda).
    tamanho_ = outro.tamanho_;
    dados_ = new int[tamanho_];
    std::cout << "      Novo buffer alocado no endereco " << dados_ << ".\n";
    std::copy(outro.dados_, outro.dados_ + outro.tamanho_, dados_);

    // Retorna uma referência para o próprio objeto para permitir encadeamento (a = b = c).
    return *this;
  }

  void imprimir() const {
    std::cout << "      Buffer no endereco " << dados_ << " | Tamanho: " << tamanho_ << "\n";
  }

private:
  size_t tamanho_;
  int* dados_;
};

int main() {
  std::cout << "Iniciando o programa.\n\n";

  // 1. Cria um buffer original.
  BufferSimples buffer_original(10);
  std::cout << "Original:\n";
  buffer_original.imprimir();

  std::cout << "\n--- Testando o Construtor de Copia ---\n";
  // 2. Cria uma cópia. Isso invoca o CONSTRUTOR DE CÓPIA.
  BufferSimples buffer_copia = buffer_original;
  std::cout << "Original:\n";
  buffer_original.imprimir();
  std::cout << "Copia:\n";
  buffer_copia.imprimir(); // Agora tem seu próprio endereço de memória!

  std::cout << "\n--- Testando o Operador de Atribuicao ---\n";
  // 3. Cria um terceiro buffer.
  BufferSimples buffer_atribuicao(5); // Tamanho diferente para ver a mudança.
  std::cout << "Buffer para atribuicao (antes):\n";
  buffer_atribuicao.imprimir();
  // 4. Atribui o original a ele. Isso invoca o OPERADOR DE ATRIBUIÇÃO.
  buffer_atribuicao = buffer_original;
  std::cout << "Buffer para atribuicao (depois):\n";
  buffer_atribuicao.imprimir(); // Agora é uma cópia profunda do original.

  std::cout << "\nFim do escopo 'main'. Os destrutores serao chamados para cada objeto...\n";
  // O programa agora terminará sem erros!
  return 0;
}

/*
  Explicação: A Solução com a "Regra dos Três" e Cópia Profunda

  Este exemplo corrige o bug de "double free" do `example3.cpp` implementando
  corretamente a "Regra dos Três".

  1.  **Cópia Profunda (Deep Copy):**
      -   A solução para o problema da cópia superficial é realizar uma "cópia
          profunda". Em vez de apenas copiar o ponteiro, nós alocamos um **novo**
          bloco de memória para o objeto de destino e copiamos o **conteúdo**
          do recurso original para esse novo bloco.
      -   Agora, cada objeto possui e gerencia seu próprio recurso de forma
          independente. Quando um objeto é destruído, ele libera apenas a sua
          própria memória, evitando o erro de "double free".

  2.  **Construtor de Cópia (`BufferSimples(const BufferSimples& outro)`):**
      -   Esta função é chamada quando um **novo** objeto é criado a partir de
          um objeto existente (ex: `BufferSimples copia = original;`).
      -   Nossa implementação aloca um novo `int* dados_` e usa `std::copy` para
          copiar os valores do buffer do `outro` objeto para o novo buffer.

  3.  **Operador de Atribuição por Cópia (`operator=(...)`):**
      -   Esta função é chamada quando um objeto **já existente** recebe o valor
          de outro objeto (ex: `copia = original;`).
      -   A implementação é mais complexa porque o objeto de destino já possui
          um recurso alocado que precisa ser liberado antes de alocar o novo.
      -   **Passos:**
          a.  **Verificar auto-atribuição:** `if (this == &outro)` previne que o
              objeto tente se atribuir a si mesmo, o que levaria à liberação
              prematura de sua própria memória.
          b.  **Liberar recurso antigo:** `delete[] dados_;` libera a memória
              que o objeto de destino estava gerenciando.
          c.  **Alocar novo recurso e copiar:** Aloca nova memória e copia o
              conteúdo do `outro` objeto, assim como o construtor de cópia.
          d.  **Retornar `*this`:** Permite o encadeamento de atribuições
              (ex: `a = b = c;`).

  **Rumo à "Regra dos Cinco" (C++11):**
  -   Fazer cópias profundas pode ser caro, especialmente para objetos grandes.
      Se você tem um objeto temporário que está prestes a ser destruído, por
      que pagar o custo de copiar seu recurso se você pode simplesmente "roubar"
      o recurso dele?
  -   O C++11 introduziu a "semântica de movimentação" (move semantics) para
      lidar com isso, levando à "Regra dos Cinco", que adiciona o **Construtor
      de Movimentação** e o **Operador de Atribuição por Movimentação**.
  -   Veremos isso em um próximo exemplo.

  **Implicações para HFT:**
  -   Entender a "Regra dos Três/Cinco" é absolutamente essencial para escrever
      código C++ seguro e correto.
  -   Embora em HFT se evite cópias de dados pesados em caminhos críticos,
      saber como gerenciar recursos manualmente de forma correta é um
      conhecimento fundamental.
  -   A "Regra do Zero" (usar classes RAII como `std::vector` ou
      `std::unique_ptr` para gerenciar recursos) ainda é a abordagem preferida
      para evitar ter que escrever tudo isso manualmente.
*/