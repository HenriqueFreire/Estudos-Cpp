#include <iostream>

int main() {
  int escolha;

  // O loop 'do-while' garante que o bloco de código seja executado
  // pelo menos uma vez, antes de verificar a condição.
  do {
    std::cout << "--- Menu ---\n";
    std::cout << "1. Opcao A\n";
    std::cout << "2. Opcao B\n";
    std::cout << "3. Sair\n";
    std::cout << "Escolha uma opcao: ";
    std::cin >> escolha;

    switch (escolha) {
    case 1:
      std::cout << "Voce escolheu a Opcao A.\n\n";
      break;
    case 2:
      std::cout << "Voce escolheu a Opcao B.\n\n";
      break;
    case 3:
      std::cout << "Saindo do programa.\n\n";
      break;
    default:
      std::cout << "Opcao invalida. Tente novamente.\n\n";
      break;
    }
  } while (escolha != 3); // O loop continua ENQUANTO a escolha não for 3

  return 0;
}

/*
  Este exemplo demonstra o loop `do-while`.

  O que observar:
  - A principal característica do `do-while` é que o bloco de código dentro do
  `do { ... }` é executado **pelo menos uma vez**, independentemente da
  condição.
  - A condição `while (condicao);` é avaliada SOMENTE DEPOIS da primeira
  execução do bloco.
  - É ideal para menus interativos ou quando você precisa realizar uma ação
    inicial antes de decidir se continua ou não.

  Performance (Baixa Latência):
  - Assim como `for` e `while`, a performance do `do-while` é geralmente muito
    eficiente e otimizada pelo compilador.
  - A escolha entre os tipos de loop é uma questão de clareza e de qual se
    encaixa melhor na lógica que você quer implementar.
  - As mesmas regras de otimização se aplicam: mantenha o corpo do loop o mais
    leve e previsível possível para evitar gargalos em código crítico.
*/
