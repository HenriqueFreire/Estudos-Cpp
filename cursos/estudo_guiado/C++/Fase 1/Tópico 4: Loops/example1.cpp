#include <iostream>

int main() {
  // Este é o loop 'for' em sua forma mais básica.
  // Ele é ideal para quando sabemos exatamente quantas vezes queremos repetir
  // uma ação.
  std::cout << "Iniciando a contagem com um loop 'for':\n";

  // A estrutura do loop 'for' tem 3 partes separadas por ';':
  // 1. Inicialização: `int i = 0;` (cria uma variável 'i' e a inicia em 0)
  //    -> Executa apenas uma vez, no começo.
  // 2. Condição: `i < 5;` (o loop continua ENQUANTO 'i' for menor que 5)
  //    -> Verifica antes de cada iteração.
  // 3. Incremento: `++i;` (adiciona 1 a 'i' no final de cada iteração)
  //    -> Executa ao final de cada iteração.
  for (int i = 0; i < 5; ++i) {
    // Este é o "corpo" do loop. O código aqui dentro será repetido.
    std::cout << "Iteracao numero: " << i << '\n';
  }

  std::cout << "Loop 'for' concluido.\n";

  return 0;
}

/*
  Este exemplo introduz o conceito mais fundamental de repetição em C++: o loop
  `for`.

  O que observar:
  - O loop executará 5 vezes, para os valores de `i` de 0, 1, 2, 3 e 4.
  - Quando `i` se torna 5, a condição `i < 5` se torna falsa, e o loop termina
    antes que a iteração para `i = 5` possa começar.
  - A variável `i` só existe dentro do escopo do loop `for`.

  Performance (Baixa Latência):
  Loops `for` com um número de iterações conhecido no início (como este) são
  extremamente fáceis para o compilador otimizar. O compilador pode prever
  exatamente como o loop se comportará e aplicar otimizações como "loop
  unrolling" (desenrolamento de loop), onde ele efetivamente substitui o loop
  por uma sequência de instruções diretas para reduzir o overhead do controle do
  loop. Para o hardware, isso é muito eficiente e previsível.
*/