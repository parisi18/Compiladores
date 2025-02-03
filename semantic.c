#include "semantic.h"

// Criar tabela de símbolos global
SymbolTable *semantic_symbol_table = NULL;

// Função de análise semântica
void semantic_analysis(ASTNode *node, const char *current_scope)
{
    if (node == NULL)
        return;

    // Caso seja uma declaração de variável
    if (strcmp(node->name, "var_declaration") == 0)
    {
        char *var_name = node->children[1]->name;
        if (lookup_symbol(semantic_symbol_table, var_name, current_scope))
        {
            printf("ERRO SEMÂNTICO: Variável '%s' já declarada. LINHA: %d\n", var_name, node->line);
        }
        else
        {
            insert_symbol(semantic_symbol_table, var_name, current_scope, node->children[0]->name, "Variável", node->line);
        }
    }

    // Caso seja uma declaração de função
    if (strcmp(node->name, "fun_declaration") == 0)
    {
        char *func_name = node->children[1]->name;
        if (lookup_symbol(semantic_symbol_table, func_name, "global"))
        {
            printf("ERRO SEMÂNTICO: Função '%s' já declarada. LINHA: %d\n", func_name, node->line);
        }
        else
        {
            insert_symbol(semantic_symbol_table, func_name, "global", node->children[0]->name, "Função", node->line);
        }
    }

    // Caso seja uma utilização de variável
    if (strcmp(node->name, "var") == 0)
    {
        char *var_name = node->children[0]->name;
        if (!lookup_symbol(semantic_symbol_table, var_name, current_scope))
        {
            printf("ERRO SEMÂNTICO: Variável '%s' não declarada. LINHA: %d\n", var_name, node->line);
        }
    }

    // Caso seja uma chamada de função
    if (strcmp(node->name, "activation") == 0)
    {
        char *func_name = node->children[0]->name;
        if (!lookup_symbol(semantic_symbol_table, func_name, "global"))
        {
            printf("ERRO SEMÂNTICO: Função '%s' não declarada. LINHA: %d\n", func_name, node->line);
        }
    }

    // Percorre os filhos do nó na AST para análise recursiva
    for (int i = 0; i < node->child_count; i++)
    {
        semantic_analysis(node->children[i], current_scope);
    }
}
