#include <iostream>
#include <set>
#include <vector>
#include <algorithm> // STL: std::set_union, std::set_intersection, std::includes
#include <iterator>  // STL: std::inserter

// ============================================================================
// UNIVESP - MMB002 (SEMANA 1) - QUESTAO 3 (COM RECURSOS DA STL)
// Tema: Teoria dos Conjuntos, Cardinalidade e Inclusao-Exclusao
//
// Recursos STL Utilizados:
//   - <set>: std::set para modelagem matemática de conjuntos (elementos únicos e ordenados)
//   - <algorithm>: std::set_union para união de conjuntos
//   - <algorithm>: std::set_intersection para interseção de conjuntos
//   - <algorithm>: std::includes para teste formal de subconjuntos (A ⊆ B)
//   - <iterator>: std::inserter para popular os conjuntos resultantes das operações STL
// ============================================================================

int main() {
    std::cout << "=================================================================\n";
    std::cout << "  UNIVESP - MMB002 (SEMANA 1) - QUESTAO 3 (COM STL)             \n";
    std::cout << "  Tema: Teoria dos Conjuntos, Cardinalidade e Inclusao-Exclusao  \n";
    std::cout << "=================================================================\n\n";

    // 1. Modelagem com std::set da STL
    std::set<int> conjuntoUniverso;     // U (50 alunos: 1 a 50)
    for (int aluno = 1; aluno <= 50; ++aluno) conjuntoUniverso.insert(aluno);

    std::set<int> conjuntoArtes;        // A (20 alunos: 1 a 20)
    for (int aluno = 1; aluno <= 20; ++aluno) conjuntoArtes.insert(aluno);

    std::set<int> conjuntoMusica;       // M (20 alunos: 21 a 40)
    for (int aluno = 21; aluno <= 40; ++aluno) conjuntoMusica.insert(aluno);

    std::set<int> conjuntoEsportes;     // E (10 alunos: 1 a 10, subconjunto de Artes no cenário teste)
    for (int aluno = 1; aluno <= 10; ++aluno) conjuntoEsportes.insert(aluno);

    std::set<int> conjuntoVazio;        // ∅ (vazio)

    std::cout << "  [DADOS DE CARDINALIDADE (STL std::set::size)]\n";
    std::cout << "    - |U| = " << conjuntoUniverso.size() << " (Conjunto Universo de Alunos)\n";
    std::cout << "    - |A| = " << conjuntoArtes.size()    << " (Inscritos em Artes)\n";
    std::cout << "    - |M| = " << conjuntoMusica.size()   << " (Inscritos em Musica)\n";
    std::cout << "    - |E| = " << conjuntoEsportes.size() << " (Inscritos em Esportes)\n";
    std::cout << "    - |∅| = " << conjuntoVazio.size()    << " (Conjunto Vazio)\n\n";

    std::cout << "  [AVALIACAO DAS AFIRMATIVAS VIA STL]\n";

    // Afirmativa I: Conjuntos Unitários?
    // STL: verifica se size() == 1
    bool afirmativa1 = (conjuntoArtes.size() == 1 && conjuntoMusica.size() == 1 && conjuntoEsportes.size() == 1);
    std::cout << "    I.   A, M e E sao conjuntos unitarios? \n";
    std::cout << "         -> Status: " << (afirmativa1 ? "[VERDADEIRA]" : "[FALSA]") 
              << " (|A|=20, |M|=20, |E|=10; nenhum tem size()==1)\n\n";

    // Afirmativa II: Conjunto vazio ∅ é subconjunto de U e de todos os outros?
    // STL: std::includes testa a relação de subconjunto (A ⊆ B)
    bool vazioSubU = std::includes(conjuntoUniverso.begin(), conjuntoUniverso.end(),
                                   conjuntoVazio.begin(), conjuntoVazio.end());
    bool vazioSubA = std::includes(conjuntoArtes.begin(), conjuntoArtes.end(),
                                   conjuntoVazio.begin(), conjuntoVazio.end());
    bool afirmativa2 = vazioSubU && vazioSubA;
    std::cout << "    II.  O conjunto vazio ∅ e subconjunto de U e de todos os outros?\n";
    std::cout << "         -> STL std::includes(U, ∅): " << (vazioSubU ? "true" : "false") << "\n";
    std::cout << "         -> STL std::includes(A, ∅): " << (vazioSubA ? "true" : "false") << "\n";
    std::cout << "         -> Status: " << (afirmativa2 ? "[VERDADEIRA]" : "[FALSA]") 
              << " (Axioma universal: ∅ ⊆ X, ∀X)\n\n";

    // Afirmativa III: A e M são conjuntos iguais pois contêm o mesmo número de elementos?
    // STL: operador == compara se todos os elementos são estritamente idênticos
    bool saoIguaisSTL = (conjuntoArtes == conjuntoMusica);
    std::cout << "    III. E possivel afirmar que A e M sao conjuntos iguais?\n";
    std::cout << "         -> STL (conjuntoArtes == conjuntoMusica): " << (saoIguaisSTL ? "true" : "false") << "\n";
    std::cout << "         -> Status: " << (saoIguaisSTL ? "[VERDADEIRA]" : "[FALSA]") 
              << " (|A|=|M|=20 indica equipotencia, mas os elementos sao alunos distintos)\n\n";

    // Afirmativa IV: A união de A e E contém entre 20 e 30 alunos?
    // STL: Calculamos a união real com std::set_union
    std::set<int> uniaoCenario1; // Quando E ⊆ A (interseção máxima = 10)
    std::set_union(conjuntoArtes.begin(), conjuntoArtes.end(),
                   conjuntoEsportes.begin(), conjuntoEsportes.end(),
                   std::inserter(uniaoCenario1, uniaoCenario1.begin()));

    std::set<int> conjuntoEsportesDisjunto; // 10 alunos disjuntos de Artes (21 a 30)
    for (int aluno = 21; aluno <= 30; ++aluno) conjuntoEsportesDisjunto.insert(aluno);

    std::set<int> uniaoCenario2; // Quando A ∩ E = ∅ (interseção mínima = 0)
    std::set_union(conjuntoArtes.begin(), conjuntoArtes.end(),
                   conjuntoEsportesDisjunto.begin(), conjuntoEsportesDisjunto.end(),
                   std::inserter(uniaoCenario2, uniaoCenario2.begin()));

    int minUniao = uniaoCenario1.size(); // 20
    int maxUniao = uniaoCenario2.size(); // 30
    bool afirmativa4 = (minUniao == 20 && maxUniao == 30);

    std::cout << "    IV.  A uniao de A e E contem entre 20 e 30 alunos?\n";
    std::cout << "         - STL std::set_union (Cenario E ⊆ A):    |A ∪ E| = " << minUniao << " (minimo)\n";
    std::cout << "         - STL std::set_union (Cenario A ∩ E = ∅): |A ∪ E| = " << maxUniao << " (maximo)\n";
    std::cout << "         -> Status: " << (afirmativa4 ? "[VERDADEIRA]" : "[FALSA]") 
              << " (Intervalo valido: 20 <= |A ∪ E| <= 30)\n\n";

    std::cout << "=================================================================\n";
    std::cout << "  GABARITO OFICIAL: Alternativa D (II e IV, apenas)\n";
    std::cout << "=================================================================\n\n";

    return 0;
}
