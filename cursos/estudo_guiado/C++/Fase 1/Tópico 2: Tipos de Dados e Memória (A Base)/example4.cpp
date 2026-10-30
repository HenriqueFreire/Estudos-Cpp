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
  sizeof() é uma ferramenta poderosa para entender como a memória está sendo
  usada. Ele nos diz exatamente quantos bytes cada tipo de dado consome. Saber
  isso é crucial em programação de baixa latência, onde o layout da memória e o
  seu consumo são de extrema importância para o desempenho (por exemplo, para
  caber dados na cache da CPU). Os tamanhos podem variar dependendo da
  arquitetura (32-bit vs 64-bit), mas os mostrados aqui são os mais comuns em
  sistemas modernos.
*/