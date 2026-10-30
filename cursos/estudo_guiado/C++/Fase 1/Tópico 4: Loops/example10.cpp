#include <chrono>
#include <iostream>
#include <numeric>
#include <vector>

const int SIZE = 100000000; // 100 milhões de elementos
std::vector<int> dados(SIZE);

void preencherDados() {
  std::iota(dados.begin(), dados.end(), 1); // Preenche o vetor com 1, 2, 3, ...
}

// Versão com dependência de dados: cada iteração depende do resultado da
// anterior
void soma_com_dependencia() {
  volatile long long sum = 0;
  for (int i = 0; i < SIZE; ++i) {
    sum += dados[i]; // sum não pode ser calculado na próxima iteração até que
                     // esta termine
  }
}

// Versão que quebra a dependência usando 4 acumuladores
void soma_sem_dependencia() {
  volatile long long sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
  for (int i = 0; i < SIZE; i += 4) {
    sum1 += dados[i];     // Operação 1
    sum2 += dados[i + 1]; // Operação 2 (independente da 1)
    sum3 += dados[i + 2]; // Operação 3 (independente da 1 e 2)
    sum4 += dados[i + 3]; // Operação 4 (independente da 1, 2 e 3)
  }
  // Soma final fora do loop
  // volatile long long total_sum = sum1 + sum2 + sum3 + sum4;
}

int main() {
  preencherDados();

  auto start = std::chrono::high_resolution_clock::now();
  soma_com_dependencia();
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> com_dep_time = end - start;
  std::cout << "Tempo com dependencia de dados: " << com_dep_time.count()
            << " ms\n";

  start = std::chrono::high_resolution_clock::now();
  soma_sem_dependencia();
  end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> sem_dep_time = end - start;
  std::cout << "Tempo sem dependencia de dados (paralelizavel): "
            << sem_dep_time.count() << " ms\n";

  return 0;
}

/*
  Este exemplo demonstra uma técnica de otimização avançada chamada "quebra de
  dependência de dados" (breaking data dependencies). O objetivo é explorar
  melhor o **Paralelismo em Nível de Instrução (Instruction-Level Parallelism -
  ILP)** das CPUs modernas.

  **ILP** é a capacidade que um único núcleo de CPU tem de executar múltiplas
  instruções (como somas, multiplicações) simultaneamente, desde que elas
  sejam independentes umas das outras.

  O que observar:
  1. `soma_com_dependencia`: Esta é a forma padrão de somar elementos. No
  entanto, há uma "cadeia de dependência": a `soma` da iteração `i+1` não pode
  começar antes que a `soma` da iteração `i` esteja completa. Isso limita a CPU
  a processar uma adição de cada vez.

  2. `soma_sem_dependencia`: Esta versão "desenrola" o loop (loop unrolling)
     manualmente e usa quatro acumuladores separados. As quatro operações de
     soma dentro do loop são independentes umas das outras.

  Performance (Baixa Latência):
  CPUs modernas são "superscalares", o que é a base para o ILP. Elas podem
  iniciar várias instruções por ciclo de clock.

  - **Com Dependência:** O pipeline da CPU fica subutilizado. A instrução de
    adição precisa esperar o resultado da adição anterior, criando um gargalo
    que impede o ILP.

  - **Sem Dependência:** Como as quatro somas (`sum1` a `sum4`) são
  independentes, a CPU pode executá-las em paralelo, aproveitando ao máximo o
  ILP e maximizando o uso de suas unidades de execução.

  Esta técnica é uma forma de "loop unrolling" manual que não apenas reduz o
  overhead do loop, mas, mais importante, quebra a cadeia de dependência de
  dados. Isso permite que o hardware explore o ILP de forma eficaz, sendo uma
  otimização poderosa para cálculos e agregações de dados em HFT.
*/