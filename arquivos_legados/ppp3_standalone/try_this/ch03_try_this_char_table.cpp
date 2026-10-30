#include <iostream>

// Programming: Principles and Practice Using C++ (3rd Edition)
// Chapter 3: Computation
// Section 3.4.2.1: while-statements (Try this - Page 66)
//
// Prints a table of characters ('a' through 'z') with their integer values.
// Uses the book's hint: 'b' is char('a'+1), 'c' is char('a'+2), etc.

int main()
{
    int i = 0;
    while (i < 26) {
        char c = 'a' + i;
        std::cout << c << '\t' << int(c) << '\n';
        ++i;
    }

    return 0;
}
