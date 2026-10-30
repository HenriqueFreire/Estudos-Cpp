#include <iostream>

int main() {
  // Solicita um número ao usuário
  std::cout << "Digite um numero inteiro: ";
  int numero;
  // Lê o input do usuário e armazena na variável 'numero'
  std::cin >> numero;

  // Inicia a verificação da condição
  if (numero > 0) {
    // Executado se o número for positivo
    std::cout << "O numero " << numero << " eh positivo." << '\n';
  } else if (numero < 0) {
    // Executado se a primeira condição for falsa e esta for verdadeira
    std::cout << "O numero " << numero << " eh negativo." << '\n';
  } else {
    // Executado se nenhuma das condições anteriores for verdadeira
    std::cout << "O numero eh zero." << '\n';
  }

  return 0;
}

/*
  Este código demonstra a estrutura de decisão mais fundamental em C++: o
  if-else. Ele classifica um número fornecido pelo usuário como positivo,
  negativo ou zero.

  O que observar:
  1. A condição dentro do `if (...)`.
  2. O bloco `else if` para uma segunda verificação.
  3. O bloco `else` que captura todos os outros casos.

  Performance: Para o processador, um `if` pode resultar em um 'branch' (salto).
  Quando o processador encontra um salto condicional, ele tenta prever qual
  caminho será tomado para continuar executando instruções sem parar. Se a
  previsão estiver errada (branch misprediction), ele precisa descartar o
  trabalho feito e começar de novo no caminho correto, o que custa ciclos de
  CPU preciosos. Em código de baixa latência, tentamos minimizar branches ou
  torná-los o mais previsível possível para o hardware.
*/