#include "lexer.h"
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

void report_lexical_error(const char *lexeme, int line, int column)
{
    printf("ERRO LEXICO: \"%s\" INVALIDO [linha: %d, COLUNA: %d].\n", lexeme, line, column);
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
    b->char_index++;

    if (letter == '\n')
    {
        b->column = 0;
        b->curr_line++;
    }
    else
        b->column++;

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

void log_lexeme(Token token)
{
    printf("%s\"%s\"[linha: %d]\n", token_type_to_string(token.type), token.lexeme, --token.line);
}

Token get_token(Buffer *b)
{
    State state = START;
    Token token;
    token.lexeme[0] = '\0';
    int lexeme_index = 0;
    int line = 1;
    char c;

    while ((c = get_next_char(b, NULL, 0)) != EOF || state != FAILURE)
    {
        if (b->eof)
        {
            token.type = END_OF_FILE;
            return token;
        }
        if (c == '\n')
        {
            b->curr_line++;
            continue;
        }

        switch (state)
        {
        case START:
            token.line = b->curr_line;
            if (isalpha(c))
            {
                state = INID;
                token.lexeme[lexeme_index++] = c;
            }
            else if (isdigit(c))
            {
                state = INNUM;
                token.lexeme[lexeme_index++] = c;
            }
            else if (c == '/')
            {
                state = INCOMMENT;
            }

            else
            {
                switch (c)
                {
                case '=':
                    if (peek_next_char(b) == '=')
                    {
                        get_next_char(b, NULL, 0);
                        token.type = LOGICAL_EQ;
                        strcpy(token.lexeme, "==");
                    }
                    else
                    {
                        token.type = ASSIGN;
                        strcpy(token.lexeme, "=");
                    }

                    return token;
                case '!':
                    if (peek_next_char(b) == '=')
                    {
                        get_next_char(b, NULL, 0);
                        token.type = NOT_EQ;
                        strcpy(token.lexeme, "!=");
                        log_lexeme(token);
                        return token;
                    }
                    else
                    {
                        token.type = UNKNOWN;
                        token.lexeme[0] = c;
                        token.lexeme[1] = '\0';
                        token.line = b->curr_line;
                        token.column = b->column;
                        report_lexical_error(token.lexeme, token.line, token.column);
                        state = FAILURE;
                        continue;
                    }

                case '<':
                    if (peek_next_char(b) == '=')
                    {
                        get_next_char(b, NULL, 0);
                        token.type = LESS_EQ;
                        strcpy(token.lexeme, "<=");
                    }
                    else
                    {
                        token.type = LESS;
                        strcpy(token.lexeme, "<");
                    }
                    log_lexeme(token);

                    return token;
                case '>':
                    if (peek_next_char(b) == '=')
                    {
                        get_next_char(b, NULL, 0);
                        token.type = GREATER_EQ;
                        strcpy(token.lexeme, ">=");
                    }
                    else
                    {
                        token.type = GREATER;
                        strcpy(token.lexeme, ">");
                    }
                    log_lexeme(token);

                    return token;
                case '+':
                    token.type = PLUS;
                    strcpy(token.lexeme, "+");
                    log_lexeme(token);

                    return token;
                case '-':
                    token.type = MINUS;
                    strcpy(token.lexeme, "-");
                    log_lexeme(token);
                    return token;
                case '*':
                    token.type = MULT;
                    strcpy(token.lexeme, "*");
                    log_lexeme(token);
                    return token;

                case '(':
                    token.type = LPAREN;
                    strcpy(token.lexeme, "(");
                    log_lexeme(token);
                    return token;
                case ')':
                    token.type = RPAREN;
                    strcpy(token.lexeme, ")");
                    log_lexeme(token);
                    return token;
                case '[':
                    token.type = LBRACKET;
                    strcpy(token.lexeme, "[");
                    log_lexeme(token);
                    return token;
                case ']':
                    token.type = RBRACKET;
                    strcpy(token.lexeme, "]");
                    log_lexeme(token);
                    return token;
                case '{':
                    token.type = LBRACE;
                    strcpy(token.lexeme, "{");
                    log_lexeme(token);
                    return token;
                case '}':
                    token.type = RBRACE;
                    strcpy(token.lexeme, "}");
                    log_lexeme(token);
                    return token;
                case ';':
                    token.type = SEMICOLON;
                    strcpy(token.lexeme, ";");
                    log_lexeme(token);
                    return token;
                case ',':
                    token.type = COMMA;
                    strcpy(token.lexeme, ",");
                    log_lexeme(token);
                    return token;
                case ' ':
                case '\t':
                case '\r':
                    break;
                default:
                    token.type = UNKNOWN;
                    token.lexeme[0] = c;
                    token.lexeme[1] = '\0';
                    token.line = b->curr_line;
                    token.column = b->column;
                    report_lexical_error(token.lexeme, token.line, token.column);
                    state = FAILURE;
                    continue;
                }
            }
            break;
        case INCOMMENT:
            if (c == '*')
                state = COMMENTING;
            else
            {
                token.type = DIV;
                return token;
            }
            break;
        case COMMENTING:
            if (c == '*')
                state = FINISH_COMMENT;
            else
                state = COMMENTING;
            break;
        case FINISH_COMMENT:
            if (c == '/')
                state = START;
            else
                state = COMMENTING;
            break;
        case INID:
            if (isalnum(c))
                token.lexeme[lexeme_index++] = c;
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

                log_lexeme(token);
                return token;
            }
            break;
        case INNUM:
            if (isdigit(c))
                token.lexeme[lexeme_index++] = c;
            else
            {
                token.lexeme[lexeme_index] = '\0';
                token.line = b->curr_line;
                token.type = NUMBER;

                go_back(b);

                log_lexeme(token);
                return token;
            }
            break;
        case INATRIB:
            if (c == '=')
                token.type = LOGICAL_EQ;
            else
            {
                token.type = ASSIGN;
                go_back(b);
            }
            log_lexeme(token);
            return token;
        case FAILURE:
            return token;
        }
    }
    token.type = END_OF_FILE;
    return token;
}
