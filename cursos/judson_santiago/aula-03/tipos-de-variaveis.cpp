// tipo-de-variaveis.cpp - Exemplo didático de diferentes tipos de variáveis em
// C++. Este programa demonstra a declaração e o uso dos tipos de dados mais
// comuns em C++, explicando suas características e faixas de valores.

#include <iomanip> // Inclui a biblioteca iomanip para formatar a saída (setprecision).
#include <iostream> // Inclui a biblioteca iostream para operações de entrada e saída.
#include <limits> // Inclui a biblioteca limits para exibir os limites de alguns tipos.
#include <string> // Inclui a biblioteca string para usar o tipo de dado string.

using namespace std; // Usa o namespace padrão.

int main() {
  cout << "--- Exemplos de Tipos de Variáveis em C++ ---" << endl;
  cout << "---------------------------------------------" << endl << endl;

  // 1. Tipo Inteiro (int)
  //    Armazena números inteiros (positivos, negativos e zero).
  //    O tamanho exato pode variar entre sistemas, mas geralmente é de 4 bytes
  //    (32 bits).
  int idade = 30;
  cout << "1. Inteiro (int):" << endl;
  cout << "   Idade: " << idade << endl;
  cout << "   Tamanho: " << sizeof(int) << " bytes" << endl;
  cout << "   Faixa: " << numeric_limits<int>::min() << " a "
       << numeric_limits<int>::max() << endl
       << endl;

  // 2. Tipo Caractere (char)
  //    Armazena um único caractere (letra, número, símbolo).
  //    Internamente, é armazenado como um número inteiro (código ASCII ou
  //    Unicode).
  char inicial = 'H';
  cout << "2. Caractere (char):" << endl;
  cout << "   Inicial: " << inicial << endl;
  cout << "   Tamanho: " << sizeof(char) << " byte" << endl;
  cout << "   Faixa: " << (int)numeric_limits<char>::min() << " a "
       << (int)numeric_limits<char>::max() << " (como int)" << endl
       << endl;

  // 3. Tipo Booleano (bool)
  //    Armazena valores lógicos: verdadeiro (true) ou falso (false).
  //    'true' é geralmente representado por 1 e 'false' por 0.
  bool estaChovendo = true;
  bool temSol = false;
  cout << "3. Booleano (bool):" << endl;
  cout << "   Está chovendo? " << (estaChovendo ? "Sim" : "Não")
       << endl; // Exibe "Sim" ou "Não"
  cout << "   Tem sol? " << (temSol ? "Sim" : "Não") << endl;
  cout << "   Tamanho: " << sizeof(bool) << " byte" << endl << endl;

  // 4. Tipo Ponto Flutuante (float)
  //    Armazena números com casas decimais (ponto flutuante) com precisão
  //    simples. Geralmente 4 bytes (32 bits) de armazenamento.
  float preco = 19.99f; // O 'f' no final indica que é um float literal.
  cout << "4. Ponto Flutuante (float):" << endl;
  cout << "   Preço: " << fixed << setprecision(2) << preco
       << endl; // Formata para 2 casas decimais
  cout << "   Tamanho: " << sizeof(float) << " bytes" << endl;
  cout << "   Faixa: " << numeric_limits<float>::lowest() << " a "
       << numeric_limits<float>::max() << endl
       << endl;

  // 5. Tipo Ponto Flutuante de Dupla Precisão (double)
  //    Armazena números com casas decimais com precisão dupla.
  //    É o tipo padrão para números decimais em C++ e geralmente tem 8 bytes
  //    (64 bits).
  double pi = 3.1415926535;
  cout << "5. Ponto Flutuante de Dupla Precisão (double):" << endl;
  cout << "   Valor de Pi: " << fixed << setprecision(10) << pi
       << endl; // Formata para 10 casas decimais
  cout << "   Tamanho: " << sizeof(double) << " bytes" << endl;
  cout << "   Faixa: " << numeric_limits<double>::lowest() << " a "
       << numeric_limits<double>::max() << endl
       << endl;

  // 6. Tipo String (std::string)
  //    Não é um tipo primitivo, mas uma classe da biblioteca padrão para
  //    armazenar sequências de caracteres.
  string nome = "Maria Silva";
  cout << "6. String (std::string):" << endl;
  cout << "   Nome: " << nome << endl;
  cout << "   (Tamanho variável, depende do conteúdo)" << endl << endl;

  // Tipos inteiros com modificadores (short, long, unsigned)
  // short: geralmente 2 bytes, menor faixa que int.
  // long: geralmente 4 ou 8 bytes, pode ter faixa maior que int.
  // unsigned: apenas números não negativos, dobra a faixa positiva.
  unsigned int contador = 100000;            // Não pode ser negativo
  long long populacaoMundial = 8000000000LL; // 'LL' para long long literal
  cout << "7. Outros Tipos Inteiros:" << endl;
  cout << "   Contador (unsigned int): " << contador << endl;
  cout << "   População Mundial (long long): " << populacaoMundial << endl;
  cout << "   Tamanho (unsigned int): " << sizeof(unsigned int) << " bytes"
       << endl;
  cout << "   Tamanho (long long): " << sizeof(long long) << " bytes" << endl
       << endl;

  return 0; // Indica que o programa foi executado com sucesso.
}
