#include <iostream>
#include <map>
#include <string>

int main() {
  // Exemplo de 'switch' com inicialização (C++17)
  // A variável 'codigoErro' é inicializada e seu escopo é limitado ao 'switch'.
  // Isso é útil para variáveis que são calculadas apenas para a decisão do
  // switch.
  if (int codigoErro = 200;
      codigoErro == 200) { // Exemplo de como 'codigoErro' poderia ser obtido
    switch (codigoErro) {
    case 200:
      std::cout << "Status: OK (200)\n";
      break;
    case 404:
      std::cout << "Status: Nao Encontrado (404)\n";
      break;
    case 500:
      std::cout << "Status: Erro Interno do Servidor (500)\n";
      break;
    default:
      std::cout << "Status: Codigo de erro desconhecido (" << codigoErro
                << ")\n";
      break;
    }
  } else {
    std::cout << "Nao foi possivel determinar o codigo de erro.\n";
  }

  std::cout << '\n';

  // Outro exemplo: usando um mapa para simular uma busca
  std::map<std::string, int> inventario = {{"maca", 10}, {"banana", 5}};
  if (auto it = inventario.find("maca"); it != inventario.end()) {
    switch (it->second) { // 'it->second' é a quantidade de maçãs
    case 0:
      std::cout << "Maca: Fora de estoque.\n";
      break;
    case 1:
    case 2:
    case 3:
      std::cout << "Maca: Poucas unidades restantes (" << it->second << ").\n";
      break;
    default:
      std::cout << "Maca: Em estoque (" << it->second << ").\n";
      break;
    }
  } else {
    std::cout << "Maca: Item nao encontrado no inventario.\n";
  }

  return 0;
}

/*
  Este exemplo demonstra a sintaxe 'switch com inicialização', uma
  funcionalidade adicionada no C++17, similar ao 'if com inicialização'.

  O que observar:
  1. **Sintaxe:** `switch (inicializacao; expressao)`
     - A parte de 'inicializacao' é executada uma vez antes da 'expressao' ser
       avaliada para a decisão do `switch`.
     - A variável declarada na 'inicializacao' (ex: `codigoErro`, `it`) tem seu
       escopo limitado ao bloco `switch` associado.
  2. **Gerenciamento de Escopo:** Assim como no `if` com inicialização, isso
     ajuda a manter o escopo de variáveis auxiliares restrito ao contexto onde
     elas são realmente necessárias, melhorando a organização e reduzindo
     potenciais conflitos de nomes ou usos indevidos.
  3. **Clareza e Concisão:** Permite que a lógica de inicialização e a decisão
     do `switch` sejam agrupadas de forma mais compacta e legível.

  Performance (Baixa Latência):
  - **Sem Overhead Direto:** Esta é primariamente uma melhoria sintática e de
    gerenciamento de escopo, sem impacto direto na performance em tempo de
    execução.
  - **Melhoria Indireta:** Ao limitar o tempo de vida de variáveis e melhorar
    a clareza do código, pode-se indiretamente contribuir para um código mais
    otimizável e menos propenso a erros, o que é valioso em ambientes de
    baixa latência.
  - **Consistência:** Promove um estilo de codificação mais consistente com
    outras funcionalidades modernas do C++ que enfatizam o gerenciamento de
    escopo.
*/