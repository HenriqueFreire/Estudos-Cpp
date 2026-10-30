#include <iostream>

int main(int argc, char *argv[]) {
  // A função main pode retornar valores diferentes de 0 para sinalizar erros.
  // Por convenção, 0 é sucesso. 1 (ou qualquer outro valor diferente de zero) é
  // erro.

  // Este é um exemplo: se o programa não receber argumentos, ele "falha".
  if (argc < 2) {
    std::cout << "Erro: Argumentos insuficientes.\n";
    return 1; // Sinaliza um erro para o sistema operacional
  }

  std::cout << "Sucesso: O programa recebeu argumentos.\n";
  return 0; // Sinaliza sucesso
}

/*

  Aqui, a função main foi declarada com int argc, char* argv[].
  Estes são parâmetros para receber argumentos da linha de comando (veremos em
  detalhes mais tarde). Oimportante é a lógica do return. Se uma condição de
  erro for encontrada, retornamos 1. Caso contrário, retornamos 0. Sistemas de
  automação e scripts podem verificar esse "código de saída" para saber se seu
  programa foi executado corretamente.

*/