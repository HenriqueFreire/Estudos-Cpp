#include <string>

int main() {
  std::string some_string = "First string";

  // ... alternativamente, usando `auto`:
  auto some_string_2 = std::string("Second string");

  // ... ou, usando `auto` e `string literals`:
  using namespace std::string_literals;
  auto some_string_3 = "Third string"s;  // Note o `s` após a string!
}
