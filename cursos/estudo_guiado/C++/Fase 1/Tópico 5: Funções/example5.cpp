#include <iostream>
#include <string>
#include <typeinfo> // Para typeid

// Template de função para somar dois valores de qualquer tipo T.
// O compilador irá gerar uma versão específica desta função para cada tipo
// com o qual ela for chamada (ex: somar<int>, somar<double>).
template <typename T> T somar(T a, T b) {
  std::cout << "Chamando somar<" << typeid(T).name()
            << ">\n"; // typeid para mostrar o tipo
  return a + b;
}

// Outro template de função para comparar e imprimir o maior de dois valores.
template <typename Tipo> void imprimirMaior(Tipo val1, Tipo val2) {
  std::cout << "Entre " << val1 << " e " << val2 << ", o maior eh: ";
  if (val1 > val2) {
    std::cout << val1 << '\n';
  } else {
    std::cout << val2 << '\n';
  }
}

int main() {
  std::cout << "Demonstrando Templates de Funcoes.\n\n";

  // O compilador deduz o tipo 'int' para T
  std::cout << "Soma de inteiros: " << somar(10, 20) << '\n';

  // O compilador deduz o tipo 'double' para T
  std::cout << "Soma de doubles: " << somar(15.5, 2.3) << '\n';

  // O compilador deduz o tipo 'float' para T
  std::cout << "Soma de floats: " << somar(1.2f, 3.4f) << '\n';

  // Exemplo com imprimirMaior
  imprimirMaior(50, 75);
  imprimirMaior(10.1, 9.9);
  imprimirMaior('C', 'A'); // Funciona com char tambem!

  // Note que somar("Ola ", "Mundo") funcionaria, mas concatenaria as strings.
  // Templates sao flexiveis, mas o tipo T deve suportar as operacoes usadas.

  std::cout << "\nPrograma finalizado.\n";

  return 0;
}

/*
  Este exemplo demonstra os templates de função em C++.

  O que observar:
  - **Código Genérico:** Templates permitem escrever funções que operam com
    qualquer tipo de dado que satisfaça os requisitos das operações dentro
    da função (ex: `+` para `somar`, `>` para `imprimirMaior`).
  - **`template <typename T>`:** A sintaxe para declarar um template. `T`
    (ou qualquer outro nome) é um "parâmetro de tipo".
  - **Instanciação em Tempo de Compilação:** O compilador gera uma versão
    específica da função para cada tipo com o qual o template é usado.
    Por exemplo, `somar(10, 20)` gera `somar<int>`, e `somar(15.5, 2.3)` gera
    `somar<double>`.

  Performance (Baixa Latência):
  - **Zero Overhead em Tempo de Execução:** Templates são resolvidos
    completamente em **tempo de compilação**. Isso significa que não há
    nenhum custo de performance em tempo de execução por usar um template
    em vez de uma função escrita manualmente para um tipo específico.
  - **Código Otimizado:** Cada instância de um template é um código
    totalmente otimizado para o tipo específico, tão rápido quanto se
    você tivesse escrito a função para aquele tipo manualmente.
  - **Redução de Duplicação:** Templates evitam a duplicação de código,
    o que melhora a manutenibilidade e reduz a chance de erros.
*/