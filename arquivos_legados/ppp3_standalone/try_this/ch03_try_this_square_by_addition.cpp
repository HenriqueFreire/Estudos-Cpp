#include <iostream>

// Programming: Principles and Practice Using C++ (3rd Edition)
// Chapter 3: Computation
// Section 3.5: Functions (Try this - Page 71)
//
// Implements square() without using the multiplication operator,
// computing x * x by repeated addition (adding x to result, x times).

int square(int x)
{
    // Handle negative numbers: (-x)^2 == x^2
    if (x < 0) {
        x = -x;
    }

    int result = 0;
    for (int i = 0; i < x; ++i) {
        result += x;
    }
    return result;
}

int main()
{
    std::cout << "Testing square() using repeated addition:\n";
    std::cout << "Number\tSquare\n";
    std::cout << "------\t------\n";

    for (int i = 0; i <= 10; ++i) {
        std::cout << i << '\t' << square(i) << '\n';
    }

    // Testing negative input
    std::cout << "\nTesting negative number (-5):\n";
    std::cout << "-5\t" << square(-5) << '\n';

    return 0;
}
