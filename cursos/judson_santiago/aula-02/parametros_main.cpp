// parametros_main.cpp - Demonstra o uso de argumentos de linha de comando na
// função main. Este programa recebe argumentos passados durante a execução e os
// exibe no console.

#include <iostream> // Inclui a biblioteca iostream para operações de entrada e saída.
#include <string> // Inclui a biblioteca string para manipulação de strings.

using namespace std; // Usa o namespace padrão para facilitar o acesso a funções
                     // como 'cout' e 'endl'.

// A função main pode receber dois parâmetros para lidar com argumentos de linha
// de comando: argc: (argument count) - Um inteiro que representa o número de
// argumentos passados para o programa.
//                         Sempre será no mínimo 1, pois o nome do próprio
//                         programa é contado como o primeiro argumento.
// argv: (argument vector) - Um array de ponteiros para caracteres (char*[]),
// onde cada ponteiro
//                           aponta para uma string (cadeia de caracteres) que
//                           representa um argumento. argv[0] é sempre o nome do
//                           programa.
int main(int argc, char *argv[]) {

  cout << "Número de argumentos: " << argc
       << endl; // Exibe o número total de argumentos.

  cout << "Argumentos recebidos:" << endl;
  // Loop para iterar sobre todos os argumentos, do primeiro (nome do programa)
  // até o último.
  for (int i = 0; i < argc; ++i) {
    cout << "  Argumento " << i << ": " << argv[i]
         << endl; // Exibe o índice e o valor de cada argumento.
  }

  // Exemplo de como acessar um argumento específico (se existir)
  if (argc >
      1) { // Verifica se há pelo menos um argumento além do nome do programa.
    cout << "\nPrimeiro argumento (excluindo o nome do programa): " << argv[1]
         << endl;
  } else {
    cout << "\nNenhum argumento adicional foi fornecido." << endl;
  }

  return 0; // Retorna 0 para indicar que o programa foi executado com sucesso.
}