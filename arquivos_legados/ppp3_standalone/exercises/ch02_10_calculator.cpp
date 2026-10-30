#include <iostream>
#include <string>

/**
 * Programming: Principles and Practice Using C++ (3rd Edition) - Bjarne Stroustrup
 * Chapter 2: Objects, Types, and Values
 * Exercise 10: Simple Operation Calculator
 *
 * Write a program that takes an operation followed by two operands and outputs the result.
 * Example inputs:
 *   + 100 3.14
 *   * 4 5
 *
 * Supported operations:
 *   +, plus
 *   -, minus
 *   *, mul
 *   /, div
 */

int main() {
    std::string operation;
    double val1 = 0.0;
    double val2 = 0.0;

    std::cout << "Enter an operation (+, -, *, /, plus, minus, mul, div) followed by two numbers:\n";

    if (std::cin >> operation >> val1 >> val2) {
        if (operation == "+" || operation == "plus") {
            std::cout << val1 << " + " << val2 << " = " << val1 + val2 << '\n';
        } else if (operation == "-" || operation == "minus") {
            std::cout << val1 << " - " << val2 << " = " << val1 - val2 << '\n';
        } else if (operation == "*" || operation == "mul") {
            std::cout << val1 << " * " << val2 << " = " << val1 * val2 << '\n';
        } else if (operation == "/" || operation == "div") {
            if (val2 != 0.0) {
                std::cout << val1 << " / " << val2 << " = " << val1 / val2 << '\n';
            } else {
                std::cerr << "Error: Division by zero is not allowed.\n";
            }
        } else {
            std::cout << "Unknown operation: " << operation << '\n';
        }
    } else {
        std::cerr << "Error: Invalid input format.\n";
        return 1;
    }

    return 0;
}
