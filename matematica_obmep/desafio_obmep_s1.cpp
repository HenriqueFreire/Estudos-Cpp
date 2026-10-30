#include <iostream>
#include <vector>
#include <numeric>   // std::gcd da STL (C++17)

// ============================================================================
// UNIVESP - MMB002 (SEMANA 1) - FORUM TEMATICO
// Desafio OBMEP 2017 - As cadeiras do teatro (Utilizando recursos da STL)
//
// Recursos STL Utilizados:
//   - <numeric>: std::gcd para calcular o Máximo Divisor Comum
//   - <vector>: std::vector para armazenar dinamicamente as soluções candidatas
// ============================================================================

struct Solucao {
    int assentosPorFileira; // Quantidade de cadeiras em cada fileira (L)
    int fileirasDaFrente;   // Quantidade de fileiras completas à frente (f_frente)
    int fileirasDeTras;     // Quantidade de fileiras completas atrás (f_tras)
    int totalDeFileiras;    // Total de fileiras: frente + casal + trás
    int totalDeAssentos;    // Capacidade total do auditório: L * totalDeFileiras
};

// Função para verificar se um número é primo (propriedade que garante a unicidade do divisor >= 2)
bool ehPrimo(int numero) {
    if (numero <= 1) return false;
    for (int divisor = 2; divisor * divisor <= numero; ++divisor) {
        if (numero % divisor == 0) return false;
    }
    return true;
}

std::vector<Solucao> resolverComSTL(int pessoasAFrente, int pessoasAtras) {
    std::vector<Solucao> solucoes;

    // Utiliza std::gcd da STL (<numeric>) para encontrar o MDC
    int mdc = std::gcd(pessoasAFrente, pessoasAtras);

    // Teorema da Aritmética: Qualquer divisor comum de (a, b) é divisor de mdc(a, b).
    // Testamos todos os divisores possíveis assentosPorFileira >= 2
    for (int assentosPorFileira = 2; assentosPorFileira <= mdc; ++assentosPorFileira) {
        if (mdc % assentosPorFileira == 0) {
            int fileirasDaFrente = pessoasAFrente / assentosPorFileira;
            int fileirasDeTras   = pessoasAtras   / assentosPorFileira;
            int fileiraDoCasal   = 1;
            
            int totalDeFileiras  = fileirasDaFrente + fileiraDoCasal + fileirasDeTras;
            int totalDeAssentos  = assentosPorFileira * totalDeFileiras;

            solucoes.push_back({
                assentosPorFileira,
                fileirasDaFrente,
                fileirasDeTras,
                totalDeFileiras,
                totalDeAssentos
            });
        }
    }
    return solucoes;
}

void analisar(int pessoasAFrente, int pessoasAtras, const char* titulo) {
    std::cout << "-----------------------------------------------------------------\n";
    std::cout << "  " << titulo << "\n";
    std::cout << "  Pessoas a frente: " << pessoasAFrente 
              << " | Pessoas atras: " << pessoasAtras << "\n";

    // STL: std::gcd
    int mdc = std::gcd(pessoasAFrente, pessoasAtras);
    std::cout << "  [STL std::gcd] MDC(" << pessoasAFrente << ", " << pessoasAtras 
              << ") = " << mdc << " (Primo? " << (ehPrimo(mdc) ? "SIM" : "NAO") << ")\n";
    std::cout << "-----------------------------------------------------------------\n";

    std::vector<Solucao> solucoes = resolverComSTL(pessoasAFrente, pessoasAtras);

    for (const Solucao& solucao : solucoes) {
        std::cout << "    " << solucao.assentosPorFileira << " assentos/fileira -> "
                  << solucao.fileirasDaFrente << " (frente) + 1 (casal) + " << solucao.fileirasDeTras << " (tras) = " 
                  << solucao.totalDeFileiras << " fileiras -> "
                  << solucao.assentosPorFileira << " x " << solucao.totalDeFileiras << " = " 
                  << solucao.totalDeAssentos << " assentos no total\n";
    }

    if (solucoes.empty()) {
        std::cout << "    Nenhuma solucao encontrada (nao ha divisor comum >= 2).\n\n";
    } else if (solucoes.size() == 1) {
        std::cout << "    => SOLUCAO UNICA: " << solucoes[0].totalDeAssentos 
                  << " assentos (pois MDC=" << mdc << " e primo!).\n\n";
    } else {
        std::cout << "    => " << solucoes.size() 
                  << " SOLUCOES POSSIVEIS: o problema seria ambiguo!\n\n";
    }
}

int main() {
    std::cout << "=================================================================\n";
    std::cout << "  UNIVESP - MMB002 (SEMANA 1) - FORUM TEMATICO (COM STL)          \n";
    std::cout << "  Desafio OBMEP 2017 - As cadeiras do teatro                     \n";
    std::cout << "=================================================================\n\n";

    analisar(14, 21, "PROBLEMA ORIGINAL (OBMEP 2017)");
    analisar(12, 18, "CONTRAEXEMPLO: por que 'L = MDC' nao e a regra geral");

    std::cout << "=================================================================\n";
    std::cout << "  RESPOSTA DO DESAFIO: 42 CADEIRAS (validado via STL std::gcd)\n";
    std::cout << "=================================================================\n";

    return 0;
}
