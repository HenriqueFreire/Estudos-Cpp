#include <iostream>

int main() {
  int contador = 0;

  // Loop 'while': executa o bloco de código ENQUANTO a condição for verdadeira.
  // A condição é verificada ANTES de cada iteração.
  std::cout << "Loop 'while':\n";
  while (contador < 3) {
    std::cout << "Contador (while) = " << contador << '\n';
    contador++; // Incrementa o contador para evitar um loop infinito
  }

  std::cout << '\n';

  int outroContador = 0;

  // Loop 'do-while': executa o bloco de código PELO MENOS UMA VEZ,
  // e então verifica a condição.
  // A condição é verificada DEPOIS de cada iteração.
  std::cout << "Loop 'do-while':\n";
  do {
    std::cout << "Contador (do-while) = " << outroContador << '\n';
    outroContador++; // Incrementa o contador
  } while (outroContador < 3);

  std::cout << '\n';

  // Exemplo de 'do-while' onde a condição é falsa na primeira verificação
  // (mas o loop executa pelo menos uma vez)
  int nuncaEntraNoWhile = 10;
  std::cout << "Loop 'do-while' com condicao falsa inicial:\n";
  do {
    std::cout << "Este bloco executa pelo menos uma vez. Valor: "
              << nuncaEntraNoWhile << '\n';
    nuncaEntraNoWhile++;
  } while (nuncaEntraNoWhile < 5); // Condição é falsa (10 < 5 é falso)

  return 0;
}

/*
  Este exemplo demonstra os loops `while` e `do-while`, outras estruturas de
  repetição em C++.

  Diferenças Chave:
  - `while`: A condição é avaliada **antes** da execução do bloco de código.
    Se a condição for falsa desde o início, o bloco nunca será executado.
  - `do-while`: O bloco de código é executado **pelo menos uma vez**, e a
    condição é avaliada **depois** da execução do bloco. Se a condição for
    falsa após a primeira execução, o loop termina.

  O que observar:
  1. A necessidade de garantir que a condição do loop eventualmente se torne
     falsa para evitar loops infinitos.
  2. A escolha entre `while` e `do-while` depende se você precisa que o bloco
     de código seja executado pelo menos uma vez.

  Performance (Baixa Latência):
  Assim como os loops `for`, `while` e `do-while` são eficientes e podem ser
  otimizados pelo compilador. As mesmas considerações de performance se aplicam:
  - Evitar operações caras (alocações de memória, chamadas de função complexas)
    dentro do loop.
  - Garantir que o trabalho dentro do loop seja o mais previsível possível para
    o processador.
  - A escolha entre `for`, `while` e `do-while` é mais uma questão de semântica
    e clareza do código do que de diferença de performance intrínseca, pois
    o compilador geralmente gera código muito similar para casos equivalentes.
*/