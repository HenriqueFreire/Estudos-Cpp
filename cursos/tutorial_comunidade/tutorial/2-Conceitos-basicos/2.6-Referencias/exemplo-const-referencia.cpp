#include <iostream>

using Matrix = double[100][100];

/**
 * Esta função recebe a matriz por REFERÊNCIA CONSTANTE (& + const).
 *
 * 1. O '&' garante que NÃO haverá cópia (Performance de referência).
 * 2. O 'const' garante que a função NÃO pode alterar a matriz (Imutabilidade).
 */
double sum_elements(const Matrix& matrix) {
  double sum = 0.0;

  // Tentar descomentar a linha abaixo causará um erro de compilação:
  // matrix[0][0] = 10.0;

  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 100; ++j) {
      sum += matrix[i][j];
    }
  }
  return sum;
}

int main() {
  // Inicializamos a matriz
  static Matrix my_matrix = {};
  my_matrix[0][0] = 42.0;

  std::cout << "Valor original antes da soma: " << my_matrix[0][0] << std::endl;

  // Chamada eficiente: passa apenas o endereço da matriz
  double result = sum_elements(my_matrix);

  std::cout << "Soma total: " << result << std::endl;
  std::cout << "Valor original depois da soma (continua igual): " << my_matrix[0][0] << std::endl;

  return 0;
}
