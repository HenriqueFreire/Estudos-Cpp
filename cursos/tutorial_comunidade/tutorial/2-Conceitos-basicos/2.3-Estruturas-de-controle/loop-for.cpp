#include <iostream>

int main() {
  int a = 0;
  int b = 0;

  std::cout << "Digite o valor de A: ";
  std::cin >> a;

  std::cout << "Digite o valor de B: ";
  std::cin >> b;

  int sum = 0;

  for (int i = a; i <= b; ++i) {
    sum += 1;
  }

  std::cout << "Sum [" << a << ", " << b << "] = " << sum << std::endl;

  return 0;
}
