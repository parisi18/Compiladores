#include <stdio.h>
#include <stdlib.h>

#define DATA_LEN 256
#define ERR 0

typedef struct
{
    char data[DATA_LEN];
    int char_index;
    int free_space;
    int curr_line;

} buffer;

buffer allocate_buffer();
void dealocate_buffer(buffer *b);
char get_next_char(buffer *b, char *words, int line_size);
void go_back(buffer *b);