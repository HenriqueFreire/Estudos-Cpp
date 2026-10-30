#include <iostream>

// Programming: Principles and Practice Using C++ (3rd Edition)
// Chapter 3: Computation
// Section 3.4.1.3: Selection (Try this - switch-statements)
//
// Converts foreign currencies into US dollars using a switch statement.
// Suffix indicates the currency:
// 'y' (yen), 'e' (euros), 'p' (pounds), 'u' (yuan), 'k' (kroner)

int main()
{
    // Taxas de conversão aproximadas para Dólar (USD)
    constexpr double dollars_per_yen = 0.0067;   // 1 Iene   ~ 0.0067 USD
    constexpr double dollars_per_euro = 1.09;    // 1 Euro   ~ 1.09 USD
    constexpr double dollars_per_pound = 1.31;   // 1 Libra  ~ 1.31 USD
    constexpr double dollars_per_yuan = 0.14;    // 1 Yuan   ~ 0.14 USD
    constexpr double dollars_per_krone = 0.095;  // 1 Coroa  ~ 0.095 USD

    double amount = 0.0;
    char currency = ' ';

    std::cout << "Please enter an amount followed by a currency (y, e, p, u, or k):\n";
    std::cin >> amount >> currency;

    switch (currency) {
    case 'y':
        std::cout << amount << " yen == $" << amount * dollars_per_yen << " USD\n";
        break;
    case 'e':
        std::cout << amount << " euros == $" << amount * dollars_per_euro << " USD\n";
        break;
    case 'p':
        std::cout << amount << " pounds == $" << amount * dollars_per_pound << " USD\n";
        break;
    case 'u':
        std::cout << amount << " yuan == $" << amount * dollars_per_yuan << " USD\n";
        break;
    case 'k':
        std::cout << amount << " kroner == $" << amount * dollars_per_krone << " USD\n";
        break;
    default:
        std::cout << "Sorry, I don't know a currency called '" << currency << "'\n";
        break;
    }

    return 0;
}
