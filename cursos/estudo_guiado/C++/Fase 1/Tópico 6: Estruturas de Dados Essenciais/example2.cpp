// Estudo Guiado/Fase 1/Tópico 6: Estruturas de Dados Essenciais/example2.cpp
#include <chrono> // Para medir tempo
#include <iostream>
#include <numeric> // Para std::iota
#include <vector>  // Necessário para usar std::vector

int main() {
  // 1. Criação e Inicialização de std::vector
  // std::vector é um array dinâmico. Ele gerencia sua própria memória no Heap.
  // Ao contrário de arrays C-style, seu tamanho pode mudar em tempo de
  // execução.
  std::vector<int> numeros = {10, 20, 30, 40, 50};

  std::cout << "Vetor inicial: ";
  for (int n : numeros) {
    std::cout << n << " ";
  }
  std::cout << '\n';

  std::cout << "Tamanho do vetor: " << numeros.size() << '\n';
  std::cout << "Capacidade do vetor: " << numeros.capacity()
            << '\n'; // Memória alocada

  // 2. Adicionando elementos (pode causar realocação)
  // Quando adicionamos um elemento e a capacidade atual é excedida,
  // o vector realoca memória (geralmente dobra a capacidade), copia os
  // elementos e libera a memória antiga. Isso é custoso.
  numeros.push_back(60); // Adiciona 60 ao final
  numeros.push_back(70); // Adiciona 70 ao final

  std::cout << "Vetor apos push_back: ";
  for (int n : numeros) {
    std::cout << n << " ";
  }
  std::cout << '\n';
  std::cout << "Novo tamanho: " << numeros.size() << '\n';
  std::cout << "Nova capacidade: " << numeros.capacity() << '\n';

  // 3. Acesso a elementos
  // Acesso por índice (como arrays C-style)
  std::cout << "Elemento no indice 2: " << numeros[2] << '\n';
  // Acesso seguro com verificação de limites (lança exceção se fora dos
  // limites)
  std::cout << "Elemento no indice 0 (com at): " << numeros.at(0) << '\n';

  // 4. Pré-alocação para evitar realocações
  std::vector<int> grandesNumeros;
  grandesNumeros.reserve(1000); // Pré-aloca espaço para 1000 elementos
  std::cout << "\nVetor grandesNumeros (vazio):\n";
  std::cout << "Tamanho: " << grandesNumeros.size() << '\n';
  std::cout << "Capacidade apos reserve(1000): " << grandesNumeros.capacity()
            << '\n';

  // Adicionando elementos sem realocação até a capacidade ser atingida
  for (int i = 0; i < 500; ++i) {
    grandesNumeros.push_back(i);
  }
  std::cout << "Tamanho apos 500 push_backs: " << grandesNumeros.size() << '\n';
  std::cout << "Capacidade: " << grandesNumeros.capacity()
            << '\n'; // Ainda 1000

  // 5. Localidade de Cache (Exemplo Conceitual)
  // std::vector armazena seus elementos em um bloco contíguo de memória.
  // Isso é EXTREMAMENTE importante para a performance devido à localidade de
  // cache.
  const int TAMANHO_VETOR = 1000000; // 1 milhão de elementos
  std::vector<int> dados(TAMANHO_VETOR);
  std::iota(dados.begin(), dados.end(), 0); // Preenche com 0, 1, 2, ...

  long long soma = 0;
  auto inicio = std::chrono::high_resolution_clock::now();

  // Iteração sequencial (ótima localidade de cache)
  for (int i = 0; i < TAMANHO_VETOR; ++i) {
    soma += dados[i];
  }

  auto fim = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> duracao = fim - inicio;
  std::cout << "\nSoma sequencial (boa localidade de cache): "
            << duracao.count() << " ms\n";

  // Se acessássemos elementos de forma não sequencial (ex: dados[i*1000]),
  // a performance seria muito pior devido a "cache misses".
  // (Este exemplo não demonstra isso diretamente para manter a clareza,
  // mas é o princípio por trás da importância da localidade de cache).

  return 0;
}

/*
  Explicação: std::vector e Localidade de Cache

  `std::vector` é o contêiner mais fundamental e amplamente utilizado na STL
  (Standard Template Library) do C++. Ele funciona como um array dinâmico,
  oferecendo uma interface segura e conveniente para gerenciar coleções de
  elementos.

  1.  **Memória Contígua no Heap:** A característica mais importante de
  `std::vector` para performance é que ele armazena seus elementos em um bloco
  **contíguo** de memória no Heap. Isso significa que todos os elementos estão
  um ao lado do outro na RAM.

  2.  **Localidade de Cache (Cache Locality):**
      -   **Cache da CPU:** CPUs modernas possuem caches (L1, L2, L3) que são
          muito mais rápidas que a RAM principal. Quando a CPU precisa de um
  dado, ela primeiro verifica se ele está no cache.
      -   **Cache Lines:** A CPU não busca dados byte a byte da RAM. Ela busca
          blocos maiores de memória, chamados "cache lines" (tipicamente 64
  bytes). Quando você acessa `elementos[i]`, a CPU carrega a cache line que
  contém `elementos[i]` e vários de seus vizinhos (`elementos[i+1]`,
  `elementos[i+2]`, etc.).
      -   **Benefício do `std::vector`:** Como os elementos de um `std::vector`
          são contíguos, uma iteração sequencial (`for (int n : meu_vector)`)
          resulta em muitos "cache hits". A CPU lê um elemento, e os próximos
          elementos que ela precisará já estão no cache, prontos para uso. Isso
          é extremamente rápido.
      -   **Contraste com Listas Encadeadas:** Contêineres como `std::list`
  (lista duplamente encadeada) armazenam elementos espalhados pela memória.
          Acessar o próximo elemento em uma `std::list` geralmente resulta em
          um "cache miss", pois o próximo elemento não está na mesma cache line,
          forçando a CPU a ir buscar na RAM, o que é muito mais lento.

  3.  **Custo da Realocação:** Assim como `std::string`, quando um `std::vector`
      precisa de mais espaço do que sua capacidade atual (por exemplo, ao usar
      `push_back` e a capacidade é excedida), ele:
      a.  Aloca um novo bloco de memória maior no Heap (geralmente dobra o
  tamanho). b.  Copia todos os elementos existentes para o novo bloco. c. Libera
  o bloco de memória antigo. Essas realocações são operações **custosas** e
  podem introduzir picos de latência imprevisíveis.

  **Implicações para HFT:**
  -   **`std::vector` é o Contêiner Padrão:** Devido à sua excelente localidade
      de cache e acesso O(1) por índice, `std::vector` é o contêiner preferido
      para a maioria das coleções de dados em HFT, especialmente para dados
      que são processados sequencialmente.
  -   **Pré-alocação é Crucial:** Para evitar realocações custosas em caminhos
      críticos, sempre use `reserve()` se você tiver uma estimativa do tamanho
      final do vetor. Isso garante que a memória seja alocada uma única vez.
  -   **Evitar `push_back` em Loops Críticos:** Se você não pode pré-alocar,
      evite `push_back` dentro de loops de alta frequência. Considere outras
      estratégias ou use um alocador de memória customizado.
  -   **Data-Oriented Design (DOD):** O princípio de armazenar dados de forma
      contígua para maximizar a localidade de cache é um pilar do DOD, que é
      fundamental em HFT.
*/