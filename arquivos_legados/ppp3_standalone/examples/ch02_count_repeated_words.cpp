#include <iostream>
#include <string>

// Section 2.5: Assignment and Initialization (Counting repeated words with word index)
int main() {
    int number_of_words = 0;
    std::string previous;
    std::string current;

    std::cout << "Enter words (press Ctrl+D on Linux to finish):\n";
    while (std::cin >> current) {
        ++number_of_words;
        if (previous == current) {
            std::cout << "word number " << number_of_words
                      << " repeated: " << current << '\n';
        }
        previous = current;
    }

    return 0;
}
