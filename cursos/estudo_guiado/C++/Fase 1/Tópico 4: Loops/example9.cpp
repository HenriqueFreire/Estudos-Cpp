#include <chrono>
#include <iostream>
#include <vector>

const int ROWS = 1000;
const int COLS = 1000;

// Matriz global para evitar que o otimizador remova o código
int matrix[ROWS][COLS];

void preencherMatrix() {
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      matrix[i][j] = i + j;
    }
  }
}

void iteracao_row_major() {
  volatile long long sum = 0; // volatile para evitar otimizações excessivas
  for (int i = 0; i < ROWS; ++i) {   // Loop externo itera sobre as linhas
    for (int j = 0; j < COLS; ++j) { // Loop interno itera sobre as colunas
      sum += matrix[i][j];
    }
  }
}

void iteracao_col_major() {
  volatile long long sum = 0;
  for (int j = 0; j < COLS; ++j) {   // Loop externo itera sobre as colunas
    for (int i = 0; i < ROWS; ++i) { // Loop interno itera sobre as linhas
      sum += matrix[i][j];
    }
  }
}

int main() {
  preencherMatrix();

  auto start = std::chrono::high_resolution_clock::now();
  iteracao_row_major();
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> row_major_time = end - start;
  std::cout << "Tempo de iteracao Row-Major (ideal): " << row_major_time.count()
            << " ms\n";

  start = std::chrono::high_resolution_clock::now();
  iteracao_col_major();
  end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> col_major_time = end - start;
  std::cout << "Tempo de iteracao Col-Major (ruim): " << col_major_time.count()
            << " ms\n";

  return 0;
}

/*
  Este exemplo demonstra um dos conceitos mais importantes em otimização de C++:
  a localidade de dados (data locality) e como a ordem de iteração em loops
  aninhados afeta drasticamente a performance.

  O que observar:
  Em C++, matrizes 2D são armazenadas na memória em "row-major order". Isso
  significa que a linha 0 inteira é seguida pela linha 1 inteira, e assim por
  diante. `matrix[0][0], matrix[0][1], ..., matrix[1][0], matrix[1][1], ...`

  1. `iteracao_row_major`: Itera sobre a matriz da mesma forma que ela está
     disposta na memória (acessos sequenciais).
  2. `iteracao_col_major`: Itera "pulando" pela memória. Acessa `matrix[0][0]`,
     depois `matrix[1][0]`, `matrix[2][0]`, etc.

  Performance (Baixa Latência):
  A diferença de tempo entre as duas funções será enorme. Isso ocorre por causa
  do **cache da CPU**.

  - **Cache Lines:** A CPU não lê dados da RAM byte por byte. Ela busca blocos
    de memória de tamanho fixo, chamados "cache lines" (tipicamente 64 bytes).
  - **Row-Major (Ideal):** Quando você acessa `matrix[i][0]`, a CPU carrega a
    cache line que contém `matrix[i][0]`, `matrix[i][1]`, ..., `matrix[i][15]`.
    Os próximos 15 acessos do seu loop interno já estão no cache L1, que é
    extremamente rápido. Isso é chamado de "cache hit".
  - **Col-Major (Ruim):** Quando você acessa `matrix[0][0]` e depois
  `matrix[1][0]`, esses dois elementos estão muito distantes na memória. Cada
  acesso provavelmente exigirá que a CPU busque uma nova cache line da RAM, um
  processo muito lento. Isso é chamado de "cache miss".

  Em HFT, entender como seus dados são dispostos na memória e como o hardware
  interage com eles é fundamental. Escrever loops que respeitam a localidade
  de dados é uma das otimizações mais impactantes que existem.
*/
