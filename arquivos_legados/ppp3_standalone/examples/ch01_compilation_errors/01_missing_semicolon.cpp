// ============================================================================
// Book: Programming: Principles and Practice Using C++ (3rd Edition)
// Chapter 1: Compilation Errors - Example 1
// Error Type: Missing Semicolon (Syntax Error)
//
// Description:
// In C++, every statement must terminate with a semicolon ';'.
// Omitting it causes the compiler to read the next token as part of the
// current statement, triggering a syntax error.
//
// Expected Compiler Error:
// error: expected ';' before 'return'
// ============================================================================

#include <iostream>

int main()
{
    std::cout << "Hello, World!\n"  // ERROR: Missing semicolon ';'
    return 0;
}
