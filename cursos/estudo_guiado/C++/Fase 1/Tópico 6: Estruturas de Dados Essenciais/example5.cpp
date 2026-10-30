#include <iostream>
#include <map> // Necessário para usar std::map
#include <string>
#include <chrono> // Para ilustrar conceitos de tempo

int main() {
  // 1. Criação e Operações Básicas de std::map
  // std::map armazena pares chave-valor de forma ORDENADA pela chave.
  // É implementado como uma Árvore Binária de Busca Balanceada (geralmente Red-Black Tree).
  std::map<std::string, int> pontuacoes;

  // Inserir elementos. O mapa irá mantê-los ordenados alfabeticamente pela chave.
  pontuacoes["Charlie"] = 90;
  pontuacoes["Alice"] = 95;
  pontuacoes["Bob"] = 88;

  // Acessar elementos (complexidade O(log N))
  std::cout << "Pontuacao de Alice: " << pontuacoes["Alice"] << '\n';

  // Verificar se uma chave existe
  if (pontuacoes.count("David")) {
    std::cout << "David esta no mapa.\n";
  } else {
    std::cout << "David NAO esta no mapa.\n";
  }

  // 2. A Principal Vantagem: Ordem
  // Iterar sobre o mapa mostrará os elementos em ordem alfabética da chave.
  std::cout << "\nPontuacoes em ordem alfabetica:\n";
  for (const auto& par : pontuacoes) {
    std::cout << "  " << par.first << ": " << par.second << '\n';
  }

  // A ordem permite operações eficientes baseadas em faixas de valores.
  // Ex: Encontrar o primeiro elemento cuja chave não é menor que "B"
  auto it = pontuacoes.lower_bound("B");
  if (it != pontuacoes.end()) {
    std::cout << "\nPrimeiro jogador a partir de 'B': " << it->first << '\n';
  }

  return 0;
}

/*
  Explicação: std::map e a Performance de Estruturas Ordenadas

  `std::map` é um contêiner associativo que armazena pares chave-valor de forma
  ordenada, o que o diferencia fundamentalmente do `std::unordered_map`.

  1.  **Como Funciona (Árvore Binária de Busca Balanceada):**
      -   `std::map` é geralmente implementado como uma Red-Black Tree, um tipo
          de árvore binária de busca que se auto-balanceia.
      -   Isso garante que a árvore nunca se torne "desequilibrada", o que
          mantém a performance das operações previsível.
      -   Cada nó da árvore armazena um par chave-valor. Os nós são alocados
          individualmente no Heap.

  2.  **Performance (O(log N)):**
      -   Buscas, inserções e remoções em um `std::map` têm uma complexidade de
          tempo garantida de O(log N).
      -   Isso ocorre porque, a cada passo da busca na árvore, metade do
          restante dos elementos é descartada. Para encontrar um elemento entre
          1 milhão, são necessários no máximo ~20 comparações (log₂1.000.000 ≈ 19.9).
      -   Isso é mais lento que o tempo médio O(1) do `std::unordered_map`, mas
          evita completamente o pior caso O(N) do seu primo baseado em hash.

  3.  **Localidade de Cache:**
      -   Assim como `std::list` e `std::unordered_map`, os nós de um `std::map`
          são alocados individualmente no Heap, o que pode levar a uma baixa
          localidade de cache em comparação com `std::vector`.
      -   No entanto, durante uma iteração sequencial, a localidade de cache de
          um `std::map` pode ser ligeiramente melhor que a de um
          `std::unordered_map`, pois os nós "vizinhos" na árvore podem, por vezes,
          ser alocados mais próximos na memória. Ainda assim, ambos são muito
          inferiores a um contêiner contíguo como `std::vector`.

  **Implicações para HFT: `std::map` vs. `std::unordered_map`**

  A escolha entre `map` and `unordered_map` em HFT é um trade-off clássico
  entre velocidade média e previsibilidade de latência.

  -   **Use `std::unordered_map` quando:**
      1.  A velocidade de busca média é a prioridade máxima.
      2.  A ordem dos elementos não importa.
      3.  Você pode mitigar o custo de `rehash` (picos de latência) usando
          `reserve()` para pré-alocar buckets fora do caminho crítico.
      4.  Você pode tolerar um (raro) pior caso de performance O(N) se a função
          de hash se comportar mal.

  -   **Use `std::map` quando:**
      1.  A **ordem** dos elementos é um requisito funcional (ex: order book,
          onde as ordens são agrupadas por preço).
      2.  A **previsibilidade da latência** é mais importante que a velocidade
          média. O `O(log N)` garantido do `std::map` significa que não haverá
          picos de latência inesperados e grandes como um `rehash`.
      3.  Você precisa realizar operações baseadas em faixas de valores (ex:
          "encontre todas as ordens entre o preço X e Y").

  **Conclusão:** Para lookups simples e rápidos onde a ordem não importa,
  `std::unordered_map` (com `reserve()`) é geralmente a escolha. Para casos
  onde a ordem é essencial ou a latência precisa ser garantida e previsível,
  `std::map` é a opção mais segura e apropriada, mesmo sendo mais lento na média.
*/