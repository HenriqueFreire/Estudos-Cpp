#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

/*
  =============================================================================
  05. STACK, QUEUE E DEQUE - FILAS E PILHAS
  =============================================================================
  - std::stack (Pilha - LIFO: Last In, First Out):
      * O último que entra é o primeiro que sai.
      * Operações: push(), pop(), top() em O(1).
      * Aplicações: Casamento de parênteses, Pilha Monotônica, DFS manual.
  
  - std::queue (Fila - FIFO: First In, First Out):
      * O primeiro que entra é o primeiro que sai.
      * Operações: push(), pop(), front() em O(1).
      * Aplicações: BFS (Busca em Largura em Grafos e Grids).

  - std::deque (Double-Ended Queue - Fila de Duas Pontas):
      * Permite inserção e remoção no INÍCIO e no FIM em O(1)!
      * Permite acesso por índice `dq[i]` em O(1).
      * Aplicações: Algoritmo de Sliding Window Maximum e BFS 0-1.
  =============================================================================
*/

int main() { _
    cout << "=== 1. STD::STACK (PILHA - LIFO) ===" << endl;
    stack<int> pilha;
    pilha.push(10);
    pilha.push(20);
    pilha.push(30);

    cout << "Topo da pilha: " << pilha.top() << endl; // 30
    pilha.pop(); // Remove o 30
    cout << "Novo topo apos pop(): " << pilha.top() << endl; // 20


    cout << "\n=== 2. STD::QUEUE (FILA - FIFO) ===" << endl;
    queue<string> fila;
    fila.push("Ana");
    fila.push("Bruno");
    fila.push("Carlos");

    cout << "Primeiro da fila: " << fila.front() << endl; // Ana
    fila.pop(); // Ana é atendida e sai da fila
    cout << "Proximo a ser atendido: " << fila.front() << endl; // Bruno


    cout << "\n=== 3. STD::DEQUE (FILA DUPLA) ===" << endl;
    deque<int> dq;
    dq.push_back(10);   // {10}
    dq.push_back(20);   // {10, 20}
    dq.push_front(5);   // {5, 10, 20}  (Inserção no início em O(1)!)
    dq.push_front(1);   // {1, 5, 10, 20}

    cout << "Elemento na frente: " << dq.front() << endl; // 1
    cout << "Elemento no fundo: " << dq.back() << endl;    // 20
    cout << "Acesso direto por indice dq[2]: " << dq[2] << endl; // 10

    dq.pop_front(); // Remove 1
    dq.pop_back();  // Remove 20

    cout << "Deque apos remocoes nas duas pontas: ";
    for (int x : dq) cout << x << " "; // 5 10
    cout << endl;

    return 0;
}
