// variaveis.cpp - Exemplo didático de cálculo com variáveis em C++.
// Este programa demonstra como declarar variáveis, atribuir valores a elas
// e realizar cálculos onde o resultado de uma operação é armazenado em outra
// variável, ou onde variáveis são usadas para definir o valor de outras
// variáveis.

#include <iostream> // Inclui a biblioteca iostream para operações de entrada e saída.

using namespace std; // Usa o namespace padrão.

int main() {
  // 1. Declaração e inicialização de variáveis básicas
  int numero1 =
      10; // Declara uma variável inteira 'numero1' e a inicializa com 10.
  int numero2 =
      5; // Declara uma variável inteira 'numero2' e a inicializa com 5.

  cout << "--- Valores Iniciais ---" << endl;
  cout << "Numero 1: " << numero1 << endl;
  cout << "Numero 2: " << numero2 << endl;
  cout << endl;

  // 2. Cálculo simples e armazenamento em uma nova variável
  int soma =
      numero1 +
      numero2; // Declara 'soma' e armazena o resultado da adição de 'numero1' e
               // 'numero2'. Aqui, 'soma' recebe o valor 15 (10 + 5).
  cout << "Soma (numero1 + numero2): " << soma << endl;

  // 3. Usando o resultado de um cálculo para definir outra variável
  int dobro_da_soma =
      soma * 2; // Declara 'dobro_da_soma' e armazena o dobro do valor de
                // 'soma'. Aqui, 'dobro_da_soma' recebe o valor 30 (15 * 2).
  cout << "Dobro da Soma (soma * 2): " << dobro_da_soma << endl;

  // 4. Cálculo mais complexo usando múltiplas variáveis
  int resultado_complexo =
      (numero1 * numero2) - soma; // Declara 'resultado_complexo' e armazena
                                  // (10 * 5) - 15 = 50 - 15 = 35.
  cout << "Resultado Complexo ((numero1 * numero2) - soma): "
       << resultado_complexo << endl;

  // 5. Modificando o valor de uma variável e observando o impacto
  numero1 = 20; // Altera o valor de 'numero1' para 20.
                // Note que 'soma' e 'dobro_da_soma' *não* são atualizados
                // automaticamente, pois foram calculados com o valor *anterior*
                // de 'numero1'.
  cout << "\n--- Após alterar Numero 1 para 20 ---" << endl;
  cout << "Novo Numero 1: " << numero1 << endl;
  cout << "Soma (ainda 15, pois foi calculada antes): " << soma << endl;

  // Para ter a soma atualizada, precisaríamos recalcular:
  soma = numero1 + numero2; // Recalcula 'soma' com o novo valor de 'numero1'.
                            // Agora 'soma' é 25 (20 + 5).
  cout << "Nova Soma (recalculada): " << soma << endl;

  return 0; // Indica que o programa foi executado com sucesso.
}