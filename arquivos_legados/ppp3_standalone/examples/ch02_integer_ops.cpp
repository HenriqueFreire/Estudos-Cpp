#include <cmath>
#include <iostream>

// Section 2.4: Operations and Operators (Try This: Integer operations & modulo)
int main() {
    std::cout << "Please enter an integer value: ";
    int n = 0;
    if (std::cin >> n) {
        std::cout << "n == " << n
                  << "\nn + 1 == " << n + 1
                  << "\nthree times n == " << 3 * n
                  << "\ntwice n == " << n + n
                  << "\nn squared == " << n * n
                  << "\nhalf of n (integer division) == " << n / 2
                  << "\nremainder of n / 2 (modulo) == " << n % 2
                  << "\nsquare root of n == " << std::sqrt(n)
                  << '\n';
    }
    return 0;
}
