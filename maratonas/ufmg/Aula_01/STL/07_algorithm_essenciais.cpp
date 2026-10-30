#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

/*
  =============================================================================
  07. <ALGORITHM> - AS FUNÇÕES MÁGICAS DA STL
  =============================================================================
  A biblioteca <algorithm> resolve grande parte das tarefas repetitivas em CP:
  - Ordenação e inversão.
  - Busca binária (lower_bound, upper_bound, binary_search).
  - Remoção de duplicatas (std::unique + erase).
  - Permutações completas (next_permutation).
  =============================================================================
*/

int main() { _
    cout << "=== 1. REMOÇÃO DE DUPLICATAS (ORDENAÇÃO + UNIQUE + ERASE) ===" << endl;
    vector<int> v = {4, 1, 2, 1, 4, 3, 2, 4};

    // Passo 1: Ordenar
    sort(v.begin(), v.end()); // {1, 1, 2, 2, 3, 4, 4, 4}

    // Passo 2: std::unique coloca os elementos únicos no início e retorna o novo final
    // Passo 3: erase remove a sobra no fim
    v.erase(unique(v.begin(), v.end()), v.end());

    cout << "Vetor sem duplicatas: ";
    for (int x : v) cout << x << " "; // 1 2 3 4
    cout << endl;


    cout << "\n=== 2. BUSCA BINÁRIA EM VETOR ORDENADO ===" << endl;
    vector<int> arr = {10, 20, 30, 30, 30, 40, 50};

    // lower_bound: primeiro elemento >= 30
    auto it1 = lower_bound(arr.begin(), arr.end(), 30);
    // upper_bound: primeiro elemento > 30
    auto it2 = upper_bound(arr.begin(), arr.end(), 30);

    // Dica de ouro: Subtrair arr.begin() dá o ÍNDICE exato (0-based) em O(1)!
    int idx_lower = it1 - arr.begin();
    int idx_upper = it2 - arr.begin();

    cout << "Indice do primeiro >= 30: " << idx_lower << " (valor: " << *it1 << ")" << endl;
    cout << "Indice do primeiro > 30: " << idx_upper << " (valor: " << *it2 << ")" << endl;
    cout << "Quantidade de vezes que o 30 aparece: " << (idx_upper - idx_lower) << endl;


    cout << "\n=== 3. GERANDO TODAS AS PERMUTAÇÕES (NEXT_PERMUTATION) ===" << endl;
    // Muito útil para problemas de força bruta (N <= 10)
    vector<int> perm = {1, 2, 3};

    cout << "Todas as permutacoes de {1, 2, 3}:" << endl;
    do {
        cout << perm[0] << " " << perm[1] << " " << perm[2] << endl;
    } while (next_permutation(perm.begin(), perm.end()));


    cout << "\n=== 4. MÁXIMO E MÍNIMO ===" << endl;
    vector<int> dados = {15, 89, 42, 7, 63};
    auto it_max = max_element(dados.begin(), dados.end());
    auto it_min = min_element(dados.begin(), dados.end());

    cout << "Maior valor: " << *it_max << " no indice " << (it_max - dados.begin()) << endl;
    cout << "Menor valor: " << *it_min << " no indice " << (it_min - dados.begin()) << endl;

    return 0;
}
