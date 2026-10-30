// example-header.h - Exemplo de arquivo de cabeçalho em C++.
// Este arquivo contém a declaração de uma função simples e define uma constante.
// Arquivos de cabeçalho são usados para declarar funções, classes, variáveis e constantes
// que serão utilizadas em múltiplos arquivos-fonte (.cpp), promovendo a reutilização de código
// e a organização do projeto.

#ifndef EXAMPLE_HEADER_H // Diretiva de pré-processador: Se EXAMPLE_HEADER_H não estiver definido...
#define EXAMPLE_HEADER_H // ...então defina EXAMPLE_HEADER_H. Isso evita inclusões múltiplas do mesmo cabeçalho.

// Definição de uma constante usando #define.
// É uma forma antiga, mas ainda comum, de definir valores constantes.
#define PI 3.14159

// Declaração de uma função.
// A implementação (corpo) desta função estará em um arquivo .cpp separado.
// Esta função simplesmente retorna o dobro do número inteiro passado como argumento.
int dobrarNumero(int numero);

#endif // Fim da diretiva #ifndef
