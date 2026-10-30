#include <iostream>
#include <string>
#include <vector>

int main() {
  // Exemplo de 'if' com inicialização (C++17)
  // A variável 'tamanho' é inicializada e seu escopo é limitado ao 'if' e
  // 'else'. Isso ajuda a evitar que a variável seja usada indevidamente fora do
  // contexto.
  if (int tamanho = std::vector<int>{1, 2, 3, 4, 5}.size(); tamanho > 3) {
    std::cout << "O vetor tem mais de 3 elementos. Tamanho: " << tamanho
              << '\n';
  } else {
    std::cout << "O vetor tem 3 ou menos elementos. Tamanho: " << tamanho
              << '\n';
  }

  std::cout << '\n';

  // Outro exemplo com uma string
  if (std::string nome = "Alice"; nome.length() > 5) {
    std::cout << "O nome '" << nome << "' tem mais de 5 caracteres.\n";
  } else {
    std::cout << "O nome '" << nome << "' tem 5 ou menos caracteres.\n";
  }

  return 0;
}

/*
  Este exemplo introduz a sintaxe 'if com inicialização', uma funcionalidade
  adicionada no C++17.

  O que observar:
  1. **Sintaxe:** `if (inicializacao; condicao)`
     - A parte de 'inicializacao' é executada uma vez antes da 'condicao' ser
       avaliada.
     - A variável declarada na 'inicializacao' (ex: `tamanho`, `nome`) tem seu
       escopo limitado ao bloco `if` e `else` associado.
  2. **Gerenciamento de Escopo:** Isso é extremamente útil para limitar o escopo
     de variáveis auxiliares que são usadas apenas para a condição do `if`.
     Evita "poluir" o escopo externo e reduz a chance de erros.
  3. **Clareza:** Torna o código mais conciso e legível, agrupando a
  inicialização e a condição logicamente relacionadas.

  Performance (Baixa Latência):
  - **Sem Overhead Direto:** Esta funcionalidade é principalmente uma melhoria
    sintática e de gerenciamento de escopo. Não introduz um overhead de
    performance direto em tempo de execução.
  - **Potencial Indireto:** Ao limitar o escopo de variáveis, pode-se
  indiretamente melhorar a localidade de cache e reduzir o tempo de vida de
  objetos, o que pode ser benéfico em cenários de alta performance.
  - **Boas Práticas:** Em HFT, onde a clareza e a minimização de erros são
    fundamentais, o uso de `if` com inicialização é uma boa prática para
    manter o código limpo e focado.
*/