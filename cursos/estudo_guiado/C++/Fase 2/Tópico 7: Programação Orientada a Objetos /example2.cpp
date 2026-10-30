#include <iostream>
#include <string>
#include <vector>

// Classe que demonstra o ciclo de vida de um objeto e o princípio RAII.
// RAII (Resource Acquisition Is Initialization) significa que a aquisição de um
// recurso (como memória, um arquivo, um socket) é vinculada ao tempo de vida
// de um objeto.
class Recurso {
public:
  // 1. Construtor: Chamado quando o objeto é criado.
  // É o local ideal para adquirir recursos.
  Recurso(const std::string& nome) : nome_(nome) {
    std::cout << "  [+] Recurso '" << nome_ << "' adquirido (Construtor)\n";
  }

  // 2. Destrutor: Chamado automaticamente quando o objeto é destruído.
  // O til (~) antes do nome da classe o identifica como um destrutor.
  // É o local ideal para liberar os recursos adquiridos no construtor.
  ~Recurso() {
    std::cout << "  [-] Recurso '" << nome_ << "' liberado (Destrutor)\n";
  }

  void usar() const {
    std::cout << "      ... usando o recurso '" << nome_ << "' ...\n";
  }

private:
  std::string nome_;
};

void demonstrarEscopo() {
  std::cout << "Entrando na funcao demonstrarEscopo().\n";
  Recurso recurso_funcao("Recurso da Funcao");
  recurso_funcao.usar();
  std::cout << "Saindo da funcao demonstrarEscopo(). O recurso sera liberado "
               "agora.\n";
}

int main() {
  std::cout << "Iniciando o programa.\n";

  // Criando um recurso dentro de um escopo local.
  {
    std::cout << "Entrando no escopo interno {}.\n";
    Recurso recurso_local("Recurso Local");
    recurso_local.usar();
    std::cout << "Saindo do escopo interno {}. O recurso sera liberado agora.\n";
  } // O destrutor de 'recurso_local' é chamado aqui automaticamente.

  std::cout << "\nDe volta ao escopo principal.\n\n";

  demonstrarEscopo();

  std::cout << "\nPrograma finalizado.\n";
  return 0;
}

/*
  Explicação: Construtores, Destrutores e RAII

  Este exemplo demonstra três conceitos fundamentais da POO em C++:

  1.  **Construtor:**
      -   É um método especial chamado automaticamente quando um objeto de uma
          classe é criado.
      -   Seu nome é o mesmo da classe.
      -   É usado para inicializar os membros do objeto e garantir que ele
          esteja em um estado válido desde o início.
      -   No exemplo, `Recurso(const std::string& nome)` é o construtor.

  2.  **Destrutor:**
      -   É um método especial chamado automaticamente quando um objeto é
          destruído (sai do escopo, é deletado, etc.).
      -   Seu nome é `~` seguido do nome da classe.
      -   É usado para "limpar" o objeto, principalmente para liberar recursos
          que ele adquiriu durante sua vida (memória, arquivos, conexões de rede).

  3.  **RAII (Resource Acquisition Is Initialization):**
      -   Este é um dos padrões de design mais importantes e poderosos do C++.
      -   A ideia é que a posse de um recurso (memória, arquivo, etc.) seja
          vinculada ao tempo de vida de um objeto.
      -   O recurso é adquirido no **construtor** do objeto.
      -   O recurso é liberado no **destrutor** do objeto.
      -   **Benefício Principal:** Garante que os recursos sejam liberados de
          forma automática e determinística, mesmo em caso de exceções. Isso
          previne vazamentos de recursos (memory leaks, file handle leaks, etc.)
          e torna o código muito mais robusto e seguro.
      -   `std::vector`, `std::string`, `std::unique_ptr` são todos exemplos
          de classes que seguem o princípio RAII.

  **A Regra dos 3/5/0 (Introdução):**
  -   Quando uma classe gerencia um recurso bruto (como um ponteiro alocado com
      `new`), o construtor e o destrutor padrão que o compilador gera não são
      suficientes.
  -   Se você copiar um objeto que contém um ponteiro, a cópia terá o mesmo
      ponteiro. Quando um dos objetos for destruído, ele liberará a memória.
      Quando o segundo objeto for destruído, ele tentará liberar a mesma
      memória novamente (double free), causando um crash.
  -   Para resolver isso, você precisa implementar suas próprias versões do
      **construtor de cópia**, **operador de atribuição por cópia** e, em C++11,
      o **construtor de movimentação** e o **operador de atribuição por
      movimentação**. Isso é conhecido como a "Regra dos 3/5".
  -   A "Regra do 0" é a abordagem moderna: prefira usar classes que já gerenciam
      recursos (como `std::vector`, `std::string`, `std::unique_ptr`) em vez de
      ponteiros brutos, para que você não precise escrever nenhuma dessas
      funções especiais.

  **Implicações para HFT:**
  -   RAII é fundamental em HFT para garantir que recursos críticos (memória,
      conexões de rede) sejam gerenciados de forma previsível e sem vazamentos.
  -   A destruição automática no final do escopo significa que a liberação de
      recursos é determinística e não depende de um coletor de lixo
      imprevisível.
  -   Evitar ponteiros brutos e usar classes RAII (como `std::unique_ptr`)
      torna o código mais seguro e rápido de desenvolver, sem sacrificar a
      performance.
*/