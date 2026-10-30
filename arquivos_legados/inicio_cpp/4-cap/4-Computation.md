# 4 Computação

> "Se não precisa produzir resultados corretos,  
> eu posso torná-lo arbitrariamente rápido."  
> — *Gerald M. Weinberg*

Este capítulo apresenta o básico sobre computação. Em particular, discutiremos como calcular um valor a partir de um conjunto de operandos (**expressão**), como escolher entre ações alternativas (**seleção**) e como repetir uma computação para uma série de valores (**iteração**). Também mostraremos como uma subcomputação específica pode ser nomeada e especificada separadamente (uma **função**). Nossa preocupação principal é expressar computações de formas que levem a programas corretos e bem organizados. Para ajudá-lo a realizar computações mais realistas, introduziremos o tipo `vector` para manter sequências de valores.

## Sumário do Capítulo
*   4.1 Computação
*   4.2 Objetivos e ferramentas
*   4.3 Expressões
    *   4.3.1 Expressões constantes
    *   4.3.2 Operadores
    *   4.3.3 Conversões
*   4.4 Instruções (Statements)
    *   4.4.1 Seleção
    *   4.4.2 Iteração
*   4.5 Funções
    *   4.5.1 Por que se incomodar com funções?
    *   4.5.2 Declarações de função
*   4.6 Vector
    *   4.6.1 Aumentando um vetor
    *   4.6.2 Um exemplo numérico
    *   4.6.3 Um exemplo de texto
*   4.7 Recursos da linguagem

---

## 4.1 Computação

De um certo ponto de vista, tudo o que um programa faz é computar; ou seja, ele recebe algumas entradas e produz alguma saída. Afinal, chamamos o hardware no qual rodamos o programa de **computador**. Essa visão é precisa e razoável, desde que tenhamos uma visão ampla do que constitui entrada e saída:

### Entrada (Input)
A entrada pode vir de um teclado, de um mouse, de uma tela sensível ao toque, de arquivos, de outros dispositivos de entrada, de outros programas, de outras partes de um programa. "Outros dispositivos de entrada" é uma categoria que contém a maioria das fontes de entrada realmente interessantes: teclados musicais, gravadores de vídeo, conexões de rede, sensores de temperatura, sensores de imagem de câmera digital, etc. A variedade é essencialmente infinita.

Para lidar com a entrada, um programa geralmente contém alguns dados, às vezes referidos como suas **estruturas de dados** ou seu **estado**. Por exemplo, um programa de calendário pode conter listas de feriados em vários países e uma lista de seus compromissos. Alguns desses dados fazem parte do programa desde o início; outros dados são construídos conforme o programa lê a entrada e coleta informações úteis dela. Por exemplo, o programa de calendário provavelmente construirá sua lista de compromissos a partir da entrada que você lhe dá. Para o calendário, as entradas principais são os pedidos para ver os meses e dias que você solicita (provavelmente usando cliques do mouse) e os compromissos que você lhe dá para acompanhar (provavelmente digitando informações em seu teclado). A saída é a exibição de calendários e compromissos, além dos botões e prompts de entrada que o programa de calendário escreve em sua tela.

A entrada vem de uma grande variedade de fontes. Da mesma forma, a saída pode ir para uma grande variedade de destinos. A saída pode ser para uma tela, para arquivos, para outros dispositivos de saída, para outros programas e para outras partes de um programa. Exemplos de dispositivos de saída incluem interfaces de rede, sintetizadores musicais, motores elétricos, geradores de luz, aquecedores, etc.

Do ponto de vista da programação, as categorias mais importantes e interessantes são "de/para outro programa" e "de/para outras partes de um programa". A maior parte do restante deste livro poderia ser vista como uma discussão sobre essa última categoria: como expressamos um programa como um conjunto de partes cooperantes e como elas podem compartilhar e trocar dados? Estas são questões-chave na programação. Podemos ilustrar isso graficamente:

**Código:**  
`Entrada -> [ Dados ] -> Saída`

A abreviação **I/O** significa "input/output" (entrada/saída). Neste caso, a saída de uma parte do código é a entrada para a próxima parte. O que tais "partes de um programa" compartilham são dados armazenados na memória principal, em dispositivos de armazenamento persistente (como discos) ou transmitidos por conexões de rede. Por "partes de um programa" queremos dizer entidades como uma função produzindo um resultado a partir de um conjunto de argumentos de entrada (ex: uma raiz quadrada de um número de ponto flutuante), uma função realizando uma ação em um objeto físico (ex: uma função desenhando uma linha em uma tela), ou uma função modificando alguma tabela dentro do programa (ex: uma função adicionando um nome a uma tabela de clientes).

Quando dizemos "entrada" e "saída", geralmente nos referimos à informação que entra e sai de um computador, mas, como você vê, também podemos usar os termos para informações dadas a ou produzidas por uma parte de um programa. Entradas para uma parte de um programa são frequentemente chamadas de **argumentos** e as saídas de uma parte de um programa são frequentemente chamadas de **resultados**.

Por **computação**, queremos dizer simplesmente o ato de produzir algumas saídas baseadas em algumas entradas, como produzindo o resultado (saída) 49 a partir do argumento (entrada) 7 usando a computação (função) `square` (veja §4.5). Como uma curiosidade possivelmente útil, notamos que até a década de 1950 um "computador" era definido como uma pessoa que fazia computações, como um contador, um navegador ou um físico. Hoje, simplesmente delegamos a maioria das computações a computadores (máquinas) de várias formas, das quais a calculadora de bolso está entre as mais simples.

---

## 4.2 Objetivos e ferramentas

Nosso trabalho como programadores é expressar computações:
1.  **Corretamente**
2.  **Simplesmente**
3.  **Eficientemente**

Por favor, note a ordem desses ideais: não importa quão rápido um programa seja se ele der os resultados errados. Da mesma forma, um programa correto e eficiente pode ser tão complicado que deve ser descartado ou completamente reescrito para produzir uma nova versão (*release*). Lembre-se, programas úteis serão sempre modificados para acomodar novas necessidades, novo hardware, etc. Portanto, um programa — e qualquer parte de um programa — deve ser o mais simples possível para realizar sua tarefa.

Por exemplo, assuma que você escreveu o programa perfeito para ensinar aritmética básica para crianças em sua escola local, e que sua estrutura interna é uma bagunça. Qual linguagem você usou para se comunicar com as crianças? Inglês? Inglês e espanhol? E se eu quisesse usá-lo na Finlândia? No Kuwait? Como você mudaria a linguagem (natural) usada para comunicação com uma criança? Se a estrutura interna do programa for uma bagunça, a operação logicamente simples (mas na prática quase sempre muito difícil) de mudar a linguagem natural usada para se comunicar com os usuários torna-se insuperável.

Preocupações com correção, simplicidade e eficiência tornam-se nossas no minuto em que começamos a escrever código para outros e aceitamos a responsabilidade de fazer isso bem; ou seja, devemos aceitar essa responsabilidade quando decidimos nos tornar profissionais. Em termos práticos, isso significa que não podemos simplesmente "jogar" código até que ele pareça funcionar; devemos nos preocupar com a estrutura do código. Paradoxalmente, preocupações com estrutura e "qualidade do código" são frequentemente a maneira mais rápida de fazer algo funcionar. Quando a programação é bem feita, tais preocupações minimizam a necessidade da parte mais frustrante da programação: a **depuração** (*debugging*); ou seja, uma boa estrutura de programa durante o desenvolvimento pode minimizar o número de erros cometidos e o tempo necessário para procurar tais erros e removê-los.

Nossa principal ferramenta para organizar um programa — e para organizar nossos pensamentos enquanto programamos — é quebrar uma grande computação em muitas pequenas. Esta técnica vem em duas variações:

*   **Abstração:** Esconder detalhes que não precisamos para usar uma facilidade ("detalhes de implementação") atrás de uma interface conveniente e geral. Por exemplo, em vez de considerar os detalhes de como ordenar uma lista telefônica (livros grossos foram escritos sobre como ordenar), apenas chamamos o algoritmo `sort` da biblioteca padrão C++. Tudo o que precisamos saber para ordenar é como invocar (chamar) esse algoritmo, então podemos escrever `sort(b, e)` onde `b` e `e` se referem ao início e ao fim da lista telefônica, respectivamente. Outro exemplo é a maneira como usamos a memória do computador. O uso direto da memória pode ser bastante confuso, então a acessamos através de variáveis tipadas e nomeadas (§3.2), vetores da biblioteca padrão (§4.6, Capítulos 17-19), mapas (Capítulo 21), etc.
*   **Dividir e conquistar:** Aqui pegamos um problema grande e o dividimos em vários pequenos. Por exemplo, se precisarmos construir um dicionário, podemos separar esse trabalho em três: ler os dados, ordenar os dados e produzir a saída dos dados. Cada um dos problemas resultantes é significativamente menor do que o original.

Por que isso ajuda? Afinal, um programa construído a partir de partes provavelmente será um pouco maior do que um programa onde tudo é fundido de forma otimizada. A razão é que não somos muito bons em lidar com problemas grandes. A maneira como realmente lidamos com eles — na programação e em outros lugares — é dividi-los em problemas menores, e continuamos dividindo esses em partes ainda menores até obtermos algo simples o suficiente para entender e resolver.

Em termos de programação, você descobrirá que um programa de 1.000 linhas tem muito mais do que dez vezes mais erros do que um programa de 100 linhas, então tentamos compor o programa de 1.000 linhas a partir de partes com menos de 100 linhas. Para programas grandes, digamos 10.000.000 de linhas, aplicar abstração e dividir e conquistar não é apenas uma opção, é um requisito essencial. Simplesmente não podemos escrever e manter grandes programas monolíticos. O restante deste livro pode ser visto como uma longa série de exemplos de problemas que precisam ser divididos em partes menores, juntamente com as ferramentas e técnicas necessárias para fazê-lo.

Quando consideramos dividir um programa, devemos sempre considerar quais ferramentas temos disponíveis para expressar as partes e suas comunicações. Uma boa biblioteca, fornecendo facilidades úteis para expressar ideias, pode afetar crucialmente a maneira como distribuímos a funcionalidade em diferentes partes de um programa. Não podemos apenas sentar e "imaginar" como melhor particionar um programa; devemos considerar quais bibliotecas temos disponíveis. É cedo ainda, mas não é cedo demais para apontar que, se você puder usar uma biblioteca existente, como a biblioteca padrão C++, você pode economizar muito trabalho, não apenas na programação, mas também nos testes e na documentação. Os `iostreams` nos salvam de ter que lidar diretamente com as portas de entrada/saída do hardware. Este é um primeiro exemplo de particionamento de um programa usando abstração. Cada novo capítulo fornecerá mais exemplos.

Note a ênfase em estrutura e organização: você não obtém um bom código apenas escrevendo muitas instruções. Por que mencionamos isso agora? Nesta fase, você (ou pelo menos muitos leitores) tem pouca ideia sobre o que é código, e levará meses até que você esteja pronto para escrever código do qual outras pessoas possam depender para suas vidas ou sustento. Mencionamos isso para ajudá-lo a ajustar a ênfase do seu aprendizado corretamente. É muito tentador avançar rapidamente, focando nas partes da programação que — como o que é descrito no restante deste capítulo — são concretas e imediatamente úteis, e ignorar as partes mais "suaves" e conceituais da arte do desenvolvimento de software. No entanto, bons programadores e designers de sistema sabem (frequentemente tendo aprendido da maneira mais difícil) que as preocupações com a estrutura residem no coração de um bom software e que ignorar a estrutura leva a bagunças caras. Sem estrutura, você está (metaforicamente falando) construindo com tijolos de lama. Isso pode ser feito, mas você nunca chegará ao quinto andar (tijolos de lama não têm a resistência estrutural para isso). Se você tem a ambição de construir algo razoavelmente permanente, preste atenção às questões de estrutura e organização do código ao longo do caminho, em vez de ter que voltar e aprendê-las após os fracassos.

---

## 4.3 Expressões

O bloco de construção mais básico dos programas é uma **expressão**. Uma expressão computa um valor a partir de um número de operandos. A expressão mais simples é simplesmente um valor literal, como `10`, `'a'`, `3.14` ou `"Norah"`.

Nomes de variáveis também são expressões. Uma variável representa o objeto do qual ela é o nome. Considere:

```cpp
// calcular área:
int length = 20;        // um literal inteiro (usado para inicializar uma variável)
int width = 40;
int area = length * width; // uma multiplicação
```

Aqui os literais `20` e `40` são usados para inicializar as variáveis `length` e `width`. Então, `length` e `width` são multiplicados; ou seja, multiplicamos os valores encontrados em `length` e `width`. Aqui, `length` é simplesmente uma abreviação para "o valor encontrado no objeto chamado length". Considere também:

`length = 99; // atribui 99 a length`

Aqui, como o operando à esquerda da atribuição, `length` significa "o objeto chamado length", de modo que a expressão de atribuição é lida como "Coloque 99 no objeto nomeado por length". Distinguimos entre `length` usado no lado esquerdo de uma atribuição ou inicialização ("o **lvalue** de length" ou "o objeto nomeado por length") e `length` usado no lado direito de uma atribuição ou inicialização ("o **rvalue** de length", "o valor do objeto nomeado por length", ou apenas "o valor de length"). Neste contexto, achamos útil visualizar uma variável como uma caixa rotulada por seu nome:

**int:**  
`length:` [ 99 ]

Ou seja, `length` é o nome de um objeto do tipo `int` contendo o valor 99. Às vezes (como um lvalue), `length` refere-se à caixa (objeto) e às vezes (como um rvalue), `length` refere-se ao valor naquela caixa.

Podemos fazer expressões mais complicadas combinando expressões usando operadores, como `+` e `*`, da mesma forma que estamos acostumados. Quando necessário, podemos usar parênteses para agrupar expressões:

`int perimeter = (length + width) * 2; // somar, depois multiplicar`

Sem parênteses, teríamos que dizer:

`int perimeter = length * 2 + width * 2;`

o que é desajeitado, e poderíamos até ter cometido este erro:

`int perimeter = length + width * 2; // adiciona width*2 a length`

Este último erro é lógico e não pode ser encontrado pelo compilador. Tudo o que o compilador vê é uma variável chamada `perimeter` inicializada por uma expressão válida. Se o resultado dessa expressão for um absurdo, o problema é seu. Você conhece a definição matemática de um perímetro, mas o compilador não.

As regras matemáticas usuais de precedência de operadores se aplicam, então `length + width * 2` significa `length + (width * 2)`. Da mesma forma, `a*b + c/d` significa `(a*b) + (c/d)` e não `a*(b+c)/d`. Veja §A.5 para uma tabela de precedência.

A primeira regra para o uso de parênteses é simplesmente "Em caso de dúvida, use parênteses", mas, por favor, aprenda o suficiente sobre expressões para não ter dúvidas sobre `a*b + c/d`. O uso excessivo de parênteses, como em `(a*b) + (c/d)`, diminui a legibilidade.

Por que você deveria se importar com a legibilidade? Porque você e possivelmente outros lerão seu código, e um código feio retarda a leitura e a compreensão. Um código feio não é apenas difícil de ler, é também muito mais difícil de tornar correto. O código feio frequentemente esconde erros lógicos. Ele é mais lento de ler e torna mais difícil convencer a si mesmo — e a outros — de que o código está correto. Não escreva expressões absurdamente complicadas como:

`a * b + c / d * (e - f / g) / h + 7 // muito complicado`

e sempre tente escolher nomes significativos.

---

### 4.3.1 Expressões constantes

Programas tipicamente usam muitas constantes. Por exemplo, um programa de geometria pode usar *pi* e um programa de conversão de polegadas para centímetros usará um fator de conversão como 2.54. Obviamente, queremos usar nomes significativos para essas constantes (como fizemos para *pi*; não dissemos 3.14159). Da mesma forma, não queremos mudar essas constantes acidentalmente. Consequentemente, o C++ oferece a noção de uma **constante simbólica**, ou seja, um objeto nomeado ao qual você não pode dar um novo valor após ele ter sido inicializado. Por exemplo:

```cpp
const double pi = 3.14159;
pi = 7;             // erro: atribuição a const
int v = 2 * pi * r; // OK: nós apenas lemos pi; não tentamos mudá-lo
```

Tais constantes são úteis para manter o código legível. Você pode ter reconhecido 3.14159 como uma aproximação de *pi* se o visse em algum código, mas você teria reconhecido 299792458? Além disso, se alguém lhe pedisse para mudar algum código para usar *pi* com a precisão de 12 dígitos para sua computação, você poderia procurar por 3.14 em seu código, mas se alguém incautamente tivesse usado 22/7, você provavelmente não o encontraria. Seria muito melhor apenas mudar a definição de *pi* para usar o valor mais apropriado:

`const double pi = 3.14159265359;`

Consequentemente, preferimos não usar literais (exceto os muito óbvios, como 0 e 1) na maioria dos lugares em nosso código. Em vez disso, usamos constantes com nomes descritivos. Literais não óbvios no código (fora das definições `const`) são referidos depreciativamente como **magic constants** (constantes mágicas).

Em alguns lugares, como rótulos de `case` (§4.4.1.3), o C++ exige uma **expressão constante**, ou seja, uma expressão com um valor inteiro composta exclusivamente de constantes. Por exemplo:

```cpp
const int max = 17; // um literal é uma expressão constante
int val = 19;
max + 2;            // uma expressão constante (um const int mais um literal)
val + 2;            // NÃO é uma expressão constante: ela usa uma variável
```

E a propósito, 299792458 é uma das constantes fundamentais do universo: a velocidade da luz no vácuo medida em metros por segundo. Se você não reconheceu isso instantaneamente, por que esperaria não ficar confuso e ser retardado por outras constantes embutidas no código? Evite constantes mágicas!

---

### 4.3.2 Operadores

Acabamos de usar os operadores mais simples. No entanto, você logo precisará de mais conforme quiser expressar operações mais complexas. A maioria dos operadores é convencional, então apenas os explicaremos conforme necessário e você poderá consultar detalhes se e quando sentir necessidade. Aqui está uma lista dos operadores mais comuns:

| Expressão | Nome | Comentário |
| :--- | :--- | :--- |
| `f(a)` | chamada de função | passa `a` para `f` como um argumento |
| `++lvai` | pré-incremento | incrementa e usa o valor incrementado |
| `--lvai` | pré-decremento | decrementa e usa o valor decrementado |
| `!a` | NOT lógico | resultado é `bool` |
| `-a` | menos unário | |
| `a * b` | multiplicar | |
| `a / b` | dividir | |
| `a % b` | módulo (resto) | apenas para tipos inteiros |
| `a + b` | somar | |
| `a - b` | subtrair | |
| `out << b` | escrever `b` em `out` | onde `out` é um `ostream` |
| `in >> b` | ler de `in` para `b` | onde `in` é um `istream` |
| `a < b` | menor que | resultado é `bool` |
| `a <= b` | menor ou igual | resultado é `bool` |
| `a > b` | maior que | resultado é `bool` |
| `a >= b` | maior ou igual | resultado é `bool` |
| `a == b` | igual | não confundir com `=` |
| `a != b` | diferente | resultado é `bool` |
| `a && b` | AND lógico | resultado é `bool` |
| `a || b` | OR lógico | resultado é `bool` |
| `lvai = a` | atribuição | não confundir com `==` |
| `lvai *= a` | atribuição composta | `lvai = lvai * a`; também para `/`, `%`, `+`, `-` |

Usamos `lvai` (abreviação de "valor que pode aparecer no lado esquerdo de uma atribuição") onde o operador modifica um operando. Você pode encontrar uma lista completa no §A.5.

Para exemplos do uso dos operadores lógicos `&&` (e), `||` (ou) e `!` (não), veja §5.5.1, §7.7, §7.8.2 e §10.4.

Note que `a < b < c` significa `(a < b) < c` e que `a < b` avalia para um valor booleano: `true` ou `false`. Portanto, `a < b < c` será equivalente a `true < c` ou `false < c`. Em particular, `a < b < c` **não** significa "b está entre a e c?", como muitos assumiram ingenuamente (e não sem razão). Assim, `a < b < c` é basicamente uma expressão inútil. Não escreva tais expressões com duas operações de comparação, e seja muito suspeito se encontrar tal expressão no código de outra pessoa — é muito provável que seja um erro.

Um incremento pode ser expresso de pelo menos três formas:
*   `++a`
*   `a += 1`
*   `a = a + 1`

Qual notação devemos usar? Por quê? Preferimos a primeira versão, `++a`, porque ela expressa mais diretamente a ideia de incrementar. Ela diz o que queremos fazer (incrementar `a`) em vez de como fazê-lo (somar 1 a `a` e depois escrever o resultado em `a`). Em geral, uma forma de dizer algo em um programa é melhor do que outra se expressar mais diretamente uma ideia. O resultado é mais conciso e mais fácil para um leitor entender. Se escrevêssemos `a = a + 1`, um leitor poderia facilmente se perguntar se realmente queríamos incrementar por 1. Talvez tivéssemos apenas digitado incorretamente `a = b + 1`, `a = a + 2` ou até `a = a - 1`; com `++a` existem muito menos oportunidades para tais dúvidas. Por favor, note que este é um argumento lógico sobre legibilidade e correção, não um argumento sobre eficiência. Ao contrário da crença popular, compiladores modernos tendem a gerar exatamente o mesmo código a partir de `a = a + 1` e para `++a` quando `a` é um dos tipos embutidos. Da mesma forma, preferimos `a *= escala` em vez de `a = a * escala`.

---

### 4.3.3 Conversões

Podemos "misturar" tipos diferentes em expressões. Por exemplo, `2.5 / 2` é um `double` dividido por um `int`. O que isso significa? Fazemos divisão inteira ou divisão de ponto flutuante? A divisão inteira joga fora o resto; por exemplo, `5 / 2` é `2`. A divisão de ponto flutuante é diferente pois não há resto a ser jogado fora; por exemplo, `5.0 / 2.0` é `2.5`. Segue-se que a resposta mais óbvia para a pergunta "2.5 / 2 é divisão inteira ou de ponto flutuante?" é "Ponto flutuante, é claro: caso contrário perderíamos informação". Preferiríamos a resposta `1.25` em vez de `1`, e `1.25` é o que obtemos.

A regra (para os tipos que apresentamos até agora) é que se um operador tem um operando do tipo `double`, usamos aritmética de ponto flutuante produzindo um resultado `double`; caso contrário, usamos aritmética inteira produzindo um resultado `int`. Por exemplo:
*   `5 / 2` é `2` (não `2.5`)
*   `2.5 / 2` significa `2.5 / double(2)`, ou seja, `1.25`
*   `'a' + 1` significa `int('a') + 1`

In other words, if necessary, o compilador converte ("promove") operandos `int` para `doubles` ou operandos `char` para `int`. Uma vez que o resultado foi calculado, o compilador pode ter que convertê-lo (novamente) para usá-lo como um inicializador ou o lado direito de uma atribuição. Por exemplo:

```cpp
double d = 2.5;
int i = 2;
double d2 = d / i;  // d2 == 1.25
int i2 = d / i;     // i2 == 1
d2 = d / i;         // d2 == 1.25
i2 = d / i;         // i2 == 1
```

Cuidado que é fácil esquecer a divisão inteira em uma expressão que também contém operandos de ponto flutuante. Considere a fórmula usual para converter graus Celsius para graus Fahrenheit: $f = 9/5 * c + 32$. Poderíamos escrever:

```cpp
double dc;
cin >> dc;
double df = 9 / 5 * dc + 32; // cuidado!
```

Infelizmente, mas de forma bastante lógica, isso não representa uma conversão precisa de escala de temperatura: o valor de `9 / 5` é `1` em vez de `1.8` que poderíamos ter esperado. Para tornar o código matematicamente correto, ou o `9` ou o `5` (ou ambos) terão que ser convertidos em um `double`. Por exemplo:

```cpp
double dc;
cin >> dc;
double df = 9.0 / 5 * dc + 32; // melhor
```

---

## 4.4 Instruções (Statements)

Uma expressão computa um valor a partir de um conjunto de operandos usando operadores como os mencionados no §4.3. O que fazemos quando queremos produzir vários valores? Quando queremos fazer algo muitas vezes? Quando queremos escolher entre alternativas? Quando queremos obter entrada ou produzir saída? Em C++, como em muitas linguagens, você usa construções de linguagem chamadas **instruções** (*statements*) para expressar essas coisas.

Até agora, vimos dois tipos de instruções: **instruções de expressão** e **declarações**. Uma instrução de expressão é simplesmente uma expressão seguida por um ponto e vírgula. Por exemplo:

```cpp
a = b;
++b;
```

Essas são duas instruções de expressão. Note que a atribuição `=` é um operador, de modo que `a = b` é uma expressão e precisamos do ponto e vírgula final para tornar `a = b;` uma instrução. Por que precisamos desses pontos e vírgulas? A razão é amplamente técnica. Considere:

`a = b ++ b; // erro de sintaxe: faltam pontos e vírgula`

Sem o ponto e vírgula, o compilador não sabe se queremos dizer `a = b++; b;` ou `a = b; ++b;`. Esse tipo de problema não se restringe a linguagens de computador; considere a exclamação "homem comendo tigre!" Quem está comendo quem? A pontuação existe para eliminar tais problemas, por exemplo, "homem-comendo-tigre!"

Quando instruções seguem uma à outra, o computador as executa na ordem em que foram escritas. Por exemplo:

```cpp
int a = 7;
cout << a << '\n';
```

Aqui a declaração, com sua inicialização, é executada antes da instrução de expressão de saída.

Em geral, queremos que uma instrução tenha algum efeito. Instruções sem efeito são tipicamente inúteis. Por exemplo:

```cpp
1 + 2; // faz uma adição, mas não usa a soma
a * b; // faz uma multiplicação, mas não usa o produto
```

Tais instruções sem efeitos são tipicamente erros lógicos, e os compiladores frequentemente alertam contra elas. Assim, instruções de expressão são tipicamente atribuições, instruções de I/O ou chamadas de função.

Mencionaremos mais um tipo de instrução: a **"instrução vazia"**. Considere o código:

```cpp
if (x == 5);
{ y = 3; }
```

Isso parece um erro, e quase certamente é. O `;` na primeira linha não deveria estar lá. Mas, infelizmente, esta é uma construção legal em C++. Ela é chamada de **instrução vazia**, uma instrução que não faz nada. Uma instrução vazia antes de um ponto e vírgula raramente é útil. Neste caso, ela tem a consequência infeliz de permitir que o que é quase certamente um erro seja aceitável para o compilador, de modo que ele não o alertará sobre o erro e você terá muito mais dificuldade em encontrá-lo.

O que acontecerá se este código for executado? O compilador testará `x` para ver se ele tem o valor 5. Se esta condição for verdadeira, a instrução seguinte (a instrução vazia) será executada, sem efeito. Então o programa continua para a próxima linha, atribuindo o valor 3 a `y` (que é o que você queria que acontecesse se `x` fosse igual a 5). Se, por outro lado, `x` não tiver o valor 5, o compilador não executará a instrução vazia (ainda sem efeito) e continuará como antes para atribuir o valor 3 a `y` (o que **não** é o que você queria que acontecesse, a menos que `x` fosse igual a 5). Em outras palavras, o `if-statement` não importa; `y` vai receber o valor 3 independentemente. Este é um erro comum para programadores novatos, e pode ser difícil de detectar, portanto, fique atento.

A próxima seção é dedicada às instruções usadas para alterar a ordem de avaliação para nos permitir expressar computações mais interessantes do que aquelas que obtemos apenas executando instruções na ordem em que foram escritas.

---

### 4.4.1 Seleção

Em programas, como na vida, frequentemente temos que selecionar entre alternativas. Em C++, isso é feito usando uma instrução `if` ou uma instrução `switch`.

#### 4.4.1.1 Instruções if

A forma mais simples de seleção é uma instrução `if`, que seleciona entre duas alternativas. Por exemplo:

```cpp
int main()
{
    int a = 0;
    int b = 0;
    cout << "Por favor, insira dois inteiros\n";
    cin >> a >> b;
    if (a < b) // condição
        // 1ª alternativa (tomada se a condição for verdadeira):
        cout << "max(" << a << ", " << b << ") é " << b << "\n";
    else
        // 2ª alternativa (tomada se a condição for falsa):
        cout << "max(" << a << ", " << b << ") é " << a << "\n";
}
```

Uma instrução `if` escolhe entre duas alternativas. Se sua condição for verdadeira, a primeira instrução é executada; caso contrário, a segunda instrução é. Essa noção é simples. A maioria dos recursos básicos de linguagem de programação é. Na verdade, a maioria das facilidades básicas em uma linguagem de programação é apenas uma nova notação para coisas que você aprendeu no ensino fundamental — ou até antes disso. Por exemplo, provavelmente lhe disseram no jardim de infância que, para atravessar a rua em um semáforo, você tinha que esperar pelo sinal verde: "Se o sinal estiver verde, vá" e "Se o sinal estiver vermelho, espere". Em C++ isso se torna algo como:

`if (traffic_light == green) go();`

e

`if (traffic_light == red) wait();`

Então, a noção básica é simples, mas também é fácil usar instruções `if` de uma maneira simplória demais. Considere o que está errado com este programa (além de omitir o `#include` como de costume):

```cpp
// converter de polegadas para centímetros ou de centímetros para polegadas
// um sufixo 'i' ou 'c' indica a unidade da entrada

int main()
{
    const double cm_per_inch = 2.54; // número de centímetros em uma polegada
    double length = 1;               // comprimento em polegadas ou centímetros
    char unit = 0;
    cout << "Por favor, insira um comprimento seguido de uma unidade (c ou i):\n";
    cin >> length >> unit;
    if (unit == 'i')
        cout << length << "in == " << cm_per_inch * length << "cm\n";
    else
        cout << length << "cm == " << length / cm_per_inch << "in\n";
}
```

Na verdade, este programa funciona aproximadamente como anunciado: insira `1i` e você obterá `1in == 2.54cm`; insira `2.54c` e obterá `2.54cm == 1in`. Apenas tente; é uma boa prática.

O problema é que não testamos entradas ruins. O programa assume que o usuário insere uma entrada adequada. A condição `unit == 'i'` distingue entre o caso onde a unidade é 'i' e todos os outros casos. Ele nunca procura por um 'c'.

E se o usuário inserisse `15f` (para *feet* - pés) "apenas para ver o que acontece"? A condição `(unit == 'i')` falharia e o programa executaria a parte `else` (a segunda alternativa), convertendo de centímetros para polegadas. Presumivelmente, não era isso o que queríamos quando inserimos 'f'.

Devemos sempre testar nossos programas com entradas "ruins", porque alguém eventualmente — intencionalmente ou acidentalmente — inserirá uma entrada ruim. Um programa deve se comportar de forma sensata mesmo que seus usuários não o façam.

Aqui está uma versão melhorada:

```cpp
// converter de polegadas para centímetros ou de centímetros para polegadas
// um sufixo 'i' ou 'c' indica a unidade da entrada
// qualquer outro sufixo é um erro

int main()
{
    const double cm_per_inch = 2.54;
    double length = 1;
    char unit = ' '; // um espaço não é uma unidade
    cout << "Por favor, insira um comprimento seguido de uma unidade (c ou i):\n";
    cin >> length >> unit;
    if (unit == 'i')
        cout << length << "in == " << cm_per_inch * length << "cm\n";
    else if (unit == 'c')
        cout << length << "cm == " << length / cm_per_inch << "in\n";
    else
        cout << "Sinto muito, não conheço uma unidade chamada '" << unit << "'\n";
}
```

Nós primeiro testamos `unit == 'i'` e depois `unit == 'c'` e, se não for nenhum dos dois, dizemos "Sinto muito". Pode parecer que usamos uma "instrução else-if", mas não existe tal coisa em C++. Em vez disso, combinamos duas instruções `if`. A forma geral de uma instrução `if` é:

`if ( expressão ) instrução else instrução`

Ou seja, um `if` seguido por uma expressão entre parênteses seguido por uma instrução seguido por um `else` seguido por uma instrução. O que fizemos foi usar uma instrução `if` como a parte `else` de uma instrução `if`:

`if ( expressão ) instrução else if ( expressão ) instrução else instrução`

Para o nosso programa, isso dá esta estrutura:

```cpp
if (unit == 'i')
    // 1ª alternativa
else if (unit == 'c')
    // 2ª alternativa
else
    // 3ª alternativa
```

Dessa forma, podemos escrever testes arbitrariamente complexos e associar uma instrução com cada alternativa. No entanto, por favor, lembre-se de que um dos ideais para o código é a simplicidade, em vez da complexidade. Você não demonstra sua inteligência escrevendo o programa mais complexo. Em vez disso, você demonstra competência escrevendo o código mais simples que realiza o trabalho.

---

### TENTE ISSO
Use o exemplo acima como modelo para um programa que converte ienes (yen), euros e libras (*pounds*) em dólares. Se você gosta de realismo, pode encontrar as taxas de conversão na web.

---

#### 4.4.1.2 Instruções switch

Na verdade, a comparação de `unit` com 'i' e com 'c' é um exemplo da forma mais comum de seleção: uma seleção baseada na comparação de um valor contra várias constantes. Tal seleção é tão comum que o C++ fornece uma instrução especial para ela: a instrução `switch`. Podemos reescrever nosso exemplo como:

```cpp
int main()
{
    const double cm_per_inch = 2.54;
    double length = 1;
    char unit = 'a';
    cout << "Por favor, insira um comprimento seguido de uma unidade (c ou i):\n";
    cin >> length >> unit;
    switch (unit) {
    case 'i':
        cout << length << "in == " << cm_per_inch * length << "cm\n";
        break;
    case 'c':
        cout << length << "cm == " << length / cm_per_inch << "in\n";
        break;
    default:
        cout << "Sinto muito, não conheço uma unidade chamada '" << unit << "'\n";
        break;
    }
}
```

A sintaxe da instrução `switch` é arcaica, mas ainda mais clara do que instruções `if` aninhadas, especialmente quando comparamos contra muitas constantes. O valor apresentado entre parênteses após o `switch` é comparado a um conjunto de constantes. Cada constante é apresentada como parte de um rótulo `case`. Se o valor for igual à constante em um rótulo `case`, a instrução para esse caso é escolhida. Cada caso é terminado por um `break`. Se o valor não corresponder a nenhum dos rótulos `case`, a instrução identificada pelo rótulo `default` é escolhida. Você não precisa fornecer um `default`, mas é uma boa ideia fazê-lo, a menos que tenha certeza absoluta de que listou cada alternativa. Se você ainda não sabe, a programação lhe ensinará que é difícil ter certeza absoluta (e estar certo) sobre qualquer coisa.

---

#### 4.4.1.3 Tecnicidades do Switch

Aqui estão alguns detalhes técnicos sobre instruções `switch`:

1.  O valor sobre o qual fazemos o `switch` deve ser de um tipo **inteiro**, **char** ou **enumeração** (§9.5). Em particular, você não pode fazer um `switch` sobre uma `string`.
2.  Os valores nos rótulos `case` devem ser **expressões constantes** (§4.3.1). Em particular, você não pode usar uma variável em um rótulo `case`.
3.  Você não pode usar o mesmo valor para dois rótulos `case`.
4.  Você pode usar vários rótulos `case` para um único caso.
5.  **Não esqueça de terminar cada caso com um `break`.** Infelizmente, o compilador não o alertará se você esquecer.

Por exemplo:

```cpp
int main() // você pode fazer switch apenas em inteiros, etc.
{
    cout << "Você gosta de peixe?\n";
    string s;
    cin >> s;
    switch (s) { // erro: o valor deve ser de tipo inteiro, char ou enum
    case "não":
        // ...
        break;
    case "sim":
        // ...
        break;
    }
}
```

Para selecionar com base em uma `string`, você tem que usar uma instrução `if` ou um `map` (Capítulo 21).

Uma instrução `switch` gera código otimizado para comparar contra um conjunto de constantes. Para conjuntos maiores de constantes, isso tipicamente produz um código mais eficiente do que uma coleção de instruções `if`. No entanto, isso significa que os valores dos rótulos `case` devem ser constantes e distintos. Por exemplo:

```cpp
// rótulos case devem ser constantes
int main()
{
    // definir alternativas:
    int y = 'y'; // isso vai causar problemas
    const char n = 'n';
    const char m = 'm';
    cout << "Você gosta de peixe?\n";
    char a;
    cin >> a;
    switch (a) {
    case n:
        // ...
        break;
    case y: // erro: variável no rótulo case
        // ...
        break;
    case m:
        // ...
        break;
    case 'n': // erro: rótulo case duplicado (o valor de n é 'n')
        // ...
        break;
    default:
        // ...
        break;
    }
}
```

Frequentemente você quer a mesma ação para um conjunto de valores em um `switch`. Seria tedioso repetir a ação, então você pode rotular uma única ação com um conjunto de rótulos `case`. Por exemplo:

```cpp
int main() // você pode rotular uma instrução com vários rótulos case
{
    cout << "Por favor, insira um dígito\n";
    char a;
    cin >> a;
    switch (a) {
    case '0': case '2': case '4': case '6': case '8':
        cout << "é par\n";
        break;
    case '1': case '3': case '5': case '7': case '9':
        cout << "é ímpar\n";
        break;
    default:
        cout << "não é um dígito\n";
        break;
    }
}
```

O erro mais comum com instruções `switch` é esquecer de terminar um caso com um `break`. Por exemplo:

```cpp
int main() // exemplo de código ruim (falta um break)
{
    const double cm_per_inch = 2.54;
    double length = 1;
    char unit = 'a';
    cout << "Por favor, insira um comprimento seguido de uma unidade (c ou i):\n";
    cin >> length >> unit;
    switch (unit) {
    case 'i':
        cout << length << "in == " << cm_per_inch * length << "cm\n";
    case 'c':
        cout << length << "cm == " << length / cm_per_inch << "in\n";
    }
}
```

Infelizmente, o compilador aceitará isso e, quando você terminar o `case 'i'`, você simplesmente "cairá" (*drop through*) no `case 'c'`, de modo que se você inserir `2i`, o programa produzirá:

`2in == 5.08cm`
`2cm == 0.787402in`

Você foi avisado!

---

### TENTE ISSO
Reescreva seu programa conversor de moedas do "Tente Isso" anterior para usar uma instrução `switch`. Adicione conversões de yuan e coroas (*kroner*). Qual versão do programa é mais fácil de escrever, entender e modificar? Por quê?

---

### 4.4.2 Iteração

Raramente fazemos algo apenas uma vez. Portanto, as linguagens de programação fornecem maneiras convenientes de fazer algo várias vezes. Isso é chamado de **repetição** ou — especialmente quando você faz algo para uma série de elementos de uma estrutura de dados — **iteração**.

#### 4.4.2.1 Instruções while

Como um exemplo de iteração, considere o primeiro programa a rodar em um computador de programa armazenado (o EDSAC). Ele foi escrito e executado por David Wheeler no laboratório de informática da Universidade de Cambridge, Inglaterra, em 6 de maio de 1949, para calcular e imprimir uma lista simples de quadrados como esta:

```
0   0
1   1
2   4
3   9
4   16
...
98  9604
99  9801
```

Cada linha é um número seguido por um caractere de "tabulação" (`'\t'`), seguido pelo quadrado do número. Uma versão em C++ se parece com isto:

```cpp
// calcular e imprimir uma tabela de quadrados de 0-99
int main()
{
    int i = 0; // começa do 0
    while (i < 100) {
        cout << i << '\t' << square(i) << '\n';
        ++i;   // incrementa i (ou seja, i torna-se i+1)
    }
}
```

A notação `square(i)` simplesmente significa o quadrado de `i`. Explicaremos mais tarde como ela chega a significar isso (§4.5).

Não, este primeiro programa moderno não foi realmente escrito em C++, mas a lógica era como a mostrada aqui:
1. Começamos com 0.
2. Vemos se chegamos a 100 e, se sim, terminamos.
3. Caso contrário, imprimimos o número e seu quadrado, separados por uma tabulação (`'\t'`), aumentamos o número e tentamos novamente.

Claramente, para fazer isso precisamos de:
*   Uma maneira de repetir alguma instrução (um loop).
*   Uma variável para acompanhar quantas vezes passamos pelo loop (uma **variável de loop** ou uma **variável de controle**), aqui o `int` chamado `i`.
*   Um inicializador para a variável de loop, aqui `0`.
*   Um critério de terminação, aqui, que queremos passar pelo loop 100 vezes.
*   Algo para fazer a cada vez no loop (o **corpo** do loop).

A construção de linguagem que usamos é chamada de instrução `while`. Logo após sua palavra-chave distintiva, `while`, ela tem uma condição "no topo" seguida pelo seu corpo:

```cpp
while (i < 100) // a condição do loop testando a variável de loop i
{
    cout << i << '\t' << square(i) << '\n';
    ++i; // incrementa a variável de loop i
}
```

O corpo do loop é um bloco (delimitado por chaves) que escreve uma linha da tabela e incrementa a variável de loop, `i`. Começamos cada passagem pelo loop testando se `i < 100`. Se sim, ainda não terminamos e podemos executar o corpo do loop. Se chegamos ao fim, ou seja, se `i` é 100, saímos da instrução `while` e executamos o que vem a seguir. Neste programa, o fim do programa é o próximo passo, então saímos do programa.

A variável de loop para uma instrução `while` deve ser definida e inicializada fora (antes) da instrução `while`. Se falharmos em defini-la, o compilador nos dará um erro. Se a definirmos, mas falharmos em inicializá-la, a maioria dos compiladores nos avisará, dizendo algo como "variável local i não definida", mas estaria disposta a nos deixar executar o programa se insistíssemos. **Não insista!** Os compiladores estão quase certamente certos quando avisam sobre variáveis não inicializadas. Variáveis não inicializadas são uma fonte comum de erros. Neste caso, escrevemos:

`int i = 0; // começa do 0`

então está tudo bem.

Basicamente, escrever um loop é simples. Acertá-lo para problemas do mundo real pode ser complicado, porém. Em particular, pode ser difícil expressar a condição corretamente e inicializar todas as variáveis para que o loop comece corretamente.

---

### TENTE ISSO
O caractere 'b' é `char('a'+1)`, 'c' é `char('a'+2)`, etc. Use um loop para escrever uma tabela de caracteres com seus valores inteiros correspondentes:
```
a   97
b   98
...
z   122
```

---

#### 4.4.2.2 Blocos

Note como agrupamos as duas instruções que o `while` tinha que executar:

```cpp
while (i < 100) {
    cout << i << '\t' << square(i) << '\n';
    ++i; // incrementa i (ou seja, i torna-se i+1)
}
```

Uma sequência de instruções delimitada por chaves `{` e `}` é chamada de **bloco** ou uma **instrução composta**. Um bloco é um tipo de instrução. O bloco vazio `{ }` é às vezes útil para expressar que nada deve ser feito. Por exemplo:

```cpp
if (a <= b) {
    // não faz nada
}
else {
    // troca a e b
    int t = a;
    a = b;
    b = t;
}
```

---

#### 4.4.2.3 Instruções for

Iterar sobre uma sequência de números é tão comum que o C++, como a maioria das outras linguagens de programação, tem uma sintaxe especial para isso. Uma instrução `for` é como uma instrução `while`, exceto que o gerenciamento da variável de controle é concentrado no topo, onde é fácil de ver e entender. Poderíamos ter escrito o "primeiro programa" assim:

```cpp
// calcular e imprimir uma tabela de quadrados de 0-99
int main()
{
    for (int i = 0; i < 100; ++i)
        cout << i << '\t' << square(i) << '\n';
}
```

Isso significa: "Execute o corpo com `i` começando em 0, incrementando `i` após cada execução do corpo até chegarmos a 100". Uma instrução `for` é sempre equivalente a alguma instrução `while`. Neste caso:

```cpp
for (int i = 0; i < 100; ++i)
    cout << i << '\t' << square(i) << '\n';
```

significa:

```cpp
{
    int i = 0; // o inicializador da instrução for
    while (i < 100) { // a condição da instrução for
        cout << i << '\t' << square(i) << '\n'; // o corpo da instrução for
        ++i; // o incremento da instrução for
    }
}
```

Alguns novatos preferem instruções `while` e alguns novatos preferem instruções `for`. No entanto, usar uma instrução `for` produz um código mais facilmente compreendido e mais manutenível sempre que um loop puder ser definido como uma instrução `for` com um inicializador simples, condição e operação de incremento. Use uma instrução `while` apenas quando esse não for o caso.

**Nunca modifique a variável de loop dentro o corpo de uma instrução `for`.** Isso violaria a suposição razoável de cada leitor sobre o que um loop está fazendo. Considere:

```cpp
int main()
{
    for (int i = 0; i < 100; ++i) { // para i no intervalo [0:100)
        cout << i << '\t' << square(i) << '\n';
        // o que está acontecendo aqui? Cheira a erro!
        ++i;
    }
}
```

Qualquer um que olhasse para este loop assumiria razoavelmente que o corpo seria executado 100 vezes. No entanto, não é. O `++i` no corpo garante que `i` seja incrementado duas vezes a cada volta do loop, de modo que obtemos uma saída apenas para os 50 valores pares de `i`. Se víssemos tal código, assumiríamos que é um erro, provavelmente causado por uma conversão desleixada de um loop `while`. Se você quiser incrementar de 2 em 2, diga isso:

```cpp
// calcular e imprimir uma tabela de quadrados de números pares no intervalo [0:100)
int main()
{
    for (int i = 0; i < 100; i += 2)
        cout << i << '\t' << square(i) << '\n';
}
```

Por favor, note que a versão mais limpa e explícita é mais curta do que a bagunçada. Isso é típico.

---

### TENTE ISSO
Reescreva o exemplo o valor do caractere o "Tente Isso" anterior para usar um loop `for`. Em seguida, modifique seu programa para também obter uma tabela dos valores inteiros para letras maiúsculas e dígitos.

---

## 4.5 Funções

No programa acima, o que era `square(i)`? É uma chamada de uma função. Em particular, é uma chamada da função chamada `square` com o argumento `i`. Uma **função** é uma sequência nomeada de instruções. Uma função pode retornar um resultado (também chamado de **valor de retorno**). A biblioteca padrão fornece muitas funções úteis, como a função de raiz quadrada `sqrt()` que usamos no §3.4. No entanto, escrevemos muitas funções nós mesmos. Aqui está uma definição plausível de `square`:

```cpp
int square(int x)
{
    return x * x; // retorna o quadrado de x
}
```

A primeira linha desta definição nos diz que esta é uma função (é isso que os parênteses significam), que ela é chamada `square`, que ela recebe um argumento `int` (aqui, chamado `x`) e que ela retorna um `int` (o tipo do resultado sempre vem primeiro em uma declaração de função); ou seja, podemos usá-la assim:

```cpp
int main()
{
    cout << square(2) << '\n';  // imprime 4
    cout << square(10) << '\n'; // imprime 100
}
```

Não temos que usar o resultado de uma chamada de função (mas se não quiséssemos o resultado, por que a chamaríamos?), mas temos que dar a uma função exatamente os argumentos que ela exige. Considere:

```cpp
square(2);            // provavelmente um erro: valor de retorno não usado
int v1 = square();    // erro: falta argumento
int v2 = square;      // erro: faltam parênteses
int v3 = square(1,2); // erro: muitos argumentos
int v4 = square("dois"); // erro: tipo errado de argumento - esperado int
```

Muitos compiladores avisam contra resultados não usados, e todos dão erros como indicado. Você pode pensar que um computador deve ser inteligente o suficiente para descobrir que pela string `"dois"` você realmente quis dizer o inteiro 2. No entanto, um compilador C++ deliberadamente não é tão inteligente. É trabalho do compilador fazer exatamente o que você manda ele fazer, após verificar que seu código está bem formado de acordo com a definição de C++. Se o compilador adivinhasse o que você quis dizer, ele ocasionalmente adivinharia errado, e você — ou os usuários do seu programa — ficariam bastante irritados. Você achará difícil o suficiente prever o que seu código fará sem ter o compilador "ajudando você" ao tentar adivinhar suas intenções.

O **corpo da função** é o bloco (§4.4.2.2) que realmente faz o trabalho:

`return x * x; // retorna o quadrado de x`

Para `square`, o trabalho é trivial: produzimos o quadrado do argumento e retornamos isso como nosso resultado. Dizer isso em C++ é mais fácil do que dizer em português. Isso é típico para ideias simples. Afinal, uma linguagem de programação é projetada para declarar tais ideias simples de forma simples e precisa.

A sintaxe de uma definição de função pode ser descrita assim:

`tipo identificador ( lista-de-parâmetros ) corpo-da-função`

Ou seja, um tipo (o tipo de retorno), seguido por um identificador (o nome da função), seguido por uma lista de parâmetros entre parênteses, seguido pelo corpo da função (as instruções a serem executadas). A lista de argumentos exigida pela função é chamada de **lista de parâmetros** e seus elementos são chamados de **parâmetros** (ou **argumentos formais**). A lista de parâmetros pode estar vazia e, se não quisermos retornar um resultado, damos `void` (que significa "nada") como o tipo de retorno. Por exemplo:

```cpp
// não recebe argumento; não retorna valor
void write_sorry()
{
    cout << "Sinto muito\n";
}
```

Os aspectos técnico-linguísticos das funções serão examinados mais detalhadamente no Capítulo 8.

---

### 4.5.1 Por que se incomodar com funções?

Definimos uma função quando queremos uma computação separada com um nome porque fazê-lo:
*   Torna a computação logicamente separada.
*   Torna o texto do programa mais claro (ao dar nome à computação).
*   Torna possível usar a função em mais de um lugar em nosso programa.
*   Facilita os testes.

Veremos muitos exemplos de cada uma dessas razões conforme avançarmos, e mencionaremos ocasionalmente uma razão. Note que programas do mundo real usam milhares de funções, alguns até centenas de milhares. Obviamente, nunca seríamos capazes de escrever ou entender tais programas se suas partes (ex: computações) não fossem claramente separadas e nomeadas. Além disso, você logo descobrirá que muitas funções são repetidamente úteis e você logo se cansaria de repetir suas definições. Por exemplo, você poderia estar feliz escrevendo `x * x` e `7 * 7` e `(x + 7) * (x + 7)`, etc., em vez de `square(x)` e `square(7)` e `square(x + 7)`, etc. No entanto, isso é apenas porque `square` é uma computação muito simples. Considere a raiz quadrada (chamada `sqrt` em C++): você prefere escrever `sqrt(x)` e `sqrt(7)` e `sqrt(x + 7)`, etc., em vez de repetir o código (um tanto complicado e com muitas linhas de extensão) para computar a raiz quadrada. Melhor ainda: você não tem nem que olhar para a computação da raiz quadrada porque saber que `sqrt(x)` dá a raiz quadrada de `x` é suficiente.

No §8.5 abordaremos muitas tecnicidades de funções, mas por enquanto, daremos apenas outro exemplo. Se quiséssemos tornar o loop no `main()` realmente simples, poderíamos ter escrito:

```cpp
void print_square(int v)
{
    cout << v << '\t' << v * v << '\n';
}

int main()
{
    for (int i = 0; i < 100; ++i)
        print_square(i);
}
```

Por que não usamos essa versão usando `print_square()`? Essa versão não é significativamente mais simples do que a versão usando `square()`, e note que:
*   `print_square()` é uma função bastante especializada que não poderíamos esperar ser capaz de usar mais tarde, enquanto `square()` é um candidato óbvio para outros usos.
*   `square()` dificilmente requer documentação, enquanto `print_square()` obviamente precisa de explicação.

A razão subjacente para ambos é que `print_square()` realiza duas ações logicamente separadas:
1. Ela imprime.
2. Ela calcula um quadrado.

Programas são geralmente mais fáceis de escrever e de entender se cada função realizar uma única ação lógica. Basicamente, a versão `square()` é o melhor design.

Finalmente, por que usamos `square(i)` em vez de simplesmente `i * i` na primeira versão do problema? Bem, um dos propósitos das funções é simplificar o código ao separar cálculos complicados como funções nomeadas e, para a versão do programa de 1949, não havia hardware que implementasse diretamente a "multiplicação". Consequentemente, na versão do programa de 1949, `i * i` era na verdade um cálculo bastante complicado, similar ao que você faria à mão usando um pedaço de papel. Além disso, o autor daquela versão original, David Wheeler, foi o inventor da função (então chamada de sub-rotina) na computação moderna, então parecia apropriado usá-la aqui.

---

### TENTE ISSO
Implemente `square()` sem usar o operador de multiplicação; ou seja, faça o `x * x` por adição repetida (comece uma variável `result` em 0 e adicione `x` a ela `x` vezes). Em seguida, execute alguma versão do "primeiro programa" usando esse `square()`.

---

### 4.5.2 Declarações de função

Você notou que toda a informação necessária para chamar uma função estava na primeira linha de sua definição? Por exemplo:

`int square(int x)`

Dado isso, sabemos o suficiente para dizer:

`int x = square(44);`

Não precisamos realmente olhar para o corpo da função. Em programas reais, na maioria das vezes não queremos olhar para um corpo de função. Por que quereríamos olhar para o corpo da função `sqrt()` da biblioteca padrão? Sabemos que ela calcula a raiz quadrada de seu argumento. Por que quereríamos ver o corpo da nossa função `square()`? Claro que poderíamos apenas estar curiosos. Mas quase todo o tempo, estamos apenas interessados em saber como chamar uma função — ver a definição seria apenas uma distração. Felizmente, o C++ fornece uma maneira de fornecer essa informação separada da definição completa da função. Ela é chamada de **declaração de função**:

```cpp
int square(int);    // declaração de square
double sqrt(double); // declaração de sqrt
```

Note os pontos e vírgulas finais. Um ponto e vírgula é usado em uma declaração de função em vez do corpo usado na definição de função correspondente:

```cpp
int square(int x) // definição de square
{
    return x * x;
}
```

Então, se você apenas quiser usar uma função, você simplesmente escreve — ou mais comumente `#include` — sua declaração. A definição da função pode estar em outro lugar. Discutiremos onde esse "outro lugar" pode estar no §8.3 e §8.7. Esta distinção entre declarações e definições torna-se essencial em programas maiores, onde usamos declarações para manter a maior parte do código fora de vista para nos permitir concentrar em uma única parte do programa de cada vez (§4.2).

---

## 4.6 Vector

Para fazer quase qualquer coisa de interesse em um programa, precisamos de uma coleção de dados para trabalhar. Por exemplo, podemos precisar de uma lista de números de telefone, uma lista de membros de um time de futebol, uma lista de cursos, uma lista de livros lidos no último ano, um catálogo de músicas para download, um conjunto de opções de pagamento para um carro, uma lista de previsões meteorológicas para a próxima semana, uma lista de preços para uma câmera em diferentes lojas da web, etc. As possibilidades são literalmente infinitas e, portanto, onipresentes em programas. Veremos uma variedade de maneiras de armazenar coleções de dados (uma variedade de **contêineres** de dados; veja Capítulos 20 e 21). Aqui começaremos com uma das maneiras mais simples e, sem dúvida, a mais útil de armazenar dados: um `vector`.

Um vetor é simplesmente uma sequência de elementos que você pode acessar por um índice. Por exemplo, aqui está um vetor chamado `v`:

v: [ 0 | 1 | 2 | 3 | 4 | 5 ]  
   [ 5 | 7 | 9 | 4 | 6 | 8 ] (valores)
