#include <iostream>
#include <string>

// Este arquivo demonstra os vários tipos de operadores em C++.
// Operadores são símbolos que executam operações em variáveis e valores.

int main() {
  // --- 1. Operadores Aritméticos ---
  // Usados para realizar operações matemáticas.
  int a = 10;
  int b = 3;
  std::cout << "--- Operadores Aritméticos (a=10, b=3) ---" << std::endl;
  std::cout << "Soma (a + b): " << (a + b) << std::endl;          // 13
  std::cout << "Subtração (a - b): " << (a - b) << std::endl;     // 7
  std::cout << "Multiplicação (a * b): " << (a * b) << std::endl; // 30
  std::cout << "Divisão (a / b): " << (a / b)
            << std::endl; // 3 (divisão inteira, a parte decimal é descartada)
  std::cout << "Módulo (a % b): " << (a % b)
            << std::endl; // 1 (resto da divisão)

  // Para uma divisão com resultado decimal, um dos operandos deve ser de ponto
  // flutuante.
  float a_float = 10.0f;
  float b_float = 3.0f;
  std::cout << "Divisão com float (a / b): " << (a_float / b_float)
            << std::endl; // 3.333...
  std::cout << std::endl;

  // --- 2. Operadores de Atribuição ---
  // Usados para atribuir valores a variáveis.
  int x = 20;
  std::cout << "--- Operadores de Atribuição (x=20) ---" << std::endl;
  std::cout << "Valor inicial de x: " << x << std::endl;

  x += 5;                                         // Equivalente a: x = x + 5;
  std::cout << "Após x += 5: " << x << std::endl; // 25

  x -= 10;                                         // Equivalente a: x = x - 10;
  std::cout << "Após x -= 10: " << x << std::endl; // 15

  x *= 2;                                         // Equivalente a: x = x * 2;
  std::cout << "Após x *= 2: " << x << std::endl; // 30

  x /= 6;                                         // Equivalente a: x = x / 6;
  std::cout << "Após x /= 6: " << x << std::endl; // 5
  std::cout << std::endl;

  // --- 3. Operadores de Incremento e Decremento ---
  // Adicionam ou subtraem 1 de uma variável.
  int y = 5;
  std::cout << "--- Operadores de Incremento e Decremento (y=5) ---"
            << std::endl;

  // Pós-incremento: usa o valor de y e DEPOIS incrementa.
  std::cout << "Pós-incremento (y++): " << y++
            << std::endl; // Mostra 5, mas y agora é 6.
  std::cout << "Valor de y agora: " << y << std::endl; // 6

  // Pré-incremento: PRIMEIRO incrementa o valor de y e DEPOIS o usa.
  std::cout << "Pré-incremento (++y): " << ++y
            << std::endl; // y se torna 7 e então é mostrado.

  // O mesmo se aplica ao decremento.
  std::cout << "Pós-decremento (y--): " << y--
            << std::endl; // Mostra 7, mas y agora é 6.
  std::cout << "Pré-decremento (--y): " << --y
            << std::endl; // y se torna 5 e então é mostrado.
  std::cout << std::endl;

  // --- 4. Operadores Relacionais (Comparação) ---
  // Comparam dois valores e retornam um resultado booleano (true ou false).
  int val1 = 10;
  int val2 = 5;
  std::cout << "--- Operadores Relacionais (val1=10, val2=5) ---" << std::endl;
  std::cout << "val1 == val2 (Igual a): " << (val1 == val2)
            << std::endl; // 0 (false)
  std::cout << "val1 != val2 (Diferente de): " << (val1 != val2)
            << std::endl; // 1 (true)
  std::cout << "val1 > val2 (Maior que): " << (val1 > val2)
            << std::endl; // 1 (true)
  std::cout << "val1 < val2 (Menor que): " << (val1 < val2)
            << std::endl; // 0 (false)
  std::cout << "val1 >= val2 (Maior ou igual a): " << (val1 >= val2)
            << std::endl; // 1 (true)
  std::cout << "val1 <= val2 (Menor ou igual a): " << (val1 <= val2)
            << std::endl; // 0 (false)
  std::cout << std::endl;

  // --- 5. Operadores Lógicos ---
  // Usados para combinar múltiplas condições.
  bool cond1 = true;
  bool cond2 = false;
  std::cout << "--- Operadores Lógicos (cond1=true, cond2=false) ---"
            << std::endl;
  // E (AND): && -> Retorna true apenas se AMBAS as condições forem verdadeiras.
  std::cout << "cond1 && cond2 (E): " << (cond1 && cond2)
            << std::endl; // 0 (false)

  // OU (OR): || -> Retorna true se PELO MENOS UMA das condições for verdadeira.
  std::cout << "cond1 || cond2 (OU): " << (cond1 || cond2)
            << std::endl; // 1 (true)

  // NÃO (NOT): ! -> Inverte o valor booleano.
  std::cout << "!cond1 (NÃO): " << (!cond1) << std::endl; // 0 (false)
  std::cout << std::endl;

  // --- 6. Operador Ternário ---
  // Um atalho para uma instrução if-else simples.
  // sintaxe: condicao ? valor_se_verdadeiro : valor_se_falso;
  int idade_usuario = 18;
  std::string status =
      (idade_usuario >= 18) ? "Maior de idade" : "Menor de idade";
  std::cout << "--- Operador Ternário ---" << std::endl;
  std::cout << "Idade: " << idade_usuario << " -> Status: " << status
            << std::endl;
  std::cout << std::endl;

  // --- 7. Operadores Bitwise (Bit a Bit) ---
  // Tópico mais avançado, usado para manipulação direta dos bits de um número.
  // & (AND), | (OR), ^ (XOR), ~ (NOT), << (shift left), >> (shift right)
  std::cout << "--- Operadores Bitwise (Avançado) ---" << std::endl;
  std::cout << "Estes são operadores mais avançados para manipulação de bits."
            << std::endl;

  return 0; // Indica que o programa terminou com sucesso.
}
