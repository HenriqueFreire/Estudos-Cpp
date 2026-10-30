#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

/*
  =============================================================================
  06. STD::PRIORITY_QUEUE - HEAPS DE MÁXIMO E MÍNIMO
  =============================================================================
  - Implementação interna: Binary Heap (Árvore Binária Completa em Vetor).
  - Por padrão no C++: É um MAX-HEAP (o MAIOR elemento sempre fica no topo).
  - Complexidades:
      * Inserção (push): O(log N)
      * Remoção do topo (pop): O(log N)
      * Consulta do topo (top): O(1)
  
  ⚠️ APLICAÇÃO REI NA MARATONA:
     É a estrutura central do Algoritmo de DIJKSTRA (menor caminho em grafos).
     Para o Dijkstra, usamos o MIN-HEAP (o menor elemento no topo).
  =============================================================================
*/

int main() { _
    cout << "=== 1. MAX-HEAP PADRÃO (MAIOR NO TOPO) ===" << endl;
    priority_queue<int> max_heap;

    max_heap.push(30);
    max_heap.push(100);
    max_heap.push(20);
    max_heap.push(70);

    cout << "Elementos saindo em ordem decrescente:" << endl;
    while (!max_heap.empty()) {
        cout << max_heap.top() << " "; // 100 70 30 20
        max_heap.pop();
    }
    cout << endl;


    cout << "\n=== 2. MIN-HEAP (MENOR NO TOPO - ESSENCIAL PARA DIJKSTRA) ===" << endl;
    // Sintaxe: priority_queue<Tipo, Container, Comparador>
    priority_queue<int, vector<int>, greater<int>> min_heap;

    min_heap.push(30);
    min_heap.push(100);
    min_heap.push(20);
    min_heap.push(70);

    cout << "Elementos saindo em ordem crescente:" << endl;
    while (!min_heap.empty()) {
        cout << min_heap.top() << " "; // 20 30 70 100
        min_heap.pop();
    }
    cout << endl;


    cout << "\n=== 3. MIN-HEAP COM PARES (Estrutura exata do Dijkstra: {distancia, vertice}) ===" << endl;
    // O menor par fica no topo (compara .first primeiro)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila_dijkstra;

    fila_dijkstra.push({15, 3}); // {distancia 15, vertice 3}
    fila_dijkstra.push({5, 1});  // {distancia 5, vertice 1}
    fila_dijkstra.push({20, 2}); // {distancia 20, vertice 2}

    auto [dist, u] = fila_dijkstra.top();
    cout << "Vertice mais proximo: " << u << " com distancia " << dist << endl; // Vertice 1 com dist 5

    return 0;
}
