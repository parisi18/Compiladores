// gcc funcs.c main.c -o lab1 -fsanitize=address -g && ./lab1 3 lab1.txt

#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

void verify_args(int argc, int expected)
{
    printf("Expected arg num: %i\n", expected);
    printf("Argc: %i\n", argc);

    if (argc != expected)
    {
        printf("Número de argumentos inválido\n");
        exit(1);
    }
}

void main(int argc, char const *argv[])
{
    verify_args(argc, 3);

    FILE *file = fopen(argv[2], "r");

    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    buffer *b = allocate_buffer(atoi(argv[1]));

    replace_print(b, file);

    fclose(file);

    dealocate_buffer(b);

    return;
}