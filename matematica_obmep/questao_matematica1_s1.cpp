#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>   // std::accumulate da STL
#include <string>

// ============================================================================
// UNIVESP - MMB002 (SEMANA 1) - QUESTAO 1 (COM RECURSOS DA STL)
// Tema: Analise Financeira e Operacoes Aritmeticas Basicas
//
// Recursos STL Utilizados:
//   - <vector>: std::vector para listas dinâmicas de transações
//   - <numeric>: std::accumulate para somatório funcional com lambdas
//   - <string>: std::string para rótulos semânticos das transações
// ============================================================================

struct Transacao {
    std::string descricao;
    double valor;
};

int main() {
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "=================================================================\n";
    std::cout << "  UNIVESP - MMB002 (SEMANA 1) - QUESTAO 1 (COM STL)             \n";
    std::cout << "  Tema: Analise Financeira e Operacoes Aritmeticas Basicas       \n";
    std::cout << "=================================================================\n\n";

    // 1. Dados estruturados em containers da STL (std::vector)
    std::vector<Transacao> entradas = {
        {"Receita de Vendas", 200000.0},
        {"Investimento Adicional", 15000.0}
    };

    std::vector<Transacao> saidas = {
        {"Despesas Operacionais", 120000.0},
        {"Impostos", 10000.0},
        {"Novos Equipamentos", 30000.0}
    };

    // 2. STL: std::accumulate com lambda para cálculo das entradas e saídas
    auto somador = [](double acumulado, const Transacao& item) {
        return acumulado + item.valor;
    };

    double totalEntradas = std::accumulate(entradas.begin(), entradas.end(), 0.0, somador);
    double totalSaidas   = std::accumulate(saidas.begin(), saidas.end(), 0.0, somador);
    double lucroLiquido  = totalEntradas - totalSaidas;

    std::cout << "  [ENTRADAS (STL std::vector + std::accumulate)]\n";
    for (const auto& item : entradas) {
        std::cout << "    - " << std::left << std::setw(26) << item.descricao 
                  << ": R$ " << std::right << std::setw(10) << item.valor << "\n";
    }
    std::cout << "    * Total de Entradas:        R$ " << std::setw(10) << totalEntradas << "\n\n";

    std::cout << "  [SAIDAS (STL std::vector + std::accumulate)]\n";
    for (const auto& item : saidas) {
        std::cout << "    - " << std::left << std::setw(26) << item.descricao 
                  << ": R$ " << std::right << std::setw(10) << item.valor << "\n";
    }
    std::cout << "    * Total de Gastos:          R$ " << std::setw(10) << totalSaidas << "\n";
    std::cout << "    --------------------------------------------\n";
    std::cout << "    * Lucro Liquido Calculado:  R$ " << std::setw(10) << lucroLiquido << "\n\n";

    // 3. Avaliação das Afirmativas
    std::cout << "  [AVALIACAO DAS AFIRMATIVAS]\n";

    // Afirmativa I: Lucro Líquido é de R$ 55.000,00
    bool afirmativa1 = (lucroLiquido == 55000.0);
    std::cout << "    I.  Lucro Liquido = R$ 55.000,00?       --> " 
              << (afirmativa1 ? "[VERDADEIRA]" : "[FALSA]") << "\n";

    // Afirmativa II: Divisão igual entre 5 setores (R$ 11.000,00 cada)
    double valorPorSetor = lucroLiquido / 5.0;
    bool afirmativa2 = (valorPorSetor == 11000.0);
    std::cout << "    II. Divisao por 5 = R$ 11.000,00 cada?  --> " 
              << (afirmativa2 ? "[VERDADEIRA]" : "[FALSA]") 
              << " (Valor por setor: R$ " << valorPorSetor << ")\n";

    // Afirmativa III: Redução de R$ 3.500 nos impostos pagos geraria lucro de R$ 51.500,00
    double reducaoImposto = 3500.0;
    double impostoReduzido = 10000.0 - reducaoImposto;
    double gastosComReducao = (120000.0 + impostoReduzido + 30000.0);
    double lucroComReducaoImposto = totalEntradas - gastosComReducao;
    bool afirmativa3 = (lucroComReducaoImposto == 51500.0);

    std::cout << "    III. Reducao de imposto em R$ 3.500,00:\n";
    std::cout << "         - Novo imposto pago: R$ " << impostoReduzido << "\n";
    std::cout << "         - Novo lucro real:   R$ " << lucroComReducaoImposto << " (aumentou)\n";
    std::cout << "         - Afirmado no teste: R$ 51500.00\n";
    std::cout << "         - Status:            --> " 
              << (afirmativa3 ? "[VERDADEIRA]" : "[FALSA] (Corte de custos aumenta o lucro)") << "\n\n";

    std::cout << "=================================================================\n";
    std::cout << "  GABARITO OFICIAL: Alternativa B (I e II, apenas)\n";
    std::cout << "=================================================================\n\n";

    return 0;
}
