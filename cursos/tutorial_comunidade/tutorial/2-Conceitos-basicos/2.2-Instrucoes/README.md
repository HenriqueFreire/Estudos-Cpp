# 2.2 - Instruções (*Statements*)

As instruções (ou *statements*) são as unidades básicas de execução de um programa em C++. Cada linha de código que termina com um ponto e vírgula (`;`) é, geralmente, uma instrução que o computador deve seguir.

## Tipos Comuns de Instruções

### 1. Declaração
Reserva espaço na memória para uma variável.
```cpp
int x;
```

### 2. Atribuição
Dá um valor a uma variável existente.
```cpp
x = 10;
```

### 3. Chamada de Função
Executa um bloco de código definido em outro lugar.
```cpp
std::cout << "Olá";
```

### 4. Estruturas de Bloco
Um conjunto de instruções agrupadas por chaves `{ }`. Isso é muito comum em `if`, `for` e funções.

## Exemplos neste Capítulo

### [instrucoes.cpp](./instrucoes.cpp)
Mostra como as instruções são sequenciadas e como o compilador as interpreta uma por uma.

---
> **Curiosidade:** No C++, esquecer um ponto e vírgula (`;`) ao final de uma instrução é um dos erros mais comuns e pode causar mensagens de erro confusas do compilador!
