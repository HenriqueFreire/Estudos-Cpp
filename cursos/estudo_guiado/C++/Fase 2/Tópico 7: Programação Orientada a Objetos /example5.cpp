#include <iostream>
#include <string>
#include <algorithm> // Para std::copy
#include <utility>   // Para std::move

// Este exemplo estende o example4 para implementar a "Regra dos Cinco".

class BufferSimples {
public:
  // 1. Construtor Padrão
  BufferSimples(size_t tamanho) : tamanho_(tamanho), dados_(new int[tamanho]) {
    std::cout << "  [+] CONSTRUTOR PADRAO: Alocado " << tamanho_ << " ints em " << dados_ << "\n";
  }

  // 2. Destrutor
  ~BufferSimples() {
    std::cout << "  [-] DESTRUTOR: Liberando memoria em " << dados_ << "\n";
    delete[] dados_;
  }

  // 3. Construtor de Cópia (Deep Copy)
  BufferSimples(const BufferSimples& outro)
      : tamanho_(outro.tamanho_), dados_(new int[outro.tamanho_]) {
    std::cout << "  [C] CONSTRUTOR DE COPIA (caro): Realizando copia profunda.\n";
    std::copy(outro.dados_, outro.dados_ + outro.tamanho_, dados_);
  }

  // 4. Operador de Atribuição por Cópia (Deep Copy)
  BufferSimples& operator=(const BufferSimples& outro) {
    std::cout << "  [=] OPERADOR DE ATRIBUICAO POR COPIA (caro).\n";
    if (this == &outro) return *this;
    delete[] dados_;
    tamanho_ = outro.tamanho_;
    dados_ = new int[tamanho_];
    std::copy(outro.dados_, outro.dados_ + outro.tamanho_, dados_);
    return *this;
  }

  // --- NOVAS FUNÇÕES DO C++11 (REGRA DOS CINCO) ---

  // 5. Construtor de Movimentação (Move Constructor)
  // Recebe uma referência r-value (&&), indicando um objeto temporário.
  BufferSimples(BufferSimples&& outro) noexcept
      : tamanho_(0), dados_(nullptr) { // Inicializa o estado atual
    std::cout << "  [M] CONSTRUTOR DE MOVIMENTACAO (barato): 'Roubando' recursos.\n";
    // Troca os ponteiros e tamanhos. 'outro' ficará com nosso nullptr.
    tamanho_ = outro.tamanho_;
    dados_ = outro.dados_;

    // Deixa o objeto 'outro' em um estado válido, mas vazio.
    // Isso é CRUCIAL para que o destrutor de 'outro' não libere a memória que roubamos.
    outro.tamanho_ = 0;
    outro.dados_ = nullptr;
  }

  // 6. Operador de Atribuição por Movimentação (Move Assignment)
  BufferSimples& operator=(BufferSimples&& outro) noexcept {
    std::cout << "  [=M] OPERADOR DE ATRIBUICAO POR MOVIMENTACAO (barato).\n";
    if (this == &outro) return *this;

    // Libera o recurso que este objeto já possuía.
    delete[] dados_;

    // Rouba os recursos do objeto 'outro'.
    tamanho_ = outro.tamanho_;
    dados_ = outro.dados_;

    // Deixa 'outro' em um estado válido e vazio.
    outro.tamanho_ = 0;
    outro.dados_ = nullptr;

    return *this;
  }

  void imprimir() const {
    std::cout << "      Buffer em " << dados_ << " | Tamanho: " << tamanho_ << '\n';
  }

private:
  size_t tamanho_;
  int* dados_;
};

// Uma função que cria e retorna um Buffer. O compilador sabe que o retorno
// é um objeto temporário (r-value).
BufferSimples criarBuffer(size_t tamanho) {
  std::cout << "\n--- Entrando na funcao criarBuffer ---\n";
  BufferSimples b(tamanho);
  std::cout << "--- Saindo da funcao criarBuffer ---\n";
  return b;
}

int main() {
  std::cout << "--- 1. Testando o Construtor de Movimentacao ---\n";
  // criarBuffer(10) retorna um objeto temporário (r-value).
  // O compilador escolhe o Construtor de Movimentação em vez do de Cópia.
  BufferSimples b1 = criarBuffer(10);
  b1.imprimir();

  std::cout << "\n--- 2. Testando o Operador de Atribuicao por Movimentacao ---\n";
  BufferSimples b2(5); // Cria um buffer menor.
  std::cout << "b2 antes da movimentacao:\n";
  b2.imprimir();
  // Atribuímos um temporário a b2. O Operador de Atribuição por Movimentação é chamado.
  b2 = criarBuffer(20);
  std::cout << "b2 depois da movimentacao:\n";
  b2.imprimir();

  std::cout << "\n--- 3. Forcando a movimentacao com std::move ---\n";
  BufferSimples b3(50);
  std::cout << "b3 antes de std::move:\n";
  b3.imprimir();
  // std::move transforma b3 em um r-value, permitindo que o construtor de
  // movimentação seja usado.
  BufferSimples b4 = std::move(b3);
  std::cout << "b4 (que recebeu b3):\n";
  b4.imprimir();
  std::cout << "b3 apos ter sido movido (estado vazio e valido):\n";
  b3.imprimir(); // b3 agora está "vazio".

  std::cout << "\nFim do escopo 'main'.\n";
  return 0;
}


/*
  Explicação: A "Regra dos Cinco" e a Semântica de Movimentação

  Este exemplo completa nosso gerenciamento de recursos com a "Regra dos Cinco",
  uma extensão da "Regra dos Três" para C++11 e além.

  1.  **O Problema da Cópia:**
      -   Como vimos, a cópia profunda (deep copy) funciona, mas pode ser cara.
          Ela sempre aloca nova memória e copia todo o conteúdo.
      -   Considere a função `criarBuffer`. Ela cria um buffer, e quando retorna,
          esse buffer temporário é copiado para `b1` no `main`. Seria um
          desperdício alocar e copiar os dados de um objeto que será destruído
          imediatamente depois.

  2.  **A Solução: Semântica de Movimentação (Move Semantics):**
      -   A ideia é, em vez de copiar, "roubar" ou "mover" os recursos de
          objetos temporários (chamados de *r-values*).
      -   Isso é muito mais rápido, pois envolve apenas a cópia de ponteiros e
          variáveis de tamanho, não do bloco de dados inteiro.

  3.  **Referências R-Value (`&&`):**
      -   C++11 introduziu um novo tipo de referência, `Tipo&&`, que só pode se
          ligar a objetos temporários (r-values).
      -   Isso permite que o compilador sobrecarregue funções para tratar
          objetos temporários de forma diferente dos objetos permanentes.

  4.  **Construtor de Movimentação (`BufferSimples(BufferSimples&& outro)`):**
      -   É chamado quando um novo objeto é criado a partir de um temporário.
      -   **Como funciona:**
          a.  Copia o ponteiro e o tamanho do objeto `outro`.
          b.  **Zera o ponteiro e o tamanho em `outro`**. Isso é a parte mais
              importante. O objeto `outro` não é mais dono do recurso. Seu
              destrutor será chamado, mas como seu ponteiro é `nullptr`,
              `delete[] nullptr` é uma operação segura que não faz nada.
      -   O resultado é uma transferência de posse barata, sem alocações ou
          cópias de dados pesados.

  5.  **Operador de Atribuição por Movimentação (`operator=(BufferSimples&& outro)`):**
      -   É chamado quando um objeto existente recebe um temporário
          (ex: `b2 = criarBuffer(20);`).
      -   Funciona de forma semelhante: libera seu próprio recurso antigo,
          rouba o recurso do `outro` e deixa `outro` em um estado vazio.

  6.  **`std::move`:**
      -   É uma função utilitária que transforma um objeto nomeado (um *l-value*)
          em uma referência r-value.
      -   É uma promessa ao compilador: "trate este objeto como se fosse um
          temporário; você pode roubar seus recursos".
      -   Após usar `std::move` em um objeto, você deve assumir que ele está em
          um estado "movido" e não deve mais usá-lo, exceto para destruí-lo ou
          atribuir um novo valor a ele.

  **Implicações para HFT:**
  -   A semântica de movimentação é uma das otimizações mais importantes do C++
      moderno.
  -   Ela permite retornar objetos complexos de funções por valor de forma
      eficiente, sem o custo de cópias profundas.
  -   Em HFT, onde cada alocação e cópia de memória é evitada em caminhos
      críticos, a capacidade de mover recursos de forma barata é fundamental
      para escrever código que é ao mesmo tempo seguro, limpo e extremamente
      rápido.
*/