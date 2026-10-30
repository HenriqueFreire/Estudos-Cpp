/*
  O que é um Algoritmo?

  Em sua essência, um algoritmo é uma receita ou um conjunto de instruções bem
  definidas e finitas para resolver um problema ou realizar uma tarefa. Pense
  nele como um manual de instruções detalhado.


  Para ser considerado um algoritmo, ele precisa ter algumas características
  importantes:


   1. Finito: Deve terminar após um número finito de passos. Não pode ser um
  processo que nunca acaba.
   2. Não Ambíguo: Cada passo deve ser claro e preciso, sem margem para dupla
  interpretação.
   3. Entradas (Inputs): Pode receber zero ou mais valores de entrada.
   4. Saídas (Outputs): Deve produzir um ou mais valores de saída.
   5. Efetivo: Cada instrução deve ser básica o suficiente para ser executada em
  um tempo finito por uma pessoa (ou máquina) usando papel e lápis (ou seus
  recursos computacionais).

  Representação de Algoritmos

  Existem várias formas de representar um algoritmo. As mais comuns são:


   * Fluxogramas: Diagramas visuais que usam símbolos padronizados para
  representar os passos e o fluxo de controle.
   * Pseudocódigo: Uma descrição textual do algoritmo que se assemelha a um
  código de programação, mas é mais abstrata e usa linguagem natural para
  facilitar a compreensão humana, sem se prender a uma sintaxe específica de uma
  linguagem.


  Para nossa interação, o pseudocódigo será a forma mais prática de representar
  nossos algoritmos.

  ---

  Foco em Performance: Análise de Custo Intuitiva

  Aqui é onde a filosofia de HFT começa a se manifestar. Mesmo sem entrar em
  detalhes matemáticos de "Big O", podemos ter uma intuição sobre a eficiência
  de um algoritmo.


  Exemplo: Imagine que você tem uma lista telefônica com 1000 nomes e números, e
  você quer encontrar o número de "Maria".

  Algoritmo 1: Busca Linear (Ingênua)


   1. Comece na primeira página.
   2. Olhe o primeiro nome. Se for "Maria", pegue o número e termine.
   3. Se não for "Maria", vá para o próximo nome.
   4. Repita até encontrar "Maria" ou chegar ao fim da lista.


   * Custo Intuitivo: No pior caso, você terá que olhar os 1000 nomes. Se a
  lista dobrar para 2000 nomes, você terá que olhar até 2000 nomes. O número de
  passos cresce linearmente com o tamanho da lista.

  Algoritmo 2: Busca Binária (Inteligente - porque a lista está ordenada)


   1. Abra a lista telefônica exatamente no meio.
   2. Olhe o nome que está ali.
   3. Se for "Maria", pegue o número e termine.
   4. Se "Maria" vier antes do nome que você viu, descarte a segunda metade da
  lista e repita o processo na primeira metade.
   5. Se "Maria" vier depois, descarte a primeira metade e repita o processo na
  segunda metade.
   6. Continue dividindo a lista pela metade até encontrar "Maria" ou a lista
  ficar vazia.


   * Custo Intuitivo:
       * 1000 nomes -> 500 -> 250 -> 125 -> 62 -> 31 -> 15 -> 7 -> 3 -> 1. Você
  encontra "Maria" em cerca de 10 passos!
       * Se a lista dobrar para 2000 nomes, você precisará de apenas 1 passo a
  mais (2000 -> 1000 -> ...).
       * O número de passos cresce muito mais lentamente, de forma logarítmica,
  com o tamanho da lista.


  A diferença na "eficiência" é gritante, mesmo sem código. A escolha do
  algoritmo pode significar a diferença entre um programa que responde
  instantaneamente e um que trava.

  ---

  Vamos começar com um exemplo simples em C++ para ilustrar um algoritmo básico.


  Algoritmo: Calcular a soma de todos os números em um vetor.

*/

#include <iostream> // Para entrada/saída (cout)
#include <vector>   // Para usar o tipo de dado 'vector'

// Algoritmo: CalcularSomaVetor
// Entrada: Um vetor de números inteiros (vetor_entrada)
// Saída: A soma total dos números no vetor

int main() {
  // 1. Definir o vetor de entrada
  std::vector<int> numeros = {10, 20, 30, 40, 50};

  // 2. Inicializar uma variável para armazenar a soma
  int soma = 0;

  // 3. Percorrer cada número no vetor
  //    Para cada 'numero' dentro de 'numeros':
  for (int numero : numeros) {
    // 4. Adicionar o número atual à soma
    soma = soma + numero; // Ou soma += numero;
  }

  // 5. Exibir o resultado
  std::cout << "A soma dos numeros e: " << soma << "\n";

  return 0;
}
