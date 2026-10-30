#include <iostream>

int main() {
  int age = 0;
  double const price = 20.0;
  std::cout << "Insira sua idade: ";
  std::cin >> age;

  std::cout << "Sua idade é " << age << '\n';

  if (age <= 10) {
    std::cout << "Você não precisa pagar!\n";
  } else if (age > 50) {
    std::cout << "Você paga apenas " << price / 2 << "!\n";
  } else {
    std::cout << "Você paga " << price << ".\n";
  }
}
