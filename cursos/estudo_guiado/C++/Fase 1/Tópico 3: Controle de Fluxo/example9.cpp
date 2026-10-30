#include <chrono>
#include <iostream>

// Função que usa um if-else tradicional (com branch)
void com_branch(bool condicao, long &contador_a, long &contador_b) {
  if (condicao) {
    contador_a++;
  } else {
    contador_b++;
  }
}

// Função que usa aritmética para evitar o branch
void sem_branch(bool condicao, long &contador_a, long &contador_b) {
  // Em C++, 'true' é convertido para 1 e 'false' para 0.
  // Se condicao for true: contador_a += 1; contador_b += 0;
  // Se condicao for false: contador_a += 0; contador_b += 1;
  contador_a += condicao;
  contador_b += !condicao;
}

int main() {
  long contador_a_branch = 0;
  long contador_b_branch = 0;
  long contador_a_sem_branch = 0;
  long contador_b_sem_branch = 0;

  // Demonstração simples
  com_branch(true, contador_a_branch, contador_b_branch);
  sem_branch(true, contador_a_sem_branch, contador_b_sem_branch);
  std::cout << "Apos 1x true: com_branch(A=" << contador_a_branch
            << ", B=" << contador_b_branch << ")\n";
  std::cout << "Apos 1x true: sem_branch(A=" << contador_a_sem_branch
            << ", B=" << contador_b_sem_branch << ")\n\n";

  com_branch(false, contador_a_branch, contador_b_branch);
  sem_branch(false, contador_a_sem_branch, contador_b_sem_branch);
  std::cout << "Apos 1x false: com_branch(A=" << contador_a_branch
            << ", B=" << contador_b_branch << ")\n";
  std::cout << "Apos 1x false: sem_branch(A=" << contador_a_sem_branch
            << ", B=" << contador_b_sem_branch << ")\n";

  return 0;
}

/*
  Este exemplo introduz uma técnica avançada e crucial para baixa latência:
  código "branchless" (sem desvios).

  O que observar:
  1. **`com_branch`**: A implementação tradicional e intuitiva usando `if-else`.
     O processador encontra um salto condicional aqui.
  2. **`sem_branch`**: A implementação "branchless". Ela explora o fato de que,
     em C++, o valor booleano `true` é convertido para o inteiro `1` e `false`
     para `0`. A lógica de decisão é transformada em uma operação aritmética.

  Performance (Baixa Latência):
  O `if` introduz um "branch". Como vimos no `example1.cpp`, se o padrão da
  condição for imprevisível (ex: alternando aleatoriamente entre true/false),
  o processador errará a previsão do branch (branch misprediction) com
  frequência, causando uma penalidade de performance significativa (de 10 a 20
  ciclos de CPU).

  A versão `sem_branch` não possui saltos condicionais. Ela executa sempre as
  mesmas instruções aritméticas, tornando o fluxo de execução perfeitamente
  previsível para o pipeline da CPU. Mesmo que o número de instruções seja
  maior, a ausência de mispredictions pode tornar esta versão drasticamente
  mais rápida em loops críticos com dados de padrão imprevisível.

  Em HFT, transformar lógica condicional em aritmética é uma otimização comum
  e poderosa para garantir latência baixa e determinística.
*/