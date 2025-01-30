#include "funcs.h"
#include <ctype.h>
#include <string.h>

Buffer *allocate_buffer(FILE *file)
{
    Buffer *b = (Buffer *)malloc(sizeof(Buffer));

    if (file == NULL)
    {
        perror("Error opening file");
        free(b);
        exit(1);
    }

    b->char_index = 0;
    b->curr_line = 0;
    b->load_index = 0;
    b->free_space = DATA_LEN;
    b->file = file;
    b->eof = 0;

    return b;
}

void dealocate_buffer(Buffer *b)
{
    if (b != NULL)
        free(b);
}

int load_chunk(Buffer *b)
{
    if (b->eof)
        return 0;

    if (b->char_index >= b->load_index)
    {
        int unread_size = b->load_index - b->char_index;

        if (unread_size > 0)
            memmove(b->data, &b->data[b->char_index], unread_size);

        b->char_index = 0;
        b->load_index = unread_size;
        b->free_space = DATA_LEN - unread_size;

        int bytes_read = fread(&b->data[b->load_index], 1, b->free_space, b->file);

        if (bytes_read == 0)
        {
            b->eof = 1;
            return 0;
        }

        b->load_index += bytes_read;
        b->free_space -= bytes_read;
    }

    return 1;
}

char get_next_char(Buffer *b, char *words, int line_size)
{
    if (b->eof)
        return EOF;

    if (line_size > DATA_LEN)
    {
        printf("Error: line_size exceeds buffer capacity.\n");
        return ERR;
    }

    if (b->char_index >= b->load_index)
    {
        if (!load_chunk(b))
            return EOF;
    }

    char letter = b->data[b->char_index];

    if (letter == '\n')
    {
        b->curr_line++;
    }

    b->char_index++;
    return letter;
}

void go_back(Buffer *b)
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

int is_keyword(const char *word)
{
    struct
    {
        const char *name;
        TokenType type;
    } keywords[] = {
        {"else", ELSE},
        {"if", IF},
        {"int", INT},
        {"return", RETURN},
        {"void", VOID},
        {"while", WHILE}};

    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < num_keywords; i++)
    {
        if (strcmp(word, keywords[i].name) == 0)
        {
            return keywords[i].type;
        }
    }

    return 0;
}

const char *token_type_to_string(TokenType type)
{
    switch (type)
    {
    case ELSE:
        return "ELSE";
    case IF:
        return "IF";
    case INT:
        return "INT";
    case RETURN:
        return "RETURN";
    case VOID:
        return "VOID";
    case WHILE:
        return "WHILE";

    case ID:
        return "ID";
    case KEYWORD:
        return "KEYWORD";
    case NUMBER:
        return "NUMBER";

    case ASSIGN:
        return "ASSIGN";
    case LOGICAL_EQ:
        return "LOGICAL_EQ";
    case NOT_EQ:
        return "NOT_EQ";
    case LESS:
        return "LESS";
    case LESS_EQ:
        return "LESS_EQ";
    case GREATER:
        return "GREATER";
    case GREATER_EQ:
        return "GREATER_EQ";
    case PLUS:
        return "PLUS";
    case MINUS:
        return "MINUS";
    case MULT:
        return "MULT";
    case DIV:
        return "DIV";
    case MODULO:
        return "MODULO";
    case LOGICAL_AND:
        return "LOGICAL_AND";
    case LOGICAL_OR:
        return "LOGICAL_OR";
    case LOGICAL_NOT:
        return "LOGICAL_NOT";

    case LPAREN:
        return "LPAREN";
    case RPAREN:
        return "RPAREN";
    case LBRACKET:
        return "LBRACKET";
    case RBRACKET:
        return "RBRACKET";
    case LBRACE:
        return "LBRACE";
    case RBRACE:
        return "RBRACE";
    case COMMA:
        return "COMMA";
    case SEMICOLON:
        return "SEMICOLON";

    case INPUT:
        return "INPUT";
    case OUTPUT:
        return "OUTPUT";
    case COMMENT:
        return "COMMENT";
    case UNKNOWN:
        return "UNKNOWN";
    case END_OF_FILE:
        return "END_OF_FILE";

    default:
        return "UNKNOWN_TOKEN";
    }
}

char peek_next_char(Buffer *b)
{
    return b->data[b->char_index]; // Look ahead without consuming
}

Token get_token(Buffer *b)
{
    State state = START;
    Token token;
    token.lexeme[0] = '\0';
    int lexeme_index = 0;
    int token_idx;
    int line = 1;
    char c;

    while ((c = get_next_char(b, NULL, 0)) != EOF)
    {
        if (b->eof)
        {
            printf("Lexer has reached EOF. Stopping.\n");
            token.type = END_OF_FILE;
            return token;
        }
        switch (state)
        {
        case START:
            if (isalpha(c)) // Identifiers and keywords
            {
                state = INID;
                token.lexeme[lexeme_index++] = c;
            }
            else if (isdigit(c)) // Numbers
            {
                state = INNUM;
                token.lexeme[lexeme_index++] = c;
            }
            else if (c == '/') // Division or Comment
            {
                state = INCOMENT;
            }
            else if (c == '=') // Assignment or equality (==)
            {
                state = INATRIB;
            }
            else if (c == '!') // Logical NOT or NOT_EQUAL (!=)
            {
                state = INNOT;
            }
            else if (c == '<') // Less than (<) or Less than or equal (<=)
            {
                state = INLESS;
            }
            else if (c == '>') // Greater than (>) or Greater than or equal (>=)
            {
                state = INGREATER;
            }
            else if (c == '&') // Logical AND (&&)
            {
                state = INAND;
            }
            else if (c == '|') // Logical OR (||)
            {
                state = INOR;
            }
            else if (c == '+')
            {
                token.type = PLUS;
                token.lexeme[0] = c;
                token.lexeme[1] = '\0';
                printf("Linha: %d, Lexema: %s, Token: %s\n", token.line, token.lexeme, token_type_to_string(token.type));
                return token;
            }
            else if (c == '-')
            {
                token.type = MINUS;
                token.lexeme[0] = c;
                token.lexeme[1] = '\0';
                printf("Linha: %d, Lexema: %s, Token: %s\n", token.line, token.lexeme, token_type_to_string(token.type));
                return token;
            }
            else if (c == '*')
            {
                token.type = MULT;
                token.lexeme[0] = c;
                token.lexeme[1] = '\0';
                printf("Linha: %d, Lexema: %s, Token: %s\n", token.line, token.lexeme, token_type_to_string(token.type));
                return token;
            }
            else if (c == '%')
            {
                token.type = MODULO;
                token.lexeme[0] = c;
                token.lexeme[1] = '\0';
                printf("Linha: %d, Lexema: %s, Token: %s\n", token.line, token.lexeme, token_type_to_string(token.type));
                return token;
            }
            else if (c == '(')
            {
                token.type = LPAREN;
                token.lexeme[0] = c;
                token.lexeme[1] = '\0';
                printf("Linha: %d, Lexema: %s, Token: %s\n", token.line, token.lexeme, token_type_to_string(token.type));
                return token;
            }
            else if (c == ')')
            {
                token.type = RPAREN;
                token.lexeme[0] = c;
                token.lexeme[1] = '\0';
                printf("Linha: %d, Lexema: %s, Token: %s\n", token.line, token.lexeme, token_type_to_string(token.type));
                return token;
            }
            else if (c == '{')
            {
                token.type = LBRACE;
                token.lexeme[0] = c;
                token.lexeme[1] = '\0';
                printf("Linha: %d, Lexema: %s, Token: %s\n", token.line, token.lexeme, token_type_to_string(token.type));
                return token;
            }
            else if (c == '}')
            {
                token.type = RBRACE;
                token.lexeme[0] = c;
                token.lexeme[1] = '\0';
                printf("Linha: %d, Lexema: %s, Token: %s\n", token.line, token.lexeme, token_type_to_string(token.type));
                return token;
            }
            else if (c == '[')
            {
                token.type = LBRACKET;
                token.lexeme[0] = c;
                token.lexeme[1] = '\0';
                printf("Linha: %d, Lexema: %s, Token: %s\n", token.line, token.lexeme, token_type_to_string(token.type));
                return token;
            }
            else if (c == ']')
            {
                token.type = RBRACKET;
                token.lexeme[0] = c;
                token.lexeme[1] = '\0';
                printf("Linha: %d, Lexema: %s, Token: %s\n", token.line, token.lexeme, token_type_to_string(token.type));
                return token;
            }
            else if (c == ',')
            {
                token.type = COMMA;
                token.lexeme[0] = c;
                token.lexeme[1] = '\0';
                printf("Linha: %d, Lexema: %s, Token: %s\n", token.line, token.lexeme, token_type_to_string(token.type));
                return token;
            }
            else if (c == ';')
            {
                token.type = SEMICOLON;
                token.lexeme[0] = c;
                token.lexeme[1] = '\0';
                printf("Linha: %d, Lexema: %s, Token: %s\n", token.line, token.lexeme, token_type_to_string(token.type));
                return token;
            }
            else if (isspace(c))
            {
                if (c == '\n')
                    token.line++;
            }
            else
            {
                printf("Erro léxico na linha %d: caractere desconhecido '%c'\n", token.line, c);
                state = FAILURE;
            }
            break;

        case INID:
            if (isalnum(c))
            {
                token.lexeme[lexeme_index++] = c;
            }
            else
            {
                token.lexeme[lexeme_index] = '\0';
                token.line = b->curr_line;

                TokenType keyword_type = (TokenType)is_keyword(token.lexeme);
                if (keyword_type)
                    token.type = keyword_type;
                else
                    token.type = ID;

                go_back(b);

                printf("Linha: %d, Lexema: %s, Token: %s\n", token.line, token.lexeme, token_type_to_string(token.type));
                return token;
            }
            break;

        case INNUM:
            if (isdigit(c))
            {
                token.lexeme[lexeme_index++] = c;
            }
            else if (c == '.' && isdigit(peek_next_char(b))) // Handle floating-point numbers
            {
                token.lexeme[lexeme_index++] = c;
            }
            else
            {
                token.lexeme[lexeme_index] = '\0';
                token.line = b->curr_line;
                token.type = NUMBER;

                go_back(b);

                printf("Linha: %d, Lexema: %s, Token: %s\n", token.line, token.lexeme, token_type_to_string(token.type));
                return token;
            }
            break;

        case INCOMENT:
            if (c == '*')
                state = COMMENT_1;
            else
                state = FAILURE;
            break;
        case COMMENT_1:
            if (c == '*')
                state = COMMENT_2;
            else
                state = COMMENT_1;
            break;
        case COMMENT_2:
            if (c == '/')
                state = START;
            else
                state = COMMENT_1;
            break;

        case INATRIB:
            if (c == '=')
                token.type = LOGICAL_EQ;
            else
            {
                token.type = ASSIGN;
                go_back(b);
            }
            printf("Linha: %d, Lexema: %s, Token: %s\n", token.line, token.lexeme, token_type_to_string(token.type));
            return token;

        case INNOT:
            if (c == '=')
                token.type = NOT_EQ;
            else
            {
                token.type = LOGICAL_NOT;
                go_back(b);
            }
            printf("Linha: %d, Lexema: %s, Token: %s\n", token.line, token.lexeme, token_type_to_string(token.type));
            return token;

        case INLESS:
            if (c == '=')
                token.type = LESS_EQ;
            else
            {
                token.type = LESS;
                go_back(b);
            }
            printf("Linha: %d, Lexema: %s, Token: %s\n", token.line, token.lexeme, token_type_to_string(token.type));
            return token;

        case INGREATER:
            if (c == '=')
                token.type = GREATER_EQ;
            else
            {
                token.type = GREATER;
                go_back(b);
            }
            printf("Linha: %d, Lexema: %s, Token: %s\n", token.line, token.lexeme, token_type_to_string(token.type));
            return token;

        case INAND:
            if (c == '&')
                token.type = LOGICAL_AND;
            else
            {
                printf("Erro léxico na linha %d: caractere inesperado '&'\n", token.line);
                token.type = UNKNOWN;
            }
            printf("Linha: %d, Lexema: %s, Token: %s\n", token.line, token.lexeme, token_type_to_string(token.type));
            return token;

        case INOR:
            if (c == '|')
                token.type = LOGICAL_OR;
            else
            {
                printf("Erro léxico na linha %d: caractere inesperado '|'\n", token.line);
                token.type = UNKNOWN;
            }
            printf("Linha: %d, Lexema: %s, Token: %s\n", token.line, token.lexeme, token_type_to_string(token.type));
            return token;

        case FAILURE:
            printf("Erro léxico na linha %d: caractere desconhecido '%c'\n", line, c);
            state = FINISH;
            break;

        case FINISH:
            exit(1);
        }
    }
    token.type = END_OF_FILE;
    return token;
}
