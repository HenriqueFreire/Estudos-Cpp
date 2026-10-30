# Plano de Estudos de C++: Rumo ao Nível 5 para Baixa Latência

Bem-vindo ao seu guia de estudos de C++! Este documento descreve o caminho que seguiremos para você alcançar a maestria em C++ moderno, com foco em sistemas de baixa latência e alta performance (HFT), inspirado em referências como o canal "Coding Jesus".

Nosso objetivo é atingir o "Nível 5" de proficiência, o que exige um profundo conhecimento da linguagem, do compilador, do hardware e do sistema operacional.

---

## Como Vamos Estudar

1.  **Foco em Performance:** Cada conceito será analisado sob a ótica da performance. "Qual o custo desta abstração?" será nossa pergunta constante. 
2.  **C++ Moderno (C++17/20/23):** Usaremos os recursos mais modernos da linguagem para escrever código seguro, expressivo e rápido.
3.  **Exemplos de Código em Todos os Tópicos:** Cada conceito abordado será acompanhado de 10 ou mais exemplos de código práticos.
4.  **Exibição Direta no Terminal:** Os exemplos de código serão exibidos diretamente aqui no terminal, para que você possa visualizá-los e copiá-los facilmente, seguindo este formato código comentado depois a explicação.
5.  **Cópia Manual:** Você poderá copiar o código exibido no terminal e salvá-lo em seus próprios arquivos para compilar e testar. Eu também salvarei uma versão para você, mas a cópia manual é incentivada para a prática.
6.  **Interatividade:** Sinta-se à vontade para fazer perguntas, pedir mais exemplos ou solicitar exercícios a qualquer momento.
7.  **Projetos Práticos:** As fases avançadas incluem a implementação de componentes de sistemas de baixa latência reais.
---

### Fase 1: Fundamentos Sólidos (Mapeando para Nível 1-2)

O objetivo aqui é dominar a sintaxe e os blocos de construção fundamentais. Não há atalhos.

1.  **Estrutura e Compilação:** "Olá, Mundo!", processo de compilação (`g++`), linking.
2.  **Tipos de Dados e Memória (A Base):**
    *   Tipos primitivos (`int`, `char`, `float`, `double`) e o espaço que ocupam.
    *   Introdução à diferença entre **Stack** e **Heap**.
3.  **Controle de Fluxo:** `if`, `else`, `switch`.
4.  **Loops:** `for`, `while`, `do-while`.
5.  **Funções:** Passagem por valor vs. referência (`&`) e o impacto na performance (cópia de dados).
6.  **Estruturas de Dados Essenciais:**
    *   `std::string`: Como funciona por baixo dos panos (alocação no heap).
    *   `std::vector`: **Tópico crítico.** Foco em *cache locality*.
    *   Arrays C-style e suas diferenças para `std::vector`.

---

### Fase 2: C++ Intermediário e Abstrações (Mapeando para Nível 3)

Solidificamos o conhecimento e aprendemos a abstração, sempre questionando seu custo.

7.  **Programação Orientada a Objetos (POO) com Olhar Crítico:**
    *   `struct` vs. `class`.
    *   Construtores, Destrutores, e a **Regra dos 3/5/0** (RAII).
    *   **Herança e Polimorfismo:** Entender `virtual functions` e o custo do *dynamic dispatch* (v-tables).
8.  **Gerenciamento de Memória Moderno:**
    *   **Ponteiros Inteligentes:** `std::unique_ptr`, `std::shared_ptr` e seu overhead.
    *   *Move Semantics*, `std::move`, e *copy elision*.
9.  **STL (Standard Template Library) - O Essencial:**
    *   **Contêineres:** `std::unordered_map`, `std::map`, `std::array`. Análise de complexidade e performance.
    *   **Iteradores e Algoritmos.**

---

### Fase 3: C++ Avançado e Consciência de Hardware (Mapeando para Nível 4)

Mergulhamos nos detalhes que separam um programador intermediário de um avançado.

10. **Templates e Código Genérico (Nível Profundo):**
    *   Template Metaprogramming (TMP) e `if constexpr` (C++17).
11. **Concurrency e Multithreading:**
    *   `std::thread`, `std::mutex`, `std::atomic` e o C++ Memory Model.
12. **Otimização e Hardware:**
    *   **Caches da CPU (L1/L2/L3):** *Cache lines*, *cache misses*, *false sharing*.
    *   **Data-Oriented Design.**
    *   **Alinhamento de Memória:** `alignas`, `alignof`.
13. **Compilador e Assembly:**
    *   Analisar a saída em Assembly (`-S` no g++) e flags de otimização.

---

### Fase 4: Maestria em Baixa Latência (Alcançando o Nível 5)

Esta fase é dividida em módulos que representam os pilares da expertise em HFT.

*   **Módulo 4.1: Arquitetura de Computadores e SO para Especialistas**
    *   **Tópicos:** Pipelining, Branch Prediction, Out-of-Order Execution; TLB, Paging; System Calls; CPU Pinning.
    *   **Objetivo:** Entender como o hardware e o SO executam seu código.

*   **Módulo 4.2: Gerenciamento de Memória de Performance Extrema**
    *   **Projeto Prático:** Implementar um **Pool Allocator** e um **Arena Allocator**.
    *   **Objetivo:** Eliminar a latência indeterminística do alocador de memória padrão.

*   **Módulo 4.3: Concorrência Lock-Free**
    *   **Projeto Prático:** Implementar uma fila circular **SPSC (Single-Producer, Single-Consumer) lock-free**.
    *   **Objetivo:** Dominar a comunicação entre threads sem mutexes.

*   **Módulo 4.4: Otimização no Nível da Máquina**
    *   **Projeto Prático:** Usar **SIMD Intrinsics (AVX/SSE)** para vetorizar um cálculo.
    *   **Objetivo:** Escrever código que se aproxima do máximo de performance da CPU.

*   **Módulo 4.5: Networking e Protocolos de Baixa Latência**
    *   **Tópicos:** Estudo de **Kernel Bypass**; Análise de formatos de serialização (SBE vs. Protobuf).
    *   **Objetivo:** Compreender as técnicas para minimizar a latência de rede.