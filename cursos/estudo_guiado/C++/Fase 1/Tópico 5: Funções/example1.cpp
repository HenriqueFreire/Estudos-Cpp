#include <iostream>

// Esta é a definição de uma função simples.
// 'void' significa que a função não retorna nenhum valor.
// Os parênteses vazios indicam que ela não recebe nenhum parâmetro.
void saudacao() { std::cout << "Ola do interior da funcao saudacao!\n"; }

int main() {
  std::cout << "Iniciando o programa.\n";

  // Chamada da função: o programa salta para 'saudacao()', executa seu código,
  // e depois retorna para continuar aqui.
  saudacao();

  std::cout << "Programa finalizado.\n";

  return 0;
}

/*
  Este exemplo introduz o conceito mais fundamental de uma função: um bloco
  de código nomeado que pode ser executado (chamado) a qualquer momento.

  O que observar:
  - **Definição da Função:** Onde o código da função é escrito.
  - **Chamada da Função:** Onde a função é invocada para ser executada.
  - **`void`:** Indica que a função não produz um resultado para ser usado
    pelo código que a chamou.
  - **Reusabilidade:** A principal vantagem das funções é que você pode
    escrever um código uma vez e usá-lo várias vezes, em diferentes partes
    do seu programa.

  Performance (Baixa Latência):
  - Chamar uma função tem um pequeno custo (overhead) associado. Para funções
    tão pequenas e simples como esta, o compilador C++ é muito inteligente
    e frequentemente aplica uma otimização chamada "inlining".
  - **Inlining:** O compilador substitui a chamada da função pelo próprio
    código da função diretamente no local da chamada, eliminando o overhead
    da chamada de função. Isso torna a execução tão rápida quanto se o código
    estivesse escrito diretamente no `main`.
*/