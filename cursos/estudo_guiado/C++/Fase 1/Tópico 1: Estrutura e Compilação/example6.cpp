#include <iostream>

int main() {
  // O resultado de uma expressão aritmética pode ser impresso diretamente.
  // A expressão 5 + 3 é avaliada primeiro (resultando em 8),
  // e então o resultado é enviado para o std::cout.
  std::cout << "Cinco mais três é: " << 5 + 3 << '\n';

  return 0;
}

/*

A linguagem C++ avalia a expressão 5 + 3 antes de passá-la para o operador <<.
O resultado, 8, é então inserido no std::cout.
Isso mostra que podemos realizar cálculos diretamente na instrução de saída.

*/