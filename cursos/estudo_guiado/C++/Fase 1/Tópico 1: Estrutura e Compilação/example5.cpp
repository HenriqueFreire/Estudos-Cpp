#include <iostream>

int main() {
  // std::cout não se limita a imprimir apenas texto (strings).
  // Ele pode imprimir tipos de dados fundamentais, como números inteiros.
  std::cout << "O número da sorte é: " << 7 << '\n';

  return 0;
}

/*

  std::cout é inteligente. Graças à "sobrecarga de operadores" (um tópico da
  Fase 2), ele sabe como manusear diferentes tipos de dados. Aqui, ele entende
  que 7 é um número inteiro e o converte para uma representação de texto para
  ser exibido no terminal.

*/