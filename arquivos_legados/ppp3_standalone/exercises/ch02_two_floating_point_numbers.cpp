#include <iostream>
#include <cmath>

/**
 * Programming: Principles and Practice Using C++ (3rd Edition) - Bjarne Stroustrup
 * Chapter 2: Objects, Types, and Values
 * Exercise 5: Arithmetic operations and comparisons with two floating-point (double) values
 *
 * Determine:
 *  1. Smaller and Larger
 *  2. Sum
 *  3. Difference
 *  4. Product
 *  5. Ratio (val1 / val2)
 */

int main() {
    double val1 = 0.0;
    double val2 = 0.0;

    std::cout << "Enter two floating-point values separated by space:\n";
    if (!(std::cin >> val1 >> val2)) {
        std::cerr << "Error: invalid input. Please enter valid numbers.\n";
        return 1;
    }

    std::cout << "\n--- Floating-Point (double) Results for " << val1 << " and " << val2 << " ---\n";

    // 1. Smaller and Larger
    if (val1 < val2) {
        std::cout << "Smaller: " << val1 << '\n';
        std::cout << "Larger: " << val2 << '\n';
    } else if (val1 > val2) {
        std::cout << "Smaller: " << val2 << '\n';
        std::cout << "Larger: " << val1 << '\n';
    } else {
        std::cout << "The values are equal: " << val1 << " == " << val2 << '\n';
    }

    // 2. Sum
    std::cout << "Sum (" << val1 << " + " << val2 << "): " << val1 + val2 << '\n';

    // 3. Difference
    std::cout << "Difference (" << val1 << " - " << val2 << "): " << val1 - val2 << '\n';

    // 4. Product
    std::cout << "Product (" << val1 << " * " << val2 << "): " << val1 * val2 << '\n';

    // 5. Ratio (val1 / val2)
    if (std::abs(val2) > 1e-12) {
        std::cout << "Ratio (" << val1 << " / " << val2 << "): " << val1 / val2 << '\n';
    } else {
        std::cout << "Ratio (" << val1 << " / " << val2 << "): Undefined (division by zero is not allowed)\n";
    }

    return 0;
}
