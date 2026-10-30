# 1.1 - Olá Mundo (Projeto CMake)

Este projeto demonstra a estrutura de um projeto C++ profissional. Em vez de compilarmos os arquivos um por um manualmente, usamos o **CMake** para automatizar tudo.

## O Código
O código fonte principal está em [`src/main.cpp`](./src/main.cpp).

## Como Compilar e Rodar

### 1. Usando o ambiente Nix
Garanta que você está no `nix-shell`.

### 2. Configurar o Projeto (Cria a pasta de build)
```bash
cmake -B build
```

### 3. Compilar
```bash
cmake --build build
```

### 4. Rodar o executável
```bash
./build/src/HelloWorld
```

## O que são esses arquivos?
- **`CMakeLists.txt`**: O script que diz ao CMake como construir o projeto.
- **`CMakePresets.json`**: Atalhos pré-definidos para compilação (Debug, Release).
- **`src/`**: A pasta onde fica o seu código real.
