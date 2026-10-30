#include <iomanip> // Necessário para std::setprecision
#include <iostream>

int main() {
  // 'float' é um número de ponto flutuante de precisão simples.
  float precoGasolina =
      5.799f; // O sufixo 'f' é recomendado para literais float

  // 'double' é um número de ponto flutuante de precisão dupla. É o padrão para
  // decimais.
  double constantePi = 3.141592653589793;

  // std::setprecision controla o número de dígitos a serem exibidos
  std::cout << std::fixed << std::setprecision(3);
  std::cout << "Preco da Gasolina (float): " << precoGasolina << '\n';

  std::cout << std::fixed << std::setprecision(15);
  std::cout << "Constante Pi (double): " << constantePi << '\n';

  return 0;
}

/*

  float e double são usados para números com casas decimais.
  double tem o dobro da precisão do float (por isso o nome "dupla precisão")
  e é geralmente a escolha preferida, a menos que você tenha uma razão
  muito forte para economizar memória (como em arrays gigantes de dados
  gráficos). O uso de std::setprecision nos ajuda a visualizar a diferença na
  precisão que cada tipo pode manter.

*/