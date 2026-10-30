#include <iostream>
#include <string> // Para std::string
#include <vector> // Para std::vector

int main() {
  // Exemplo com um array C-style
  int numeros[] = {1, 2, 3, 4, 5};
  std::cout << "Iterando sobre um array C-style:\n";
  for (int num : numeros) { // 'num' é uma cópia de cada elemento
    std::cout << num << " ";
  }
  std::cout << '\n';

  // Exemplo com std::vector
  std::vector<std::string> frutas = {"maca", "banana", "cereja"};
  std::cout << "Iterando sobre um std::vector (por copia):\n";
  for (std::string fruta : frutas) { // 'fruta' é uma cópia de cada string
    fruta += " (copia)";             // Modifica a cópia, não o original
    std::cout << fruta << '\n';
  }
  std::cout << "Vector original apos loop (nao modificado):\n";
  for (const std::string &fruta :
       frutas) { // Iterando por referência constante para mostrar original
    std::cout << fruta << '\n';
  }

  std::cout << '\n';

  // Exemplo com std::vector iterando por referência para modificar elementos
  std::cout
      << "Iterando sobre um std::vector (por referencia para modificar):\n";
  for (std::string &fruta :
       frutas) {              // 'fruta' é uma referência ao elemento original
    fruta += " (modificado)"; // Modifica o elemento original
    std::cout << fruta << '\n';
  }
  std::cout << "Vector original apos loop (modificado):\n";
  for (const std::string &fruta : frutas) {
    std::cout << fruta << '\n';
  }

  std::cout << '\n';

  // Exemplo com std::string (que se comporta como uma coleção de chars)
  std::string saudacao = "Ola Mundo";
  std::cout << "Iterando sobre um std::string:\n";
  for (char c : saudacao) {
    std::cout << c << "-";
  }
  std::cout << '\n';

  return 0;
}

/*
  Este exemplo demonstra o loop `for` baseado em range (range-based for loop),
  introduzido no C++11. Ele oferece uma sintaxe mais concisa e legível para
  iterar sobre coleções (arrays, `std::vector`, `std::string`, etc.).

  Sintaxe: `for (declaracao_de_elemento : range)`

  O que observar:
  1. **Simplicidade:** Elimina a necessidade de gerenciar índices ou iteradores
     manualmente, reduzindo a chance de erros "off-by-one".
  2. **Cópia vs. Referência:**
     - `for (Tipo elemento : range)`: `elemento` é uma **cópia** de cada item.
       Modificações em `elemento` não afetam o original.
     - `for (Tipo& elemento : range)`: `elemento` é uma **referência** a cada
  item. Modificações em `elemento` afetam o original.
     - `for (const Tipo& elemento : range)`: `elemento` é uma **referência
  constante**. Ideal para iterar sem copiar e sem modificar os elementos, sendo
  a forma mais performática para leitura.

  Performance (Baixa Latência):
  - **Geralmente Equivalente:** Para a maioria dos tipos de containers, o
  compilador otimiza o range-based for loop para ser tão eficiente quanto um
  loop `for` tradicional com iteradores.
  - **Evitar Cópias Desnecessárias:** Para tipos complexos (como `std::string`
  ou objetos grandes), iterar por **referência constante (`const Tipo&`)** é
  crucial para a performance, pois evita a cópia de cada elemento em cada
  iteração. Iterar por cópia (`Tipo elemento`) pode ser muito custoso.
  - **Clareza e Segurança:** Embora a performance seja similar, a clareza e a
    redução de erros que o range-based for loop oferece são benefícios
  significativos, especialmente em código complexo onde a robustez é tão
  importante quanto a velocidade.
*/