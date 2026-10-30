// --- matematica.h ---
// Este é o arquivo de cabeçalho (header).
// Ele declara as funções que nosso módulo 'matematica' oferece, mas não contém o código delas.
// Funciona como um contrato ou uma interface pública.

// Estas são "include guards". Elas previnem que este arquivo seja incluído mais de uma vez
// no mesmo arquivo .cpp, o que causaria erros de compilação.
#ifndef MATEMATICA_H
#define MATEMATICA_H

// Declaração (protótipo) da função de soma.
// Qualquer arquivo que incluir "matematica.h" saberá que a função 'somar' existe.
int somar(int a, int b);

// Declaração (protótipo) da função de subtração.
int subtrair(int a, int b);

#endif // MATEMATICA_H
