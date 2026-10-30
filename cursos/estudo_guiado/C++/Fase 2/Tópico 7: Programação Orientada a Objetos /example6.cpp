#include <iostream>
#include <string>

// --- Classe Base ---
// Representa um conceito genérico.
class Animal {
public:
  // Construtor da classe base.
  Animal(const std::string& nome) : nome_(nome) {
    std::cout << "  Construtor de Animal: " << nome_ << " foi criado.\n";
  }

  // Destrutor da classe base.
  ~Animal() {
    std::cout << "  Destrutor de Animal: " << nome_ << " foi destruido.\n";
  }

  // Método que pode ser usado por todas as classes derivadas.
  void comer() const {
    std::cout << "  " << nome_ << " esta comendo.\n";
  }

  // Método que será "sobrescrito" (overridden) pela classe derivada.
  void fazerSom() const {
    std::cout << "  " << nome_ << " faz um som generico de animal.\n";
  }

  std::string getNome() const {
    return nome_;
  }

protected:
  // 'protected' significa que este membro é acessível pela classe base
  // e por qualquer classe que herde dela, mas não pelo público externo.
  std::string nome_;
};


// --- Classe Derivada ---
// 'Cachorro' "é um" 'Animal'. Ele herda publicamente de Animal.
class Cachorro : public Animal {
public:
  // O construtor da classe derivada DEVE chamar o construtor da classe base.
  // Isso é feito na lista de inicialização.
  Cachorro(const std::string& nome) : Animal(nome) {
    std::cout << "  Construtor de Cachorro: " << nome_ << " é um cachorro.\n";
  }

  ~Cachorro() {
    std::cout << "  Destrutor de Cachorro: " << nome_ << " foi destruido.\n";
  }

  // Este método "sobrescreve" o método fazerSom() da classe Animal.
  // Quando chamado em um objeto Cachorro, esta versão será executada.
  void fazerSom() const {
    std::cout << "  " << nome_ << " late: Au! Au!\n";
  }

  // Método específico da classe Cachorro.
  void abanarRabo() const {
    std::cout << "  " << nome_ << " esta abanando o rabo.\n";
  }
};


int main() {
  std::cout << "--- Criando um objeto da classe Base ---\n";
  Animal animal_generico("Bicho");
  animal_generico.fazerSom();
  animal_generico.comer();

  std::cout << "\n--- Criando um objeto da classe Derivada ---\n";
  Cachorro meu_cachorro("Rex");
  // Cachorro pode usar métodos da classe base...
  meu_cachorro.comer();
  // ...pode usar sua versão sobrescrita de um método...
  meu_cachorro.fazerSom();
  // ...e pode usar seus próprios métodos.
  meu_cachorro.abanarRabo();

  std::cout << "\n--- Fim do escopo, destrutores serao chamados na ordem inversa da construcao ---\n";
  return 0;
}

/*
  Explicação: Herança (Inheritance)

  A herança é um dos pilares da Programação Orientada a Objetos (POO). Ela
  permite criar uma nova classe (classe derivada ou filha) que reutiliza,
  estende e modifica o comportamento de uma classe existente (classe base ou pai).

  1.  **Relacionamento "É UM" (Is-A):**
      -   A herança modela um relacionamento "é um". No nosso exemplo, um
          `Cachorro` **é um** `Animal`. Isso significa que um `Cachorro` tem
          todas as características e comportamentos de um `Animal`, e mais alguns
          específicos.

  2.  **Sintaxe (`class Derivada : public Base`):**
      -   `public` na declaração de herança significa que todos os membros
          `public` da classe `Animal` também serão `public` na classe `Cachorro`.
          Isso é o tipo de herança mais comum.

  3.  **Construtores e Destrutores:**
      -   Quando um objeto derivado é criado, o construtor da classe **base** é
          executado primeiro, seguido pelo construtor da classe **derivada**.
      -   Quando o objeto é destruído, a ordem é inversa: o destrutor da classe
          **derivada** é executado primeiro, seguido pelo destrutor da classe
          **base**.

  4.  **Sobrescrita de Métodos (Method Overriding):**
      -   A classe derivada pode fornecer sua própria implementação para um
          método que já existe na classe base (como `fazerSom()`).
      -   Quando o método é chamado em um objeto da classe derivada, a versão
          sobrescrita é a que será executada.
      -   **Importante:** No C++ moderno, usamos a palavra-chave `override` para
          indicar explicitamente que estamos sobrescrevendo um método, e a
          palavra-chave `virtual` na classe base para permitir o polimorfismo
          dinâmico. Veremos isso no próximo exemplo.

  **Polimorfismo Estático (Compile-Time Polymorphism):**
  -   O que vemos neste exemplo é uma forma de polimorfismo estático. O
      compilador sabe, em tempo de compilação, qual versão de `fazerSom()`
      chamar com base no tipo do objeto (`animal_generico` ou `meu_cachorro`).
      Não há custo de performance em tempo de execução para essa decisão.

  **Implicações para HFT:**
  -   A herança pode ser usada para organizar o código e evitar duplicação,
      o que é bom para a manutenibilidade.
  -   No entanto, a herança, especialmente quando combinada com funções virtuais
      (polimorfismo dinâmico), introduz um pequeno overhead que precisa ser
      compreendido e gerenciado em código de baixa latência.
  -   O próximo exemplo irá explorar o **polimorfismo dinâmico** com `virtual`,
      que é muito mais poderoso, mas vem com o custo do "dynamic dispatch"
      através de v-tables.
*/