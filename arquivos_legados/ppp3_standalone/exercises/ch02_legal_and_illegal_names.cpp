#include <iostream>
#include <string>

/**
 * Programming: Principles and Practice Using C++ (3rd Edition) - Bjarne Stroustrup
 * Chapter 2: Objects, Types, and Values
 * Exercise 3: Declaration of legal and illegal variable names
 *
 * Goal: Observe how the C++ compiler reacts to identifier rules and reserved keywords.
 */

int main() {
    std::cout << "========================================================\n";
    std::cout << "  PPP3 - Ch. 02 - Exercise 3: Legal and Illegal Names   \n";
    std::cout << "========================================================\n\n";

    // =========================================================================
    // 🟢 1. LEGAL IDENTIFIERS (VALID IN C++)
    // C++ Language Rules:
    //  - Must begin with a letter (a-z, A-Z) or underscore (_).
    //  - Can contain letters, digits (0-9), and underscores (_).
    //  - Cannot be reserved language keywords.
    //  - C++ is case-sensitive.
    // =========================================================================

    int age = 25;                                 // Simple and conventional
    int _counter = 10;                           // Starting with underscore (_)
    int number_of_students = 45;                  // snake_case
    int numberOfStudents = 46;                    // camelCase (different from number_of_students)
    int NumberOfStudents = 47;                    // PascalCase (different from numberOfStudents)
    int value1 = 100;                             // Digit in the middle or end
    int x1_y2_z3 = 999;                           // Multiple digits and underscores
    std::string this_is_a_very_long_name = "ok";  // Long self-explanatory name
    double pi_approximation_3_14 = 3.14159;       // Descriptive floating-point identifier
    char _ = 'x';                                 // Single underscore (valid identifier)

    std::cout << "[OK] Variables with legal identifiers successfully declared:\n";
    std::cout << "  - age: " << age << "\n";
    std::cout << "  - _counter: " << _counter << "\n";
    std::cout << "  - number_of_students: " << number_of_students << "\n";
    std::cout << "  - numberOfStudents: " << numberOfStudents << "\n";
    std::cout << "  - NumberOfStudents: " << NumberOfStudents << "\n";
    std::cout << "  - value1: " << value1 << "\n";
    std::cout << "  - x1_y2_z3: " << x1_y2_z3 << "\n";
    std::cout << "  - this_is_a_very_long_name: " << this_is_a_very_long_name << "\n";
    std::cout << "  - pi_approximation_3_14: " << pi_approximation_3_14 << "\n";
    std::cout << "  - _: " << _ << "\n\n";

    // =========================================================================
    // 🔴 2. ILLEGAL IDENTIFIERS (COMPILATION ERRORS)
    // Uncomment any line below to see compiler diagnostics:
    // =========================================================================

    // ❌ Error 1: Cannot begin with numeric digits
    // int 1a = 10;
    // -> Diagnostic: error: expected unqualified-id before numeric constant

    // int 2fast2furious = 20;
    // -> Diagnostic: error: invalid suffix on literal; C++ does not permit identifiers starting with numbers

    // ❌ Error 2: Cannot contain spaces
    // int full name = 30;
    // -> Diagnostic: error: expected initializer before 'name'

    // ❌ Error 3: Cannot contain hyphens (interpreted as subtraction operator)
    // int user-age = 40;
    // -> Diagnostic: error: expected initializer before '-' token

    // ❌ Error 4: Cannot use reserved keywords
    // int double = 50;
    // -> Diagnostic: error: expected unqualified-id before 'double'

    // int return = 60;
    // -> Diagnostic: error: expected unqualified-id before 'return'

    // int class = 70;
    // -> Diagnostic: error: expected unqualified-id before 'class'

    // int if = 80;
    // -> Diagnostic: error: expected unqualified-id before 'if'

    // int while = 90;
    // -> Diagnostic: error: expected unqualified-id before 'while'

    // int int = 100;
    // -> Diagnostic: error: expected unqualified-id before 'int'

    // ❌ Error 5: Cannot contain punctuation or special operators (@, #, $, %, !, .)
    // int user.name = 110;
    // -> Diagnostic: error: expected unqualified-id before '.' token

    // int price$ = 120;
    // -> Diagnostic (strict ISO C++): error: '$' in identifier

    // int email@address = 130;
    // -> Diagnostic: error: expected unqualified-id before '@' token

    std::cout << "--------------------------------------------------------\n";
    std::cout << "Study Tip: Uncomment each illegal line in the source code\n";
    std::cout << "to observe actual GCC/Clang diagnostics firsthand!\n";
    std::cout << "--------------------------------------------------------\n";

    return 0;
}
