#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "symbol_tab.h"
#include "ast.h"

// Tabela de símbolos global para a análise semântica
extern SymbolTable *semantic_symbol_table;

// Função para verificar declarações e tipos
void semantic_analysis(ASTNode *node, const char *current_scope);

#endif
