#include <iostream>

int calculate_sum(int a, int b) {
  int sum = 0;
  for (int i = a; i <= b; ++i) {
    sum += i;
  }
  return sum;
}

int main() {
  int a = 0;
  int b = 0;
  std::cout << "Digite o valor de A: ";
  std::cin >> a;
  std::cout << "Digite o valor de B: ";
  std::cin >> b;

  std::cout << "Sum [" << a << ", " << b << "] = " << calculate_sum(a, b) << std::endl;

  return 0;
}
