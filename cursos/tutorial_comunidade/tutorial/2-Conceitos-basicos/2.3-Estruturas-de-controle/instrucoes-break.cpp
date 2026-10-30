#include <iostream>

int main() {
  for (int i = 1; i <= 100; i = i + 1) {
    std::cout << "Iteração #" << i << '\n' << "Você deseja continuar? [s/n]: ";

    char op;
    std::cin >> op;
    if (op == 'n') {
      break;
    }

    std::cout << "Incrementando i..." << std::endl;
  }

  return 0;
}
