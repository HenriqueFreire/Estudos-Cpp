#include <iostream>

void minhaFuncao() {
  // 'variavelLocal' é criada na Stack quando 'minhaFuncao' é chamada.
  int variavelLocal = 20;
  std::cout << "Dentro da funcao, variavelLocal = " << variavelLocal << '\n';
  // Quando a função termina, 'variavelLocal' é automaticamente destruída.
}

int main() {
  // 'variavelPrincipal' é criada na Stack quando 'main' é chamada.
  int variavelPrincipal = 10;
  std::cout << "Antes da funcao, variavelPrincipal = " << variavelPrincipal
            << '\n';

  minhaFuncao();

  std::cout << "Depois da funcao, variavelPrincipal = " << variavelPrincipal
            << '\n';
  // Tentar acessar 'variavelLocal' aqui causaria um erro de compilação,
  // pois ela não existe mais.

  return 0;
}

/*
  A Stack (Pilha) é uma região da memória onde variáveis locais são armazenadas.
  Ela é extremamente rápida e o gerenciamento é automático.
  Quando uma função é chamada, suas variáveis locais são "empilhadas" na stack.
  Quando a função retorna, elas são "desempilhadas" (destruídas).
  Todas as variáveis que declaramos até agora nos exemplos
  (excetoas alocadas com new, que veremos a seguir) vivem na Stack.
  Para baixa latência, preferimos a Stack sempre que possível devido à sua
  velocidade e gerenciamento previsível.
*/