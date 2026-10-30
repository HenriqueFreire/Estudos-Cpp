# 🏛️ Repositório Unificado de Estudos de C++ & Algoritmos

Bem-vindo ao repositório centralizado de estudos em **C++ Moderno (C++20 / C++23)**, estruturas de dados, programação competitiva e práticas deliberadas de Henrique Freire.

> **Nota de Arquitetura:** O livro principal **PPP3 (*Programming: Principles and Practice Using C++*, 3ª Edição de Bjarne Stroustrup)** permanece isolado em seu repositório dedicado na grade acadêmica da Univesp (`Modelos/Univesp/estudos dos livros/01 - Principios e Praticas de Programacao com C++ (Bjarne Stroustrup)`). Todos os demais cursos, maratonas e práticas estão unificados aqui.

---

## 📂 Estrutura do Repositório

```text
Estudos-C++/
├── flake.nix                 # Ambiente de desenvolvimento C++23 no NixOS (GCC 14, Clang 18, GDB)
├── .envrc                    # Integração com direnv
├── README.md                 # Este documento
├── cursos/                   # Cursos e tutoriais estruturados
│   ├── judson_santiago/     # Curso de Programação de Computadores (Prof. Judson Santiago)
│   ├── prog_descomplicada/  # Aulas da Programação Descomplicada C++
│   ├── estudo_guiado/       # Planos de estudo de lógica e categorização de desafios
│   └── tutorial_comunidade/ # Tutoriais de sintaxe e conceitos básicos
├── pratica/                  # Prática Deliberada diária
│   ├── cses/                # CSES Problem Set (Introductory, Sorting, DP)
│   ├── beecrowd/            # Problemas resolvidos no Beecrowd / URI
│   ├── daily/               # Registro e sessões diárias
│   └── gemini.md            # Protocolo do Algoritmo dos 25 Minutos
├── maratonas/                # Trilhas de Programação Competitiva
│   ├── ufmg/                # Aulas da Maratona UFMG (Complexidade, STL, Grafos)
│   ├── samuel_hericles/     # Trilha de Iniciação à Programação Competitiva
│   └── progresso_playlists.md # Tracker de aulas assistidas e status
├── matematica_obmep/        # Resoluções de desafios matemáticos e olimpíadas (OBMEP)
└── arquivos_legados/        # Versões anteriores e registros históricos
    ├── inicio_cpp/          # Primeiras anotações em Markdown
    └── ppp3_standalone/     # Cópia standalone anterior à migração para a Univesp
```

---

## 🚀 Ambiente de Desenvolvimento (NixOS / C++23)

O repositório utiliza o **Nix Flakes** para garantir um ambiente idêntico e reprodutível com ferramentas de ponta:

* **Compilador:** GCC 14.4+ e Clang 18.1+ com suporte completo a **C++23**.
* **Diagnóstico e Memória:** **AddressSanitizer (ASan)**, **Valgrind** e **GDB 17+**.
* **Build Systems:** CMake 4+ e Ninja.
* **Linter & LSP:** `clangd`, `clang-format` e `clang-tidy`.

### Como Ativar:
```bash
# Entrar no ambiente nix:
nix develop

# Ou usar o direnv para carregar automaticamente ao entrar na pasta:
direnv allow
```

---

## 🛠️ Comandos de Compilação Recomendados

### 1. Compilação Segura com AddressSanitizer (Modo Estudo / Debug):
Detecta vazamentos de memória (*memory leaks*) e acessos ilegais (*buffer overflows*) em tempo de execução:
```bash
g++ -std=c++23 -Wall -Wextra -Wpedantic -g -fsanitize=address,undefined arquivo.cpp -o app
./app
```

### 2. Compilação Otimizada para Programação Competitiva (CSES / Maratona):
```bash
g++ -std=c++23 -O3 -Wall -Wextra arquivo.cpp -o app
./app < input.txt
```

---

## 📌 Diretrizes de Estudo e Boas Práticas

1. **Priorize C++ Moderno:** Evite padrões arcaicos ("C com classes", `malloc`, ponteiros crus soltos). Prefira containers da STL (`std::vector`, `std::string_view`, `std::optional`), RAII e ponteiros inteligentes (`std::unique_ptr`).
2. **Prática Deliberada:** Siga o protocolo do Algoritmo dos 25 Minutos definido em [`pratica/gemini.md`](pratica/gemini.md).
3. **Controle de Maratonas:** Atualize seu progresso nas playlists através de [`maratonas/progresso_playlists.md`](maratonas/progresso_playlists.md).
