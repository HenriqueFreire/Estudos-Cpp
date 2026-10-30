#include <iostream>

int main() {
  // Exemplo com 'break': interrompe o loop completamente
  std::cout << "Exemplo com 'break':\n";
  for (int i = 0; i < 10; ++i) {
    if (i == 5) {
      std::cout << "Encontrei 5, saindo do loop com 'break'.\n";
      break; // Sai do loop 'for'
    }
    std::cout << "i = " << i << '\n';
  }

  std::cout << '\n';

  // Exemplo com 'continue': pula a iteração atual e vai para a próxima
  std::cout << "Exemplo com 'continue':\n";
  for (int j = 0; j < 10; ++j) {
    if (j % 2 != 0) { // Se 'j' for ímpar
      std::cout << "Encontrei um numero impar (" << j
                << "), pulando com 'continue'.\n";
      continue; // Pula o restante do corpo do loop para esta iteração
    }
    std::cout << "j = " << j << " (numero par)\n";
  }

  return 0;
}

/*
  Este exemplo demonstra as instruções `break` e `continue`, que fornecem
  controle mais granular sobre o fluxo de execução dentro de loops.

  O que observar:
  - `break`: Interrompe a execução do loop mais interno em que está contido
    e transfere o controle para a instrução imediatamente após o loop.
    É útil quando uma condição específica é atendida e não há necessidade
    de continuar as iterações restantes.
  - `continue`: Pula o restante do corpo da iteração atual do loop mais
    interno e passa para a próxima iteração (reavaliando a condição do loop).
    É útil quando você quer pular o processamento de certos casos dentro de
    uma iteração, mas continuar com as próximas iterações.

  Performance (Baixa Latência):
  O uso de `break` e `continue` pode, na verdade, melhorar a performance em
  certos cenários, pois permite sair de um loop ou pular trabalho desnecessário
  mais cedo. No entanto, como são instruções de controle de fluxo, elas
  introduzem branches.

  Para HFT, a consideração é a mesma dos `if`s:
  - **Previsibilidade:** Se o `break` ou `continue` for acionado de forma
    muito imprevisível, pode levar a branch mispredictions, que são custosos.
  - **Evitar Trabalho Desnecessário:** Se eles consistentemente evitam uma
    quantidade significativa de trabalho caro dentro do loop, o ganho de
    performance pode superar o custo do branch.

  A decisão de usá-los deve ser baseada na clareza do código e na análise
  de perfil de performance, se o loop for crítico.
*/