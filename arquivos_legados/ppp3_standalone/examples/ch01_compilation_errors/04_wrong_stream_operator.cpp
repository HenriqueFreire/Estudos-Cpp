// ============================================================================
// Book: Programming: Principles and Practice Using C++ (3rd Edition)
// Chapter 1: Compilation Errors - Example 4
// Error Type: Wrong Stream Operator (Operator Mismatch Error)
//
// Description:
// In C++, the insertion operator '<<' is used to send data TO output streams (like std::cout).
// The extraction operator '>>' is used to get data FROM input streams (like std::cin).
// Using '>>' with std::cout and a string literal fails because you cannot extract into a literal.
//
// Expected Compiler Error:
// error: no match for 'operator>>' (operand types are 'std::ostream' and 'const char[15]')
// ============================================================================

#include <iostream>

int main()
{
    std::cout >> "Hello, World!\n";  // ERROR: Used '>>' instead of '<<'
    return 0;
}
