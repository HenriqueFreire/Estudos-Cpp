# 📚 Guia Definitivo da STL para Maratonas (UFMG - Aula 01)

Esta pasta contém exemplos práticos, detalhados e prontos para compilar de cada recurso fundamental da **Standard Template Library (STL)** do C++.

Todos os códigos utilizam o template da Maratona UFMG com I/O rápido (`#define _ ios_base::sync_with_stdio(0);cin.tie(0);`).

---

## 📂 Arquivos Disponíveis

| Arquivo | Tópicos Principais | Complexidade Chave |
| :--- | :--- | :---: |
| **[`01_vector.cpp`](file:///home/henrique/Maratonas/UFMG/Aula_01/STL/01_vector.cpp)** | Arrays dinâmicos, `push_back`, `pop_back`, matrizes 2D/3D, `reserve` vs `resize`. | $O(1)$ acesso / $O(1)$ amortizado no fim |
| **[`02_pair_e_tuple.cpp`](file:///home/henrique/Maratonas/UFMG/Aula_01/STL/02_pair_e_tuple.cpp)** | Agrupamento de dados, ordenação natural de pares, *Structured Bindings* (C++17). | $O(1)$ criação / $O(N \log N)$ ordenação |
| **[`03_set_e_multiset.cpp`](file:///home/henrique/Maratonas/UFMG/Aula_01/STL/03_set_e_multiset.cpp)** | Árvores rubro-negras, ordenação automática, valores únicos vs duplicados, `lower_bound`. | $O(\log N)$ inserção / busca |
| **[`04_map_e_unordered_map.cpp`](file:///home/henrique/Maratonas/UFMG/Aula_01/STL/04_map_e_unordered_map.cpp)** | Dicionários chave-valor, `std::map` vs `unordered_map`, Custom Hash anti-hack do Neal Wu. | $O(\log N)$ no map / $O(1)$ médio no unordered |
| **[`05_stack_queue_deque.cpp`](file:///home/henrique/Maratonas/UFMG/Aula_01/STL/05_stack_queue_deque.cpp)** | Pilha (LIFO), Fila (FIFO), Fila Dupla (Deque), base para BFS e DFS. | $O(1)$ nas pontas |
| **[`06_priority_queue.cpp`](file:///home/henrique/Maratonas/UFMG/Aula_01/STL/06_priority_queue.cpp)** | Max-Heap, Min-Heap (`greater<T>`), base do Algoritmo de Dijkstra. | $O(\log N)$ inserção / $O(1)$ consulta do topo |
| **[`07_algorithm_essenciais.cpp`](file:///home/henrique/Maratonas/UFMG/Aula_01/STL/07_algorithm_essenciais.cpp)** | `sort`, `unique` + `erase` (compressão de coordenadas), `next_permutation`, `max_element`. | $O(N \log N)$ sort / $O(N)$ unique |
| **[`08_bitset.cpp`](file:///home/henrique/Maratonas/UFMG/Aula_01/STL/08_bitset.cpp)** | Vetor de bits, operações de 64 bits por ciclo de clock, otimização $O(N / 64)$. | $O(1)$ por bloco de 64 bits |

---

## 🛠️ Como Compilar e Rodar no NixOS

No terminal, dentro desta pasta:

```bash
# Abrir ambiente temporário com g++
nix-shell -p gcc

# Compilar qualquer um dos arquivos com C++20
g++ -std=c++20 -O2 01_vector.cpp -o prog
./prog
```
