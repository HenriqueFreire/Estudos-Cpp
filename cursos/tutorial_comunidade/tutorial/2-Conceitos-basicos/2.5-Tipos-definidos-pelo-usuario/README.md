# 2.5 - Tipos Definidos pelo Usuário (`struct`)

O C++ permite criar seus próprios tipos de dados complexos ao agrupar variáveis simples. A palavra-chave para isso é `struct`.

## Comparação com TypeScript
As **`structs`** em C++ são semelhantes às **`interfaces`** ou objetos literais do TypeScript, mas com uma grande diferença: no C++, a `struct` existe na memória física.

## Por que usar?
- Agrupar dados que fazem sentido juntos (como `x` e `y` em um ponto).
- Facilitar a passagem de múltiplos argumentos para funções (passar uma única struct em vez de 10 variáveis soltas).

## Exemplos neste Capítulo

### [structs.cpp](./structs.cpp)
O básico de como definir e usar uma estrutura.

### [structs-compondo-estruturas aninhadas.cpp](./structs-compondo-estruturas%20aninhadas.cpp)
Como colocar uma `struct` dentro de outra (ex: um `Player` que possui uma `Position`).

---
> **Dica Profissional:** No C++, a única diferença real entre uma `struct` e uma `class` é que na `struct` tudo é público por padrão, enquanto na `class` tudo é privado.
