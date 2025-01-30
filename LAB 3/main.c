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
    char ch;

    while ((ch = get_next_char(b, NULL, 0)) != EOF)
    {
        if (ch == ERR)
        {
            printf("Error retrieving character.\n");
            break;
        }
        printf("%c", ch);
    }
    printf("\n");

    dealocate_buffer(b);
    b = NULL;
    fclose(file);

    return 0;
}