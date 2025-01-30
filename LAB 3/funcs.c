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

    return b;
}

void dealocate_buffer(Buffer *b)
{
    if (b != NULL)
        free(b);
}

int load_chunk(Buffer *b)
{
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
            return 0;

        b->load_index += bytes_read;
        b->free_space -= bytes_read;
    }

    return 1;
}

char get_next_char(Buffer *b, char *words, int line_size)
{
    if (line_size > DATA_LEN)
    {
        printf("Error: line_size exceeds buffer capacity.\n");
        return ERR;
    }

    if (b->char_index >= b->load_index && !load_chunk(b))
        return EOF;

    if (b->char_index >= b->load_index)
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
    const char *keywords[] = {"else", "if", "int", "return", "void", "while"};

    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++)
    {
        if (strcmp(word, keywords[i]) == 0)
        {
            return i + 1;
        }
    }

    return 0;
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
    int i;

    while ((c = get_next_char(b, NULL, 0)) != EOF)
    {
        switch (state)
        {
        case START:
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
                state = INCOMENT;
            }
            else if (c == '=')
            {
                state = INATRIB;
            }
            break;
        case INID:
            if (isalnum(c))
            {
                token.lexeme[lexeme_index++] = c;
            }
            else
            {
                token.lexeme[lexeme_index++] = '\0';
                token.line = b->curr_line;

                if (token_idx = is_keyword(token.lexeme))
                {
                    token.type = (TokenType)token_idx;
                }
                else
                {
                    token.type = ID;
                }

                printf("Linha: %d, Lexema: %s, Token %s\n",
                       token.line,
                       token.lexeme,
                       token.type == KEYWORD ? "KEYWORD" : "ID");

                go_back(b);
                return token;
            }
            break;

        case INNUM:
            if (isdigit(c))
            {
                token.lexeme[lexeme_index++] = c;
            }
            else
            {
                token.lexeme[lexeme_index] = '\0';
                token.line = b->curr_line;
                token.type = NUMBER;

                printf("Linha: %d, Lexema: %s, Token: NUMBER\n",
                       token.line,
                       token.lexeme);

                go_back(b);
                return token;
            }
            break;

        case INCOMENT:
            if (c == '/')
            {
                state = COMMENT_1;
            }
            else if (c == '*')
            {

                state = COMMENT_2;
            }
            else
            {
                state = FAILURE;
            }
            break;
        case COMMENT_1:
            if (c == '\n')
                state = START;
        case COMMENT_2:
            if (c == '*')
                state = COMMENT_3;
        case COMMENT_3:
            if (c == '/')
                state = START;
            else
                state = COMMENT_2;
        case INATRIB:
            if (c == '=')
            {
                token.type = LOGICAL_EQ;
                printf("Linha: %d, Lexema: ==, Token: EQUAL\n", token.line);
            }
            else
            {
                token.type = ASSIGN;
                printf("Linha: %d, Lexema: =, Token: ASSIGN\n", token.line);
            }
            token.line = b->curr_line;
            return token;
            break;

        case FAILURE:
            printf("Erro léxico na linha %d: caractere desconhecido '%c'\n", line, c);
            state = FINISH;
            break;

        case FINISH:
            exit(1);
        }
    }
}