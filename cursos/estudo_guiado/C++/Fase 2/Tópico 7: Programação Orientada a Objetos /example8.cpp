#include <iostream>
#include <string>
#include <vector>
#include <memory> // Para std::unique_ptr

// --- Classe Base Abstrata ---
// Uma classe é abstrata se tiver pelo menos uma função virtual pura.
// Não é possível criar instâncias de classes abstratas diretamente.
class Forma {
public:
  Forma(const std::string& nome) : nome_(nome) {}

  // Destrutor virtual é importante para hierarquias polimórficas.
  virtual ~Forma() {
    std::cout << "  ~Destrutor de Forma: " << nome_ << '\n';
  }

  // Função virtual pura:
  // = 0 a torna pura virtual. Classes derivadas DEVEM implementá-la.
  // Isso define uma interface: toda Forma DEVE saber como calcular sua area.
  virtual double calcularArea() const = 0;

  // Função virtual comum (pode ser sobrescrita, mas não é obrigatório)
  virtual void imprimirInfo() const {
    std::cout << "  Forma: " << nome_ << '\n';
  }

protected:
  std::string nome_;
};

// --- Classe Derivada Concreta ---
// Implementa a função virtual pura da classe base.
class Circulo : public Forma {
public:
  Circulo(const std::string& nome, double raio) : Forma(nome), raio_(raio) {}

  ~Circulo() override {
    std::cout << "  ~Destrutor de Circulo: " << nome_ << '\n';
  }

  // Implementação OBRIGATÓRIA da função virtual pura.
  double calcularArea() const override {
    return 3.14159 * raio_ * raio_;
  }

  void imprimirInfo() const override {
    std::cout << "  Circulo: " << nome_ << ", Raio: " << raio_ << ", Area: " << calcularArea() << '\n';
  }

private:
  double raio_;
};

// --- Outra Classe Derivada Concreta ---
class Retangulo : public Forma {
public:
  Retangulo(const std::string& nome, double largura, double double altura)
      : Forma(nome), largura_(largura), altura_(altura) {}

  ~Retangulo() override {
    std::cout << "  ~Destrutor de Retangulo: " << nome_ << '\n';
  }

  // Implementação OBRIGATÓRIA da função virtual pura.
  double calcularArea() const override {
    return largura_ * altura_;
  }

  void imprimirInfo() const override {
    std::cout << "  Retangulo: " << nome_ << ", Largura: " << largura_ << ", Altura: " << altura_ << ", Area: " << calcularArea() << '\n';
  }

private:
  double largura_;
  double altura_;
};

int main() {
  std::cout << "--- Demonstrando Classes Abstratas e Funcoes Virtuais Puras ---\n\n";

  // Forma f("Generica"); // ERRO: Nao pode instanciar classe abstrata 'Forma'

  std::vector<std::unique_ptr<Forma>> formas;
  formas.push_back(std::make_unique<Circulo>("Meu Circulo", 5.0));
  formas.push_back(std::make_unique<Retangulo>("Meu Retangulo", 4.0, 6.0));

  std::cout << "--- Iterando sobre a colecao de formas ---\n";
  for (const auto& forma_ptr : formas) {
    forma_ptr->imprimirInfo();
    // A chamada a calcularArea() tambem e polimorfica
    // std::cout << "    Area calculada: " << forma_ptr->calcularArea() << "\n";
  }

  std::cout << "\n--- Fim do escopo, destrutores serao chamados ---\n";
  return 0;
}

/*
  Explicação: Classes Abstratas e Funções Virtuais Puras

  Este exemplo introduz o conceito de classes abstratas e funções virtuais puras,
  que são fundamentais para definir interfaces em C++.

  1.  **Função Virtual Pura (`= 0`):**
      -   Uma função virtual é declarada como "pura" adicionando `= 0` ao final
          de sua declaração (ex: `virtual double calcularArea() const = 0;`).
      -   Isso significa que a classe base (`Forma`) não fornece uma
          implementação para essa função. Ela apenas declara que *toda* classe
          derivada concreta DEVE fornecer sua própria implementação.
      -   É uma forma de definir um **contrato** ou **interface**.

  2.  **Classe Abstrata:**
      -   Qualquer classe que contenha pelo menos uma função virtual pura é
          considerada uma **classe abstrata**.
      -   **Não é possível criar instâncias diretamente** de uma classe abstrata
          (ex: `Forma f("Generica");` causaria um erro de compilação).
      -   Classes abstratas servem como base para outras classes, definindo uma
          interface comum que as classes derivadas devem seguir.

  3.  **Classes Derivadas Concretas:**
      -   Para que uma classe derivada de uma abstrata possa ser instanciada,
          ela deve **implementar todas as funções virtuais puras** de sua
          classe base.
      -   `Circulo` e `Retangulo` são classes concretas porque implementam
          `calcularArea()`.

  **Implicações para HFT:**
  -   **Definição de Interfaces:** Classes abstratas são usadas para definir
      interfaces claras para componentes do sistema. Por exemplo, uma interface
      `IProcessadorDeMensagens` pode ter uma função virtual pura `processar(const Mensagem& msg) = 0;`.
      Diferentes implementações (processadores de ordens, processadores de dados
      de mercado) podem herdar dessa interface.
  -   **Polimorfismo:** Permite tratar diferentes tipos de objetos de forma
      uniforme através de ponteiros ou referências à classe base abstrata.
      Isso é útil para coleções de objetos heterogêneos (como `std::vector<std::unique_ptr<Forma>>`).
  -   **Custo de v-tables:** Assim como as funções virtuais comuns, as funções
      virtuais puras ainda utilizam o mecanismo de v-tables, o que implica no
      mesmo pequeno overhead de dynamic dispatch. Em caminhos de código
      extremamente críticos, onde esse overhead é inaceitável, alternativas
      como `std::variant` ou `CRTP` (Curiously Recurring Template Pattern)
      podem ser consideradas para polimorfismo estático.
*/