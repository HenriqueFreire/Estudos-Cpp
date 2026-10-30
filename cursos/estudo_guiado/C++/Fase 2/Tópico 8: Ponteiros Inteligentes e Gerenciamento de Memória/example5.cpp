#include <iostream>
#include <memory> // Para std::unique_ptr
#include <vector>

// --- Cenário: Gerenciar um array de tamanho definido em tempo de execução ---

void processarArray(const int* array, size_t tamanho) {
  std::cout << "  Processando array: ";
  long long soma = 0;
  for (size_t i = 0; i < tamanho; ++i) {
    soma += array[i];
  }
  std::cout << "Soma = " << soma << "\n";
}

// --- 1. A maneira C-style (new[] / delete[]) ---
void gerenciamentoManualDeArray(size_t tamanho) {
  std::cout << "--- 1. Gerenciamento Manual com new[] / delete[] ---\n";
  int* array_bruto = new int[tamanho]; // Aloca o array

  // Preenche o array
  for (size_t i = 0; i < tamanho; ++i) {
    array_bruto[i] = i + 1;
  }

  processarArray(array_bruto, tamanho);

  // CRUCIAL: Deve usar delete[] para arrays, não delete.
  // Esquecer isso ou usar 'delete' simples é um erro grave.
  delete[] array_bruto;
  std::cout << "  Array liberado com delete[].\n";
}

// --- 2. A maneira C++ Moderno com std::unique_ptr<T[]> ---
void gerenciamentoComSmartArray(size_t tamanho) {
  std::cout << "\n--- 2. Gerenciamento com std::unique_ptr<T[]> ---\n";

  // A forma correta de criar um unique_ptr para um array.
  // A sintaxe <int[]> informa ao unique_ptr que ele gerencia um array.
  std::unique_ptr<int[]> array_inteligente = std::make_unique<int[]>(tamanho);

  // Preenche o array. O operador[] é sobrecarregado.
  for (size_t i = 0; i < tamanho; ++i) {
    array_inteligente[i] = i + 1;
  }

  // .get() retorna o ponteiro bruto para interoperabilidade com outras funções.
  processarArray(array_inteligente.get(), tamanho);

  std::cout << "  Saindo da funcao. O unique_ptr ira chamar delete[] automaticamente.\n";
} // O destrutor de 'array_inteligente' é chamado. Como é um <T[]>, ele
  // invoca 'delete[]' corretamente, em vez de 'delete'.

int main() {
  const size_t TAMANHO = 5;
  gerenciamentoManualDeArray(TAMANHO);
  gerenciamentoComSmartArray(TAMANHO);
  return 0;
}

/*
  Explicação: Gerenciando Arrays com `std::unique_ptr<T[]>`

  Este exemplo foca na especialização de `std::unique_ptr` para arrays, que é
  a substituição direta e segura do par `new[]`/`delete[]`.

  1.  **O Problema com `new[]` e `delete[]`:**
      -   Assim como com `new`/`delete`, o programador é responsável por chamar
          `delete[]` para liberar a memória do array.
      -   É fácil esquecer a chamada, causando vazamentos de memória.
      -   É um erro comum e grave usar `delete` em vez de `delete[]` para um
          array. Isso resulta em comportamento indefinido, pois apenas o primeiro
          elemento pode ser destruído corretamente, e a memória restante vaza.

  2.  **A Solução: `std::unique_ptr<T[]>`:**
      -   O C++ fornece uma especialização do template `std::unique_ptr` para
          arrays, indicada pela sintaxe `T[]`.
      -   Quando você cria um `std::unique_ptr<int[]>`, ele "sabe" que está
          gerenciando um array.
      -   **Limpeza Automática e Correta:** Seu destrutor chama automaticamente
          `delete[]` em vez de `delete`, garantindo que todos os elementos do
          array sejam destruídos e toda a memória seja liberada corretamente.
      -   **Acesso:** Ele sobrecarrega o operador `[]`, permitindo o acesso aos
          elementos de forma natural (ex: `meu_array[i]`).
      -   **Criação:** A forma preferida de criar é com `std::make_unique<T[]>(tamanho)`.

  **`std::unique_ptr<T[]>` vs. `std::vector<T>`: Qual usar?**

  Embora `std::unique_ptr<T[]>` seja a maneira correta de ter um ponteiro
  inteligente para um array C-style, na maioria das vezes, **`std::vector<T>` é
  a escolha preferida**.

  -   **Use `std::vector<T>` quando:**
      -   Você precisa de um contêiner completo, com funcionalidades como `size()`,
          `push_back()`, `resize()`, iteradores (`begin()`, `end()`) e integração
          fácil com os algoritmos da STL.
      -   A flexibilidade de mudar o tamanho do array é útil.
      -   É a escolha padrão para a maioria dos casos em C++ moderno.

  -   **Use `std::unique_ptr<T[]>` quando:**
      -   Você precisa de um array dinâmico de **tamanho fixo** e quer a
          solução com o **mínimo de overhead possível**. `std::unique_ptr<T[]>`
          é basicamente um ponteiro bruto com gerenciamento de vida automático;
          ele não armazena o tamanho do array nem tem a sobrecarga de outras
          funcionalidades do `vector`.
      -   Você precisa interagir com uma API C que espera receber a "posse" de
          um ponteiro para um buffer alocado no heap. Você pode alocar com
          `make_unique`, trabalhar com ele, e então usar `.release()` para
          transferir a posse para a API C.

  **Implicações para HFT:**
  -   A escolha entre `vector` e `unique_ptr<T[]>` é um trade-off entre
      funcionalidade e overhead.
  -   Para buffers de dados onde o tamanho é fixo e a performance é ultra-crítica,
      `unique_ptr<T[]>` pode ser preferível por ser um wrapper mais "magro".
  -   No entanto, a segurança e a riqueza de funcionalidades do `std::vector`
      geralmente o tornam a melhor escolha, a menos que um profiler aponte que
      o pequeno overhead do `vector` é um gargalo real.
*/