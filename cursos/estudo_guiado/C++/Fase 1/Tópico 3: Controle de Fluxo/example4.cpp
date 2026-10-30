#include <iostream>
#include <type_traits> // Para std::is_integral, std::is_floating_point

// Um template de função que demonstra if constexpr
template <typename T> void processarValor(T valor) {
  // if constexpr é avaliado em tempo de compilação
  if constexpr (std::is_integral_v<T>) {
    // Este bloco é compilado APENAS se T for um tipo integral
    std::cout << "Processando um inteiro: " << valor * 2 << '\n';
  } else if constexpr (std::is_floating_point_v<T>) {
    // Este bloco é compilado APENAS se T for um tipo de ponto flutuante
    std::cout << "Processando um float: " << valor * 1.5 << '\n';
  } else {
    // Este bloco é compilado APENAS se T não for nenhum dos anteriores
    std::cout << "Processando um tipo desconhecido.\n";
  }
}

int main() {
  processarValor(10);      // T será int
  processarValor(3.14);    // T será double
  processarValor("texto"); // T será const char*

  return 0;
}

/*
  Este exemplo introduz `if constexpr`, uma funcionalidade do C++17 que permite
  ramificação em tempo de compilação. Ao contrário de um `if` normal, onde
  ambos os ramos são compilados e um é escolhido em tempo de execução, com
  `if constexpr`, apenas o ramo que satisfaz a condição é compilado.

  O que observar:
  1. `template <typename T>`: A função `processarValor` é um template,
     o que significa que ela pode operar com diferentes tipos de dados.
  2. `if constexpr (...)`: A condição dentro do `if constexpr` deve ser
     avaliável em tempo de compilação (uma expressão constante booleana).
  3. `std::is_integral_v<T>` e `std::is_floating_point_v<T>`: São traits de
     tipo do C++ (disponíveis a partir do C++17) que verificam se um tipo `T`
     é integral ou de ponto flutuante, respectivamente. O `_v` no final é
     um "variable template" que simplifica o acesso ao valor booleano do trait.

  Performance (Baixa Latência):
  `if constexpr` é uma ferramenta poderosa para otimização em HFT porque
  elimina completamente o custo de um branch em tempo de execução. O compilador
  gera código apenas para o caminho que será realmente executado para um dado
  tipo `T`. Isso significa:
  - **Zero overhead de branch prediction:** Não há branches para o processador
    prever ou errar.
  - **Código menor e mais rápido:** Apenas o código relevante é incluído no
    binário final, potencialmente melhorando a localidade de cache de
  instruções.
  - **Flexibilidade:** Permite escrever código genérico que se comporta de
    maneiras fundamentalmente diferentes para tipos distintos, sem custo em
    tempo de execução.
*/