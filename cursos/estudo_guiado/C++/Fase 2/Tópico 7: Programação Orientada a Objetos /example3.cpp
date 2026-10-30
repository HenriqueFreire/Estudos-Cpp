#include <iostream>
#include <string>
#include <algorithm> // Para std::copy

// ATENÇÃO: Este exemplo contém um bug deliberado para fins de aprendizado.
// Ele demonstra o problema que a "Regra dos Três" resolve.

class BufferSimples {
public:
  // Construtor: aloca um recurso (memória no Heap).
  BufferSimples(size_t tamanho) : tamanho_(tamanho), dados_(new int[tamanho]) {
    std::cout << "  [+] BufferSimples(" << tamanho_
              << ") alocado no endereco " << dados_ << " (Construtor)\n";
  }

  // Destrutor: libera o recurso.
  ~BufferSimples() {
    std::cout << "  [-] BufferSimples(" << tamanho_
              << ") no endereco " << dados_ << " sendo liberado (Destrutor)\n";
    delete[] dados_;
  }

  void imprimir() const {
    std::cout << "      Buffer no endereco " << dados_ << " | Tamanho: " << tamanho_ << '\n';
  }

private:
  size_t tamanho_;
  int* dados_; // Ponteiro para o recurso gerenciado.
};

int main() {
  std::cout << "Iniciando o programa.\n\n";

  BufferSimples buffer_original(10);
  buffer_original.imprimir();

  std::cout << "\nAgora, vamos criar uma copia do buffer...\n";

  // Aqui, o compilador usa o "construtor de cópia" padrão.
  // Este construtor padrão faz uma "cópia superficial" (shallow copy):
  // ele apenas copia o valor do ponteiro 'dados_', não a memória para a qual ele aponta.
  BufferSimples buffer_copia = buffer_original;

  std::cout << "Apos a copia:\n";
  buffer_original.imprimir(); // Aponta para o mesmo endereço...
  buffer_copia.imprimir();    // ...que a cópia.

  std::cout << "\nFim do escopo 'main'. Os destrutores serao chamados...\n";
  // O programa provavelmente irá travar (crash) aqui.
  return 0;
}

// 1. O destrutor de 'buffer_copia' é chamado. Ele libera a memória.
// 2. O destrutor de 'buffer_original' é chamado. Ele tenta liberar A MESMA memória novamente.
// Isso é um erro de "double free" e causa comportamento indefinido (geralmente um crash).

/*
  Explicação: O Problema da Cópia Superficial e a "Regra dos Três"

  Este exemplo demonstra por que classes que gerenciam recursos brutos (como
  memória alocada com `new`, arquivos, sockets, etc.) não podem depender das
  funções padrão geradas pelo compilador para cópia e atribuição.

  1.  **Funções Especiais Geradas pelo Compilador:**
      -   Se você não definir suas próprias funções de cópia, o compilador C++
          gera algumas para você, incluindo um **construtor de cópia** e um
          **operador de atribuição por cópia**.
      -   Por padrão, essas funções realizam uma "cópia superficial" (shallow
          copy), o que significa que elas copiam os membros da classe bit a bit.

  2.  **O Problema da Cópia Superficial:**
      -   Quando `BufferSimples buffer_copia = buffer_original;` é executado,
          o construtor de cópia padrão simplesmente copia o valor do ponteiro
          `dados_` de `buffer_original` para `buffer_copia.dados_`.
      -   Agora, ambos os objetos apontam para o **mesmo bloco de memória** no Heap.
      -   Quando o primeiro objeto (`buffer_copia`) sai do escopo, seu destrutor
          é chamado e a memória é liberada com `delete[]`.
      -   Quando o segundo objeto (`buffer_original`) sai do escopo, seu
          destrutor tenta liberar a **mesma memória que já foi liberada**. Isso
          é um erro grave conhecido como **double free**, que corrompe o estado
          do Heap e geralmente causa um crash no programa.

  3.  **A Regra dos Três (The Rule of Three):**
      -   É uma regra prática em C++ (pré-C++11) que afirma: se uma classe
          precisa de um dos seguintes itens definidos explicitamente...
          1.  Destrutor
          2.  Construtor de Cópia
          3.  Operador de Atribuição por Cópia (`operator=`)
      -   ...então ela provavelmente precisa de **todos os três**.
      -   Nossa classe `BufferSimples` tem um destrutor para liberar a memória,
          portanto, de acordo com a regra, ela também precisa de um construtor
          de cópia e de um operador de atribuição por cópia personalizados para
          lidar com a cópia de forma correta (fazendo uma "cópia profunda").

  **Cópia Profunda (Deep Copy):**
  -   A solução para este problema é implementar um construtor de cópia que
      realize uma "cópia profunda". Em vez de apenas copiar o ponteiro, ele
      deve alocar um **novo** bloco de memória para o objeto copiado e, em
      seguida, copiar o **conteúdo** do buffer original para este novo bloco.
      Dessa forma, cada objeto gerencia seu próprio recurso de forma independente.

  O próximo exemplo (`example4.cpp`) mostrará como implementar corretamente a
  "Regra dos Três" para consertar o bug de `double free`.
*/