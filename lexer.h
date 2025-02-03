#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"
#include "symbol_tab.h"

extern int yylineno;
extern int yycolumn;
extern char yytext[256];

extern FILE *yyin;
int yylex();

#define DATA_LEN 256
#define MAX_LEXEME_LENGTH 64
#define ERR 0

typedef struct
{
    char data[DATA_LEN];
    int char_index;
    int curr_line;
    int free_space;
    int load_index;
    FILE *file;
    int eof;
    int column;

} Buffer;

extern Buffer *lexer_buffer;
extern SymbolTable *symbol_table;

typedef struct
{
    char lexeme[MAX_LEXEME_LENGTH];
    int type;
    int line;
    int column;
} Token;

typedef enum
{
    START,          // 0 - Initial state
    INCOMMENT,      // 1 - Start of comment (`/*`)
    COMMENTING,     // 2 - Inside comment
    FINISH_COMMENT, // 3 - Possible end of comment (`*/`)
    INNUM,          // 4 - Inside a number
    INID,           // 5 - Inside an identifier
    INATRIB,        // 6 - Assignment (`=`)
    FAILURE         // 12 - Lexical error
} State;

Buffer *allocate_buffer(FILE *file);
void dealocate_buffer(Buffer *b);
void go_back(Buffer *b);
void init_buffer(Buffer *b);
int is_keyword(const char *word);
const char *token_type_to_string(int type);
int load_chunk(Buffer *b);
char get_next_char(Buffer *b, int line_size);
Token get_token(Buffer *b);
char peek_next_char(Buffer *b);
void report_lexical_error(const char *lexeme, int line, int column);
void log_lexeme(Token token);

#endif // LEXER_H