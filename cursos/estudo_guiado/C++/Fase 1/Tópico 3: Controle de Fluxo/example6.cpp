#include <iostream>

int main() {
  int idade = 20;
  bool temCarteira = true;

  std::cout << "Verificando elegibilidade para dirigir:\n";

  if (idade >= 18) {
    std::cout << "Idade OK (maior ou igual a 18).\n";
    if (temCarteira) {
      std::cout << "Possui carteira de motorista. Elegivel para dirigir.\n";
    } else {
      std::cout
          << "Nao possui carteira de motorista. Nao elegivel para dirigir.\n";
    }
  } else {
    std::cout
        << "Idade insuficiente (menor que 18). Nao elegivel para dirigir.\n";
  }

  std::cout << "\n";

  int pontuacao = 85;
  bool passouNaProva = true;

  std::cout << "Verificando status do aluno:\n";

  if (passouNaProva) {
    if (pontuacao >= 70) {
      std::cout << "Aluno aprovado com pontuacao: " << pontuacao << ".\n";
    } else {
      std::cout
          << "Aluno reprovado por pontuacao, apesar de ter feito a prova.\n";
    }
  } else {
    std::cout << "Aluno nao fez a prova. Reprovado.\n";
  }

  return 0;
}

/*
  Este exemplo demonstra o uso de `if-else` aninhados, onde uma instrução
  `if-else` está contida dentro de outra. Isso permite criar lógicas de
  decisão mais complexas e hierárquicas.

  O que observar:
  1. **Hierarquia de Condições:** As condições são avaliadas em sequência.
     A condição interna só é verificada se a condição externa for verdadeira.
  2. **Clareza:** A indentação correta é crucial para manter a legibilidade
     e entender qual `else` pertence a qual `if`.
  3. **Alternativa:** Para muitas condições aninhadas, pode-se considerar
     refatorar o código usando funções, `switch` (se aplicável) ou tabelas
     de decisão para melhorar a clareza.

  Performance (Baixa Latência):
  - **Branches Múltiplos:** `if-else` aninhados introduzem múltiplos branches
    no fluxo de execução. Cada `if` é um ponto onde o processador precisa
    prever qual caminho será tomado.
  - **Branch Misprediction:** Se as condições internas não forem altamente
    previsíveis, o processador pode sofrer mais "branch mispredictions",
    o que resulta em penalidades de desempenho significativas.
  - **Otimização:** Em HFT, a complexidade de `if-else` aninhados em caminhos
    críticos é frequentemente evitada ou simplificada. Se a lógica for
    baseada em tipos ou constantes, `if constexpr` pode ser uma alternativa
    sem custo em tempo de execução. Para lógicas de runtime, tentar achatar
    a estrutura de decisão ou usar tabelas de lookup pode ser mais performático.
*/