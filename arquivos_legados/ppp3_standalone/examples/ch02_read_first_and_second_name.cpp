#include <iostream>
#include <string>

// Section 2.3: Read first and second name
int main() {
    std::cout << "Please enter your first and second names:\n";
    std::string first;
    std::string second;
    if (std::cin >> first >> second) {
        std::cout << "Hello, " << first << " " << second << "!\n";
    }
    return 0;
}
