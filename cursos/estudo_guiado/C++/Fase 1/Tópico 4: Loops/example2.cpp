#include <iostream>

int main() {
  int numero = 0;
  const int VALOR_SENTINELA = -1; // O valor que vai parar o loop

  std::cout << "Digite numeros inteiros. Digite " << VALOR_SENTINELA
            << " para parar.\n";

  // O loop 'while' continua executando ENQUANTO sua condição for verdadeira.
  // A condição é testada antes de cada iteração.
  while (numero != VALOR_SENTINELA) {
    std::cout << "Voce digitou: " << numero << ". Digite outro numero: ";
    std::cin >> numero; // Lê o próximo número do usuário
  }

  std::cout << "Voce digitou o valor sentinela " << VALOR_SENTINELA
            << ". Fim do programa.\n";

  return 0;
}

/*
  Este exemplo foca no loop `while`. Ele é a escolha ideal quando um loop
  precisa continuar enquanto uma certa condição for verdadeira, mas não sabemos
  quantas iterações isso levará.

  O que observar:
  - O loop `while` é mais simples em sua estrutura que o `for`: `while
  (condicao) { ... }`.
  - A condição é avaliada ANTES de cada iteração. Se a condição for falsa na
    primeira vez, o corpo do loop nunca executa.
  - É crucial que algo dentro do loop (neste caso, a entrada do usuário)
    possa eventualmente tornar a condição falsa, para evitar um loop infinito.

  Performance (Baixa Latência):
  - A performance de um loop `while` é, em geral, idêntica à de um loop `for`
    equivalente. A escolha entre eles é uma questão de clareza e semântica:
      - Use `for` quando o número de iterações for conhecido (contagem, iterar
  sobre um array).
      - Use `while` quando o loop depender de uma condição externa que pode
  mudar a qualquer momento (entrada do usuário, status de uma conexão de rede,
  etc.).
  - As mesmas otimizações e preocupações se aplicam: o compilador pode otimizar
    bem o loop, mas o trabalho dentro dele deve ser mantido o mais leve possível
    em código crítico.
*/
