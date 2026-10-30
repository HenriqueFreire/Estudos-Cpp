# 📘 Programming: Principles and Practice Using C++ (3rd Edition)

**Author:** Bjarne Stroustrup  
**Standard:** C++20 / C++23  
**Focus:** Computer Science Fundamentals, Software Engineering, Scientific & Numerical Computing, High Performance  

---

## 📁 Repository Structure

```
Principles_and_Practice_Using_C++_3/
├── README.md           # Project overview and compilation guidelines
├── bookmark.md         # Reading log and chapter progress tracker
├── algorithms/         # Reusable implementations of key algorithms
├── examples/           # Code samples and chapter demonstrations
├── exercises/          # Solutions to end-of-chapter drills and exercises
└── notes/              # Theoretical summaries and conceptual notes
```

---

## 🛠️ Build & Compilation

To compile C++ files with all standard warnings and modern standards enabled:

```bash
# Compile with C++20
g++ -std=c++20 -Wall -Wextra -pedantic main.cpp -o main

# Run
./main
```

For performance profiling or release builds:
```bash
g++ -std=c++20 -O3 -Wall -Wextra -DNDEBUG main.cpp -o main
```

---

## 🗺️ Book Outline & Coverage

| Part | Topic | Focus Areas |
| :--- | :--- | :--- |
| **Part 0: Introduction** | Context & Basics | Philosophy of programming, hardware & software interaction |
| **Part I: The Basics** | Core Programming | Types, Objects, Expressions, Statements, Functions, Errors, Class Design |
| **Part II: Input and Output** | I/O & Visualization | Streams, File handling, Custom I/O, Display models, Graphical User Interfaces |
| **Part III: Data and Algorithms** | Memory & STL | Free store (heap), Pointers, Arrays, RAII, Templates, Vectors, Containers & Iterators |
| **Part IV: Broadening the View** | Advanced & Applied | History, Text processing, Numerics, Embedded systems, Testing, C interoperability |

