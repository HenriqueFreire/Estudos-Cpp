#include <iostream>

int main() {
  // 'short' pode usar menos memória que 'int' (geralmente 2 bytes).
  short temperaturaMinima = -10;

  // 'unsigned' remove a capacidade de armazenar números negativos,
  // dobrando o alcance positivo do tipo.
  unsigned int numeroDeItens = 150;
  // Um 'unsigned int' não pode ser -1.

  std::cout << "Temperatura minima: " << temperaturaMinima << " (short)\n";
  std::cout << "Numero de itens: " << numeroDeItens << " (unsigned int)\n";
  std::cout << "Tamanho de short: " << sizeof(short) << " bytes\n";
  std::cout << "Tamanho de unsigned int: " << sizeof(unsigned int)
            << " bytes\n";

  return 0;
}

/*
  Modificadores como short, long, e unsigned alteram as propriedades dos tipos
  base (como int). unsigned é particularmente importante: se você sabe que uma
  variável nunca será negativa (como uma contagem de itens ou um índice de
  array), declará-la como unsigned não só documenta essa intenção, mas também
  dobra a quantidade de valores positivos que ela pode armazenar no mesmo espaço
  de memória.
*/