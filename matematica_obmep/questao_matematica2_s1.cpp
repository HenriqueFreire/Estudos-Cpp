#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <map>

// ============================================================================
// UNIVESP - MMB002 (SEMANA 1) - QUESTAO 2 (COM RECURSOS DA STL)
// Tema: Precedencia de Operadores e Expressoes Numericas
//
// Recursos STL Utilizados:
//   - <stack>: std::stack para implementar o algoritmo clássico de avaliação de expressões
//   - <string>: std::string para manipulação da expressão algébrica
//   - <map>: std::map para definir a tabela de precedência dos operadores aritméticos
// ============================================================================

// Função auxiliar para aplicar operações no topo da pilha
int aplicarOperador(int operandoA, int operandoB, char operador) {
    switch (operador) {
        case '+': return operandoA + operandoB;
        case '-': return operandoA - operandoB;
        case '*': return operandoA * operandoB;
        case '/': return operandoA / operandoB;
        default: return 0;
    }
}

// Avaliador de expressões com precedência usando std::stack da STL
int avaliarExpressaoSTL(const std::string& expressao) {
    std::stack<int> valores;       // STL: pilha de operandos
    std::stack<char> operadores;    // STL: pilha de operadores e delimitadores

    // STL: tabela de precedência
    std::map<char, int> precedencia = {
        {'+', 1}, {'-', 1},
        {'*', 2}, {'/', 2}
    };

    for (size_t i = 0; i < expressao.length(); ++i) {
        if (expressao[i] == ' ') continue;

        // Se for número
        if (std::isdigit(expressao[i])) {
            int valor = 0;
            while (i < expressao.length() && std::isdigit(expressao[i])) {
                valor = (valor * 10) + (expressao[i] - '0');
                ++i;
            }
            --i;
            valores.push(valor);
        }
        // Se for abertura de delimitador '(' ou '['
        else if (expressao[i] == '(' || expressao[i] == '[') {
            operadores.push(expressao[i]);
        }
        // Se for fechamento ')' ou ']'
        else if (expressao[i] == ')' || expressao[i] == ']') {
            char delimitadorAbertura = (expressao[i] == ')') ? '(' : '[';
            while (!operadores.empty() && operadores.top() != delimitadorAbertura) {
                char op = operadores.top(); operadores.pop();
                int b = valores.top(); valores.pop();
                int a = valores.top(); valores.pop();
                valores.push(aplicarOperador(a, b, op));
            }
            if (!operadores.empty()) operadores.pop(); // Remove delimitador de abertura
        }
        // Se for operador (+, -, *, /)
        else if (precedencia.count(expressao[i])) {
            while (!operadores.empty() && precedencia.count(operadores.top()) &&
                   precedencia[operadores.top()] >= precedencia[expressao[i]]) {
                char op = operadores.top(); operadores.pop();
                int b = valores.top(); valores.pop();
                int a = valores.top(); valores.pop();
                valores.push(aplicarOperador(a, b, op));
            }
            operadores.push(expressao[i]);
        }
    }

    while (!operadores.empty()) {
        char op = operadores.top(); operadores.pop();
        int b = valores.top(); valores.pop();
        int a = valores.top(); valores.pop();
        valores.push(aplicarOperador(a, b, op));
    }

    return valores.top();
}

int main() {
    std::cout << "=================================================================\n";
    std::cout << "  UNIVESP - MMB002 (SEMANA 1) - QUESTAO 2 (COM STL)             \n";
    std::cout << "  Tema: Precedencia de Operadores e Expressoes Numericas         \n";
    std::cout << "=================================================================\n\n";

    std::string expressao = "[8 * (3 + 2) - (24 / 3 + 6)] + [5 * (4 - 1) - (18 / 2 - 3)]";
    std::cout << "  Expressao Original:\n    " << expressao << "\n\n";

    // 1. Resolução Analítica Passo a Passo
    std::cout << "  [1. RESOLUCAO ANALITICA PASSO A PASSO]\n";
    int bloco1 = (8 * (3 + 2) - (24 / 3 + 6));
    int bloco2 = (5 * (4 - 1) - (18 / 2 - 3));
    int resultadoAnalitico = bloco1 + bloco2;

    std::cout << "    - Bloco 1: [8 * 5 - (8 + 6)] = [40 - 14] = " << bloco1 << "\n";
    std::cout << "    - Bloco 2: [5 * 3 - (9 - 3)] = [15 - 6]  = " << bloco2 << "\n";
    std::cout << "    - Total = " << bloco1 << " + " << bloco2 << " = " << resultadoAnalitico << "\n\n";

    // 2. Resolução Computacional usando std::stack da STL
    std::cout << "  [2. RESOLUCAO COMPUTACIONAL VIA STL std::stack]\n";
    int resultadoSTL = avaliarExpressaoSTL(expressao);
    std::cout << "    - Expressao parseada e avaliada: " << resultadoSTL << "\n";
    std::cout << "    - Status de Equivalencia: " 
              << (resultadoAnalitico == resultadoSTL ? "[VERIFICADO COM SUCESSO]" : "[ERRO]") << "\n\n";

    std::cout << "=================================================================\n";
    std::cout << "  GABARITO OFICIAL: Alternativa D (35)\n";
    std::cout << "=================================================================\n\n";

    return 0;
}
