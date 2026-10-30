# Aula 02 - Variáveis, Entrada e Saída de Dados em C++

Este diretório contém os exercícios e exemplos da Aula 02 de Programação de Computadores, focados em variáveis, entrada e saída de dados no console.

## Conteúdo Principal

- `primeiro.cpp`: Demonstra a saída de texto simples no console (`cout`).
- `segundo.cpp`: Ilustra a declaração, atribuição e manipulação de variáveis inteiras.
- `terceiro.cpp`: Apresenta a entrada de dados do usuário (`cin`) e cálculos simples com variáveis.
- `parametros_main.cpp`: Exemplo de como a função `main` pode receber argumentos de linha de comando (`argc`, `argv`).
- `example-header.h`: Um arquivo de cabeçalho de exemplo contendo a declaração de uma função e uma constante.
- `usa_header.cpp`: Um arquivo-fonte que demonstra como incluir e utilizar o `example-header.h`.

## Exercícios

O subdiretório `exercicios/` contém arquivos adicionais para prática:

- `exec-1a.cpp`: (Descrição a ser adicionada se necessário)
- `exec-1b.cpp`: (Descrição a ser adicionada se necessário)
- `exec-2.cpp`: (Descrição a ser adicionada se necessário)
- `exec-3.cpp`: Exemplo de saída de texto com caracteres especiais.
- `exec-5.cpp`: Demonstra o uso de argumentos de linha de comando.

## Como Compilar e Executar

Para compilar e executar os programas, siga os passos abaixo. É necessário ter um compilador C++ (como o g++) instalado no seu sistema.

### Compilação

Abra um terminal no diretório `aula-02` e use o comando `g++` para compilar cada arquivo. Para os arquivos na pasta `exercicios`, você precisará especificar o caminho completo.

```bash
# Compilação dos arquivos principais
g++ primeiro.cpp -o primeiro
g++ segundo.cpp -o segundo
g++ terceiro.cpp -o terceiro
g++ parametros_main.cpp -o parametros_main
g++ usa_header.cpp -o usa_header

# Compilação dos arquivos de exercício
g++ exercicios/exec-1a.cpp -o exercicios/exec-1a
g++ exercicios/exec-1b.cpp -o exercicios/exec-1b
g++ exercicios/exec-2.cpp -o exercicios/exec-2
g++ exercicios/exec-3.cpp -o exercicios/exec-3
g++ exercicios/exec-5.cpp -o exercicios/exec-5
```

Isso criará os arquivos executáveis correspondentes.

### Execução

Após a compilação, você pode executar os programas da seguinte forma:

```bash
# Execução dos arquivos principais
./primeiro
./segundo
./terceiro
./parametros_main arg1 arg2 "argumento com espaço"
./usa_header

# Execução dos arquivos de exercício
./exercicios/exec-1a
./exercicios/exec-1b
./exercicios/exec-2
./exercicios/exec-3
./exercicios/exec-5
./exercicios/exec-5 eu amo
```

Para `parametros_main` e `exec-5`, você pode passar quantos argumentos desejar após o nome do executável.
Cada comando executará o programa correspondente no terminal.
