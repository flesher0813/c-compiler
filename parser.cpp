/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include"node.h"
Block *programBlock;
extern int yylex();
void yyerror(const char *s) { printf("ERROR: %s\n", s); }
long long changeToInt(const char* str);
double changeToDouble(const char* str);

#line 79 "parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    Int = 258,
    Float = 259,
    Double = 260,
    Long = 261,
    Short = 262,
    Signed = 263,
    Char = 264,
    Unsigned = 265,
    Auto = 266,
    Bool = 267,
    Break = 268,
    Case = 269,
    Const = 270,
    Else = 271,
    For = 272,
    If = 273,
    Return = 274,
    While = 275,
    INT = 276,
    DOUBLE = 277,
    ID = 278,
    EQ = 279,
    GT = 280,
    LT = 281,
    EQEQ = 282,
    GE = 283,
    LE = 284,
    NE = 285,
    LPAREN = 286,
    RPAREN = 287,
    LBRACE = 288,
    RBRACE = 289,
    LMBRA = 290,
    RMBRA = 291,
    ADD = 292,
    SUB = 293,
    MUL = 294,
    DIV = 295,
    SEMI = 296,
    DOT = 297,
    COMMA = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "parser.y" /* yacc.c:355  */

	Node* node;
	Block *block;
	Statement *stmt;
	Expression *expr;
	Identifier *ident;
	ArrayIndex *index;
	VariableList *varvec;
	ExpressionList *exprvec;
	VariableDecration *var_decl;
	std::string *str;
	int token;

#line 177 "parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 194 "parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   288

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  108

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    56,    58,    62,    62,    63,    64,    65,
      66,    67,    71,    72,    73,    77,    81,    82,    85,    86,
      87,    91,    93,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   110,   111,   112,   116,   116,   116,
     116,   116,   116,   119,   123,   126,   127,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   144,   148,   149,
     154,   155,   156,   161,   165
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Int", "Float", "Double", "Long",
  "Short", "Signed", "Char", "Unsigned", "Auto", "Bool", "Break", "Case",
  "Const", "Else", "For", "If", "Return", "While", "INT", "DOUBLE", "ID",
  "EQ", "GT", "LT", "EQEQ", "GE", "LE", "NE", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "LMBRA", "RMBRA", "ADD", "SUB", "MUL", "DIV", "SEMI", "DOT",
  "COMMA", "$accept", "program", "stmts", "stmt", "var_decl", "func_decl",
  "block", "func_argv", "assign", "expr", "call_argv", "comprison",
  "ident", "array_index", "number", "primary_type", "array_type", "mytype",
  "if_stmt", "for_stmt", "while_stmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF -77

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-77)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     137,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -24,    -2,    -2,   -14,   -77,   -77,   -77,    -2,    60,
     137,   -77,   -77,   -77,   -77,   233,   243,    40,   -77,    37,
     -77,    50,   -77,   -77,   -77,    -2,   153,   233,    -2,   169,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    54,     4,    29,
      73,    70,   185,   -77,   -15,   -15,    22,    22,   233,   233,
     233,   -16,   201,   233,    51,    98,   276,    -2,   -77,   105,
       0,    55,   -77,    -2,   -77,   -77,    -2,   233,   -77,     2,
      50,   136,   -77,   -77,   -77,   -77,   233,    10,    55,   276,
      74,    -2,   -77,   -77,   -77,   217,    55,   -77
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,     0,     0,     0,     0,    45,    46,    43,     0,     0,
       2,     3,     5,     6,    23,     7,    25,    33,    26,    58,
      59,     0,     9,    10,    11,     0,     0,     8,     0,     0,
       1,     4,    37,    38,    39,    40,    41,    42,     0,     0,
       0,     0,     0,     0,    34,     0,     0,     0,    12,     0,
       0,    60,     0,    32,    29,    30,    27,    28,    31,    21,
      35,     0,     0,    22,     0,     0,    18,     0,    16,     0,
       0,     0,    24,     0,    44,    57,    34,    13,    19,     0,
       0,     0,    17,    61,    62,    64,    36,     0,     0,     0,
      12,     0,    14,    15,    20,     0,     0,    63
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -77,   -77,    39,   -18,   -68,   -77,   -76,   -77,   -77,   -12,
      11,   -77,   -28,   -77,   -77,   -77,   -77,   -67,    20,   -77,
     -77
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    19,    20,    21,    22,    23,    61,    89,    24,    25,
      71,    52,    26,    27,    28,    29,    30,    31,    32,    33,
      34
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      36,    37,    41,    58,    93,    95,    39,    35,    88,    90,
      42,    43,    44,    45,    46,    47,    82,    38,    12,    15,
      16,    17,   103,    59,    50,    51,    62,    83,    75,    18,
     107,   104,    90,    60,    98,    76,    64,    65,    66,    67,
      68,    69,    70,    72,    73,    99,   102,    42,    43,    44,
      45,    46,    47,    83,    42,    43,    44,    45,    46,    47,
      40,    41,   100,    87,    56,    91,    48,    49,    50,    51,
      77,    96,    57,    17,    70,    74,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    80,    85,    60,   105,
      11,    12,    13,    14,    15,    16,    17,    97,    75,    79,
      94,     0,     0,     0,    18,     0,     0,    78,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    15,
      16,    17,    11,    12,    13,    14,    15,    16,    17,    18,
       0,     0,     0,    86,     0,     0,    18,     0,     0,    92,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,     0,    11,    12,    13,    14,    15,    16,
      17,    42,    43,    44,    45,    46,    47,     0,    18,     0,
       0,     0,     0,    48,    49,    50,    51,   101,    42,    43,
      44,    45,    46,    47,     0,     0,    60,     0,     0,     0,
      48,    49,    50,    51,    42,    43,    44,    45,    46,    47,
       0,    63,     0,     0,     0,     0,    48,    49,    50,    51,
      42,    43,    44,    45,    46,    47,     0,    81,     0,     0,
       0,     0,    48,    49,    50,    51,    42,    43,    44,    45,
      46,    47,     0,     0,     0,     0,     0,    84,    48,    49,
      50,    51,    42,    43,    44,    45,    46,    47,     0,   106,
       0,     0,     0,     0,    48,    49,    50,    51,    42,    43,
      44,    45,    46,    47,     0,     0,     0,    53,     0,     0,
      48,    49,    50,    51,    54,     0,     0,     0,    55,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10
};

static const yytype_int8 yycheck[] =
{
      12,    13,    20,    31,    80,    81,    18,    31,    76,    76,
      25,    26,    27,    28,    29,    30,    32,    31,    18,    21,
      22,    23,    98,    35,    39,    40,    38,    43,    24,    31,
     106,    99,    99,    33,    32,    31,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    43,    36,    25,    26,    27,
      28,    29,    30,    43,    25,    26,    27,    28,    29,    30,
       0,    79,    90,    75,    24,    77,    37,    38,    39,    40,
      41,    83,    35,    23,    86,    21,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    16,    36,    33,   101,
      17,    18,    19,    20,    21,    22,    23,    86,    24,    60,
      80,    -1,    -1,    -1,    31,    -1,    -1,    34,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    21,
      22,    23,    17,    18,    19,    20,    21,    22,    23,    31,
      -1,    -1,    -1,    35,    -1,    -1,    31,    -1,    -1,    34,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      23,    25,    26,    27,    28,    29,    30,    -1,    31,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    25,    26,
      27,    28,    29,    30,    -1,    -1,    33,    -1,    -1,    -1,
      37,    38,    39,    40,    25,    26,    27,    28,    29,    30,
      -1,    32,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      25,    26,    27,    28,    29,    30,    -1,    32,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    25,    26,    27,    28,    29,    30,    -1,    32,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    24,    -1,    -1,
      37,    38,    39,    40,    31,    -1,    -1,    -1,    35,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    17,    18,    19,    20,    21,    22,    23,    31,    45,
      46,    47,    48,    49,    52,    53,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    31,    53,    53,    31,    53,
       0,    47,    25,    26,    27,    28,    29,    30,    37,    38,
      39,    40,    55,    24,    31,    35,    24,    35,    56,    53,
      33,    50,    53,    32,    53,    53,    53,    53,    53,    53,
      53,    54,    53,    53,    21,    24,    31,    41,    34,    46,
      16,    32,    32,    43,    36,    36,    35,    53,    48,    51,
      61,    53,    34,    50,    62,    50,    53,    54,    32,    43,
      56,    41,    36,    50,    48,    53,    32,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    47,
      47,    47,    48,    48,    48,    49,    50,    50,    51,    51,
      51,    52,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    54,    54,    54,    55,    55,    55,
      55,    55,    55,    56,    57,    58,    58,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    61,    61,
      62,    62,    62,    63,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     2,     1,
       1,     1,     2,     4,     6,     6,     2,     3,     0,     1,
       3,     3,     3,     1,     4,     1,     1,     3,     3,     3,
       3,     3,     3,     1,     0,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     1,
       3,     5,     5,     9,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 52 "parser.y" /* yacc.c:1646  */
    { programBlock = (yyvsp[0].block); }
#line 1382 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 56 "parser.y" /* yacc.c:1646  */
    { (yyval.block) = new Block(); (yyval.block)->statements.push_back((yyvsp[0].stmt)); }
#line 1388 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 58 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].block)->statements.push_back((yyvsp[0].stmt)); }
#line 1394 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 63 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ExpressionStatement(*(yyvsp[0].expr)); }
#line 1400 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 64 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ReturnStatement(*(yyvsp[0].expr)); }
#line 1406 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 65 "parser.y" /* yacc.c:1646  */
    { printf("if_stmt created\n"); }
#line 1412 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 66 "parser.y" /* yacc.c:1646  */
    { printf("for_stmt created\n"); }
#line 1418 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 67 "parser.y" /* yacc.c:1646  */
    { printf("while_stmt created\n"); }
#line 1424 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 71 "parser.y" /* yacc.c:1646  */
    {(yyval.stmt) = new VariableDecration(shared_ptr<Identifier>((yyvsp[-1].ident)),*(yyvsp[0].ident));  }
#line 1430 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 72 "parser.y" /* yacc.c:1646  */
    {(yyval.stmt) = new VariableDecration(shared_ptr<Identifier>((yyvsp[-3].ident)),*(yyvsp[-2].ident),(yyvsp[0].expr)); }
#line 1436 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 73 "parser.y" /* yacc.c:1646  */
    { auto varial = new VariableDecration(shared_ptr<Identifier>((yyvsp[-5].ident)),*(yyvsp[-4].ident)); (yyval.stmt) = new ArrayInitialization(*varial,*(yyvsp[-1].exprvec));}
#line 1442 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 77 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new FuncStatement(*(yyvsp[-5].ident),*(yyvsp[-4].ident),*(yyvsp[-2].varvec),*(yyvsp[0].block)); }
#line 1448 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 81 "parser.y" /* yacc.c:1646  */
    { (yyval.block) = new Block(); }
#line 1454 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 82 "parser.y" /* yacc.c:1646  */
    { (yyval.block) = (yyvsp[-1].block); }
#line 1460 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 85 "parser.y" /* yacc.c:1646  */
    { (yyval.varvec) = new VariableList(); }
#line 1466 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 86 "parser.y" /* yacc.c:1646  */
    { (yyval.varvec) = new VariableList(); (yyval.varvec)->push_back((yyvsp[0].var_decl)); }
#line 1472 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 87 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].varvec)->push_back((yyvsp[0].var_decl)); }
#line 1478 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 91 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new AssignExpression(*(yyvsp[-2].ident),*(yyvsp[0].expr)); }
#line 1484 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 93 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArrayAssignment(shared_ptr<ArrayIndex>((yyvsp[-2].index)),*(yyvsp[0].expr));}
#line 1490 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 97 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1496 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 98 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new CallExpression(*(yyvsp[-3].ident),*(yyvsp[-1].exprvec));}
#line 1502 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 99 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].ident);}
#line 1508 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 101 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression(shared_ptr<Expression>((yyvsp[-2].expr)),(yyvsp[-1].token),shared_ptr<Expression>((yyvsp[0].expr))); }
#line 1514 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 102 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression(shared_ptr<Expression>((yyvsp[-2].expr)),(yyvsp[-1].token),shared_ptr<Expression>((yyvsp[0].expr))); }
#line 1520 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 103 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression(shared_ptr<Expression>((yyvsp[-2].expr)),(yyvsp[-1].token),shared_ptr<Expression>((yyvsp[0].expr))); }
#line 1526 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 104 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression(shared_ptr<Expression>((yyvsp[-2].expr)),(yyvsp[-1].token),shared_ptr<Expression>((yyvsp[0].expr))); }
#line 1532 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 105 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression(shared_ptr<Expression>((yyvsp[-2].expr)),(yyvsp[-1].token),shared_ptr<Expression>((yyvsp[0].expr)));}
#line 1538 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 106 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr);}
#line 1544 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 107 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].index);}
#line 1550 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 110 "parser.y" /* yacc.c:1646  */
    { (yyval.exprvec) = new ExpressionList; }
#line 1556 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 111 "parser.y" /* yacc.c:1646  */
    { (yyval.exprvec) = new ExpressionList; (yyval.exprvec)->push_back((yyvsp[0].expr)); }
#line 1562 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 112 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].exprvec)->push_back((yyvsp[0].expr)); }
#line 1568 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 119 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = new Identifier(*(yyvsp[0].str)); }
#line 1574 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 123 "parser.y" /* yacc.c:1646  */
    { (yyval.index) = new ArrayIndex(*(yyvsp[-3].ident),shared_ptr<Expression>((yyvsp[-1].expr))); }
#line 1580 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 126 "parser.y" /* yacc.c:1646  */
    { long long a = std::stoll(*(yyvsp[0].str)); (yyval.expr) = new IntExpression(a); }
#line 1586 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 127 "parser.y" /* yacc.c:1646  */
    {double a = changeToDouble((yyvsp[0].str)->c_str()); (yyval.expr) = new DoubleExpression(a); }
#line 1592 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 131 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = new Identifier(*(yyvsp[0].str)); (yyval.ident)->isType = true; }
#line 1598 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 132 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = new Identifier(*(yyvsp[0].str)); (yyval.ident)->isType = true; }
#line 1604 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 133 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = new Identifier(*(yyvsp[0].str)); (yyval.ident)->isType = true; }
#line 1610 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 134 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = new Identifier(*(yyvsp[0].str)); (yyval.ident)->isType = true; }
#line 1616 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 135 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = new Identifier(*(yyvsp[0].str)); (yyval.ident)->isType = true; }
#line 1622 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 136 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = new Identifier(*(yyvsp[0].str)); (yyval.ident)->isType = true; }
#line 1628 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 137 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = new Identifier(*(yyvsp[0].str)); (yyval.ident)->isType = true; }
#line 1634 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = new Identifier(*(yyvsp[0].str)); (yyval.ident)->isType = true; }
#line 1640 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 139 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = new Identifier(*(yyvsp[0].str)); (yyval.ident)->isType = true; }
#line 1646 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = new Identifier(*(yyvsp[0].str)); (yyval.ident)->isType = true; }
#line 1652 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 144 "parser.y" /* yacc.c:1646  */
    {long long a = std::stoll(*(yyvsp[-1].str));  (yyvsp[-3].ident)->isArray = true; (yyvsp[-3].ident)->arraySize->push_back(make_shared<IntExpression>(a)); (yyval.ident) = (yyvsp[-3].ident);}
#line 1658 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 148 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = (yyvsp[0].ident);}
#line 1664 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 149 "parser.y" /* yacc.c:1646  */
    { (yyval.ident) = (yyvsp[0].ident);}
#line 1670 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 154 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new IfStatement(shared_ptr<Expression>((yyvsp[-1].expr)),shared_ptr<Block>((yyvsp[0].block))); }
#line 1676 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new IfStatement(shared_ptr<Expression>((yyvsp[-3].expr)),shared_ptr<Block>((yyvsp[-2].block)),shared_ptr<Block>((yyvsp[0].block))); }
#line 1682 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 156 "parser.y" /* yacc.c:1646  */
    { auto blk = new Block(); blk->statements.push_back((yyvsp[0].stmt)); 
		(yyval.stmt) = new IfStatement(shared_ptr<Expression>((yyvsp[-3].expr)),shared_ptr<Block>(blk)); }
#line 1689 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ForStatement(shared_ptr<Block>((yyvsp[0].block)),shared_ptr<Expression>((yyvsp[-6].expr)),shared_ptr<Expression>((yyvsp[-4].expr)),shared_ptr<Expression>((yyvsp[-2].expr))); }
#line 1695 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new ForStatement(shared_ptr<Block>((yyvsp[0].block)),nullptr,shared_ptr<Expression>((yyvsp[-2].expr)),nullptr); }
#line 1701 "parser.cpp" /* yacc.c:1646  */
    break;


#line 1705 "parser.cpp" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 167 "parser.y" /* yacc.c:1906  */


long long changeToInt(const char* str){
	long long sum = atol(str);
	return sum;
}

double changeToDouble(const char* str){
	double sum = atof(str);
	return sum;
}
