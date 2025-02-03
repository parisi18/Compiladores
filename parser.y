%{ 
    #include <stdio.h>
    #include <stdlib.h>

    #define BISON_COMPILATION
    #include "parser.tab.h"
    #include "symbol_tab.h"
    #include "lexer.h"
    #include "ast.h"
    #include "semantic.h"

    extern Buffer *lexer_buffer;
    extern SymbolTable *symbol_tab;

    extern int yylineno; 
    extern int yycolumn; 
    extern int yylex();
    void yyerror(const char *s);

    struct ASTNode *root;
    char current_scope[100] = "global";
%}

%locations
%define parse.trace

%union{ 
    int ival;
    char *sval;
    struct ASTNode *node;
}

%token <sval> ID 
%token <ival> NUMBER
%token INT VOID ELSE IF RETURN WHILE
%token PLUS MINUS MULT DIV
%token LESS LESS_EQ GREATER GREATER_EQ LOGICAL_EQ NOT_EQ ASSIGN
%token SEMICOLON COMMA LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE

%left COMMA
%left LOGICAL_EQ NOT_EQ
%left LESS LESS_EQ GREATER GREATER_EQ
%left PLUS MINUS
%left MULT DIV
%left ELSE

%type <node> program declaration_list declaration var_declaration type_specifier params
%type <node> fun_declaration param_list param compound_stmt statement_list statement locals_declarations
%type <node> expression_stmt selection_stmt iteration_stmt return_stmt expression simple_expression 
%type <node> var relational sum_expression sum mult activation
%type <node> term factor args arg_list

%%

program:
    declaration_list {
        ASTNode *node = create_node("program", 0);
        add_child(node, $1);
        root = node;
    }
;

declaration_list: 
    declaration_list declaration {
        add_child($1, $2);
    }
    | declaration {
        $$ = $1;
    }
;

declaration:
    var_declaration { 
        $$ = $1;
    }
    | fun_declaration {         
        $$ = $1;
    }
;

var_declaration:
    type_specifier ID SEMICOLON {
        ASTNode *node = create_node("var_declaration", yylineno);
        add_child(node, $1);
        add_child($$, create_node_text($2, yylineno));

        // Verifica se a variável já foi declarada
        if (lookup_symbol(symbol_tab, $2, current_scope)) {
            printf("ERRO SEMÂNTICO: Variável '%s' já declarada. LINHA: %d\n", $2, yylineno);
        } else {
            insert_symbol(symbol_tab, $2, current_scope, $1->name, "variável", yylineno);
        }

        $$ = node;
    }
    | type_specifier ID LBRACKET NUMBER RBRACKET SEMICOLON
    {
        ASTNode *node = create_node("var_declaration", yylineno);
        add_child(node, $1);
        add_child(node, create_node($2, yylineno));
        add_child(node, create_node_int($4, yylineno));
        $$ = node;
    }
;

type_specifier:
    INT {
        $$= create_node("INT", yylineno);
    }
    | VOID {
        $$ = create_node("VOID", yylineno);
    }
;

fun_declaration:
    type_specifier ID LPAREN params RPAREN compound_stmt {
        ASTNode *node = create_node("fun_declaration", yylineno);
        add_child(node, $1);
        add_child(node, create_node_text($2, yylineno));
        add_child(node, $4);
        add_child(node, $6);

        // Verifica se a função já foi declarada
        if (lookup_symbol(symbol_tab, $2, "global")) {
            printf("ERRO SEMÂNTICO: Função '%s' já declarada. LINHA: %d\n", $2, yylineno);
        } else {
            insert_symbol(symbol_tab, $2, "global", $1->name, "função", yylineno);
        }

        // Atualiza o escopo para o nome da função
        strcpy(current_scope, $2);

        $$ = node;
    }
;

params:
    param_list{
        $$ = $1;
    }
    | 
    { 
        $$ = NULL;
    } 
;

param_list:
    param_list COMMA param {
        add_child($1, $3);
        $$ = $1;
    }
    | param {
        $$ = $1;
    }
;

param:
    type_specifier ID {
        ASTNode *node  = create_node("param", yylineno);
        add_child(node, $1);
        add_child(node, create_node_text($2, yylineno));
        $$ = node;
    }
    | type_specifier ID LBRACKET RBRACKET {
        ASTNode *node = create_node("param", yylineno);
        add_child(node, $1);
        add_child(node, create_node_text($2, yylineno));
        $$ = node;
    }
;

compound_stmt:
    LBRACE locals_declarations statement_list RBRACE {
        ASTNode *node = create_node("compound_stmt", yylineno);
        add_child(node, $2);
        add_child(node, $3);
        $$ = node;
    }
;

locals_declarations:
    locals_declarations var_declaration {
        add_child($1, $2);
        $$ = $1;
    }
    |  
    { 
        ASTNode *node = create_node("local_empty", yylineno); 
        $$ = node;
    } 
;

statement_list: 
    statement_list statement {
        add_child($1, $2);
        $$ = $1;
    }
    | 
    { 
        ASTNode *node = create_node("stmt_empty", yylineno);
        $$ = node;
    } 
;

statement:
    expression_stmt {
        $$ = $1;
    }
    | compound_stmt {
        $$ = $1;
    }
    | selection_stmt {
        $$ = $1;
    }
    | iteration_stmt {
        $$ = $1;
    }
    | return_stmt {
        $$ = $1;
    }
;

expression_stmt:
    expression SEMICOLON {
        $$ = $1;
    }
    | SEMICOLON {
        $$ = NULL;
    }
;

selection_stmt:
    IF LPAREN expression RPAREN statement {
        ASTNode *node = create_node("selection_stmt", yylineno);
        add_child(node, $3);
        add_child(node, $5);
        $$ = node;
    }
    | IF LPAREN expression RPAREN statement ELSE statement{
        ASTNode *node = create_node("selection_stmt", yylineno);
        add_child(node, $3);
        add_child(node, $5);
        add_child(node, create_node_text("ELSE", yylineno));
        add_child(node, $7);
        $$ = node;
    }
;

iteration_stmt:
    WHILE LPAREN expression RPAREN statement {
        ASTNode *node = create_node("iteration_stmt", yylineno);
        add_child(node, create_node_text("WHILE", yylineno));
        add_child(node, $3);
        add_child(node, $5);
        $$ = node;
    }
;

return_stmt:
    RETURN SEMICOLON {
        $$ = create_node_text("RETURN", yylineno);
    }
    | RETURN expression SEMICOLON {
        ASTNode *node = create_node("return_stmt", yylineno);
        add_child(node, create_node_text("RETURN", yylineno));
        add_child(node, $2);
        $$ = node;
    }
;

expression:
    var ASSIGN expression {
        ASTNode *node = create_node("expression", yylineno);
        add_child(node, $1);
        add_child(node, create_node_text("ASSIGN", yylineno));
        add_child(node, $3);
        $$ = node;

    }
    | simple_expression {
        $$ = $1;
    }
;

var:
    ID {
        ASTNode *node = create_node("var", yylineno);
        add_child(node, create_node_text($1, yylineno));
        $$ = node;
    }
    | ID LBRACKET expression RBRACKET {
        ASTNode *node = create_node("var", yylineno);
        add_child(node, create_node_text($1, yylineno));
        add_child(node, $3);
        $$ = node;
    }
;

simple_expression:
    sum_expression relational sum_expression {
        ASTNode *node = create_node("simple_expression", yylineno);
        add_child(node, $1);
        add_child(node, $2);
        add_child(node, $3);
        $$ = node;
    }
    | sum_expression {
        ASTNode *node = create_node("simple_expression", yylineno);
        add_child(node, $1);
        $$ = node;
    }
;

relational:
    LESS {
        $$ = create_node_text("<", yylineno);
    }
    | LESS_EQ {
        $$ = create_node_text("<=", yylineno);
    }
    | GREATER {
        $$ = create_node_text(">", yylineno);
    }
    | GREATER_EQ {
        $$ = create_node_text(">=", yylineno);
    }
    | LOGICAL_EQ {
        $$ = create_node_text("==", yylineno);
    }
    | NOT_EQ {
        $$ = create_node_text("!=", yylineno);
    }
;

sum_expression:
    sum_expression sum term {
        ASTNode *node = create_node("sum_expression", yylineno);
        add_child(node, $1);
        add_child(node, $2);
        add_child(node, $3);
        $$ = node;
    }
    | term {
        $$ = $1;
    }
;

sum:
    PLUS {
        $$ = create_node_text("+", yylineno);
    }
    | MINUS {
        $$ = create_node_text("-", yylineno);
    }
;

term:
    term mult factor {
        ASTNode *node = create_node("term", yylineno);
        add_child(node, $1);
        add_child(node, $2);
        add_child(node, $3);
        $$ = node;
    }
    | factor {
        ASTNode *node = create_node("term", yylineno);
        add_child(node, $1);
        $$ = node;
    }
;

mult:
    MULT {
        $$ = create_node_text("*", yylineno);
    }
    | DIV {
        $$ = create_node_text("/", yylineno);
    }
;

factor:
    LPAREN expression RPAREN {
        ASTNode *node = create_node("factor", yylineno);
        add_child(node, $2);
        $$ = node;
    }
    | var {
        $$ = $1;
    }
    | activation {
        $$ = $1;
    }
    | NUMBER {
        char *ival = (char *)malloc(16);
        sprintf(ival, "%d", $1);
        ASTNode *node = create_node_text(ival, yylineno);
        $$ = node;
    }
;

activation:
    ID LPAREN args RPAREN {
        ASTNode *node = create_node("activation", yylineno);
        add_child(node, create_node_text($1, yylineno));
        add_child(node, $3);
        $$ = node;
    }
;

args:
    arg_list {
        $$ = $1;
    }
    |
    {
        ASTNode *node = create_node("args_empy", yylineno);
        $$ = node;
    }
;

arg_list:
    arg_list COMMA expression {
        add_child($1, $3);
        $$ = $1;
    }
    | expression {

        ASTNode *node = create_node("arg_list", yylineno);
        add_child(node, $1);
        $$ = node;
    }
;

%%

void yyerror(const char *s)
{
    printf("ERRO SINTATICO: \"%s\" INVALIDO [linha: %d, COLUNA %d].\n", s, yylineno, yycolumn);
}