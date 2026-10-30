// terceiro.cpp - erros de semântica

#include <iostream>

using namespace std;

int main() {
  int dias; // declaração de variável
  cout << "Numero de dias: ";
  cin >> dias; // Lê o valor de uma variável

  int horas = dias * 24;
  cout << dias << "dias tem " << horas << " horas." << endl;

  return 0;
}