#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

/*
  =============================================================================
  02. STD::PAIR E STD::TUPLE - AGRUPAMENTO DE DADOS HETEROGÊNEOS
  =============================================================================
  - std::pair<T1, T2>: Agrupa exatamente 2 valores (muito usado em coordenadas,
    arestas de grafos com peso {peso, vizinho}, etc.).
  - std::tuple<T1, T2, T3...>: Generalização do pair para 3 ou mais valores.
  
  - Super Poder na Maratona:
      std::pair tem OPERADOR DE COMPARAÇÃO (<) NATIVO!
      Ele compara o `.first` primeiro. Se forem iguais, compara o `.second`.
      Isso significa que você pode ordenar um vector<pair<int, int>> diretamente!
  =============================================================================
*/

int main() { _
    cout << "=== 1. STD::PAIR: CRIAÇÃO E ACESSO ===" << endl;
    
    // a) Criação direta com chaves {} (C++11)
    pair<int, string> aluno = {101, "Henrique"};

    // b) Acesso clássico via .first e .second
    cout << "Matricula: " << aluno.first << ", Nome: " << aluno.second << endl;

    // c) Usando os macros da UFMG (#define f first / #define s second)
    cout << "Com macros UFMG -> f: " << aluno.f << ", s: " << aluno.s << endl;

    // d) Desempacotamento Moderno (Structured Bindings - C++17)
    auto [id, nome] = aluno;
    cout << "Structured binding -> id: " << id << ", nome: " << nome << endl;


    cout << "\n=== 2. ORDENAÇÃO NATURAL DE PARES (Muito usado em CP) ===" << endl;
    // Lista de {altura, peso}
    vector<pair<int, int>> pessoas = {
        {180, 80},
        {175, 70},
        {180, 75}, // Mesma altura que o primeiro, mas menor peso
        {165, 60}
    };

    // Ordena automaticamente pelo .first, desempatando pelo .second
    sort(pessoas.begin(), pessoas.end());

    cout << "Pessoas ordenadas por altura (e desempate por peso):" << endl;
    for (auto [alt, pes] : pessoas) {
        cout << "(" << alt << "cm, " << pes << "kg) ";
    }
    cout << endl;


    cout << "\n=== 3. STD::TUPLE (3 OU MAIS VALORES) ===" << endl;
    // Exemplo: {peso da aresta, vertice_origem, vertice_destino}
    tuple<int, int, int> aresta = {15, 1, 4};

    // a) Acesso com get<indice>
    cout << "Peso: " << get<0>(aresta) 
         << ", De: " << get<1>(aresta) 
         << " -> Para: " << get<2>(aresta) << endl;

    // b) Desempacotamento moderno com auto [x, y, z]
    auto [peso, u, v] = aresta;
    cout << "Via Structured Binding: " << peso << " conecta " << u << " e " << v << endl;

    return 0;
}
