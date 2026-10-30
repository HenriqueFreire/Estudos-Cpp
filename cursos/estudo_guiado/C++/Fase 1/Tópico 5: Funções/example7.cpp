#include <iostream>

// Funções simples com a mesma assinatura (int (int, int))
int adicionar(int a, int b) { return a + b; }

int subtrair(int a, int b) { return a - b; }

int multiplicar(int a, int b) { return a * b; }

// Função que recebe um ponteiro para função como parâmetro
// Isso permite que a função 'executarOperacao' seja genérica na operação que
// realiza.
void executarOperacao(int x, int y, int (*operacao)(int, int)) {
  int resultado = operacao(x, y);
  std::cout << "Resultado da operacao: " << resultado << '\n';
}

int main() {
  std::cout << "Demonstrando Ponteiros para Funcoes.\n\n";

  // 1. Declarando um ponteiro para função
  // A sintaxe é: tipo_retorno (*nome_do_ponteiro)(tipo_param1, tipo_param2,
  // ...);
  int (*ptrOperacao)(int, int);

  // 2. Atribuindo uma função ao ponteiro
  ptrOperacao =
      adicionar; // O nome da função 'adicionar' já é um ponteiro para ela

  // 3. Chamando a função através do ponteiro
  std::cout << "Usando ponteiro para adicionar (10 + 5): " << ptrOperacao(10, 5)
            << '\n';

  // 4. Atribuindo outra função ao mesmo ponteiro
  ptrOperacao = subtrair;
  std::cout << "Usando ponteiro para subtrair (10 - 5): " << ptrOperacao(10, 5)
            << '\n';

  // 5. Usando ponteiros para função como argumento para outra função (callback)
  std::cout << "\nExecutando operacoes via funcao auxiliar:\n";
  executarOperacao(20, 5, adicionar);
  executarOperacao(20, 5, multiplicar);

  std::cout << "\nPrograma finalizado.\n";

  return 0;
}

/*
  Este exemplo demonstra o uso de ponteiros para funções em C++.

  O que observar:
  - **Sintaxe:** A declaração de um ponteiro para função pode ser um pouco
    confusa: `tipo_retorno (*nome_do_ponteiro)(parametros);`. Os parênteses
    em torno de `*nome_do_ponteiro` são cruciais para indicar que é um ponteiro
    para uma função, e não uma função que retorna um ponteiro.
  - **Atribuição:** O nome de uma função (sem parênteses) pode ser atribuído
    diretamente a um ponteiro para função compatível.
  - **Chamada:** Uma função pode ser chamada através do ponteiro usando a
    sintaxe `ptr(args)` ou `(*ptr)(args)`.
  - **Callbacks:** Ponteiros para funções são a base para implementar callbacks,
    onde você passa uma função para outra função para que ela seja chamada
    em um momento posterior ou sob certas condições.

  Performance (Baixa Latência):
  - **Overhead de Chamada Indireta:** Chamar uma função através de um ponteiro
    é uma "chamada indireta". Isso significa que o compilador não sabe qual
    função será chamada até o tempo de execução.
  - **Prevenção de Inlining:** Chamadas indiretas geralmente impedem que o
    compilador aplique a otimização de "inlining", pois ele não pode substituir
    o corpo da função no local da chamada se não souber qual função é.
  - **Branch Prediction:** O processador pode ter mais dificuldade em prever
    o destino de um salto indireto, o que pode levar a *branch mispredictions*
    e penalidades de performance.
  - **Trade-off:** Em HFT, ponteiros para funções são usados com cautela em
    caminhos críticos. O benefício da flexibilidade deve ser pesado contra o
    pequeno custo de performance. Para cenários onde a flexibilidade é
  essencial, `std::function` (C++11) e lambdas (C++11) são alternativas mais
  modernas e seguras, embora possam ter um overhead ligeiramente maior.
*/