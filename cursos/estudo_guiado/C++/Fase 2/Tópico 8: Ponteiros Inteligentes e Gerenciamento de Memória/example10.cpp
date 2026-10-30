#include <iostream>
#include <string>
#include <vector>

// Classe que demonstra o uso de membros e métodos estáticos.
class FabricaDeWidgets {
public:
  // Construtor: incrementa o contador estático de widgets criados.
  FabricaDeWidgets(const std::string& nome) : nome_(nome) {
    total_widgets_criados_++;
    id_ = total_widgets_criados_;
    std::cout << "  [+] Widget '" << nome_ << "' (ID: " << id_ << ") criado.\n";
  }

  // Método de membro normal (não estático).
  // Ele opera em uma instância específica do objeto (tem um ponteiro 'this').
  void imprimirInfo() const {
    std::cout << "      Info do Widget: Nome=" << nome_ << ", ID=" << id_ << "\n";
  }

  // --- Métodos Estáticos ---

  // 1. Método estático: pode ser chamado diretamente na classe, sem uma instância.
  // Não tem acesso a membros não estáticos (como 'nome_' ou 'id_'),
  // pois não há um ponteiro 'this'.
  static int getTotalWidgetsCriados() {
    return total_widgets_criados_;
  }

  // Um exemplo de "Factory Method" estático.
  // É uma forma comum de encapsular a criação de objetos.
  static FabricaDeWidgets criarWidgetPadrao() {
    std::cout << "  [*] Usando a fabrica estatica para criar um widget padrao.\n";
    return FabricaDeWidgets("Widget Padrao");
  }

private:
  // Membro de dados normal (não estático).
  // Cada instância da classe tem sua própria cópia.
  std::string nome_;
  int id_;

  // --- Membros Estáticos ---

  // 2. Membro de dados estático.
  // Existe apenas UMA cópia desta variável, compartilhada por TODAS as
  // instâncias da classe. Deve ser inicializada fora da classe.
  static int total_widgets_criados_;
};

// 3. Inicialização do membro de dados estático.
// Isso é feito no escopo global, geralmente no arquivo .cpp.
int FabricaDeWidgets::total_widgets_criados_ = 0;

int main() {
  std::cout << "--- Demonstrando Membros e Metodos Estaticos ---\n\n";

  // Podemos chamar o método estático antes mesmo de criar qualquer objeto.
  std::cout << "Total de widgets criados inicialmente: "
            << FabricaDeWidgets::getTotalWidgetsCriados() << "\n\n";

  // Criando alguns objetos.
  FabricaDeWidgets w1("Alfa");
  FabricaDeWidgets w2("Beta");

  std::cout << "\nTotal de widgets criados agora: "
            << FabricaDeWidgets::getTotalWidgetsCriados() << "\n\n";

  // Usando o factory method estático.
  auto w3 = FabricaDeWidgets::criarWidgetPadrao();

  std::cout << "\nTotal final de widgets criados: "
            << FabricaDeWidgets::getTotalWidgetsCriados() << "\n\n";

  w1.imprimirInfo();
  w2.imprimirInfo();
  w3.imprimirInfo();

  std::cout << "\n--- Fim do programa ---\n";
  return 0;
}

/*
  Explicação: Membros e Métodos Estáticos (`static`)

  A palavra-chave `static` em C++, quando usada dentro de uma classe, muda
  fundamentalmente como um membro ou método se comporta. Em vez de pertencer a
  uma instância individual de um objeto, ele pertence à classe como um todo.

  1.  Membros de Dados Estáticos (`static int total_widgets_criados_`):
      -   Uma Única Cópia: Existe apenas uma única instância dessa variável,
          não importa quantos objetos da classe sejam criados. Todos os objetos
          compartilham essa mesma variável.
      -   Tempo de Vida: A variável estática existe durante toda a execução
          do programa. Ela é inicializada quando o programa começa e destruída
          quando ele termina.
      -   Inicialização: Deve ser definida e inicializada fora da declaração
          da classe, no escopo global (geralmente no arquivo .cpp).
      -   Uso: Ideal para contadores, constantes compartilhadas, ou qualquer
          dado que precise ser comum a todas as instâncias de uma classe.

  2.  Métodos Estáticos (`static int getTotalWidgetsCriados()`):
      -   Sem Instância Necessária: Podem ser chamados diretamente na classe
          (usando `NomeDaClasse::metodo()`) sem a necessidade de criar um objeto.
      -   Sem Ponteiro `this`: Métodos estáticos não recebem o ponteiro
          oculto `this`. Consequentemente, eles não podem acessar membros não
          estáticos (como `nome_` ou `id_`), pois esses membros pertencem a
          instâncias específicas.
      -   Acesso: Eles só podem operar em outros membros estáticos ou dados
          passados como parâmetros.
      -   Uso: Comuns para funções utilitárias que estão logicamente ligadas
          a uma classe, mas não dependem do estado de um objeto específico.
          "Factory methods" (como `criarWidgetPadrao`) são um excelente caso de uso.

  Implicações para HFT:
  -   Estado Global Controlado: Membros estáticos fornecem uma maneira de ter
      um estado "global", mas de forma organizada e encapsulada dentro do escopo
      de uma classe, o que é preferível a variáveis globais verdadeiras.
  -   Performance da Chamada: A chamada de um método estático pode ser
      ligeiramente mais rápida que a de um método de membro, pois não há a
      necessidade de passar o ponteiro `this`. É uma micro-otimização, mas
      relevante.
  -   Localidade de Dados: Membros estáticos são armazenados no segmento de
      dados do programa, não na stack com objetos locais ou no heap com objetos
      dinâmicos. Isso significa que eles têm um endereço de memória fixo durante
      toda a vida do programa, o que pode ser benéfico para a previsibilidade
      de acesso.
  -   Factories: O padrão "Factory Method" estático é útil em HFT para
      controlar a criação de objetos complexos, garantindo que eles sejam
      inicializados corretamente ou venham de um "pool" de objetos pré-alocados.
*/