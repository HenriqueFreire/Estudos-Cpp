#include <iostream>
#include <vector>
#include <algorithm> // sort, reverse, binary_search, min, max
#include <numeric>   // accumulate

using namespace std;

// 1. Função simples com retorno (passagem por valor)
int somar(int a, int b) {
    return a + b;
}

// 2. Função que recebe vetor por REFERÊNCIA CONSTANTE (const &)
// Dica de ouro: evita copiar todo o vetor na memória (muito mais rápido!)
void imprimirVetor(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << "\n";
}

// 3. Função de comparação customizada para a STL (ordem decrescente)
bool compararDecrescente(int a, int b) {
    return a > b; // Retorna true se 'a' deve vir antes de 'b'
}

int main() {
    // Testando função simples
    cout << "--- Função Simples ---\n";
    cout << "Soma de 10 + 20: " << somar(10, 20) << "\n\n";

    vector<int> numeros = {42, 7, 19, 3, 99, 15};

    cout << "--- Vetor Original ---\n";
    imprimirVetor(numeros);

    // 4. STL: std::sort (ordena em ordem crescente)
    cout << "\n--- STL: sort (crescente) ---\n";
    sort(numeros.begin(), numeros.end());
    imprimirVetor(numeros);

    // 5. STL: binary_search (busca binária - requer vetor ordenado)
    cout << "\n--- STL: binary_search ---\n";
    int alvo = 19;
    if (binary_search(numeros.begin(), numeros.end(), alvo)) {
        cout << "O número " << alvo << " existe no vetor!\n";
    } else {
        cout << "O número " << alvo << " NÃO existe no vetor!\n";
    }

    // 6. STL: sort com função customizada (ordem decrescente)
    cout << "\n--- STL: sort com função customizada (decrescente) ---\n";
    sort(numeros.begin(), numeros.end(), compararDecrescente);
    imprimirVetor(numeros);

    // 7. STL: reverse (inverte a ordem dos elementos)
    cout << "\n--- STL: reverse ---\n";
    reverse(numeros.begin(), numeros.end());
    imprimirVetor(numeros);

    // 8. STL: min, max e accumulate
    cout << "\n--- STL: Funções Matemáticas Úteis ---\n";
    cout << "Menor entre 15 e 42: " << min(15, 42) << "\n";
    cout << "Maior entre 15 e 42: " << max(15, 42) << "\n";
    
    // Soma todos os elementos do vetor iniciando do 0
    int somaTotal = accumulate(numeros.begin(), numeros.end(), 0);
    cout << "Soma de todos os elementos: " << somaTotal << "\n";

    return 0;
}
