#include <array> // Para std::array (array de tamanho fixo da STL)
#include <iostream>
#include <vector> // Para comparação com std::vector

int main() {
  // 1. Array C-style (Stack-allocated)
  // Tamanho fixo, alocado na Stack (se declarado dentro de uma função).
  // Não gerencia sua própria memória.
  int arrayC_stack[5] = {10, 20, 30, 40, 50};

  std::cout << "Array C-style (Stack): ";
  for (int i = 0; i < 5; ++i) {
    std::cout << arrayC_stack[i] << " ";
  }
  std::cout << '\n';
  std::cout << "Tamanho em bytes do array C-style (Stack): "
            << sizeof(arrayC_stack) << '\n';
  std::cout << "Numero de elementos (Stack): "
            << sizeof(arrayC_stack) / sizeof(arrayC_stack[0]) << '\n';

  // 2. Array C-style (Heap-allocated) - usando new/delete
  // Tamanho pode ser dinâmico, alocado no Heap.
  // O programador é responsável por gerenciar a memória (delete[]).
  int tamanho = 3;
  int *arrayC_heap = new int[tamanho]; // Aloca 3 inteiros no Heap

  arrayC_heap[0] = 100;
  arrayC_heap[1] = 200;
  arrayC_heap[2] = 300;

  std::cout << "\nArray C-style (Heap): ";
  for (int i = 0; i < tamanho; ++i) {
    std::cout << arrayC_heap[i] << " ";
  }
  std::cout << '\n';

  // IMPORTANTE: Liberar a memória alocada no Heap
  delete[] arrayC_heap;
  arrayC_heap = nullptr; // Boa prática: evitar ponteiros "dangling"

  // 3. std::array (Stack-allocated, tamanho fixo) - C++11
  // Combina a segurança e interface da STL com a alocação na Stack e
  // performance de arrays C-style de tamanho fixo.
  std::array<double, 4> arraySTL_stack = {1.1, 2.2, 3.3, 4.4};

  std::cout << "\nstd::array (Stack): ";
  for (double d : arraySTL_stack) { // Range-based for loop funciona
    std::cout << d << " ";
  }
  std::cout << '\n';
  std::cout << "Tamanho do std::array: " << arraySTL_stack.size() << '\n';
  std::cout << "Tamanho em bytes do std::array: " << sizeof(arraySTL_stack)
            << '\n';

  // 4. Comparação com std::vector (Heap-allocated, tamanho dinâmico)
  std::vector<int> vetorSTL_heap = {1, 2, 3};
  std::cout << "\nstd::vector (Heap): ";
  for (int n : vetorSTL_heap) {
    std::cout << n << " ";
  }
  std::cout << '\n';
  std::cout << "Tamanho do std::vector: " << vetorSTL_heap.size() << '\n';
  std::cout << "Capacidade do std::vector: " << vetorSTL_heap.capacity()
            << '\n';
  // Note que sizeof(vetorSTL_heap) retornaria o tamanho do objeto vector em si,
  // não o tamanho dos dados que ele contém no Heap.

  return 0;
}

/*
  Explicação: Arrays C-style e suas Diferenças

  Este exemplo explora os arrays C-style e os compara com `std::vector` e
  `std::array`.

  1.  **Arrays C-style (int[] ou char[]):**
      -   **Alocação:** Podem ser alocados na Stack (tamanho fixo em tempo de
  compilação) ou no Heap (tamanho dinâmico em tempo de execução, usando `new[]`
  e `delete[]`).
      -   **Gerenciamento de Memória:** O programador é totalmente responsável
  pela liberação da memória alocada no Heap. Esquecer `delete[]` causa memory
  leaks.
      -   **Segurança:** Não há verificação de limites. Acessar um índice fora
  dos limites (`arrayC_stack[10]`) resulta em Comportamento Indefinido
  (Undefined Behavior), que pode levar a crashes ou bugs difíceis de depurar.
      -   **Passagem para Funções:** Quando passados para funções, "decaem" para
  um ponteiro para o primeiro elemento, perdendo a informação de seu tamanho.

  2.  **`std::vector` (Heap-allocated, tamanho dinâmico):**
      -   **Alocação:** Sempre aloca seus elementos no Heap.
      -   **Gerenciamento de Memória:** Gerencia automaticamente a memória (RAII
  - Resource Acquisition Is Initialization). A memória é liberada
  automaticamente quando o `std::vector` sai do escopo.
      -   **Segurança:** Oferece `at()` para acesso com verificação de limites
  (lança exceção) e `[]` para acesso sem verificação (mais rápido, mas inseguro
  se o índice for inválido).
      -   **Tamanho:** Pode mudar dinamicamente em tempo de execução.

  3.  **`std::array` (Stack-allocated, tamanho fixo) - C++11:**
      -   **Alocação:** Sempre aloca seus elementos na Stack (se declarado
  localmente). O tamanho é fixo e deve ser conhecido em tempo de compilação.
      -   **Gerenciamento de Memória:** Não há gerenciamento dinâmico, pois a
  memória é gerenciada pela Stack.
      -   **Segurança:** Oferece `at()` para acesso com verificação de limites.
      -   **Tamanho:** Fixo em tempo de compilação.
      -   **Benefício:** Combina a performance e localidade de cache de arrays
  C-style na Stack com a interface segura e rica em recursos da STL (como
  `size()`, `begin()`, `end()`, range-based for loops).

  **Implicações para HFT:**
  -   **Preferência por `std::vector` e `std::array`:** Em C++ moderno e
  especialmente em HFT, `std::vector` e `std::array` são quase sempre preferidos
  em relação aos arrays C-style. Eles oferecem segurança, gerenciamento
  automático de memória e uma interface mais rica, sem sacrificar a localidade
  de cache (pois ambos armazenam elementos contiguamente).
  -   **Arrays C-style (Heap) a Evitar:** O uso de `new[]` e `delete[]` para
  arrays C-style no Heap é geralmente desaconselhado em favor de `std::vector`
  ou ponteiros inteligentes (`std::unique_ptr<int[]>`) para evitar erros de
      gerenciamento de memória.
  -   **`std::array` para Tamanho Fixo:** Se você sabe o tamanho exato da
  coleção em tempo de compilação e ela não precisa mudar, `std::array` é uma
  excelente escolha, pois evita alocações no Heap e oferece a segurança da STL.
  -   **Localidade de Cache:** Todos os três tipos (arrays C-style,
  `std::vector`, `std::array`) se beneficiam da localidade de cache devido ao
  armazenamento contíguo de seus elementos. A escolha entre eles depende mais do
  gerenciamento de memória, segurança e flexibilidade de tamanho.
*/