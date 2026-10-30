/*
O que é um Hash Map (std::unordered_map) em C++?

  1. A Analogia do Dicionário Mágico


  Imagine um dicionário de português. Se você quer encontrar o significado da
palavra "eficiente", você não lê o dicionário do começo até a letra 'E'. Você
usa a organização alfabética para pular diretamente para a seção 'E'. Um hash
map funciona de forma parecida, mas é ainda mais "mágico".


  Pense no hash map como um dicionário mágico onde, ao dar a ele uma palavra (a
chave), ele instantaneamente te diz a página exata (o índice) onde a definição
(o valor) está, sem precisar folhear nada.

  ---

  2. O que é Tecnicamente?


  Em C++, a implementação padrão de um hash map é o std::unordered_map.

  É uma estrutura de dados que armazena informações em pares de chave-valor. A
sua grande vantagem é que ele permite inserções, buscas e remoções de elementos
de forma extremamente rápida. Em média, essas operações levam tempo constante,
ou O(1).

  ---

  3. Como a "Mágica" Acontece: A Função de Hash

  O segredo por trás da velocidade do unordered_map é a função de hash.


   1. Entra a Chave: Você fornece uma chave (pode ser um número, uma string, um
objeto customizado, etc.).
   2. Cálculo do Hash: Uma "função de hash" pega essa chave e a transforma em um
número inteiro, chamado de hash. Esse cálculo é determinístico: a mesma chave
sempre gerará o mesmo hash.
   3. Mapeamento para o Índice: Esse hash é então usado para calcular um índice
em um grande array interno que o unordered_map gerencia.
   4. Armazenamento/Busca: O valor associado à sua chave é armazenado (ou
buscado) nesse índice calculado.

  Quando você quer encontrar um valor, o unordered_map não percorre os elementos
um por um. Ele simplesmente repete o processo: calcula o hash da chave, encontra
o índice e pega o valor que está lá. É um acesso quase direto e instantâneo.


  E se duas chaves gerarem o mesmo índice? (Colisão)
  Isso pode acontecer e é chamado de "colisão". O std::unordered_map lida com
isso de forma elegante. Geralmente, cada índice do array interno pode conter uma
pequena lista de elementos (uma técnica chamada chaining). Se houver uma
colisão, ele simplesmente adiciona o novo par chave-valor a essa pequena lista.
Mesmo com algumas colisões, o desempenho médio continua excelente.

  ---

  4. Características Principais e Para Que Serve


   * Velocidade Extrema: É a principal razão para usá-lo. Operações de busca,
inserção e remoção são, em média, O(1). Compare isso com um std::vector, onde
encontrar um elemento (sem saber o índice) é O(n), pois você pode ter que
percorrê-lo inteiro.


   * Pares Chave-Valor: Perfeito para quando você precisa associar uma
informação a outra.
       * Exemplo: Associar o CPF de uma pessoa (chave) ao seu nome completo
(valor).


   * Não Ordenado: O std::unordered_map não garante nenhuma ordem específica dos
elementos. Se você iterar por ele, os elementos podem aparecer em uma ordem que
parece aleatória. É o preço que se paga pela velocidade.
       * Observação: Se a ordem das chaves for importante, você deve usar o
std::map, que mantém as chaves ordenadas, mas é um pouco mais lento (operações
em O(log n)).

  ---

  5. Casos de Uso Comuns


   1. Problema "Two Sum": Como vimos, usamos para mapear um número (chave) ao
seu índice (valor) para encontrar o complemento rapidamente.
   2. Contagem de Frequência: Contar quantas vezes cada palavra aparece em um
texto. A chave é a palavra (std::string), o valor é a contagem (int).
   3. Caching: Armazenar o resultado de uma computação demorada. Se a mesma
computação for pedida de novo, você pega o resultado do mapa em vez de
recalcular. A chave são os parâmetros da computação, o valor é o resultado.
   4. Procurar Propriedades de um Objeto: Em um jogo, você pode ter um mapa para
guardar as propriedades de um personagem: {"vida": 100, "mana": 50, "força":
15}.

  ---

  6. Exemplo Simples em C++
*/

#include <iostream>
#include <string>
#include <unordered_map>

int main() {
  // Criando um mapa de string (nome) para int (idade)
  std::unordered_map<std::string, int> idades;

  // Inserindo elementos (pares chave-valor)
  idades["Alice"] = 30;
  idades["Bob"] = 25;
  idades.insert({"Charlie", 35});

  // Acessando um valor diretamente pela chave (acesso O(1) em média)
  std::cout << "A idade de Bob e: " << idades["Bob"] << "\n";

  // Verificando se uma chave existe antes de acessá-la (forma segura)
  std::string nome = "David";
  if (idades.find(nome) != idades.end()) {
    std::cout << nome << " esta no mapa.\n";
  } else {
    std::cout << nome << " NAO esta no mapa.\n";
  }

  // Removendo um elemento
  idades.erase("Bob");

  // Iterando por todos os elementos (a ordem não é garantida!)
  std::cout << "\nIdades no mapa:\n";
  for (const auto &par : idades) {
    // par.first é a chave, par.second é o valor
    std::cout << "- " << par.first << ": " << par.second << " anos\n";
  }

  return 0;
}