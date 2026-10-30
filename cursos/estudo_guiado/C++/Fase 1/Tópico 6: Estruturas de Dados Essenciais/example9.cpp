#include <iostream>
#include <stack>  // Necessário para usar std::stack
#include <string>
#include <vector> // Para usar std::vector como contêiner subjacente
#include <deque>  // Contêiner subjacente padrão para std::stack e std::queue
#include <list>   // Para usar std::list como contêiner subjacente (menos comum)

int main() {
  // 1. std::stack básico: Pilha de inteiros (usa std::deque por padrão)
  std::stack<int> minhaPilha;
  std::cout << "--- Demonstrando std::stack (Pilha LIFO) ---\n";

  // Adicionar elementos (push)
  minhaPilha.push(10);
  minhaPilha.push(20);
  minhaPilha.push(30);
  std::cout << "Pilha apos push(10), push(20), push(30).\n";
  std::cout << "Tamanho da pilha: " << minhaPilha.size() << '\n';
  std::cout << "Elemento no topo: " << minhaPilha.top() << '\n';

  // Remover elementos (pop) e observar a ordem LIFO
  std::cout << "\nRemovendo elementos da pilha:\n";
  while (!minhaPilha.empty()) {
    std::cout << "  Removendo: " << minhaPilha.top() << '\n';
    minhaPilha.pop();
  }
  std::cout << "Pilha vazia? " << (minhaPilha.empty() ? "Sim" : "Nao") << '\n';

  // 2. Especificando o contêiner subjacente
  // std::stack pode usar std::vector, std::list ou std::deque.
  // std::deque é o padrão e geralmente o mais eficiente para stack.

  // Pilha usando std::vector como contêiner subjacente
  std::stack<std::string, std::vector<std::string>> pilhaDeStringsVector;
  pilhaDeStringsVector.push("Primeiro");
  pilhaDeStringsVector.push("Segundo");
  std::cout << "\n--- std::stack com std::vector subjacente ---\n";
  std::cout << "Topo: " << pilhaDeStringsVector.top() << '\n';

  // Pilha usando std::list como contêiner subjacente (menos comum e menos eficiente)
  std::stack<double, std::list<double>> pilhaDeDoublesList;
  pilhaDeDoublesList.push(1.1);
  pilhaDeDoublesList.push(2.2);
  std::cout << "\n--- std::stack com std::list subjacente ---\n";
  std::cout << "Topo: " << pilhaDeDoublesList.top() << '\n';

  return 0;
}

/*
  Explicação: std::stack (Adaptador de Contêiner LIFO)

  `std::stack` é um **adaptador de contêiner** que fornece uma interface para
  um contêiner subjacente, impondo a semântica **LIFO (Last-In, First-Out)**.
  Pense em uma pilha de pratos: você só pode adicionar ou remover pratos do topo.

  1.  **Conceito de Adaptador:**
      -   `std::stack` não armazena os elementos diretamente. Ele "adapta" a
          interface de um contêiner existente (como `std::deque`, `std::vector`
          ou `std::list`) para que ele se comporte como uma pilha.
      -   Por padrão, `std::stack` usa `std::deque` como seu contêiner
          subjacente.

  2.  **Operações Principais (O(1) para a maioria dos contêineres subjacentes):**
      -   `push(elemento)`: Adiciona `elemento` ao topo da pilha.
      -   `pop()`: Remove o elemento do topo da pilha (não retorna o valor).
      -   `top()`: Retorna uma referência ao elemento no topo da pilha (não o remove).
      -   `empty()`: Retorna `true` se a pilha estiver vazia.
      -   `size()`: Retorna o número de elementos na pilha.

  3.  **Contêineres Subjacentes e Performance:**
      -   **`std::deque` (Padrão):** É a escolha padrão porque oferece inserções
          e remoções eficientes (O(1)) tanto no início quanto no final. Para
          `std::stack`, ele usa `push_back` e `pop_back`, que são eficientes.
      -   **`std::vector`:** Pode ser usado (`std::stack<T, std::vector<T>>`).
          `push_back` e `pop_back` são O(1) amortizado. Pode ser ligeiramente
          mais rápido que `deque` para alguns casos devido à sua memória
          totalmente contígua, mas pode ter picos de latência devido a realocações.
      -   **`std::list`:** Pode ser usado (`std::stack<T, std::list<T>>`).
          `push_back` e `pop_back` são O(1). No entanto, `std::list` tem péssima
          localidade de cache, tornando-o geralmente a pior escolha para
          performance em HFT, mesmo para `std::stack`.

  **Implicações para HFT:**
  -   **Imposição de Lógica:** `std::stack` é útil para impor a lógica LIFO,
      tornando o código mais claro e menos propenso a erros de acesso.
  -   **Performance Previsível:** As operações `push`, `pop` e `top` são
      O(1) para os contêineres subjacentes recomendados (`deque` e `vector`),
      o que é excelente para baixa latência.
  -   **Evitar `std::list`:** Em ambientes de alta performance, evite usar
      `std::list` como contêiner subjacente para `std::stack` devido à sua
      baixa localidade de cache.
  -   **Casos de Uso:** Pilhas são usadas em algoritmos como:
      -   Avaliação de expressões (notação polonesa reversa).
      -   Verificação de parênteses balanceados.
      -   Algoritmos de busca em profundidade (DFS) (embora recursão seja mais comum).
      -   Funcionalidades de "desfazer" (undo) em editores.
*/