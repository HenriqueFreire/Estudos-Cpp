#include <iostream>

// Programming: Principles and Practice Using C++ (3rd Edition)
// Chapter 3: Computation
// Section 3.4.2.1: while-statements
//
// Calculates and prints a table of squares: 0, 1, 2, ..., 99
// Historical note: The first program run on a stored-program computer
// (EDSAC, May 6, 1949 by David Wheeler) was a table of squares.

int square(int x) // calculate the square of x
{
    return x * x;
}

int main()
{
    int i = 0; // start from 0
    while (i < 100) {
        std::cout << i << '\t' << square(i) << '\n';
        ++i; // increment i (that is, i becomes i + 1)
    }

    return 0;
}
