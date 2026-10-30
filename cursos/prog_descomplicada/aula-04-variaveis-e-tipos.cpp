#include <iostream>
#include <limits>
#include <string>

// Este arquivo demonstra os conceitos básicos de variáveis e tipos de dados em
// C++. Variáveis são "caixas" na memória do computador onde podemos armazenar
// informações. Cada "caixa" tem um tipo, que define que tipo de informação ela
// pode guardar (números, texto, etc.).

int main() {
  // --- 1. Tipos Numéricos Inteiros ---
  // Usados para armazenar números sem parte decimal.

  // 'int': O tipo inteiro mais comum. Geralmente tem 32 bits.
  int idade = 30;
  std::cout << "--- Tipos Inteiros ---" << std::endl;
  std::cout << "Idade (int): " << idade << std::endl;

  // 'short': Ocupa menos espaço que 'int'. Útil para economizar memória.
  short ano = 2024;
  std::cout << "Ano (short): " << ano << std::endl;

  // 'long': Pode armazenar números maiores que 'int'.
  long populacao_cidade =
      1234567L; // O 'L' no final é opcional, mas boa prática.
  std::cout << "População (long): " << populacao_cidade << std::endl;

  // 'long long': Para números inteiros realmente grandes.
  long long populacao_mundo = 8000000000LL; // O 'LL' é recomendado.
  std::cout << "População do Mundo (long long): " << populacao_mundo
            << std::endl;

  // Modificadores 'signed' e 'unsigned'
  // 'unsigned' significa que a variável só pode armazenar valores positivos,
  // o que dobra sua capacidade para números positivos.
  unsigned int distancia_sol_terra_km = 149600000;
  std::cout << "Distância Sol-Terra (unsigned int): " << distancia_sol_terra_km
            << " km" << std::endl;
  std::cout << std::endl;

  // --- 2. Tipos Numéricos de Ponto Flutuante ---
  // Usados para armazenar números com parte decimal.

  // 'float': Precisão simples. Ocupa menos espaço.
  float preco_cafe =
      5.99f; // O 'f' no final é importante para indicar que é um float.
  std::cout << "--- Tipos de Ponto Flutuante ---" << std::endl;
  std::cout << "Preço do Café (float): R$ " << preco_cafe << std::endl;

  // 'double': Precisão dupla. Mais preciso que 'float' e é o tipo padrão para
  // decimais.
  double pi = 3.1415926535;
  std::cout << "Valor de PI (double): " << pi << std::endl;
  std::cout << std::endl;

  // --- 3. Tipo Caractere ---
  // Usado para armazenar um único caractere.

  // 'char': Armazena um caractere, como uma letra, número ou símbolo.
  // O valor é colocado entre aspas simples ''.
  char letra_inicial = 'H';
  char simbolo = '@';
  std::cout << "--- Tipo Caractere ---" << std::endl;
  std::cout << "Letra Inicial (char): " << letra_inicial << std::endl;
  std::cout << "Símbolo (char): " << simbolo << std::endl;
  std::cout << std::endl;

  // --- 4. Tipo Booleano ---
  // Armazena um de dois valores: verdadeiro (true) ou falso (false).

  // 'bool': Muito usado para testes e condições.
  bool esta_chovendo = false;
  bool o_sol_e_quente = true;
  std::cout << "--- Tipo Booleano ---" << std::endl;
  std::cout << "Está chovendo? (bool): " << esta_chovendo << " (0 para false)"
            << std::endl;
  std::cout << "O sol é quente? (bool): " << o_sol_e_quente << " (1 para true)"
            << std::endl;
  std::cout << std::endl;

  // --- 5. Tipo String (Texto) ---
  // Não é um tipo primitivo, mas uma classe da biblioteca padrão do C++.
  // Requer a inclusão de <string>.

  // 'std::string': Para armazenar sequências de caracteres (texto).
  // O valor é colocado entre aspas duplas "".
  std::string nome_completo = "Jonas da Silva";
  std::cout << "--- Tipo String ---" << std::endl;
  std::cout << "Nome Completo (std::string): " << nome_completo << std::endl;
  std::cout << std::endl;

  // --- 6. Constantes ---
  // Variáveis cujo valor não pode ser alterado após a inicialização.

  // 'const': Usado para declarar uma constante.
  const double VELOCIDADE_DA_LUZ_MS = 299792458.0;
  std::cout << "--- Constantes ---" << std::endl;
  std::cout << "A velocidade da luz é uma constante: " << VELOCIDADE_DA_LUZ_MS
            << " m/s" << std::endl;
  // A linha abaixo causaria um erro de compilação, pois não podemos mudar o
  // valor de uma constante. VELOCIDADE_DA_LUZ_MS = 300000000.0;

  // --- 7. Inferência de Tipo com 'auto' (C++11 em diante) ---
  // O compilador descobre o tipo da variável automaticamente com base no valor
  // inicial.
  auto pais = "Brasil";    // O compilador entende que 'pais' é const char* (ou
                           // std::string com a devida conversão)
  auto ano_atual = 2024;   // O compilador entende que 'ano_atual' é int
  auto temperatura = 25.5; // O compilador entende que 'temperatura' é double

  std::cout << "\n--- Inferência com 'auto' ---" << std::endl;
  std::cout << "País: " << pais << " (Tipo inferido)" << std::endl;
  std::cout << "Ano: " << ano_atual << " (Tipo inferido)" << std::endl;
  std::cout << "Temperatura: " << temperatura << " (Tipo inferido)"
            << std::endl;

  return 0; // Indica que o programa terminou com sucesso.
}
