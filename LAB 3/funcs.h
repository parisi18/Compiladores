#include <stdio.h>
#include <stdlib.h>

#define DATA_LEN 256
#define ERR 0

typedef struct
{
    char data[DATA_LEN];
    int char_index;
    int curr_line;
    int free_space;
    int load_index;
    FILE *file;

} Buffer;

#define MAX_LEXEME_LENGTH 64

typedef enum Tokens
{
    ELSE,
    IF,
    INT,
    RETURN,
    VOID,
    WHILE,
    ID,         // Identificador
    KEYWORD,    // Palavra-chave
    NUMBER,     // Número
    ASSIGN,     // Atribuição (=)
    LOGICAL_EQ, // Igualdade (==)
    UNKNOWN     // Token desconhecido
} TokenType;

typedef struct
{
    char lexeme[MAX_LEXEME_LENGTH];
    TokenType type;
    int line;
} Token;

typedef enum
{
    START,
    INCOMENT,
    COMMENT_1,
    COMMENT_2,
    COMMENT_3,
    INNUM,
    INID,
    INATRIB,
    FINISH,
    FAILURE
} State;

Buffer *allocate_buffer(FILE *file);
void dealocate_buffer(Buffer *b);
char get_next_char(Buffer *b, char *words, int line_size);
void go_back(Buffer *b);
int is_keyword(const char *word);
Token get_token(Buffer *b);
void init_buffer(Buffer *b);
int load_chunk(Buffer *b);