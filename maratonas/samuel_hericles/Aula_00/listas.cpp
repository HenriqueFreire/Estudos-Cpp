#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  vector<string> lista1;
  int lista2[] = {1, 9, 2, 50, 0};

  lista1.push_back("Elemento0");

  cout << "Tamanho da lista1: " << lista1.size() << "\n";
  cout << "1º elemento em lista1: " << lista1[0] << "\n";
  cout << "1º elemento em lista2: " << lista2[0] << "\n";

  cout << "Lista1: ";
  for (auto e : lista1) {
    cout << e << " ";
  }
  cout << "\n";

  cout << "Lista2: ";
  for (int i = 0; i < 5; ++i) {
    cout << lista2[i] << " ";
  }
  cout << "\n";

  return 0;
}
