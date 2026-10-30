#include <iostream>
#include <string>
#include <vector>

// Usaremos uma classe de Log para rastrear as chamadas de construtor/destrutor.
class Log {
public:
  Log(const std::string& nome) : nome_(nome) {
    std::cout << "  [+] CONSTRUTOR PADRAO: '" << nome_ << "'\n";
  }
  Log(const Log& outro) : nome_(outro.nome_ + "_copia") {
    std::cout << "  [C] CONSTRUTOR DE COPIA (caro) de '" << outro.nome_ << "'\n";
  }
  Log(Log&& outro) noexcept : nome_(std::move(outro.nome_)) {
    std::cout << "  [M] CONSTRUTOR DE MOVIMENTACAO (barato) de '" << nome_ << "'\n";
  }
  ~Log() {
    std::cout << "  [-] DESTRUTOR de '" << nome_ << "'\n";
  }
private:
  std::string nome_;
};

// Uma função que cria e retorna um objeto Log.
Log criarLog(const std::string& nome) {
  Log log_local(nome);
  return log_local; // Retorna um objeto nomeado (l-value)
}

// Outra função que retorna um objeto temporário diretamente.
Log criarLogTemporario() {
  return Log("Temporario"); // Retorna um objeto temporário (r-value)
}

int main() {
  std::cout << "--- Demonstrando Copy Elision e RVO ---\n\n";

  std::cout << "--- Cenário 1: Retornando um temporario ---\n";
  // Esperado (sem otimização):
  // 1. Construtor Padrão para "Temporario" dentro da função.
  // 2. Construtor de Movimentação para mover o temporário para 'log1'.
  // 3. Destrutor do temporário.
  //
  // Realidade (com otimização):
  // O compilador "elide" (remove) a movimentação e constrói o objeto
  // DIRETAMENTE no espaço de memória de 'log1'.
  Log log1 = criarLogTemporario();

  std::cout << "\n--- Cenário 2: NRVO (Named Return Value Optimization) ---\n";
  // Esperado (sem otimização):
  // 1. Construtor Padrão para 'log_local' dentro da função.
  // 2. Construtor de Movimentação para mover 'log_local' para 'log2'.
  // 3. Destrutor de 'log_local'.
  //
  // Realidade (com otimização):
  // O compilador é inteligente o suficiente para ver que 'log_local' é o que
  // será retornado, então ele constrói o objeto DIRETAMENTE no espaço de 'log2'.
  Log log2 = criarLog("Log Local");

  std::cout << "\n--- Fim do main. Destrutores serao chamados. ---\n";

  // NOTA DE COMPILAÇÃO:
  // Para desativar esta otimização e ver o que aconteceria sem ela
  // (ou seja, para ver os construtores de movimentação sendo chamados),
  // você pode compilar com a flag: g++ seu_arquivo.cpp -fno-elide-constructors
  return 0;
}

/*
   Explicação: Copy Elision e RVO (Return Value Optimization)


  Este exemplo revela um "truque" que os compiladores modernos usam para tornar o C++ muito mais rápido.


   1. O que é Copy Elision?
       * É uma otimização de compilador que elimina chamadas desnecessárias aos construtores de cópia ou de movimentação.
       * Em vez de criar um objeto temporário e depois copiá-lo ou movê-lo para seu destino final, o compilador reorganiza o código para construir o objeto diretamente em seu
         local de destino.


   2. RVO (Return Value Optimization):
       * É o tipo mais comum de copy elision. Acontece quando uma função retorna um objeto por valor.
       * Cenário 1 (`criarLogTemporario`): A função retorna um r-value (Log("Temporario")). O compilador vê que este temporário será usado para inicializar log1. Em vez de
         criar o temporário e depois movê-lo, ele simplesmente passa o endereço de memória de log1 para a função e constrói o objeto lá. Resultado: apenas uma chamada de
         construtor (o padrão), em vez de um construtor e um move.
       * NRVO (Named Return Value Optimization): Uma forma mais avançada de RVO.
       * Cenário 2 (`criarLog`): A função retorna um l-value (log_local). O compilador é inteligente o suficiente para detectar que esta variável local nomeada é o valor que
         está sendo retornado. Ele então aplica a mesma otimização, construindo log_local diretamente na memória de log2. Resultado: novamente, apenas uma chamada de
         construtor.


   3. Garantias do Padrão C++:
       * Antes do C++17, RVO/NRVO era uma otimização permitida, mas não garantida. Na prática, todos os compiladores modernos a implementam agressivamente.
       * A partir do C++17, a copy elision é garantida em certos casos, como ao inicializar um objeto a partir de um r-value do mesmo tipo (nosso Cenário 1). Isso torna o
         retorno por valor ainda mais confiável em termos de performance.

  Implicações para HFT:


   * Abstrações de Custo Zero: RVO é um exemplo perfeito de uma "abstração de custo zero". Ela permite que você escreva código limpo e legível (retornando objetos complexos
     de funções por valor) com a confiança de que o compilador irá gerar o código de máquina mais otimizado possível, sem nenhuma sobrecarga de cópia ou movimentação.
   * Confie no Compilador: Em C++ moderno, parte da expertise em performance é entender e confiar nessas otimizações do compilador. Tentar "otimizar" manualmente, retornando
     ponteiros ou usando parâmetros de saída, pode muitas vezes resultar em código mais lento e menos seguro do que simplesmente retornar por valor e deixar o compilador
     fazer seu trabalho.
   * Design de API: Isso influencia o design de APIs. Funções de fábrica (factory functions) que criam e retornam objetos complexos são um padrão comum e performático graças
     à RVO.
*/