#include <iomanip>
#include <iostream>

int main() {
  double a = 0.1;
  double b = 0.2;
  double soma = a + b;

  std::cout << std::setprecision(20);
  std::cout << "0.1 + 0.2 = " << soma << '\n';
  // A saída provavelmente não será exatamente 0.3!

  if (soma == 0.3) {
    std::cout << "A soma é igual a 0.3\n";
  } else {
    std::cout << "A soma NAO é igual a 0.3\n";
  }

  return 0;
}

/*
  Números de ponto flutuante não conseguem representar todos os valores decimais
  de forma exata na memória binária. O valor 0.1, por exemplo, é uma dízima
  periódica em binário. Este exemplo mostra que 0.1 + 0.2 não resulta em
  exatamente 0.3.

  A consequência direta é: nunca compare números de ponto flutuante para
  igualdade exata usando `==`. Em vez disso, verifica-se se a diferença entre
  eles é menor que uma pequena tolerância (epsilon).
*/