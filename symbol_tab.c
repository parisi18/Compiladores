#include "symbol_tab.h"

SymbolTable *symbol_tab = NULL;

// Função de hash simples
unsigned int hash(const char *str)
{
    unsigned int hash = 0;
    while (*str)
        hash = (hash << 5) + *str++;
    return hash % TABLE_SIZE;
}

// Criar tabela de símbolos
SymbolTable *create_symbol_table()
{
    SymbolTable *symtab = (SymbolTable *)malloc(sizeof(SymbolTable));
    for (int i = 0; i < TABLE_SIZE; i++)
        symtab->table[i] = NULL;
    return symtab;
}

// Inserir símbolo na tabela
void insert_symbol(SymbolTable *symtab, const char *name, const char *scope,
                   const char *type_id, const char *type_data, int line)
{
    unsigned int index = hash(name);
    Symbol *new_symbol = (Symbol *)malloc(sizeof(Symbol));

    new_symbol->name = strdup(name);
    new_symbol->scope = strdup(scope);
    new_symbol->type_id = strdup(type_id);
    new_symbol->type_data = strdup(type_data);
    new_symbol->line = line;
    new_symbol->next = symtab->table[index];

    symtab->table[index] = new_symbol;
}

// Buscar símbolo na tabela
Symbol *lookup_symbol(SymbolTable *symtab, const char *name, const char *scope)
{
    unsigned int index = hash(name);
    Symbol *symbol = symtab->table[index];

    while (symbol)
    {
        if (strcmp(symbol->name, name) == 0 && strcmp(symbol->scope, scope) == 0)
            return symbol;
        symbol = symbol->next;
    }
    return NULL;
}

// Imprimir tabela de símbolos
void print_symbol_table(SymbolTable *symtab)
{
    printf("\n# TABELA DE SÍMBOLOS\n");
    printf("Nome_ID\tEscopo\tTipo_ID\tTipo_dado\tLinha(s)\n");

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Symbol *symbol = symtab->table[i];
        while (symbol)
        {
            printf("%s\t%s\t%s\t%s\t%d\n",
                   symbol->name, symbol->scope, symbol->type_id, symbol->type_data, symbol->line);
            symbol = symbol->next;
        }
    }
}

// Liberar memória da tabela de símbolos
void free_symbol_table(SymbolTable *symtab)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Symbol *symbol = symtab->table[i];
        while (symbol)
        {
            Symbol *temp = symbol;
            symbol = symbol->next;
            free(temp->name);
            free(temp->scope);
            free(temp->type_id);
            free(temp->type_data);
            free(temp);
        }
    }
    free(symtab);
}
