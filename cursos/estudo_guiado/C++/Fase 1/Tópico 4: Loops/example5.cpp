#include <iostream>

int main() {
  // Loop 'for' básico para iterar um número fixo de vezes
  std::cout << "Contagem progressiva:\n";
  for (int i = 0; i < 5; ++i) {
    // Imprime o valor de 'i' em cada iteração
    std::cout << "i = " << i << '\n';
  }

  std::cout << "\nContagem regressiva:\n";
  // Loop 'for' para contagem regressiva
  for (int j = 5; j > 0; --j) {
    // Imprime o valor de 'j' em cada iteração
    std::cout << "j = " << j << '\n';
  }

  std::cout << "\nContagem com passo de 2:\n";
  // Loop 'for' com inicialização e incremento mais complexos
  for (int k = 0; k < 10; k += 2) {
    // Imprime o valor de 'k' em cada iteração
    std::cout << "k = " << k << '\n';
  }

  return 0;
}

/*
  Este exemplo demonstra o loop `for`, uma das estruturas de repetição mais
  comuns e flexíveis em C++. Ele é ideal quando o número de iterações é
  conhecido ou pode ser determinado no início do loop.

  Sintaxe do `for` loop:
  `for (inicializacao; condicao; incremento/decremento)`

  O que observar:
  1. `inicializacao`: Executada apenas uma vez no início do loop.
     (Ex: `int i = 0;`)
  2. `condicao`: Avaliada antes de cada iteração. Se for verdadeira, o loop
  continua. Se for falsa, o loop termina. (Ex: `i < 5;`)
  3. `incremento/decremento`: Executado após cada iteração do corpo do loop.
     (Ex: `++i;` ou `k += 2;`)

  Performance (Baixa Latência):
  Loops `for` são geralmente muito eficientes. O compilador pode otimizá-los
  agressivamente, inclusive com técnicas como "loop unrolling" (desenrolamento
  de loop), onde várias iterações são combinadas em uma única sequência de
  instruções para reduzir o overhead de controle do loop e melhorar a
  utilização do pipeline da CPU.

  Para HFT, é crucial que os loops sejam previsíveis e que o trabalho dentro
  deles seja o mais leve possível. Evitar chamadas de função caras ou alocações
  de memória dentro de loops críticos é uma prática fundamental.
*/