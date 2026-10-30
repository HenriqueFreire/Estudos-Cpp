#include <iostream>
#include <string>
#include <vector>
#include <memory> // Para std::unique_ptr

// --- Classe Base com Funções Virtuais ---
class Animal {
public:
  Animal(const std::string& nome) : nome_(nome) {}

  // 1. DESTRUTOR VIRTUAL:
  // Essencial para garantir que o destrutor correto (da classe derivada)
  // seja chamado quando deletamos um objeto através de um ponteiro da classe base.
  virtual ~Animal() {
    std::cout << "  ~Destrutor de Animal: " << nome_ << "\n";
  }

  // 2. FUNÇÃO VIRTUAL:
  // A palavra-chave 'virtual' diz ao compilador para resolver a chamada
  // desta função em TEMPO DE EXECUÇÃO (dynamic dispatch), com base no tipo
  // real do objeto, e não no tipo do ponteiro.
  virtual void fazerSom() const {
    std::cout << "  " << nome_ << " faz um som generico de animal.\n";
  }

protected:
  std::string nome_;
};

// --- Classes Derivadas ---
class Cachorro : public Animal {
public:
  Cachorro(const std::string& nome) : Animal(nome) {}
  ~Cachorro() override {
    std::cout << "  ~Destrutor de Cachorro: " << nome_ << '\n';
  }

  // 3. OVERRIDE:
  // A palavra-chave 'override' (C++11) é uma boa prática. Ela garante que
  // esta função está de fato sobrescrevendo uma função virtual da classe base.
  // O compilador dará um erro se não houver uma função virtual correspondente.
  void fazerSom() const override {
    std::cout << "  " << nome_ << " late: Au! Au!\n";
  }
};

class Gato : public Animal {
public:
  Gato(const std::string& nome) : Animal(nome) {}
  ~Gato() override {
    std::cout << "  ~Destrutor de Gato: " << nome_ << '\n';
  }

  void fazerSom() const override {
    std::cout << "  " << nome_ << " mia: Miau!\n";
  }
};

// Esta função demonstra o polimorfismo. Ela não se importa com o tipo real
// do animal, apenas que ele "é um" Animal.
void interagirComAnimal(const Animal* animal_ptr) {
  std::cout << "Interagindo com o animal via ponteiro base:\n";
  animal_ptr->fazerSom(); // A chamada correta (Cachorro ou Gato) é feita aqui!
}

int main() {
  // Usando ponteiros inteligentes (smart pointers) para gerenciar a memória.
  // std::unique_ptr é uma classe RAII que garante que 'delete' seja chamado.
  std::vector<std::unique_ptr<Animal>> animais;
  animais.push_back(std::make_unique<Cachorro>("Rex"));
  animais.push_back(std::make_unique<Gato>("Mimi"));
  animais.push_back(std::make_unique<Animal>("Bicho"));

  std::cout << "--- Iterando sobre a colecao de animais ---\n";
  for (const auto& animal_ptr : animais) {
    // A mesma linha de código se comporta de maneiras diferentes!
    // Isso é polimorfismo dinâmico.
    animal_ptr->fazerSom();
  }

  std::cout << "\n--- Fim do escopo, destrutores serao chamados ---\n";
  // Graças ao destrutor virtual e ao unique_ptr, a limpeza é feita corretamente.
  // O destrutor de Cachorro/Gato será chamado, seguido pelo de Animal.
  return 0;
}

/*
  Explicação: Polimorfismo Dinâmico, `virtual` e v-tables

  Este exemplo demonstra o polimorfismo dinâmico, um dos conceitos mais
  poderosos da POO. Ele permite que você trate objetos de diferentes classes
  derivadas de forma uniforme através de uma interface da classe base.

  1.  **O Problema sem `virtual`:**
      -   Se `fazerSom()` não fosse `virtual` na classe `Animal`, a chamada
          `animal_ptr->fazerSom()` sempre executaria a versão de `Animal`,
          independentemente do objeto real ser um `Cachorro` ou `Gato`. Isso
          ocorre porque, sem `virtual`, a chamada da função é resolvida em
          tempo de compilação (static dispatch) com base no tipo do ponteiro
          (`Animal*`), não no tipo do objeto.

  2.  **A Solução com `virtual`:**
      -   A palavra-chave `virtual` instrui o compilador a gerar código para
          resolver a chamada da função em **tempo de execução** (dynamic dispatch).
      -   **Como funciona (v-table):**
          a.  Quando uma classe tem pelo menos uma função virtual, o compilador
              cria uma "tabela de funções virtuais" (v-table) para essa classe.
              A v-table é um array de ponteiros para as implementações corretas
              das funções virtuais daquela classe.
          b.  Cada objeto dessa classe ganha um membro oculto: um ponteiro para
              a v-table de sua classe (o **v-pointer**).
          c.  Quando você chama `animal_ptr->fazerSom()`, o código gerado faz o
              seguinte:
              1.  Acessa o objeto através de `animal_ptr`.
              2.  Usa o v-pointer do objeto para encontrar a v-table correta.
              3.  Busca o endereço da função `fazerSom` na v-table.
              4.  Chama a função naquele endereço.

  3.  **Destrutor Virtual (`virtual ~Animal()`):**
      -   **CRUCIAL:** Se você pretende deletar um objeto de uma classe derivada
          através de um ponteiro da classe base (o que é comum), o destrutor da
          classe base **DEVE** ser virtual.
      -   Se não for, apenas o destrutor da classe base será chamado, e os
          recursos da classe derivada não serão liberados, causando vazamentos
          de memória e outros bugs.

  **Implicações para HFT e o Custo do Polimorfismo:**
  -   **Custo de Memória:** Cada objeto de uma classe com funções virtuais fica
      um pouco maior, pois precisa armazenar o v-pointer (geralmente 8 bytes
      em sistemas 64-bit).
  -   **Custo de Performance (Dynamic Dispatch):** A chamada de uma função
      virtual é ligeiramente mais lenta que uma chamada de função normal. Ela
      envolve duas ou três leituras de memória extras (v-pointer -> v-table ->
      endereço da função) antes do salto para a função. Isso é chamado de
      "indireção".
  -   **Prevenção de Otimizações:** A natureza dinâmica das chamadas virtuais
      pode impedir certas otimizações do compilador, como o "inlining".
  -   **Trade-off:** Em HFT, o polimorfismo dinâmico é usado com cautela. Ele é
      extremamente útil para criar sistemas flexíveis e extensíveis, mas o
      custo do dynamic dispatch pode ser significativo em loops de baixíssima
      latência. Em muitos casos, alternativas como `std::variant` (C++17) ou
      templates (polimorfismo estático) são preferidas para evitar o overhead
      das v-tables.
*/