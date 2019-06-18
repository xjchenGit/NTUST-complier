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
#line 1 "test2.y" /* yacc.c:339  */

#include <iostream>
#include <stdio.h>
#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include "Symbol.hpp"
#include "lex.yy.cpp"
using namespace std;
#define TRACE_FLAG 1
#define Trace(t) if (TRACE_FLAG) cout << "TRACE => " << t <<endl;

string outName;
ofstream out;

int yylex();
void yyerror(string error_str);
vector<SymbolTable> stack;
SymbolTable SymbolList;
vector<string> id_arr;
int args_num=0;
string funcname;
DataItem* lookupAll(string s);
DataItem* lookupAllAddress(string s);

int LabalCount=0;
int NowCount=0;
int whilebegin=0;


#line 100 "y.tab.cpp" /* yacc.c:339  */

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
   by #include "y.tab.hpp".  */
#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
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
    AND = 258,
    OR = 259,
    EQ = 260,
    LE_EQ = 261,
    GR_EQ = 262,
    NEQ = 263,
    ARRAY = 264,
    BOOLEAN = 265,
    _BEGIN = 266,
    BREAK = 267,
    CHAR = 268,
    CASE = 269,
    CONST = 270,
    CONTINUE = 271,
    DO = 272,
    ELSE = 273,
    END = 274,
    EXIT = 275,
    FALSE = 276,
    FOR = 277,
    FN = 278,
    IF = 279,
    IN = 280,
    INTEGER = 281,
    LOOP = 282,
    MODULE = 283,
    PRINT = 284,
    PRINTLN = 285,
    PROCEDURE = 286,
    REPEAT = 287,
    RETURN = 288,
    REAL = 289,
    STRING = 290,
    RECORD = 291,
    THEN = 292,
    TURE = 293,
    TYPE = 294,
    USE = 295,
    UTIL = 296,
    VAR = 297,
    WHILE = 298,
    OF = 299,
    IDENTIFIER = 300,
    INT_CONST = 301,
    STR_CONST = 302,
    BOOLEAN_CONST = 303,
    REAL_CONST = 304,
    UMINUS = 305
  };
#endif
/* Tokens.  */
#define AND 258
#define OR 259
#define EQ 260
#define LE_EQ 261
#define GR_EQ 262
#define NEQ 263
#define ARRAY 264
#define BOOLEAN 265
#define _BEGIN 266
#define BREAK 267
#define CHAR 268
#define CASE 269
#define CONST 270
#define CONTINUE 271
#define DO 272
#define ELSE 273
#define END 274
#define EXIT 275
#define FALSE 276
#define FOR 277
#define FN 278
#define IF 279
#define IN 280
#define INTEGER 281
#define LOOP 282
#define MODULE 283
#define PRINT 284
#define PRINTLN 285
#define PROCEDURE 286
#define REPEAT 287
#define RETURN 288
#define REAL 289
#define STRING 290
#define RECORD 291
#define THEN 292
#define TURE 293
#define TYPE 294
#define USE 295
#define UTIL 296
#define VAR 297
#define WHILE 298
#define OF 299
#define IDENTIFIER 300
#define INT_CONST 301
#define STR_CONST 302
#define BOOLEAN_CONST 303
#define REAL_CONST 304
#define UMINUS 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 35 "test2.y" /* yacc.c:355  */

    int _val;
    double d_val;
    std::string* s_val;
    DataItem* id_data;
    bool b_val;
    int type;

#line 249 "y.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 266 "y.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   425

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    57,     2,     2,
      64,    65,    55,    53,    63,    54,    60,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    62,    61,
      50,    52,    51,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    58,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    72,    72,    83,    89,    94,    71,   108,   109,   110,
     113,   114,   115,   119,   129,   118,   160,   164,   166,   171,
     178,   186,   207,   229,   234,   239,   242,   243,   246,   262,
     278,   281,   282,   283,   284,   287,   293,   299,   305,   313,
     369,   369,   382,   382,   393,   397,   401,   402,   403,   406,
     457,   469,   470,   492,   502,   512,   541,   559,   582,   604,
     616,   627,   638,   649,   660,   671,   681,   685,   695,   705,
     710,   703,   724,   733,   739,   732,   753,   754,   757,   776,
     777
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "OR", "EQ", "LE_EQ", "GR_EQ",
  "NEQ", "ARRAY", "BOOLEAN", "_BEGIN", "BREAK", "CHAR", "CASE", "CONST",
  "CONTINUE", "DO", "ELSE", "END", "EXIT", "FALSE", "FOR", "FN", "IF",
  "IN", "INTEGER", "LOOP", "MODULE", "PRINT", "PRINTLN", "PROCEDURE",
  "REPEAT", "RETURN", "REAL", "STRING", "RECORD", "THEN", "TURE", "TYPE",
  "USE", "UTIL", "VAR", "WHILE", "OF", "IDENTIFIER", "INT_CONST",
  "STR_CONST", "BOOLEAN_CONST", "REAL_CONST", "'<'", "'>'", "'='", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'~'", "UMINUS", "'.'", "';'", "':'", "','",
  "'('", "')'", "$accept", "program", "$@1", "$@2", "$@3", "$@4",
  "optional_var_con_declaration", "Procedure_dec_list", "Procedure_dec",
  "$@5", "$@6", "pro_dec2", "opt_func_type", "constants", "variables",
  "opt_IDENTIFIER", "optional_arg_parentheses", "optional_arguments",
  "data_type", "const_value", "statement", "$@7", "$@8", "expression",
  "conditional_statement", "$@9", "$@10", "condition_title",
  "loop_statement", "$@11", "$@12", "optional_statement",
  "function_invocation", "optional_comma_separated_expression", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
      60,    62,    61,    43,    45,    42,    47,    37,   126,   305,
      46,    59,    58,    44,    40,    41
};
# endif

#define YYPACT_NINF -90

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-90)))

#define YYTABLE_NINF -43

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -11,   -24,    26,   -90,   -90,     7,   -14,   -13,    -2,    20,
       7,    12,     6,     7,     4,   361,    31,    20,   -90,   -90,
     361,   -13,   -90,    -7,    14,   -90,   -90,   -90,   -90,   361,
     361,   361,   -90,   101,   -90,   -90,    74,   -90,   122,   -90,
     -90,   -90,   -90,   -90,    32,   361,   -90,   -90,     3,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   -90,    24,   -90,   -90,   -33,   234,   -45,   -90,
     265,   250,    27,    27,   273,    27,    27,    27,   -32,   -32,
     -90,   -90,   -90,    47,    33,   327,   -90,   361,   -90,    35,
       0,    -7,   -90,    30,   341,    34,    -3,   307,    70,    76,
     138,   -90,   327,   -90,   -90,   234,    -7,    65,   -90,   -90,
       7,   361,   -90,   157,   -90,   361,   -90,   361,   361,   -90,
      92,    93,   -90,    52,   104,    71,    67,   -90,   361,   178,
     194,   213,    66,   113,    98,    -7,   327,    86,   112,    83,
     -90,   -90,   -90,   -90,   -90,    90,   -90,   140,   -90,   -90,
     149,   327,   -90,   -90,   -90,   148,   327,   107,   150,   -90,
     109,   -90
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     9,     0,    25,     0,    12,
       9,     0,    24,     9,     0,     0,     0,     3,    11,     7,
       0,    25,     8,     0,    49,    36,    35,    37,    38,     0,
       0,     0,    50,     0,    51,    13,     0,    10,     0,    23,
      33,    32,    34,    31,     0,     0,    67,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,    27,     4,    19,    22,    79,     0,    66,
      53,    54,    62,    63,    64,    59,    60,    61,    57,    58,
      52,    55,    56,    30,    18,    40,    21,     0,    78,     0,
       0,     0,    14,     0,     0,     0,    49,    77,     0,     0,
       0,    47,    40,    48,     5,    80,     0,     0,    26,    17,
       9,     0,    44,     0,    73,     0,    76,     0,     0,    46,
      69,     0,    28,     0,     0,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,    40,     0,     0,     0,
      39,    41,    43,    68,    70,     0,    29,     0,    15,    72,
       0,    40,     6,    16,    74,     0,    40,     0,     0,    71,
       0,    75
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -90,   -90,   -90,   -90,   -90,   -90,    -9,   -90,   154,   -90,
     -90,   -90,   -90,   -90,   114,   166,   -90,   -90,   -58,   -90,
     -90,   -90,   -90,   -15,   -90,   -90,   -90,   -90,   -90,   -90,
     -90,   -89,   -90,   -90
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    36,    85,   121,     9,    17,    18,    63,
     110,   125,    92,    10,    13,    14,    84,    90,    44,    32,
      97,    98,    99,   100,   101,   133,   151,   102,   103,   128,
     156,   104,    34,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,    19,   115,    40,    22,    38,    49,    50,   116,    51,
      52,    53,    12,   120,    46,    47,    48,     1,    87,    41,
      88,     3,     6,    59,    60,    61,     4,    42,    43,   -25,
      67,    11,    12,   109,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,   147,   122,     7,
      15,    16,     8,    54,    55,    56,    57,    58,    59,    60,
      61,    45,   155,   107,    20,   108,    23,   158,    69,    21,
      49,    50,   105,    51,    52,    53,    35,   146,    45,   113,
      57,    58,    59,    60,    61,    64,    49,    50,    83,    51,
      52,    53,    89,    66,   111,    91,   126,   106,   114,   117,
     129,   124,   130,   131,    49,    50,   118,    51,    52,    53,
     123,   132,   134,   139,   135,   136,   137,    54,    55,    56,
      57,    58,    59,    60,    61,    49,    50,   143,    51,    52,
      53,   144,   138,    54,    55,    56,    57,    58,    59,    60,
      61,    49,    50,   145,    51,    52,    53,   148,   150,   149,
     152,    54,    55,    56,    57,    58,    59,    60,    61,   153,
      49,    50,    62,    51,    52,    53,   154,   157,   159,   160,
     161,    37,    54,    55,    56,    57,    58,    59,    60,    61,
      86,    49,    50,    65,    51,    52,    53,    39,    54,    55,
      56,    57,    58,    59,    60,    61,     0,    49,    50,   119,
      51,    52,    53,     0,     0,     0,     0,    54,    55,    56,
      57,    58,    59,    60,    61,     0,    49,    50,   127,    51,
      52,    53,     0,     0,     0,     0,     0,     0,    54,    55,
      56,    57,    58,    59,    60,    61,     0,    49,    50,   140,
      51,    52,    53,     0,    54,    55,    56,    57,    58,    59,
      60,    61,     0,    49,     0,   141,    51,    52,    53,     0,
       0,     0,     0,    54,    55,    56,    57,    58,    59,    60,
      61,    51,    52,    53,   142,     0,     0,     0,     0,    51,
      52,     0,     0,     0,    54,    55,    56,    57,    58,    59,
      60,    61,     0,     0,     0,     0,     0,     0,     0,     0,
      54,    55,    56,    57,    58,    59,    60,    61,     0,     0,
       0,     0,     0,     0,     0,    54,    55,    56,    57,    58,
      59,    60,    61,    54,    55,    56,    57,    58,    59,    60,
      61,    93,     0,     0,     0,     0,   -40,   -42,     0,     0,
      94,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    93,    96,    25,    26,    27,    28,   -42,     0,     0,
      94,    29,     0,     0,     0,    30,     0,     0,     0,     0,
      95,    31,    96,    25,    26,    27,    28,     0,     0,     0,
       0,    29,     0,     0,     0,    30,    24,    25,    26,    27,
      28,    31,     0,     0,     0,    29,     0,     0,     0,    30,
       0,     0,   112,     0,     0,    31,    24,    25,    26,    27,
      28,     0,     0,     0,     0,    29,     0,     0,     0,    30,
       0,     0,     0,     0,     0,    31
};

static const yytype_int16 yycheck[] =
{
      15,    10,     5,    10,    13,    20,     3,     4,    97,     6,
       7,     8,    45,   102,    29,    30,    31,    28,    63,    26,
      65,    45,    15,    55,    56,    57,     0,    34,    35,    62,
      45,    45,    45,    91,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   136,   106,    42,
      52,    31,    45,    50,    51,    52,    53,    54,    55,    56,
      57,    64,   151,    63,    52,    65,    62,   156,    65,    63,
       3,     4,    87,     6,     7,     8,    45,   135,    64,    94,
      53,    54,    55,    56,    57,    11,     3,     4,    64,     6,
       7,     8,    45,    61,    64,    62,   111,    62,    64,    29,
     115,   110,   117,   118,     3,     4,    30,     6,     7,     8,
      45,    19,    19,   128,    62,    11,    45,    50,    51,    52,
      53,    54,    55,    56,    57,     3,     4,    61,     6,     7,
       8,    18,    65,    50,    51,    52,    53,    54,    55,    56,
      57,     3,     4,    45,     6,     7,     8,    61,    65,    37,
      60,    50,    51,    52,    53,    54,    55,    56,    57,    19,
       3,     4,    61,     6,     7,     8,    17,    19,    61,    19,
      61,    17,    50,    51,    52,    53,    54,    55,    56,    57,
      66,     3,     4,    61,     6,     7,     8,    21,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,     3,     4,    61,
       6,     7,     8,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,     3,     4,    61,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,     3,     4,    61,
       6,     7,     8,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,     3,    -1,    61,     6,     7,     8,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,     6,     7,     8,    61,    -1,    -1,    -1,    -1,     6,
       7,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    50,    51,    52,    53,    54,    55,    56,
      57,    24,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    24,    45,    46,    47,    48,    49,    30,    -1,    -1,
      33,    54,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      43,    64,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    58,    45,    46,    47,    48,
      49,    64,    -1,    -1,    -1,    54,    -1,    -1,    -1,    58,
      -1,    -1,    61,    -1,    -1,    64,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    67,    45,     0,    68,    15,    42,    45,    72,
      79,    45,    45,    80,    81,    52,    31,    73,    74,    72,
      52,    63,    72,    62,    45,    46,    47,    48,    49,    54,
      58,    64,    85,    89,    98,    45,    69,    74,    89,    81,
      10,    26,    34,    35,    84,    64,    89,    89,    89,     3,
       4,     6,     7,     8,    50,    51,    52,    53,    54,    55,
      56,    57,    61,    75,    11,    61,    61,    89,    99,    65,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    64,    82,    70,    80,    63,    65,    45,
      83,    62,    78,    24,    33,    43,    45,    86,    87,    88,
      89,    90,    93,    94,    97,    89,    62,    63,    65,    84,
      76,    64,    61,    89,    64,     5,    97,    29,    30,    61,
      97,    71,    84,    45,    72,    77,    89,    61,    95,    89,
      89,    89,    19,    91,    19,    62,    11,    45,    65,    89,
      61,    61,    61,    61,    18,    45,    84,    97,    61,    37,
      65,    92,    60,    19,    17,    97,    96,    19,    97,    61,
      19,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    68,    69,    70,    71,    67,    72,    72,    72,
      73,    73,    73,    75,    76,    74,    77,    78,    78,    79,
      79,    80,    80,    81,    81,    81,    82,    82,    83,    83,
      83,    84,    84,    84,    84,    85,    85,    85,    85,    86,
      87,    86,    88,    86,    86,    86,    86,    86,    86,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    90,    91,
      92,    90,    93,    95,    96,    94,    97,    97,    98,    99,
      99
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,    13,     2,     3,     0,
       2,     1,     0,     0,     0,     9,     4,     2,     0,     5,
       4,     5,     4,     3,     1,     0,     3,     0,     3,     5,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       0,     4,     0,     4,     2,     3,     2,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     2,     4,     0,
       0,     8,     5,     0,     0,    10,     2,     1,     4,     1,
       3
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
#line 72 "test2.y" /* yacc.c:1646  */
    {
                out << "class " << *(yyvsp[0].s_val) << endl;
                out << "{" << endl;
                outName=*(yyvsp[0].s_val);

                DataItem* id = new DataItem();
                id->IdName=*(yyvsp[0].s_val);
                id->entries="module";
                int a=stack.back().insert(*(yyvsp[0].s_val),*id);
            }
#line 1527 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 83 "test2.y" /* yacc.c:1646  */
    {
                stack.back().Dump();
                out  << "\tmethod public static void main(java.lang.String[])\n" << "\tmax_stack 15\n" << "\tmax_locals 15\n\t{\n";
                
            }
#line 1537 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 89 "test2.y" /* yacc.c:1646  */
    {
                SymbolTable tempData;
                stack.push_back(tempData);
             }
#line 1546 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 94 "test2.y" /* yacc.c:1646  */
    {
                 out << "\t\treturn\n";
                 out << "\t}";
             }
#line 1555 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 99 "test2.y" /* yacc.c:1646  */
    {
                out << "\n}\n";

                stack.back().Dump();
                stack.pop_back();
                if(*(yyvsp[-11].s_val)!=*(yyvsp[-1].s_val))
                    yyerror("End's id != Module's id\n");
            }
#line 1568 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 119 "test2.y" /* yacc.c:1646  */
    {
                    DataItem* func_id = new DataItem();
                    func_id->IdName=*(yyvsp[0].s_val);
                    func_id->entries="Procedure";
                    funcname = *(yyvsp[0].s_val);
                    stack[0].insert(*(yyvsp[0].s_val),*func_id);
                    SymbolTable temp;
                    stack.push_back(temp);
                }
#line 1582 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 129 "test2.y" /* yacc.c:1646  */
    {
                    out << "\tmethod public static ";
                    out << "int ";
                        //out << "void ";后期需要补充
                    out << *(yyvsp[-3].s_val) + "(";
                    for (int i = 0; i < args_num; i++) {
                        if(i!=0) out << ",";
                        out << "int";
                    }
                    cout << "test module1"<<endl;
                    out << ")\n" << "\tmax_stack 15\n" << "\tmax_locals 15\n\t{\n";
                    args_num=0;
                    DataItem* func_id = stack[0].lookupAddress(funcname);
                    func_id->type=(yyvsp[0].type);
                    stack[0].Dump();
                    cout << "test module2"<<endl;
                }
#line 1604 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 147 "test2.y" /* yacc.c:1646  */
    {
                    out << "\t}\n";
                    cout << "test error" << endl;
                    if(*(yyvsp[-7].s_val)!=*(yyvsp[-1].s_val))
                        yyerror("End's id != Procedure's id");
                    stack.back().Dump();
                    cout<<stack.size()<<endl;
                    stack.pop_back();
                    cout <<stack.size()<<endl;
                    cout <<"test error 2" <<endl;
                }
#line 1620 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 164 "test2.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].type);}
#line 1626 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 166 "test2.y" /* yacc.c:1646  */
    {Trace("null");}
#line 1632 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 172 "test2.y" /* yacc.c:1646  */
    {
            (yyvsp[-1].id_data) -> IdName = *(yyvsp[-3].s_val);
            (yyvsp[-1].id_data) -> entries = "const";
            int a=stack.back().insert(*(yyvsp[-3].s_val),*((yyvsp[-1].id_data)));
            
        }
#line 1643 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 179 "test2.y" /* yacc.c:1646  */
    {
            (yyvsp[-1].id_data) -> IdName = *(yyvsp[-3].s_val);
            (yyvsp[-1].id_data) -> entries = "const";
            int a=stack.back().insert(*(yyvsp[-3].s_val),*((yyvsp[-1].id_data)));
        }
#line 1653 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 187 "test2.y" /* yacc.c:1646  */
    {
                for(int i=0;i<id_arr.size();i++){
                    DataItem* tempData = new DataItem();
                    tempData->IdName = id_arr[i];
                    tempData->type = (yyvsp[-2].type);
                    tempData->entries = "variables";
                    int a=stack.back().insert(id_arr[i],*tempData);
                    
                    cout << "insert successed!!!!  1" <<endl;
                    if((yyvsp[-2].type)==INTEGER_type){
                        out << "\tfield static int "<<id_arr[i]<<"\n";
                    }else if((yyvsp[-2].type)==STRING_type){
                        out << "\tfield static java.lang.String "<<id_arr[i]<<"\n";
                    }else if((yyvsp[-2].type)==REAL_type){
                        out << "\tfield static double "<<id_arr[i]<<"\n";
                    }
                    delete tempData;
                }
                id_arr.clear();
            }
#line 1678 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 208 "test2.y" /* yacc.c:1646  */
    {
                for(int i=0;i<id_arr.size();i++){
                    DataItem* tempData = new DataItem();
                    tempData->IdName = id_arr[i];
                    tempData->type = (yyvsp[-1].type);
                    cout <<  "tempData -> type" << (yyvsp[-1].type) <<endl;
                    tempData->entries = "variables";
                    int a=stack.back().insert(id_arr[i],*tempData);
                    cout << "insert successed!!!! 2" <<endl;
                    if((yyvsp[-1].type)==INTEGER_type){
                        out << "\tfield static int "<<id_arr[i]<<"\n";
                    }else if((yyvsp[-1].type)==STRING_type){
                        out << "\tfield static java.lang.String "<<id_arr[i]<<"\n";
                    }else if((yyvsp[-1].type)==REAL_type){
                        out << "\tfield static double "<<id_arr[i]<<"\n";
                    }
                }
                id_arr.clear();
            }
#line 1702 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 230 "test2.y" /* yacc.c:1646  */
    {   
              string s=*(yyvsp[-2].s_val);
              id_arr.push_back(s);
          }
#line 1711 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 235 "test2.y" /* yacc.c:1646  */
    {
              string s=*(yyvsp[0].s_val);
              id_arr.push_back(s);
          }
#line 1720 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 247 "test2.y" /* yacc.c:1646  */
    {
                    args_num++;
                    DataItem* tempData=new DataItem();
                    tempData->IdName=*(yyvsp[-2].s_val);
                    tempData->type=(yyvsp[0].type);
                    tempData->entries="argument";
                    int a=stack.back().insert(*(yyvsp[-2].s_val),*tempData);
                    cout<<funcname<<"1"<<endl;
                    DataItem *func = stack[stack.size()-2].lookupAddress(funcname);
                    if(func==NULL) yyerror("function declation error");
                    DataItem func_argument;
                    func_argument.IdName = *(yyvsp[-2].s_val);
                    func_argument.type = (yyvsp[0].type);
                    func->arg_arr.push_back(func_argument);
                }
#line 1740 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 263 "test2.y" /* yacc.c:1646  */
    {
                    args_num++;
                    DataItem* tempData=new DataItem();
                    tempData->IdName=*(yyvsp[-2].s_val);
                    tempData->type=(yyvsp[0].type);
                    tempData->entries="argument";
                    int a=stack.back().insert(*(yyvsp[-2].s_val),*tempData);
                    cout<<funcname<<"2"<<endl;
                    DataItem *func = stack[stack.size()-2].lookupAddress(funcname);
                    if(func==NULL) yyerror("function declation error");
                    DataItem func_argument;
                    func_argument.IdName = *(yyvsp[-2].s_val);
                    func_argument.type = (yyvsp[0].type);
                    func->arg_arr.push_back(func_argument);
                }
#line 1760 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 281 "test2.y" /* yacc.c:1646  */
    { (yyval.type)=STRING_type; }
#line 1766 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 282 "test2.y" /* yacc.c:1646  */
    { (yyval.type)=INTEGER_type; }
#line 1772 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 283 "test2.y" /* yacc.c:1646  */
    {(yyval.type)=BOOLEAN_type;}
#line 1778 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 284 "test2.y" /* yacc.c:1646  */
    {(yyval.type)=REAL_type;}
#line 1784 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 287 "test2.y" /* yacc.c:1646  */
    {
                DataItem* tempData = new DataItem();
                tempData->type = STRING_type;
                tempData->sval = ((yyvsp[0].s_val))->c_str();
                (yyval.id_data) = tempData;
            }
#line 1795 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 293 "test2.y" /* yacc.c:1646  */
    {
                DataItem* tempData = new DataItem();
                tempData->type = INTEGER_type;
                tempData->val = (yyvsp[0]._val);
                (yyval.id_data) = tempData;
            }
#line 1806 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 299 "test2.y" /* yacc.c:1646  */
    {
                DataItem* tempData = new DataItem();
                tempData->type = BOOLEAN_type;
                tempData->bval = (yyvsp[0].b_val);
                (yyval.id_data) = tempData;
            }
#line 1817 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 305 "test2.y" /* yacc.c:1646  */
    {
                DataItem* tempData = new DataItem();
                tempData->type = REAL_type;
                tempData->dval = (yyvsp[0].d_val);
                (yyval.id_data) = tempData;
            }
#line 1828 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 314 "test2.y" /* yacc.c:1646  */
    {
                DataItem *tempData=lookupAllAddress(*(yyvsp[-3].s_val));
                if(tempData == NULL) yyerror("ERROR! undeclared");
                if((yyvsp[-1].id_data)->type==INTEGER_type){
                    tempData->val=(yyvsp[-1].id_data)->val;
                }else if((yyvsp[-1].id_data)->type==BOOLEAN_type){
                    tempData->bval=(yyvsp[-1].id_data)->bval;
                }else if((yyvsp[-1].id_data)->type==STRING_type){
                    tempData->sval=(yyvsp[-1].id_data)->sval;
                }else if((yyvsp[-1].id_data)->type==REAL_type){
                    tempData->dval=(yyvsp[-1].id_data)->dval;
                }
                
                stack.back().Dump();
                if(tempData->type==INTEGER_type||tempData->type==BOOLEAN_type){
                     cout << "statement eq expression integer 2" << endl;
                    if(!stack.back().lookup(*(yyvsp[-3].s_val)) || stack.size()==1){
                        out << "\t\tputstatic int " << outName << "." << *(yyvsp[-3].s_val) << "\n";
                    }else if(stack.back().lookup(*(yyvsp[-3].s_val)))
                    {
                        DataItem *tempData=stack.back().lookup(*(yyvsp[-3].s_val));
                        out << tempData->IdName <<"\n";
                        int a=stack.back().getIndex(*(yyvsp[-3].s_val));
                        out << "\t\tistore " << a <<"\n";
                        delete tempData;
                    }
                   
                }else if(tempData->type==STRING_type){
                    cout << "statement eq expression3" << endl;
                    if(!stack.back().lookup(*(yyvsp[-3].s_val)) || stack.size()==1){
                        out << "\t\tputstatic java.lang.String " << *(yyvsp[-3].s_val) << "\n";
                    }else if(stack.back().lookup(*(yyvsp[-3].s_val)))
                    {
                        DataItem *tempData=stack.back().lookup(*(yyvsp[-3].s_val));
                        out << tempData->IdName <<"\n";
                        int a=stack.back().getIndex(*(yyvsp[-3].s_val));
                        out << "\t\tistore " << a <<"\n";
                        delete tempData;
                    }
                    
                }else if(tempData->type==REAL_type){
                    if(!stack.back().lookup(*(yyvsp[-3].s_val)) || stack.size()==1){
                        out << "\t\tputstatic double " << *(yyvsp[-3].s_val) << "\n";
                    }else if(stack.back().lookup(*(yyvsp[-3].s_val)))
                    {
                        DataItem *tempData=stack.back().lookup(*(yyvsp[-3].s_val));
                        out << tempData->IdName <<"\n";
                        int a=stack.back().getIndex(*(yyvsp[-3].s_val));
                        out << "\t\tistore " << a <<"\n";
                        delete tempData;
                    }
                    cout << "statement eq expression4" << endl;
                }
                cout << "statement eq expression endl" << endl;
            }
#line 1888 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 369 "test2.y" /* yacc.c:1646  */
    {
                    out << "\t\tgetstatic java.io.PrintStream java.lang.System.out\n";
                }
#line 1896 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 373 "test2.y" /* yacc.c:1646  */
    {
                    if((yyvsp[-1].id_data)->type==INTEGER_type){
                        out << "\t\tinvokevirtual void java.io.PrintStream.print(int)\n";
                    }else if((yyvsp[-1].id_data)->type==STRING_type){
                        out << "\t\tinvokevirtual void java.io.PrintStream.print(java.lang.String)\n";
                    }else if((yyvsp[-1].id_data)->type==REAL_type){
                        out << "\t\tinvokevirtual void java.io.PrintStream.print(double)\n";
                    }
                }
#line 1910 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 382 "test2.y" /* yacc.c:1646  */
    {   out << "\t\tgetstatic java.io.PrintStream java.lang.System.out\n";  }
#line 1916 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 384 "test2.y" /* yacc.c:1646  */
    {
                    if((yyvsp[-1].id_data)->type==INTEGER_type){
                        out << "\t\tinvokevirtual void java.io.PrintStream.println(int)\n";
                    }else if((yyvsp[-1].id_data)->type==STRING_type){
                        out << "\t\tinvokevirtual void java.io.PrintStream.println(java.lang.String)\n";
                    }else if((yyvsp[-1].id_data)->type==REAL_type){
                        out << "\t\tinvokevirtual void java.io.PrintStream.println(double)\n";
                    }
                }
#line 1930 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 394 "test2.y" /* yacc.c:1646  */
    {
                out << "\treturn\n";
            }
#line 1938 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 398 "test2.y" /* yacc.c:1646  */
    {
                out << "\t\tireturn\n";
            }
#line 1946 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 407 "test2.y" /* yacc.c:1646  */
    {  
                DataItem *tempData=lookupAll(*(yyvsp[0].s_val));
                if(tempData == NULL) yyerror("ERROR! undeclared");
                (yyval.id_data)=tempData;

                if(stack.size()!= 1 && tempData->entries=="const")
                {
                    if(tempData->type == STRING_type){
                        out << "\t\tldc \"" << tempData->sval << "\"\n";
                    }else if(tempData->type == INTEGER_type||tempData->type==BOOLEAN_type){
                        out << "\t\tsipush " << tempData->val << "\n";
                    }else if(tempData->type == REAL_type){
                        out << "\t\tIdc2_w " << tempData->dval << "\n";
                    }
                }else if(tempData->type==INTEGER_type || tempData->type==BOOLEAN_type)
                {
                    if(!stack.back().lookup(*(yyvsp[0].s_val))|| stack.size()==1){
                        out << "\t\tgetstatic int " << outName << "." << *(yyvsp[0].s_val) << "\n";
                    }else if(stack.back().lookup(*(yyvsp[0].s_val)))
                    {
                        DataItem *tempData=stack.back().lookup(*(yyvsp[0].s_val));
                        int a=stack.back().getIndex(*(yyvsp[0].s_val));
                        out << "\t\tiload " << a << "\n";
                        delete tempData;
                    }
                }else if(tempData->type==STRING_type)
                {
                    if(!stack.back().lookup(*(yyvsp[0].s_val))|| stack.size()==1){
                        out << "\t\tgetstatic java.lang.String " << *(yyvsp[0].s_val) << "\n";
                    }else if(stack.back().lookup(*(yyvsp[0].s_val)))
                    {
                        DataItem *tempData=stack.back().lookup(*(yyvsp[0].s_val));
                        int a=stack.back().getIndex(*(yyvsp[0].s_val));
                        out << "\t\tiload " << a << "\n";
                        delete tempData;
                    }
                }else if(tempData->type==REAL_type)
                {
                    if(!stack.back().lookup(*(yyvsp[0].s_val))|| stack.size()==1){
                        out << "\t\tgetstatic double " << *(yyvsp[0].s_val) << "\n";
                    }else if(stack.back().lookup(*(yyvsp[0].s_val)))
                    {
                        DataItem *tempData=stack.back().lookup(*(yyvsp[0].s_val));
                        int a=stack.back().getIndex(*(yyvsp[0].s_val));
                        out << "\t\tiload " << a << "\n";
                        delete tempData;
                    }
                }
                delete tempData;
            }
#line 2001 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 458 "test2.y" /* yacc.c:1646  */
    {
                if(stack.size()!=1){
                    if((yyvsp[0].id_data)->type==INTEGER_type)
                        out<<"\t\tsipush "<<(yyvsp[0].id_data)->val<<"\n";
                    else if((yyvsp[0].id_data)->type==STRING_type)
                        out<<"\t\tldc "<<(yyvsp[0].id_data)->sval<<"\n";
                    else if((yyvsp[0].id_data)->type==REAL_type)
                        out<<"\t\tldc2_w "<<(yyvsp[0].id_data)->dval<<"\n";
                }
                (yyval.id_data) = (yyvsp[0].id_data);
            }
#line 2017 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 471 "test2.y" /* yacc.c:1646  */
    {
                if((yyvsp[-2].id_data)->type != (yyvsp[0].id_data)->type) yyerror("left != right");
                DataItem *tempData = new DataItem();
                if((yyvsp[-2].id_data)->type==INTEGER_type)
                {
                    tempData->type=(yyvsp[-2].id_data)->type;
                    tempData->val=(yyvsp[-2].id_data)->val * (yyvsp[0].id_data)->val;
                }else if((yyvsp[-2].id_data)->type==REAL_type){
                    tempData->type=(yyvsp[-2].id_data)->type;
                    tempData->dval=(yyvsp[-2].id_data)->dval * (yyvsp[0].id_data)->dval;
                }else{
                    yyerror("can't use the '*' operation");
                }
                (yyval.id_data) = tempData;
                if((yyvsp[-2].id_data)->type == INTEGER_type)
                    out<<"\t\timul\n";
                else if((yyvsp[-2].id_data)->type == REAL_type)
                    out<<"\t\tdmul\n";

                delete tempData;
            }
#line 2043 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 493 "test2.y" /* yacc.c:1646  */
    {
                DataItem *tempData = new DataItem();
                tempData->type = BOOLEAN_type;
                tempData->bval = ((yyvsp[-2].id_data)->bval && (yyvsp[0].id_data)->bval);
                (yyval.id_data) = tempData;
                if((yyvsp[-2].id_data)->type == INTEGER_type)
                    out<<"\t\tiand\n";
                delete tempData;
            }
#line 2057 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 503 "test2.y" /* yacc.c:1646  */
    {
                DataItem *tempData = new DataItem();
                tempData->type = BOOLEAN_type;
                tempData->bval = ((yyvsp[-2].id_data)->bval || (yyvsp[0].id_data)->bval);
                (yyval.id_data) = tempData;
                if((yyvsp[-2].id_data)->type == INTEGER_type)
                    out<<"\t\tior\n";
                delete tempData;
            }
#line 2071 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 513 "test2.y" /* yacc.c:1646  */
    {
                if((yyvsp[-2].id_data)->type != (yyvsp[0].id_data)->type) yyerror("left != right");
                DataItem *tempData = new DataItem();
                if((yyvsp[0].id_data)->val==0)
                    (yyvsp[0].id_data)->val=1;
                if((yyvsp[-2].id_data)->type==INTEGER_type)
                {
                    tempData->type=(yyvsp[-2].id_data)->type;
                    double temp=(yyvsp[-2].id_data)->val/(yyvsp[0].id_data)->val;
                    tempData->val=(int)temp;
                    cout<<tempData->val<<endl;
                }else if((yyvsp[-2].id_data)->type==REAL_type)
                {
                    tempData->type=(yyvsp[-2].id_data)->type;
                    double temp=(yyvsp[-2].id_data)->dval/(yyvsp[0].id_data)->dval;
                    tempData->dval=temp;
                    cout<<tempData->dval<<endl;
                }else{
                    yyerror("can't use the '/' operation");
                }
                (yyval.id_data) = tempData;
                if((yyvsp[-2].id_data)->type == INTEGER_type)
                    out<<"\t\tidiv\n";
                else if((yyvsp[-2].id_data)->type == REAL_type)
                    out<<"\t\tddiv\n";

                delete tempData;
            }
#line 2104 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 542 "test2.y" /* yacc.c:1646  */
    {
                if((yyvsp[-2].id_data)->type != (yyvsp[0].id_data)->type) yyerror("left != right");
                DataItem *tempData = new DataItem();
                if((yyvsp[0].id_data)->val==0)
                    (yyvsp[0].id_data)->val=1;
                if((yyvsp[-2].id_data)->type==INTEGER_type)
                {
                    tempData->type=(yyvsp[-2].id_data)->type;
                    tempData->val=(yyvsp[-2].id_data)->val % (yyvsp[0].id_data)->val;
                }else{
                    yyerror("can't use the '%' operation");
                }
                (yyval.id_data) = tempData;
                if((yyvsp[-2].id_data)->type == INTEGER_type)
                    out<<"\t\tirem\n";
                delete tempData;
            }
#line 2126 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 560 "test2.y" /* yacc.c:1646  */
    {
                if((yyvsp[-2].id_data)->type != (yyvsp[0].id_data)->type) yyerror("left != right");
                DataItem *tempData = new DataItem();
                if((yyvsp[-2].id_data)->type==INTEGER_type)
                {
                    tempData->type=(yyvsp[-2].id_data)->type;
                    tempData->val=(yyvsp[-2].id_data)->val + (yyvsp[0].id_data)->val;
                }else if((yyvsp[-2].id_data)->type==REAL_type)
                {
                    tempData->type=(yyvsp[-2].id_data)->type;
                    tempData->dval=(yyvsp[-2].id_data)->dval + (yyvsp[0].id_data)->dval;
                }else{
                    yyerror("can't use the '*' operation");
                }
                // cout << "'+' successed!"<<endl;
                (yyval.id_data) = tempData;
                if((yyvsp[-2].id_data)->type == INTEGER_type)
                    out<<"\t\tiadd\n";
                else if((yyvsp[-2].id_data)->type == REAL_type)
                    out<<"\t\tdadd\n";
                delete tempData;
            }
#line 2153 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 583 "test2.y" /* yacc.c:1646  */
    {
                if((yyvsp[-2].id_data)->type != (yyvsp[0].id_data)->type) yyerror("left != right");
                DataItem *tempData = new DataItem();
                if((yyvsp[-2].id_data)->type==INTEGER_type)
                {
                    tempData->type=(yyvsp[-2].id_data)->type;
                    tempData->val=(yyvsp[-2].id_data)->val - (yyvsp[0].id_data)->val;
                }else if((yyvsp[-2].id_data)->type==REAL_type)
                {
                    tempData->type=(yyvsp[-2].id_data)->type;
                    tempData->dval=(yyvsp[-2].id_data)->dval - (yyvsp[0].id_data)->dval;
                }else{
                    yyerror("can't use the '-' operation");
                }
                (yyval.id_data) = tempData;
                if((yyvsp[-2].id_data)->type == INTEGER_type)
                    out<<"\t\tisub\n";
                if((yyvsp[-2].id_data)->type == REAL_type)
                    out<<"\t\tdsub\n";
                delete tempData;
            }
#line 2179 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 605 "test2.y" /* yacc.c:1646  */
    {
                DataItem *tempData = new DataItem();
                tempData->type = BOOLEAN_type;
                tempData->bval = ((yyvsp[-2].id_data)->val <(yyvsp[0].id_data)->val);
                (yyval.id_data) = tempData;

                out << "\t\tisub\n";
                out << "\t\tiflt L"<< ++LabalCount << "\n" << "\t\ticonst_0\n" << "\t\tgoto L"<< ++LabalCount << "\n";
                out << "\tL"<< ++NowCount << ":\n" << "\t\ticonst_1\n" << "\tL"<< ++NowCount << ":\n";
                delete tempData;
            }
#line 2195 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 617 "test2.y" /* yacc.c:1646  */
    {
                DataItem *tempData = new DataItem();
                tempData->type = BOOLEAN_type;
                tempData->bval = ((yyvsp[-2].id_data)->val > (yyvsp[0].id_data)->val);
                (yyval.id_data) = tempData;
                out << "\t\tisub\n";
                out << "\t\tifgt L" << ++LabalCount << "\n"<< "\t\ticonst_0\n" << "\t\tgoto L"<< ++LabalCount << "\n";
                out << "\tL"<< ++NowCount  << ":\n" << "\t\ticonst_1\n" << "\tL" << ++NowCount << ":\n";
                delete tempData;
            }
#line 2210 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 628 "test2.y" /* yacc.c:1646  */
    {
                DataItem *tempData = new DataItem();
                tempData->type = BOOLEAN_type;
                tempData->bval = ((yyvsp[-2].id_data)->val == (yyvsp[0].id_data)->val);
                (yyval.id_data) = tempData;
                out << "\t\tisub\n";
                out << "\t\tifeq L"<<++LabalCount  << "\n" << "\t\ticonst_0\n" << "\t\tgoto L"<<++LabalCount  << "\n";
                out << "\tL"<<++NowCount  << ":\n" << "\t\ticonst_1\n" << "\tL"<<++NowCount  << ":\n";
                delete tempData;
            }
#line 2225 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 639 "test2.y" /* yacc.c:1646  */
    {
                DataItem *tempData = new DataItem();
                tempData->type = BOOLEAN_type;
                tempData->bval = ((yyvsp[-2].id_data)->val <= (yyvsp[0].id_data)->val);
                (yyval.id_data) = tempData;
                out << "\t\tisub\n";
                out << "\t\tifle L"<<++LabalCount  << "\n" << "\t\ticonst_0\n" << "\t\tgoto L"<<++LabalCount  << "\n";
                out << "\tL"<<++NowCount  << ":\n" << "\t\ticonst_1\n" << "\tL"<<++NowCount  << ":\n";
                delete tempData;
            }
#line 2240 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 650 "test2.y" /* yacc.c:1646  */
    {
                DataItem *tempData = new DataItem();
                tempData->type = BOOLEAN_type;
                tempData->bval = ((yyvsp[-2].id_data)->val >= (yyvsp[0].id_data)->val);
                (yyval.id_data) = tempData;
                out << "\t\tisub\n";
                out << "\t\tifge L"<<++LabalCount <<  "\n" << "\t\ticonst_0\n" << "\t\tgoto L"<<++LabalCount <<  "\n";
                out << "\tL"<<++NowCount <<  ":\n" << "\t\ticonst_1\n" << "\tL"<<++NowCount <<  ":\n";
                delete tempData;
            }
#line 2255 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 661 "test2.y" /* yacc.c:1646  */
    {
                DataItem *tempData = new DataItem();
                tempData->type = BOOLEAN_type;
                tempData->bval = ((yyvsp[-2].id_data)->bval != (yyvsp[0].id_data)->bval);
                (yyval.id_data) = tempData;
                out << "\t\tisub\n";
                out << "\t\tifne L"<<++LabalCount <<  "\n" << "\t\ticonst_0\n" << "\t\tgoto L"<<++LabalCount <<  "\n";
                out << "\tL"<<++NowCount <<  ":\n" << "\t\ticonst_1\n" << "\tL"<<++NowCount <<  ":\n";
                delete tempData;
            }
#line 2270 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 672 "test2.y" /* yacc.c:1646  */
    {
                DataItem *tempData = new DataItem();
                tempData->type = INTEGER_type;
                tempData->val = ~((yyvsp[0].id_data)->val);
                (yyval.id_data) = tempData;
                if((yyvsp[0].id_data)->type == INTEGER_type)
                    out<<"ixor\n";
                delete tempData;
            }
#line 2284 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 682 "test2.y" /* yacc.c:1646  */
    {
                (yyval.id_data)=(yyvsp[-1].id_data);
            }
#line 2292 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 685 "test2.y" /* yacc.c:1646  */
    {
                DataItem *tempData = new DataItem();
                tempData->type=INTEGER_type;
                tempData->val = -((yyvsp[0].id_data)->val);
                (yyval.id_data)=tempData;
                out<<"\t\tineg\n";
                delete tempData;
            }
#line 2305 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 697 "test2.y" /* yacc.c:1646  */
    {
                            out << "\tL"<< ++NowCount << ":\n";
                            stack.back().Dump();
                            stack.pop_back();
                        }
#line 2315 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 705 "test2.y" /* yacc.c:1646  */
    {
                            stack.back().Dump();
                            stack.pop_back();
                        }
#line 2324 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 710 "test2.y" /* yacc.c:1646  */
    {
                            out << "\t\tgoto L"<< ++LabalCount << "\n";
	                        out << "\tL"<< ++NowCount << ":\n";
                            SymbolTable tempData = stack.back();
                            stack.push_back(tempData);
                        }
#line 2335 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 718 "test2.y" /* yacc.c:1646  */
    {
                            out << "\tL"<< ++NowCount << ":\n";
                            stack.back().Dump();
                            stack.pop_back();
                        }
#line 2345 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 725 "test2.y" /* yacc.c:1646  */
    {
                            out << "\t\tifeq L"<< ++LabalCount << "\n";
                            SymbolTable tempData = stack.back();
                            stack.push_back(tempData);
                        }
#line 2355 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 733 "test2.y" /* yacc.c:1646  */
    { 
                    if(NowCount==0)
                        out << "\n\tL"<< NowCount << ":\n";
                    whilebegin=NowCount;
                }
#line 2365 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 739 "test2.y" /* yacc.c:1646  */
    {
                    out << "\t\tifeq L"<< ++LabalCount << "\n";  // ifeq Lexit
                    SymbolTable tempData = stack.back();
                    stack.push_back(tempData);
                }
#line 2375 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 745 "test2.y" /* yacc.c:1646  */
    {
                    stack.back().Dump();
                    stack.pop_back();
                    out << "\t\tgoto L"<<whilebegin << "\n";		// goto Lbegin
                    out << "\n\tL"<<++NowCount << ":\n";	// Lexit:
                }
#line 2386 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 758 "test2.y" /* yacc.c:1646  */
    {
                        DataItem* tempData=lookupAll(*(yyvsp[-3].s_val));
                        (yyval.id_data)=tempData;
                        Trace("IDENTIFIER '(' optional_comma_separated_expression ')'");
                        out << "\t\tinvokestatic ";
                        out << "int ";
                        //out << "void ";后期需要补充
                        out << outName + "." + *(yyvsp[-3].s_val) + "(";
                        for (int i = 0; i < tempData->arg_arr.size(); i++) {
                            if(i!=0) out << ",";
                            out << "int";
                        }
                        out << ")\n";
                        Trace("work5");
                        args_num=0;
                    }
#line 2407 "y.tab.cpp" /* yacc.c:1646  */
    break;


#line 2411 "y.tab.cpp" /* yacc.c:1646  */
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
#line 780 "test2.y" /* yacc.c:1906  */


void yyerror(string error_str){
    cout << error_str;
}
int yywrap(){
    return 1;
}

DataItem* lookupAll(string s) {
    for(int i=stack.size()-1;i>=0;i--){
		if(stack[i].lookup(s)){
			return stack[i].lookup(s);
		}
	}
}

DataItem* lookupAllAddress(string s) {
    for(int i=stack.size()-1;i>=0;i--){
		if(stack[i].lookupAddress(s)){
			return stack[i].lookupAddress(s);
		}
	}
}

int main(int argc, char *argv[]){
    SymbolTable global;
    stack.push_back(global);
	
	// open input file and check exist
    yyin = fopen(argv[1], "r");
	if(!yyin){
		cerr << "[Error] File not found!" << endl;
		exit(1);	
	}

	string source = string(argv[1]);
	size_t found = source.rfind("/");
	size_t foundDot = source.rfind(".ru");
	outName = source.substr(found+1, foundDot - found - 1);
	out.open(outName + ".jasm");
    if (yyparse() == 1)
    {
        yyerror("[Error] Parsing error!");
    }
	return 0;	
}
