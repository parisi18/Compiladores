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
    ID,      // Identificador
    KEYWORD, // Palavra-chave
    NUMBER,  // Número

    // Operators
    ASSIGN,      // Atribuição (=)
    LOGICAL_EQ,  // Igualdade (==)
    NOT_EQ,      // Diferente (!=)
    LESS,        // Menor (<)
    LESS_EQ,     // Menor ou igual (<=)
    GREATER,     // Maior (>)
    GREATER_EQ,  // Maior ou igual (>=)
    PLUS,        // Adição (+)
    MINUS,       // Subtração (-)
    MULT,        // Multiplicação (*)
    DIV,         // Divisão (/)
    MODULO,      // Módulo (%)
    LOGICAL_AND, // E lógico (&&)
    LOGICAL_OR,  // OU lógico (||)
    LOGICAL_NOT, // Negação lógica (!)

    // Delimiters
    LPAREN,    // ( Parêntese esquerdo
    RPAREN,    // ) Parêntese direito
    LBRACKET,  // [ Colchete esquerdo
    RBRACKET,  // ] Colchete direito
    LBRACE,    // { Chave esquerda
    RBRACE,    // } Chave direita
    COMMA,     // , Vírgula
    SEMICOLON, // ; Ponto e vírgula

    // Special Tokens
    INPUT,      // input() função de entrada
    OUTPUT,     // output() função de saída
    COMMENT,    // Comentário (/* ... */)
    UNKNOWN,    // Token desconhecido
    END_OF_FILE // EOF (fim do arquivo)

} TokenType;

typedef struct
{
    char lexeme[MAX_LEXEME_LENGTH];
    TokenType type;
    int line;
} Token;

typedef enum
{
    START,     // 0 - Initial state
    INCOMENT,  // 1 - Start of comment (`/*`)
    COMMENT_1, // 2 - Inside comment
    COMMENT_2, // 3 - Possible end of comment (`*/`)
    INNUM,     // 4 - Inside a number
    INID,      // 5 - Inside an identifier
    INATRIB,   // 6 - Assignment (`=`)
    INNOT,     // 7 - Logical NOT (`!` or `!=`)
    INLESS,    // 8 - Less than (`<` or `<=`)
    INGREATER, // 9 - Greater than (`>` or `>=`)
    INAND,     // 10 - Logical AND (`&&`)
    INOR,      // 11 - Logical OR (`||`)
    FINISH,    // 12 - Finished processing
    FAILURE    // 13 - Lexical error
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