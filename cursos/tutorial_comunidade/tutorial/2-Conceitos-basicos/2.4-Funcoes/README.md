# 2.4 - Funções

As funções permitem organizar o seu código em pequenos pedaços com um único propósito, o que facilita o teste e a manutenção.

## Declaração vs. Definição
Em C++, é muito comum separar a **assinatura** da função (o contrato) da sua **implementação** (o código real). Isso permite que uma função seja usada antes mesmo de ser implementada (muito comum em arquivos de cabeçalho `.h`).

## O Tipo `void`
Uma função do tipo `void` é aquela que **não retorna nada**. Ela realiza uma ação (como imprimir algo na tela) mas não entrega um valor de volta.

## Exemplos neste Capítulo

### [exemplo-de-funcao.cpp](./exemplo-de-funcao.cpp)
Exemplo completo de como criar e usar uma função.

### [exemplo-de-declaracao-e-definicao-de-funcao.cpp](./exemplo-de-declaracao-e-definicao-de-funcao.cpp)
Demonstra como declarar uma função no topo do arquivo e implementá-la no final.

### [uso-do-void.cpp](./uso-do-void.cpp)
Mostra como criar funções que apenas executam uma tarefa, sem retorno.

---
> **Atenção:** Em C++, as funções não podem ser chamadas se o compilador ainda não "viu" pelo menos a sua declaração.
