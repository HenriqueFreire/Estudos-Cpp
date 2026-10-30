#include <iostream>
#include <string>

/*
 * Exercise 9: Converting spelled-out numbers to digits.
 * Converts words like "zero", "one", "two", "three", "four" into 0, 1, 2, 3, 4.
 * If the input is not recognized, prints "not a number I know".
 */

int main() {
    std::string word;
    std::cout << "Enter a spelled-out number (e.g. zero, one, two, three, four): ";

    if (std::cin >> word) {
        if (word == "zero") {
            std::cout << 0 << '\n';
        } else if (word == "one") {
            std::cout << 1 << '\n';
        } else if (word == "two") {
            std::cout << 2 << '\n';
        } else if (word == "three") {
            std::cout << 3 << '\n';
        } else if (word == "four") {
            std::cout << 4 << '\n';
        } else {
            std::cout << "not a number I know\n";
        }
    }

    return 0;
}
