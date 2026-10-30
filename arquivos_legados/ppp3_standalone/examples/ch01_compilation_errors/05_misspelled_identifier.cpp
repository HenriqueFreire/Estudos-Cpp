// ============================================================================
// Book: Programming: Principles and Practice Using C++ (3rd Edition)
// Chapter 1: Compilation Errors - Example 5
// Error Type: Case Sensitivity / Misspelled Identifier (Name Lookup Error)
//
// Description:
// C++ is strictly case-sensitive. 'Cout' is completely distinct from 'cout'.
// Because 'std::Cout' does not exist in namespace 'std', name lookup fails.
//
// Expected Compiler Error:
// error: 'Cout' is not a member of 'std'; did you mean 'cout'?
// ============================================================================

#include <iostream>

int main()
{
    std::Cout << "Hello, World!\n";  // ERROR: 'Cout' with uppercase 'C'
    return 0;
}
