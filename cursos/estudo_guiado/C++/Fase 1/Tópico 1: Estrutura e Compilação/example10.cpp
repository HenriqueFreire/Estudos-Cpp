#include <iostream>

// #define é uma diretiva de pré-processador que substitui texto.
// Antes da compilação, toda ocorrência de "MENSAGEM" será substituída
// literalmente por "Olá, macro!".
#define MENSAGEM "Olá, macro!"

int main() {
  std::cout << MENSAGEM << '\n';

  return 0;
}

/*

  #define é uma ferramenta do pré-processador (assim como #include).
  Ele cria o que é chamado de "macro". Neste caso, ele instrui o pré-processador
  a encontrar todas as instâncias de MENSAGEM no código e substituí-las
  textualmente por "Olá, macro!". O compilador em si nunca vê a palavra
  MENSAGEM, ele já recebe o código substituído.

  AVISO IMPORTANTE: Macros de estilo C como esta são poderosas,
  mas também perigosas e propensas a erros sutis.
  O C++ moderno oferece alternativas muito mais seguras e melhores,
  como variáveis const ou constexpr, que veremos na próxima fase.
  Um desenvolvedor Nível 4/5 raramente usa #define para constantes.

*/