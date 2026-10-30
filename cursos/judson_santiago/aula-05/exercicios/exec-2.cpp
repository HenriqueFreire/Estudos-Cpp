#include <iostream>
#include <string>

// Título: Exercício 02 - Variáveis Globais vs. Locais

// ================================================================================
// CONCEITO: VARIÁVEL GLOBAL
// - Declarada fora de qualquer função.
// - Acessível de QUALQUER LUGAR do código (neste arquivo) após sua declaração.
// - Seu tempo de vida é a duração inteira do programa.
// ================================================================================

int contadorGlobal = 0; // Esta é uma variável global.

void funcaoQueUsaGlobal() {
  contadorGlobal++; // Acessa e modifica a variável global.
  std::cout << "[funcaoQueUsaGlobal] O contador global agora é: "
            << contadorGlobal << std::endl;
}

// ================================================================================
// CONCEITO: VARIÁVEL LOCAL
// - Declarada DENTRO de uma função ou de um bloco de código (ex: dentro de um
// if/for).
// - Acessível APENAS dentro da função/bloco onde foi declarada.
// - É criada quando a função é chamada e destruída quando a função termina.
// ================================================================================

void funcaoQueUsaLocal() {
  int contadorLocal = 0; // Esta é uma variável local.
  contadorLocal++;
  std::cout << "[funcaoQueUsaLocal] O contador local é: " << contadorLocal
            << std::endl;
  // A cada chamada desta função, `contadorLocal` é recriado e inicializado com
  // 0.
}

// ================================================================================
// CONCEITO: VARIÁVEL LOCAL ESTÁTICA (UMA ALTERNATIVA MELHOR)
// - Declarada dentro de uma função com a palavra-chave `static`.
// - Acessível APENAS dentro da função (como uma local).
// - MAS, seu valor é preservado entre as chamadas da função (como uma global).
// ================================================================================

void funcaoQueUsaLocalEstatica() {
  static int contadorLocalEstatico = 0; // Variável local estática.
  contadorLocalEstatico++;
  std::cout << "[funcaoQueUsaLocalEstatica] O contador local estático é: "
            << contadorLocalEstatico << std::endl;
  // É inicializada apenas na primeira vez. Nas chamadas seguintes, mantém seu
  // valor.
}

int main() {
  std::cout << "--- DEMONSTRAÇÃO DE VARIÁVEL GLOBAL ---" << std::endl;
  funcaoQueUsaGlobal(); // contadorGlobal se torna 1
  funcaoQueUsaGlobal(); // contadorGlobal se torna 2
  funcaoQueUsaGlobal(); // contadorGlobal se torna 3
  std::cout << "Valor final do contadorGlobal na main: " << contadorGlobal
            << std::endl;
  std::cout << "========================================\n" << std::endl;

  std::cout << "--- DEMONSTRAÇÃO DE VARIÁVEL LOCAL ---" << std::endl;
  funcaoQueUsaLocal(); // contadorLocal é 1, depois destruído.
  funcaoQueUsaLocal(); // contadorLocal é 1, depois destruído.
  funcaoQueUsaLocal(); // contadorLocal é 1, depois destruído.
  // std::cout << contadorLocal; // ERRO DE COMPILAÇÃO! `contadorLocal` não
  // existe aqui.
  std::cout << "========================================\n" << std::endl;

  std::cout << "--- DEMONSTRAÇÃO DE VARIÁVEL LOCAL ESTÁTICA ---" << std::endl;
  funcaoQueUsaLocalEstatica(); // contador se torna 1
  funcaoQueUsaLocalEstatica(); // contador se torna 2
  funcaoQueUsaLocalEstatica(); // contador se torna 3
  std::cout << "========================================\n" << std::endl;

  // ================================================================================
  // OS PERIGOS DAS VARIÁVEIS GLOBAIS
  // ================================================================================
  //
  // Embora pareçam convenientes, variáveis globais são perigosas e devem ser
  // evitadas:
  //
  // 1. EFEITOS COLATERAIS OCULTOS (Falta de Encapsulamento):
  //    - Qualquer função pode modificar uma variável global. Se o valor dela
  //    está errado,
  //      você precisa investigar TODAS as funções que a utilizam para achar o
  //      bug.
  //    - Uma função pode alterar o estado global de uma forma que quebra outra
  //    função
  //      que não esperava por essa mudança. Isso torna o código imprevisível.
  //
  // 2. CONFLITOS DE NOMES:
  //    - Em projetos grandes com múltiplos arquivos, duas pessoas podem criar
  //    variáveis
  //      globais com o mesmo nome sem saber, causando erros de compilação
  //      (linker) ou comportamentos inesperados.
  //
  // 3. PROBLEMAS EM PROGRAMAÇÃO CONCORRENTE (Multi-threading):
  //    - Se duas ou mais threads tentam modificar a mesma variável global ao
  //    mesmo tempo,
  //      pode ocorrer uma "condição de corrida" (race condition), corrompendo o
  //      dado. Proteger variáveis globais exige mecanismos complexos de
  //      sincronização (mutexes).
  //
  // 4. DIFICULDADE NOS TESTES:
  //    - Funções que dependem de estado global são difíceis de testar de forma
  //    isolada.
  //      Você precisa configurar o estado global corretamente antes de cada
  //      teste e limpá-lo depois, o que torna os testes mais complexos e
  //      frágeis.
  //
  // >> BOA PRÁTICA: Prefira passar dados para funções através de parâmetros e
  // retornar
  //    valores. Se precisar manter o estado dentro de uma função, use variáveis
  //    locais estáticas. Use globais apenas em último caso e com muito cuidado.
  //
  // ================================================================================

  return 0;
}