#include <iostream>
#include <string> // Para std::string

// Função que modifica um valor passado por referência
void dobrarValor(int &numero) {
  // 'numero' é uma referência à variável original.
  // Alterar 'numero' aqui altera a variável original.
  numero *= 2;
  std::cout << "Dentro de dobrarValor: numero = " << numero << '\n';
}

// Função que recebe um objeto grande por referência constante
// para evitar cópias e garantir que o objeto não será modificado.
void imprimirStringGrande(const std::string &texto) {
  // 'texto' é uma referência constante.
  // Não podemos modificar 'texto' aqui.
  std::cout << "Dentro de imprimirStringGrande: " << texto << '\n';
  // texto += " (modificado)"; // Isso causaria um erro de compilação!
}

int main() {
  int meuNumero = 5;
  std::cout << "Antes de dobrarValor: meuNumero = " << meuNumero << '\n';
  dobrarValor(meuNumero); // Passa 'meuNumero' por referência
  std::cout << "Depois de dobrarValor: meuNumero = " << meuNumero
            << '\n'; // meuNumero foi alterado!

  std::cout << '\n';

  std::string minhaString =
      "Esta eh uma string muito longa que queremos passar eficientemente.";
  std::cout << "Antes de imprimirStringGrande: " << minhaString << '\n';
  imprimirStringGrande(
      minhaString); // Passa 'minhaString' por referência constante
  std::cout << "Depois de imprimirStringGrande: " << minhaString
            << '\n'; // minhaString nao foi alterada!

  return 0;
}

/*
  Este exemplo explora a passagem de parâmetros por referência (`&`) e
  por referência constante (`const &`), que são cruciais para a performance
  e o controle de dados em C++.

  O que observar:
  1. **Passagem por Referência (`Tipo&`):**
     - O parâmetro da função (`int& numero`) torna-se um **apelido** para a
       variável original passada na chamada da função.
     - Alterações feitas no parâmetro dentro da função **afetam a variável
  original**.
     - Útil quando a função precisa modificar o valor de uma variável externa.
  2. **Passagem por Referência Constante (`const Tipo&`):**
     - O parâmetro (`const std::string& texto`) também é um apelido para a
       variável original, **evitando a cópia**.
     - No entanto, o `const` garante que a função **não pode modificar** a
       variável original.
     - Ideal para passar objetos grandes (como `std::string`, `std::vector`,
       ou structs/classes complexas) para funções que precisam apenas lê-los,
       pois combina a eficiência de evitar cópias com a segurança de não
       alterar o dado fonte.

  Performance (Baixa Latência):
  - **Evitar Cópias Custosas:** Este é um dos pilares da otimização em C++.
    Passar objetos grandes por valor (copiando-os) pode ser extremamente
    lento, pois envolve alocação de memória e cópia de dados.
  - **Passagem por Referência Constante:** É a técnica preferida para passar
    objetos grandes para funções que não precisam modificá-los. Ela oferece
    a eficiência de passar apenas um endereço de memória (geralmente 8 bytes
    em sistemas 64-bit) em vez de copiar o objeto inteiro, sem o risco de
    modificações acidentais.
  - **Impacto Direto em HFT:** Em sistemas de HFT, onde mensagens, ordens e
    dados de mercado podem ser estruturas complexas, usar `const &` para
    passar esses objetos para funções de processamento é fundamental para
    minimizar a latência e o consumo de CPU.
*/