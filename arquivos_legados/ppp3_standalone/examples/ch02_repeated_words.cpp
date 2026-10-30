#include <iostream>
#include <string>

// Section 2.5: Assignment and Initialization (Detecting repeated words)
// Run and type a sentence like: "She she laughed He He He because because"
int main() {
    std::string previous;
    std::string current;

    std::cout << "Enter words (press Ctrl+D on Linux to finish):\n";
    while (std::cin >> current) {
        if (previous == current) {
            std::cout << "repeated word: " << current << '\n';
        }
        previous = current;
    }

    return 0;
}
