#include <iostream>
#include <string>

// Função que recebe um nome (string) como parâmetro e imprime uma saudação
// personalizada. 'nome' é uma cópia do valor passado.
void saudarPessoa(std::string nome) {
  std::cout << "Ola, " << nome << "! Bem-vindo(a) ao programa.\n";
}

// Função que recebe dois números inteiros e imprime a soma deles.
// 'a' e 'b' são cópias dos valores passados.
void imprimirSoma(int a, int b) {
  std::cout << "A soma de " << a << " e " << b << " eh: " << (a + b) << '\n';
}

int main() {
  std::cout << "Iniciando o programa de saudacoes e somas.\n";

  // Chamando a função saudarPessoa com diferentes argumentos
  saudarPessoa("Alice");
  saudarPessoa("Bob");

  std::cout << '\n';

  // Chamando a função imprimirSoma com diferentes argumentos
  imprimirSoma(10, 5);
  imprimirSoma(7, 13);

  std::cout << "Programa finalizado.\n";

  return 0;
}

/*
  Este exemplo demonstra como as funções podem receber parâmetros (entradas).

  O que observar:
  - **Parâmetros:** São variáveis declaradas na definição da função que recebem
    os valores (argumentos) passados durante a chamada da função.
  - **Passagem por Valor:** Por padrão, em C++, os parâmetros são passados por
    valor. Isso significa que uma **cópia** do argumento é feita e usada dentro
    da função. Qualquer alteração no parâmetro dentro da função não afeta a
    variável original que foi passada.
  - **Flexibilidade:** Parâmetros tornam as funções muito mais flexíveis e
    úteis, pois elas podem operar com diferentes dados a cada chamada.

  Performance (Baixa Latência):
  - Para tipos de dados pequenos e simples (como `int`, `double`, `bool`),
    passar por valor (copiar) é geralmente muito eficiente e não causa overhead
    significativo.
  - No entanto, para tipos de dados maiores e mais complexos (como
  `std::string`, `std::vector`, ou objetos de classes grandes), a cópia pode ser
  uma operação muito custosa em termos de tempo e memória.
  - Em código de baixa latência, é crucial estar ciente do custo da cópia.
    Veremos no próximo exemplo como evitar cópias desnecessárias usando
    passagem por referência.
*/