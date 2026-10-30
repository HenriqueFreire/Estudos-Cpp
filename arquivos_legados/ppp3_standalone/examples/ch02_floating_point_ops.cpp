#include <cmath>
#include <iostream>

// Section 2.4: Operations and Operators (Floating-point operations)
int main() {
    std::cout << "Please enter a floating-point value: ";
    double n = 0.0;
    if (std::cin >> n) {
        std::cout << "n == " << n
                  << "\nn + 1 == " << n + 1
                  << "\nthree times n == " << 3 * n
                  << "\ntwice n == " << n + n
                  << "\nn squared == " << n * n
                  << "\nhalf of n == " << n / 2.0
                  << "\nsquare root of n == " << std::sqrt(n)
                  << '\n';
    }
    return 0;
}
