#include <iostream>

int main() {
  // 'ponteiroParaInt' é uma variável local (na Stack), mas ela aponta
  // para um endereço de memória no Heap.
  // 'new int' aloca memória para um inteiro no Heap e retorna seu endereço.
  int *ponteiroParaInt = new int;

  // Usamos o operador '*' para acessar o valor no endereço apontado.
  *ponteiroParaInt = 50;

  std::cout << "Valor no Heap: " << *ponteiroParaInt << '\n';

  // A memória alocada no Heap NÃO é liberada automaticamente.
  // Nós somos responsáveis por liberá-la usando 'delete'.
  // Se esquecermos, teremos um 'memory leak' (vazamento de memória).
  delete ponteiroParaInt;

  // Os ponteiros inteligentes (smart pointers) que veremos na Fase 2
  // automatizam esse processo de 'delete'.

  return 0;
}

/*
  O Heap é outra região da memória usada para alocação dinâmica.
  Ao contrário da Stack, os dados no Heap persistem mesmo após a função que os
  criou terminar. Nós controlamos explicitamente quando alocar (new) e quando
  liberar (delete) essa memória. Isso oferece flexibilidade (podemos criar
  objetos cujo tamanho só conhecemos em tempo de execução), mas vem com um
  custo:

  1. Performance: A alocação no Heap é significativamente mais lenta que na
  Stack.

  2. Gerenciamento: O programador é responsável por liberar a memória.
  Esquecer de usar delete causa vazamentos de memória (memory leaks).

  Em HFT, a alocação no Heap durante operações críticas é quase sempre evitada.
*/