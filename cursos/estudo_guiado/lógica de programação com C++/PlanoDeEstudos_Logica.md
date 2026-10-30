# Plano de Estudos: Lógica de Programação com Foco em Performance

Este plano de estudos é projetado para ensinar lógica de programação desde os fundamentos, mas com a mesma filosofia do plano de C++ para HFT: cada conceito lógico tem uma consequência no hardware e na performance.

## Filosofia Guia

-   **Um Algoritmo não é só um Algoritmo:** É uma série de instruções que a CPU executará. A ordem e a natureza dessas instruções importam.
-   **Dados são Físicos:** Dados não são abstratos; eles vivem na memória (RAM) e são movidos para o processador (cache). A forma como organizamos e acessamos os dados é, muitas vezes, mais importante que o próprio código.
-   **Decisões Têm Custo:** Um `se` no seu código é um desvio (branch) para a CPU. Desvios imprevisíveis são caros.
-   **Medir o Pensamento:** Antes mesmo de escrever código, devemos ser capazes de analisar a "complexidade" de uma ideia.
-   **Exemplos de Código em Todos os Tópicos:** Cada conceito abordado será acompanhado de 1 ou mais exemplos de código práticos e logo em seguida de 3 desafios de código.
-   **Exibição Direta no Terminal:** Os exemplos de código serão exibidos diretamente aqui no terminal, para que você possa visualizá-los e copiá-los facilmente, seguindo este formato código comentado depois a explicação.
-   **Cópia Manual:** Você poderá copiar o código exibido no terminal e salvá-lo em seus próprios arquivos para compilar e testar. Eu também salvarei uma versão para você, mas a cópia manual é incentivada para a prática.
-   **Interatividade:** Sinta-se à vontade para fazer perguntas, pedir mais exemplos ou solicitar exercícios a qualquer momento.

---

## Fase 1: Fundamentos do Pensamento Computacional e o Hardware

**Objetivo:** Entender os blocos de construção da lógica e como eles interagem com a memória e o processador.

### Tópico 1: Algoritmos e Eficiência
-   **Conceitos:**
    -   O que é um algoritmo: uma receita passo a passo, finita e inequívoca.
    -   Representação: fluxogramas, pseudocódigo.
-   **Foco em Performance:**
    -   **Análise de Custo Intuitiva:** Comparar dois algoritmos para o mesmo problema. Ex: Para encontrar um nome em uma lista telefônica, qual é o custo de procurar um por um (busca linear) vs. abrir no meio e decidir (início da busca binária)? Um é inerentemente mais "eficiente" em termos de passos.

### Tópico 2: Variáveis, Tipos e o Mapa da Memória
-   **Conceitos:**
    -   Variáveis como "caixas" para guardar dados.
    -   Tipos de dados primitivos: Inteiro, Real/Ponto Flutuante, Caractere, Booleano.
-   **Foco em Performance:**
    -   **Tamanho Importa:** Cada tipo ocupa um espaço diferente na memória (`int` vs `long`). Usar o tipo certo evita desperdício.
    -   **Onde os Dados Vivem (Conceitual):** Introduzir a ideia de duas "vizinhanças" na memória: a **Stack** (pequena, extremamente rápida, para dados locais e temporários) e o **Heap** (grande, mais lenta, para dados que precisam viver por mais tempo ou cujo tamanho é desconhecido).

### Tópico 3: Operadores e Expressões
-   **Conceitos:**
    -   Operadores aritméticos (`+`, `-`, `*`, `/`, `%`).
    -   Operadores relacionais (`==`, `!=`, `>`, `<`, `>=`, `<=`).
    -   Operadores lógicos (`E`, `OU`, `NÃO`).
-   **Foco em Performance:**
    -   **Avaliação de Curto-Circuito (Short-Circuit Evaluation):** Se você está avaliando `condiçãoA E condiçãoB` e a `condiçãoA` já é falsa, um computador inteligente nem olha para a `condiçãoB`. Isso é uma otimização fundamental. A ordem das suas condições importa!

### Tópico 4: Controle de Fluxo Condicional
-   **Conceitos:**
    -   `Se / Então / Senão` (If / Else).
    -   `Escolha / Caso` (Switch / Case).
-   **Foco em Performance:**
    -   **O Custo de uma Decisão (Branch Prediction):** Explicar que um `Se` é um "garfo na estrada" para a CPU. A CPU tenta "adivinhar" qual caminho será seguido para não parar. Se ela errar a previsão (branch misprediction), ela perde tempo. Um fluxo de decisões previsível é mais rápido.

### Tópico 5: Estruturas de Repetição (Loops)
-   **Conceitos:**
    -   `Enquanto` (While).
    -   `Para` (For).
    -   `Repita / Até` (Do-While).
-   **Foco em Performance:**
    -   **Localidade de Cache (Visão Lógica):** Este é o conceito mais importante. Acessar dados que estão "perto" uns dos outros na memória é ordens de magnitude mais rápido.
    -   **Exemplo Prático:** Ao processar uma imagem, é muito mais rápido processar todos os pixels de uma linha e depois passar para a próxima (acesso sequencial), do que processar a primeira coluna inteira e depois a segunda (acessos saltados).

---

## Fase 2: Estruturando Dados e Algoritmos

**Objetivo:** Aprender a organizar os dados de forma eficiente e a aplicar algoritmos clássicos, sempre analisando os trade-offs de performance.

### Tópico 6: Vetores e Matrizes (Arrays)
-   **Conceitos:**
    -   Coleções de dados homogêneos.
    -   Acesso por índice.
-   **Foco em Performance:**
    -   **O Poder da Memória Contígua:** Vetores são a estrutura de dados mais amigável ao cache que existe. Iterar sobre um vetor sequencialmente é a operação mais rápida possível para acessar múltiplos dados.
    -   **Acesso O(1):** O acesso a qualquer elemento por seu índice (ex: `vetor[42]`) é instantâneo, pois o computador pode calcular sua posição exata na memória.

### Tópico 7: Funções e Modularização
-   **Conceitos:**
    -   Dividir problemas complexos em partes menores e reutilizáveis.
    -   Parâmetros (entradas) e Retorno (saídas).
-   **Foco em Performance:**
    -   **Custo da Chamada:** Uma chamada de função tem um pequeno custo (overhead).
    -   **Custo de Passar Dados:** Passar um dado "por cópia" para uma função pode ser muito caro se o dado for grande (ex: um texto inteiro). É mais barato passar uma "referência" ou um "endereço" para o dado original.

### Tópico 8: Análise de Complexidade (Big-O Notation)
-   **Conceitos:**
    -   Como medir a eficiência de um algoritmo conforme os dados de entrada crescem.
    -   `O(1)` (constante), `O(log N)` (logarítmico), `O(N)` (linear), `O(N²)` (quadrático).
-   **Foco em Performance:**
    -   Big-O é a ferramenta teórica para prever gargalos de performance. Um algoritmo `O(N²)` não é apenas academicamente "pior", ele se torna inutilizável para grandes volumes de dados, enquanto um `O(log N)` escala de forma fantástica.

### Tópico 9: Algoritmos Fundamentais
-   **Conceitos:**
    -   **Busca:** Busca Linear (`O(N)`) vs. Busca Binária (`O(log N)`).
    -   **Ordenação:** Algoritmos simples como Bubble Sort (`O(N²)`) e algoritmos eficientes como Merge Sort (`O(N log N)`).
-   **Foco em Performance:**
    -   **O Trade-off da Busca Binária:** É extremamente rápida, mas exige que os dados estejam previamente ordenados. O custo de ordenar compensa se você for fazer muitas buscas.
    -   Demonstrar como a escolha do algoritmo de ordenação pode significar a diferença entre um programa que roda em milissegundos e um que leva horas.

### Tópico 10: Estruturas de Dados Fundamentais
-   **Conceitos:**
    -   Pilhas (Stack), Filas (Queue).
    -   Listas Encadeadas (Linked Lists).
    -   Tabelas Hash (Hash Tables / Maps).
-   **Foco em Performance:**
    -   **Análise de Trade-offs (Crucial):**
        -   **Vetor:** Ótimo para acesso e iteração sequencial. Ruim para inserção/remoção no meio. **Rei da localidade de cache.**
        -   **Lista Encadeada:** Ótima para inserção/remoção no meio. Péssima para acesso e iteração. **Inimiga da localidade de cache.**
        -   **Tabela Hash:** Ótima para busca por chave (em média `O(1)`). Ruim para iteração sequencial. **Pode ter picos de latência imprevisíveis (colisões, rehash).**
    -   A escolha da estrutura de dados correta é 80% da batalha da otimização.
