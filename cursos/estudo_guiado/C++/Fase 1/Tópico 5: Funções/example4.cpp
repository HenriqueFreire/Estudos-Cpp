#include <iostream>
#include <string>

// Função 'somar' para dois inteiros
int somar(int a, int b) {
  std::cout << "Chamando somar(int, int)\n";
  return a + b;
}

// Sobrecarga da função 'somar' para dois doubles
double somar(double a, double b) {
  std::cout << "Chamando somar(double, double)\n";
  return a + b;
}

// Sobrecarga da função 'somar' para três inteiros
int somar(int a, int b, int c) {
  std::cout << "Chamando somar(int, int, int)\n";
  return a + b + c;
}

// Função 'imprimir' para um inteiro
void imprimir(int valor) { std::cout << "Imprimindo int: " << valor << '\n'; }

// Sobrecarga da função 'imprimir' para uma string
void imprimir(const std::string &texto) {
  std::cout << "Imprimindo string: " << texto << '\n';
}

int main() {
  std::cout << "Demonstrando Sobrecarga de Funcoes (Function Overloading).\n\n";

  // O compilador escolhe a versão correta de 'somar' com base nos tipos dos
  // argumentos
  std::cout << "Soma de inteiros: " << somar(5, 10) << '\n';
  std::cout << "Soma de doubles: " << somar(3.5, 2.1) << '\n';
  std::cout << "Soma de tres inteiros: " << somar(1, 2, 3) << '\n';

  std::cout << '\n';

  // O compilador escolhe a versão correta de 'imprimir'
  imprimir(100);
  imprimir("Ola, mundo da sobrecarga!");

  std::cout << "\nPrograma finalizado.\n";

  return 0;
}

/*
  Este exemplo demonstra a sobrecarga de funções (function overloading) em C++.

  O que observar:
  - **Mesmo Nome, Diferentes Parâmetros:** Você pode ter múltiplas funções com
    o mesmo nome, desde que suas "assinaturas" (a lista de tipos e número de
    parâmetros) sejam diferentes.
  - **Resolução de Sobrecarga:** O compilador é responsável por determinar qual
    versão da função chamar com base nos tipos e no número de argumentos
    fornecidos na chamada.
  - **Clareza e Consistência:** A sobrecarga permite usar um nome intuitivo
    (como `somar` ou `imprimir`) para operações conceitualmente semelhantes,
    mas que atuam sobre diferentes tipos de dados ou com diferentes quantidades
    de entradas. Isso torna o código mais legível e consistente.

  Performance (Baixa Latência):
  - A sobrecarga de funções é uma funcionalidade resolvida em **tempo de
  compilação**. Isso significa que não há overhead de performance em tempo de
  execução associado à escolha da função correta. O compilador já sabe qual
  função chamar antes mesmo do programa ser executado.
  - A performance de cada função sobrecarregada individualmente segue as
    mesmas regras de qualquer outra função (custo de chamada, passagem de
    parâmetros, etc.).
*/