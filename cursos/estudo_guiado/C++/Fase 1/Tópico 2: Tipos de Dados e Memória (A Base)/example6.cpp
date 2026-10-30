#include <iostream>

int main() {
  // 'const' é uma promessa de que a variável não será modificada após a
  // inicialização
  const double VELOCIDADE_DA_LUZ_MS = 299792458.0;

  std::cout << "A velocidade da luz é: " << VELOCIDADE_DA_LUZ_MS << " m/s.\n";

  // A linha abaixo causaria um ERRO DE COMPILAÇÃO se fosse descomentada
  // VELOCIDADE_DA_LUZ_MS = 300000000.0;

  return 0;
}
/*

  Usar const é uma das práticas mais importantes em C++ moderno.
  Ela permite que o compilador faça otimizações e, mais importante,
  previne erros ao garantir que valores que não deveriam mudar, de fato, não
  mudem. É uma forma de usar o sistema de tipos para tornar seu código mais
  seguro e expressivo. Prefira const a #define (do exemplo anterior) para criar
  constantes.

*/