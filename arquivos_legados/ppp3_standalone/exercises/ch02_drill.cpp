#include <iostream>
#include <string>

// Chapter 02 - Drill: Letter Generator (Form Letter)
// Programming: Principles and Practice Using C++ (3rd Edition) - Bjarne Stroustrup

int main() {
    // Step 1: Prompt for recipient's name
    std::cout << "Enter the name of the person you want to write to: ";
    std::string first_name;
    std::cin >> first_name;

    // Step 3: Prompt for another friend's name
    std::cout << "Enter the name of another friend: ";
    std::string friend_name;
    std::cin >> friend_name;

    // Step 4: Prompt for friend's sex ('m' or 'f')
    std::cout << "Enter friend's sex (m for male, f for female): ";
    char friend_sex = 0;
    std::cin >> friend_sex;

    // Step 5: Prompt for recipient's age
    std::cout << "Enter the age of the recipient: ";
    int age = 0;
    std::cin >> age;

    std::cout << "\n----------------------------------------\n";
    std::cout << "               GENERATED LETTER         \n";
    std::cout << "----------------------------------------\n\n";

    // Step 1 & 2: Salutation and introduction
    std::cout << "Dear " << first_name << ",\n\n";
    std::cout << "    How are you? I am fine. I miss you.\n";
    std::cout << "I hope everything is going well with your studies.\n";

    // Step 3 & 4: Friend mention and gender-specific pronoun
    std::cout << "Have you seen " << friend_name << " lately? ";
    if (friend_sex == 'm') {
        std::cout << "If you see " << friend_name << " please ask him to call me.\n";
    } else if (friend_sex == 'f') {
        std::cout << "If you see " << friend_name << " please ask her to call me.\n";
    } else {
        std::cout << "If you see " << friend_name << " please ask them to call me.\n";
    }

    // Step 5 & 6: Age validation and contextual message
    if (age <= 0 || age >= 110) {
        std::cout << "I hear you had a birthday, but you're kidding about your age!\n";
    } else {
        std::cout << "I hear you just had a birthday and you are " << age << " years old.\n";

        if (age < 12) {
            std::cout << "Next year you will be " << age + 1 << ".\n";
        } else if (age == 17) {
            std::cout << "Next year you will be able to vote.\n";
        } else if (age > 70) {
            std::cout << "I hope you are enjoying retirement.\n";
        }
    }

    // Step 7: Closing signature
    std::cout << "\nYours sincerely,\n\n";
    std::cout << "Henrique\n";

    return 0;
}
