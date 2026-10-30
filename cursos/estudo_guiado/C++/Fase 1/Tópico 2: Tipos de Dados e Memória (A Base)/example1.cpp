#include <iostream>

int main() {
  // 'int' é o tipo de inteiro mais comum. Adequado para a maioria dos casos.
  int numeroDeGols = 3;

  // 'long long' é usado para números inteiros que podem ser muito grandes.
  // A população da Terra, por exemplo, não caberia em um 'int' padrão.
  long long populacaoDaTerra =
      8000000000LL; // O sufixo LL indica que é um long long

  std::cout << "Gols na partida: " << numeroDeGols << '\n';
  std::cout << "Populacao da Terra: " << populacaoDaTerra << '\n';

  return 0;
}

/*

  int e long long são tipos para armazenar números inteiros.
  A principal diferença é a capacidade de armazenamento.
  Um int geralmente ocupa 4 bytes e pode armazenar valores
  de aproximadamente -2 bilhões a +2 bilhões.
  Um long long ocupa 8 bytes, permitindo armazenar números muito maiores.
  A escolha entre eles é uma troca entre a capacidade e o uso de memória.

*/