#include <iostream>
#include <vector>
#include <string>

// Programming: Principles and Practice Using C++ (3rd Edition)
// Chapter 3: Computation
// Section 3.6: vector (Page 72)
//
// Demonstrates creating, initializing, sizing, and accessing vectors.

int main()
{
    // 1. Initializer-list syntax: specifying exact elements
    std::vector<int> v = {5, 7, 9, 4, 6, 8};
    std::vector<std::string> philosopher = {"Kant", "Plato", "Hume", "Kierkegaard"};

    std::cout << "--- Vector of integers (size: " << v.size() << ") ---\n";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << "v[" << i << "] = " << v[i] << '\n';
    }

    std::cout << "\n--- Vector of strings (philosophers, size: " << philosopher.size() << ") ---\n";
    for (size_t i = 0; i < philosopher.size(); ++i) {
        std::cout << "philosopher[" << i << "] = " << philosopher[i] << '\n';
    }

    // 2. Specifying size explicitly with default values
    std::vector<int> vi(6);         // 6 ints, all initialized to 0
    std::vector<std::string> vs(4); // 4 strings, all initialized to ""

    std::cout << "\n--- Vector initialized with size 6 (defaults to 0) ---\n";
    for (int x : vi) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    std::cout << "\n--- Vector initialized with size 4 (defaults to empty strings) ---\n";
    std::cout << "Length of vs[0]: " << vs[0].length() << " (empty string)\n";

    return 0;
}
