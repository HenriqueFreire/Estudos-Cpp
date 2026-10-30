// ============================================================================
// Book: Programming: Principles and Practice Using C++ (3rd Edition)
// Chapter 1: Compilation Errors - Example 3
// Error Type: Single Quotes Instead of Double Quotes (Type / Literal Error)
//
// Description:
// In C++, single quotes ('a') denote a single character literal (char),
// whereas double quotes ("text") denote a string literal (const char[] / std::string).
// Putting multiple characters in single quotes results in a multicharacter literal warning/error.
//
// Expected Compiler Warning / Error:
// warning: character constant too long for its type
// warning: multi-character character constant
// ============================================================================

#include <iostream>

int main()
{
    std::cout << 'Hello, World!\n';  // ERROR: Single quotes used for a string of characters
    return 0;
}
