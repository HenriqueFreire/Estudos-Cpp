#include <iostream>

// Programming: Principles and Practice Using C++ (3rd Edition)
// Chapter 3: Computation
// Section 3.4.1.1: Selection (if-statements)
//
// Converts length from inches to centimeters or centimeters to inches.
// Suffix 'i' or 'c' indicates the unit of the input.

int main()
{
    constexpr double cm_per_inch = 2.54; // Number of centimeters in an inch
    double length = 1;                  // Length in inches or centimeters
    char unit = ' ';

    std::cout << "Please enter a length followed by a unit (c or i):\n";
    std::cin >> length >> unit;

    if (unit == 'i')
        std::cout << length << "in == " << cm_per_inch * length << "cm\n";
    else if (unit == 'c')
        std::cout << length << "cm == " << length / cm_per_inch << "in\n";
    else
        std::cout << "Sorry, I don't know a unit called '" << unit << "'\n";

    return 0;
}
