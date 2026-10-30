// --- modularidade_main.cpp ---
// Este é o nosso programa principal.
// Ele usa as funcionalidades definidas no módulo 'matematica'.

#include <iostream>

// Incluímos "matematica.h" para ter acesso às declarações das funções 'somar' e
// 'subtrair'. Usamos aspas duplas "" em vez de < > porque o arquivo está na
// mesma pasta do nosso projeto, e não é uma biblioteca padrão do sistema.
#include "matematica.h"

int main() {
  int x = 10;
  int y = 5;

  std::cout << "Exemplo de Modularidade em C++" << std::endl;

  // Chamando a função 'somar' que foi definida em matematica.cpp
  int resultado_soma = somar(x, y);
  std::cout << x << " + " << y << " = " << resultado_soma << std::endl;

  // Chamando a função 'subtrair'
  int resultado_subtracao = subtrair(x, y);
  std::cout << x << " - " << y << " = " << resultado_subtracao << std::endl;

  return 0;
}
