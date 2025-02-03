# Compilador - Lexer, Parser e Análise Semântica

Este projeto implementa um compilador básico com as etapas de análise léxica, sintática e semântica utilizando **Bison e C**.

## Requisitos

Antes de compilar e rodar o projeto, é necessário ter instalado:

```sh
sudo apt update && sudo apt install -y build-essential bison
```

Para **MacOS** (Homebrew):

```sh
brew install bison
```

## Compilação e Execução

### Compilar o projeto

```sh
make
```

Esse comando gera os arquivos do parser (`parser.tab.c` e `parser.tab.h`) e compila os arquivos em `.o`, criando o executável `parser`.

### Executar o compilador

```sh
./parser <caminho_do_arquivo>
```

Substitua `<caminho_do_arquivo>` pelo caminho do código-fonte que será analisado.

### Flags Disponíveis

| Flag | Descrição                               |
| ---- | --------------------------------------- |
| `-t` | Mostra os **tokens** gerados pelo lexer |
| `-a` | Exibe a **árvore sintática** gerada     |
| `-s` | Mostra a **tabela de símbolos**         |

Exemplo:

```sh
./parser caminho/do/codigo.c <flag>
```

## Fluxo de Compilação

1. **Análise Léxica (Lexer)**: Lê o código-fonte e identifica **tokens** (palavras-chave, identificadores, números, etc.).

    - Implementado em **lexer.c**
    - Chamado via `yylex()`
    - Retorna tokens para o parser

2. **Análise Sintática (Parser)**: Verifica se a estrutura do código segue as regras da gramática.

    - Implementado em **parser.y**
    - Utiliza `yyparse()`
    - Constrói a **árvore sintática abstrata (AST)**

3. **Análise Semântica**: Verifica regras lógicas como:

    - Declarações duplicadas
    - Tipos incompatíveis
    - Uso de variáveis não declaradas

## Comandos Úteis

### Limpar arquivos compilados

```sh
make clean
```

### Recompilar do zero

```sh
make clean && make
```

### Gerar o parser manualmente

```sh
bison -d parser.y
```

Este README fornece todas as instruções necessárias para compilar e rodar o projeto corretamente.
