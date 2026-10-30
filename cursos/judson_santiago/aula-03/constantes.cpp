// constantes.cpp - Exemplo didático de como usar constantes em C++.
// Este programa demonstra diferentes maneiras de definir e utilizar valores
// constantes, que não podem ser alterados durante a execução do programa.

#include <iostream> // Inclui a biblioteca iostream para operações de entrada e saída.
#include <string> // Inclui a biblioteca string para manipulação de strings (para a constante de string).

using namespace std; // Usa o namespace padrão.

// 1. Constante definida com #define (pré-processador)
//    É uma substituição textual simples que ocorre antes da compilação.
//    Não tem tipo e não ocupa espaço na memória do programa em tempo de
//    execução.
#define PI_MACRO 3.14159265359

// 2. Constante global definida com 'const'
//    Tem um tipo e é verificada pelo compilador. Ocupa espaço na memória.
//    É uma prática mais segura e recomendada em C++ do que #define para
//    constantes numéricas.
const double GRAVIDADE_TERRA = 9.81;

int main() {
  // 3. Constante local definida com 'const'
  //    A constante é válida apenas dentro do escopo onde foi declarada (neste
  //    caso, a função main).
  const int IDADE_MINIMA_VOTO = 16;

  // 4. Constante de string
  const string MENSAGEM_BOAS_VINDAS = "Bem-vindo ao programa de constantes!";

  cout << MENSAGEM_BOAS_VINDAS << endl;
  cout << "-------------------------------------" << endl;

  cout << "Valor de PI (macro): " << PI_MACRO << endl;
  cout << "Aceleração da gravidade na Terra: " << GRAVIDADE_TERRA << " m/s^2"
       << endl;
  cout << "Idade mínima para votar: " << IDADE_MINIMA_VOTO << " anos" << endl;

  // Tentativa de alterar uma constante (resultaria em erro de compilação)
  // PI_MACRO = 3.14; // Erro: não é uma variável, é uma substituição textual.
  // GRAVIDADE_TERRA = 9.80; // Erro: atribuição a uma variável somente leitura.
  // IDADE_MINIMA_VOTO = 18; // Erro: atribuição a uma variável somente leitura.

  // Exemplo de uso de constantes em cálculos
  double raio = 5.0;
  double area_circulo = PI_MACRO * raio * raio; // Usando a constante PI_MACRO
  cout << "\nÁrea de um círculo com raio " << raio << ": " << area_circulo
       << endl;

  return 0; // Indica que o programa foi executado com sucesso.
}