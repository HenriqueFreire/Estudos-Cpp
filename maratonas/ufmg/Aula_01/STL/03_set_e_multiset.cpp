#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl

/*
  =============================================================================
  03. STD::SET E STD::MULTISET - CONJUNTOS ORDENADOS
  =============================================================================
  - Implementação interna: Árvore Rubro-Negra (Árvore Binária de Busca Balanceada).
  - Características do set:
      1. Mantém os elementos SEMPRE ORDENADOS em ordem crescente.
      2. Não permite elementos duplicados (armazena apenas valores únicos).
  - Complexidades:
      * Inserção (insert): O(log N)
      * Remoção (erase): O(log N)
      * Busca (find / count): O(log N)
  
  ⚠️ AVISO DE OURO DE PERFORMANCE (UFMG / CP):
     SEMPRE use o método membro `s.lower_bound(x)` e NUNCA `lower_bound(s.begin(), s.end(), x)`.
     O método membro é O(log N), enquanto o algoritmo genérico em set é O(N)!
  =============================================================================
*/

int main() { _
    cout << "=== 1. STD::SET: ELEMENTOS ÚNICOS E ORDENADOS ===" << endl;
    set<int> s;

    // Inserindo elementos fora de ordem e repetidos
    s.insert(50);
    s.insert(10);
    s.insert(30);
    s.insert(10); // Duplicado: será ignorado!

    cout << "Elementos no set (automaticamente ordenados e sem duplicatas):" << endl;
    for (int x : s) {
        cout << x << " "; // Saída: 10 30 50
    }
    cout << endl;

    // Verificando existência em O(log N)
    if (s.count(30)) {
        cout << "O elemento 30 existe no set!" << endl;
    }

    // Remoção em O(log N)
    s.erase(30);
    cout << "Apos remover o 30, tamanho do set: " << s.size() << endl;


    cout << "\n=== 2. BUSCAS LOGARÍTMICAS (lower_bound e upper_bound) ===" << endl;
    set<int> numeros = {10, 20, 30, 40, 50};

    // lower_bound(x): primeiro elemento >= x
    auto it_lower = numeros.lower_bound(25);
    cout << "lower_bound(25) [primeiro >= 25]: " << *it_lower << endl; // 30

    // upper_bound(x): primeiro elemento estritamente > x
    auto it_upper = numeros.upper_bound(30);
    cout << "upper_bound(30) [primeiro > 30]: " << *it_upper << endl;   // 40


    cout << "\n=== 3. STD::MULTISET: PERMITE ELEMENTOS DUPLICADOS ===" << endl;
    multiset<int> ms;
    ms.insert(5);
    ms.insert(5);
    ms.insert(5);
    ms.insert(2);

    cout << "Elementos no multiset: ";
    for (int x : ms) cout << x << " "; // 2 5 5 5
    cout << endl;

    // ⚠️ PEGADINHA CLÁSSICA DE MARATONA:
    // ms.erase(5) remove TODAS as cópias de 5!
    // Para remover APENAS UMA CÓPIA de 5, passe o iterator via find:
    ms.erase(ms.find(5)); // Remove só um '5'

    cout << "Apos remover apenas um '5': ";
    for (int x : ms) cout << x << " "; // 2 5 5
    cout << endl;

    return 0;
}
