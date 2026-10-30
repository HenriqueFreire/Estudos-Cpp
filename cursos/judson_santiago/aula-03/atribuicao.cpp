// atribuicao.cpp - Exemplo didático de operadores de atribuição em C++.
// Este programa demonstra como usar o operador de atribuição (=) e os
// operadores de atribuição composta (+=, -=, *=, /=, %=) para modificar o valor
// de variáveis.

#include <iostream> // Inclui a biblioteca iostream para operações de entrada e saída.

using namespace std; // Usa o namespace padrão.

int main() {
  cout << "--- Exemplos de Operadores de Atribuição em C++ ---" << endl;
  cout << "--------------------------------------------------" << endl << endl;

  // 1. Operador de Atribuição Simples (=)
  //    Atribui o valor do lado direito ao operando do lado esquerdo.
  int a = 10; // Declara 'a' e atribui o valor 10.
  int b = 5;  // Declara 'b' e atribui o valor 5.
  int c;      // Declara 'c' sem inicializar.

  cout << "Valores iniciais: a = " << a << ", b = " << b << endl;

  c = a;                                 // Atribui o valor de 'a' (10) a 'c'.
  cout << "c = a; -> c = " << c << endl; // c agora é 10.

  c = b;                                 // Atribui o valor de 'b' (5) a 'c'.
  cout << "c = b; -> c = " << c << endl; // c agora é 5.
  cout << endl;

  // 2. Operadores de Atribuição Composta
  //    São atalhos para realizar uma operação e atribuir o resultado à mesma
  //    variável.

  int x = 20;
  cout << "Valor inicial de x: " << x << endl;

  // x += 5;  equivalente a x = x + 5;
  x += 5;
  cout << "x += 5; -> x = " << x << endl; // x agora é 25.

  // x -= 10; equivalente a x = x - 10;
  x -= 10;
  cout << "x -= 10; -> x = " << x << endl; // x agora é 15.

  // x *= 2;  equivalente a x = x * 2;
  x *= 2;
  cout << "x *= 2; -> x = " << x << endl; // x agora é 30.

  // x /= 3;  equivalente a x = x / 3;
  x /= 3;
  cout << "x /= 3; -> x = " << x << endl; // x agora é 10.

  // x %= 4;  equivalente a x = x % 4; (resto da divisão)
  x %= 4;
  cout << "x %= 4; -> x = " << x
       << endl; // x agora é 2 (10 dividido por 4 é 2 com resto 2).
  cout << endl;

  // 3. Atribuição em cadeia (não recomendada para clareza)
  int d, e, f;
  d = e = f =
      100; // Atribui 100 a f, depois o valor de f a e, depois o valor de e a d.
  cout << "Atribuição em cadeia: d = e = f = 100;" << endl;
  cout << "d = " << d << ", e = " << e << ", f = " << f << endl;
  cout << endl;

  return 0; // Indica que o programa foi executado com sucesso.
}