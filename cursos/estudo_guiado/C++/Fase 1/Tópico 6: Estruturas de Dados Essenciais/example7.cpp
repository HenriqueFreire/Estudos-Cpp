// Estudo Guiado/Fase 1/Tópico 6: Estruturas de Dados Essenciais/example6.cpp
#include <chrono> // Para medir tempo
#include <iostream>
#include <random> // Para gerar dados aleatórios
#include <string>
#include <unordered_map> // Necessário para usar std::unordered_map
#include <vector>        // Para armazenar chaves para busca

int main() {
  // 1. Criação e Operações Básicas de std::unordered_map
  // std::unordered_map armazena pares chave-valor.
  // Ele usa uma tabela hash para acesso rápido (em média O(1)).
  std::unordered_map<std::string, int> inventario;

  // Inserir elementos
  inventario["maca"] = 10;
  inventario["banana"] = 5;
  inventario["laranja"] = 8;

  // Acessar elementos
  std::cout << "Estoque de maca: " << inventario["maca"] << '\n';

  // Verificar se uma chave existe
  if (inventario.count("uva")) {
    std::cout << "Uva esta no inventario.\n";
  } else {
    std::cout << "Uva NAO esta no inventario.\n";
  }

  // Iterar sobre o mapa (ordem não garantida)
  std::cout << "Inventario atual:\n";
  for (const auto &par : inventario) {
    std::cout << "  " << par.first << ": " << par.second << '\n';
  }

  // Remover elemento
  inventario.erase("banana");
  std::cout << "Inventario apos remover banana:\n";
  for (const auto &par : inventario) {
    std::cout << "  " << par.first << ": " << par.second << '\n';
  }

  // 2. Performance de Busca (O(1) em média vs O(N) no pior caso)
  const int NUM_ELEMENTOS = 100000;
  std::unordered_map<int, std::string> grandeMapa;
  std::vector<int>
      chavesParaBuscar; // Para garantir que buscamos chaves existentes

  // Gerador de números aleatórios
  std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
  std::uniform_int_distribution<int> dist(0, NUM_ELEMENTOS *
                                                 2); // Chaves podem ser maiores

  // Preencher o mapa e as chaves para busca
  for (int i = 0; i < NUM_ELEMENTOS; ++i) {
    int chave = dist(rng);
    grandeMapa[chave] = "Valor_" + std::to_string(chave);
    chavesParaBuscar.push_back(chave); // Adiciona a chave para busca
  }

  // Medir tempo de busca
  long long totalBuscas = 0;
  auto inicioBusca = std::chrono::high_resolution_clock::now();
  for (int chave : chavesParaBuscar) {
    auto it = grandeMapa.find(chave);
    if (it != grandeMapa.end()) {
      totalBuscas++;
    }
  }
  auto fimBusca = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> duracaoBusca =
      fimBusca - inicioBusca;

  std::cout << "\nBusca em std::unordered_map com " << NUM_ELEMENTOS
            << " elementos:\n";
  std::cout << "Tempo total para " << chavesParaBuscar.size()
            << " buscas: " << duracaoBusca.count() << " ms\n";
  std::cout << "Buscas encontradas: " << totalBuscas << '\n';

  // 3. Fatores de Performance para HFT
  std::cout << "\nFatores de Performance para HFT com std::unordered_map:\n";
  std::cout << "  - O(1) em media: Muito rapido para a maioria das buscas.\n";
  std::cout << "  - O(N) no pior caso: Colisoes de hash podem degradar para "
               "busca linear.\n";
  std::cout << "  - Funcao de Hash: Escolha uma boa funcao de hash para seus "
               "tipos de chave.\n";
  std::cout << "  - Fator de Carga (Load Factor): Controla a densidade da "
               "tabela hash.\n";
  std::cout << "    - `grandeMapa.load_factor()`: " << grandeMapa.load_factor()
            << '\n';
  std::cout << "    - `grandeMapa.max_load_factor()`: "
            << grandeMapa.max_load_factor() << '\n';
  std::cout << "  - Rehash: Quando o fator de carga excede o max_load_factor, "
               "o mapa e reconstruido.\n";
  std::cout << "    - Rehash e uma operacao custosa e imprevisivel (alocacao "
               "no Heap, copia).\n";
  std::cout
      << "    - Use `reserve()` para pre-alocar buckets e evitar rehashes.\n";
  grandeMapa.reserve(NUM_ELEMENTOS * 2); // Tenta evitar rehashes futuros
  std::cout << "  - Localidade de Cache: Elementos espalhados no Heap (como "
               "std::list).\n";
  std::cout << "    - Iteracao sequencial e mais lenta que std::vector.\n";

  return 0;
}

/*
  Explicação: std::unordered_map e suas Implicações para HFT

  `std::unordered_map` é um contêiner associativo que armazena pares chave-valor
  e permite buscas, inserções e remoções muito rápidas, em tempo constante médio
  (O(1)). Ele é implementado usando uma **tabela hash**.

  1.  **Como Funciona (Tabela Hash):**
      -   Para cada chave, uma "função de hash" calcula um índice (hash) na
  tabela.
      -   O valor é armazenado nesse "bucket" (balde).
      -   Em caso de "colisão" (duas chaves diferentes geram o mesmo hash), os
          elementos são armazenados em uma lista encadeada dentro do bucket.

  2.  **Performance (O(1) em Média, O(N) no Pior Caso):**
      -   **Média (O(1)):** Se a função de hash for boa e as colisões forem
  mínimas, a busca é quase instantânea, pois o elemento é encontrado diretamente
          no bucket.
      -   **Pior Caso (O(N)):** Se houver muitas colisões (função de hash ruim,
          muitos elementos no mesmo bucket), a busca degenera para uma busca
          linear na lista encadeada do bucket, tornando-se tão lenta quanto
          iterar sobre uma `std::list`.

  3.  **Fatores Críticos para HFT:**
      -   **Função de Hash:** A escolha de uma boa função de hash é vital. Para
          tipos personalizados, você pode fornecer sua própria função de hash.
          Uma função de hash ruim leva a muitas colisões e degrada a
  performance.
      -   **Fator de Carga (Load Factor):** É a razão entre o número de
  elementos e o número de buckets. Se o fator de carga exceder
  `max_load_factor()`, o `std::unordered_map` realiza um **rehash**.
      -   **Rehash:** É uma operação **muito custosa** e imprevisível. Envolve:
          a.  Alocar uma nova tabela de buckets maior no Heap.
          b.  Re-hashear e mover *todos* os elementos da tabela antiga para a
  nova. c.  Liberar a tabela antiga. Isso introduz picos de latência que são
  inaceitáveis em HFT. Para evitar rehashes, use `reserve()` para pré-alocar um
  número suficiente de buckets se você souber o número aproximado de elementos.
      -   **Localidade de Cache:** Os elementos (nós dos buckets) de um
          `std::unordered_map` são alocados individualmente no Heap e podem
          estar espalhados pela memória, assim como em `std::list`. Isso resulta
          em **baixa localidade de cache** durante a iteração ou em buscas
          que envolvem colisões.

  **Contraste com `std::map` (Árvore Binária Balanceada):**
  -   `std::map` é implementado como uma árvore binária de busca balanceada
  (geralmente Red-Black Tree).
  -   **Performance:** Garante O(log N) para buscas, inserções e remoções. É
  mais lento que `std::unordered_map` em média, mas seu pior caso é garantido.
  -   **Localidade de Cache:** Geralmente tem melhor localidade de cache que
      `std::unordered_map` para buscas em um pequeno intervalo de chaves, pois
      os nós da árvore tendem a estar mais próximos.
  -   **Ordem:** Mantém os elementos ordenados por chave, o que
  `std::unordered_map` não faz.

  **Implicações para HFT:**
  -   `std::unordered_map` pode ser usado para lookups rápidos, mas **com
  cautela**.
  -   É crucial **pré-alocar** (`reserve()`) para evitar rehashes.
  -   A **função de hash** deve ser cuidadosamente escolhida/implementada.
  -   Para dados que precisam ser iterados sequencialmente ou que se beneficiam
      de boa localidade de cache, `std::vector` ainda é superior.
  -   Se a ordem dos elementos for importante ou se o pior caso de latência for
      mais crítico que a média, `std::map` pode ser uma alternativa, embora mais
  lenta.
*/