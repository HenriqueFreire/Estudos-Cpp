// primeiro.cpp - mostra uma mensagem
// Este programa demonstra a saída de texto simples no console usando C++.

#include <iostream> // Inclui a biblioteca iostream, que fornece funcionalidades para entrada e saída de dados.
    // 'iostream' significa 'input/output stream' (fluxo de entrada/saída).

using namespace std; // Usa o namespace 'std' (standard). Isso evita que
                     // tenhamos que escrever 'std::' antes de cada função ou
                     // objeto padrão (como 'cout' e 'endl').

int main() { // A função 'main' é o ponto de entrada de qualquer programa C++.
             // O tipo de retorno 'int' indica que a função retornará um número
             // inteiro.

  cout << "Bem vindo ao C++"; // 'cout' (console output) é um objeto usado para
                              // imprimir dados no console. O operador '<<' é o
                              // operador de inserção, que "insere" a string
                              // "Bem vindo ao C++" no fluxo de saída.
  cout << endl; // 'endl' (end line) é um manipulador de fluxo que insere um
                // caractere de nova linha e descarrega o buffer de saída,
                // garantindo que o texto seja exibido imediatamente.
  cout << "Meu primeiro programa" << endl; // Combina a impressão de uma string
                                           // e a inserção de uma nova linha.

  return 0; // 'return 0' indica que o programa foi executado com sucesso.
            // É uma convenção comum em C++ para indicar uma saída bem-sucedida.
}