#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl

/*
  =============================================================================
  04. STD::MAP E STD::UNORDERED_MAP - DICIONÁRIOS CHAVE-VALOR
  =============================================================================
  - std::map<Key, Value>:
      * Baseado em Árvore Rubro-Negra.
      * Chaves sempre ordenadas.
      * Inserção, busca e remoção: O(log N).
  
  - std::unordered_map<Key, Value>:
      * Baseado em Tabela Hash.
      * Sem ordem garantida.
      * Complexidade média: O(1).
      * Pior caso: O(N) devido a colisões de hash.

  ⚠️ CUIDADO NO CODEFORCES (ANTI-HASH TESTS):
     No Codeforces, outros competidores podem hackear soluções que usam 
     unordered_map padrão passando entradas feitas de propósito para gerar 
     colisões na função de hash do GCC, fazendo seu código dar TLE (Time Limit)!
     Para segurança absoluta, use `std::map` ou o `custom_hash` do Neal Wu.
  =============================================================================
*/

// Custom Hash de alta performance anti-hack (famoso template do Neal Wu)
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() { _
    cout << "=== 1. STD::MAP: ORDENADO POR CHAVE (O(log N)) ===" << endl;
    map<string, int> frequencia;

    // Inserção e contagem
    frequencia["banana"] = 3;
    frequencia["maca"] = 10;
    frequencia["abacaxi"] = 5;

    // Iterando pelo map (as chaves aparecem em ordem alfabetica!)
    cout << "Itens ordenados pelas chaves:" << endl;
    for (const auto& [fruta, qtd] : frequencia) {
        cout << fruta << " -> " << qtd << endl;
    }

    // ⚠️ PEGADINHA DO OPERADOR []:
    // Acessar `frequencia["pera"]` CRIA a chave "pera" com valor 0 se ela não existir!
    // Para apenas checar existência sem criar, use .count() ou .find():
    if (frequencia.count("uva") == 0) {
        cout << "\n'uva' nao existe no map (e nao foi criada!)" << endl;
    }


    cout << "\n=== 2. STD::UNORDERED_MAP SEGURO COM CUSTOM HASH (O(1)) ===" << endl;
    // Tabela hash protegida contra hacks do Codeforces
    unordered_map<long long, int, custom_hash> mapa_seguro;

    mapa_seguro[1000000007] = 1;
    mapa_seguro[998244353] = 2;

    cout << "Valor da chave 1000000007: " << mapa_seguro[1000000007] << endl;
    cout << "Tamanho da tabela hash: " << mapa_seguro.size() << endl;

    return 0;
}
