#include <iostream>
#include <memory> // Para std::unique_ptr e std::make_unique
#include <string>

// Uma classe simples para demonstrar o ciclo de vida
class Recurso {
public:
  Recurso(const std::string& nome) : nome_(nome) {
    std::cout << "  [+] Recurso '" << nome_ << "' criado.\n";
  }
  ~Recurso() {
    std::cout << "  [-] Recurso '" << nome_ << "' destruído.\n";
  }
  void usar() const {
    std::cout << "      Usando o recurso '" << nome_ << "'.\n";
  }

private:
  std::string nome_;
};

// Função que retorna um std::unique_ptr
std::unique_ptr<Recurso> criarRecurso(const std::string& nome) {
  std::cout << "Criando recurso '" << nome << "' dentro da funcao.\n";
  // std::make_unique é a forma preferida de criar unique_ptr
  // É mais seguro (exceção-safe) e mais eficiente que 'new'.
  return std::make_unique<Recurso>(nome);
}

int main() {
  std::cout << "--- Demonstrando std::unique_ptr ---\n\n";

  // 1. Criação de um unique_ptr
  // 'ptr1' agora possui o objeto Recurso.
  std::unique_ptr<Recurso> ptr1 = std::make_unique<Recurso>("Recurso A");
  ptr1->usar();

  std::cout << "\n--- Tentando copiar um unique_ptr (ERRO DE COMPILAÇÃO) ---\n";
  // std::unique_ptr não pode ser copiado, pois ele representa propriedade exclusiva.
  // std::unique_ptr<Recurso> ptr2 = ptr1; // Descomente para ver o erro de compilação

  std::cout << "\n--- Movendo a propriedade de um unique_ptr ---\n";
  // A propriedade pode ser MOVIDA usando std::move.
  // Após o move, 'ptr1' não possui mais o recurso (fica nullptr).
  std::unique_ptr<Recurso> ptr3 = std::move(ptr1);
  if (ptr1) { // ptr1 agora é nullptr
    ptr1->usar();
  } else {
    std::cout << "  ptr1 agora é nullptr (não possui mais o recurso).\n";
  }
  ptr3->usar(); // ptr3 agora possui o recurso

  std::cout << "\n--- unique_ptr retornado de uma função ---\n";
  // O retorno de um unique_ptr de uma função é eficiente (move semantics).
  std::unique_ptr<Recurso> ptr4 = criarRecurso("Recurso B");
  ptr4->usar();

  std::cout << "\n--- unique_ptr saindo do escopo ---\n";
  {
    std::unique_ptr<Recurso> ptr_escopo = std::make_unique<Recurso>("Recurso Escopo");
    ptr_escopo->usar();
  } // O recurso "Recurso Escopo" é automaticamente destruído aqui.

  std::cout << "\nFim do main. Os recursos restantes serao destruidos.\n";
  // 'ptr3' e 'ptr4' sairão do escopo e seus recursos serão automaticamente destruídos.

  return 0;
}

/*
  Explicação: std::unique_ptr

  `std::unique_ptr` é um ponteiro inteligente (smart pointer) introduzido no C++11
  que implementa o princípio RAII (Resource Acquisition Is Initialization) para
  gerenciar a vida útil de objetos alocados dinamicamente. Ele garante que o
  objeto para o qual aponta seja automaticamente destruído quando o `unique_ptr`
  sai do escopo.

  1.  **Propriedade Exclusiva:**
      -   Um `std::unique_ptr` possui o objeto para o qual aponta de forma
          **exclusiva**. Isso significa que não pode haver dois `unique_ptr`s
          apontando para o mesmo objeto ao mesmo tempo.
      -   Essa exclusividade é imposta em tempo de compilação: `unique_ptr`s
          não podem ser copiados.

  2.  **Semântica de Movimentação:**
      -   Embora não possam ser copiados, `unique_ptr`s podem ser **movidos**.
          Quando um `unique_ptr` é movido, a propriedade do recurso é transferida
          do `unique_ptr` de origem para o de destino. O `unique_ptr` de origem
          fica vazio (aponta para `nullptr`).
      -   Isso é eficiente e seguro, pois evita cópias caras e garante que apenas
          um `unique_ptr` seja responsável pela liberação do recurso.

  3.  **RAII e Destruição Automática:**
      -   Quando um `unique_ptr` sai do escopo (seja por fim de função, fim de
          bloco, ou exceção), seu destrutor é chamado. O destrutor do `unique_ptr`
          chama `delete` no ponteiro bruto que ele gerencia, liberando a memória
          do objeto.
      -   Isso elimina a necessidade de chamar `delete` manualmente, prevenindo
          vazamentos de memória e erros de `double free`.

  4.  **`std::make_unique` (C++14):**
      -   É a forma **preferida** de criar `std::unique_ptr`s.
      -   **Segurança contra Exceções:** Garante que, se uma exceção ocorrer
          durante a construção do objeto, não haverá vazamento de memória.
      -   **Eficiência:** Realiza uma única alocação de memória para o objeto
          e para o `unique_ptr` em si, o que pode ser mais eficiente que usar
          `new` diretamente.

  **Implicações para HFT:**
  -   **Zero Overhead:** `std::unique_ptr` tem **zero overhead** em tempo de
      execução em comparação com um ponteiro bruto. Ele é apenas um wrapper
      em tempo de compilação que adiciona segurança e automação.
  -   **Prevenção de Vazamentos:** Em sistemas de alta performance que rodam
      por longos períodos, vazamentos de memória são inaceitáveis. `unique_ptr`
      garante que os recursos sejam liberados de forma determinística.
  -   **Clareza de Propriedade:** Deixa claro no código quem é o "dono" de um
      recurso, o que é crucial para a manutenibilidade de código complexo.
  -   **Substituição de Ponteiros Brutos:** Em C++ moderno, `std::unique_ptr`
      deve ser a escolha padrão para gerenciar recursos alocados no Heap,
      substituindo quase todas as instâncias de ponteiros brutos (`new`/`delete`).
*/