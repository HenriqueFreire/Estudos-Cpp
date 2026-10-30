// Estudo Guiado/C++/Fase 2/Tópico 8: Ponteiros Inteligentes e Gerenciamento de Memória/example7.cpp
#include <iostream>
#include <vector>
#include <string>
#include <utility> // Para std::move

// Uma classe que simula um recurso pesado, como um grande buffer de dados.
class BufferPesado {
public:
  // Construtor padrão
  BufferPesado(const std::string& nome, size_t tamanho) : nome_(nome), dados_(tamanho) {
    std::cout << "  [+] CONSTRUTOR PADRAO: Criado '" << nome_ << "' com " << tamanho << " elementos.\n";
  }

  // 1. Construtor de Cópia (L-value) - CUSTOSO
  // É chamado quando copiamos de um objeto que tem um nome (um l-value).
  BufferPesado(const BufferPesado& outro) : nome_(outro.nome_ + "_copia"), dados_(outro.dados_) {
    std::cout << "  [C] CONSTRUTOR DE COPIA (MUITO CARO): Copiando todos os " << dados_.size() << " elementos de '" << outro.nome_ << "'.\n";
  }

  // 2. Construtor de Movimentação (R-value) - BARATO
  // É chamado quando "copiamos" de um objeto temporário (um r-value).
  // A palavra-chave 'noexcept' é uma otimização importante que informa ao compilador
  // que este construtor não lança exceções.
  BufferPesado(BufferPesado&& outro) noexcept : nome_(std::move(outro.nome_)), dados_(std::move(outro.dados_)) {
    std::cout << "  [M] CONSTRUTOR DE MOVIMENTACAO (BARATO): 'Roubando' os dados de '" << nome_ << "'.\n";
    // O objeto 'outro' fica em um estado válido, mas vazio.
  }

  std::string getNome() const { return nome_; }
  size_t getTamanho() const { return dados_.size(); }

private:
  std::string nome_;
  std::vector<int> dados_;
};

// Função que retorna um objeto pesado por valor.
BufferPesado criarBuffer(const std::string& nome) {
  return BufferPesado(nome, 1000000); // Cria um buffer com 1 milhão de inteiros
}

int main() {
  std::cout << "--- Demonstrando Semantica de Movimentacao ---\n\n";

  std::cout << "--- Cenário 1: Copia (l-value) ---\n";
  BufferPesado buffer_original("Original", 500000);
  BufferPesado buffer_copiado = buffer_original; // Chama o CONSTRUTOR DE CÓPIA (caro)
  std::cout << "  Copia criada: '" << buffer_copiado.getNome() << "' com " << buffer_copiado.getTamanho() << " elementos.\n";
  std::cout << "  Original ainda existe: '" << buffer_original.getNome() << "' com " << buffer_original.getTamanho() << " elementos.\n";

  std::cout << "\n--- Cenário 2: Movimentacao de temporario (r-value) ---\n";
  // A função criarBuffer retorna um objeto temporário (r-value).
  // O compilador escolhe automaticamente o CONSTRUTOR DE MOVIMENTAÇÃO (barato).
  BufferPesado buffer_de_funcao = criarBuffer("Buffer Temporario");
  std::cout << "  Buffer recebido da funcao: '" << buffer_de_funcao.getNome() << "' com " << buffer_de_funcao.getTamanho() << " elementos.\n";

  std::cout << "\n--- Cenário 3: Movimentacao explicita com std::move ---\n";
  // Queremos transferir os dados de 'buffer_de_funcao' para 'buffer_final' sem copiar.
  // std::move transforma um l-value em um r-value, permitindo a chamada do construtor de movimentação.
  BufferPesado buffer_final = std::move(buffer_de_funcao);
  std::cout << "  Buffer final: '" << buffer_final.getNome() << "' com " << buffer_final.getTamanho() << " elementos.\n";
  std::cout << "  Buffer antigo ('buffer_de_funcao') apos o move: Tamanho = " << buffer_de_funcao.getTamanho() << " (esta vazio).\n";

  std::cout << "\n--- Fim do programa ---\n";
  return 0;
}

/*
    Explicação: Semântica de Movimentação (std::move)

  Este exemplo ilustra a diferença crucial entre copiar e mover, um pilar da performance em C++ moderno.

   1. L-values e R-values:
       * L-value: Pense em um objeto que tem um nome e um endereço fixo na memória. Você pode pegar seu endereço (&). buffer_original é um l-value.
       * R-value: Pense em um objeto temporário que está prestes a ser destruído, como o valor de retorno de uma função (criarBuffer(...)). Você não pode pegar seu endereço.

   2. Construtor de Cópia vs. Construtor de Movimentação:
       * O C++ pode ter duas versões de um construtor: uma que aceita um l-value (const BufferPesado&) e outra que aceita um r-value (BufferPesado&&).
       * Cópia (l-value): Quando o compilador vê que você está inicializando a partir de um l-value (um objeto que continuará a existir), ele chama o construtor de cópia.
         Este deve criar uma cópia profunda e independente dos dados, o que é caro.
       * Movimentação (r-value): Quando o compilador vê que você está inicializando a partir de um r-value (um objeto temporário que vai morrer logo em seguida), ele escolhe
         o construtor de movimentação. Em vez de copiar os dados, ele simplesmente "rouba" os ponteiros e recursos internos do objeto temporário e os transfere para o novo
         objeto. Isso é extremamente barato.

   3. `std::move`:
       * std::move é uma "ferramenta de casting". Ele não move nada, mas transforma um l-value em um r-value.
       * É uma promessa que você faz ao compilador: "Eu sei que este objeto (buffer_de_funcao) parece um l-value, mas eu não vou mais usá-lo. Pode tratá-lo como um temporário
         e roubar seus recursos."
       * Após usar std::move em um objeto, ele fica em um estado "válido, mas não especificado" (no nosso caso, vazio). Você não deve mais usar seu valor, apenas permitir que
         ele seja destruído ou atribuir um novo valor a ele.

  Implicações para HFT:

   * Eliminação de Cópias: A semântica de movimentação é a principal ferramenta para eliminar cópias de dados pesados em C++. Em HFT, onde a alocação de memória e a cópia de
     grandes blocos de dados são operações proibitivas em caminhos críticos, a movimentação é essencial.
   * Retorno Eficiente de Funções: Permite que funções retornem objetos complexos (como um std::vector de dados de mercado) por valor de forma muito eficiente, sem o custo de
     uma cópia.
   * Filas e Contêineres: É o que torna o push_back de objetos complexos em um std::vector eficiente, pois o objeto é movido para dentro do contêiner em vez de copiado.

  Este conceito é a base para o funcionamento eficiente de std::unique_ptr e muitos outros componentes da STL.

*/