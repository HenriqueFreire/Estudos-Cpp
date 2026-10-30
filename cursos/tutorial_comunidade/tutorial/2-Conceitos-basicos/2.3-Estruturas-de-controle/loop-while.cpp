#include <iostream>

int main() {
  char answer = '\0';

  while (answer != 's' && answer != 'n') {
    std::cout << "Você deseja aprender C++? [s/n]: ";
    std::cin >> answer;
  }

  if (answer == 's') {
    std::cout << "Esse é o espirito!\n";
  } else {
    std::cout << "Que triste...\n";
  }
}
