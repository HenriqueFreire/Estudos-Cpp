#include <iostream>

// Programming: Principles and Practice Using C++ (3rd Edition)
// Chapter 3: Computation
// Section 3.4.2.3: for-statements (Try this - Page 68)
//
// Rewrites the character value example to use a for-loop,
// and also writes out a table of integer values for uppercase letters and digits.

int main()
{
    std::cout << "=== Digits ('0' to '9') ===\n";
    for (char c = '0'; c <= '9'; ++c) {
        std::cout << c << '\t' << int(c) << '\n';
    }

    std::cout << "\n=== Uppercase letters ('A' to 'Z') ===\n";
    for (char c = 'A'; c <= 'Z'; ++c) {
        std::cout << c << '\t' << int(c) << '\n';
    }

    std::cout << "\n=== Lowercase letters ('a' to 'z') ===\n";
    for (char c = 'a'; c <= 'z'; ++c) {
        std::cout << c << '\t' << int(c) << '\n';
    }

    return 0;
}
