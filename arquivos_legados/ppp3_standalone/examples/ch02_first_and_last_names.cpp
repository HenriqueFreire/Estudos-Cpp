#include<string>

int main(){
  std::cout << "Please enter your first and last names\n";
  std::string first;
  std::string last;
  std::cin >> first >> last;
  std::cout << "Hello, " << first << " " << last << '\n';
}
