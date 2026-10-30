// Inclui a biblioteca necessária para entrada e saída de dados
#include <iostream>

// Ponto de entrada do programa
int main() {
  // Imprime a primeira linha de texto
  std::cout << "Está é a primeira linha.";

  // std::endl insere um caractere de nova linha e descarrega o buffer de saída
  std::cout << std::endl;

  // Imprime a segunda linha de texto
  std::cout << "Está é a segunda linha.";

  // É uma boa prática a última linha de saída com um nova linha também
  std::cout << std::endl;

  return 0;
}

/*

A principal diferença aqui é o uso de std::endl. Ele faz duas coisas:
  1. Insere um caractere de quebra de linha (\n).
  2. Força o "descarregamento" (flush) do buffer de saída, garantindo que o
texto seja exibido na tela imediatamente. Em programas simples, a diferença não
é notável, mas em sistemas complexos pode ser importante.

*/