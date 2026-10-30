// ============================================================================
// Book: Programming: Principles and Practice Using C++ (3rd Edition)
// Chapter 1: Compilation Errors - Example 8
// Error Type: Missing Standard Library Header / Module (Undeclared Scope Error)
//
// Description:
// In C++, names from the standard library like 'std::cout' must be made available
// by importing or including their declaration (via '#include <iostream>' or 'import std;').
// Without this, 'std' is unknown to the compiler.
//
// Expected Compiler Error:
// error: 'cout' is not a member of 'std' (or 'std' has not been declared)
// ============================================================================

// ERROR: Missing #include <iostream> or import std;

int main()
{
    std::cout << "Hello, World!\n";
    return 0;
}
