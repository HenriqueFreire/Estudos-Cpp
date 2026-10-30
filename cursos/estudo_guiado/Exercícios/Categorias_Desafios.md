# Categorias e Técnicas Comuns em Desafios de Programação

Entender as diferentes categorias de problemas e as técnicas algorítmicas é crucial para abordar desafios em plataformas como HackerRank, LeetCode e Codeforces.

---

### 1. Categorias de Estruturas de Dados (O "Onde" os dados vivem)

*   **Arrays / Vetores:**
    *   **O que é:** A estrutura de dados mais fundamental. Uma coleção de elementos do mesmo tipo armazenados em posições de memória contíguas. Em C++, `std::vector` é a implementação dinâmica de um array.
    *   **Problemas:** Envolvem manipulação de elementos, busca, ordenação, rotação, encontrar sub-arrays, etc.
    *   **Exemplo:** O problema "Trionic Array" que acabamos de discutir é um problema de Array/Vetor.

*   **Strings:**
    *   **O que é:** Uma sequência de caracteres. Em C++, `std::string` é a classe padrão.
    *   **Problemas:** Manipulação de texto, busca de padrões, palíndromos, anagramas, compressão, etc.

*   **Hash Tables / Maps (Hash Maps):**
    *   **O que é:** Estruturas de dados que mapeiam chaves para valores usando uma função hash para acesso muito rápido (O(1) em média). Em C++, `std::unordered_map` e `std::unordered_set`.
    *   **Problemas:** Contagem de frequência, verificação de existência, problemas "Two Sum".

*   **Linked Lists (Listas Encadeadas):**
    *   **O que é:** Uma sequência de nós, onde cada nó contém um valor e um ponteiro para o próximo nó. Em C++, `std::list` (duplamente encadeada) ou `std::forward_list` (simplesmente encadeada).
    *   **Problemas:** Inserção/remoção eficiente no meio, inversão de lista, detecção de ciclos.

*   **Trees (Árvores):**
    *   **O que é:** Estruturas de dados hierárquicas. Incluem árvores binárias, árvores de busca binária (BSTs), árvores balanceadas (AVL, Red-Black Trees - como o `std::map` e `std::set` são implementados).
    *   **Problemas:** Busca, inserção, remoção, travessias (inorder, preorder, postorder), encontrar ancestrais comuns.

*   **Graphs (Grafos):**
    *   **O que é:** Uma coleção de nós (vértices) e arestas que os conectam.
    *   **Problemas:** Caminho mais curto (Dijkstra, BFS), conectividade, detecção de ciclos, fluxo máximo.

---

### 2. Técnicas Algorítmicas (O "Como" resolver o problema)

*   **Two Pointers (Dois Ponteiros):**
    *   **O que é:** Uma técnica onde dois ponteiros (índices) percorrem uma estrutura de dados (geralmente um array ou lista), muitas vezes de extremidades opostas ou em velocidades diferentes.
    *   **Quando usar:** Para problemas que envolvem encontrar pares, sub-arrays, ou manipular elementos em um array ordenado.
    *   **Exemplo:** Encontrar um par que soma um `target` em um array ordenado, remover duplicatas de um array ordenado.

*   **Greedy (Guloso):**
    *   **O que é:** Um paradigma algorítmico que faz a escolha localmente ótima em cada etapa, na esperança de que essa escolha leve a uma solução globalmente ótima.
    *   **Quando usar:** Para problemas onde a escolha atual não afeta negativamente as escolhas futuras para a solução ótima. É preciso provar que a estratégia gulosa funciona.
    *   **Exemplo:** Problema da troca de moedas (com moedas padrão), agendamento de tarefas.

*   **Binary Search (Busca Binária):**
    *   **O que é:** Um algoritmo eficiente para encontrar um item em uma lista **ordenada**, dividindo repetidamente o intervalo de busca pela metade.
    *   **Complexidade:** `O(log N)`.
    *   **Quando usar:** Sempre que você tiver uma lista ordenada e precisar encontrar um elemento ou um ponto de corte.

*   **Recursion (Recursão) / Backtracking:**
    *   **O que é:** Recursão é quando uma função chama a si mesma. Backtracking é uma forma de recursão usada para explorar todas as soluções possíveis para um problema, voltando atrás (backtracking) quando um caminho não leva a uma solução válida.
    *   **Quando usar:** Travessias de árvores/grafos, permutações, combinações, problemas de quebra-cabeça (ex: N-Queens, Sudoku).

*   **Dynamic Programming (Programação Dinâmica - DP):**
    *   **O que é:** Uma técnica para resolver problemas complexos dividindo-os em subproblemas menores e sobrepostos, e armazenando os resultados desses subproblemas para evitar recálculos.
    *   **Quando usar:** Problemas de otimização que exibem "subproblemas sobrepostos" e "estrutura ótima".
    *   **Exemplo:** Problema da mochila, sequência de Fibonacci, caminho mais curto em grafos sem ciclos.

*   **Sliding Window (Janela Deslizante):**
    *   **O que é:** Uma técnica para resolver problemas em arrays ou strings que envolvem sub-arrays ou substrings de um tamanho específico ou variável. Uma "janela" de elementos "desliza" sobre a sequência.
    *   **Quando usar:** Encontrar o maior/menor sub-array com uma certa propriedade, problemas de substring.
