#include <iostream>

// Programming: Principles and Practice Using C++ (3rd Edition)
// Chapter 3: Computation
// Section 3.5.1: Function declarations and definitions (Page 71)
//
// Demonstrates separating function declarations (prototypes)
// from their definitions (bodies), allowing them to be called
// before their implementation appears in the file.

// -------------------------------------------------------------
// 1. DECLARAÇÕES DE FUNÇÕES (Protótipos)
// Informam ao compilador o tipo de retorno, nome e parâmetros.
// Note o ponto e vírgula no final (sem corpo {}).
// -------------------------------------------------------------
int square(int x);
double area(double width, double height);
void print_square(int val);

int main()
{
    // O compilador valida essas chamadas consultando apenas as declarações acima:
    int x = 7;
    print_square(x);

    double w = 4.5;
    double h = 2.0;
    std::cout << "Area of " << w << " x " << h << " = " << area(w, h) << '\n';

    return 0;
}

// -------------------------------------------------------------
// 2. DEFINIÇÕES DE FUNÇÕES (Implementações)
// Aqui fornecemos o corpo real {} de cada função.
// Podem ficar abaixo da main() ou até em outro arquivo fonte (.cpp).
// -------------------------------------------------------------

int square(int x)
{
    return x * x;
}

double area(double width, double height)
{
    return width * height;
}

void print_square(int val)
{
    std::cout << "The square of " << val << " is " << square(val) << '\n';
}
