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

typedef struct STNode
{
    struct STNode **children;
    char *s;
    int value;
    int child_count;
} STNode;

char token;

STNode *exp();
STNode *term();
STNode *factor();
STNode *create_node(char *s);
void add_child(STNode *parent, STNode *child);
void free_st_node(STNode *node);
// ***NEED TO ADD SYNTAX TREE PRINT.***

STNode *create_node(char *s)
{
    STNode *node = (STNode *)malloc(sizeof(STNode));
    node->s = strdup(s);
    node->children = NULL;
    node->child_count = 0;

    return node;
}

void free_st_node(STNode *node)
{
    if (!node)
        return;

    for (int i = 0; i < node->child_count; i++)
    {
        free_st_node(node->children[i]);
    }

    free(node->children);
    free(node->s);
    free(node);
}

void add_child(STNode *parent, STNode *child)
{
    if (parent == NULL || child == NULL)
        return;

    parent->children = (STNode **)realloc(parent->children, parent->child_count + 1 * sizeof(STNode *));

    parent->children[parent->child_count++] = child;
}

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
    STNode *result = (STNode *)malloc(sizeof(STNode));

    token = getchar();
    result = exp();

    if (result->value == "\n")
        printf("Result: %d", result->value);
    else
        error();

    free(result);

    return 0;
}

// <exp> -> <term> { <sum> <term> }
STNode *exp()
{
    STNode *temp, *aux_temp;

    temp = term();
    while (temp->value == "+" || temp->value == "-")
    {
        aux_temp = create_node(temp->value);
        match(temp->value);
        add_child(aux_temp, temp);
        add_child(aux_temp, term());
        temp = aux_temp;
    }

    return temp;
}

// <term> -> <factor> { <mult> <factor> }
STNode *term()
{
    STNode *temp, *aux_temp;

    temp = factor();

    while (temp->value == '*')
    {
        aux_temp = create_node(temp->value);
        match('*');
        add_child(aux_temp, temp);
        add_child(aux_temp, factor());
        temp = aux_temp;
    }

    return temp;
}

// <factor> -> ( exp ) | Number
STNode *factor()
{
    STNode *temp, *aux_temp;
    if (token == '(')
    {
        match('(');
        temp = exp();
        aux_temp = create_node(temp->value);
        match(')');
        temp = aux_temp;
    }
    else if (isdigit(token))
    {
        ungetc(token, stdin);
        scanf("%d", &temp->value);
        token = getchar();
    }
    else
        error();

    return temp;
}