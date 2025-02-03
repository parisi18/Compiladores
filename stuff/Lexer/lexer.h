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
    int eof;
    int column;

} Buffer;

#define MAX_LEXEME_LENGTH 64

typedef enum Tokens
{
    // Keywords
    ELSE,
    IF,
    INT,
    RETURN,
    VOID,
    WHILE,

    // Identifiers, Literals, and Keywords
    ID,     // Identificador
    NUMBER, // Número

    // Operadores
    PLUS,       // +
    MINUS,      // -
    MULT,       // *
    DIV,        // /
    LESS,       // <
    LESS_EQ,    // <=
    GREATER,    // >
    GREATER_EQ, // >=
    LOGICAL_EQ, // ==
    NOT_EQ,     // !=
    ASSIGN,     // =

    // Delimitadores
    SEMICOLON, // ;
    COMMA,     // ,
    LPAREN,    // (
    RPAREN,    // )
    LBRACKET,  // [
    RBRACKET,  // ]
    LBRACE,    // {
    RBRACE,    // }

    // Comentários
    COMMENT, // /* ... */

    UNKNOWN,    // Token desconhecido
    END_OF_FILE // EOF

} TokenType;

typedef struct
{
    char lexeme[MAX_LEXEME_LENGTH];
    TokenType type;
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
    INNOT,          // 7 - Logical NOT (`!` or `!=`)
    INLESS,         // 8 - Less than (`<` or `<=`)
    INGREATER,      // 9 - Greater than (`>` or `>=`)
    INAND,          // 10 - Logical AND (`&&`)
    INOR,           // 11 - Logical OR (`||`)
    FAILURE         // 12 - Lexical error
} State;

Buffer *allocate_buffer(FILE *file);
void dealocate_buffer(Buffer *b);
void go_back(Buffer *b);
void init_buffer(Buffer *b);
int is_keyword(const char *word);
int load_chunk(Buffer *b);
char get_next_char(Buffer *b, char *words, int line_size);
Token get_token(Buffer *b);
char peek_next_char(Buffer *b);
const char *token_type_to_string(TokenType type);
void report_lexical_error(const char *lexeme, int line, int column);
void log_lexeme(Token token);