// ============================================================================
// Book: Programming: Principles and Practice Using C++ (3rd Edition)
// Chapter 1: Compilation Errors - Example 7
// Error Type: Missing Closing Brace '}' (Block Delimiter Error)
//
// Description:
// Functions in C++ delimit their body with matching curly braces '{' and '}'.
// Omitting the closing brace causes the compiler to reach the end of the file
// while still expecting the function block to close.
//
// Expected Compiler Error:
// error: expected '}' at end of input
// ============================================================================

#include <iostream>

int main()
{
    std::cout << "Hello, World!\n";
    return 0;
// ERROR: Missing closing brace '}'
