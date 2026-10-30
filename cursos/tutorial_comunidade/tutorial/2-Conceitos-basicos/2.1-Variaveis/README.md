# 2.1 - Variáveis e Tipos de Dados

No C++, toda variável deve ter um tipo definido. Ao contrário do TypeScript (que pode ser compilado para JS), em C++ os tipos determinam exatamente quanto espaço na memória será alocado.

## Tipos Primitivos
Estes são os tipos "átomos" da linguagem, que já vêm embutidos:
- **`int`**: Números inteiros.
- **`double` / `float`**: Números decimais (ponto flutuante).
- **`char`**: Um único caractere (como 'a').
- **`bool`**: Verdadeiro ou falso (`true`/`false`).

## O Uso de `auto` (C++11 em diante)
Assim como o `let` ou `const` no TypeScript, o `auto` permite que o compilador descubra o tipo da variável automaticamente a partir do valor que você atribui a ela.

## Exemplos neste Capítulo

### [tipos-de-variaveis.cpp](./tipos-de-variaveis.cpp)
Apresenta os tipos primitivos e como declará-los.

### [recurso-auto-C++11.cpp](./recurso-auto-C++11.cpp)
Mostra como o compilador infere os tipos usando a palavra-chave `auto`.

### [tipo-string.cpp](./tipo-string.cpp)
Explica o uso de textos (`std::string`) em C++, que é um tipo de biblioteca (`std`) e não um tipo primitivo "puro".

---
> **Atenção:** No C++, cada tipo ocupa um espaço físico real na RAM. Por exemplo, um `double` costuma ocupar 8 bytes, enquanto um `int` ocupa 4 bytes.
