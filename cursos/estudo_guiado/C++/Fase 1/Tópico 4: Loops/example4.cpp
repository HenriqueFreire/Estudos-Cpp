#include <iostream>
#include <string> // Para std::getline

int main() {
  std::cout << "Demonstrando um loop infinito controlado:\n";
  std::string entrada;
  int contador = 0;

  // Um loop 'for' infinito. A ausência das três partes significa que
  // a condição é sempre verdadeira.
  for (;;) {
    std::cout << "Loop 'for' infinito. Digite 'sair' para terminar: ";
    std::getline(std::cin, entrada); // Lê a linha inteira, incluindo espaços

    if (entrada == "sair") {
      std::cout << "Comando 'sair' detectado. Saindo do loop 'for'.\n";
      break; // Sai do loop 'for'
    }
    contador++;
    std::cout << "Voce digitou: '" << entrada << "'. Iteracao: " << contador
              << '\n';
  }

  std::cout << "\nDemonstrando outro loop infinito controlado (com 'while'):\n";
  contador = 0;
  // Um loop 'while' infinito. A condição 'true' é sempre verdadeira.
  while (true) {
    std::cout << "Loop 'while' infinito. Digite 'parar' para terminar: ";
    std::getline(std::cin, entrada);

    if (entrada == "parar") {
      std::cout << "Comando 'parar' detectado. Saindo do loop 'while'.\n";
      break; // Sai do loop 'while'
    }
    contador++;
    std::cout << "Voce digitou: '" << entrada << "'. Iteracao: " << contador
              << '\n';
  }

  std::cout << "Ambos os loops infinitos foram terminados com sucesso.\n";

  return 0;
}

/*
  Este exemplo demonstra loops infinitos e como controlá-los.

  O que observar:
  - **Loops Infinitos:**
    - `for (;;)`: É a sintaxe clássica para um loop `for` infinito.
    - `while (true)`: É a sintaxe mais legível para um loop `while` infinito.
  - **Controle:** Loops infinitos são úteis em programas que precisam rodar
    continuamente (servidores, sistemas embarcados) ou em menus interativos
    onde a condição de saída é interna ao loop.
  - **Saída:** A instrução `break` é usada para sair de um loop infinito
    quando uma condição específica é atendida. Sem um `break` ou um `return`
    dentro do loop, o programa nunca terminaria.

  Performance (Baixa Latência):
  - Um loop infinito em si não tem um custo de performance inerente maior do
    que um loop com condição de término. A performance depende do trabalho
    feito dentro do loop.
  - A principal preocupação é garantir que o loop não consuma 100% da CPU
    se não houver trabalho útil a ser feito (por exemplo, usando
  `std::this_thread::sleep_for` ou esperando por eventos).
  - Em sistemas de baixa latência, loops infinitos são comuns em "event loops"
    ou "game loops", onde o programa está sempre ativo, esperando por entradas
    ou eventos para processar. A eficiência do trabalho dentro do loop e a
    forma como ele espera por eventos são cruciais.
*/
