#include <iostream>

using namespace std;

int main() {
  float comprimento;
  float largura;
  float altura;

  cout << "Digite o comprimento, largura e altura:\n";
  cin >> comprimento >> largura >> altura;

  float volume = comprimento * largura * altura;

  cout << "O volume total é: " << volume << endl;

  return 0;
}