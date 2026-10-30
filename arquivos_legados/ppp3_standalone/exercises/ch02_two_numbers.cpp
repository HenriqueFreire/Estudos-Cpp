#include <iostream>
#include <algorithm>

/**
 * Programming: Principles and Practice Using C++ (3rd Edition) - Bjarne Stroustrup
 * Chapter 2: Objects, Types, and Values
 * Exercise 4: Arithmetic operations and comparisons with two integer values
 *
 * Determine:
 *  1. Smaller and Larger
 *  2. Sum
 *  3. Difference
 *  4. Product
 *  5. Ratio (val1 / val2)
 */

int main() {
    int val1 = 0;
    int val2 = 0;

    std::cout << "Enter two integer values separated by space:\n";
    if (!(std::cin >> val1 >> val2)) {
        std::cerr << "Error: invalid input. Please enter integers.\n";
        return 1;
    }

    std::cout << "\n--- Results for values " << val1 << " and " << val2 << " ---\n";

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
    std::cout << "Product (" << val1 << " * " << val2 << "): " << static_cast<long long>(val1) * val2 << '\n';

    // 5. Ratio (val1 / val2)
    if (val2 != 0) {
        double ratio = static_cast<double>(val1) / val2;
        std::cout << "Ratio (" << val1 << " / " << val2 << "): " << ratio << '\n';
    } else {
        std::cout << "Ratio (" << val1 << " / " << val2 << "): Undefined (division by zero is not allowed)\n";
    }

    return 0;
}
