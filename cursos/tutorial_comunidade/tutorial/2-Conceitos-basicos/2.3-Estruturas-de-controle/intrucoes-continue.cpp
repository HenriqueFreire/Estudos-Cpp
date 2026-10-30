#include <iostream>

int main() {
  for (int i = 1; i <= 100; i = i + 1) {
    std::cout << "Iteração #" << i << '\n' << "Você deseja pular essa iteração? [s/n]: ";

    char op;
    std::cin >> op;
    if (op == 's') {
      continue;
    }

    std::cout << "Executando o resto do corpo do laço" << std::endl;
  }

  return 0;
}
