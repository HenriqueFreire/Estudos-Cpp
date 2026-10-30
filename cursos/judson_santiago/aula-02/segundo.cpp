// segundo.cpp - Demonstra a declaração, atribuição e manipulação de variáveis
// inteiras. Este programa ilustra como declarar uma variável, atribuir um valor
// a ela, exibi-la no console e modificar seu valor.

#include <iostream> // Inclui a biblioteca iostream para operações de entrada e saída.

using namespace std; // Usa o namespace padrão para facilitar o acesso a funções
                     // como 'cout' e 'endl'.

int main() {     // Função principal, ponto de entrada do programa.
  int cenouras;  // Declaração de uma variável inteira chamada 'cenouras'.
                 // 'int' é o tipo de dado que armazena números inteiros.
  cenouras = 25; // Atribuição de um valor inicial (25) à variável 'cenouras'.

  cout << "Eu tenho " << cenouras << " cenouras."
       << endl; // Imprime uma string literal, o valor da variável 'cenouras',
                // outra string literal e uma nova linha.

  cenouras = cenouras - 1; // Decrementa o valor da variável 'cenouras' em 1.
                           // O novo valor de 'cenouras' será 24.

  cout << "Agora eu tenho " << cenouras << " cenouras."
       << endl; // Imprime a nova quantidade de cenouras.

  return 0; // Retorna 0 para indicar que o programa foi executado com sucesso.
}