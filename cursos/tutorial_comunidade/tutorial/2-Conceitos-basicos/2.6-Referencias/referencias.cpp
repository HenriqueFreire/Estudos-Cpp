#include <iostream>

int main() {
  int a = 1;
  int& b = a;
  // Já que a variável 'b' se refere a 'a',
  b = 7;
  // então atribuir '7' para 'b' significa atribuir '7' para 'a'.
  std::cout << "a = " << a << ", b = " << b << std::endl;

  return 0;
}
