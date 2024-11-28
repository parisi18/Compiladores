#include "funcs.h"

buffer allocate_buffer()
{
    buffer b;

    for (int i = 0; i < DATA_LEN; i++)
    {
        b.data[i] = '\0';
    }

    b.char_index = 0;
    b.free_space = DATA_LEN;
    b.curr_line = 0;

    return b;
}

void dealocate_buffer(buffer *b)
{
    for (int i = 0; i < DATA_LEN; i++)
    {
        b->data[i] = 0;
    }

    b->char_index = 0;
    b->free_space = DATA_LEN;
    b->curr_line = 0;
}

char get_next_char(buffer *b, char *words, int line_size)
{
    if (line_size > DATA_LEN)
    {
        printf("Error: line_size exceeds buffer capacity.\n");
        return ERR;
    }

    // Load new data into buffer
    if (line_size > 0)
    {
        if (b->free_space < line_size)
        {
            printf("Error: Insufficient buffer space.\n");
            return ERR;
        }

        for (int i = 0; i < line_size; i++)
        {
            b->data[DATA_LEN - b->free_space + i] = words[i];
        }
        b->free_space -= line_size;
    }

    // Ensure char_index is within bounds
    if (b->char_index >= DATA_LEN || b->char_index < 0)
    {
        printf("Error: char_index out of bounds.\n");
        return ERR;
    }

    char letter = b->data[b->char_index];

    if (letter == '\n')
    {
        b->curr_line++;
    }

    b->char_index++;
    return letter;
}

void go_back(buffer *b)
{
    if (b->char_index > 0)
    {
        char letter = b->data[b->char_index - 1];
        b->char_index--;

        if (letter == '\n')
        {
            b->curr_line--;
        }
    }
    else
    {
        printf("Error: Attempt to go back beyond buffer start.\n");
    }
}
