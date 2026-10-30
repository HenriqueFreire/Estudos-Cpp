#include <iostream>
#include <string>

/*
 * Exercise 2: Miles to kilometers conversion.
 * 1 mile is equivalent to 1.60934 kilometers.
 */

double convertDistance(const double& distance) {
    return distance * 1.60934;
}

int main() {
    std::string inputValue;
    std::cout << "Enter a distance in miles:\n";
    if (std::cin >> inputValue) {
        double numericValue = std::stod(inputValue);
        std::cout << "The distance in km is: " << convertDistance(numericValue) << " km\n";
    }

    return 0;
}
