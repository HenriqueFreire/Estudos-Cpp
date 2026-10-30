#include <iostream>
#include <queue>  // Necessário para usar std::queue
#include <string>
#include <deque>  // Contêiner subjacente padrão para std::queue
#include <list>   // Pode ser usado como contêiner subjacente

int main() {
  // 1. std::queue básico: Fila de inteiros (usa std::deque por padrão)
  std::queue<int> minhaFila;
  std::cout << "--- Demonstrando std::queue (Fila FIFO) ---\n";

  // Adicionar elementos (push)
  minhaFila.push(10);
  minhaFila.push(20);
  minhaFila.push(30);
  std::cout << "Fila apos push(10), push(20), push(30).\n";
  std::cout << "Tamanho da fila: " << minhaFila.size() << '\n';
  std::cout << "Elemento na frente: " << minhaFila.front() << '\n';
  std::cout << "Elemento no final: " << minhaFila.back() << '\n';

  // Remover elementos (pop) e observar a ordem FIFO
  std::cout << "\nRemovendo elementos da fila:\n";
  while (!minhaFila.empty()) {
    std::cout << "  Removendo: " << minhaFila.front() << '\n';
    minhaFila.pop();
  }
  std::cout << "Fila vazia? " << (minhaFila.empty() ? "Sim" : "Nao") << '\n';

  // 2. Especificando o contêiner subjacente
  // std::queue pode usar std::deque (padrão) ou std::list.
  // std::vector NÃO pode ser usado diretamente, pois não tem pop_front eficiente.

  // Fila usando std::list como contêiner subjacente
  std::queue<std::string, std::list<std::string>> filaDeStringsList;
  filaDeStringsList.push("Primeiro na fila");
  filaDeStringsList.push("Segundo na fila");
  std::cout << "\n--- std::queue com std::list subjacente ---\n";
  std::cout << "Frente: " << filaDeStringsList.front() << '\n';
  std::cout << "Final: " << filaDeStringsList.back() << '\n';

  return 0;
}

/*
  Explicação: std::queue (Adaptador de Contêiner FIFO)

  `std::queue` é um **adaptador de contêiner** que fornece uma interface para
  um contêiner subjacente, impondo a semântica **FIFO (First-In, First-Out)**.
  Pense em uma fila de pessoas em um caixa: o primeiro a chegar é o primeiro a ser atendido.

  1.  **Conceito de Adaptador:**
      -   Assim como `std::stack`, `std::queue` não armazena os elementos
          diretamente. Ele "adapta" a interface de um contêiner existente para
          que ele se comporte como uma fila.
      -   Por padrão, `std::queue` usa `std::deque` como seu contêiner
          subjacente.

  2.  **Operações Principais (O(1) para a maioria dos contêineres subjacentes):**
      -   `push(elemento)`: Adiciona `elemento` ao final da fila.
      -   `pop()`: Remove o elemento do início da fila (não retorna o valor).
      -   `front()`: Retorna uma referência ao elemento no início da fila.
      -   `back()`: Retorna uma referência ao elemento no final da fila.
      -   `empty()`: Retorna `true` se a fila estiver vazia.
      -   `size()`: Retorna o número de elementos na fila.

  3.  **Contêineres Subjacentes e Performance:**
      -   **`std::deque` (Padrão):** É a escolha padrão porque oferece inserções
          e remoções eficientes (O(1)) tanto no início (`pop_front`) quanto no
          final (`push_back`). Isso é exatamente o que `std::queue` precisa.
      -   **`std::list`:** Pode ser usado (`std::queue<T, std::list<T>>`).
          `push_back` e `pop_front` são O(1). No entanto, `std::list` tem péssima
          localidade de cache, tornando-o geralmente a pior escolha para
          performance em HFT, mesmo para `std::queue`.
      -   **`std::vector`:** **NÃO pode ser usado** como contêiner subjacente
          para `std::queue` porque `std::vector` não possui uma operação
          `pop_front` eficiente (remover do início de um `vector` é O(N), pois
          todos os elementos precisam ser deslocados).

  **Implicações para HFT:**
  -   **Processamento de Eventos/Mensagens:** `std::queue` é fundamental em
      sistemas de HFT para gerenciar filas de mensagens, eventos de mercado,
      ordens a serem processadas, etc. A natureza FIFO garante que os eventos
      sejam processados na ordem em que chegam.
  -   **Performance Previsível:** As operações `push`, `pop`, `front` e `back`
      são O(1) com `std::deque` ou `std::list`, o que é crucial para baixa
      latência.
  -   **Escolha do Contêiner Subjacente:** Para a maioria dos casos, `std::deque`
      é a melhor escolha para `std::queue` devido à sua eficiência nas duas
      pontas e melhor localidade de cache que `std::list`.
*/