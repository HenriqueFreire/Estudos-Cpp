# Parte I: O Básico

---

# 2 Olá, Mundo!

> "Aprende-se programação escrevendo programas."  
> — *Brian Kernighan*

Aqui, apresentamos o programa em C++ mais simples que realmente faz alguma coisa. O propósito de escrever este programa é:

*   Deixar você testar seu ambiente de programação.
*   Dar a você uma primeira sensação de como você pode fazer um computador realizar coisas para você.

Assim, apresentamos a noção de um programa, a ideia de traduzir um programa de uma forma legível por humanos para instruções de máquina usando um compilador, e finalmente executar essas instruções de máquina.

---

## 2.1 Programas

Para fazer um computador fazer algo, você (ou outra pessoa) tem que dizer a ele exatamente — em detalhes excruciantes — o que fazer. Tal descrição de "o que fazer" é chamada de **programa**, e programação é a atividade de escrever e testar tais programas.

Em certo sentido, todos nós já programamos antes. Afinal, já demos descrições de tarefas a serem realizadas, como "como dirigir até o cinema mais próximo", "como encontrar o banheiro no andar de cima" e "como aquecer uma refeição no micro-ondas". A diferença entre tais descrições e programas é o grau de precisão: os seres humanos tendem a compensar instruções ruins usando o senso comum, mas os computadores não. Por exemplo, "vire à direita no corredor, suba as escadas, estará à sua esquerda" é provavelmente uma boa descrição de como chegar ao banheiro do andar de cima. No entanto, quando você olha para essas instruções simples, descobrirá que a gramática é desleixada e as instruções incompletas. Um humano compensa facilmente. Por exemplo, suponha que você esteja sentado à mesa e peça direções para o banheiro. Você não precisa ser instruído a se levantar da cadeira para chegar ao corredor, caminhar de alguma forma ao redor (e não por cima ou por baixo) da mesa, não pisar no gato, etc. Você não terá que ser instruído a não levar sua faca e garfo ou a lembrar de acender a luz para que possa ver as escadas. Abrir a porta do banheiro antes de entrar é provavelmente também algo que você não precisa ser instruído.

Em contraste, os computadores são realmente burros. Eles precisam ter tudo descrito com precisão e em detalhes. Considere novamente "vire à direita no corredor, suba as escadas, estará à sua esquerda". Onde está o corredor? O que é um corredor? O que é "vire à direita"? Quais escadas? Como subo escadas? (Um degrau de cada vez? Dois degraus? Escorregar pelo corrimão?) O que está à minha esquerda? Quando estará à minha esquerda? Para ser capaz de descrever "coisas" com precisão para um computador, precisamos de uma linguagem precisamente definida com uma gramática específica (o inglês é muito frouxamente estruturado para isso) e um vocabulário bem definido para os tipos de ações que queremos que sejam executadas. Tal linguagem é chamada de linguagem de programação, e o C++ é uma linguagem de programação projetada para uma ampla seleção de tarefas de programação.

Se você quiser mais detalhes filosóficos sobre computadores, programas e programação, (re)leia o Capítulo 1. Aqui, vamos dar uma olhada em algum código, começando com um programa muito simples e as ferramentas e técnicas que você precisa para fazê-lo rodar.

---

## 2.2 O primeiro programa clássico

Aqui está uma versão do clássico primeiro programa. Ele escreve "Hello, World!" na sua tela:

```cpp
// Este programa envia a mensagem "Hello, World!" para o monitor

#include "std_lib_facilities.h"

int main() // Programas C++ começam executando a função main
{
    // saída "Hello, World!"
    cout << "Hello, World!\n";
    return 0;
}
```

Pense neste texto como um conjunto de instruções que damos ao computador para executar, assim como daríamos uma receita para um cozinheiro seguir, ou como uma lista de instruções de montagem para seguirmos para fazer um novo brinquedo funcionar. Vamos discutir o que cada linha deste programa faz, começando pela linha:

`cout << "Hello, World!\n"; // saída "Hello, World!"`

Essa é a linha que realmente produz a saída. Ela imprime os caracteres `Hello, World!` seguidos por uma nova linha; ou seja, após escrever `Hello, World!`, o cursor será colocado no início da próxima linha. Um cursor é um pequeno caractere ou linha piscante que mostra onde você pode digitar o próximo caractere.

Em C++, literais de string são delimitados por aspas duplas (`"`); ou seja, `"Hello, World!\n"` é uma string de caracteres. O `\n` é um "caractere especial" que indica uma nova linha. O nome `cout` refere-se a um fluxo de saída padrão (*standard output stream*). Caracteres "colocados no `cout`" usando o operador de saída `<<` aparecerão na tela. O nome `cout` é pronunciado "see-out" e é uma abreviação de "character output stream". Você descobrirá que abreviações são bastante comuns na programação. Naturalmente, uma abreviação pode ser um pouco incômoda na primeira vez que você a vê e precisa lembrá-la, mas uma vez que você comece a usar abreviações repetidamente, elas se tornam uma segunda natureza, e são essenciais para manter o texto do programa curto e gerenciável.

O final dessa linha:

`// saída "Hello, World!"`

é um comentário. Qualquer coisa escrita após o token `//` (que é o caractere `/`, chamado "slash", duas vezes) em uma linha é um comentário. Comentários são ignorados pelo compilador e escritos para o benefício de programadores que leem o código. Aqui, usamos o comentário para dizer o que o início daquela linha realmente fez.

Comentários são escritos para descrever o que o programa pretende fazer e, em geral, para fornecer informações úteis para humanos que não podem ser expressas diretamente em código. A pessoa com maior probabilidade de se beneficiar dos comentários em seu código é você — quando você voltar a esse código na próxima semana, ou no próximo ano, e tiver esquecido exatamente por que escreveu o código da maneira que escreveu. Portanto, documente bem seus programas. No §7.6.4, discutiremos o que constitui bons comentários.

Um programa é escrito para dois públicos. Naturalmente, escrevemos código para computadores executarem. No entanto, passamos longas horas lendo e modificando o código. Assim, os programadores são outro público para os programas. Então, escrever código também é uma forma de comunicação de humano para humano. Na verdade, faz sentido considerar os leitores humanos de nosso código como nosso público principal: se eles (nós) não acharem o código razoavelmente fácil de entender, é improvável que o código venha a se tornar correto. Portanto, por favor, não se esqueça: o código é para leitura — faça tudo o que puder para torná-lo legível. De qualquer forma, os comentários são apenas para o benefício dos leitores humanos; o computador não olha para o texto nos comentários.

A primeira linha do programa é um comentário típico; ela simplesmente diz ao leitor humano o que o programa deve fazer:

`// Este programa envia a mensagem "Hello, World!" para o monitor`

Tais comentários são úteis porque o próprio código diz o que o programa faz, não o que pretendíamos que ele fizesse. Além disso, geralmente podemos explicar (grosseiramente) o que um programa deve fazer para um humano de forma muito mais concisa do que podemos expressá-lo (em detalhes) em código para um computador. Frequentemente, tal comentário é a primeira parte do programa que escrevemos. Se nada mais, ele nos lembra o que estamos tentando fazer.

A próxima linha:

`#include "std_lib_facilities.h"`

é uma "diretiva `#include`". Ela instrui o computador a disponibilizar ("incluir") facilidades de um arquivo chamado `std_lib_facilities.h`. Escrevemos esse arquivo para simplificar o uso das facilidades disponíveis em todas as implementações de C++ ("a biblioteca padrão C++"). Explicaremos seu conteúdo à medida que avançarmos. É C++ padrão perfeitamente comum, mas contém detalhes com os quais preferimos não incomodá-lo por mais uma dúzia de capítulos. Para este programa, a importância de `std_lib_facilities.h` é que disponibilizamos as facilidades de E/S de fluxo (*stream I/O*) padrão do C++. Aqui, apenas usamos o fluxo de saída padrão, `cout`, e seu operador de saída, `<<`. Um arquivo incluído usando `#include` geralmente tem o sufixo `.h` e é chamado de **header** (cabeçalho) ou **header-file**. Um header contém definições de termos, como `cout`, que usamos em nosso programa.

Como um computador sabe por onde começar a executar um programa? Ele procura por uma função chamada `main` e começa a executar as instruções que encontra lá. Aqui está a função `main` do nosso programa "Hello, World!":

```cpp
int main() // Programas C++ começam executando a função main
{
    cout << "Hello, World!\n"; // saída "Hello, World!"
    return 0;
}
```

Todo programa C++ deve ter uma função chamada `main` para dizer a ele por onde começar a execução. Uma função é basicamente uma sequência nomeada de instruções para o computador executar na ordem em que foram escritas. Uma função tem quatro partes:

*   Um **tipo de retorno** (return type), aqui `int` (que significa "inteiro"), que especifica que tipo de resultado, se houver, a função retornará para quem pediu que ela fosse executada. A palavra `int` é uma palavra reservada em C++ (uma palavra-chave), portanto `int` não pode ser usado como nome de mais nada (veja §A.3.1).
*   Um **nome**, aqui `main`.
*   Uma **lista de parâmetros** entre parênteses (veja §8.2 e §8.6), aqui `()`; neste caso, a lista de parâmetros está vazia.
*   Um **corpo da função** delimitado por um conjunto de "chaves", `{ }`, que lista as ações (chamadas de **instruções** ou *statements*) que a função deve realizar.

Segue-se que o programa C++ mínimo é simplesmente:

`int main() { }`

Isso não tem muita utilidade, porém, porque não faz nada. A função `main()` do nosso programa "Hello, World!" tem duas instruções em seu corpo:

```cpp
cout << "Hello, World!\n"; // saída "Hello, World!"
return 0;
```

Primeiro ela escreverá `Hello, World!` na tela, e depois retornará um valor `0` (zero) para quem a chamou. Como `main()` é chamada pelo "sistema", não usaremos esse valor de retorno. No entanto, em alguns sistemas (notavelmente Unix/Linux), ele pode ser usado para verificar se o programa teve sucesso. Um zero (0) retornado por `main()` indica que o programa terminou com sucesso.

Uma parte de um programa C++ que especifica uma ação e não é uma diretiva `#include` (ou alguma outra diretiva de pré-processador; veja §4.4 e §A.17) é chamada de **instrução** (*statement*).

---

## 2.3 Compilação

O C++ é uma linguagem compilada. Isso significa que, para fazer um programa rodar, você deve primeiro traduzi-lo da forma legível por humanos para algo que uma máquina possa "entender". Essa tradução é feita por um programa chamado **compilador**. O que você lê e escreve é chamado de **código-fonte** ou texto do programa, e o que o computador executa é chamado de **executável**, **código de objeto** ou **código de máquina**. Tipicamente, arquivos de código-fonte C++ recebem o sufixo `.cpp` (ex: `hello_world.cpp`) ou `.h` (como em `std_lib_facilities.h`), e arquivos de código de objeto recebem o sufixo `.obj` (no Windows) ou `.o` (no Unix). A palavra simples **código** é, portanto, ambígua e pode causar confusão; use-a com cuidado apenas quando for óbvio o que se quer dizer com ela. A menos que especificado de outra forma, usamos *código* para significar "código-fonte" ou mesmo "o código-fonte, exceto os comentários", porque os comentários realmente estão lá apenas para nós humanos e não são vistos pelo compilador que gera o código de objeto.

O compilador lê seu código-fonte e tenta dar sentido ao que você escreveu. Ele verifica se o seu programa está gramaticalmente correto, se cada palavra tem um significado definido e se há algo obviamente errado que possa ser detectado sem tentar realmente executar o programa. Você descobrirá que os computadores são bastante exigentes quanto à sintaxe. Deixar de fora qualquer detalhe de nosso programa, como um arquivo `#include`, um ponto e vírgula ou uma chave, causará erros. Da mesma forma, o compilador tem tolerância absolutamente zero para erros de ortografia. Permita-nos ilustrar isso com uma série de exemplos que possuem, cada um, um único pequeno erro. Cada erro é um exemplo de um tipo de erro que cometemos com frequência:

```cpp
// erro: falta o #include aqui
int main()
{
    cout << "Hello, World!\n";
    return 0;
}
```
Não incluímos algo para dizer ao compilador o que era `cout`, então o compilador reclama. Para corrigir isso, vamos adicionar um arquivo de cabeçalho:

```cpp
#include "std_facilities.h"
int main()
{
    cout << "Hello, World!\n";
    return 0;
}
```
Infelizmente, o compilador reclama novamente: escrevemos `std_lib_facilities.h` incorretamente. O compilador também objeta a isto:

```cpp
#include "std_lib_facilities.h"
int main()
{
    cout << "Hello, World!\n;
    return 0;
}
```
Não terminamos a string com uma `"`. O compilador também objeta a isto:

```cpp
#include "std_lib_facilities.h"
integer main()
{
    cout << "Hello, World!\n";
    return 0;
}
```
A abreviação `int` é usada em C++ em vez da palavra `integer`. O compilador também não gosta disto:

```cpp
#include "std_lib_facilities.h"
int main()
{
    cout < "Hello, World!\n";
    return 0;
}
```
Usamos `<` (o operador menor que) em vez de `<<` (o operador de saída). O compilador também objeta a isto:

```cpp
#include "std_lib_facilities.h"
int main()
{
    cout << 'Hello, World!\n';
    return 0;
}
```
Usamos aspas simples em vez de aspas duplas para delimitar a string. Finalmente, o compilador dá um erro para isto:

```cpp
#include "std_lib_facilities.h"
int main()
{
    cout << "Hello, World!\n"
    return 0;
}
```
Esquecemos de terminar a instrução de saída com um ponto e vírgula. Note que muitas instruções em C++ são terminadas por um ponto e vírgula (`;`). O compilador precisa desses pontos e vírgulas para saber onde uma instrução termina e a próxima começa. Não existe uma maneira realmente curta, totalmente correta e não técnica de resumir onde os pontos e vírgulas são necessários. Por enquanto, apenas copie nosso padrão de uso, que pode ser resumido como: "Coloque um ponto e vírgula após cada expressão que não termine com uma chave direita (`}`)."

Por que gastamos duas páginas de bom espaço e minutos de seu precioso tempo mostrando exemplos de erros triviais em um programa trivial? Para mostrar o ponto de que você — como todos os programadores — passará muito tempo procurando erros no texto fonte do programa. Na maioria das vezes, olhamos para textos com erros neles. Afinal, se estivéssemos convencidos de que algum código estava correto, normalmente estaríamos olhando para algum outro código ou tirando uma folga. Foi uma grande surpresa para os pioneiros da computação que eles estivessem cometendo erros e tivessem que dedicar uma parte importante de seu tempo para encontrá-los. Ainda é uma surpresa para a maioria dos recém-chegados à programação.

Ao programar, você ficará bastante irritado com o compilador às vezes. Às vezes, ele parece reclamar de detalhes sem importância (como um ponto e vírgula faltando) ou de coisas que você considera "obviamente certas". No entanto, o compilador geralmente está certo: quando ele dá uma mensagem de erro e se recusa a produzir código de objeto a partir de seu código-fonte, há algo que não está totalmente certo em seu programa; ou seja, o significado do que você escreveu não está precisamente definido pelo padrão C++.

O compilador não tem senso comum (ele não é humano) e é muito exigente com detalhes. Como ele não tem senso comum, você não gostaria que ele tentasse adivinhar o que você quis dizer com algo que "parecia OK", mas não estava de acordo com a definição de C++. Se ele fizesse isso e o palpite dele fosse diferente do seu, você poderia acabar gastando muito tempo tentando descobrir por que o programa não fez o que você pensou ter dito para ele fazer. Quando tudo é dito e feito, o compilador nos salva de muitos problemas auto-infligidos. Ele nos salva de muito mais problemas do que causa. Portanto, por favor, lembre-se: o compilador é seu amigo; possivelmente, o compilador é o melhor amigo que você tem quando programa.

---

## 2.4 Vinculação (Linking)

Um programa geralmente consiste em várias partes separadas, muitas vezes desenvolvidas por pessoas diferentes. Por exemplo, o programa "Hello, World!" consiste na parte que escrevemos mais partes da biblioteca padrão C++. Essas partes separadas (às vezes chamadas de **unidades de tradução** - *translation units*) devem ser compiladas e os arquivos de código de objeto resultantes devem ser vinculados para formar um programa executável. O programa que une essas partes é (sem surpresa) chamado de **vinculador** (*linker*).

[Diagrama conceitual: 
Código-objeto (hello_world.obj) + Código-objeto da biblioteca padrão C++ 
    -- Linker --> 
Programa Executável (hello_world.exe)]

Por favor, note que o código de objeto e os executáveis **não são portáteis** entre sistemas. Por exemplo, quando você compila para uma máquina Windows, obtém um código de objeto para Windows que não rodará em uma máquina Linux.

Uma biblioteca é simplesmente algum código — geralmente escrito por outros — que acessamos usando declarações encontradas em um arquivo `#included`. Uma declaração é uma instrução de programa que especifica como uma parte do código pode ser usada; examinaremos as declarações em detalhes mais tarde (ex: §4.5.2).

Erros encontrados pelo compilador são chamados de **erros de tempo de compilação** (*compile-time errors*), erros encontrados pelo vinculador são chamados de **erros de tempo de vinculação** (*link-time errors*), e erros não encontrados até que o programa seja executado são chamados de **erros de tempo de execução** (*run-time errors*) ou **erros de lógica**. Geralmente, erros de tempo de compilação são mais fáceis de entender e corrigir do que erros de tempo de vinculação, e erros de tempo de vinculação costumam ser mais fáceis de encontrar e corrigir do que erros de tempo de execução e erros de lógica. No Capítulo 5, discutiremos os erros e as formas de tratá-los com mais detalhes.

---

## 2.5 Ambientes de programação

Para programar, usamos uma linguagem de programação. Também usamos um compilador para traduzir nosso código-fonte em código de objeto e um vinculador para vincular nosso código de objeto em um programa executável. Além disso, usamos algum programa para inserir o texto do nosso código-fonte no computador e editá-lo. Essas são apenas as primeiras e mais cruciais ferramentas que constituem o conjunto de ferramentas do nosso programador ou "ambiente de desenvolvimento de programas".

Se você trabalha a partir de uma janela de linha de comando, como muitos programadores profissionais fazem, terá que emitir os comandos de compilação e vinculação você mesmo. Se, em vez disso, você usar uma **IDE** ("ambiente de desenvolvimento interativo" ou "ambiente de desenvolvimento integrado"), como muitos programadores profissionais também fazem, um simples clique no botão correto fará o trabalho. Veja o Apêndice D para uma descrição de como compilar e vincular em sua implementação de C++.

IDEs geralmente incluem um editor com recursos úteis como codificação por cores para ajudar a distinguir entre comentários, palavras-chave e outras partes do código-fonte do seu programa, além de outras facilidades para ajudá-lo a depurar (*debug*) seu código, compilá-lo e executá-lo. **Debugging** é a atividade de encontrar erros em um programa e removê-los; você ouvirá muito sobre isso ao longo do caminho.

Neste livro, usamos o **Visual C++** da Microsoft como nosso exemplo de ambiente de desenvolvimento de programas. Se dissermos apenas "o compilador" ou nos referirmos a partes da "IDE", esse é o sistema ao qual estamos nos referindo. No entanto, você pode usar qualquer sistema que forneça uma implementação do C++ atualizada e em conformidade com os padrões. A maior parte do que dissermos será, com modificações muito pequenas, verdade para todas as implementações de C++, e o código rodará em todos os lugares. Em nosso trabalho, usamos várias implementações diferentes.

---

## Prática (Drill)

Até agora falamos sobre programação, código e ferramentas (como compiladores). Agora você tem que fazer um programa rodar. Este é um ponto crucial neste livro e no aprendizado da programação. É aqui que você começa a desenvolver habilidades práticas e bons hábitos de programação. Os exercícios deste capítulo focam em familiarizá-lo com seu ambiente de desenvolvimento de software. Uma vez que você faça o programa "Hello, World!" rodar, terá passado o primeiro grande marco como programador.

O propósito de uma prática (*drill*) é estabelecer ou reforçar suas habilidades práticas de programação e dar experiência com as ferramentas do ambiente de programação. Tipicamente, uma prática é uma sequência de modificações em um único programa, "fazendo-o crescer" de algo completamente trivial para algo que possa ser uma parte útil de um programa real. Um conjunto tradicional de exercícios é projetado para testar sua iniciativa, esperteza ou inventividade. Em contraste, uma prática exige pouca invenção de sua parte. Tipicamente, o sequenciamento é crucial, e cada passo individual deve ser fácil (ou até trivial). Por favor, não tente ser esperto e pular passos; em média, isso irá atrasá-lo ou até mesmo confundi-lo.

Você pode pensar que entende tudo o que leu e tudo o que seu mentor ou instrutor lhe disse, mas a repetição e a prática são necessárias para desenvolver habilidades de programação. Nesse sentido, a programação é como o atletismo, a música, a dança ou qualquer ofício baseado em habilidades. Imagine pessoas tentando competir em qualquer um desses campos sem prática regular. Você sabe quão bem elas se sairiam. Prática constante — para profissionais, isso significa prática constante por toda a vida — é a única maneira de desenvolver e manter uma habilidade prática de alto nível.

Portanto, **nunca pule as práticas**, não importa quão tentado você esteja; elas são essenciais para o processo de aprendizado. Apenas comece com o primeiro passo e prossiga, testando cada passo conforme avança para garantir que está fazendo certo. Não se assuste se não entender cada detalhe da sintaxe que está usando, e não tenha medo de pedir ajuda a instrutores ou amigos. Continue, faça todas as práticas e muitos dos exercícios, e tudo ficará claro no devido tempo.

Então, aqui está sua primeira prática:

1.  Vá para o Apêndice D e siga os passos necessários para configurar um projeto. Configure um projeto C++ de console vazio chamado `hello_world`.
2.  Digite `hello_world.cpp`, exatamente como especificado abaixo, salve-o em seu diretório de prática e inclua-o em seu projeto `hello_world`.

```cpp
#include "std_lib_facilities.h"

int main() // Programas C++ começam executando a função main
{
    cout << "Hello, World!\n"; // saída "Hello, World!"
    keep_window_open();        // aguarda que um caractere seja inserido
    return 0;
}
```

A chamada para `keep_window_open()` é necessária em algumas máquinas Windows para evitar que fechem a janela antes que você tenha a chance de ler a saída. Isso é uma peculiaridade/recurso do Windows, não do C++. Definimos `keep_window_open()` em `std_lib_facilities.h` para simplificar a escrita de programas de texto simples.

Como encontrar `std_lib_facilities.h`? Se você estiver em um curso, peça ao seu instrutor. Caso contrário, baixe-o de nosso site de suporte `www.stroustrup.com/Programming`. Mas e se você não tiver um instrutor e não tiver acesso à web? Nesse caso (apenas), substitua a diretiva `#include` por:

```cpp
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
inline void keep_window_open() { char ch; cin>>ch; }
```

Isso usa a biblioteca padrão diretamente, o manterá funcionando até o Capítulo 5 e será explicado em detalhes mais tarde (§8.7).

3.  Compile e execute o programa "Hello, World!". É bem provável que algo não tenha funcionado exatamente certo. Raramente funciona na primeira tentativa de usar uma nova linguagem ou um novo ambiente. Encontre o problema e corrija-o! Este é um ponto onde pedir ajuda a uma pessoa mais experiente é sensato, mas certifique-se de entender o que lhe é mostrado para que você possa fazer tudo sozinho antes de prosseguir.
4.  A esta altura, você provavelmente já encontrou alguns erros e teve que corrigi-los. Agora é a hora de se familiarizar um pouco melhor com as facilidades de detecção e relato de erros do seu compilador! Tente os seis erros do §2.3 para ver como seu ambiente de programação reage. Pense em pelo menos mais cinco erros que você poderia ter cometido ao digitar seu programa (por exemplo, esquecer `keep_window_open()`, deixar a tecla *Caps Lock* ligada ao digitar uma palavra, ou digitar uma vírgula em vez de um ponto e vírgula) e tente cada um para ver o que acontece quando você tenta compilar e executar essas versões.

---

## Revisão

A ideia básica dessas questões de revisão é dar a você a chance de ver se notou e entendeu os pontos-chave do capítulo. Você pode ter que consultar o texto para responder a uma pergunta; isso é normal e esperado. Você pode ter que reler seções inteiras; isso também é normal e esperado. No entanto, se você tiver que reler todo o capítulo ou tiver problemas com cada questão de revisão, deve considerar se seu estilo de aprendizado é eficaz. Você está lendo rápido demais? Você deveria parar e fazer algumas das sugestões de "Tente isso"? Você deveria estudar com um amigo para que possam discutir problemas com as explicações no texto?

1.  Qual é o propósito do programa "Hello, World!"?
2.  Nomeie as quatro partes de uma função.
3.  Nomeie uma função que deve aparecer em todo programa C++.
4.  No programa "Hello, World!", qual é o propósito da linha `return 0;`?
5.  Qual é o propósito do compilador?
6.  Qual é o propósito da diretiva `#include`?
7.  O que o sufixo `.h` no final de um nome de arquivo significa em C++?
8.  O que o vinculador (*linker*) faz pelo seu programa?
9.  Qual é a diferença entre um arquivo-fonte e um arquivo de objeto?
10. O que é uma IDE e o que ela faz por você?
11. Se você entende tudo no livro didático, por que é necessário praticar?

A maioria das questões de revisão tem uma resposta clara no capítulo em que aparecem. No entanto, ocasionalmente incluímos perguntas para lembrá-lo de informações relevantes de outros capítulos e, às vezes, até relacionadas ao mundo fora deste livro. Consideramos isso justo; há mais em escrever um bom software e pensar sobre as implicações de fazê-lo do que cabe em um capítulo ou livro individual.

---

## Termos

Esses termos apresentam o vocabulário básico da programação e do C++. Se você quiser entender o que as pessoas dizem sobre tópicos de programação e articular suas próprias ideias, você deve saber o que cada um significa.

*   `//`
*   `<<`
*   C++
*   comentário (*comment*)
*   compilador (*compiler*)
*   erro de tempo de compilação (*compile-time error*)
*   `cout`
*   executável (*executable*)
*   função (*function*)
*   cabeçalho (*header*)
*   IDE
*   `#include`
*   biblioteca (*library*)
*   vinculador (*linker*)
*   `main()`
*   código de objeto (*object code*)
*   saída (*output*)
*   programa (*program*)
*   código-fonte (*source code*)
*   instrução (*statement*)

Você pode gostar de desenvolver gradualmente um glossário escrito em suas próprias palavras. Você pode fazer isso repetindo o exercício 5 abaixo para cada capítulo.

---

## Exercícios

Listamos as práticas (*drills*) separadamente dos exercícios; sempre complete a prática do capítulo antes de tentar um exercício. Fazer isso economizará seu tempo.

1.  Altere o programa para exibir as duas linhas:
    `Hello, programming!`
    `Here we go!`
2.  Expandindo o que você aprendeu, escreva um programa que liste as instruções para um computador encontrar o banheiro no andar de cima, discutido no §2.1. Consegue pensar em mais algum passo que uma pessoa assumiria, mas que um computador não? Adicione-os à sua lista. Este é um bom começo em "pensar como um computador". **Aviso:** Para a maioria das pessoas, "vá ao banheiro" é uma instrução perfeitamente adequada. Para alguém sem experiência com casas ou banheiros (imagine uma pessoa da idade da pedra, de alguma forma transportada para sua sala de jantar), a lista de instruções necessárias poderia ser muito longa. Por favor, não use mais de uma página. Para o benefício do leitor, você pode adicionar uma pequena descrição do layout da casa que está imaginando.
3.  Escreva uma descrição de como ir da porta da frente do seu quarto, apartamento, casa, o que for, até a porta da sua sala de aula (assumindo que você frequenta alguma escola; se não, escolha outro alvo). Peça para um amigo tentar seguir as instruções e anotá-las com melhorias conforme avança. Para manter os amigos, pode ser uma boa ideia fazer um "teste de campo" dessas instruções antes de entregá-las a um amigo.
4.  Encontre um bom livro de receitas. Leia as instruções para assar muffins de mirtilo (se você estiver em um país onde "muffins de mirtilo" é um prato estranho e exótico, use um prato mais familiar). Observe que, com um pouco de ajuda e instrução, a maioria das pessoas no mundo pode assar deliciosos muffins de mirtilo. Não é considerado culinária avançada ou difícil. No entanto, para o autor, poucos exercícios neste livro são tão difíceis quanto este. É incrível o que você pode fazer com um pouco de prática.
    *   Reescreva essas instruções de forma que cada ação individual esteja em seu próprio parágrafo numerado.
    *   Tome cuidado para listar todos os ingredientes e todos os utensílios de cozinha usados em cada etapa.
    *   Tome cuidado com detalhes cruciais, como a temperatura desejada do forno, o pré-aquecimento do forno, a preparação da assadeira, a forma de cronometrar o cozimento e a necessidade de proteger as mãos ao retirar os muffins do forno.
    *   Considere essas instruções do ponto de vista de um novato na cozinha (se você não for um, peça ajuda a um amigo que não sabe cozinhar). Preencha os passos que o autor do livro (quase certamente um cozinheiro experiente) omitiu por serem óbvios.
    *   Construa um glossário dos termos usados. (O que é uma forma de muffin? O que o pré-aquecimento faz? O que você quer dizer com "forno"?)
    *   Agora asse alguns muffins e aproveite seus resultados.
5.  Escreva uma definição para cada um dos termos da seção "Termos". Primeiro tente ver se consegue fazer sem olhar o capítulo (improvável), depois procure no capítulo para encontrar as definições. Você pode achar interessante a diferença entre sua primeira tentativa e a versão do livro. Você pode consultar algum glossário online adequado, como `www.research.att.com/~bs/glossary.html`. Ao escrever sua própria definição antes de pesquisá-la, você reforça o aprendizado que obteve através de sua leitura. Se tiver que reler uma seção para formar uma definição, isso apenas o ajuda a entender. Sinta-se à vontade para usar suas próprias palavras para as definições e torne as definições tão detalhadas quanto achar razoável. Muitas vezes, um exemplo após a definição principal será útil. Você pode gostar de armazenar as definições em um arquivo para que possa adicioná-las a partir das seções "Termos" de capítulos posteriores.

---

## Posfácio

O que há de tão importante no programa "Hello, World!"? Seu propósito é nos familiarizar com as ferramentas básicas de programação. Tendemos a fazer um exemplo extremamente simples, como "Hello, World!", sempre que abordamos uma nova ferramenta. Dessa forma, separamos nosso aprendizado em duas partes: primeiro aprendemos o básico de nossas ferramentas com um programa trivial, e depois aprendemos sobre programas mais complicados sem sermos distraídos por nossas ferramentas. Aprender as ferramentas e a linguagem simultaneamente é muito mais difícil do que fazer primeiro uma e depois a outra. Essa abordagem de simplificar o aprendizado de uma tarefa complexa, dividindo-a em uma série de passos pequenos (e mais gerenciáveis), não se limita à programação e aos computadores. É comum e útil na maioria das áreas da vida, especialmente naquelas que envolvem alguma habilidade prática.
