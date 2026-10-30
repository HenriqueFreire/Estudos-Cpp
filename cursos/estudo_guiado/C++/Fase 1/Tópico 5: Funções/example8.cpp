#include <algorithm>  // Para std::for_each
#include <functional> // Para std::function
#include <iostream>
#include <string>
#include <vector>

// Função tradicional para ser usada com std::function
void imprimirMensagemGlobal(const std::string &msg) {
  std::cout << "Mensagem Global: " << msg << '\n';
}

int main() {
  std::cout << "Demonstrando Lambdas e std::function.\n\n";

  // 1. Lambda Simples (sem captura, sem parametros)
  auto lambdaSimples = []() { std::cout << "Esta eh uma lambda simples.\n"; };
  lambdaSimples(); // Chamando a lambda

  // 2. Lambda com Parametros
  auto somarLambda = [](int a, int b) { return a + b; };
  std::cout << "Soma com lambda: " << somarLambda(10, 5) << '\n';

  // 3. Lambda com Captura (por valor e por referencia)
  int x = 10;
  int y = 20;

  // Captura por valor ([=]): copia 'x' e 'y'. Alteracoes em x/y externos nao
  // afetam a lambda.
  auto lambdaCapturaValor = [=]() {
    std::cout << "Lambda captura por valor: x=" << x << ", y=" << y << '\n';
  };
  x = 100;              // Altera o 'x' externo
  lambdaCapturaValor(); // A lambda ainda ve x=10, y=20

  // Captura por referencia ([&]): referencia 'x' e 'y'. Alteracoes afetam a
  // lambda.
  auto lambdaCapturaReferencia = [&]() {
    std::cout << "Lambda captura por referencia: x=" << x << ", y=" << y
              << '\n';
  };
  y = 200;                   // Altera o 'y' externo
  lambdaCapturaReferencia(); // A lambda ve x=100, y=200

  // Captura especifica ([x, &y]): captura 'x' por valor, 'y' por referencia
  auto lambdaCapturaEspecifica = [x, &y]() {
    std::cout << "Lambda captura especifica: x=" << x << ", y=" << y << '\n';
  };
  x = 1000;                  // Nao afeta a lambda
  y = 2000;                  // Afeta a lambda
  lambdaCapturaEspecifica(); // A lambda ve x=100 (valor original de x na
                             // captura), y=2000

  std::cout << '\n';

  // 4. std::function: Um wrapper para qualquer "callable"
  // Pode armazenar funcoes, ponteiros para funcoes, lambdas, etc.
  std::function<int(int, int)>
      operacao; // Declara um std::function que recebe 2 int e retorna 1 int

  operacao = somarLambda; // Armazena a lambda
  std::cout << "std::function com lambda: " << operacao(3, 4) << '\n';

  // Podemos reatribuir para uma funcao tradicional (ponteiro para funcao)
  int (*ptrSomar)(int, int) = [](int a, int b) {
    return a + b;
  }; // Lambda usada como ponteiro para funcao
  operacao = ptrSomar;
  std::cout << "std::function com ponteiro para funcao: " << operacao(6, 7)
            << '\n';

  // Exemplo de uso com std::for_each e lambda
  std::vector<int> numeros = {1, 2, 3, 4, 5};
  std::cout << "\nNumeros no vetor: ";
  std::for_each(numeros.begin(), numeros.end(),
                [](int n) { std::cout << n << " "; });
  std::cout << '\n';

  std::cout << "\nPrograma finalizado.\n";

  return 0;
}

/*
  Este exemplo demonstra duas ferramentas poderosas do C++ moderno (C++11):
  **Lambdas** e **`std::function`**.

  O que observar:
  - **Lambdas (`[] (params) -> return_type { body }`):**
    - São funções anônimas que podem ser definidas "inline" (no local onde são
  usadas).
    - **Cláusula de Captura (`[]`):** Define como a lambda acessa variáveis do
  escopo externo.
      - `[]`: Não captura nada.
      - `[=]`: Captura todas as variáveis usadas por valor (cópia).
      - `[&]`: Captura todas as variáveis usadas por referência.
      - `[var]`: Captura `var` por valor.
      - `[&var]`: Captura `var` por referência.
    - São extremamente úteis para callbacks, algoritmos da STL e para tornar o
      código mais conciso e legível.

  - **`std::function` (`std::function<Signature>`):**
    - É um "wrapper" genérico e polimórfico para qualquer "callable" (algo que
      pode ser chamado como uma função), desde que sua assinatura (tipos de
      parâmetros e retorno) seja compatível.
    - Pode armazenar funções tradicionais, ponteiros para funções, lambdas,
      e objetos de função (functors).
    - Útil quando você precisa armazenar ou passar um callable de forma
  genérica, sem se preocupar com seu tipo exato.

  Performance (Baixa Latência):
  - **Lambdas:**
    - Se uma lambda é simples e não captura muitas variáveis, o compilador
      frequentemente a "inlina" (substitui a chamada pelo corpo da lambda),
      resultando em **zero overhead** em tempo de execução.
    - Lambdas com captura podem ter um pequeno custo adicional para gerenciar
      o estado capturado, mas geralmente são muito eficientes.
  - **`std::function`:**
    - `std::function` introduz um pequeno overhead em tempo de execução devido
      à sua natureza polimórfica (type erasure). É similar ao custo de uma
      chamada de função virtual ou de um ponteiro para função.
    - Em caminhos de código extremamente críticos em HFT, onde cada nanossegundo
      conta, pode-se preferir usar lambdas diretamente (se possível) ou
      ponteiros para função puros para evitar esse overhead. No entanto, para
      a maioria dos casos, a flexibilidade e segurança de `std::function`
      compensam o pequeno custo.
  - **Closures:** A capacidade de lambdas capturarem variáveis é o que as torna
    tão poderosas, permitindo criar "closures" que encapsulam estado e
  comportamento.
*/