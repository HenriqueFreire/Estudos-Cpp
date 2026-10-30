#include <iostream>

// Declaração da função (protótipo)
// Informa ao compilador que a função 'somar' existe e como chamá-la.
int somar(int a, int b);

// Outra função simples que não retorna valor (void)
void imprimirMensagem() {
  std::cout << "Esta eh uma mensagem de uma funcao.\n";
}

int main() {
  imprimirMensagem(); // Chama a função que imprime uma mensagem

  int x = 10;
  int y = 20;

  // Chama a função 'somar' e armazena o resultado
  int resultado = somar(x, y);

  std::cout << "A soma de " << x << " e " << y << " eh: " << resultado << '\n';

  // Exemplo de chamada com literais
  std::cout << "A soma de 5 e 3 eh: " << somar(5, 3) << '\n';

  return 0;
}

// Definição da função 'somar'
// Implementa o que a função faz.
int somar(int a, int b) {
  // 'a' e 'b' são cópias dos valores passados.
  // Modificações em 'a' ou 'b' aqui não afetam as variáveis originais (x, y) em
  // main.
  return a + b;
}

/*
  Este exemplo introduz o conceito de funções em C++, que são blocos de código
  reutilizáveis projetados para realizar uma tarefa específica. Funções são
  essenciais para organizar o código, torná-lo modular e mais fácil de manter.

  O que observar:
  1. **Declaração (Protótipo):** `int somar(int a, int b);`
     - Informa ao compilador o nome da função, o tipo de retorno e os tipos
       e nomes dos parâmetros. É como uma "promessa" de que a função será
       definida em algum lugar.
  2. **Definição:** A implementação real da função.
  3. **Chamada:** `somar(x, y);`
     - Executa o código dentro da função.
  4. **`void`:** Indica que a função não retorna nenhum valor.
  5. **Passagem por Valor:** Os parâmetros `a` e `b` na função `somar` são
     **cópias** dos valores de `x` e `y` passados de `main`. Qualquer alteração
     em `a` ou `b` dentro de `somar` não afetará `x` ou `y` em `main`.

  Performance (Baixa Latência):
  - **Overhead de Chamada:** Chamar uma função tem um pequeno overhead (push/pop
    de registradores, salto de instrução). Para funções muito pequenas e
  simples, o compilador pode aplicar "inlining", que substitui a chamada da
  função pelo corpo da função diretamente no local da chamada, eliminando o
  overhead.
  - **Passagem por Valor:** Para tipos pequenos (como `int`, `char`, `float`),
    passar por valor (copiar) é geralmente eficiente. Para tipos maiores ou
    complexos, a cópia pode ser custosa. Este é um ponto crítico que será
    abordado no próximo exemplo (passagem por referência).
  - **Modularidade:** Embora haja um custo mínimo, a modularidade e a clareza
    que as funções trazem são cruciais para a manutenção de código complexo,
    mesmo em HFT.
*/