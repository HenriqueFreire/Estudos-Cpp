#include <iostream>

// Definindo um alias para uma matriz 100x100 de doubles
using Matrix = double[100][100];

/**
 * Soma dos elementos de uma matriz 100x100.
 * Usamos 'const Matrix&' para passar por REFERÊNCIA.
 * Isso evita a cópia de 80.000 bytes (100*100*8) a cada chamada.
 * O 'const' garante que a função não alterará a matriz original.
 */
double sum_elements(const Matrix& matrix) {
  double sum = 0.0;
  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 100; ++j) {
      sum += matrix[i][j];
    }
  }
  return sum;
}

int main() {
  // Inicializando a matriz com zeros
  // Usamos static para não sobrecarregar a stack com 80KB se necessário
  static Matrix matrix = {};
  matrix[0][0] = 1.0;

  double total_sum = 0.0;
  // Rodando 1 milhão de vezes para demonstrar o ganho de performance da referência
  for (int i = 0; i < 1000000; ++i) {
    total_sum += sum_elements(matrix);
  }

  std::cout << "Total Sum = " << total_sum << std::endl;

  return 0;
}
