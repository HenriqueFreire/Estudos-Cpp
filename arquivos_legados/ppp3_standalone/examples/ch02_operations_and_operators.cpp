#include <iostream>
#include <string>

// Section 2.4: Operations and Operators (Type-specific operators overview)
int main() {
    std::cout << "Please enter your first name and age:\n";
    std::string name;
    int age = -1;

    if (std::cin >> name >> age) {
        // '+' adds integers
        int a2 = age + 2;
        // '+' concatenates strings
        std::string n2 = name + " Jr.";

        std::cout << "In two years: " << n2 << " will be " << a2 << " years old.\n";

        // '-' subtracts integers
        int a3 = age - 2;
        std::cout << "Two years ago, you were " << a3 << " years old.\n";

        // Note: The following line is a compile error because '-' is not defined for std::string:
        // std::string n3 = name - " Jr."; // ERROR!
    }

    return 0;
}
