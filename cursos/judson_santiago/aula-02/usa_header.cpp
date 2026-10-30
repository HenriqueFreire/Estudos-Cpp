// usa_header.cpp - Demonstra o uso de um arquivo de cabeçalho personalizado.
// Este arquivo-fonte inclui "example-header.h" e utiliza a função e a constante
// declaradas nele.

#include "example-header.h" // Inclui nosso arquivo de cabeçalho personalizado.
#include <iostream>         // Para operações de entrada/saída (cout, endl).
    // As aspas duplas indicam que o compilador deve procurar
    // o arquivo no diretório atual ou nos diretórios de inclusão especificados.

using namespace std; // Usa o namespace padrão.

// Implementação da função declarada em example-header.h
// É importante que a implementação esteja em um arquivo .cpp para evitar erros
// de múltiplas definições quando o cabeçalho é incluído em vários
// arquivos-fonte.
int dobrarNumero(int numero) { return numero * 2; }

int main() {
  int valor = 10;
  // Usa a função declarada no cabeçalho
  cout << "O dobro de " << valor << " é: " << dobrarNumero(valor) << endl;

  // Usa a constante definida no cabeçalho
  cout << "O valor de PI é: " << PI << endl;

  return 0; // Indica que o programa foi executado com sucesso.
}
