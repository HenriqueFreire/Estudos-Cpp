#include<iostream>

int main(){
  int a,b,c;
  std::cin >> a >> b >> c;
  if (a <= b && b <= c) {
    std::cout << a << ", " << b << ", " << c << '\n';
  } else if (a <= c && c <= b) {
    std::cout << a << ", " << c << ", " << b << '\n';
  } else if (b <= a && a <= c) {
    std::cout << b << ", " << a << ", " << c << '\n';
  } else if (b <= c && c <= a) {
    std::cout << b << ", " << c << ", " << a << '\n';
  } else if (c <= a && a <= b) {
    std::cout << c << ", " << a << ", " << b << '\n';
  } else {
    std::cout << c << ", " << b << ", " << a << '\n';
  }

  return 0;
}
