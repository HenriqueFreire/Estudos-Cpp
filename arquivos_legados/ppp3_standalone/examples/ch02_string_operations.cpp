#include <iostream>
#include <string>

// Section 2.4: Operations and Operators (String operations & comparisons)
int main() {
    std::cout << "Please enter two names:\n";
    std::string first;
    std::string second;
    if (std::cin >> first >> second) {
        if (first == second) {
            std::cout << "That's the same name twice!\n";
        }
        if (first < second) {
            std::cout << first << " comes before " << second << " alphabetically.\n";
        }
        if (first > second) {
            std::cout << first << " comes after " << second << " alphabetically.\n";
        }

        std::string full_name = first + " " + second;
        std::cout << "Concatenation (+): " << full_name << '\n';
    }
    return 0;
}
