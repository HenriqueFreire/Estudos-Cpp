#include <iostream>
#include <string>

// Função que imprime uma mensagem com um prefixo e um sufixo.
// O prefixo e o sufixo têm valores padrão.
void imprimirComBordas(const std::string &mensagem,
                       const std::string &prefixo = "--- ",
                       const std::string &sufixo = " ---") {
  std::cout << prefixo << mensagem << sufixo << '\n';
}

// Função que calcula a potência, com expoente padrão 2 (quadrado).
double potencia(double base, int expoente = 2) {
  double resultado = 1.0;
  for (int i = 0; i < expoente; ++i) {
    resultado *= base;
  }
  return resultado;
}

int main() {
  std::cout << "Demonstrando Argumentos Padrao (Default Arguments).\n\n";

  // Chamada usando todos os argumentos padrão
  imprimirComBordas("Minha Mensagem");

  // Chamada sobrescrevendo apenas o prefixo
  imprimirComBordas("Outra Mensagem", ">>> ");

  // Chamada sobrescrevendo prefixo e sufixo
  imprimirComBordas("Mensagem Final", "### ", " ###");

  std::cout << '\n';

  // Chamada da função potencia com expoente padrão (2)
  std::cout << "O quadrado de 5 eh: " << potencia(5) << '\n'; // expoente = 2

  // Chamada da função potencia com expoente especificado
  std::cout << "5 elevado a 3 eh: " << potencia(5, 3) << '\n'; // expoente = 3

  std::cout << "\nPrograma finalizado.\n";

  return 0;
}

/*
  Este exemplo demonstra o uso de argumentos padrão (default arguments) em
  funções.

  O que observar:
  - **Valores Padrão:** Você pode atribuir um valor padrão a um parâmetro na
    declaração da função. Se o chamador não fornecer um argumento para esse
    parâmetro, o valor padrão será usado.
  - **Ordem:** Argumentos padrão devem ser especificados da direita para a
    esquerda. Uma vez que você define um argumento padrão, todos os parâmetros
    à sua direita também devem ter valores padrão.
  - **Flexibilidade:** Argumentos padrão tornam as funções mais flexíveis,
    permitindo que sejam chamadas com diferentes números de argumentos. Isso
    pode reduzir a necessidade de sobrecargas de função em alguns casos.

  Performance (Baixa Latência):
  - Argumentos padrão são resolvidos em **tempo de compilação**. O compilador
    simplesmente "preenche" os argumentos que faltam com seus valores padrão
    antes de gerar o código.
  - Isso significa que não há nenhum overhead de performance em tempo de
  execução associado ao uso de argumentos padrão. A função é chamada como se
  todos os argumentos tivessem sido explicitamente fornecidos.
  - A performance da função em si segue as mesmas regras de qualquer outra
    função (custo de chamada, passagem de parâmetros, etc.).
*/