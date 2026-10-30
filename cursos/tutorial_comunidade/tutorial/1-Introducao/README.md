# Capítulo 1 - Introdução ao Ambiente C++

Antes de começarmos a programar, precisamos configurar as ferramentas certas. O ecossistema C++ moderno depende de um bom compilador e de um sistema de build.

## O que vamos aprender:

### [1.1 - Olá Mundo](./1.1-ola-mundo/)
O ponto de partida de qualquer programador. Aqui aprendemos a estrutura básica de um programa C++ e como usar o **CMake** para gerenciar o projeto.

## Ferramentas deste Repositório

### Nix (`shell.nix`)
Para garantir que todos tenham o mesmo compilador (`g++`), debugger (`gdb`) e formatador (`clang-format`), usamos o Nix. Basta rodar `nix-shell` para ativar o ambiente.

### CMake
Diferente de rodar `g++` manualmente para cada arquivo, o **CMake** gerencia a compilação de projetos complexos, lidando com dependências e múltiplos arquivos de código-fonte de forma profissional.

---
> **Dica:** O arquivo `ola-mundo.cpp` na raiz é um exemplo simples para teste rápido, mas o projeto profissional está dentro da pasta `1.1-ola-mundo/src/`.
