#include <iostream>
#include <set>           // Necessário para usar std::set
#include <unordered_set> // Necessário para usar std::unordered_set
#include <string>
#include <chrono>

int main() {
  // 1. std::set: armazena elementos únicos de forma ORDENADA.
  // Implementado como uma Árvore Binária de Busca (Red-Black Tree).
  std::set<std::string> setOrdenado;
  std::cout << "--- Demonstrando std::set ---\n";

  // Inserindo elementos. A inserção é O(log N).
  setOrdenado.insert("banana");
  setOrdenado.insert("maca");
  setOrdenado.insert("uva");
  setOrdenado.insert("maca"); // Duplicatas são ignoradas silenciosamente.

  // Iterar sobre o set mostra os elementos em ordem.
  std::cout << "Elementos no std::set (ordenados):\n";
  for (const auto& item : setOrdenado) {
    std::cout << "  " << item << '\n';
  }

  // Buscar um elemento (O(log N)).
  if (setOrdenado.count("banana")) {
    std::cout << "'banana' foi encontrado no set.\n";
  }

  // 2. std::unordered_set: armazena elementos únicos SEM ORDEM específica.
  // Implementado como uma Tabela Hash.
  std::unordered_set<std::string> setNaoOrdenado;
  std::cout << "\n--- Demonstrando std::unordered_set ---\n";

  // Inserindo elementos. A inserção é O(1) em média.
  setNaoOrdenado.insert("banana");
  setNaoOrdenado.insert("maca");
  setNaoOrdenado.insert("uva");
  setNaoOrdenado.insert("maca"); // Duplicatas também são ignoradas.

  // Iterar sobre o unordered_set mostra os elementos em uma ordem aparentemente aleatória.
  std::cout << "Elementos no std::unordered_set (sem ordem garantida):\n";
  for (const auto& item : setNaoOrdenado) {
    std::cout << "  " << item << '\n';
  }

  // Buscar um elemento (O(1) em média).
  if (setNaoOrdenado.count("laranja")) {
    std::cout << "'laranja' foi encontrado no unordered_set.\n";
  } else {
    std::cout << "'laranja' NAO foi encontrado no unordered_set.\n";
  }

  return 0;
}

/*
  Explicação: std::set vs. std::unordered_set

  Ambos `std::set` e `std::unordered_set` são contêineres que armazenam coleções
  de elementos únicos. A principal diferença entre eles é a mesma que entre
  `std::map` e `std::unordered_map`: a estrutura de dados subjacente e as
  garantias de ordem e performance.

  1.  **std::set**
      -   **Estrutura:** Árvore Binária de Busca Balanceada (Red-Black Tree).
      -   **Ordem:** Mantém os elementos sempre em ordem crescente.
      -   **Performance:** Buscas, inserções e remoções são garantidas em
          **O(log N)**.
      -   **Uso:** Ideal quando você precisa de uma coleção de itens únicos e
          também precisa que eles estejam sempre ordenados, ou quando precisa
          realizar operações baseadas em faixas de valores.

  2.  **std::unordered_set**
      -   **Estrutura:** Tabela Hash.
      -   **Ordem:** Nenhuma ordem garantida. A ordem pode mudar entre
          diferentes execuções ou após inserções/remoções.
      -   **Performance:** Buscas, inserções e remoções são **O(1) em média**,
          mas podem degradar para **O(N) no pior caso** (muitas colisões de hash).
      -   **Uso:** O caso de uso mais comum e poderoso é para verificação de
          existência de forma extremamente rápida. Ex: "Já vi este elemento antes?".

  **Implicações para HFT: Qual usar?**

  A escolha depende do requisito do seu algoritmo.

  -   **Para Verificação de Existência Rápida:** Se você só precisa saber se um
      item está ou não em uma coleção, e a ordem não importa,
      **`std::unordered_set` é quase sempre a melhor escolha**. Sua performance
      média O(1) é superior ao O(log N) do `std::set`.
      -   **Exemplo:** Manter um conjunto de IDs de ordens que já foram
          processadas para evitar processamento duplicado.

  -   **Quando a Ordem Importa:** Se a lógica do seu algoritmo depende da ordem
      dos elementos únicos, então **`std::set` é a única opção**.
      -   **Exemplo:** Manter uma lista de preços únicos em que uma ordem foi
          executada, e você precisa rapidamente encontrar o preço mais próximo
          de um determinado valor.

  **Mesmas ressalvas do `unordered_map` se aplicam:**
  -   `std::unordered_set` pode sofrer `rehash`, uma operação custosa que causa
      picos de latência. Use `reserve()` para pré-alocar buckets se o número de
      elementos for conhecido, para evitar isso em caminhos críticos.
  -   A performance do `unordered_set` depende de uma boa função de hash.

  **Conclusão:** Para a tarefa comum de "marcar" itens como "vistos",
  `std::unordered_set` é a ferramenta padrão devido à sua velocidade. Use
  `std::set` apenas quando a ordenação dos elementos únicos for um requisito
  essencial.
*/