#include <iostream>

/*
 * Exercise 8: Test an integer value to determine if it is odd or even.
 * Output format: "The value X is an even number" or "The value X is an odd number".
 */

int main() {
    int n;
    std::cout << "Enter an integer: ";
    if (std::cin >> n) {
        if (n % 2 == 0) {
            std::cout << "The value " << n << " is an even number\n";
        } else {
            std::cout << "The value " << n << " is an odd number\n";
        }
    }

    return 0;
}
