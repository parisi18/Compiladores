// TEST WITH: gcc -I*.h funcs.c main.c -o lexer.o -fsanitize=address -g  && ./lexer.o 3 C-\ tests/SSORT.c

#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

void verify_args(int argc, int expected)
{
    // printf("Expected arg num: %i\n", expected);
    // printf("Argc: %i\n", argc);

    if (argc != expected)
    {
        // printf("Número de argumentos inválido\n");
        exit(1);
    }
}

int main(int argc, char const *argv[])
{
    verify_args(argc, 3);

    FILE *file = fopen(argv[2], "r");

    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    Buffer *b = allocate_buffer(file);

    Token token;
    while ((token = get_token(b)).type != END_OF_FILE)
    {
        if (token.type == UNKNOWN)
            break;
    }

    dealocate_buffer(b);
    b = NULL;
    fclose(file);

    return 0;
}