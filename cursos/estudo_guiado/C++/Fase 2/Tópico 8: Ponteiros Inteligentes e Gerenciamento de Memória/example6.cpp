#include <iostream>
#include <memory>
#include <string>
#include <chrono>

class Widget {
public:
    Widget(const std::string& nome) : nome_(nome) {}
    void usar() const { std::cout << "  Usando o Widget '" << nome_ << "'\n"; }
private:
    std::string nome_;
};

// --- Diferentes maneiras de passar um ponteiro inteligente para uma função ---

// Opção 1: Passar shared_ptr por valor.
// CUSTOSO: Envolve uma cópia do shared_ptr e um incremento/decremento atômico
// do contador de referência.
void processarPorValor(std::shared_ptr<Widget> sp) {
    std::cout << "-> Entrou em processarPorValor. Contador de ref.: " << sp.use_count() << "\n";
    sp->usar();
} // sp sai do escopo, contador de ref. diminui.

// Opção 2: Passar shared_ptr por referência constante.
// MAIS RÁPIDO que por valor: Evita a cópia e a manipulação do contador.
// Mas ainda acopla a função ao fato de que o chamador USA um shared_ptr.
void processarPorReferencia(const std::shared_ptr<Widget>& sp) {
    std::cout << "-> Entrou em processarPorReferencia. Contador de ref.: " << sp.use_count() << "\n";
    sp->usar();
}

// Opção 3 (GERALMENTE A MELHOR): Passar por ponteiro bruto ou referência.
// RÁPIDO e FLEXÍVEL: Não há custo de smart pointer. A função não se importa
// como o objeto é gerenciado. Ela apenas "pega emprestado" o objeto.
void processarPorPonteiroBruto(const Widget* wp) {
    std::cout << "-> Entrou em processarPorPonteiroBruto.\n";
    if (wp) {
        wp->usar();
    }
}

int main() {
    std::cout << "--- Criando um shared_ptr para o Widget ---\n";
    auto s_ptr = std::make_shared<Widget>("Meu Widget");
    std::cout << "Contador de referencia inicial: " << s_ptr.use_count() << "\n\n";

    std::cout << "--- 1. Chamando a funcao que recebe por VALOR ---\n";
    processarPorValor(s_ptr);
    std::cout << "Apos a chamada, contador de referencia: " << s_ptr.use_count() << "\n\n";

    std::cout << "--- 2. Chamando a funcao que recebe por REFERENCIA ---\n";
    processarPorReferencia(s_ptr);
    std::cout << "Apos a chamada, contador de referencia: " << s_ptr.use_count() << "\n\n";

    std::cout << "--- 3. Chamando a funcao que recebe por PONTEIRO BRUTO ---\n";
    processarPorPonteiroBruto(s_ptr.get()); // Usa .get() para obter o ponteiro bruto
    std::cout << "Apos a chamada, contador de referencia: " << s_ptr.use_count() << "\n\n";

    return 0;
}

/*
  Explicação: Passando Ponteiros Inteligentes para Funções

  A maneira como você passa um ponteiro inteligente para uma função tem
  implicações diretas na performance e no design do seu código. Este exemplo
  compara as abordagens mais comuns.

  1.  **Passar por Valor (`void func(std::shared_ptr<T> sp)`):**
      -   **O que faz:** Cria uma cópia do `shared_ptr`. Isso incrementa o
          contador de referência na entrada da função e o decrementa na saída.
      -   **Custo:** Esta é a opção mais custosa. A atualização do contador de
          referência é uma operação atômica, que exige sincronização de hardware
          e é significativamente mais lenta que uma operação normal.
      -   **Quando usar:** Use esta abordagem **apenas** quando a função
          precisa, ela mesma, participar da propriedade do objeto. Por exemplo,
          se a função for armazenar uma cópia do `shared_ptr` para uso posterior
          (ex: em outra thread, ou em uma estrutura de dados).

  2.  **Passar por Referência Constante (`void func(const std::shared_ptr<T>& sp)`):**
      -   **O que faz:** Passa uma referência para o `shared_ptr` original,
          evitando a cópia. O contador de referência **não** é modificado.
      -   **Custo:** É muito mais rápido que passar por valor.
      -   **Desvantagem:** Ainda acopla a assinatura da função ao fato de que o
          chamador está usando um `shared_ptr`. A função se torna menos genérica.

  3.  **Passar por Ponteiro Bruto ou Referência (`void func(T* p)` ou `void func(T& r)`):**
      -   **O que faz:** A função recebe apenas um ponteiro ou referência para o
          objeto subjacente, sem saber (ou se importar) como sua vida útil é
          gerenciada.
      -   **Custo:** É a opção mais rápida. Não há nenhuma sobrecarga relacionada
          ao ponteiro inteligente.
      -   **Vantagem de Design:** Esta é a abordagem **mais flexível e desacoplada**.
          A função pode ser chamada com um objeto vindo de um `shared_ptr`
          (usando `.get()`), de um `unique_ptr`, de um objeto na stack, ou de
          qualquer outra fonte. A função simplesmente "observa" ou "usa" o
          objeto durante a chamada.

  **Regra Geral e Implicações para HFT:**

  -   **Prefira passar por ponteiro (`T*`) ou referência (`T&`)**. Isso expressa
      corretamente a intenção de que a função apenas "pega emprestado" o objeto,
      sem afetar sua propriedade. Em HFT, evitar a manipulação do contador de
      referência do `shared_ptr` em funções de alta frequência é uma
      micro-otimização importante.

  -   **Use passagem por valor de `shared_ptr` apenas quando você explicitamente
      precisar compartilhar ou estender a propriedade do objeto.**

  -   Passar `unique_ptr` para funções segue uma lógica similar, mas mais
      restrita:
      -   `void func(std::unique_ptr<T> p)`: Transfere a propriedade para a função.
          O chamador perde o acesso ao objeto.
      -   `void func(T* p)` ou `void func(T& r)`: A melhor opção para apenas
          observar/usar o objeto gerenciado por um `unique_ptr`.
*/