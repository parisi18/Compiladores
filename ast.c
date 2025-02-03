#include "ast.h"

ASTNode *create_node(const char *text, int line)
{
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->name = strdup(text); // Armazena o texto do nó
    node->line = line;
    node->child_count = 0;
    node->children = NULL;
    return node;
}

ASTNode *create_node_text(const char *text, int line)
{
    ASTNode *node = create_node(text, line);
    return node;
}

ASTNode *create_node_int(int value, int line)
{
    char *str[16];
    snprintf(str, sizeof(str), "%d", value);
    ASTNode *node = create_node(str, line);

    return node;
}

void add_child(ASTNode *parent, ASTNode *child)
{
    if (parent == NULL || child == NULL)
        return;

    parent->children = (ASTNode **)realloc(parent->children,
                                           (parent->child_count + 1) * sizeof(ASTNode *));
    parent->children[parent->child_count++] = child;
}

void print_ast(ASTNode *node, int depth)
{
    if (!node)
        return;

    // Indentação correta
    for (int i = 0; i < depth; i++)
        printf("  ");

    printf("<%s>", node->name);

    if (node->child_count > 0)
    {
        printf("(\n");

        for (int i = 0; i < node->child_count; i++)
        {
            print_ast(node->children[i], depth + 1);

            if (i < node->child_count - 1)
                printf(",\n");
        }

        // Fechamento correto da árvore
        for (int i = 0; i < depth; i++)
            printf("  ");
        printf(")");
    }

    printf("\n");
}

void free_ast(ASTNode *node)
{
    if (!node)
        return;

    for (int i = 0; i < node->child_count; i++)
    {
        free_ast(node->children[i]);
    }

    free(node->children);
    free(node->name);
    free(node);
}
