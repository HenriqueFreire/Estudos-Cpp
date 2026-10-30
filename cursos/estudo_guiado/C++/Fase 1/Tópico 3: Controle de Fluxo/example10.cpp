#include <iostream>

// Uma função "barata" de verificar. Retorna 'true' e imprime uma mensagem.
bool checagemRapida() {
  std::cout << "  (Executou checagemRapida)\n";
  return true;
}

// Uma função que simula uma operação "cara" (ex: acesso a banco de dados,
// cálculo complexo). Retorna 'false' e imprime uma mensagem.
bool checagemCara() {
  std::cout << "  (Executou checagemCara - CUSTOSA)\n";
  return false;
}

int main() {
  std::cout << "Demonstrando '&&' (E logico):\n";
  std::cout << "Condicao: checagemCara() && checagemRapida()\n";
  // Como checagemCara() é false, o programa nem avalia checagemRapida().
  if (checagemCara() && checagemRapida()) {
    // Este bloco não será executado
  } else {
    std::cout << "Resultado: A expressao eh falsa.\n\n";
  }

  std::cout << "Demonstrando '||' (OU logico):\n";
  std::cout << "Condicao: checagemRapida() || checagemCara()\n";
  // Como checagemRapida() é true, o programa nem avalia checagemCara().
  if (checagemRapida() || checagemCara()) {
    std::cout << "Resultado: A expressao eh verdadeira.\n\n";
  } else {
    // Este bloco não será executado
  }

  return 0;
}

/*
  Este exemplo demonstra a "avaliação de curto-circuito" (short-circuit
  evaluation) dos operadores lógicos `&&` (E) e `||` (OU).

  O que observar:
  1. **Operador `&&` (E):** Se o operando da esquerda for `false`, a expressão
     inteira já é garantidamente `false`. Portanto, o C++ **não executa** o
     operando da direita. No nosso exemplo, `checagemRapida()` nunca é chamada
     na primeira condição.

  2. **Operador `||` (OU):** Se o operando da esquerda for `true`, a expressão
     inteira já é garantidamente `true`. Portanto, o C++ **não executa** o
     operando da direita. No nosso exemplo, `checagemCara()` nunca é chamada
     na segunda condição.

  Performance (Baixa Latência):
  Este comportamento não é apenas uma conveniência, é uma ferramenta de
  otimização. O fluxo de controle é alterado em tempo de execução com base no
  resultado intermediário. Em código de baixa latência, isso é usado para:

  - **Minimizar o trabalho:** Ao construir uma condição `if`, você deve sempre
    colocar os testes mais "baratos" (rápidos de executar) e com maior
    probabilidade de resolver a expressão primeiro.

  - **Regra prática para `&&`:** Coloque a condição mais provável de ser `false`
    primeiro. `if (condicao_provavelmente_false && condicao_cara)`.

  - **Regra prática para `||`:** Coloque a condição mais provável de ser `true`
    primeiro. `if (condicao_provavelmente_true || condicao_cara)`.

  Seguir essa ordem garante que as operações mais "caras" (cálculos complexos,
  acessos à memória distantes) sejam executadas o mínimo de vezes possível,
  economizando preciosos ciclos de CPU no caminho crítico do seu programa.
*/