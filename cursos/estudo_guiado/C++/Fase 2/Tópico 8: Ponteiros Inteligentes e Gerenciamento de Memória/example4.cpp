#include <iostream>
#include <memory>
#include <cstdio> // Para FILE, fopen, fclose, fputs

// --- Cenário: Gerenciar um recurso que não é memória, como um 'FILE*' da biblioteca C ---

// Função que simula a escrita em um arquivo
void escreverEmArquivo(FILE* f) {
  if (f) {
    fputs("Ola, mundo dos recursos!\n", f);
    std::cout << "  Escreveu no arquivo com sucesso.\n";
  } else {
    std::cout << "  Ponteiro de arquivo invalido.\n";
  }
}

// --- 1. A maneira C-style / Manual (propensa a erros) ---
void gerenciamentoManualDeArquivo() {
  std::cout << "--- 1. Gerenciamento Manual de Arquivo ---\n";
  FILE* f = fopen("manual.txt", "w");
  if (!f) {
    std::cout << "  Nao foi possivel abrir o arquivo.\n";
    return; // Saída prematura, mas sem vazamento de recurso aqui.
  }

  escreverEmArquivo(f);

  // O programador DEVE se lembrar de fechar o arquivo.
  // Se uma exceção ocorresse antes desta linha, o arquivo ficaria aberto (vazamento de recurso).
  fclose(f);
  std::cout << "  Arquivo fechado manualmente.\n";
}

// --- 2. A maneira C++ Moderno com Deleter Customizado ---

// Um "deleter" é uma função ou um objeto de função (functor) que sabe como
// liberar um recurso específico. Para um FILE*, a função de liberação é 'fclose'.
// Criamos um tipo alias para o ponteiro para a função 'fclose'.
using FileCloser = decltype(&fclose);

// A função agora recebe um unique_ptr que gerencia o FILE*.
void escreverComSeguranca(std::unique_ptr<FILE, FileCloser>& ptr_arquivo) {
    escreverEmArquivo(ptr_arquivo.get()); // .get() retorna o ponteiro bruto
}

void gerenciamentoComSmartPointer() {
  std::cout << "\n--- 2. Gerenciamento com Smart Pointer e Deleter Customizado ---\n";

  // Criamos o unique_ptr, passando o ponteiro bruto e um ponteiro para a função
  // que deve ser usada para liberá-lo (o deleter).
  std::unique_ptr<FILE, FileCloser> f_ptr(fopen("smart.txt", "w"), &fclose);

  if (!f_ptr) {
    std::cout << "  Nao foi possivel abrir o arquivo.\n";
    return;
  }

  escreverComSeguranca(f_ptr);

  std::cout << "  Saindo da funcao. O unique_ptr ira chamar fclose() automaticamente.\n";
} // O destrutor de 'f_ptr' é chamado aqui. Como fornecemos um deleter customizado,
  // ele chama 'fclose(ponteiro_do_arquivo)' em vez de 'delete ponteiro_do_arquivo'.

int main() {
  gerenciamentoManualDeArquivo();
  gerenciamentoComSmartPointer();
  return 0;
}

/*
  Explicação: Deleters Customizados (Custom Deleters)

  Este exemplo demonstra uma das características mais flexíveis e poderosas dos
  ponteiros inteligentes: a capacidade de fornecer uma lógica de "deleção"
  customizada.

  1.  **O Problema:**
      -   Por padrão, `std::unique_ptr` chama `delete` no ponteiro que ele
          gerencia. `std::shared_ptr` faz o mesmo.
      -   Isso funciona perfeitamente para memória alocada com `new`.
      -   No entanto, muitos recursos não são liberados com `delete`. Por exemplo:
          -   Ponteiros `FILE*` da biblioteca C são liberados com `fclose()`.
          -   Handles de arquivos do sistema operacional são liberados com `CloseHandle()` (Windows) ou `close()` (Linux).
          -   Recursos de bibliotecas de terceiros podem ter funções como `destroy_recurso()`.
      -   Tentar usar um `unique_ptr` padrão com esses recursos resultaria em erro,
          pois `delete` seria chamado em um ponteiro que não foi alocado com `new`.

  2.  **A Solução: Deleter Customizado:**
      -   Os templates de `std::unique_ptr` e `std::shared_ptr` permitem que você
          especifique um segundo parâmetro: o tipo do "Deleter".
      -   Um Deleter pode ser qualquer "callable" (algo que pode ser chamado),
          como um ponteiro para uma função (nosso caso) ou um objeto de função
          (functor).
      -   **`std::unique_ptr<FILE, decltype(&fclose)>`**:
          -   `FILE`: O tipo do recurso que estamos gerenciando.
          -   `decltype(&fclose)`: O tipo do nosso deleter. `decltype` é um
              operador do C++ que extrai o tipo de uma expressão. Aqui, ele
              extrai o tipo de um ponteiro para a função `fclose`.
      -   Ao construir o `unique_ptr`, passamos o recurso bruto (`fopen(...)`) e
          um ponteiro para a função de liberação (`&fclose`).
      -   Agora, quando o `unique_ptr` for destruído, em vez de chamar `delete`,
          ele chamará a função que fornecemos (`fclose`) no ponteiro que ele
          gerencia.

  **Implicações para HFT:**
  -   **RAII para Tudo:** Deleters customizados estendem o poder do RAII para
      qualquer tipo de recurso, não apenas memória. Isso é fundamental para
      escrever código robusto que interage com APIs de baixo nível.
  -   **Interoperabilidade Segura com C:** Sistemas de HFT frequentemente
      interagem com bibliotecas C de alta performance ou diretamente com APIs do
      sistema operacional. Envelopar os handles ou ponteiros retornados por
      essas APIs em ponteiros inteligentes com deleters customizados é a maneira
      padrão de garantir que esses recursos nunca vazem.
  -   **Zero Overhead (com `unique_ptr`):** Se o deleter for um ponteiro para
      função ou um functor sem estado (como no nosso exemplo), o `unique_ptr`
      geralmente não aumenta de tamanho. Ele continua com o mesmo overhead zero
      de um ponteiro bruto, mas com toda a segurança do RAII.
*/