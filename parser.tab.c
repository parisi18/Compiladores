/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"
 
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

#line 94 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_NUMBER = 4,                     /* NUMBER  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_VOID = 6,                       /* VOID  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_RETURN = 9,                     /* RETURN  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_PLUS = 11,                      /* PLUS  */
  YYSYMBOL_MINUS = 12,                     /* MINUS  */
  YYSYMBOL_MULT = 13,                      /* MULT  */
  YYSYMBOL_DIV = 14,                       /* DIV  */
  YYSYMBOL_LESS = 15,                      /* LESS  */
  YYSYMBOL_LESS_EQ = 16,                   /* LESS_EQ  */
  YYSYMBOL_GREATER = 17,                   /* GREATER  */
  YYSYMBOL_GREATER_EQ = 18,                /* GREATER_EQ  */
  YYSYMBOL_LOGICAL_EQ = 19,                /* LOGICAL_EQ  */
  YYSYMBOL_NOT_EQ = 20,                    /* NOT_EQ  */
  YYSYMBOL_ASSIGN = 21,                    /* ASSIGN  */
  YYSYMBOL_SEMICOLON = 22,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 23,                     /* COMMA  */
  YYSYMBOL_LPAREN = 24,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 25,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 26,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 27,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 28,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 29,                    /* RBRACE  */
  YYSYMBOL_YYACCEPT = 30,                  /* $accept  */
  YYSYMBOL_program = 31,                   /* program  */
  YYSYMBOL_declaration_list = 32,          /* declaration_list  */
  YYSYMBOL_declaration = 33,               /* declaration  */
  YYSYMBOL_var_declaration = 34,           /* var_declaration  */
  YYSYMBOL_type_specifier = 35,            /* type_specifier  */
  YYSYMBOL_fun_declaration = 36,           /* fun_declaration  */
  YYSYMBOL_params = 37,                    /* params  */
  YYSYMBOL_param_list = 38,                /* param_list  */
  YYSYMBOL_param = 39,                     /* param  */
  YYSYMBOL_compound_stmt = 40,             /* compound_stmt  */
  YYSYMBOL_locals_declarations = 41,       /* locals_declarations  */
  YYSYMBOL_statement_list = 42,            /* statement_list  */
  YYSYMBOL_statement = 43,                 /* statement  */
  YYSYMBOL_expression_stmt = 44,           /* expression_stmt  */
  YYSYMBOL_selection_stmt = 45,            /* selection_stmt  */
  YYSYMBOL_iteration_stmt = 46,            /* iteration_stmt  */
  YYSYMBOL_return_stmt = 47,               /* return_stmt  */
  YYSYMBOL_expression = 48,                /* expression  */
  YYSYMBOL_var = 49,                       /* var  */
  YYSYMBOL_simple_expression = 50,         /* simple_expression  */
  YYSYMBOL_relational = 51,                /* relational  */
  YYSYMBOL_sum_expression = 52,            /* sum_expression  */
  YYSYMBOL_sum = 53,                       /* sum  */
  YYSYMBOL_term = 54,                      /* term  */
  YYSYMBOL_mult = 55,                      /* mult  */
  YYSYMBOL_factor = 56,                    /* factor  */
  YYSYMBOL_activation = 57,                /* activation  */
  YYSYMBOL_args = 58,                      /* args  */
  YYSYMBOL_arg_list = 59                   /* arg_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   94

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  101

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    56,    56,    64,    67,    73,    76,    82,    96,   107,
     110,   116,   138,   142,   148,   152,   158,   164,   173,   182,
     187,   194,   199,   206,   209,   212,   215,   218,   224,   227,
     233,   239,   250,   260,   263,   272,   280,   286,   291,   300,
     307,   315,   318,   321,   324,   327,   330,   336,   343,   349,
     352,   358,   365,   373,   376,   382,   387,   390,   393,   402,
     411,   415,   422,   426
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUMBER", "INT",
  "VOID", "ELSE", "IF", "RETURN", "WHILE", "PLUS", "MINUS", "MULT", "DIV",
  "LESS", "LESS_EQ", "GREATER", "GREATER_EQ", "LOGICAL_EQ", "NOT_EQ",
  "ASSIGN", "SEMICOLON", "COMMA", "LPAREN", "RPAREN", "LBRACKET",
  "RBRACKET", "LBRACE", "RBRACE", "$accept", "program", "declaration_list",
  "declaration", "var_declaration", "type_specifier", "fun_declaration",
  "params", "param_list", "param", "compound_stmt", "locals_declarations",
  "statement_list", "statement", "expression_stmt", "selection_stmt",
  "iteration_stmt", "return_stmt", "expression", "var",
  "simple_expression", "relational", "sum_expression", "sum", "term",
  "mult", "factor", "activation", "args", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-73)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      41,   -73,   -73,    17,    41,   -73,   -73,    26,   -73,   -73,
     -73,    35,   -73,    41,    51,    63,    12,    44,   -73,    42,
      45,    40,    41,    48,    46,   -73,   -73,   -73,   -73,   -73,
      41,   -73,    69,     3,   -18,    34,   -73,    50,    18,    52,
     -73,    32,   -73,   -73,   -73,   -73,   -73,   -73,   -73,    55,
      54,   -73,    33,    49,   -73,   -73,    32,    32,    32,   -73,
      56,    32,    57,   -73,    32,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,    32,    32,   -73,   -73,    32,   -73,    58,
      61,    59,    60,   -73,    62,   -73,   -73,   -73,    53,    49,
     -73,   -73,    32,   -73,     6,     6,   -73,    72,   -73,     6,
     -73
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     2,     4,     5,     0,     6,     1,
       3,     0,     7,    13,     0,     0,     0,    12,    15,     0,
      16,     0,     0,     0,     0,    20,    11,    14,     8,    17,
      22,    19,     0,     0,     0,    37,    58,     0,     0,     0,
      29,     0,    18,    24,    21,    23,    25,    26,    27,     0,
      56,    36,    40,    48,    52,    57,    61,     0,     0,    33,
       0,     0,     0,    28,     0,    49,    50,    41,    42,    43,
      44,    45,    46,     0,     0,    53,    54,     0,    63,     0,
      60,     0,     0,    34,     0,    55,    35,    56,    39,    47,
      51,    59,     0,    38,     0,     0,    62,    30,    32,     0,
      31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -73,   -73,   -73,    76,    64,    11,   -73,   -73,   -73,    66,
      68,   -73,   -73,   -56,   -73,   -73,   -73,   -73,   -38,   -72,
     -73,   -73,     8,   -73,    16,   -73,    14,   -73,   -73,   -73
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    16,    17,    18,
      43,    30,    33,    44,    45,    46,    47,    48,    49,    50,
      51,    73,    52,    74,    53,    77,    54,    55,    79,    80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      60,    87,    87,    62,    12,    87,    35,    36,    14,    35,
      36,    37,    38,    39,    37,    38,    39,     9,    78,    81,
      82,    35,    36,    84,    15,    40,    86,    41,    40,    11,
      41,    25,    42,    15,    25,    35,    36,    21,    97,    98,
      59,    32,    41,   100,    65,    66,     1,     2,    67,    68,
      69,    70,    71,    72,    96,    19,    41,    12,    56,    13,
      57,    14,    75,    76,    65,    66,    20,    22,    25,    23,
      28,    24,    34,    29,    58,    64,    61,    63,    83,    99,
      10,    88,    85,    91,    92,    94,    93,    95,    27,    26,
      89,    90,     0,     0,    31
};

static const yytype_int8 yycheck[] =
{
      38,    73,    74,    41,    22,    77,     3,     4,    26,     3,
       4,     8,     9,    10,     8,     9,    10,     0,    56,    57,
      58,     3,     4,    61,    13,    22,    64,    24,    22,     3,
      24,    28,    29,    22,    28,     3,     4,    25,    94,    95,
      22,    30,    24,    99,    11,    12,     5,     6,    15,    16,
      17,    18,    19,    20,    92,     4,    24,    22,    24,    24,
      26,    26,    13,    14,    11,    12,     3,    23,    28,    27,
      22,    26,     3,    27,    24,    21,    24,    22,    22,     7,
       4,    73,    25,    25,    23,    25,    27,    25,    22,    21,
      74,    77,    -1,    -1,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,    31,    32,    33,    34,    35,    36,     0,
      33,     3,    22,    24,    26,    35,    37,    38,    39,     4,
       3,    25,    23,    27,    26,    28,    40,    39,    22,    27,
      41,    34,    35,    42,     3,     3,     4,     8,     9,    10,
      22,    24,    29,    40,    43,    44,    45,    46,    47,    48,
      49,    50,    52,    54,    56,    57,    24,    26,    24,    22,
      48,    24,    48,    22,    21,    11,    12,    15,    16,    17,
      18,    19,    20,    51,    53,    13,    14,    55,    48,    58,
      59,    48,    48,    22,    48,    25,    48,    49,    52,    54,
      56,    25,    23,    27,    25,    25,    48,    43,    43,     7,
      43
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    33,    34,    34,    35,
      35,    36,    37,    37,    38,    38,    39,    39,    40,    41,
      41,    42,    42,    43,    43,    43,    43,    43,    44,    44,
      45,    45,    46,    47,    47,    48,    48,    49,    49,    50,
      50,    51,    51,    51,    51,    51,    51,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    56,    56,    57,
      58,    58,    59,    59
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     0,     3,     1,     2,     4,     4,     2,
       0,     2,     0,     1,     1,     1,     1,     1,     2,     1,
       5,     7,     5,     2,     3,     3,     1,     1,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     4,
       1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declaration_list  */
#line 56 "parser.y"
                     {
        ASTNode *node = create_node("program", 0);
        add_child(node, (yyvsp[0].node));
        root = node;
    }
#line 1328 "parser.tab.c"
    break;

  case 3: /* declaration_list: declaration_list declaration  */
#line 64 "parser.y"
                                 {
        add_child((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1336 "parser.tab.c"
    break;

  case 4: /* declaration_list: declaration  */
#line 67 "parser.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1344 "parser.tab.c"
    break;

  case 5: /* declaration: var_declaration  */
#line 73 "parser.y"
                    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 1352 "parser.tab.c"
    break;

  case 6: /* declaration: fun_declaration  */
#line 76 "parser.y"
                      {         
        (yyval.node) = (yyvsp[0].node);
    }
#line 1360 "parser.tab.c"
    break;

  case 7: /* var_declaration: type_specifier ID SEMICOLON  */
#line 82 "parser.y"
                                {
        ASTNode *node = create_node("var_declaration", yylineno);
        add_child(node, (yyvsp[-2].node));
        add_child((yyval.node), create_node_text((yyvsp[-1].sval), yylineno));

        // Verifica se a variável já foi declarada
        if (lookup_symbol(symbol_tab, (yyvsp[-1].sval), current_scope)) {
            printf("ERRO SEMÂNTICO: Variável '%s' já declarada. LINHA: %d\n", (yyvsp[-1].sval), yylineno);
        } else {
            insert_symbol(symbol_tab, (yyvsp[-1].sval), current_scope, (yyvsp[-2].node)->name, "variável", yylineno);
        }

        (yyval.node) = node;
    }
#line 1379 "parser.tab.c"
    break;

  case 8: /* var_declaration: type_specifier ID LBRACKET NUMBER RBRACKET SEMICOLON  */
#line 97 "parser.y"
    {
        ASTNode *node = create_node("var_declaration", yylineno);
        add_child(node, (yyvsp[-5].node));
        add_child(node, create_node((yyvsp[-4].sval), yylineno));
        add_child(node, create_node_int((yyvsp[-2].ival), yylineno));
        (yyval.node) = node;
    }
#line 1391 "parser.tab.c"
    break;

  case 9: /* type_specifier: INT  */
#line 107 "parser.y"
        {
        (yyval.node)= create_node("INT", yylineno);
    }
#line 1399 "parser.tab.c"
    break;

  case 10: /* type_specifier: VOID  */
#line 110 "parser.y"
           {
        (yyval.node) = create_node("VOID", yylineno);
    }
#line 1407 "parser.tab.c"
    break;

  case 11: /* fun_declaration: type_specifier ID LPAREN params RPAREN compound_stmt  */
#line 116 "parser.y"
                                                         {
        ASTNode *node = create_node("fun_declaration", yylineno);
        add_child(node, (yyvsp[-5].node));
        add_child(node, create_node_text((yyvsp[-4].sval), yylineno));
        add_child(node, (yyvsp[-2].node));
        add_child(node, (yyvsp[0].node));

        // Verifica se a função já foi declarada
        if (lookup_symbol(symbol_tab, (yyvsp[-4].sval), "global")) {
            printf("ERRO SEMÂNTICO: Função '%s' já declarada. LINHA: %d\n", (yyvsp[-4].sval), yylineno);
        } else {
            insert_symbol(symbol_tab, (yyvsp[-4].sval), "global", (yyvsp[-5].node)->name, "função", yylineno);
        }

        // Atualiza o escopo para o nome da função
        strcpy(current_scope, (yyvsp[-4].sval));

        (yyval.node) = node;
    }
#line 1431 "parser.tab.c"
    break;

  case 12: /* params: param_list  */
#line 138 "parser.y"
              {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1439 "parser.tab.c"
    break;

  case 13: /* params: %empty  */
#line 142 "parser.y"
    { 
        (yyval.node) = NULL;
    }
#line 1447 "parser.tab.c"
    break;

  case 14: /* param_list: param_list COMMA param  */
#line 148 "parser.y"
                           {
        add_child((yyvsp[-2].node), (yyvsp[0].node));
        (yyval.node) = (yyvsp[-2].node);
    }
#line 1456 "parser.tab.c"
    break;

  case 15: /* param_list: param  */
#line 152 "parser.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1464 "parser.tab.c"
    break;

  case 16: /* param: type_specifier ID  */
#line 158 "parser.y"
                      {
        ASTNode *node  = create_node("param", yylineno);
        add_child(node, (yyvsp[-1].node));
        add_child(node, create_node_text((yyvsp[0].sval), yylineno));
        (yyval.node) = node;
    }
#line 1475 "parser.tab.c"
    break;

  case 17: /* param: type_specifier ID LBRACKET RBRACKET  */
#line 164 "parser.y"
                                          {
        ASTNode *node = create_node("param", yylineno);
        add_child(node, (yyvsp[-3].node));
        add_child(node, create_node_text((yyvsp[-2].sval), yylineno));
        (yyval.node) = node;
    }
#line 1486 "parser.tab.c"
    break;

  case 18: /* compound_stmt: LBRACE locals_declarations statement_list RBRACE  */
#line 173 "parser.y"
                                                     {
        ASTNode *node = create_node("compound_stmt", yylineno);
        add_child(node, (yyvsp[-2].node));
        add_child(node, (yyvsp[-1].node));
        (yyval.node) = node;
    }
#line 1497 "parser.tab.c"
    break;

  case 19: /* locals_declarations: locals_declarations var_declaration  */
#line 182 "parser.y"
                                        {
        add_child((yyvsp[-1].node), (yyvsp[0].node));
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1506 "parser.tab.c"
    break;

  case 20: /* locals_declarations: %empty  */
#line 187 "parser.y"
    { 
        ASTNode *node = create_node("local_empty", yylineno); 
        (yyval.node) = node;
    }
#line 1515 "parser.tab.c"
    break;

  case 21: /* statement_list: statement_list statement  */
#line 194 "parser.y"
                             {
        add_child((yyvsp[-1].node), (yyvsp[0].node));
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1524 "parser.tab.c"
    break;

  case 22: /* statement_list: %empty  */
#line 199 "parser.y"
    { 
        ASTNode *node = create_node("stmt_empty", yylineno);
        (yyval.node) = node;
    }
#line 1533 "parser.tab.c"
    break;

  case 23: /* statement: expression_stmt  */
#line 206 "parser.y"
                    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1541 "parser.tab.c"
    break;

  case 24: /* statement: compound_stmt  */
#line 209 "parser.y"
                    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1549 "parser.tab.c"
    break;

  case 25: /* statement: selection_stmt  */
#line 212 "parser.y"
                     {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1557 "parser.tab.c"
    break;

  case 26: /* statement: iteration_stmt  */
#line 215 "parser.y"
                     {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1565 "parser.tab.c"
    break;

  case 27: /* statement: return_stmt  */
#line 218 "parser.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1573 "parser.tab.c"
    break;

  case 28: /* expression_stmt: expression SEMICOLON  */
#line 224 "parser.y"
                         {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1581 "parser.tab.c"
    break;

  case 29: /* expression_stmt: SEMICOLON  */
#line 227 "parser.y"
                {
        (yyval.node) = NULL;
    }
#line 1589 "parser.tab.c"
    break;

  case 30: /* selection_stmt: IF LPAREN expression RPAREN statement  */
#line 233 "parser.y"
                                          {
        ASTNode *node = create_node("selection_stmt", yylineno);
        add_child(node, (yyvsp[-2].node));
        add_child(node, (yyvsp[0].node));
        (yyval.node) = node;
    }
#line 1600 "parser.tab.c"
    break;

  case 31: /* selection_stmt: IF LPAREN expression RPAREN statement ELSE statement  */
#line 239 "parser.y"
                                                          {
        ASTNode *node = create_node("selection_stmt", yylineno);
        add_child(node, (yyvsp[-4].node));
        add_child(node, (yyvsp[-2].node));
        add_child(node, create_node_text("ELSE", yylineno));
        add_child(node, (yyvsp[0].node));
        (yyval.node) = node;
    }
#line 1613 "parser.tab.c"
    break;

  case 32: /* iteration_stmt: WHILE LPAREN expression RPAREN statement  */
#line 250 "parser.y"
                                             {
        ASTNode *node = create_node("iteration_stmt", yylineno);
        add_child(node, create_node_text("WHILE", yylineno));
        add_child(node, (yyvsp[-2].node));
        add_child(node, (yyvsp[0].node));
        (yyval.node) = node;
    }
#line 1625 "parser.tab.c"
    break;

  case 33: /* return_stmt: RETURN SEMICOLON  */
#line 260 "parser.y"
                     {
        (yyval.node) = create_node_text("RETURN", yylineno);
    }
#line 1633 "parser.tab.c"
    break;

  case 34: /* return_stmt: RETURN expression SEMICOLON  */
#line 263 "parser.y"
                                  {
        ASTNode *node = create_node("return_stmt", yylineno);
        add_child(node, create_node_text("RETURN", yylineno));
        add_child(node, (yyvsp[-1].node));
        (yyval.node) = node;
    }
#line 1644 "parser.tab.c"
    break;

  case 35: /* expression: var ASSIGN expression  */
#line 272 "parser.y"
                          {
        ASTNode *node = create_node("expression", yylineno);
        add_child(node, (yyvsp[-2].node));
        add_child(node, create_node_text("ASSIGN", yylineno));
        add_child(node, (yyvsp[0].node));
        (yyval.node) = node;

    }
#line 1657 "parser.tab.c"
    break;

  case 36: /* expression: simple_expression  */
#line 280 "parser.y"
                        {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1665 "parser.tab.c"
    break;

  case 37: /* var: ID  */
#line 286 "parser.y"
       {
        ASTNode *node = create_node("var", yylineno);
        add_child(node, create_node_text((yyvsp[0].sval), yylineno));
        (yyval.node) = node;
    }
#line 1675 "parser.tab.c"
    break;

  case 38: /* var: ID LBRACKET expression RBRACKET  */
#line 291 "parser.y"
                                      {
        ASTNode *node = create_node("var", yylineno);
        add_child(node, create_node_text((yyvsp[-3].sval), yylineno));
        add_child(node, (yyvsp[-1].node));
        (yyval.node) = node;
    }
#line 1686 "parser.tab.c"
    break;

  case 39: /* simple_expression: sum_expression relational sum_expression  */
#line 300 "parser.y"
                                             {
        ASTNode *node = create_node("simple_expression", yylineno);
        add_child(node, (yyvsp[-2].node));
        add_child(node, (yyvsp[-1].node));
        add_child(node, (yyvsp[0].node));
        (yyval.node) = node;
    }
#line 1698 "parser.tab.c"
    break;

  case 40: /* simple_expression: sum_expression  */
#line 307 "parser.y"
                     {
        ASTNode *node = create_node("simple_expression", yylineno);
        add_child(node, (yyvsp[0].node));
        (yyval.node) = node;
    }
#line 1708 "parser.tab.c"
    break;

  case 41: /* relational: LESS  */
#line 315 "parser.y"
         {
        (yyval.node) = create_node_text("<", yylineno);
    }
#line 1716 "parser.tab.c"
    break;

  case 42: /* relational: LESS_EQ  */
#line 318 "parser.y"
              {
        (yyval.node) = create_node_text("<=", yylineno);
    }
#line 1724 "parser.tab.c"
    break;

  case 43: /* relational: GREATER  */
#line 321 "parser.y"
              {
        (yyval.node) = create_node_text(">", yylineno);
    }
#line 1732 "parser.tab.c"
    break;

  case 44: /* relational: GREATER_EQ  */
#line 324 "parser.y"
                 {
        (yyval.node) = create_node_text(">=", yylineno);
    }
#line 1740 "parser.tab.c"
    break;

  case 45: /* relational: LOGICAL_EQ  */
#line 327 "parser.y"
                 {
        (yyval.node) = create_node_text("==", yylineno);
    }
#line 1748 "parser.tab.c"
    break;

  case 46: /* relational: NOT_EQ  */
#line 330 "parser.y"
             {
        (yyval.node) = create_node_text("!=", yylineno);
    }
#line 1756 "parser.tab.c"
    break;

  case 47: /* sum_expression: sum_expression sum term  */
#line 336 "parser.y"
                            {
        ASTNode *node = create_node("sum_expression", yylineno);
        add_child(node, (yyvsp[-2].node));
        add_child(node, (yyvsp[-1].node));
        add_child(node, (yyvsp[0].node));
        (yyval.node) = node;
    }
#line 1768 "parser.tab.c"
    break;

  case 48: /* sum_expression: term  */
#line 343 "parser.y"
           {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1776 "parser.tab.c"
    break;

  case 49: /* sum: PLUS  */
#line 349 "parser.y"
         {
        (yyval.node) = create_node_text("+", yylineno);
    }
#line 1784 "parser.tab.c"
    break;

  case 50: /* sum: MINUS  */
#line 352 "parser.y"
            {
        (yyval.node) = create_node_text("-", yylineno);
    }
#line 1792 "parser.tab.c"
    break;

  case 51: /* term: term mult factor  */
#line 358 "parser.y"
                     {
        ASTNode *node = create_node("term", yylineno);
        add_child(node, (yyvsp[-2].node));
        add_child(node, (yyvsp[-1].node));
        add_child(node, (yyvsp[0].node));
        (yyval.node) = node;
    }
#line 1804 "parser.tab.c"
    break;

  case 52: /* term: factor  */
#line 365 "parser.y"
             {
        ASTNode *node = create_node("term", yylineno);
        add_child(node, (yyvsp[0].node));
        (yyval.node) = node;
    }
#line 1814 "parser.tab.c"
    break;

  case 53: /* mult: MULT  */
#line 373 "parser.y"
         {
        (yyval.node) = create_node_text("*", yylineno);
    }
#line 1822 "parser.tab.c"
    break;

  case 54: /* mult: DIV  */
#line 376 "parser.y"
          {
        (yyval.node) = create_node_text("/", yylineno);
    }
#line 1830 "parser.tab.c"
    break;

  case 55: /* factor: LPAREN expression RPAREN  */
#line 382 "parser.y"
                             {
        ASTNode *node = create_node("factor", yylineno);
        add_child(node, (yyvsp[-1].node));
        (yyval.node) = node;
    }
#line 1840 "parser.tab.c"
    break;

  case 56: /* factor: var  */
#line 387 "parser.y"
          {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1848 "parser.tab.c"
    break;

  case 57: /* factor: activation  */
#line 390 "parser.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1856 "parser.tab.c"
    break;

  case 58: /* factor: NUMBER  */
#line 393 "parser.y"
             {
        char *ival = (char *)malloc(16);
        sprintf(ival, "%d", (yyvsp[0].ival));
        ASTNode *node = create_node_text(ival, yylineno);
        (yyval.node) = node;
    }
#line 1867 "parser.tab.c"
    break;

  case 59: /* activation: ID LPAREN args RPAREN  */
#line 402 "parser.y"
                          {
        ASTNode *node = create_node("activation", yylineno);
        add_child(node, create_node_text((yyvsp[-3].sval), yylineno));
        add_child(node, (yyvsp[-1].node));
        (yyval.node) = node;
    }
#line 1878 "parser.tab.c"
    break;

  case 60: /* args: arg_list  */
#line 411 "parser.y"
             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1886 "parser.tab.c"
    break;

  case 61: /* args: %empty  */
#line 415 "parser.y"
    {
        ASTNode *node = create_node("args_empy", yylineno);
        (yyval.node) = node;
    }
#line 1895 "parser.tab.c"
    break;

  case 62: /* arg_list: arg_list COMMA expression  */
#line 422 "parser.y"
                              {
        add_child((yyvsp[-2].node), (yyvsp[0].node));
        (yyval.node) = (yyvsp[-2].node);
    }
#line 1904 "parser.tab.c"
    break;

  case 63: /* arg_list: expression  */
#line 426 "parser.y"
                 {

        ASTNode *node = create_node("arg_list", yylineno);
        add_child(node, (yyvsp[0].node));
        (yyval.node) = node;
    }
#line 1915 "parser.tab.c"
    break;


#line 1919 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 434 "parser.y"


void yyerror(const char *s)
{
    printf("ERRO SINTATICO: \"%s\" INVALIDO [linha: %d, COLUNA %d].\n", s, yylineno, yycolumn);
}
