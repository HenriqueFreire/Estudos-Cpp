#include <iostream>

/**
 * Programming: Principles and Practice Using C++ (3rd Edition) - Bjarne Stroustrup
 * Chapter 2: Objects, Types, and Values
 * Exercise 11: Coin Counter and Currency Formatter
 *
 * Prompts for the number of:
 *   - pennies (1 cent)
 *   - nickels (5 cents)
 *   - dimes (10 cents)
 *   - quarters (25 cents)
 *   - half dollars (50 cents)
 *   - one-dollar coins (100 cents)
 *
 * Features:
 *   - Grammatically correct singular/plural forms ("1 penny" vs "2 pennies", "1 dime" vs "2 dimes", etc.)
 *   - Total sum reported in cents and in dollars ($X.XX)
 *   - Uses exact integer fixed-point arithmetic to avoid floating-point rounding errors on money!
 */

int main() {
    int pennies = 0;
    int nickels = 0;
    int dimes = 0;
    int quarters = 0;
    int half_dollars = 0;
    int one_dollar_coins = 0;

    std::cout << "How many pennies do you have? ";
    std::cin >> pennies;

    std::cout << "How many nickels do you have? ";
    std::cin >> nickels;

    std::cout << "How many dimes do you have? ";
    std::cin >> dimes;

    std::cout << "How many quarters do you have? ";
    std::cin >> quarters;

    std::cout << "How many half dollars do you have? ";
    std::cin >> half_dollars;

    std::cout << "How many one-dollar coins do you have? ";
    std::cin >> one_dollar_coins;

    std::cout << "\n----------------------------------------\n";

    // Grammatically correct reporting for each coin type
    if (pennies == 1) {
        std::cout << "You have 1 penny.\n";
    } else {
        std::cout << "You have " << pennies << " pennies.\n";
    }

    if (nickels == 1) {
        std::cout << "You have 1 nickel.\n";
    } else {
        std::cout << "You have " << nickels << " nickels.\n";
    }

    if (dimes == 1) {
        std::cout << "You have 1 dime.\n";
    } else {
        std::cout << "You have " << dimes << " dimes.\n";
    }

    if (quarters == 1) {
        std::cout << "You have 1 quarter.\n";
    } else {
        std::cout << "You have " << quarters << " quarters.\n";
    }

    if (half_dollars == 1) {
        std::cout << "You have 1 half dollar.\n";
    } else {
        std::cout << "You have " << half_dollars << " half dollars.\n";
    }

    if (one_dollar_coins == 1) {
        std::cout << "You have 1 one-dollar coin.\n";
    } else {
        std::cout << "You have " << one_dollar_coins << " one-dollar coins.\n";
    }

    // Exact integer calculation (no floating-point rounding bugs)
    int total_cents = pennies * 1 +
                      nickels * 5 +
                      dimes * 10 +
                      quarters * 25 +
                      half_dollars * 50 +
                      one_dollar_coins * 100;

    std::cout << "----------------------------------------\n";
    if (total_cents == 1) {
        std::cout << "The value of all of your coins is 1 cent.\n";
    } else {
        std::cout << "The value of all of your coins is " << total_cents << " cents.\n";
    }

    // Formatting in dollars ($X.XX) using integer division and modulo
    int dollars = total_cents / 100;
    int remaining_cents = total_cents % 100;

    std::cout << "The total in dollars is: $" << dollars << '.'
              << (remaining_cents < 10 ? "0" : "") << remaining_cents << '\n';

    return 0;
}
