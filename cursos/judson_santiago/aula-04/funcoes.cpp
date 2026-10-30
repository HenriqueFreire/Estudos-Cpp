#include <iostream>
#include <string>

// Este arquivo demonstra o conceito e uso de funções em C++.
// Funções são blocos de código que realizam uma tarefa específica e podem ser
// chamados de qualquer parte do programa. Elas ajudam a organizar o código,
// torná-lo reutilizável e mais fácil de entender.

// --- 1. Declaração de Função (Protótipo) ---
// A declaração informa ao compilador sobre a existência de uma função antes de
// sua implementação. É útil quando a definição da função aparece depois de ela
// ser usada no código. Formato: tipo_de_retorno nome_da_funcao(parametros);
void saudacao(); // Protótipo da função 'saudacao'

// Protótipo de uma função que recebe parâmetros e retorna um valor.
int somar(int a, int b);

// --- 2. Função Principal (main) ---
// O ponto de entrada de todo programa C++.
int main() {
  std::cout << "--- Chamando Funções ---" << std::endl;

  // Chamando uma função simples que não recebe nem retorna nada.
  saudacao();

  // Chamando uma função que recebe argumentos e retorna um valor.
  int resultado = somar(5, 3);
  std::cout << "O resultado da soma é: " << resultado << std::endl;
  std::cout << std::endl;

  // --- 5. Passagem por Valor vs. Passagem por Referência ---
  std::cout << "--- Passagem por Valor vs. Referência ---" << std::endl;
  int numero = 10;
  std::cout << "Valor original do número: " << numero << std::endl;

  // Passagem por valor: uma CÓPIA do valor é passada para a função.
  // A variável original não é alterada.
  void porValor(int n); // Protótipo
  porValor(numero);
  std::cout << "Valor após 'porValor': " << numero << std::endl; // Continua 10

  // Passagem por referência: a função recebe uma REFERÊNCIA à variável
  // original. Qualquer alteração dentro da função afeta a variável original.
  void porReferencia(int &n); // Protótipo
  porReferencia(numero);
  std::cout << "Valor após 'porReferencia': " << numero
            << std::endl; // Agora é 20
  std::cout << std::endl;

  // --- 6. Sobrecarga de Funções (Function Overloading) ---
  // Permite ter múltiplas funções com o mesmo nome, desde que seus parâmetros
  // sejam diferentes (seja no número de parâmetros ou no tipo deles).
  std::cout << "--- Sobrecarga de Funções ---" << std::endl;
  int soma_int = somar(10, 20);
  double soma_double =
      somar(4.5, 2.2); // O compilador escolhe a função correta.

  double somar(double a, double b); // Protótipo da versão sobrecarregada

  std::cout << "Soma de dois inteiros: " << soma_int << std::endl;
  std::cout << "Soma de dois doubles: " << soma_double << std::endl;
  std::cout << std::endl;

  // --- 7. Funções com Argumentos Padrão ---
  std::cout << "--- Argumentos Padrão ---" << std::endl;
  void mostrarMensagem(std::string msg, int vezes = 1); // Protótipo

  mostrarMensagem(
      "Olá!"); // Chama a função usando o valor padrão para 'vezes' (1).
  mostrarMensagem("Mundo!",
                  3); // Chama a função fornecendo um valor para 'vezes'.

  return 0;
}

// --- 3. Definição de Funções ---
// Aqui está a implementação (o corpo) das funções declaradas anteriormente.

// Definição da função 'saudacao'.
// 'void' significa que a função não retorna nenhum valor.
void saudacao() {
  std::cout << "Olá! Esta mensagem veio de uma função." << std::endl;
}

// Definição da função 'somar'.
// 'int' significa que a função retorna um valor do tipo inteiro.
// 'a' e 'b' são os parâmetros da função.
int somar(int a, int b) {
  return a + b; // A palavra-chave 'return' envia o resultado de volta.
}

// --- 4. Mais exemplos de funções ---

// Passagem por valor
void porValor(int n) {
  n = 99; // Altera a CÓPIA local. A variável original em main() não é afetada.
}

// Passagem por referência usando o operador '&'
void porReferencia(int &n) {
  n = 20; // Altera a variável ORIGINAL que foi passada como argumento.
}

// Definição da versão sobrecarregada de 'somar' para doubles.
double somar(double a, double b) { return a + b; }

// Definição da função com argumento padrão.
void mostrarMensagem(std::string msg, int vezes) {
  for (int i = 0; i < vezes; ++i) {
    std::cout << msg << std::endl;
  }
}
