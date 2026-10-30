#include <iostream>

using namespace std;

int main() {

  cout << "Que horas são?";

  int horas, mins;
  char pontos;

  cin >> horas;
  cin >> pontos;
  cin >> mins;

  cout << horas << " horas\n";
  cout << "e\n";
  cout << mins << " minutos\n";

  return 0;
}