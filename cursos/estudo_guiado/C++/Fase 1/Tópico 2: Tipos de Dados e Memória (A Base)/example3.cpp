#include <iostream>

int main() {
  // 'char' armazena um único caractere. Usa aspas simples.
  char inicialDoNome = 'H';

  // 'bool' armazena um de dois valores: true (verdadeiro) ou false (falso).
  bool estaChovendo = false;

  std::cout << "Inicial: " << inicialDoNome << '\n';

  // Por padrão, std::cout imprime '1' para true e '0' para false.
  std::cout << "Esta chovendo? (0=nao, 1=sim): " << estaChovendo << '\n';

  // Podemos usar std::boolalpha para imprimir "true" ou "false" textualmente.
  std::cout << std::boolalpha;
  std::cout << "Esta chovendo? (texto): " << estaChovendo << '\n';

  return 0;
}

/*

  char é o tipo mais básico para dados textuais,
  armazenando um único caractere (letra, número, símbolo).
  bool é fundamental para a lógica do programa,
  representando condições que podem ser verdadeiras ou falsas.
  O manipulador std::boolalpha é útil para tornar a saída de valores booleanos
  mais legível.

  */