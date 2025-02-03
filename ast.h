#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ASTNode
{
    char *name;
    int line;
    struct ASTNode **children;
    int child_count;
} ASTNode;

ASTNode *create_node(const char *name, int line);
ASTNode *create_node_text(const char *text, int line);
ASTNode *create_node_int(int value, int line);
void add_child(ASTNode *parent, ASTNode *child);
void print_ast(ASTNode *node, int depth);
void free_ast(ASTNode *node);

#endif
