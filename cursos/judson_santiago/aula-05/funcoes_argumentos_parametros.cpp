#include <iostream>
#include <string>

// Bem-vindo à sua lição sobre funções, parâmetros e argumentos em C++!
// Este arquivo irá guiá-lo através dos conceitos centrais com exemplos claros.

// ====================================================================================
// CONCEITO 1: Funções, Parâmetros e Argumentos
//
// - FUNÇÃO: Um bloco de código nomeado que realiza uma tarefa específica.
//           Ajuda a organizar o código, torná-lo reutilizável e melhorar a
//           legibilidade.
//
// - PARÂMETRO: Uma variável declarada na assinatura de uma função (dentro dos
// parênteses).
//              Atua como um placeholder para um valor que a função precisa para
//              fazer seu trabalho.
//
// - ARGUMENTO: O valor real que é passado para a função quando ela é chamada.
// ====================================================================================

// --- Exemplo 1: Uma função simples ---
// Esta função não tem parâmetros e não retorna nenhum valor (void).
void exibirIntroducao() {
  std::cout << "--- Bem-vindo ao Tutorial de Funções! ---" << std::endl;
}

// --- Exemplo 2: Função com parâmetros ---
// Esta função, `somar`, tem dois PARÂMETROS: `int a` e `int b`.
// Ela é projetada para receber dois inteiros e retornar sua soma.
int somar(int a, int b) {
  // 'a' e 'b' contêm os valores passados quando a função é chamada.
  return a + b;
}

// ====================================================================================
// CONCEITO 2: Passagem por Valor vs. Passagem por Referência
// Isso determina se uma função trabalha com uma cópia dos seus dados ou com os
// dados originais.
// ====================================================================================

// --- Exemplo 3: Passagem por VALOR ---
// Por padrão, C++ passa argumentos por valor.
// A função recebe uma CÓPIA do argumento.
// Quaisquer alterações no parâmetro dentro da função NÃO afetam a variável
// original.
void dobrarValorPorCopia(int numero) {
  numero = numero * 2; // Modifica a CÓPIA
  std::cout << "[Dentro de dobrarValorPorCopia] O número agora é: " << numero
            << std::endl;
}

// --- Exemplo 4: Passagem por REFERÊNCIA ---
// Para passar por referência, adicionamos um e comercial (&) ao tipo do
// parâmetro. A função recebe uma REFERÊNCIA (um apelido) para o argumento
// original. Quaisquer alterações no parâmetro dentro da função IRÃO AFETAR a
// variável original.
void dobrarValorPorReferencia(int &numero) {
  numero = numero * 2; // Modifica a variável ORIGINAL
  std::cout << "[Dentro de dobrarValorPorReferencia] O número agora é: "
            << numero << std::endl;
}

// ====================================================================================
// CONCEITO 3: Parâmetros Padrão (Default)
// Você pode fornecer um valor padrão para um parâmetro. Se um argumento para
// esse parâmetro não for fornecido na chamada da função, o valor padrão é
// usado.
// ====================================================================================

// --- Exemplo 5: Função com um parâmetro padrão ---
// O parâmetro `pontuacao` tem um valor padrão de "!".
void saudar(std::string nome, std::string pontuacao = "!") {
  std::cout << "Olá, " << nome << pontuacao << std::endl;
}

// A função `main` é onde seu programa começa a execução.
int main() {
  // --- Chamando uma função simples ---
  exibirIntroducao();
  std::cout << std::endl;

  // --- Chamando uma função com ARGUMENTOS ---
  int num1 = 10;
  int num2 = 5;
  // Aqui, `num1` e `num2` (cujos valores são 10 e 5) são os ARGUMENTOS.
  int soma = somar(num1, num2);
  std::cout << "Chamando somar(" << num1 << ", " << num2 << ")" << std::endl;
  std::cout << "Resultado da soma: " << soma << std::endl;
  std::cout << "----------------------------------------" << std::endl;

  // --- Demonstrando Passagem por VALOR ---
  int meuValor = 7;
  std::cout << "meuValor original antes da passagem por valor: " << meuValor
            << std::endl;
  dobrarValorPorCopia(meuValor); // Passa uma cópia de meuValor
  std::cout << "meuValor original depois da passagem por valor: " << meuValor
            << " (INALTERADO)" << std::endl;
  std::cout << "----------------------------------------" << std::endl;

  // --- Demonstrando Passagem por REFERÊNCIA ---
  int meuValorDeReferencia = 7;
  std::cout
      << "meuValorDeReferencia original antes da passagem por referência: "
      << meuValorDeReferencia << std::endl;
  dobrarValorPorReferencia(
      meuValorDeReferencia); // Passa uma referência para meuValorDeReferencia
  std::cout
      << "meuValorDeReferencia original depois da passagem por referência: "
      << meuValorDeReferencia << " (ALTERADO!)" << std::endl;
  std::cout << "----------------------------------------" << std::endl;

  // --- Demonstrando Parâmetros Padrão ---
  std::cout << "Chamando saudar() com um argumento:" << std::endl;
  saudar("Alice"); // O valor padrão "!" será usado para a pontuação.

  std::cout << "\nChamando saudar() com dois argumentos:" << std::endl;
  saudar("Bob", "!!!"); // Nós fornecemos nossa própria pontuação.

  return 0; // Indica que a execução foi bem-sucedida
}