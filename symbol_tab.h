#ifndef SYMBOL_TAB_H
#define SYMBOL_TAB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

// Estrutura para armazenar informações sobre um identificador
typedef struct Symbol
{
    char *name;
    char *scope;
    char *type_id;   // INT, VOID, etc.
    char *type_data; // Variável ou função
    int line;
    struct Symbol *next; // Encadeamento para colidir hash
} Symbol;

// Estrutura para a tabela de símbolos (tabela hash)
typedef struct SymbolTable
{
    Symbol *table[TABLE_SIZE];
} SymbolTable;

extern SymbolTable *symbol_tab;

// Funções da tabela de símbolos
SymbolTable *create_symbol_table();
void insert_symbol(SymbolTable *symtab, const char *name, const char *scope,
                   const char *type_id, const char *type_data, int line);
Symbol *lookup_symbol(SymbolTable *symtab, const char *name, const char *scope);
void print_symbol_table(SymbolTable *symtab);
void free_symbol_table(SymbolTable *symtab);

#endif
