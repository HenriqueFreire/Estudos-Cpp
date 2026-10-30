#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

/*
  =============================================================================
  08. STD::BITSET - O ACELERADOR DE 64x POR ESCOVAÇÃO DE BITS
  =============================================================================
  - O que é: Array de bits de tamanho FIXO definido em tempo de compilação.
  - Consumo de memória: Apenas 1 bit por posição (8x menos que bool).
  
  🚀 O SUPER-PODER DE PERFORMANCE EM MARATONA:
     As operações lógicas (&, |, ^, <<, >>) operam 64 BITS POR INSTRUÇÃO DE CLOCK!
     Isso significa que uma solução O(N^2) pode virar O(N^2 / 64).
     Um algoritmo que levaria 3 segundos (TLE) roda em 0.05 segundos!
  =============================================================================
*/

int main() { _
    cout << "=== 1. CRIAÇÃO E OPERAÇÕES BÁSICAS ===" << endl;
    const int N = 8;
    bitset<N> b1("10110010"); // Inicialização a partir de string binária
    bitset<N> b2(15);         // 15 em binário = 00001111

    cout << "b1: " << b1 << endl;
    cout << "b2: " << b2 << endl;

    // Métodos úteis
    cout << "Quantidade de bits '1' em b1 (.count()): " << b1.count() << endl; // 4
    cout << "O bit na posicao 1 esta ativo? (.test(1)): " << b1.test(1) << endl;

    b1.set(0);   // Liga o bit 0 (vira 1)
    b1.reset(1); // Desliga o bit 1 (vira 0)
    b1.flip(2);  // Inverte o bit 2 (0 vira 1, 1 vira 0)
    cout << "b1 apos modificacoes: " << b1 << endl;


    cout << "\n=== 2. OPERAÇÕES BIT A BIT EM LOTE (64 BITS POR VEZ) ===" << endl;
    bitset<N> mask_and = b1 & b2;
    bitset<N> mask_or  = b1 | b2;
    bitset<N> mask_xor = b1 ^ b2;

    cout << "b1 & b2: " << mask_and << endl;
    cout << "b1 | b2: " << mask_or  << endl;
    cout << "b1 ^ b2: " << mask_xor << endl;


    cout << "\n=== 3. APLICAÇÃO CLÁSSICA: SUBSET SUM / MOCHILA ULTRA-RÁPIDA ===" << endl;
    // Descobrir se é possível formar uma soma 'S' usando elementos de um vetor
    // Com bitset, o knapsack 0/1 roda em O(N * S / 64)!
    const int MAX_SOMA = 100;
    bitset<MAX_SOMA> alcancavel;
    alcancavel[0] = 1; // A soma 0 sempre é possível

    vector<int> moedas = {3, 7, 12};
    for (int moeda : moedas) {
        alcancavel |= (alcancavel << moeda); // Atualiza todas as somas possíveis de uma só vez!
    }

    cout << "A soma 15 e possivel com as moedas {3, 7, 12}? " 
         << (alcancavel[15] ? "SIM!" : "NAO!") << endl; // 3 + 12 = 15 -> SIM
    cout << "A soma 11 e possivel? " 
         << (alcancavel[11] ? "SIM!" : "NAO!") << endl; // NAO

    return 0;
}
