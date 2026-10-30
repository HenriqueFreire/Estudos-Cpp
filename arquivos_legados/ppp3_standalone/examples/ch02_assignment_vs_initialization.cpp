#include <iostream>
#include <string>

// Section 2.5: Assignment and Initialization
int main() {
    // Initialization: gives a value to a variable at its creation
    int a = 3;
    std::cout << "Initial value of a: " << a << '\n';

    // Assignment: overwrites an existing variable's value with a new value
    a = 7;
    std::cout << "After assignment (a = 7): " << a << '\n';

    // Updating a variable based on its previous value
    a = a + 3;
    std::cout << "After a = a + 3: " << a << '\n';

    // Compound assignment and increment operators
    a += 5; // equivalent to a = a + 5
    std::cout << "After a += 5: " << a << '\n';

    ++a; // equivalent to a += 1 or a = a + 1
    std::cout << "After ++a: " << a << '\n';

    // Strings with assignment and append (+=)
    std::string s = "Hello";
    std::cout << "String initial: " << s << '\n';
    s += ", World!";
    std::cout << "String after +=: " << s << '\n';

    return 0;
}
