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

int main(int argc, char const *argv[])
{
    verify_args(argc, 3);

    FILE *file = fopen(argv[2], "r");

    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    buffer b = allocate_buffer();
    char buffer_aux[DATA_LEN];
    char letter;
    int i = 0;
    int ch;

    // Safely read the file into buffer_aux
    while ((ch = getc(file)) != EOF)
    {
        if (i >= DATA_LEN - 1)
        { // Prevent buffer overflow
            printf("Buffer overflow prevented. Truncating input.\n");
            break;
        }
        buffer_aux[i] = (char)ch;
        i++;
    }
    buffer_aux[i] = '\0'; // Null-terminate the buffer

    // Load the buffer with data
    if (get_next_char(&b, buffer_aux, i) == ERR)
    {
        printf("Error loading buffer.\n");
        fclose(file);
        dealocate_buffer(&b);
        return 1;
    }

    go_back(&b);

    // Process the buffer
    for (size_t j = 0; j < DATA_LEN && buffer_aux[j] != '\0'; j++)
    {
        letter = get_next_char(&b, NULL, 0);
        if (letter == ERR)
        {
            printf("Error retrieving character.\n");
            break;
        }
        printf("%c", letter);
    }
    printf("\n");

    fclose(file);
    dealocate_buffer(&b);

    return 0;
}
