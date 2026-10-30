#include <chrono> // Para medir tempo
#include <iostream>
#include <numeric> // Para std::iota
#include <vector>

const int TAMANHO_MATRIZ = 8192; // 8192 * 8192 = 67,108,864 elementos
const int NUM_REPETICOES = 10;   // Para obter uma média mais estável

// Matriz 2D para demonstrar o acesso
// Usamos um std::vector<std::vector<int>> para simular uma matriz 2D
// mas é importante notar que isso NÃO garante localidade de cache perfeita
// entre as "linhas" como um array C-style int[TAMANHO][TAMANHO] faria.
// Para uma demonstração mais pura de cache locality em 2D, um array C-style
// ou um std::vector<int> grande e acesso manual seria melhor.
// No entanto, para ilustrar o conceito de acesso por linha vs coluna, serve.
std::vector<std::vector<int>> matriz(TAMANHO_MATRIZ,
                                     std::vector<int>(TAMANHO_MATRIZ));

void inicializarMatriz() {
  for (int i = 0; i < TAMANHO_MATRIZ; ++i) {
    std::iota(matriz[i].begin(), matriz[i].end(), 0); // Preenche cada linha
  }
}

// Acesso Row-Major (por linha) - Boa localidade de cache
long long somarPorLinha() {
  long long soma = 0;
  for (int i = 0; i < TAMANHO_MATRIZ; ++i) {
    for (int j = 0; j < TAMANHO_MATRIZ; ++j) {
      soma += matriz[i][j];
    }
  }
  return soma;
}

// Acesso Column-Major (por coluna) - Ruim localidade de cache
long long somarPorColuna() {
  long long soma = 0;
  for (int j = 0; j < TAMANHO_MATRIZ; ++j) { // Loop externo itera sobre colunas
    for (int i = 0; i < TAMANHO_MATRIZ;
         ++i) { // Loop interno itera sobre linhas
      soma += matriz[i][j];
    }
  }
  return soma;
}

int main() {
  inicializarMatriz();

  std::cout << "Demonstrando o impacto da Localidade de Cache em matrizes.\n";
  std::cout << "Tamanho da matriz: " << TAMANHO_MATRIZ << "x" << TAMANHO_MATRIZ
            << '\n';
  std::cout << "Numero de repeticoes: " << NUM_REPETICOES << '\n';

  // Medir tempo para acesso por linha
  double tempoTotalLinha = 0;
  long long resultadoLinha = 0;
  for (int rep = 0; rep < NUM_REPETICOES; ++rep) {
    auto inicio = std::chrono::high_resolution_clock::now();
    resultadoLinha = somarPorLinha();
    auto fim = std::chrono::high_resolution_clock::now();
    tempoTotalLinha +=
        std::chrono::duration<double, std::milli>(fim - inicio).count();
  }
  std::cout << "\nTempo medio (acesso por linha - Row-Major): "
            << tempoTotalLinha / NUM_REPETICOES
            << " ms (Soma: " << resultadoLinha << ")\n";

  // Medir tempo para acesso por coluna
  double tempoTotalColuna = 0;
  long long resultadoColuna = 0;
  for (int rep = 0; rep < NUM_REPETICOES; ++rep) {
    auto inicio = std::chrono::high_resolution_clock::now();
    resultadoColuna = somarPorColuna();
    auto fim = std::chrono::high_resolution_clock::now();
    tempoTotalColuna +=
        std::chrono::duration<double, std::milli>(fim - inicio).count();
  }
  std::cout << "Tempo medio (acesso por coluna - Column-Major): "
            << tempoTotalColuna / NUM_REPETICOES
            << " ms (Soma: " << resultadoColuna << ")\n";

  std::cout << "\nObserve a grande diferença de tempo. Isso se deve à "
               "localidade de cache.\n";

  return 0;
}

/*
  Explicação: Localidade de Cache em Matrizes (Row-Major vs Column-Major)

  Este exemplo demonstra de forma prática o impacto da localidade de cache
  ao iterar sobre uma matriz 2D.

  **Como Matrizes são Armazenadas na Memória (em C++):**
  Em C++ (e C), matrizes são armazenadas em "Row-Major Order". Isso significa
  que:
  -   Todos os elementos da primeira linha são armazenados sequencialmente.
  -   Em seguida, todos os elementos da segunda linha são armazenados
  sequencialmente.
  -   E assim por diante.
  Ou seja, `matriz[i][j]` e `matriz[i][j+1]` estão próximos na memória,
  enquanto `matriz[i][j]` e `matriz[i+1][j]` estão distantes.

  **`somarPorLinha()` (Acesso Row-Major):**
  -   O loop externo itera sobre as linhas (`i`).
  -   O loop interno itera sobre as colunas (`j`).
  -   Isso significa que os acessos à memória (`matriz[i][j]`, `matriz[i][j+1]`,
  ...) são sequenciais.
  -   Quando `matriz[i][j]` é acessado, a CPU busca uma "cache line" da RAM
      que contém `matriz[i][j]` e vários de seus vizinhos na mesma linha.
  -   Os acessos subsequentes (`matriz[i][j+1]`, `matriz[i][j+2]`, etc.)
      encontram os dados já no cache (cache hit), que é muito rápido.
  -   **Resultado:** Performance excelente devido à alta localidade de cache.

  **`somarPorColuna()` (Acesso Column-Major):**
  -   O loop externo itera sobre as colunas (`j`).
  -   O loop interno itera sobre as linhas (`i`).
  -   Isso significa que os acessos à memória (`matriz[i][j]`, `matriz[i+1][j]`,
  ...) são não sequenciais (com um "stride" grande).
  -   Quando `matriz[i][j]` é acessado, a CPU busca uma cache line.
  -   Quando `matriz[i+1][j]` é acessado, é muito provável que ele esteja em
      uma cache line diferente, forçando a CPU a buscar uma nova cache line
      da RAM (cache miss). Isso é muito mais lento.
  -   **Resultado:** Performance significativamente pior devido à baixa
  localidade de cache.

  **Implicações para HFT:**
  -   **Data-Oriented Design (DOD):** Este é um princípio fundamental do DOD.
      Organizar seus dados e algoritmos para maximizar o acesso sequencial
      e a localidade de cache é uma das otimizações mais impactantes em HFT.
  -   **Evitar Acessos com Stride Grande:** Sempre que possível, projete suas
      estruturas de dados e seus loops para que os acessos à memória sejam
      o mais sequenciais possível.
  -   **Impacto em Latência:** Um "cache miss" pode custar centenas de ciclos
      de CPU, o que é inaceitável em sistemas de baixa latência. Entender e
      mitigar isso é crucial para alcançar o Nível 5 de proficiência.
*/