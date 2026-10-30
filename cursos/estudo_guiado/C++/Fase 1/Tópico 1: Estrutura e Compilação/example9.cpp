#include <iostream>

// A diretiva "using namespace std;" importa todos os nomes do namespace std
// para o escopo global. Isso nos permite escrever "cout" em vez de "std::cout".
using namespace std;

int main() {
  // Agora não precisamos mais do prefixo "std::"
  cout << "Sem o prefixo std::\n";

  return 0;
}

/*

  A diretiva using namespace std;
  é um atalho para evitar ter que digitar std::
  antes de cada elemento da biblioteca padrão (como cout, endl, cin, etc.).

  AVISO IMPORTANTE (Performance e Boas Práticas): Embora seja conveniente para
  exemplos pequenos, em projetos grandes e especialmente em arquivos de
  cabeçalho (.h), esta prática é fortemente desaconselhada. Ela "polui" o escopo
  global, podendo levar a conflitos de nomes (ambiguidade) e dificultar a
  leitura do código. Para um desenvolvedor Nível 4/5, o uso explícito de std:: é
  o padrão.

  */