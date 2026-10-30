# 🚨 Chapter 1: Common Compilation & Linker Errors

In Chapter 1 (*Hello, World!*), Bjarne Stroustrup introduces beginners to compiler error messages. The goal is to demystify compiler diagnostics and learn how to interpret what the compiler is trying to communicate.

---

## 📑 Summary of Examples

| File | Error Category | Description | Primary Diagnostic |
| :--- | :--- | :--- | :--- |
| [`01_missing_semicolon.cpp`](file:///home/henrique/Modelos/Principles_and_Practice_Using_C++_3/examples/ch02_compilation_errors/01_missing_semicolon.cpp) | **Syntax Error** | Missing terminating `;` on output statement | `error: expected ';' before 'return'` |
| [`02_missing_quotes.cpp`](file:///home/henrique/Modelos/Principles_and_Practice_Using_C++_3/examples/ch02_compilation_errors/02_missing_quotes.cpp) | **Syntax / Lookup** | Missing double quotes around string literal | `error: 'Hello' was not declared in this scope` |
| [`03_single_quotes_for_string.cpp`](file:///home/henrique/Modelos/Principles_and_Practice_Using_C++_3/examples/ch02_compilation_errors/03_single_quotes_for_string.cpp) | **Literal Type** | Single quotes `'...'` used for multi-character text | `warning: character constant too long for its type` |
| [`04_wrong_stream_operator.cpp`](file:///home/henrique/Modelos/Principles_and_Practice_Using_C++_3/examples/ch02_compilation_errors/04_wrong_stream_operator.cpp) | **Operator Mismatch** | Using input operator `>>` with output stream `std::cout` | `error: no match for 'operator>>'` |
| [`05_misspelled_identifier.cpp`](file:///home/henrique/Modelos/Principles_and_Practice_Using_C++_3/examples/ch02_compilation_errors/05_misspelled_identifier.cpp) | **Case-Sensitivity** | `std::Cout` instead of `std::cout` | `error: 'Cout' is not a member of 'std'` |
| [`06_misspelled_main_function.cpp`](file:///home/henrique/Modelos/Principles_and_Practice_Using_C++_3/examples/ch02_compilation_errors/06_misspelled_main_function.cpp) | **Linker Error** | `int Main()` instead of `int main()` | `undefined reference to 'main'` |
| [`07_missing_closing_brace.cpp`](file:///home/henrique/Modelos/Principles_and_Practice_Using_C++_3/examples/ch02_compilation_errors/07_missing_closing_brace.cpp) | **Syntax Error** | Missing closing curly brace `}` | `error: expected '}' at end of input` |
| [`08_missing_header_or_import.cpp`](file:///home/henrique/Modelos/Principles_and_Practice_Using_C++_3/examples/ch02_compilation_errors/08_missing_header_or_import.cpp) | **Scope / Name Lookup** | Omitting `<iostream>` or `import std;` | `error: 'std' has not been declared` |

---

## 🧪 Testing These Files

You can test how your local compiler reports each error by attempting to compile any of the files:

```bash
g++ -std=c++20 01_missing_semicolon.cpp
```
