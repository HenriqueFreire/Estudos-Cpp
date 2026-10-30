// Inclui a biblioteca de Input/Output Stream (Fluxo de Entrada/Saída)
#include <iostream>

// A função main é o ponto de entrada de qualquer programa C++
int main() {
  // std::cout envia dados para a saída padrão (o terminal)
  // << é o operador de inserção de stream
  // "Olá, Mundo!" é a string literal que queremos imprimir
  std::cout << "Olá, Mundo!";

  // Retorna 0 para o sistema operacional, indicando que o programa terminou com
  // sucesso
  return 0;
}

/*

Este é o programa mais fundamental.
Ele usa a biblioteca iostream para ter acesso ao std::cout.
A função main é executada, e dentro dela,
std::cout é usado com o operador << para "inserir" a string "Olá, Mundo!" no
fluxo de saída, que é o seu terminal. O return 0; sinaliza que tudo ocorreu como
esperado.

*/
