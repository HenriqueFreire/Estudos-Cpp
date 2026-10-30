// ============================================================================
// Book: Programming: Principles and Practice Using C++ (3rd Edition)
// Chapter 1: Compilation Errors - Example 2
// Error Type: Missing String Quotes (Syntax / Undeclared Identifier Error)
//
// Description:
// String literals in C++ must be enclosed in double quotes ("...").
// Without quotes, the compiler interprets 'Hello' and 'World' as variable
// or function identifiers that have not been declared.
//
// Expected Compiler Error:
// error: 'Hello' was not declared in this scope
// error: expected ';' before 'World'
// ============================================================================

#include <iostream>

int main()
{
    std::cout << Hello, World!\n;  // ERROR: Missing double quotes around string literal
    return 0;
}
