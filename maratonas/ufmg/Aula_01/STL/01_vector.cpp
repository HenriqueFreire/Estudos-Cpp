#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

/*
  =============================================================================
  01. STD::VECTOR - O ARRAY DINÂMICO DA STL
  =============================================================================
  - O que é: Array de tamanho dinâmico, armazenado em memória contígua (Heap).
  - Por que é rei em CP e Performance:
      1. Excelente Cache Locality (a CPU puxa blocos contínuos para o Cache L1/L2).
      2. Cresce automaticamente dobrando de tamanho quando atinge a capacidade.
  - Complexidades:
      * Acesso por índice: O(1)
      * Inserção/Remoção no final (push_back / pop_back): O(1) amortizado
      * Inserção/Remoção no meio: O(N)
      * Busca linear: O(N)
  =============================================================================
*/

int main() { _
    cout << "=== 1. FORMAS DE INICIALIZAÇÃO ===" << endl;
    
    // a) Vetor vazio
    vector<int> v1;

    // b) Vetor inicializado com 5 posições zeradas: {0, 0, 0, 0, 0} - O(N)
    int n = 5;
    vector<int> v2(n);

    // c) Vetor de tamanho 5 preenchido com valor 42: {42, 42, 42, 42, 42}
    vector<int> v3(n, 42);

    // d) Inicialização direta com lista de elementos (C++11)
    vector<int> v4 = {10, 20, 30, 40, 50};


    cout << "\n=== 2. INSERÇÃO E REMOÇÃO ===" << endl;
    vector<int> v;
    v.push_back(5);   // Insere 5 no final
    v.push_back(10);  // Insere 10 no final
    v.push_back(15);  // Insere 15 no final

    dbg(v.size());    // Tamanho atual = 3
    dbg(v.front());   // Primeiro elemento = 5
    dbg(v.back());    // Último elemento = 15

    v.pop_back();     // Remove o último elemento (15) em O(1)
    dbg(v.size());    // Agora tem 2 elementos


    cout << "\n=== 3. ACESSO E ITERAÇÃO ===" << endl;
    // a) Acesso indexado clássico O(1)
    cout << "Por indice: ";
    for (int i = 0; i < (int)v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    // b) Range-based loop moderno (cópia vs referência)
    cout << "Range-based por referencia: ";
    for (const auto& elemento : v4) { // 'const auto&' evita copiar dados
        cout << elemento << " ";
    }
    cout << endl;


    cout << "\n=== 4. MATRIZES 2D COM VECTOR (Linhas x Colunas) ===" << endl;
    // Matriz de 3 linhas por 4 colunas preenchida com 0
    int linhas = 3, colunas = 4;
    vector<vector<int>> matriz(linhas, vector<int>(colunas, 0));

    matriz[1][2] = 99; // Linha 1, Coluna 2 recebe 99

    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }


    cout << "\n=== 5. OTIMIZAÇÃO: RESERVE VS RESIZE ===" << endl;
    vector<int> otimizado;
    // reserve(1000): Aloca memória para 1000 inteiros sem criar elementos ainda.
    // Evita realocações múltiplas da memória durante push_backs repetidos!
    otimizado.reserve(1000);
    dbg(otimizado.capacity()); // Capacidade alocada = 1000
    dbg(otimizado.size());     // Elementos reais existentes = 0

    return 0;
}
