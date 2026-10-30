#include <iostream>
#include <iomanip>

int main(){
  const double PI = 3.14159;
  double R;
  std::cin >> R;

  double A = PI * (R * R);
  std::cout << std::fixed << std::setprecision(4);
  std::cout << "A=" << A << '\n';
  return 0;
}
