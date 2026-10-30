#include <iostream>

int main() {
  int a = 10;
  int b = 20;

  // A variável 'maior' recebe 'a' se a > b, senão recebe 'b'
  int maior = (a > b) ? a : b;

  std::cout << "Entre " << a << " e " << b << ", o maior eh: " << maior << '\n';

  // O mesmo princípio, mas para atribuir um ponteiro a uma string literal
  const char *status = (maior > 15) ? "Maior que 15" : "Nao eh maior que 15";
  std::cout << "Status: " << status << '\n';

  return 0;
}

/*
  Este exemplo introduz o operador ternário (?:), uma alternativa compacta
  para uma instrução if-else simples, muito comum em C++.

  Sintaxe: condicao ? valor_se_verdadeiro : valor_se_falso;

  Performance: Geralmente, o compilador otimiza o operador ternário para o mesmo
  código de máquina de um if-else, resultando em performance idêntica. A escolha
  é mais por legibilidade e concisão do que por velocidade.

  Nota sobre `const char*`: Usamos ponteiros para char (C-style strings) em vez
  de `std::string` no segundo exemplo. Isso é uma micro-otimização deliberada.
  A criação de um `std::string` poderia envolver alocação de memória no Heap,
  enquanto usar `const char*` apenas copia um endereço de memória (8 bytes em
  sistemas 64-bit), sendo uma operação extremamente rápida e sem sobrecarga.
*/