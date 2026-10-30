#include <iostream>
#include <vector>
#include <algorithm>

// Programming: Principles and Practice Using C++ (3rd Edition)
// Chapter 3: Computation
// Section 3.6.3: A numeric example (Pages 74-76)
//
// Lê temperaturas via cin, compara o padrão while vs for,
// e calcula a temperatura média e a mediana com std::ranges::sort.

int main()
{
    // -------------------------------------------------------------------------
    // 1. Leitura Idiomática com loop 'for' (versus 'while')
    // -------------------------------------------------------------------------
    // Em vez de 'double temp; while (cin >> temp)', o Stroustrup recomenda
    // declarar 'temp' diretamente no cabeçalho do 'for' para isolar seu escopo:
    std::vector<double> temps;

    std::cout << "Digite as temperaturas (digite '|' para encerrar):\n";
    for (double temp; std::cin >> temp; ) {
        temps.push_back(temp);
    }

    // Guarda defensiva: previne divisão por zero caso nenhum número seja digitado
    if (temps.empty()) {
        std::cout << "Nenhuma temperatura foi informada.\n";
        return 0;
    }

    // -------------------------------------------------------------------------
    // 2. Temperatura Média
    // -------------------------------------------------------------------------
    double sum = 0.0;
    for (double x : temps) {
        sum += x;
    }
    std::cout << "Temperatura media: " << (sum / temps.size()) << '\n';

    // -------------------------------------------------------------------------
    // 3. Mediana com std::ranges::sort (C++20 / C++23)
    // -------------------------------------------------------------------------
    std::ranges::sort(temps); // ordena os elementos em ordem crescente
    std::cout << "Temperatura mediana: " << temps[temps.size() / 2] << '\n';

    return 0;
}
