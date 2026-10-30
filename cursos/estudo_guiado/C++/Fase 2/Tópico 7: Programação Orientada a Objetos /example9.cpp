#include <iostream>
#include <string>
#include <vector>
#include <memory> // Para std::unique_ptr

// --- Demonstração da palavra-chave 'final' ---

// Classe base que pode ser herdada
class Base {
public:
  virtual void foo() { std::cout << "Base::foo()\n"; }
  virtual void bar() { std::cout << "Base::bar()\n"; }
};

// Classe derivada que impede herança posterior usando 'final'
class DerivadaFinal final : public Base {
public:
  void foo() override final { // Impede que 'foo' seja sobrescrito novamente
    std::cout << "DerivadaFinal::foo() (final)\n";
  }
  void bar() override { // 'bar' ainda pode ser sobrescrito
    std::cout << "DerivadaFinal::bar()\n";
  }
};

// class OutraDerivada : public DerivadaFinal {}; // ERRO: 'DerivadaFinal' é final

// --- Demonstração de CRTP (Curiously Recurring Template Pattern) ---
// Uma alternativa ao polimorfismo dinâmico para evitar o overhead de v-tables.

// Classe base CRTP
template <typename Derived>
class AnimalCRTP {
public:
  void fazerSom() const {
    // Chama a implementação da classe derivada em tempo de compilação
    static_cast<const Derived*>(this)->fazerSomImpl();
  }

  // Método comum que pode ser usado por todas as classes derivadas
  void comer() const {
    std::cout << "  " << static_cast<const Derived*>(this)->getNome() << " esta comendo (CRTP).\n";
  }

protected:
  // Para simular "funções virtuais puras", deletamos a implementação na base.
  // Isso força a classe derivada a implementar estes métodos, caso contrário,
  // ocorrerá um erro de compilação.
  void fazerSomImpl() const = delete;
  std::string getNome() const = delete;
};

// Classe derivada CRTP
class CachorroCRTP : public AnimalCRTP<CachorroCRTP> {
public:
  CachorroCRTP(const std::string& nome) : nome_(nome) {}

  // Implementação específica para CachorroCRTP
  void fazerSomImpl() const {
    std::cout << "  " << nome_ << " late: Au! Au! (CRTP)\n";
  }
  std::string getNome() const { return nome_; }

private:
  std::string nome_;
};

// Outra classe derivada CRTP
class GatoCRTP : public AnimalCRTP<GatoCRTP> {
public:
  GatoCRTP(const std::string& nome) : nome_(nome) {}

  void fazerSomImpl() const {
    std::cout << "  " << nome_ << " mia: Miau! (CRTP)\n";
  }
  std::string getNome() const { return nome_; }

private:
  std::string nome_;
};


int main() {
  std::cout << "--- Demonstrando 'final' keyword ---\n";
  DerivadaFinal df;
  df.foo(); // Chama DerivadaFinal::foo()
  df.bar(); // Chama DerivadaFinal::bar()

  Base* b_ptr = &df;
  b_ptr->foo(); // Polimorfismo dinâmico ainda funciona
  b_ptr->bar();

  std::cout << "\n--- Demonstrando CRTP (Curiously Recurring Template Pattern) ---\n";

  CachorroCRTP rex("Rex");
  rex.fazerSom(); // Chama CachorroCRTP::fazerSomImpl() estaticamente
  rex.comer();    // Chama AnimalCRTP::comer(), que usa CachorroCRTP::getNome()

  GatoCRTP mimi("Mimi");
  mimi.fazerSom(); // Chama GatoCRTP::fazerSomImpl() estaticamente
  mimi.comer();    // Chama AnimalCRTP::comer(), que usa GatoCRTP::getNome()

  // CRTP não permite polimorfismo em tempo de execução via ponteiros base
  // AnimalCRTP<CachorroCRTP>* animal_ptr = &rex; // Isso não funciona diretamente como com virtual
  // Para coleções heterogêneas, ainda precisaríamos de std::variant ou polimorfismo dinâmico.

  std::cout << "\n--- Fim do programa ---\n";
  return 0;
}

/*
  Explicação: 'final' keyword e CRTP (Curiously Recurring Template Pattern)

  Este exemplo aborda duas técnicas importantes para controle e otimização em C++:
  a palavra-chave `final` e o padrão CRTP.

  1.  **A Palavra-chave `final` (C++11):**
      -   **Para Classes:** Quando aplicada a uma classe (`class MinhaClasse final`),
          impede que qualquer outra classe herde dela. Isso pode ser útil para
          garantir que uma hierarquia de classes não seja estendida de maneiras
          não intencionais ou para otimizações.
      -   **Para Funções Virtuais:** Quando aplicada a uma função virtual
          (`virtual void foo() final`), impede que essa função seja sobrescrita
          por classes derivadas.
      -   **Benefícios de Performance:**
          -   **Otimização do Compilador:** Quando o compilador sabe que uma
              função virtual não pode ser sobrescrita (porque a classe ou a
              função é `final`), ele pode, em alguns casos, otimizar a chamada
              virtual para uma chamada direta (static dispatch), eliminando o
              overhead da v-table. Isso é especialmente relevante em HFT.
          -   **Clareza de Design:** Deixa claro para outros desenvolvedores que
              uma classe ou um método virtual não deve ser estendido/sobrescrito.

  2.  **CRTP (Curiously Recurring Template Pattern):**
      -   **O que é:** É um padrão de design em C++ onde uma classe base
          (`AnimalCRTP`) é um template que recebe a própria classe derivada
          (`CachorroCRTP`) como um parâmetro de template.
          `template <typename Derived> class AnimalCRTP { ... };`
      -   **Polimorfismo Estático:** O CRTP permite alcançar um tipo de
          polimorfismo em tempo de compilação (static polymorphism), em contraste
          com o polimorfismo dinâmico das funções `virtual`.
      -   **Como funciona:** A classe base usa `static_cast<Derived*>(this)`
          para chamar métodos implementados na classe derivada. Como o tipo
          `Derived` é conhecido em tempo de compilação, o compilador pode
          resolver essas chamadas diretamente, sem o uso de v-tables.
      -   **Benefícios de Performance (HFT):**
          -   **Zero Overhead:** Não há custo de v-table ou dynamic dispatch.
              As chamadas de função são resolvidas em tempo de compilação,
              resultando em código tão rápido quanto se você tivesse escrito
              as chamadas diretamente.
          -   **Inlining:** O compilador tem mais oportunidades para realizar
              inlining, o que pode levar a um código ainda mais otimizado.
      -   **Limitações:**
          -   **Não é para Coleções Heterogêneas:** CRTP não permite armazenar
              objetos de diferentes tipos derivados em uma única coleção
              (ex: `std::vector<AnimalCRTP<???>>`) e chamá-los polimorficamente
              em tempo de execução. Para isso, ainda precisaríamos de polimorfismo
              dinâmico (`virtual`) ou alternativas como `std::variant` (C++17).
          -   **Aumento do Tamanho do Binário:** Pode levar a um "code bloat"
              (inchaço do código) se houver muitas instâncias de templates
              geradas para diferentes tipos derivados.

  **Implicações para HFT:**
  -   **`final`:** Use `final` em classes ou funções virtuais quando você sabe
      que não haverá mais herança/sobrescrita. Isso pode dar ao compilador
      oportunidades de otimização valiosas, eliminando indireções e permitindo
      inlining, o que é crucial para latência ultra-baixa.
  -   **CRTP:** Considere CRTP como uma alternativa poderosa ao polimorfismo
      dinâmico quando você precisa de polimorfismo, mas o overhead da v-table
      é inaceitável, e você não precisa de coleções heterogêneas em tempo de
      execução. É uma técnica avançada para extrair o máximo de performance.
*/