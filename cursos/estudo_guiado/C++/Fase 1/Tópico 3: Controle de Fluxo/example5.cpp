#include <iostream>

int main() {
  int contador = 0;

  std::cout << "Demonstracao do 'goto':\n";

loop_inicio: // Define um rótulo (label)
  std::cout << "Contador: " << contador << '\n';
  contador++;

  if (contador < 3) {
    goto loop_inicio; // Salta para o rótulo 'loop_inicio'
  }

  std::cout << "Fim do programa.\n";

  // Exemplo de uso para sair de loops aninhados (um dos poucos casos
  // "aceitáveis")
  std::cout << "\nSaindo de loops aninhados com 'goto':\n";
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::cout << "i = " << i << ", j = " << j << '\n';
      if (i == 1 && j == 1) {
        goto fim_loops; // Salta para o rótulo fora dos loops
      }
    }
  }

fim_loops: // Rótulo para onde o goto salta
  std::cout << "Saiu dos loops aninhados.\n";

  return 0;
}

/*
  Este exemplo demonstra a instrução `goto`, que permite um salto incondicional
  para um rótulo (label) definido em qualquer parte da função.

  O que observar:
  1. **Rótulo (Label):** Um identificador seguido por dois pontos (`:`), como
  `loop_inicio:`.
  2. **Salto Incondicional:** `goto nome_do_rotulo;` transfere o controle de
  execução imediatamente para a instrução após o rótulo.

  **AVISO IMPORTANTE: O uso de `goto` é FORTEMENTE DESENCORAJADO em C++
  moderno.**

  Problemas com `goto`:
  - **Código Espaguete:** Torna o fluxo de controle do programa extremamente
  difícil de seguir, ler, depurar e manter.
  - **Quebra de Estrutura:** Viola os princípios de programação estruturada, que
    promovem o uso de `if/else`, `for`, `while`, `break`, `continue` e funções.
  - **Vazamento de Recursos:** Pode facilmente ignorar a inicialização de
  variáveis ou a chamada de destrutores, levando a vazamentos de memória ou
  outros recursos.

  Casos de Uso (Extremamente Raros e Debatíveis):
  Historicamente, `goto` era usado para sair de loops aninhados (como no segundo
  exemplo) ou para tratamento de erros em código C-style. No entanto, em C++
  moderno, existem alternativas muito melhores e mais seguras:
  - Para sair de loops aninhados: use flags booleanas, funções auxiliares com
  `return`, ou exceções (embora exceções tenham custo de performance).
  - Para tratamento de erros: use exceções, códigos de retorno de erro, ou RAII.

  Performance (Baixa Latência):
  Embora um `goto` seja um salto direto e possa parecer "rápido", ele geralmente
  introduz mais problemas do que soluções em termos de performance e
  manutenibilidade. A imprevisibilidade do salto pode impactar o pipeline da CPU
  e a localidade de código. Em HFT, a clareza e a previsibilidade do fluxo de
  controle são cruciais, e `goto` quase sempre as prejudica. Evite `goto` a todo
  custo.
*/