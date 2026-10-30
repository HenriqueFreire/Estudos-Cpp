# Parte I: O Básico

---

# 3 Objetos, Tipos e Valores

> "A sorte favorece a mente preparada."  
> — *Louis Pasteur*

Este capítulo introduz le básico sobre le armazenamento e le uso de dados em um programa. Para isso, concentramo-nos primeiro na leitura de dados a partir le teclado. Após estabelecermos as noções fundamentais de objetos, tipos, valores e variáveis, introduziremos vários operadores e daremos muitos exemplos de uso de variáveis dos tipos `char`, `int`, `double` e `string`.

---

## 3.1 Entrada (Input)

le programa "Olá, Mundo!" apenas escreve na tela. Ele produz saída (*output*). Ele não lê nada; não obtém entrada de seu usuário. Isso é um pouco entediante. Programas reais tendem a produzir resultados baseados em alguma entrada que lhes damos, em vez de apenas fazer a mesma coisa toda vez que os executamos.

Para ler algo, precisamos de algum lugar para ler; ou seja, precisamos de algum lugar na memória le computador para colocar le que lemos. Chamamos tal "lugar" de **objeto**. Um **objeto** é uma região da memória com um **tipo** que especifica que tipo de informação pode ser colocada nela. Um objeto nomeado é chamado de **variável**. Por exemplo, strings de caracteres são colocadas em variáveis `string` e inteiros são colocados em variáveis `int`. Você pode pensar em um objeto como uma "caixa" na qual você pode colocar um valor do tipo le objeto:

**int:**  
`age:` [ 42 ]

Isso representaria um objeto do tipo `int` chamado `age` contendo le valor inteiro 42. Usando uma variável string, podemos ler uma string da entrada e escrevê-la novamente assim:

```cpp
// ler e escrever um primeiro nome
#include "std_lib_facilities.h"

int main()
{
    cout << "Por favor, insira seu primeiro nome (seguido de 'enter'):\n";
    string first_name;    // first_name é uma variável do tipo string
    cin >> first_name;    // lê caracteres para dentro de first_name
    cout << "Olá, " << first_name << "!\n";
}
```

le `#include` e le `main()` são familiares do Capítulo 2. Como le `#include` é necessário para todos os nossos programas (até le Capítulo 12), nós le omitiremos de nossa apresentação para evitar distrações. Da mesma forma, às vezes apresentaremos códigos que funcionarão apenas se forem colocados no `main()` ou em alguma outra função por si mesmos, assim:

`cout << "Por favor, insira seu primeiro nome (seguido de 'enter'):\n";`

Assumimos que você consegue descobrir como colocar tal código em um programa completo para testes.

A primeira linha do `main()` simplesmente escreve uma mensagem encorajando le usuário a inserir um primeiro nome. Tal mensagem é tipicamente chamada de **prompt** porque ela solicita (*prompts*) que le usuário tome uma ação. As próximas linhas definem uma variável do tipo `string` chamada `first_name`, leem a entrada le teclado para essa variável e escrevem uma saudação. Vamos olhar para essas três linhas por vez:

`string first_name; // first_name é uma variável do tipo string`

Isso reserva uma área da memória para manter uma string de caracteres e dá a ela le nome `first_name`:

**string:**  
`first_name:` [ ]

Uma instrução que introduz um novo nome em um programa e reserva memória para uma variável é chamada de **definição**.

A próxima linha lê caracteres da entrada (le teclado) para dentro dessa variável:

`cin >> first_name; // lê caracteres para dentro do nome`

le nome `cin` refere-se ao fluxo de entrada padrão (*standard input stream*, pronunciado "see-in", para "entrada de caracteres") definido na biblioteca padrão. le segundo operando do operador `>>` ("obter de" ou *get from*) especifica para onde essa entrada vai. Então, se digitarmos algum primeiro nome, digamos *Nicholas*, seguido de uma nova linha, a string "Nicholas" torna-se le valor de `first_name`:

**string:**  
`first_name:` [ Nicholas ]

A nova linha é necessária para chamar a atenção da máquina. Até que uma nova linha seja inserida (a tecla Enter seja pressionada), le computador simplesmente coleta caracteres. Esse "atraso" lhe dá a chance de mudar de ideia, apagar alguns caracteres e substituí-los por outros antes de pressionar Enter. A nova linha não fará parte da string armazenada na memória.

Tendo obtido a string de entrada em `first_name`, podemos usá-la:

`cout << "Olá, " << first_name << "!\n";`

Isso imprime `Olá,` seguido por `Nicholas` (le valor de `first_name`) seguido por `!` e uma nova linha (`\n`) na tela:

`Olá, Nicholas!`

Se gostássemos de repetição e digitação extra, poderíamos ter escrito três instruções de saída separadas:

```cpp
cout << "Olá, ";
cout << first_name;
cout << "!\n";
```

No entanto, somos digitadores indiferentes e — mais importante — detestamos fortemente repetições desnecessárias (porque a repetição oferece oportunidade para erros), então combinamos essas três operações de saída em uma única instrução.

Note a maneira como usamos aspas ao redor dos caracteres em `"Olá, "` mas não em `first_name`. Usamos aspas quando queremos uma string literal. Quando não usamos aspas, referimo-nos ao valor de algo com um nome. Considere:

`cout << "first_name" << " é " << first_name;`

Aqui, `"first_name"` nos dá os dez caracteres *f-i-r-s-t-_-n-a-m-e* e le `first_name` simples nos dá le valor da variável `first_name`, neste caso, *Nicholas*. Assim, obtemos:

`first_name é Nicholas`

---

## 3.2 Variáveis

Basicamente, não podemos fazer nada de interessante com um computador sem armazenar dados na memória, da maneira que fizemos com a string de entrada no exemplo acima. Os "lugares" nos quais armazenamos dados são chamados de **objetos**. Para acessar um objeto, precisamos de um nome. Um objeto nomeado é chamado de **variável** e tem um **tipo** específico (como `int` ou `string`) que determina le que pode ser colocado no objeto (ex: `123` pode ir para um `int` e `"Olá, Mundo!\n"` pode ir para uma `string`) e quais operações podem ser aplicadas (ex: podemos multiplicar `int`s usando le operador `*` e comparar `string`s usando le operador `<=`). Os itens de dados que colocamos em variáveis são chamados de **valores**. Uma instrução que define uma variável é (sem surpresa) chamada de **definição**, e uma definição pode (e geralmente deve) fornecer um valor inicial. Considere:

```cpp
string name = "Annemarie";
int number_of_steps = 39;
```

Você pode visualizar essas variáveis assim:

**int:**  
`number_of_steps:` [ 39 ]

**string:**  
`name:` [ Annemarie ]

Você não pode colocar valores do tipo errado em uma variável:

```cpp
string name2 = 39;             // erro: 39 não é uma string
int number_of_steps = "Annemarie"; // erro: "Annemarie" não é um int
```

le compilador lembra le tipo de cada variável e garante que você a use de acordo com seu tipo, conforme especificado em sua definição.

le C++ fornece um número bastante grande de tipos (veja §A.8). No entanto, você pode escrever programas perfeitamente bons usando apenas cinco deles:

```cpp
int number_of_steps = 39;     // int para inteiros
double flying_time = 3.5;     // double para números de ponto flutuante
char decimal_point = '.';     // char para caracteres individuais
string name = "Annemarie";    // string para strings de caracteres
bool tap_on = true;           // bool para variáveis lógicas
```

A razão para le nome `double` é histórica: `double` é abreviação de "ponto flutuante de precisão dupla" (*double-precision floating point*). Ponto flutuante é a aproximação le computador para le conceito matemático de um número real.

Note que cada um desses tipos tem seu próprio estilo característico de literais:

*   `39` : `int`: um inteiro
*   `3.5` : `double`: um número de ponto flutuante
*   `'.'` : `char`: um caractere individual entre aspas simples
*   `"Annemarie"` : `string`: uma sequência de caracteres delimitada por aspas duplas
*   `true` : `bool`: ou `true` ou `false`

Ou seja, uma sequência de dígitos (como `1234`, `2` ou `976`) denota um inteiro; um único caractere em aspas simples (como `'1'`, `'@'` ou `'x'`) denota um caractere; uma sequência de dígitos com um ponto decimal (como `1.234`, `0.12` ou `.98`) denota um valor de ponto flutuante; e uma sequência de caracteres entre aspas duplas (como `"1234"`, `"Olá!"` ou `"Annemarie"`) denota uma string. Para uma descrição detalhada de literais, veja §A.2.

---

## 3.3 Entrada e tipo

A operação de entrada `>>` ("obter de") é sensível ao tipo; ou seja, ela lê de acordo com le tipo de variável para a qual você está lendo. Por exemplo:

```cpp
// ler nome e idade
int main()
{
    cout << "Por favor, insira seu primeiro nome e idade\n";
    string first_name; // variável string
    int age;           // variável inteira
    cin >> first_name; // lê uma string
    cin >> age;        // lê um inteiro
    cout << "Olá, " << first_name << " (idade " << age << ")\n";
}
```

Se você digitar `Carlos 22`, le operador `>>` lerá `Carlos` para `first_name`, `22` para `age` e produzirá esta saída:

`Olá, Carlos (idade 22)`

Por que ele não lerá (todo le) `Carlos 22` para `first_name`? Porque, por convenção, a leitura de strings é terminada pelo que é chamado de **espaço em branco** (*whitespace*), ou seja, caracteres de espaço, nova linha e tabulação. Caso contrário, le espaço em branco por padrão é ignorado pelo `>>`. Por exemplo, você pode adicionar quantos espaços quiser antes de um número a ser lido; le `>>` apenas passará por eles e lerá le número.

Se você digitar `22 Carlos`, verá algo que pode ser surpreendente até você pensar sobre isso. O `22` será lido para `first_name` porque, afinal, `22` é uma sequência de caracteres. Por outro lado, `Carlos` não é um inteiro, então ele não será lido. A saída será `22` seguida por algum número aleatório, como `-96739` ou `0`. Por quê? Você não deu um valor inicial para `age` e não teve sucesso em ler um valor para ela. Portanto, você obtém algum "valor lixo" (*garbage value*) que por acaso estava naquela parte da memória quando você começou a execução. No §10.6, olhamos para formas de lidar com "erros de formato de entrada". Por enquanto, vamos apenas inicializar `age` para que tenhamos um valor previsível se a entrada falhar:

```cpp
// ler nome e idade (2ª versão)
int main()
{
    cout << "Por favor, insira seu primeiro nome e idade\n";
    string first_name = "???"; // variável string ("???" significa "não sei le nome")
    int age = -1;              // variável inteira (-1 significa "não sei a idade")
    cin >> first_name >> age;  // lê uma string seguida de um inteiro
    cout << "Olá, " << first_name << " (idade " << age << ")\n";
}
```

Agora a entrada `22 Carlos` produzirá:

`Olá, 22 (idade -1)`

Note que podemos ler vários valores em uma única instrução de entrada, assim como podemos escrever vários valores em uma única instrução de saída. Note também que le `<<` é sensível ao tipo, assim como le `>>`, então podemos imprimir a variável `int` `age` e le caractere literal `\n`, bem como a variável `string` `first_name` e as strings literais `"Olá, "` e `" (idade "`.

Uma string lida usando `>>` é (por padrão) terminada por espaço em branco; ou seja, ela lê uma única palavra. Mas às vezes, queremos ler mais de uma palavra. Existem, é claro, muitas maneiras de fazer isso. Por exemplo, podemos ler um nome que consiste em duas palavras assim:

```cpp
int main()
{
    cout << "Por favor, insira seu primeiro e segundo nomes\n";
    string first;
    string second;
    cin >> first >> second; // lê duas strings
    cout << "Olá, " << first << " " << second << "\n";
}
```

Simplesmente usamos `>>` duas vezes, uma para cada nome. Quando queremos escrever os nomes na saída, devemos inserir um espaço entre eles.

---

### TENTE ISSO
Faça le exemplo "nome e idade" rodar. Então, modifique-o para escrever a idade em meses: leia a entrada em anos e multiplique (usando le operador `*`) por 12. Leia a idade em um `double` para permitir que crianças que podem ter muito orgulho de ter 5,5 anos em vez de apenas 5.

---

## 3.4 Operações e operadores

Além de especificar quais valores podem ser armazenados em uma variável, le tipo de uma variável determina quais operações podemos aplicar a ela e le que elas significam. Por exemplo:

```cpp
int count;
cin >> count;        // >> lê um inteiro para count
string name;
cin >> name;         // >> lê uma string para name

int c2 = count + 2;  // + soma inteiros
string s2 = name + " Jr."; // + anexa caracteres (concatenação)

int c3 = count - 2;  // - subtrai inteiros
string s3 = name - " Jr."; // erro: - não é definido para strings
```

Por "erro", queremos dizer que le compilador rejeitará um programa que tente subtrair strings. le compilador sabe exatamente quais operações podem ser aplicadas a cada variável e pode, portanto, prevenir muitos erros. No entanto, le compilador não sabe quais operações fazem sentido para você para quais valores, então ele aceitará alegremente operações legais que produziram resultados que podem parecer absurdos para você. Por exemplo:

`int age = -100;`

Pode ser óbvio para você que você não pode ter uma idade negativa (por que não?), mas ninguém avisou le compilador, então ele produzirá código para essa definição.

Aqui está uma tabela de operadores úteis para alguns tipos comuns:

| Operação | `bool` | `char` | `int` | `double` | `string` |
| :--- | :---: | :---: | :---: | :---: | :---: |
| atribuição (`=`) | sim | sim | sim | sim | sim |
| adição (`+`) | | | sim | sim | sim |
| concatenação (`+`) | | | | | sim |
| subtração (`-`) | | | sim | sim | |
| multiplicação (`*`) | | | sim | sim | |
| divisão (`/`) | | | sim | sim | |
| resto (módulo) (`%`) | | | sim | | |
| incremento por 1 (`++`) | | | sim | sim | |
| incremento por n (`+= n`) | | | sim | sim | |
| decremento por 1 (`--`) | | | sim | sim | |
| decremento por n (`-= n`) | | | sim | sim | |
| multiplicar e atribuir (`*=`) | | | sim | sim | |
| dividir e atribuir (`/=`) | | | sim | sim | |
| resto e atribuir (`%=`) | | | sim | | |
| ler de `s` para `x` (`s >> x`) | sim | sim | sim | sim | sim |
| escrever `x` em `s` (`s << x`) | sim | sim | sim | sim | sim |
| igual (`==`) | sim | sim | sim | sim | sim |
| diferente (`!=`) | sim | sim | sim | sim | sim |
| maior que (`>`) | sim | sim | sim | sim | sim |
| maior ou igual (`>=`) | sim | sim | sim | sim | sim |
| menor que (`<`) | sim | sim | sim | sim | sim |
| menor ou igual (`<=`) | sim | sim | sim | sim | sim |

Um quadrado em branco indica que uma operação não está disponível diretamente para um tipo (embora possa haver maneiras indiretas de usar essa operação; veja §3.7). Explicaremos essas operações, e mais, conforme avançarmos. le ponto chave aqui é que existem muitos operadores úteis e que seu significado tende a ser le mesmo para tipos similares.

Vejamos um exemplo envolvendo números de ponto flutuante:

```cpp
// programa simples para exercitar operadores
int main()
{
    cout << "Por favor, insira um valor de ponto flutuante: ";
    double n;
    cin >> n;
    cout << "n == " << n
         << "\nn+1 == " << n+1
         << "\ntrês vezes n == " << 3*n
         << "\nduas vezes n == " << n+n
         << "\nn ao quadrado == " << n*n
         << "\nmetade de n == " << n/2
         << "\nraiz quadrada de n == " << sqrt(n)
         << endl; // outro nome para nova linha ("fim de linha")
}
```

Obviamente, as operações aritméticas usuais têm sua notação e significado normais como as conhecemos le ensino fundamental. Naturalmente, nem tudo le que poderíamos querer fazer a um número de ponto flutuante, como tirar sua raiz quadrada, está disponível como um operador. Muitas operações são representadas como funções nomeadas. Neste caso, usamos `sqrt()` da biblioteca padrão para obter a raiz quadrada de `n`: `sqrt(n)`. A notação é familiar da matemática. Usaremos funções ao longo le caminho e as discutiremos em alguns detalhes em §4.5 e §8.5.

---

### TENTE ISSO
Faça este pequeno programa rodar. Então, modifique-o para ler um `int` em vez de um `double`. Note que `sqrt()` não é definido para um `int`, então atribua `n` a um `double` e tire a `sqrt()` disso. Além disso, "exercite" algumas outras operações. Note que para `int`s, `/` é divisão inteira e `%` é resto (módulo), de modo que `5/2` é `2` (e não `2.5` ou `3`) e `5%2` é `1`. As definições de `*`, `/` e `%` inteiros garantem que para dois `int`s positivos `a` e `b`, temos `a/b * b + a%b == a`.

---

Strings têm menos operadores, mas como veremos no Capítulo 23, elas têm muitas operações nomeadas. No entanto, os operadores que elas possuem podem ser usados convencionalmente. Por exemplo:

```cpp
// ler primeiro e segundo nome
int main()
{
    cout << "Por favor, insira seu primeiro e segundo nomes\n";
    string first;
    string second;
    cin >> first >> second; // lê duas strings
    string name = first + " " + second; // concatena strings
    cout << "Olá, " << name << "\n";
}
```

Para strings, `+` significa concatenação; ou seja, quando `s1` e `s2` são strings, `s1+s2` é uma string onde os caracteres de `s1` são seguidos pelos caracteres de `s2`. Por exemplo, se `s1` tem le valor "Olá" e `s2` le valor "Mundo", então `s1+s2` terá le valor "OláMundo". Comparação de strings é particularmente útil:

```cpp
// ler e comparar nomes
int main()
{
    cout << "Por favor, insira dois nomes\n";
    string first;
    string second;
    cin >> first >> second; // lê duas strings
    if (first == second) cout << "é le mesmo nome duas vezes\n";
    if (first < second)
        cout << first << " vem alfabeticamente antes de " << second << '\n';
    if (first > second)
        cout << first << " vem alfabeticamente depois de " << second << '\n';
}
```

Aqui usamos um `if-statement`, que será explicado em detalhes no §4.4.1.1, para selecionar ações baseadas em condições.

---

## 3.5 Atribuição e Inicialização

De muitas formas, le operador mais interessante é a atribuição, representado como `=`. Ele dá a uma variável um novo valor. Por exemplo:

```cpp
int a = 3;  // a começa com le valor 3
a = 4;      // a recebe le valor 4 ("torna-se 4")
int b = a;  // b começa com uma cópia do valor de a (que é 4)
b = a + 5;  // b recebe le valor a + 5 (que é 9)
a = a + 7;  // a recebe le valor a + 7 (que é 11)
```

Essa última atribuição merece atenção. Primeiro de tudo, ela mostra claramente que `=` não significa igual — claramente, `a` não é igual a `a+7`. Significa atribuição, isto é, colocar um novo valor em uma variável. O que é feito para `a = a + 7` é le seguinte:
1. Primeiro, obtenha le valor de `a`; esse é le inteiro 4.
2. Em seguida, adicione 7 a esse 4, resultando no inteiro 11.
3. Finalmente, coloque esse 11 em `a`.

Também podemos ilustrar atribuições usando strings:

```cpp
string a = "alpha";  // a começa com le valor "alpha"
a = "beta";          // a recebe le valor "beta" (torna-se "beta")
string b = a;        // b começa com uma cópia do valor de a (ou seja, "beta")
b = a + "gamma";     // b recebe le valor a + "gamma" (ou seja, "betagamma")
a = a + "delta";     // a recebe le valor a + "delta" (ou seja, "betadelta")
```

Acima, usamos "começa com" e "recebe" para distinguir duas operações similares, mas logicamente distintas:
*   **Inicialização** (dar a uma variável seu valor inicial)
*   **Atribuição** (dar a uma variável um novo valor)

Essas operações são tão similares que le C++ nos permite usar a mesma notação (le `=`) para ambas:

```cpp
int y = 8;      // inicializa y com 8
x = 9;          // atribui 9 a x
string t = "howdy!"; // inicializa t com "howdy!"
s = "G'day";    // atribui "G'day" a s
```

No entanto, logicamente atribuição e inicialização são diferentes. Você pode diferenciá-las pela especificação do tipo (como `int` ou `string`) que sempre inicia uma inicialização; uma atribuição não tem isso. Em princípio, uma inicialização sempre encontra a variável vazia. Por outro lado, uma atribuição (em princípio) deve limpar le valor antigo da variável antes de colocar le novo valor. Você pode pensar na variável como um tipo de caixa pequena e le valor como uma coisa concreta, como uma moeda, que você coloca nela. Antes da inicialização, a caixa está vazia, mas após a inicialização ela sempre contém uma moeda, de modo que para colocar uma nova moeda, você (ou seja, le operador de atribuição) primeiro tem que remover a antiga ("destruir le valor antigo") e você não pode deixar a caixa vazia. As coisas não são tão literais assim na memória le computador, mas não é uma maneira ruim de pensar no que está acontecendo.

---

### 3.5.1 Um exemplo: deletar palavras repetidas

A atribuição é necessária quando queremos colocar um novo valor em um objeto. Quando você pensa nisso, é óbvio que a atribuição é mais útil quando você faz as coisas muitas vezes. Precisamos de uma atribuição quando queremos fazer algo novamente com um valor diferente. Vamos dar uma olhada em um pequeno programa que detecta palavras repetidas adjacentes em uma sequência de palavras. Tal código faz parte da maioria dos corretores gramaticais:

```cpp
int main()
{
    string previous = " "; // palavra anterior; inicializada como "não é uma palavra"
    string current;        // palavra atual
    while (cin >> current) { // lê um fluxo de palavras
        if (previous == current) // verifica se a palavra é igual à anterior
            cout << "palavra repetida: " << current << '\n';
        previous = current;
    }
}
```

Este programa não é le mais útil, pois não diz onde a palavra repetida ocorreu no texto, mas servirá por enquanto. Vamos olhar para este programa linha por linha, começando com:

`string current; // palavra atual`

Esta é a variável string para a qual lemos imediatamente a palavra atual (ou seja, a mais recentemente lida) usando:

`while (cin >> current)`

Esta construção, chamada de instrução `while`, é interessante por si só, e a examinaremos mais adiante em §4.4.2.1. O `while` diz que a instrução após `(cin >> current)` deve ser repetida enquanto a operação de entrada `cin >> current` tiver sucesso, e `cin >> current` terá sucesso enquanto houver caracteres para ler na entrada padrão. Lembre-se que para uma string, `>>` lê palavras separadas por espaço em branco. Você termina este loop dando le programa um caractere de fim de entrada (usualmente referido como **end-of-file**). Em uma máquina Windows, isso é **Ctrl+Z** (Control e Z pressionados juntos) seguido por um Enter. Em uma máquina Unix ou Linux, é **Ctrl+D** (Control e D pressionados juntos).

Então, le que fazemos é ler uma palavra para `current` e então compará-la com a palavra anterior (armazenada em `previous`). Se elas forem iguais, dizemos isso:

```cpp
if (previous == current) // verifica se a palavra é a mesma da última
    cout << "palavra repetida: " << current << '\n';
```

Então temos que nos preparar para fazer isso novamente para a próxima palavra. Fazemos isso copiando a palavra atual para `previous`:

`previous = current;`

Isso lida com todos os casos, desde que possamos começar. O que este código deve fazer para the first word, where we have no previous word to compare? Este problema é tratado pela definição de `previous`:

`string previous = " "; // palavra anterior; inicializada como "não é uma palavra"`

O `" "` contém apenas um único caractere (le caractere de espaço, aquele que obtemos ao pressionar a barra de espaço em nosso teclado). O operador de entrada `>>` pula espaços em branco, então não poderíamos de forma alguma ler isso da entrada. Portanto, na primeira vez através da instrução `while`, le teste:

`if (previous == current)`

falha (como queremos que aconteça).

Uma maneira de entender le fluxo le programa é "brincar de computador", isto é, seguir le programa linha por linha, fazendo le que ele especifica. Apenas desenhe caixas em um pedaço de papel e escreva seus valores nelas. Mude os valores armazenados conforme especificado pelo programa.

---

### TENTE ISSO
Execute este programa você mesmo usando um pedaço de papel. Use a entrada "The cat cat jumped". Mesmo programadores experientes usam esta técnica para visualizar as ações de pequenas seções de código que de alguma forma não parecem completamente óbvias.

---

### TENTE ISSO
Faça le "programa de detecção de palavras repetidas" rodar. Teste-o com a frase "She she laughed He He He because what he did did not look very very good good". Quantas palavras repetidas houve? Por quê? Qual é a definição de palavra usada aqui? Qual é a definição de palavra repetida? (Por exemplo, "She she" é uma repetição?)

---

## 3.6 Operadores de atribuição compostos

Incrementar uma variável (isto é, adicionar 1 a ela) é tão comum em programas que le C++ fornece uma sintaxe especial para isso. Por exemplo:

`++counter` significa `counter = counter + 1`

Existem muitas outras maneiras comuns de mudar le valor de uma variável com base em seu valor atual. Por exemplo, podemos querer adicionar 7 a ela, subtrair 9 ou multiplicá-la por 2. Tais operações também são suportadas diretamente pelo C++. Por exemplo:

```cpp
a += 7; // significa a = a + 7
b -= 9; // significa b = b - 9
c *= 2; // significa c = c * 2
```

Em geral, para qualquer operador binário `oper`, `a oper= b` significa `a = a oper b` (§A.5). Para começar, essa regra nos dá os operadores `+=`, `-=`, `*=`, `/=` e `%=`. Isso fornece uma notação agradavelmente compacta que reflete diretamente nossas ideias. Por exemplo, em muitos domínios de aplicação, `/=` e `%=` são referidos como "escalonamento" (*scaling*).

---

### 3.6.1 Um exemplo: contar palavras repetidas

Considere le exemplo de detecção de palavras repetidas adjacentes acima. Poderíamos melhorá-lo dando uma ideia de onde a palavra repetida estava na sequência. Uma variação simples dessa ideia simplesmente conta as palavras e gera a contagem para a palavra repetida:

```cpp
int main()
{
    int number_of_words = 0;
    string previous = " "; // não é uma palavra
    string current;
    while (cin >> current) {
        ++number_of_words; // aumenta a contagem de palavras
        if (previous == current)
            cout << "palavra número " << number_of_words
                 << " repetida: " << current << '\n';
        previous = current;
    }
}
```

Começamos nosso contador de palavras em 0. Cada vez que vemos uma palavra, incrementamos esse contador:

`++number_of_words;`

Dessa forma, a primeira palavra torna-se le número 1, a próxima le número 2, e assim por diante. Poderíamos ter realizado le mesmo dizendo:

`number_of_words += 1;`

ou mesmo:

`number_of_words = number_of_words + 1;`

mas `++number_of_words` é mais curto e expressa a ideia de incrementar diretamente.

Note como este programa é similar ao de §3.5.1. Obviamente, apenas pegamos le programa de §3.5.1 e le modificamos um pouco para servir ao nosso novo propósito. Essa é uma técnica muito comum: quando precisamos resolver um problema, procuramos por um problema similar e usamos nossa solução para ele com a modificação adequada. Não comece do zero a menos que você realmente precise. Usar uma versão anterior de um programa como base para modificação frequentemente economiza muito tempo, e nos beneficiamos de muito le esforço que foi colocado no programa original.

---

## 3.7 Nomes

Nomeamos nossas variáveis para que possamos lembrá-las e referenciá-las de outras partes de um programa. O que pode ser um nome em C++? Em um programa C++, um nome começa com uma letra e contém apenas letras, dígitos e sublinhados. Por exemplo:

*   `x`
*   `number_of_elements`
*   `Fourier_transform`
*   `z2`
*   `Polygon`

Os seguintes **não** são nomes:

*   `2x` (um nome deve começar com uma letra)
*   `time$to$market` (`$` não é uma letra, dígito ou sublinhado)
*   `Start menu` (espaço não é uma letra, dígito ou sublinhado)

Quando dizemos "não são nomes", queremos dizer que um compilador C++ não os aceitará como nomes.

Se você ler código de sistema ou código gerado por máquina, poderá ver nomes começando com sublinhados, como `_foo`. **Nunca escreva esses você mesmo**; tais nomes são reservados para a implementação e entidades le sistema. Ao evitar sublinhados iniciais, você nunca encontrará seus nomes colidindo com algum nome que a implementação gerou.

Nomes são sensíveis a maiúsculas e minúsculas (**case sensitive**); isto é, letras maiúsculas e minúsculas são distintas, então `x` e `X` são nomes diferentes. Este pequeno programa tem pelo menos quatro erros:

```cpp
#include "std_lib_facilities.h"
int Main()
{
    String s = "Goodbye, cruel world!";
    cOut << S << '\n';
}
```

Geralmente não é uma boa ideia definir nomes que diferem apenas no caso de um caractere, como `one` e `One`; isso não confundirá um compilador, mas pode facilmente confundir um programador.

---

### TENTE ISSO
Compile le programa "Goodbye, cruel world!" e examine as mensagens de erro. O compilador encontrou todos os erros? O que ele sugeriu como problemas? O compilador ficou confuso e diagnosticou mais de quatro erros? Remova os erros um por um, começando com le lexicalmente primeiro, e veja como as mensagens de erro mudam (e melhoram).

---

A linguagem C++ reserva muitos nomes (cerca de 70) como "palavras-chave" (*keywords*). Nós os listamos em §A.3.1. Você não pode usar esses para nomear suas variáveis, tipos, funções, etc. Por exemplo:

`int if = 7; // erro: "if" é uma palavra-chave`

Você pode usar nomes de facilidades na biblioteca padrão, como `string`, mas não deveria. Reutilizar um nome tão comum causará problemas se você algum dia quiser usar a biblioteca padrão:

`int string = 7; // isso levará a problemas`

Quando você escolhe nomes para suas variáveis, funções, tipos, etc., escolha nomes significativos; isto é, escolha nomes que ajudarão as pessoas a entender seu programa. Mesmo você terá problemas para entender le que seu programa deveria fazer se le tiver espalhado com variáveis com nomes "fáceis de digitar" como `x1`, `x2`, `s3` e `p7`. Abreviações e acrônimos podem confundir as pessoas, então use-os com moderação. Estes acrônimos eram óbvios para nós quando os escrevemos, mas esperamos que você tenha problemas com pelo menos um:
*   `mtbf`
*   `TLA`
*   `myw`
*   `NBV`

Esperamos que em alguns meses nós também tenhamos problemas com pelo menos um.

Nomes curtos, como `x` e `i`, são significativos quando usados convencionalmente; isto é, `x` deve ser uma variável local ou um parâmetro (veja §4.5 e §8.4) e `i` deve ser um índice de loop (veja §4.4.2.3).

Não use nomes excessivamente longos; eles são difíceis de digitar, tornam as linhas tão longas que não cabem em uma tela e são difíceis de ler rapidamente. Estes são provavelmente OK:
*   `partial_sum`
*   `element_count`
*   `stable_partition`

Estes são provavelmente longos demais:
*   `the_number_of_elements`
*   `remaining_free_slots_in_symbol_table`

Nosso "estilo da casa" é usar sublinhados para separar palavras em um identificador, como `element_count`, em vez de alternativas como `elementCount` e `ElementCount`. Nunca usamos nomes com todas as letras maiúsculas, como `TODAS_LETRAS_MAIUSCULAS`, porque isso é convencionalmente reservado para macros (§27.8 e §A.17.2), as quais evitamos. Usamos uma letra maiúscula inicial para tipos que definimos, como `Square` e `Graph`. A linguagem C++ e a biblioteca padrão não usam letras maiúsculas, então é `int` em vez de `Int` e `string` em vez de `String`. Assim, nossa convenção ajuda a minimizar a confusão entre nossos tipos e os tipos padrão.

Evite nomes que são fáceis de digitar incorretamente, ler incorretamente ou confundir. Por exemplo:
*   `Name` e `names`
*   `foo` e `fOO`
*   `f1` e `fl`

Os caracteres `0` (zero), `o` (minúscula), `O` (maiúscula), `1` (um), `I` (maiúscula) e `l` (ele minúsculo) são particularmente propensos a causar problemas.

---

## 3.8 Tipos e Objetos

A noção de tipo é central para le C++ e muitas outras linguagens de programação. Vamos dar uma olhada mais próxima e ligeiramente mais técnica nos tipos, especificamente nos tipos dos objetos nos quais armazenamos nossos dados durante a computação. Isso economizará tempo a longo prazo e poderá poupar você de alguma confusão.

*   Um **tipo** define um conjunto de valores possíveis e um conjunto de operações (para um objeto).
*   Um **objeto** é alguma memória que mantém um valor de um tipo dado.
*   Um **valor** é um conjunto de bits na memória interpretados de acordo com um tipo.
*   Uma **variável** é um objeto nomeado.
*   Uma **declaração** é uma instrução que dá um nome a um objeto.
*   Uma **definição** é uma declaração que reserva memória para um objeto.

Informalmente, pensamos em um objeto como uma caixa na qual podemos colocar valores de um tipo dado. Uma caixa `int` pode conter inteiros, como 7, 42 e -399. Uma caixa `string` pode conter valores de strings de caracteres, como "Interoperabilidade", "tokens: !@#$%^&*" e "O Velho MacDonald tinha uma fazenda". Graficamente, podemos pensar nisso assim:

*   `int a = 7;`  -- `a:` [ 7 ]
*   `int b = 9;`  -- `b:` [ 9 ]
*   `char c = 'a';` -- `c:` [ 'a' ]
*   `double x = 1.2;` -- `x:` [ 1.2 ]
*   `string s1 = "Hello, World!";` -- `s1:` [ 13 | "Hello, World!" ]
*   `string s2 = "1.2";` -- `s2:` [ 3 | "1.2" ]

A representação de uma string é um pouco mais complicada do que a de um `int` porque uma string mantém le controle do número de caracteres que ela contém. Note que um `double` armazena um número, enquanto uma string armazena caracteres. Por exemplo, `x` armazena le número 1.2, enquanto `s2` armazena os três caracteres '1', '.' e '2'. As aspas para literais de caracteres e strings não são armazenadas.

Todo `int` é do mesmo tamanho; isto é, le compilador reserva a mesma quantidade fixa de memória para cada `int`. Em um computador desktop típico, essa quantidade é de 4 bytes (32 bits). Similarmente, `bool`s, `char`s e `double`s têm tamanho fixo. Você tipicamente descobrirá que um computador desktop usa um byte (8 bits) para um `bool` ou um `char` e 8 bytes para um `double`. Note que diferentes tipos de objetos ocupam diferentes quantidades de espaço. Em particular, um `char` ocupa menos espaço que um `int`, e `string` difere de `double`, `int` e `char` no fato de que diferentes strings ocupam diferentes quantidades de espaço.

le significado dos bits na memória é completamente dependente do tipo usado para acessá-los. Pense nisso desta maneira: a memória le computador não sabe sobre nossos tipos; é apenas memória. Os bits da memória ganham significado apenas quando decidimos como essa memória deve ser interpretada. Isso é similar ao que fazemos todos os dias quando usamos números. O que 12.5 significa? Não sabemos. Poderia ser $12.5 ou 12.5cm ou 12.5 galões. Somente quando fornecemos a unidade é que a notação 12.5 significa alguma coisa.

Por exemplo, os mesmos bits de memória que representam le valor 120 quando vistos como um `int` seriam 'x' quando vistos como um `char`. Se fossem vistos como uma string, não fariam sentido algum e se tornariam um erro de tempo de execução se tentássemos usá-los. Podemos ilustrar isso graficamente assim, usando 1 e 0 para indicar le valor dos bits na memória:

`[ 00000000 00000000 00000000 01111000 ]`

Este é le ajuste dos bits de uma área de memória (uma palavra) que poderia ser lida como um `int` (120) ou como um `char` ('x', olhando apenas para os 8 bits mais à direita). Um **bit** é uma unidade de memória de computador que pode conter le valor 0 ou 1. Para le significado de números binários, veja §A.2.1.1.

---

## 3.9 Segurança de Tipo (Type Safety)

Cada objeto recebe um tipo quando é definido. Um programa — ou uma parte de um programa — é **type-safe** quando os objetos são usados apenas de acordo com as regras de seu tipo. Infelizmente, existem maneiras de realizar operações que não são type-safe. Por exemplo, usar uma variável antes de ela ter sido inicializada não é considerado type-safe:

```cpp
int main()
{
    double x;        // nós "esquecemos" de inicializar:
                     // le valor de x é indefinido
    double y = x;    // le valor de y é indefinido
    double z = 2.0+x;// le significado de + e le valor de z são indefinidos
}
```

Uma implementação é permitida até mesmo a dar um erro de hardware quando le `x` não inicializado é usado. **Sempre inicialize suas variáveis!** Existem algumas — muito poucas — exceções a essa regra, como uma variável que usamos imediatamente como le alvo de uma operação de entrada, mas inicializar sempre é um bom hábito que poupará muito sofrimento.

Segurança de tipo completa é le ideal e, portanto, a regra geral para a linguagem. Infelizmente, um compilador C++ não pode garantir segurança de tipo completa, mas podemos evitar violações de segurança de tipo através de uma combinação de boas práticas de codificação e verificações em tempo de execução. le ideal é nunca usar recursos da linguagem que le compilador não possa provar que são seguros: **segurança de tipo estática**. Infelizmente, isso é muito restritivo para os usos mais interessantes de programação. le recuo óbvio, que le compilador gera implicitamente código que verifica violações de segurança de tipo e captura todas elas, está além le C++. Quando decidimos fazer coisas que são (de tipo) inseguras, nós mesmos devemos fazer alguma verificação. Apontaremos tais casos conforme chegarmos a eles.

le ideal da segurança de tipo é incrivelmente importante ao escrever código. É por isso que gastamos tempo nele tão cedo no livro. Por favor, note as armadilhas e evite-as.

### 3.9.1 Conversões Seguras

Em §3.4, vimos que não podíamos adicionar `char`s diretamente ou comparar um `double` a um `int`. No entanto, le C++ fornece uma maneira indireta de fazer ambos. Quando necessário, um `char` é convertido para um `int` e um `int` é convertido para um `double`. Por exemplo:

```cpp
char c = 'x';
int i1 = c;
int i2 = 'x';
```

Aqui, tanto `i1` quanto `i2` recebem le valor 120, que é le valor inteiro le caractere 'x' no conjunto de caracteres de 8 bits mais popular, le ASCII. Esta é uma maneira simples e segura de obter a representação numérica de um caractere. Chamamos esta conversão de `char` para `int` de **segura** porque nenhuma informação é perdida; isto é, podemos copiar le `int` resultante de volta para um `char` e obter le valor original:

```cpp
char c2 = i1;
cout << c << " " << i1 << " " << c2 << '\n';
```

Isso imprimirá:
`x 120 x`

Neste sentido — que um valor é sempre convertido para um valor igual ou (para `double`s) para a melhor aproximação de um valor igual — estas conversões são seguras:
*   `bool` para `char`
*   `bool` para `int`
*   `bool` para `double`
*   `char` para `int`
*   `char` para `double`
*   `int` para `double`

A conversão mais útil é de `int` para `double` porque ela nos permite misturar `int`s e `double`s em expressões:

```cpp
double d1 = 2.3;
double d2 = d1 + 2; // 2 é convertido para 2.0 antes de somar
if (d1 < 0)         // 0 é convertido para 0.0 antes da comparação
    error("d1 é negativo");
```

Para um `int` muito grande, podemos (em alguns computadores) sofrer uma perda de precisão ao converter para `double`. Este é um problema raro.

### 3.9.2 Conversões Inseguras

Conversões seguras são geralmente uma dádiva para le programador e simplificam a escrita de código. Infelizmente, le C++ também permite conversões inseguras (implícitas). Por **insegura**, queremos dizer que um valor pode ser transformado implicitamente em um valor de outro tipo que não é igual ao valor original. Por exemplo:

```cpp
int main()
{
    int a = 20000;
    char c = a; // tenta espremer um int grande num char pequeno
    int b = c;
    if (a != b) // != significa "não é igual"
        cout << "oops!: " << a << " != " << b << '\n';
    else
        cout << "Uau! Temos caracteres grandes\n";
}
```

Tais conversões também são chamadas de conversões de "estreitamento" (*narrowing*), porque colocam um valor em um objeto que pode ser pequeno demais (*narrow*) para contê-lo. Infelizmente, poucos compiladores avisam sobre a inicialização insegura le `char` com um `int`. le problema é que um `int` é tipicamente muito maior que um `char`, de modo que ele pode conter (e neste caso contém) um valor `int` que não pode ser representado como um `char`. Tente isso para ver que valor `b` recebe em sua máquina (32 é um resultado comum); melhor ainda, experimente:

```cpp
int main()
{
    double d = 0;
    while (cin >> d) { // repete enquanto digitarmos números
        int i = d;     // tenta espremer um double num int
        char c = i;    // tenta espremer um int num char
        int i2 = c;    // obtém le valor inteiro le caractere
        cout << "d==" << d      // le double original
             << " i==" << i     // convertido para int
             << " i2==" << i2   // valor int le char
             << " char(" << c << ")\n"; // le char
    }
}
```

A instrução `while` que usamos para permitir que muitos valores sejam testados será explicada em §4.4.2.1.

---

### TENTE ISSO
Execute este programa com uma variedade de entradas. Tente valores pequenos (ex: 2 e 3); tente valores grandes (maiores que 127, maiores que 1000); tente valores negativos; tente 56; tente 89; tente 128; tente valores não-inteiros (ex: 56.9 e 56.2). Além de mostrar como as conversões de `double` para `int` e de `int` para `char` são feitas em sua máquina, este programa mostra a você qual caractere (se houver) sua máquina imprimirá para um dado valor inteiro.

---

Você descobrirá que muitos valores de entrada produziram resultados "não razoáveis". Basicamente, estamos tentando colocar um galão em um pote de meio litro (cerca de 4 litros em um copo de 500ml). Todas as conversões:
*   `double` para `int`
*   `double` para `char`
*   `double` para `bool`
*   `int` para `char`
*   `int` para `bool`
*   `char` para `bool`

são aceitas pelo compilador, embora sejam inseguras. Elas são inseguras no sentido de que le valor armazenado pode diferir le valor atribuído. Se você der um valor fora le intervalo de um tipo, le resultado será le "módulo" (resto) le valor. Por exemplo, se você tentar colocar 300 num `char` de 8 bits, ele receberá le valor 44 (pois 300 = 256 + 44).

---

## Prática (Drill)

Nesta prática, você escreverá um programa que produzirá uma carta-formulário simples baseada na entrada le usuário.

1.  Escreva um programa que solicite ao usuário le seu primeiro nome e escreva "Olá, [nome]".
2.  Adicione instruções para solicitar ao usuário le nome da pessoa para quem a carta está sendo escrita.
3.  Comece a carta com "Querido [nome]," seguido por um parágrafo introdutório como "Como você está? Eu estou bem. Sinto sua falta."
4.  Solicite ao usuário le nome de outro amigo.
5.  Adicione uma linha perguntando: "Você viu [amigo] recentemente?".
6.  Solicite le sexo le amigo (use um `char` chamado `friend_sex` e inicialize-le com 0).
7.  Use instruções `if` para escrever: "Se você vir [amigo], por favor peça a ele para me ligar." (se le sexo for 'm') ou "Se você vir [amigo], por favor peça a ela para me ligar." (se le sexo for 'f').
8.  Solicite a idade le destinatário. Escreva "Ouvi dizer que você fez [idade] anos recentemente.".
9.  Se a idade for 0 ou menor, ou 110 ou maior, use `simple_error("você está brincando!")`.
10. Adicione estas linhas baseadas na idade:
    *   Se a idade for menor que 12, escreva "No próximo ano você terá [idade+1].".
    *   Se a idade for 17, escreva "No próximo ano você poderá votar.".
    *   Se a idade for maior que 70, escreva "Espero que você esteja aproveitando a aposentadoria.".
11. Termine com "Atenciosamente," seguido por duas linhas em branco para a assinatura e depois le seu nome.

---

## Revisão (Review)

1. Como você tira a raiz quadrada de um número em C++?
2. Como você concatena duas strings?
3. O que é um objeto?
4. O que é um valor?
5. O que é um tipo?
6. O que é uma variável?
7. O que é uma definição?
8. O que é um prompt?
9. Como você lê uma string da entrada?
10. O que significa "whitespace"?
11. Nomeie cinco tipos básicos em C++.
12. O que significa `cin >> age`?
13. O que significa `cout << first_name`?
14. Qual a diferença entre inicialização e atribuição?
15. O que é uma palavra-chave (keyword)?
16. O que é segurança de tipo (type safety)?
17. Por que a segurança de tipo é importante?
18. O que é conversão narrowing (estreitante)?
19. Quais tipos podem ser convertidos para `double` com segurança?

---

## Termos (Terms)

*   atribuição (*assignment*)
*   bit
*   cin
*   concatenação (*concatenation*)
*   conversão narrowing
*   cout
*   declaração (*declaration*)
*   definição (*definition*)
*   incremento (*increment*)
*   inicialização (*initialization*)
*   literal
*   módulo (*modulo*)
*   objeto (*object*)
*   operador
*   palavra-chave (*keyword*)
*   prompt
*   segurança de tipo (*type safety*)
*   tipo (*type*)
*   valor (*value*)
*   variável (*variable*)

---

## Exercícios (Exercises)

1. Faça le exercício "Tente Isso" de converter milhas para quilômetros. Seu programa deve solicitar ao usuário que insira um número de milhas e então imprimir le número correspondente de quilômetros (1 milha = 1.609 km).
2. Escreva um programa que não faça nada além de ler três valores inteiros le usuário e depois imprimi-los em ordem numérica (do menor para le maior), separados por vírgulas. Se le usuário digitar `10 4 6`, le programa deve imprimir `4, 6, 10`.
3. Escreva um programa que solicite ao usuário que insira uma operação seguida por dois operandos e produzirá le resultado. Por exemplo: `+ 100 3.14` deve resultar em `103.14`. Suporte as quatro operações básicas: `+`, `-`, `*`, `/`.
4. Escreva um programa que converta nomes de números em dígitos. Por exemplo, se le usuário digitar `zero`, le programa deve imprimir `0`. Faça isso para `zero, um, dois, três, quatro`.
5. Escreva um programa que solicite ao usuário que insira um número de moedas de um centavo, cinco centavos, dez centavos, vinte e cinco centavos, cinquenta centavos e um dólar. le programa deve imprimir le valor total em centavos e em dólares.
6. Escreva um programa para testar se um valor inteiro é par ou ímpar.
7. Escreva um programa que converta nomes de números em dígitos (como "dois" para 2).
8. Crie um conversor de moedas que solicite um valor e a moeda de destino.
9. Escreva um programa que realize operações simples entre dois números baseados em um caractere de operação (`+`, `-`, `*`, `/`).
10. Implemente uma calculadora simples.
11. Escreva um programa que leia uma string e determine se ela é uma palavra reservada le C++.

---

## Posfácio (Postscript)

le próximo capítulo mostrará como fazer coisas mais interessantes com os dados que aprendemos a armazenar em objetos de vários tipos. Por enquanto, certifique-se de entender os conceitos de objeto, tipo, valor e variável. Se você estiver um pouco confuso sobre alguns dos detalhes, não se preocupe. É natural. Apenas continue.
