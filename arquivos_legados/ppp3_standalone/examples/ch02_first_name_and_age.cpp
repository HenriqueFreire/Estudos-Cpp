#include<string>

int main(){ // read name and age 
  std::cout << "Please enter your first name and age:\n";
  std::string first_name; // variable string type("???" do not know your value)
  int age; //variable integer type(-1, do not know value age)
  std::cin >> first_name >> age; // read string and integer variables
  std::cout << "Hello," << first_name << "(age " << age << ")\n";
}
