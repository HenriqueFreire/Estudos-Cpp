#include <iostream>

int main() {
  // O caractere de escape '\n' dentro de uma string também cria uma nova linha.
  // É geralmente mais performático que std::endl, pois não força o flush do
  // buffer.
  std::cout << "Linha 1\nLinha 2\nLinha 3\n";

  return 0;
}

/*

Aqui, em vez de std::endl, usamos o caractere especial \n diretamente dentro da
string. O resultado visual é o mesmo do exemplo anterior (três linhas
separadas), mas \n é frequentemente preferido em código de alta performance,
pois ele apenas adiciona a quebra de linha ao buffer, sem forçar a escrita
imediata no terminal, o que pode ser uma operação custosa.

*/