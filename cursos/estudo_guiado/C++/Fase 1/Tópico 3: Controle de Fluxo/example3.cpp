// example3.cpp
#include <iostream>

int main() {
  int opcao;

  // Solicita ao usuário que escolha uma opção
  std::cout << "Escolha uma opcao (1-3): ";
  std::cin >> opcao;

  // A instrução switch avalia a variável 'opcao'
  switch (opcao) {
  case 1:
    // Executado se 'opcao' for 1
    std::cout << "Voce escolheu a opcao 1.\n";
    break; // Importante: sai do bloco switch
  case 2:
    // Executado se 'opcao' for 2
    std::cout << "Voce escolheu a opcao 2.\n";
    break; // Importante: sai do bloco switch
  case 3:
    // Executado se 'opcao' for 3
    std::cout << "Voce escolheu a opcao 3.\n";
    break; // Importante: sai do bloco switch
  default:
    // Executado se 'opcao' nao corresponder a nenhum dos casos acima
    std::cout << "Opcao invalida.\n";
    break; // Boa pratica: terminar com break, mesmo no default
  }

  return 0;
}

/*
  Este exemplo demonstra a instrução `switch`, que é usada para controlar
  o fluxo de execução com base no valor de uma única variável.

  O que observar:
  1. A variável de controle (`opcao`) é avaliada.
  2. Cada `case` compara o valor da variável com uma constante.
  3. O `break` é crucial: sem ele, a execução "cai" para o próximo `case`
     (comportamento conhecido como "fall-through"), o que raramente é desejado.
  4. O `default` é opcional e lida com todos os valores que não correspondem
     a nenhum `case`.

  Performance: Um `switch` pode ser mais eficiente que uma longa cadeia de
  `if-else if` quando há muitas condições baseadas no mesmo valor. O compilador
  pode otimizar um `switch` para uma tabela de saltos (jump table), permitindo
  acesso direto ao código correto sem múltiplas comparações. Isso pode reduzir
  o número de branch mispredictions, o que é benéfico para baixa latência.
  No entanto, para um número pequeno de casos (como neste exemplo), a diferença
  de performance para `if-else` é geralmente insignificante.
*/