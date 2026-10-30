#include <iostream>

// Função que recebe dois números inteiros e retorna a soma deles.
// O 'int' antes do nome da função indica que ela retornará um valor inteiro.
int somarNumeros(int a, int b) {
  // O comando 'return' envia o resultado da expressão de volta para quem chamou
  // a função.
  return a + b;
}

// Função que recebe um número e retorna o seu dobro.
int dobrar(int valor) { return valor * 2; }

int main() {
  std::cout << "Iniciando o programa de calculos com funcoes.\n";

  int num1 = 15;
  int num2 = 7;

  // Chamando a função 'somarNumeros' e armazenando seu valor de retorno.
  int resultadoSoma = somarNumeros(num1, num2);
  std::cout << "A soma de " << num1 << " e " << num2 << " eh: " << resultadoSoma
            << '\n';

  // Chamando a função 'dobrar' diretamente dentro de um std::cout.
  std::cout << "O dobro de 12 eh: " << dobrar(12) << '\n';

  // O valor de retorno pode ser usado em expressões.
  int triploDeCinco = somarNumeros(dobrar(5), 5); // (5*2) + 5 = 15
  std::cout << "O triplo de 5 (dobrar(5) + 5) eh: " << triploDeCinco << '\n';

  std::cout << "Programa finalizado.\n";

  return 0;
}

/*
  Este exemplo demonstra como as funções podem retornar valores para o código
  que as chamou.

  O que observar:
  - **Tipo de Retorno:** O tipo especificado antes do nome da função (ex: `int`)
    indica o tipo de dado que a função irá retornar. Se a função não retorna
    nada, usa-se `void`.
  - **Instrução `return`:** É usada para enviar o valor de volta ao chamador
    e, ao mesmo tempo, encerrar a execução da função.
  - **Uso do Valor de Retorno:** O valor retornado pode ser armazenado em uma
    variável, usado diretamente em uma expressão ou passado como argumento
    para outra função.

  Performance (Baixa Latência):
  - Para tipos de dados pequenos e simples (como `int`, `double`, `bool`),
    retornar por valor é muito eficiente. O compilador frequentemente otimiza
    isso usando "Return Value Optimization" (RVO) ou "Named Return Value
    Optimization" (NRVO), que evitam a cópia do objeto retornado.
  - Para tipos de dados maiores e mais complexos, retornar por valor pode
    ser custoso devido à cópia. Veremos em exemplos futuros como otimizar
    o retorno de objetos complexos.
  - A clareza e a modularidade que as funções com retorno trazem são
    fundamentais para a organização do código, mesmo em ambientes de
    alta performance.
*/