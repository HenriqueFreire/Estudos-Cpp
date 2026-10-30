#include <iostream>
#include <limits> // Para std::numeric_limits

int main() {
  // std::numeric_limits<int>::max() nos dá o maior valor que um int pode ter.
  int maiorInteiroPossivel = std::numeric_limits<int>::max();

  std::cout << "Maior valor para um int: " << maiorInteiroPossivel << '\n';

  // Agora, vamos tentar adicionar 1 a ele.
  maiorInteiroPossivel = maiorInteiroPossivel + 1;

  // O resultado não é o esperado. Isso é 'Undefined Behavior' (Comportamento
  // Indefinido). Na maioria dos sistemas, ele "dá a volta" e se torna o menor
  // valor possível.
  std::cout << "Maior valor + 1 (overflow): " << maiorInteiroPossivel << '\n';

  return 0;
}

/*
  Overflow acontece quando você tenta armazenar um valor em uma variável que é
  maior do que a capacidade daquele tipo. Para inteiros com sinal (como int), o
  resultado é tecnicamente "Comportamento Indefinido", o que significa que o
  padrão do C++ não garante o que vai acontecer. Na prática, ele geralmente "dá
  a volta" para o menor valor negativo, como visto no exemplo. Este é um bug
  perigoso e sutil, e é por isso que escolher o tipo de dado correto (long long
  para números grandes, por exemplo) é tão importante.
*/