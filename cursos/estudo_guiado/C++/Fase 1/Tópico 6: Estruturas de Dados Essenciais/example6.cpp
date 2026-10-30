#include <algorithm> // Para std::generate
#include <chrono>    // Para medir tempo
#include <iostream>
#include <list>    // Necessário para usar std::list
#include <numeric> // Para std::iota
#include <vector>  // Para comparação

int main() {
  // 1. Criação e Operações Básicas de std::list
  // std::list é uma lista duplamente encadeada.
  // Cada elemento é um "nó" que contém o valor e ponteiros para o nó anterior e
  // próximo. Os nós são alocados individualmente no Heap e podem estar
  // espalhados na memória.
  std::list<int> minhaLista;

  minhaLista.push_back(10); // Adiciona ao final
  minhaLista.push_front(5); // Adiciona ao início
  minhaLista.push_back(15);

  std::cout << "Lista inicial: ";
  for (int n : minhaLista) {
    std::cout << n << " ";
  }
  std::cout << '\n';

  // Inserção no meio (eficiente para std::list)
  auto it = minhaLista.begin();
  std::advance(it, 1);      // Move o iterador para a segunda posição
  minhaLista.insert(it, 7); // Insere 7 na segunda posição

  std::cout << "Lista apos insercao: ";
  for (int n : minhaLista) {
    std::cout << n << " ";
  }
  std::cout << '\n';

  // Remoção (eficiente para std::list)
  minhaLista.remove(10); // Remove todas as ocorrências de 10

  std::cout << "Lista apos remocao: ";
  for (int n : minhaLista) {
    std::cout << n << " ";
  }
  std::cout << '\n';

  // 2. Comparação de Performance: std::vector vs std::list (Iteração
  // Sequencial)
  const int TAMANHO = 100000; // 100 mil elementos
  std::vector<int> meuVector(TAMANHO);
  std::list<int> minhaOutraLista;

  // Preencher ambos com dados
  std::iota(meuVector.begin(), meuVector.end(), 0);
  std::generate_n(std::back_inserter(minhaOutraLista), TAMANHO,
                  [n = 0]() mutable { return n++; });

  long long somaVector = 0;
  long long somaLista = 0;

  // Medir tempo para std::vector (boa localidade de cache)
  auto inicioVector = std::chrono::high_resolution_clock::now();
  for (int n : meuVector) {
    somaVector += n;
  }
  auto fimVector = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> duracaoVector =
      fimVector - inicioVector;
  std::cout << "\nTempo de iteracao std::vector: " << duracaoVector.count()
            << " ms (Soma: " << somaVector << ")\n";

  // Medir tempo para std::list (ruim localidade de cache)
  auto inicioLista = std::chrono::high_resolution_clock::now();
  for (int n : minhaOutraLista) {
    somaLista += n;
  }
  auto fimLista = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> duracaoLista =
      fimLista - inicioLista;
  std::cout << "Tempo de iteracao std::list: " << duracaoLista.count()
            << " ms (Soma: " << somaLista << ")\n";

  std::cout << "\nObserve a diferença de tempo na iteração sequencial.\n";

  return 0;
}

/*
  Explicação: std::list e o Custo da Não-Contiguidade de Memória

  Este exemplo introduz `std::list`, uma lista duplamente encadeada, e compara
  sua performance de iteração com `std::vector`.

  1.  **Estrutura de `std::list`:**
      -   `std::list` não armazena seus elementos em um bloco contíguo de
  memória.
      -   Cada elemento é encapsulado em um "nó" que, além do valor, contém
          ponteiros para o nó anterior e o próximo.
      -   Esses nós são alocados individualmente no Heap. Isso significa que
          eles podem estar espalhados por toda a memória RAM.

  2.  **Vantagens de `std::list`:**
      -   **Inserções e Remoções Rápidas (O(1)):** Uma vez que você tem um
          iterador para uma posição, inserir ou remover um elemento é muito
          rápido, pois envolve apenas a atualização de alguns ponteiros.
          Não há necessidade de mover outros elementos (como em `std::vector`).
      -   **Sem Realocações:** Não há realocações de blocos de memória grandes,
          o que evita os picos de latência associados a `std::vector` e
  `std::string`.

  3.  **Desvantagens de `std::list` (e por que é ruim para HFT):**
      -   **Péssima Localidade de Cache:** Como os nós estão espalhados na
  memória, iterar sobre uma `std::list` resulta em muitos "cache misses". A CPU
          precisa ir buscar cada nó individualmente na RAM, o que é muito lento.
          Isso é o oposto da localidade de cache que `std::vector` oferece.
      -   **Acesso Aleatório Lento (O(N)):** Acessar um elemento por índice
          (`minhaLista[5]`) não é possível diretamente. Você precisa percorrer
          a lista do início (ou fim) até a posição desejada, o que é uma
  operação linear (lenta para listas grandes).
      -   **Maior Consumo de Memória:** Cada nó armazena não apenas o valor,
          mas também dois ponteiros, aumentando o consumo de memória por
  elemento.

  **Implicações para HFT:**
  -   **Evitar `std::list` em Caminhos Críticos:** Devido à sua péssima
  localidade de cache e acesso aleatório lento, `std::list` é **raramente
  usado** em caminhos de código de alta performance em HFT.
  -   **Preferência por Contêineres Contíguos:** A regra geral é preferir
  contêineres que armazenam seus dados de forma contígua (`std::vector`,
  `std::array`, arrays C-style) sempre que a iteração sequencial ou o acesso por
  índice for importante.
  -   **Trade-offs:** Embora `std::list` seja excelente para inserções/remoções
      frequentes no meio da coleção, em HFT, essas operações são frequentemente
      reprojetadas para usar estruturas de dados mais amigáveis ao cache ou
      são feitas fora do caminho crítico.
*/