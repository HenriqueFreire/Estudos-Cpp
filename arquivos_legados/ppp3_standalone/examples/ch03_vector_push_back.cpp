#include <iostream>
#include <vector>

// Programming: Principles and Practice Using C++ (3rd Edition)
// Chapter 3: Computation
// Section 3.6.2: Growing a vector (Page 73)
//
// Demonstrates growing a vector using push_back()
// both with explicit values and dynamically from user input.

int main()
{
    // 1. Iniciando vazio e expandindo com push_back()
    std::vector<double> v; // começa vazio; sem nenhum elemento

    v.push_back(2.7);
    v.push_back(5.6);
    v.push_back(7.9);

    std::cout << "Valores adicionados manualmente a v (tamanho: " << v.size() << "):\n";
    for (double x : v) {
        std::cout << x << '\n';
    }

    // 2. Lendo valores dinamicamente a partir da entrada padrão (cin)
    std::cout << "\nDigite temperaturas/numeros (digite '|' ou caractere nao numerico para encerrar):\n";
    std::vector<double> temps;

    for (double temp; std::cin >> temp; ) {
        temps.push_back(temp); // insere cada valor no final do vetor
    }

    std::cout << "\nVoce digitou " << temps.size() << " valores:\n";
    for (double t : temps) {
        std::cout << t << '\n';
    }

    return 0;
}
