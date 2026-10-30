#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>   // std::accumulate
#include <stack>     // std::stack
#include <map>       // std::map
#include <set>       // std::set
#include <algorithm> // std::set_union, std::includes, std::max
#include <iterator>  // std::inserter
#include <cctype>

// ============================================================================
// UNIVESP - ENGENHARIA DE COMPUTACAO (2026S2B2)
// MMB002 - MATEMATICA BASICA - SEMANA 1
// RESOLUCAO COMPLETA UTILIZANDO A BIBLIOTECA PADRAO DO C++ (STL)
// ============================================================================

// ============================================================================
// QUESTÃO 1: Análise Financeira (STL std::vector + std::accumulate)
// ============================================================================
struct Transacao {
    std::string descricao;
    double valor;
};

void resolverQuestao1STL() {
    std::cout << "=================================================================\n";
    std::cout << "  QUESTAO 1: Analise Financeira (STL std::vector + std::accumulate)\n";
    std::cout << "=================================================================\n";

    std::vector<Transacao> entradas = {
        {"Receita de Vendas", 200000.0},
        {"Investimento Adicional", 15000.0}
    };

    std::vector<Transacao> saidas = {
        {"Despesas Operacionais", 120000.0},
        {"Impostos Pagos", 10000.0},
        {"Novos Equipamentos", 30000.0}
    };

    // std::accumulate da STL (<numeric>)
    auto somador = [](double acumulador, const Transacao& t) { return acumulador + t.valor; };
    double totalEntradas = std::accumulate(entradas.begin(), entradas.end(), 0.0, somador);
    double totalSaidas   = std::accumulate(saidas.begin(), saidas.end(), 0.0, somador);
    double lucroLiquido  = totalEntradas - totalSaidas;

    std::cout << "  [Resumo Financeiro via STL]\n";
    std::cout << "    * Total de Entradas:        R$ " << std::setw(10) << totalEntradas << "\n";
    std::cout << "    * Total de Saidas (Custos): R$ " << std::setw(10) << totalSaidas << "\n";
    std::cout << "    * Lucro Liquido Calculado:  R$ " << std::setw(10) << lucroLiquido << "\n\n";

    // Afirmativa I
    bool afirmativa1 = (lucroLiquido == 55000.0);
    std::cout << "  [Afirmativa I] Lucro Liquido = R$ 55.000,00?  --> "
              << (afirmativa1 ? "VERDADEIRA [OK]" : "FALSA") << "\n";

    // Afirmativa II
    double valorPorSetor = lucroLiquido / 5.0;
    bool afirmativa2 = (valorPorSetor == 11000.0);
    std::cout << "  [Afirmativa II] Divisao em 5 setores = R$ 11.000,00 cada?  --> "
              << (afirmativa2 ? "VERDADEIRA [OK]" : "FALSA") << "\n";

    // Afirmativa III
    double impostoReduzido = 10000.0 - 3500.0;
    double lucroComReducao = totalEntradas - (120000.0 + impostoReduzido + 30000.0);
    bool afirmativa3 = (lucroComReducao == 51500.0);
    std::cout << "  [Afirmativa III] Reducao de R$ 3.500 nos impostos geraria Lucro de R$ 51.500,00?  --> "
              << (afirmativa3 ? "VERDADEIRA" : "FALSA [OK]")
              << " (Lucro real seria R$ " << lucroComReducao << ")\n\n";

    std::cout << "  ===> GABARITO OFICIAL: B (I e II, apenas)\n\n";
}

// ============================================================================
// QUESTÃO 2: Expressão Aritmética (STL std::stack + std::map)
// ============================================================================
int aplicarOp(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

int avaliarComSTLStack(const std::string& expr) {
    std::stack<int> valores;
    std::stack<char> ops;
    std::map<char, int> prec = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

    for (size_t i = 0; i < expr.length(); ++i) {
        if (expr[i] == ' ') continue;
        if (std::isdigit(expr[i])) {
            int val = 0;
            while (i < expr.length() && std::isdigit(expr[i])) {
                val = (val * 10) + (expr[i] - '0');
                ++i;
            }
            --i;
            valores.push(val);
        } else if (expr[i] == '(' || expr[i] == '[') {
            ops.push(expr[i]);
        } else if (expr[i] == ')' || expr[i] == ']') {
            char abre = (expr[i] == ')') ? '(' : '[';
            while (!ops.empty() && ops.top() != abre) {
                char op = ops.top(); ops.pop();
                int b = valores.top(); valores.pop();
                int a = valores.top(); valores.pop();
                valores.push(aplicarOp(a, b, op));
            }
            if (!ops.empty()) ops.pop();
        } else if (prec.count(expr[i])) {
            while (!ops.empty() && prec.count(ops.top()) && prec[ops.top()] >= prec[expr[i]]) {
                char op = ops.top(); ops.pop();
                int b = valores.top(); valores.pop();
                int a = valores.top(); valores.pop();
                valores.push(aplicarOp(a, b, op));
            }
            ops.push(expr[i]);
        }
    }
    while (!ops.empty()) {
        char op = ops.top(); ops.pop();
        int b = valores.top(); valores.pop();
        int a = valores.top(); valores.pop();
        valores.push(aplicarOp(a, b, op));
    }
    return valores.top();
}

void resolverQuestao2STL() {
    std::cout << "=================================================================\n";
    std::cout << "  QUESTAO 2: Precedencia de Operadores (STL std::stack + std::map)\n";
    std::cout << "=================================================================\n";

    std::string expressao = "[8 * (3 + 2) - (24 / 3 + 6)] + [5 * (4 - 1) - (18 / 2 - 3)]";
    std::cout << "  Expressao: " << expressao << "\n\n";

    int resultado = avaliarComSTLStack(expressao);
    std::cout << "  [Resolucao Computacional via STL Stack]\n";
    std::cout << "    * Resultado Avaliado: " << resultado << "\n\n";

    std::cout << "  ===> GABARITO OFICIAL: D (35)\n\n";
}

// ============================================================================
// QUESTÃO 3: Teoria dos Conjuntos (STL std::set + std::includes + std::set_union)
// ============================================================================
void resolverQuestao3STL() {
    std::cout << "=================================================================\n";
    std::cout << "  QUESTAO 3: Teoria dos Conjuntos (STL std::set + std::set_union) \n";
    std::cout << "=================================================================\n";

    std::set<int> U, A, M, E, Vazio;
    for (int i = 1; i <= 50; ++i) U.insert(i);
    for (int i = 1; i <= 20; ++i) A.insert(i);
    for (int i = 21; i <= 40; ++i) M.insert(i);
    for (int i = 1; i <= 10; ++i) E.insert(i);

    std::cout << "  [Cardinalidades (STL std::set::size)]\n";
    std::cout << "    - |U|=" << U.size() << ", |A|=" << A.size() 
              << ", |M|=" << M.size() << ", |E|=" << E.size() << "\n\n";

    // Afirmativa I
    bool af1 = (A.size() == 1 && M.size() == 1 && E.size() == 1);
    std::cout << "  [Afirmativa I] Conjuntos unitarios? --> " 
              << (af1 ? "VERDADEIRA" : "FALSA [OK]") << "\n";

    // Afirmativa II (STL: std::includes)
    bool af2 = std::includes(U.begin(), U.end(), Vazio.begin(), Vazio.end());
    std::cout << "  [Afirmativa II] ∅ ⊆ U e ∅ ⊆ X (STL std::includes)? --> " 
              << (af2 ? "VERDADEIRA [OK]" : "FALSA") << "\n";

    // Afirmativa III (STL: operator==)
    bool af3 = (A == M);
    std::cout << "  [Afirmativa III] A == M por terem mesmo tamanho? --> " 
              << (af3 ? "VERDADEIRA" : "FALSA [OK]") << "\n";

    // Afirmativa IV (STL: std::set_union)
    std::set<int> uniaoMax, uniaoMin;
    std::set<int> E_disjunto;
    for (int i = 21; i <= 30; ++i) E_disjunto.insert(i);

    std::set_union(A.begin(), A.end(), E.begin(), E.end(), std::inserter(uniaoMin, uniaoMin.begin()));
    std::set_union(A.begin(), A.end(), E_disjunto.begin(), E_disjunto.end(), std::inserter(uniaoMax, uniaoMax.begin()));

    bool af4 = (uniaoMin.size() == 20 && uniaoMax.size() == 30);
    std::cout << "  [Afirmativa IV] 20 <= |A ∪ E| <= 30 (STL std::set_union)? --> " 
              << (af4 ? "VERDADEIRA [OK]" : "FALSA") 
              << " (|A ∪ E| varia de " << uniaoMin.size() << " a " << uniaoMax.size() << ")\n\n";

    std::cout << "  ===> GABARITO OFICIAL: D (II e IV, apenas)\n\n";
}

int main() {
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\n#################################################################\n";
    std::cout << "#   UNIVESP - ENGENHARIA DE COMPUTACAO (2026S2B2)              #\n";
    std::cout << "#   MMB002 - MATEMATICA BASICA - SEMANA 1                      #\n";
    std::cout << "#   VALIDACAO COMPUTACIONAL EM C++ COM RECURSOS DA STL         #\n";
    std::cout << "#################################################################\n\n";

    resolverQuestao1STL();
    resolverQuestao2STL();
    resolverQuestao3STL();

    std::cout << "#################################################################\n";
    std::cout << "#   TODAS AS QUESTOES FORAM VALIDADAS COM RECURSOS DA STL!     #\n";
    std::cout << "#################################################################\n\n";

    return 0;
}
