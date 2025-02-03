// Programador: Rafael dos Santos Parisi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"
#include "parser.tab.h"
#include "symbol_tab.h"
#include "ast.h"
#include "semantic.h"

extern ASTNode *root;
extern int yylex();
extern FILE *yyin;

int print_tokens = 0;
int print_ast_flag = 0;
int print_symbol_table_flag = 0;
int run_semantic_flag = 0;

void print_usage()
{
    printf("Uso: ./parser <arquivo.c> [flags]\n");
    printf("Flags:\n");
    printf("  -t   Mostra os tokens lexicais\n");
    printf("  -a   Mostra a árvore sintática\n");
    printf("  -s   Mostra a tabela de símbolos\n");
}

void process_flags(int argc, char *argv[])
{
    for (int i = 2; i < argc; i++)
    {
        if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "-T") == 0)
        {
            print_tokens = 1;
        }
        else if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "-A") == 0)
        {
            print_ast_flag = 1;
        }
        else if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "-S") == 0)
        {
            print_symbol_table_flag = 1;
        }
        else
        {
            printf("Opção inválida: %s\n", argv[i]);
            print_usage();
            exit(1);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        print_usage();
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    lexer_buffer = allocate_buffer(file);
    symbol_tab = create_symbol_table();

    process_flags(argc, argv);

    // Se a flag -t for passada, imprime os tokens
    if (print_tokens)
    {
        Token token;
        while ((token.type = yylex()) > 0)
        {
            if (token.type == ID)
            {
                printf("%s\"%s\"[linha: %d]\n", token_type_to_string(token.type), yylval.sval, yylineno);
                free(yylval.sval);
            }
            else if (token.type == NUMBER)
            {
                printf("%s\"%d\"[linha: %d]\n", token_type_to_string(token.type), yylval.ival, yylineno);
            }
            else
            {
                printf("%s\"%s\"[linha: %d]\n", token_type_to_string(token.type), yytext, yylineno);
            }
        }
        free(lexer_buffer);
        return 0;
    }

    // Inicialização do Parser
    yyparse();

    // Se a flag -a for passada, imprime a árvore sintática
    if (print_ast_flag)
        print_ast(root, 0);

    // Se a flag -s for passada, imprime a tabela de símbolos
    if (print_symbol_table_flag)
        print_symbol_table(symbol_tab);

    fclose(file);
    free_ast(root);
    free_symbol_table(symbol_tab);
    free(lexer_buffer);

    return 0;
}
