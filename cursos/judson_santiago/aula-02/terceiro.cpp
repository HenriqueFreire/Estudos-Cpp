// terceiro.cpp - Demonstra a entrada de dados do usuário e cálculos simples.
// Este programa solicita ao usuário um número de dias e calcula o número
// correspondente de horas.

#include <iostream> // Inclui a biblioteca iostream para operações de entrada e saída.

using namespace std; // Usa o namespace padrão para facilitar o acesso a funções
                     // como 'cout' e 'cin'.

int main() { // Função principal, ponto de entrada do programa.
  int dias; // Declaração de uma variável inteira chamada 'dias' para armazenar
            // a entrada do usuário.
  cout
      << "Numero de dias: "; // Solicita ao usuário que insira o número de dias.
  cin >>
      dias; // 'cin' (console input) é um objeto usado para ler dados do
            // teclado. O operador '>>' é o operador de extração, que "extrai" o
            // valor digitado pelo usuário e o armazena na variável 'dias'.

  int horas = dias * 24; // Declara uma nova variável inteira 'horas' e atribui
                         // a ela o resultado do cálculo: o número de dias
                         // multiplicado por 24 (horas em um dia).
  cout << dias << " dias tem " << horas << " horas."
       << endl; // Imprime o resultado, mostrando quantos dias
                // foram inseridos e o total de horas calculado.

  return 0; // Retorna 0 para indicar que o programa foi executado com sucesso.
}