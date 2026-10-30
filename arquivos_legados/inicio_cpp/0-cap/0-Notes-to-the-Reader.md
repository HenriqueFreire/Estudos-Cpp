# Notas ao Leitor

> "Quando o terreno não corresponde ao mapa,  
> confie no terreno."  
>
> — *Provérbio do exército suíço*

Este capítulo é uma coletânea de informações; seu objetivo é dar uma ideia do que esperar do restante do livro. Por favor, dê uma olhada rápida e leia o que achar interessante. Um professor considerará a maior parte das partes imediatamente útil. Se você estiver lendo este livro sem o auxílio de um bom professor, por favor, não tente ler e entender tudo neste capítulo; apenas observe **"A estrutura deste livro"** e a primeira parte da seção **"Uma filosofia de ensino e aprendizagem"**. Você pode querer retornar e reler este capítulo quando se sentir confortável escrevendo e executando pequenos programas.

## Sumário do Capítulo
*   0.1 A estrutura deste livro
    *   0.1.1 Abordagem geral
    *   0.1.2 Exercícios, práticas, etc.
    *   0.1.3 O que vem depois deste livro
*   0.2 Uma filosofia de ensino e aprendizagem
    *   0.2.1 A ordem dos tópicos
    *   0.2.2 Programação e linguagem de programação
    *   0.2.3 Portabilidade
*   0.3 Programação e ciência da computação
*   0.4 Criatividade e resolução de problemas
*   0.5 Solicitação de feedback
*   0.6 Referências
*   0.7 Biografias

---

## 0.1 A estrutura deste livro

Este livro consiste em quatro partes e uma coleção de apêndices:

**Parte I, "Noções Básicas"**, apresenta os conceitos e técnicas fundamentais de programação, juntamente com a linguagem C++ e os recursos da biblioteca necessários para começar a escrever código. Inclui o sistema de tipos, operações aritméticas, estruturas de controle, tratamento de erros e o projeto, implementação e uso de funções e tipos definidos pelo usuário.

**Parte II, "Entrada e Saída"**, descreve como obter dados numéricos e de texto do teclado e de arquivos, e como produzir a saída correspondente na tela e em arquivos. Em seguida, mostra como apresentar dados numéricos, texto e formas geométricas como saída gráfica e como obter entrada em um programa a partir de uma interface gráfica do usuário (GUI).

**Parte III, "Dados e Algoritmos"**, concentra-se na estrutura de contêineres e algoritmos da biblioteca padrão C++ (a **STL - Standard Template Library**). Mostra como os contêineres (como vetor, lista e mapa) são implementados (usando ponteiros, arrays, memória dinâmica, exceções e templates) e usados. Também demonstra o design e o uso de algoritmos da biblioteca padrão (como `sort`, `find` e `inner_product`).

**Parte IV, "Ampliando a Visão"**, oferece uma perspectiva sobre programação por meio de uma discussão sobre ideais e história, por meio de exemplos (como computação matricial, manipulação de texto, testes e programação de sistemas embarcados) e por meio de uma breve descrição da linguagem C.

Os **Apêndices** fornecem informações úteis que não cabem em uma apresentação tutorial, como análises da linguagem C++ e dos recursos da biblioteca padrão, e descrições de como começar a usar um ambiente de desenvolvimento integrado (IDE) e uma biblioteca de interface gráfica do usuário (GUI).

Infelizmente, o mundo da programação não se divide exatamente em quatro partes claramente separadas. Portanto, as "partes" deste livro fornecem apenas uma classificação geral dos tópicos. Quando o conjunto de tópicos necessários para apresentar uma ideia entra em conflito com a classificação geral, explicamos o mínimo necessário para uma boa apresentação, em vez de simplesmente remeter à explicação completa em outro lugar. Classificações rígidas funcionam muito melhor para manuais do que para tutoriais.

A ordem dos tópicos é determinada por técnicas de programação, e não por recursos da linguagem de programação (veja §0.2).

### Marcadores de Alerta
Para facilitar a revisão, colocamos três tipos de marcadores na margem:
*   🔵 **Azul:** conceitos e técnicas.
*   🟢 **Verde:** conselhos.
*   🔴 **Vermelho:** aviso.

### 0.1.1 Abordagem geral
Em nossa apresentação, buscamos o profissionalismo em vez de termos "fofos", e preferimos subestimar um ponto a exagerá-lo. Se enfatizamos discretamente que algo é importante, queremos dizer que você, mais cedo ou mais tarde, perderá dias de trabalho se não o dominar.

Esforçamo-nos para evitar "mentiras brancas"; ou seja, evitamos explicações excessivamente simplificadas que são claras e fáceis de entender, mas que não são verdadeiras no contexto de linguagens e problemas reais. Por outro lado, este livro não é uma referência; para descrições mais precisas e completas de C++, consulte Bjarne Stroustrup, *The C++ Programming Language* e o padrão ISO C++.

### 0.1.2 Práticas (Drills), exercícios, etc.
A programação não é apenas uma atividade intelectual. Oferecemos dois níveis de prática:

*   **Práticas (Drills):** Um exercício muito simples para desenvolver habilidades práticas, quase mecânicas. Você deve fazer cada prática. Se você não fez as práticas, você não "fez" o livro.
*   **Exercícios:** Destinam-se a deixar espaço para iniciativa e imaginação. Faça pelo menos o suficiente para saber quais são difíceis para você.
*   **Tente isso (Try this):** Sugestões simples para trabalho prático em pausas naturais no texto.

No final de cada capítulo, você encontrará **questões de revisão** para ajudar a articular as ideias e conceitos, e uma seção de **"Termos"** com o vocabulário básico.

### 0.1.3 O que vem depois deste livro?
Ao final deste livro, você não será um especialista, mas terá um começo realmente bom que lhe permite escrever programas úteis simples e ler programas mais complexos. A melhor continuação é trabalhar em um projeto real e, eventualmente, aprender outra linguagem de programação.

---

## 0.2 Uma filosofia de ensino e aprendizagem

Tentamos apresentar os conceitos, técnicas e ferramentas mínimos para que você possa criar programas práticos eficazes, incluindo:
*   Design de classes e algoritmos.
*   Depuração (debugging) e testes.
*   Interfaces gráficas (GUIs).
*   Gerenciamento de memória.
*   A biblioteca padrão C++.

O tópico principal deste livro é a **programação**. A linguagem C++ é nossa ferramenta principal. Cada tópico serve a dois propósitos: apresenta um conceito e um recurso prático da linguagem. Insistimos que os artesãos devem entender suas ferramentas, e não apenas considerá-las "mágicas".

### 0.2.1 A ordem dos tópicos
Nossa abordagem é **"primeiro o concreto"** e **"primeiro a profundidade"**. Escolhemos subconjuntos de recursos que fazem sentido para quem está aprendendo. Rejeitamos as seguintes abordagens comuns:
*   **"C primeiro":** desperdiça tempo e leva a más práticas em C++.
*   **Bottom-up:** promove práticas pobres por falta de suporte da biblioteca.
*   **Top-down:** distrai dos aspectos práticos antes que se aprenda a importância de evitar erros.
*   **"Apenas acredite em mágica":** impede o entendimento real de custos e aplicações.

### 0.2.2 Programação e linguagem de programação
Ensinamos programação primeiro; a linguagem é secundária. No entanto, o design e a depuração não podem ser aprendidos no abstrato. As partes do C++ que apresentamos foram escolhidas para suportar a produção de código de qualidade.

### 0.2.3 Portabilidade
Consideramos a portabilidade essencial. Essencialmente, cada exemplo neste livro é C++ Padrão ISO e portátil, testado em várias máquinas e sistemas operacionais.

Se você tiver problemas com IDEs complexos, tente a **linha de comando**. Exemplo no Linux com `g++`:

```bash
g++ -o meu_programa meu_arquivo1.cpp meu_arquivo2.cpp
./meu_programa
```

---

## 0.3 Programação e ciência da computação
Nosso objetivo é ensinar **programação**: o design e a implementação de programas. Baseamo-nos na ciência da computação o tempo todo e enfatizamos os princípios, mas ensinamos programação como uma habilidade prática baseada em teoria e experiência.

## 0.4 Criatividade e resolução de problemas
Consideramos a programação em si uma forma de resolução de problemas. Somente através da compreensão completa de um problema e de sua solução você pode expressar um programa correto para ele.

## 0.5 Solicitação de feedback
 feedback é essencial; um bom livro-texto não pode ser escrito isolado de seus leitores. Por favor, envie relatos de erros e sugestões para: `www.stroustrup.com/Programming`.

---

## 0.7 Biografias

### Bjarne Stroustrup
Designer e implementador original do C++. Trabalhou na AT&T (Bell Labs) por 25 anos. É membro da Academia Nacional de Engenharia dos EUA e adora código elegante para aplicações desafiadoras (robôs, jogos, análise de texto).

### Lawrence "Pete" Petersen
Professor na Texas A&M por quase 20 anos, Pete foi essencial para o sucesso pedagógico deste material. Ele tinha paixão por ensinar design de software para pessoas reais. Pete faleceu em 2007.

---

### Posfácio
As informações podem parecer intimidantes no início, mas serão totalmente compreendidas após os exercícios e a leitura dos próximos capítulos. Relaxe; isso é esperado. Você se tornará um programador competente à medida que avançar.
