#include <iostream>
#include <string> // Necessário para usar std::string

int main() {
  // 1. Criação de std::string
  // Uma string literal "Ola Mundo" é armazenada em uma área de memória
  // somente leitura. Quando atribuída a um std::string, o std::string
  // geralmente aloca memória no Heap para armazenar uma cópia.
  std::string saudacao = "Ola Mundo";

  // 2. Concatenacao (pode envolver realocação no Heap)
  // Quando concatenamos, se a capacidade atual da string não for suficiente,
  // uma nova e maior área de memória é alocada no Heap, o conteúdo é copiado,
  // e a memória antiga é liberada. Isso é uma operação custosa.
  saudacao += ", C++!"; // Adiciona ", C++!" à string existente

  std::cout << "Saudacao: " << saudacao << '\n';
  std::cout << "Tamanho da string: " << saudacao.length() << '\n';
  std::cout << "Capacidade da string: " << saudacao.capacity()
            << '\n'; // Memória alocada

  // 3. Acesso a caracteres
  // std::string se comporta como um array de caracteres.
  std::cout << "Primeiro caractere: " << saudacao[0] << '\n';

  // 4. Comparacao
  std::string outraSaudacao = "Ola Mundo, C++!";
  if (saudacao == outraSaudacao) {
    std::cout << "As strings sao iguais.\n";
  }

  // 5. Substring
  std::string sub = saudacao.substr(0, 3); // Pega os 3 primeiros caracteres
  std::cout << "Substring: " << sub << '\n';

  return 0;
}

/*
  Explicação: std::string e Alocação no Heap

  std::string é a classe padrão do C++ para manipulação de sequências de
  caracteres. Ao contrário dos arrays de caracteres C-style (char*), std::string
  gerencia automaticamente sua própria memória.

  1.  **Alocação no Heap:** Para strings de tamanho variável, std::string
      geralmente aloca memória dinamicamente no Heap. Isso permite que a string
      cresça ou encolha conforme necessário.
      - `length()`: Retorna o número de caracteres na string.
      - `capacity()`: Retorna o número de caracteres que a string pode armazenar
        atualmente sem precisar realocar memória. A capacidade é frequentemente
        maior que o tamanho para otimizar futuras adições.

  2.  **Custo da Realocação:** Operações como concatenação (`+=`) ou inserção
      podem exigir que std::string realoque sua memória. Se a string precisar
      de mais espaço do que sua capacidade atual, ela:
      a.  Aloca um novo bloco de memória maior no Heap.
      b.  Copia o conteúdo existente para o novo bloco.
      c.  Libera o bloco de memória antigo.
      Essas operações são **custosas** em termos de tempo e podem introduzir
      latência imprevisível, o que é um problema em HFT.

  3.  **Small String Optimization (SSO):** Muitos compiladores C++ implementam
      uma otimização chamada SSO. Para strings muito pequenas (tipicamente até
      15 ou 22 caracteres, dependendo da implementação), o conteúdo da string
      é armazenado diretamente dentro do objeto std::string na Stack, em vez
      de alocar no Heap. Isso evita completamente o custo do Heap para strings
      curtas. No entanto, se a string exceder esse limite, ela voltará a alocar
      no Heap.

  **Implicações para HFT:**
  -   **Evitar Alocações no Heap em Caminhos Críticos:** Em sistemas de baixa
      latência, qualquer operação que possa levar a uma alocação ou realocação
      no Heap é geralmente evitada em caminhos de código sensíveis ao tempo.
      Isso inclui concatenações ou construções de strings complexas.
  -   **Pré-alocação:** Se o tamanho máximo de uma string for conhecido, pode-se
      usar `std::string::reserve()` para pré-alocar a memória necessária,
      evitando realocações futuras.
  -   **Alternativas:** Para mensagens de log ou dados de mercado que precisam
      ser formatados rapidamente, alternativas como buffers de caracteres
      pré-alocados (C-style arrays) ou bibliotecas de formatação de alta
      performance (como `fmtlib`) são frequentemente preferidas.
*/