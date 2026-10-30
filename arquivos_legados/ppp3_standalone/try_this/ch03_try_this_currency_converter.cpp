#include <iostream>

// Programming: Principles and Practice Using C++ (3rd Edition)
// Chapter 3: Computation
// Section 3.4.1.1: Selection (Try this - Page 62)
//
// Converts yen, euros, and pounds into US dollars.
// Suffix 'y' (yen), 'e' (euros), or 'p' (pounds) indicates the currency.

int main()
{
    // Conversion rates to US Dollars (approximate values)
    constexpr double dollars_per_yen = 0.0067;   // 1 Yen ~ 0.0067 USD
    constexpr double dollars_per_euro = 1.09;    // 1 Euro ~ 1.09 USD
    constexpr double dollars_per_pound = 1.31;   // 1 British Pound ~ 1.31 USD

    double amount = 0.0;
    char currency = ' ';

    std::cout << "Please enter an amount followed by a currency (y, e, or p):\n";
    std::cin >> amount >> currency;

    if (currency == 'y')
        std::cout << amount << " yen == $" << amount * dollars_per_yen << " USD\n";
    else if (currency == 'e')
        std::cout << amount << " euros == $" << amount * dollars_per_euro << " USD\n";
    else if (currency == 'p')
        std::cout << amount << " pounds == $" << amount * dollars_per_pound << " USD\n";
    else
        std::cout << "Sorry, I don't know a currency called '" << currency << "'\n";

    return 0;
}
