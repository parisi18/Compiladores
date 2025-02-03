#include "funcs.h"

buffer *allocate_buffer(int size)
{
    buffer *b;
    b = (buffer *)malloc(sizeof(buffer));

    b->data = (char *)malloc(sizeof(char) * size);
    b->size = size;

    return b;
}

void dealocate_buffer(buffer *b)
{
    free(b->data);
    free(b);
}

void replace_print(buffer *b, FILE *f)
{
    char ascii_diff = 'a' - 'A';

    char ch;
    int i = 0;
    int kill = 0;
    while (!kill)
    {
        for (i = 0; i < b->size; i++)
        {
            ch = getc(f);

            if (ch == EOF)
            {
                kill = 1;
                break;
            }

            b->data[i] = ch;

            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                b->data[i] -= ascii_diff;
            else if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
                b->data[i] += ascii_diff;
        }

        for (int j = 0; j < i; j++)
        {
            printf("%c", b->data[j]);
        }
    }

    return;
}