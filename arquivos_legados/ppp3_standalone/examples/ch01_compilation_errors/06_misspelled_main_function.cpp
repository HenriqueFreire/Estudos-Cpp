// ============================================================================
// Book: Programming: Principles and Practice Using C++ (3rd Edition)
// Chapter 1: Compilation Errors - Example 6
// Error Type: Misspelled main Function / Missing Entry Point (Linker Error)
//
// Description:
// Every executable C++ program requires an entry-point function named exactly 'main'
// (all lowercase). If you name it 'Main' or 'integermain', the compilation step succeeds,
// but the linker fails because it cannot find the entry point.
//
// Expected Linker Error:
// /usr/bin/ld: undefined reference to 'main'
// collect2: error: ld returned 1 exit status
// ============================================================================

#include <iostream>

int Main()  // ERROR: 'Main' with uppercase 'M' instead of 'main'
{
    std::cout << "Hello, World!\n";
    return 0;
}
