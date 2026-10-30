#include <iostream>

void wont_change_data(int a) {
  a = 1;
}

void will_change_data(int& a) {
  a = 1;
}

int main() {
  int my_a = 8;
  std::cout << my_a << std::endl;
  // Saída: 8
  wont_change_data(my_a);
  std::cout << my_a << std::endl;
  // Saída: 8
  will_change_data(my_a);
  std::cout << my_a << std::endl;
  // Saída: 1
}
