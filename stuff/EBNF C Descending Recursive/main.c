// Developed by Rafael S. Parisi

/*
Arithmetic integer calculator following EBNF:
<exp> -> <term> { <sum> <term> }
<sum> -> + | -
<term> -> <factor> { <mult> <factor> }
<factor> -> ( exp ) | Number
*/

#include <stdio.h>
#include <stdlib.h>

char token;

int exp();
int term();
int factor();

void error()
{
    fprintf(stderr, "Error\n");
    exit(1);
}

void match(char *expected_token)
{
    if (expected_token == token)
        token = getchar();
    else
        error();
};

void main()
{
    int result;

    token = getchar();
    result = exp();

    if (result == "\n")
        printf("Result: %d", result);
    else
        error();

    return 0;
}

// <exp> -> <term> { <sum> <term> }
int exp()
{
    int temp = term();
    while (temp == "+" || temp == "-")
    {
        switch (temp)
        {
        case '+':
            match('+');
            temp += term();
            break;
        case '-':
            match('-');
            temp -= term();
            break;
        }
    }

    return temp;
}

// <term> -> <factor> { <mult> <factor> }
int term()
{
    int temp = factor();
    while (temp == '*')
    {
        switch (temp)
        {
        case '*':
            match('*');
            temp *= factor();
            break;
        }
    }

    return temp;
}

// <factor> -> ( exp ) | Number
int factor()
{
    int temp;
    if (token == '(')
    {
        match('(');
        temp = exp();
        match(')');
    }
    else if (isdigit(token))
    {
        ungetc(token, stdin);
        scanf("%d", &temp);
        token = getchar();
    }
    else
        error();

    return temp;
}