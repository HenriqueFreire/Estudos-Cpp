#include <iostream>
#include <memory> // Para std::unique_ptr
#include <stdexcept> // Para std::runtime_error

class RecursoFraco {
public:
  RecursoFraco() { std::cout << "  [+] RecursoFraco adquirido.\n"; }
  ~RecursoFraco() { std::cout << "  [-] RecursoFraco liberado.\n"; }
};

// --- Cenário 1: Gerenciamento Manual com Ponteiro Bruto ---
void processamentoComPonteiroBruto(bool falhar) {
  std::cout << "--- Iniciando processamento com ponteiro bruto ---\n";
  RecursoFraco* ptr_bruto = new RecursoFraco(); // 1. Recurso é alocado

  if (falhar) {
    std::cout << "  *** Ocorreu um erro! Saindo da funcao prematuramente... ***\n";
    // 2. Se sairmos aqui, a linha 'delete ptr_bruto' nunca é alcançada.
    // O resultado é um VAZAMENTO DE MEMÓRIA (MEMORY LEAK).
    return;
  }

  // 3. Se tudo correr bem, liberamos a memória manualmente.
  delete ptr_bruto;
  std::cout << "--- Finalizado processamento com ponteiro bruto ---\n";
}

// --- Cenário 2: Gerenciamento Automático com Ponteiro Inteligente ---
void processamentoComPonteiroInteligente(bool falhar) {
  std::cout << "\n--- Iniciando processamento com ponteiro inteligente ---\n";
  // 1. Recurso é alocado e sua posse é entregue a um unique_ptr.
  std::unique_ptr<RecursoFraco> ptr_inteligente = std::make_unique<RecursoFraco>();

  if (falhar) {
    std::cout << "  *** Ocorreu um erro! Saindo da funcao prematuramente... ***\n";
    // 2. Mesmo saindo aqui, o destrutor de 'ptr_inteligente' será chamado
    // automaticamente quando ele sair do escopo.
    // O destrutor do unique_ptr chamará 'delete' no recurso.
    // NENHUM VAZAMENTO DE MEMÓRIA!
    return;
  }

  // 3. Não precisamos de 'delete'. A limpeza é automática.
  std::cout << "--- Finalizado processamento com ponteiro inteligente ---\n";
} // O destrutor de 'ptr_inteligente' é chamado aqui em um fluxo normal.

int main() {
  std::cout << "Demonstrando um vazamento de memoria com ponteiro bruto:\n";
  processamentoComPonteiroBruto(true); // O destrutor do RecursoFraco não será chamado.

  std::cout << "\n##################################################\n";

  std::cout << "\nDemonstrando a seguranca com ponteiro inteligente:\n";
  processamentoComPonteiroInteligente(true); // O destrutor do RecursoFraco SERÁ chamado.

  return 0;
}

/*
  Explicação: Ponteiros Brutos vs. Ponteiros Inteligentes (Segurança)

  Este exemplo ilustra o principal motivo pelo qual o gerenciamento manual de
  memória com ponteiros brutos (`new` e `delete`) é perigoso e desaconselhado
  em C++ moderno.

  1.  **O Problema com Ponteiros Brutos:**
      -   Quando você aloca memória com `new`, você se torna **100% responsável**
          por liberá-la com `delete`.
      -   O problema é que o fluxo de um programa pode ser complexo. Funções
          podem ter múltiplos pontos de saída (`return`), e exceções podem ser
          lançadas.
      -   No exemplo `processamentoComPonteiroBruto`, se a condição `falhar` for
          verdadeira, a função retorna antes que a linha `delete ptr_bruto;`
          seja alcançada.
      -   O resultado é um **vazamento de memória (memory leak)**. A memória
          alocada para `RecursoFraco` nunca é liberada. Em um programa que roda
          por muito tempo (como um sistema de HFT), pequenos vazamentos se
          acumulam e podem, eventualmente, esgotar a memória do sistema,
          causando uma falha catastrófica.

  2.  **A Solução com Ponteiros Inteligentes (RAII):**
      -   `std::unique_ptr` (e outros ponteiros inteligentes) resolvem esse
          problema de forma elegante usando o padrão **RAII (Resource
          Acquisition Is Initialization)**.
      -   A posse do recurso alocado é imediatamente transferida para o objeto
          `unique_ptr`.
      -   A linguagem C++ garante que, não importa como a função termine (seja
          por um `return` normal, um `return` prematuro ou uma exceção), os
          destrutores de todos os objetos locais criados naquele escopo serão
          chamados.
      -   No exemplo `processamentoComPonteiroInteligente`, quando a função
          retorna, o destrutor de `ptr_inteligente` é invocado. O trabalho do
          destrutor do `unique_ptr` é chamar `delete` no ponteiro bruto que ele
          gerencia.
      -   **Resultado:** A liberação do recurso é garantida, automática e segura.
          O código fica mais limpo (sem `delete`s espalhados) e imensamente mais
          robusto.

  **Implicações para HFT:**
  -   **Robustez é Crucial:** Sistemas de HFT devem ser extremamente robustos.
      Vazamentos de memória são inaceitáveis. O uso de ponteiros inteligentes
      para gerenciar recursos dinâmicos é uma prática padrão para garantir essa
      robustez.
  -   **Código Mais Simples:** Embora o foco seja em performance, a
      legibilidade e a manutenibilidade do código também são importantes.
      Ponteiros inteligentes tornam o código de gerenciamento de recursos
      trivialmente correto, permitindo que os desenvolvedores se concentrem na
      lógica de negócio.
  -   **Regra Geral:** Em C++ moderno, você quase nunca deve escrever `new` ou
      `delete` diretamente.
      -   Para um único objeto no Heap, use `std::make_unique`.
      -   Para um array de objetos no Heap, use `std::vector` (preferencial) ou
          `std::make_unique<Tipo[]>(tamanho)`.
      -   Se precisar de propriedade compartilhada, use `std::make_shared`.
*/