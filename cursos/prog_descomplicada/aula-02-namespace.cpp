#include <iostream>
#include <string>

// 1. Namespace Básico
// Um namespace é uma forma de organizar o código e evitar conflitos de nomes.
// Tudo dentro de um namespace é "encapsulado" sob esse nome.
namespace MinhaBiblioteca {
void saudacao() { std::cout << "Olá da MinhaBiblioteca!" << std::endl; }

std::string getVersao() { return "1.0"; }
} // namespace MinhaBiblioteca

// 2. Namespaces Aninhados
// Namespaces podem ser aninhados para criar uma hierarquia mais detalhada.
namespace Matematica {
const double PI = 3.14159;

namespace Geometria {
double areaCirculo(double raio) { return PI * raio * raio; }

void descrever() { std::cout << "Funções de geometria." << std::endl; }
} // namespace Geometria

namespace Algebra {
int somar(int a, int b) { return a + b; }
} // namespace Algebra
} // namespace Matematica

// 6. Namespace Anônimo (ou sem nome)
// Um namespace anônimo é usado para dar a variáveis e funções linkage interno,
// o que significa que elas só são visíveis dentro da unidade de tradução
// (arquivo .cpp) onde são definidas. É uma alternativa preferível a 'static'
// para variáveis globais.
namespace {
int contadorInterno = 0;

void incrementarContador() {
  contadorInterno++;
  std::cout << "Contador interno: " << contadorInterno << std::endl;
}
} // namespace

int main() {
  // Acessando membros de um namespace usando o operador de escopo (::)
  std::cout << "--- Exemplo de Namespace Básico ---" << std::endl;
  MinhaBiblioteca::saudacao();
  std::cout << "Versão da biblioteca: " << MinhaBiblioteca::getVersao()
            << std::endl;
  std::cout << std::endl;

  // 3. Usando a diretiva 'using namespace'
  // Isso traz todos os nomes de um namespace para o escopo atual.
  // Deve ser usado com cautela, especialmente em arquivos de cabeçalho,
  // para evitar poluição do escopo global.
  std::cout << "--- Exemplo de 'using namespace' ---" << std::endl;
  using namespace MinhaBiblioteca;
  saudacao(); // Agora podemos chamar saudacao() diretamente
  std::cout << "Versão da biblioteca (via using): " << getVersao() << std::endl;
  std::cout << std::endl;

  // Acessando namespaces aninhados
  std::cout << "--- Exemplo de Namespaces Aninhados ---" << std::endl;
  std::cout << "PI em Matematica: " << Matematica::PI << std::endl;
  double raio = 5.0;
  std::cout << "Área do círculo (raio " << raio
            << "): " << Matematica::Geometria::areaCirculo(raio) << std::endl;
  Matematica::Geometria::descrever();
  std::cout << "Soma de 10 e 20: " << Matematica::Algebra::somar(10, 20)
            << std::endl;
  std::cout << std::endl;

  // 4. Usando a declaração 'using' para membros específicos
  // Isso traz apenas um nome específico de um namespace para o escopo atual.
  // É mais seguro do que 'using namespace' pois não polui o escopo com todos os
  // nomes.
  std::cout << "--- Exemplo de 'using' para membro específico ---" << std::endl;
  using Matematica::Algebra::somar;
  using Matematica::Geometria::areaCirculo;

  std::cout << "Área do círculo (raio " << raio
            << ", via using): " << areaCirculo(raio) << std::endl;
  std::cout << "Soma de 5 e 7 (via using): " << somar(5, 7) << std::endl;
  std::cout << std::endl;

  // 5. Alias de Namespace
  // Um alias pode ser criado para um namespace longo ou aninhado,
  // tornando o código mais legível.
  std::cout << "--- Exemplo de Alias de Namespace ---" << std::endl;
  namespace Geo = Matematica::Geometria;
  Geo::descrever();
  std::cout << "Área do círculo (raio 10, via alias): "
            << Geo::areaCirculo(10.0) << std::endl;
  std::cout << std::endl;

  // Usando o namespace anônimo
  std::cout << "--- Exemplo de Namespace Anônimo ---" << std::endl;
  incrementarContador();
  incrementarContador();
  // contadorInterno; // Não pode ser acessado diretamente de fora do namespace
  // anônimo
  std::cout << std::endl;

  // Exemplo de conflito de nomes (apenas para demonstração, não execute)
  // namespace Outro {
  //     void saudacao() {
  //         std::cout << "Olá de Outro!" << std::endl;
  //     }
  // }
  // using namespace Outro;
  // saudacao(); // Isso causaria um erro de ambiguidade se
  // MinhaBiblioteca::saudacao também estivesse em using

  return 0;
}
