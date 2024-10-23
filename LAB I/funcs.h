#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *data;
    int size;
} buffer;

buffer *allocate_buffer(int size);
void dealocate_buffer(buffer *b);
void replace_print(buffer *b, FILE *f);