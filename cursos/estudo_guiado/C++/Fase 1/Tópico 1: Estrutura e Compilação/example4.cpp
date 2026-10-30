#include <iostream>

int main() {
  // O operador << pode ser encadeado para imprimir múltiplas coisas
  // em uma única instrução.
  std::cout << "Olá, " << "Mundo" << "!" << '\n';

  return 0;
}

/*

  Este exemplo mostra que o operador << pode ser "encadeado".
  A execução acontece da esquerda para a direita. Primeiro, "Olá, " é inserido
  no std::cout, depois "Mundo" é inserido, e assim por diante. É funcionalmente
  idêntico a ter múltiplas linhas de std::cout, mas pode ser mais conciso.

*/
