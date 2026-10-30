#include <iostream>

// Programming: Principles and Practice Using C++ (3rd Edition)
// Chapter 3: Computation
// Section 3.4.2.3: for-statements
//
// Calculates and prints a table of squares: 0, 1, 2, ..., 99 using a for-loop.

int square(int x) // calculate the square of x
{
    return x * x;
}

int main()
{
    for (int i = 0; i < 100; ++i) {
        std::cout << i << '\t' << square(i) << '\n';
    }

    return 0;
}
