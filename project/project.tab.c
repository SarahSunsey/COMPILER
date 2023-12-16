
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "project.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int nb_ligne=1;
  int yylex();
  int yywrap();
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_PINK    "\x1b[38;2;255;182;193m"    
#define ANSI_COLOR_RESET   "\x1b[0m"
extern void yyerror(const char* msg);
char * turnEXP(char * str);
char* endptr;
double result;
int errS=0;
char tempStr[20];
char postfixExpression[100];
typedef struct {
    int top;
    double* array;
} Stack;

void printStack(Stack* stack);
Stack* initializeStack(int size);
int isEmpty(Stack* stack);
void push(Stack* stack, double item);
double pop(Stack* stack);
typedef struct {
    int top;
    char* array;
} CharStack;

void printCharStack(CharStack* stack);
CharStack* initializeCharStack(int size);
int isEmptyChar(CharStack* stack) ;
void pushChar(CharStack* stack, char item);
char popChar(CharStack* stack);
int getPrecedence(char operatorr);
void infixToPostfix(char* infix, char* postfix);
double evaluateExpression(char* expression);
extern void insert(char* str,char* strg);
extern char* yytext;
    void add(char);
    void insert_type();
    void handleAffectation() ; 
    void handleDecCst(char * cst);
    int search(char *);
    void addval(int x,char * str);
    struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        int line_no;
        double ValNUm ;
        char * str ;
        char * boolVal ; 
        
    } symbol_table[100];
    int declarationPhase=1 ;
    char exp[30];
    int count=0;
    int q;
    int y;
    char ValNumerique[10];
    char type[10];
    char decCST[10];
    int Affvar=-1;
   


/* Line 189 of yacc.c  */
#line 144 "project.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BEGINN = 258,
     aff = 259,
     pvg = 260,
     idf = 261,
     cst = 262,
     virgule = 263,
     FLOAT_NUM = 264,
     INT = 265,
     BOOLL = 266,
     STRING = 267,
     BOOL_VAL = 268,
     CHARR = 269,
     VOID = 270,
     STR = 271,
     PRINTFF = 272,
     INT_NUM = 273,
     FLOATVAR = 274,
     real = 275,
     charr = 276,
     string = 277,
     BOOL_VAR = 278,
     commentaire = 279,
     seulcommentaire = 280,
     lt = 281,
     gt = 282,
     eq = 283,
     eqeq = 284,
     neq = 285,
     pl = 286,
     min = 287,
     and = 288,
     mul = 289,
     orr = 290,
     incr = 291,
     lteq = 292,
     gteq = 293,
     not = 294,
     decr = 295,
     divv = 296,
     po = 297,
     pf = 298,
     ao = 299,
     af = 300,
     ENDD = 301,
     FOR = 302,
     IF = 303,
     ELSE = 304,
     WHILE = 305,
     DO = 306,
     FUNCTIONN = 307,
     NAMEFUNCTION = 308,
     RETURN = 309
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 70 "project.y"

int int_val;
double double_val;
char* string;



/* Line 214 of yacc.c  */
#line 242 "project.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 254 "project.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   252

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNRULES -- Number of states.  */
#define YYNSTATES  192

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      55,    56,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    58,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,    10,    11,    14,    17,    19,    23,
      24,    28,    29,    33,    34,    38,    39,    43,    44,    48,
      50,    53,    55,    59,    62,    66,    69,    73,    76,    80,
      83,    89,    92,    97,    99,   101,   103,   105,   107,   109,
     113,   116,   117,   123,   124,   125,   132,   133,   140,   141,
     151,   152,   161,   162,   163,   174,   178,   180,   184,   185,
     198,   201,   202,   207,   208,   213,   216,   219,   223,   225,
     226,   232,   233,   237,   243,   245,   247,   251,   253,   255,
     257,   259,   261,   263,   265,   267,   269,   271,   273,   275,
     277,   279,   281,   283,   285,   287,   289,   291,   293,   295,
     297,   299,   301,   303,   305,   307,   309,   311,   313
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      60,     0,    -1,    -1,    62,     3,    61,    80,    46,    -1,
      -1,     3,    46,    -1,    63,    62,    -1,    63,    -1,     7,
      99,    74,    -1,    -1,    14,    64,    70,    -1,    -1,    12,
      65,    71,    -1,    -1,    10,    66,    72,    -1,    -1,    19,
      67,    73,    -1,    -1,    11,    68,    78,    -1,    69,    -1,
      24,    69,    -1,    24,    -1,    75,     8,    70,    -1,    75,
       5,    -1,    75,     8,    71,    -1,    75,     5,    -1,    75,
       8,    72,    -1,    75,     5,    -1,    75,     8,    73,    -1,
      75,     5,    -1,    76,    28,    77,     8,    74,    -1,    76,
       5,    -1,    76,    28,    77,     5,    -1,     6,    -1,     6,
      -1,    18,    -1,     9,    -1,     6,    -1,    13,    -1,    75,
       8,    78,    -1,    75,     5,    -1,    -1,    75,    28,    13,
      79,     5,    -1,    -1,    -1,    75,    81,     4,    96,    82,
       5,    -1,    -1,    17,    83,    55,    16,    56,     5,    -1,
      -1,    48,    84,    55,    92,    56,    57,    80,    58,    93,
      -1,    -1,    50,    85,    55,    92,    56,    57,    80,    58,
      -1,    -1,    -1,    51,    86,    57,    80,    58,    50,    87,
      55,    92,    56,    -1,    75,   101,     5,    -1,    24,    -1,
     101,    75,     5,    -1,    -1,    47,    88,    55,    89,     5,
      92,     5,    89,    56,    57,    80,    58,    -1,    80,    80,
      -1,    -1,    75,    90,     4,   103,    -1,    -1,    75,    91,
       4,    98,    -1,    75,   101,    -1,   101,    75,    -1,    75,
     100,    98,    -1,    13,    -1,    -1,    49,    94,    57,    80,
      58,    -1,    -1,    96,   104,    95,    -1,    55,    96,    56,
     104,    95,    -1,   105,    -1,    95,    -1,    98,   102,    97,
      -1,   105,    -1,    97,    -1,    11,    -1,    10,    -1,    19,
      -1,    14,    -1,    26,    -1,    27,    -1,    28,    -1,    29,
      -1,    30,    -1,    36,    -1,    40,    -1,    32,    -1,    31,
      -1,    33,    -1,    34,    -1,    35,    -1,    41,    -1,    18,
      -1,     9,    -1,     6,    -1,    13,    -1,    32,    -1,    31,
      -1,    33,    -1,    41,    -1,    34,    -1,    18,    -1,     9,
      -1,    75,    -1,    13,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    89,    89,    89,    90,    91,    94,    95,    99,   100,
     100,   101,   101,   102,   102,   103,   103,   104,   104,   105,
     108,   109,   111,   112,   114,   115,   117,   118,   121,   122,
     126,   127,   128,   133,   136,   138,   140,   143,   144,   147,
     148,   149,   149,   157,   159,   157,   161,   161,   162,   162,
     163,   163,   164,   164,   164,   165,   166,   167,   168,   168,
     169,   174,   174,   176,   176,   178,   179,   185,   186,   191,
     191,   192,   194,   195,   196,   198,   201,   202,   204,   208,
     209,   210,   211,   215,   215,   215,   215,   215,   216,   216,
     218,   218,   218,   218,   218,   218,   219,   219,   219,   219,
     221,   221,   221,   221,   221,   222,   223,   223,   223
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BEGINN", "aff", "pvg", "idf", "cst",
  "virgule", "FLOAT_NUM", "INT", "BOOLL", "STRING", "BOOL_VAL", "CHARR",
  "VOID", "STR", "PRINTFF", "INT_NUM", "FLOATVAR", "real", "charr",
  "string", "BOOL_VAR", "commentaire", "seulcommentaire", "lt", "gt", "eq",
  "eqeq", "neq", "pl", "min", "and", "mul", "orr", "incr", "lteq", "gteq",
  "not", "decr", "divv", "po", "pf", "ao", "af", "ENDD", "FOR", "IF",
  "ELSE", "WHILE", "DO", "FUNCTIONN", "NAMEFUNCTION", "RETURN", "'('",
  "')'", "'{'", "'}'", "$accept", "S", "$@1", "declarations",
  "declaration", "$@2", "$@3", "$@4", "$@5", "$@6", "cmnt",
  "declarationCHAR", "declarationSTRING", "declarationENTIER",
  "declarationFLOAT", "declarationCNST", "IDF", "IDF2", "VALUEcst",
  "declarationBOOL", "$@7", "programme", "$@8", "$@9", "$@10", "$@11",
  "$@12", "$@13", "$@14", "$@15", "statement", "$@16", "$@17", "condition",
  "else", "$@18", "term", "expression", "term2", "expression1", "datatype",
  "COMP", "unary", "OP", "VALUE", "OP1", "VALUE1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    40,    41,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    61,    60,    60,    60,    62,    62,    63,    64,
      63,    65,    63,    66,    63,    67,    63,    68,    63,    63,
      69,    69,    70,    70,    71,    71,    72,    72,    73,    73,
      74,    74,    74,    75,    76,    77,    77,    77,    77,    78,
      78,    79,    78,    81,    82,    80,    83,    80,    84,    80,
      85,    80,    86,    87,    80,    80,    80,    80,    88,    80,
      80,    90,    89,    91,    89,    89,    89,    92,    92,    94,
      93,    93,    95,    95,    95,    96,    97,    97,    98,    99,
      99,    99,    99,   100,   100,   100,   100,   100,   101,   101,
     102,   102,   102,   102,   102,   102,   103,   103,   103,   103,
     104,   104,   104,   104,   104,   105,   105,   105,   105
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     5,     0,     2,     2,     1,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     3,     1,
       2,     1,     3,     2,     3,     2,     3,     2,     3,     2,
       5,     2,     4,     1,     1,     1,     1,     1,     1,     3,
       2,     0,     5,     0,     0,     6,     0,     6,     0,     9,
       0,     8,     0,     0,    10,     3,     1,     3,     0,    12,
       2,     0,     4,     0,     4,     2,     2,     3,     1,     0,
       5,     0,     3,     5,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,    13,    17,    11,     9,    15,    21,     0,
       0,     7,    19,     5,    80,    79,    82,    81,     0,     0,
       0,     0,     0,     0,    20,     1,     2,     6,    34,     8,
       0,    33,    14,     0,     0,    18,    12,     0,    10,     0,
      16,     0,     0,    31,     0,    27,     0,    40,     0,     0,
      25,     0,    23,     0,    29,     0,    46,    56,    88,    89,
      58,    48,    50,    52,    43,     0,     0,    37,    36,    38,
      35,     0,    26,    39,    41,    24,    22,    28,     0,     0,
       0,     0,     0,     0,     0,     3,    60,     0,    32,     0,
       0,     0,     0,     0,     0,     0,     0,    55,    57,    30,
      42,     0,    61,     0,     0,    68,     0,     0,     0,     0,
     106,   108,   105,     0,   107,    75,    44,    74,     0,     0,
       0,    65,     0,    66,    83,    84,    85,    86,    87,     0,
       0,     0,     0,     0,   101,   100,   102,   104,   103,     0,
       0,    47,     0,     0,     0,    78,    67,    77,     0,     0,
      53,     0,    45,    72,     0,    98,    97,    99,    96,    62,
      64,     0,    91,    90,    92,    93,    94,    95,     0,     0,
       0,     0,     0,     0,    76,     0,    71,    51,     0,    73,
       0,    69,    49,     0,     0,     0,    54,     0,     0,    59,
       0,    70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    42,    10,    11,    22,    21,    19,    23,    20,
      12,    38,    36,    32,    40,    29,    64,    30,    71,    35,
      90,    86,    83,   139,    78,    80,    81,    82,   171,    79,
     103,   119,   120,   107,   182,   185,   115,   154,   145,   146,
      18,   129,    66,   168,   159,   140,   117
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -138
static const yytype_int16 yypact[] =
{
     200,   -21,   129,  -138,  -138,  -138,  -138,  -138,     9,    39,
      53,   206,  -138,  -138,  -138,  -138,  -138,  -138,    61,    75,
      75,    75,    75,    75,  -138,  -138,  -138,  -138,  -138,  -138,
      23,  -138,  -138,     7,    13,  -138,  -138,    57,  -138,    58,
    -138,    74,   158,  -138,   220,  -138,    75,  -138,    75,    70,
    -138,    75,  -138,    75,  -138,    75,  -138,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,   -16,   138,    75,  -138,  -138,  -138,
    -138,    91,  -138,  -138,  -138,  -138,  -138,  -138,    31,    42,
      46,    50,    35,   102,   103,  -138,   158,   104,  -138,    61,
     108,    99,     8,    48,    48,   158,     4,  -138,  -138,  -138,
    -138,    60,   -16,   112,    75,  -138,   221,    64,    66,     2,
    -138,  -138,  -138,     4,  -138,  -138,   211,  -138,   127,   131,
     133,  -138,    48,  -138,  -138,  -138,  -138,  -138,  -138,   222,
      89,    93,   106,   159,  -138,  -138,  -138,  -138,  -138,   147,
       4,  -138,   228,   222,   149,  -138,    37,  -138,   158,   158,
    -138,   211,  -138,  -138,   211,  -138,  -138,  -138,  -138,  -138,
      37,     8,  -138,  -138,  -138,  -138,  -138,  -138,   222,    40,
      78,   105,     4,   107,  -138,    37,   109,  -138,    48,  -138,
     110,  -138,  -138,   114,   158,   116,  -138,    83,   158,  -138,
     121,  -138
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -138,  -138,  -138,   154,  -138,  -138,  -138,  -138,  -138,  -138,
     168,   113,   126,   134,   128,    92,   -19,  -138,  -138,   139,
    -138,   -37,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,
      34,  -138,  -138,   -85,  -138,  -138,  -129,   -73,    28,  -137,
    -138,  -138,   -57,  -138,  -138,    51,  -113
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      33,    34,    37,    39,    41,    65,   160,    84,    31,   108,
      31,   153,    45,   110,    31,    46,   147,   111,    47,    56,
      58,    48,   112,   116,    59,    13,    57,    33,    43,    34,
     147,   175,    37,     8,    39,   104,    41,   144,    58,    25,
     133,    49,    59,   179,    58,   121,    31,    87,    59,    60,
      61,    44,    62,    63,    31,   147,    26,    56,   109,   113,
     132,   105,    50,    52,    57,    51,    53,    28,   162,   163,
     164,   165,   166,   102,   106,   106,    58,   114,   167,    54,
      59,    31,    55,    74,    31,   123,    91,    60,    61,    31,
      62,    63,    95,   183,   114,    56,    88,    92,   176,    89,
      56,    93,    57,   106,   104,    94,    96,    57,    97,    98,
     114,   169,   170,   100,    58,   101,   118,   122,    59,    58,
     130,   114,   131,    59,   114,    60,    61,    31,    62,    63,
      60,    61,   141,    62,    63,   142,   177,   143,    56,    14,
      15,   189,   102,    16,    31,    57,   148,   187,    17,   114,
     149,   190,   152,   114,   161,    56,   150,    58,   181,   106,
     178,    59,    57,   180,    31,    27,    76,   184,    60,    61,
     186,    62,    63,   188,    58,    56,    24,    75,    59,   191,
      72,    99,    57,    77,    85,    60,    61,    73,    62,    63,
     134,   135,   136,   137,    58,   173,   174,     0,    59,     0,
     138,     0,   172,     1,     0,    60,    61,     2,    62,    63,
       3,     4,     5,     2,     6,   151,     3,     4,     5,     7,
       6,     0,     0,     0,     8,     7,    67,     0,    31,    68,
       8,   110,     0,    69,   155,   111,     0,   156,    70,     0,
     112,   157,   134,   135,   136,   137,   158,   124,   125,   126,
     127,   128,   138
};

static const yytype_int16 yycheck[] =
{
      19,    20,    21,    22,    23,    42,   143,    64,     6,    94,
       6,   140,     5,     9,     6,     8,   129,    13,     5,    17,
      36,     8,    18,    96,    40,    46,    24,    46,     5,    48,
     143,   168,    51,    24,    53,    92,    55,   122,    36,     0,
     113,    28,    40,   172,    36,   102,     6,    66,    40,    47,
      48,    28,    50,    51,     6,   168,     3,    17,    95,    55,
      58,    13,     5,     5,    24,     8,     8,     6,    31,    32,
      33,    34,    35,    92,    93,    94,    36,    96,    41,     5,
      40,     6,     8,    13,     6,   104,    55,    47,    48,     6,
      50,    51,    57,   178,   113,    17,     5,    55,    58,     8,
      17,    55,    24,   122,   161,    55,     4,    24,     5,     5,
     129,   148,   149,     5,    36,    16,    56,     5,    40,    36,
      56,   140,    56,    40,   143,    47,    48,     6,    50,    51,
      47,    48,     5,    50,    51,     4,    58,     4,    17,    10,
      11,    58,   161,    14,     6,    24,    57,   184,    19,   168,
      57,   188,     5,   172,     5,    17,    50,    36,    49,   178,
      55,    40,    24,    56,     6,    11,    53,    57,    47,    48,
      56,    50,    51,    57,    36,    17,     8,    51,    40,    58,
      46,    89,    24,    55,    46,    47,    48,    48,    50,    51,
      31,    32,    33,    34,    36,   161,   168,    -1,    40,    -1,
      41,    -1,   151,     3,    -1,    47,    48,     7,    50,    51,
      10,    11,    12,     7,    14,    56,    10,    11,    12,    19,
      14,    -1,    -1,    -1,    24,    19,     6,    -1,     6,     9,
      24,     9,    -1,    13,     6,    13,    -1,     9,    18,    -1,
      18,    13,    31,    32,    33,    34,    18,    26,    27,    28,
      29,    30,    41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     7,    10,    11,    12,    14,    19,    24,    60,
      62,    63,    69,    46,    10,    11,    14,    19,    99,    66,
      68,    65,    64,    67,    69,     0,     3,    62,     6,    74,
      76,     6,    72,    75,    75,    78,    71,    75,    70,    75,
      73,    75,    61,     5,    28,     5,     8,     5,     8,    28,
       5,     8,     5,     8,     5,     8,    17,    24,    36,    40,
      47,    48,    50,    51,    75,    80,   101,     6,     9,    13,
      18,    77,    72,    78,    13,    71,    70,    73,    83,    88,
      84,    85,    86,    81,   101,    46,    80,    75,     5,     8,
      79,    55,    55,    55,    55,    57,     4,     5,     5,    74,
       5,    16,    75,    89,   101,    13,    75,    92,    92,    80,
       9,    13,    18,    55,    75,    95,    96,   105,    56,    90,
      91,   101,     5,    75,    26,    27,    28,    29,    30,   100,
      56,    56,    58,    96,    31,    32,    33,    34,    41,    82,
     104,     5,     4,     4,    92,    97,    98,   105,    57,    57,
      50,    56,     5,    95,    96,     6,     9,    13,    18,   103,
      98,     5,    31,    32,    33,    34,    35,    41,   102,    80,
      80,    87,   104,    89,    97,    98,    58,    58,    55,    95,
      56,    49,    93,    92,    57,    94,    56,    80,    57,    58,
      80,    58
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 89 "project.y"
    { declarationPhase  = 0 ; add('K'); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 89 "project.y"
    { add('K'); printf("\nprogramme correct (syntaxiquement correcte)");;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 90 "project.y"
    {printf(" error : programme vide");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 91 "project.y"
    {printf("warning : programme semi vide");;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 100 "project.y"
    { insert_type(); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 101 "project.y"
    { insert_type(); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 102 "project.y"
    { insert_type(); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 103 "project.y"
    { insert_type(); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 104 "project.y"
    { insert_type();  ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 133 "project.y"
    {
 add('V'); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 136 "project.y"
    { add('C');strcpy(decCST,yytext);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 138 "project.y"
    {
  handleDecCst(decCST);
;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 140 "project.y"
    {
    //printf("\n dec cst %s\n",decCST);
    handleDecCst(decCST);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 143 "project.y"
    {handleDecCst(decCST);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 144 "project.y"
    {handleDecCst(decCST);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 149 "project.y"
    {;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 157 "project.y"
    {
  handleAffectation(); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 159 "project.y"
    { 
    strcpy(exp,"");;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 161 "project.y"
    {add('K');;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 162 "project.y"
    {add('K');;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 163 "project.y"
    {add('K');;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 164 "project.y"
    {add('K');;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 164 "project.y"
    {add('K');;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 168 "project.y"
    {add('K');;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 174 "project.y"
    {
  ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 176 "project.y"
    {
   ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 191 "project.y"
    {add('K');;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 208 "project.y"
    { insert_type();  ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 209 "project.y"
    { insert_type(); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 210 "project.y"
    { insert_type(); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 211 "project.y"
    { insert_type(); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 221 "project.y"
    {strcat(exp, yytext);;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 221 "project.y"
    {strcat(exp, yytext);;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 221 "project.y"
    {strcat(exp, yytext);;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 221 "project.y"
    {strcat(exp, yytext);;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 221 "project.y"
    {strcat(exp, yytext);;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 222 "project.y"
    {strcat(exp, yytext);
addval(y,exp);;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 223 "project.y"
    {strcat(exp, yytext);addval(y,exp);;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 223 "project.y"
    {strcat(exp, yytext);addval(y,exp);;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 223 "project.y"
    {strcat(exp, yytext);addval(y,exp);;}
    break;



/* Line 1455 of yacc.c  */
#line 1930 "project.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 238 "project.y"


void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack contents: ");
    int i;
    for (i = 0; i <= stack->top; ++i) {
        printf("%lf ", stack->array[i]);
    }
    printf("\n");
}

// Initialize a stack
Stack* initializeStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->array = (double*)malloc(size * sizeof(double));
    return stack;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(Stack* stack, double item) {
    stack->array[++stack->top] = item;
}

// Pop an element from the stack
double pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return -1; // Error: Stack is empty
}


void printCharStack(CharStack* stack) {
    if (isEmptyChar(stack)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack contents: ");
    int i;
    for (i = 0; i <= stack->top; ++i) {
        printf("%c ", stack->array[i]);
    }
    printf("\n");
}

// Initialize a character stack
CharStack* initializeCharStack(int size) {
    CharStack* stack = (CharStack*)malloc(sizeof(CharStack));
    stack->top = -1;
    stack->array = (char*)malloc(size * sizeof(char));
    return stack;
}

// Check if the character stack is empty
int isEmptyChar(CharStack* stack) {
    return stack->top == -1;
}

// Push a character onto the character stack
void pushChar(CharStack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Pop a character from the character stack
char popChar(CharStack* stack) {
    if (!isEmptyChar(stack)) {
        return stack->array[stack->top--];
    }
    return '\0'; // Error: Stack is empty
}

char * turnEXP(char * str){
     int len = strlen(str);
    char* resultt =(char*)malloc((2 * len + 1) * sizeof(char));
    char * txt=(char*)malloc((2 * len + 1) * sizeof(char));
    char* tmp = (char*)malloc((2 * len + 1) * sizeof(char)); // Maximum size after transformation
    int i=0;
    int s=0;
    int nbr=1;
    int j=0;
   for(i=0;i<strlen(str);i++){
    if(isdigit(str[i]) && str[i+1]!='.'){
      
      tmp[j]=str[i];
      j++;
    }
    else if(str[i]=='+' || str[i]=='*' || str[i]=='-' || str[i]=='/'){
      
      tmp[j]=str[i];
      j++;
    }
    else if(isdigit(str[i]) && str[i+1] == '.'){
     
      tmp[j]=str[i];
      j++;
      i=i+2;
      nbr=1;
      while(isdigit(str[i])){
              tmp[j]=str[i];
                nbr=nbr*10;
                j++;
                i++;
                
            }
            
            tmp[j]='/';
            j++;
            char nbrStr[20]; // Assuming maximum digits for an integer

            
            sprintf(nbrStr, "%d", nbr);
            for (s = 0; s < strlen(nbrStr); s++) {
                tmp[j] = nbrStr[s];
                
                j++;
            }
            i--;
            
    }
   
   } //printf("%s\n",tmp);
    return tmp;

}
// Get the precedence of an operator
int getPrecedence(char operatorr) {
    if (operatorr == '+' || operatorr == '-')
        return 1;
    else if (operatorr == '*' || operatorr == '/')
        return 2;
    return 0; // For parentheses or other characters
}

// Convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    CharStack* stack = initializeCharStack(strlen(infix));
    int i, j = 0;

    for (i = 0; infix[i]; ++i) {
        if (isdigit(infix[i])) {
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            --i;
        } else if (infix[i] == '(') {
            pushChar(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmptyChar(stack) && stack->array[stack->top] != '(') {
                postfix[j++] = popChar(stack);
                postfix[j++] = ' ';
            }
            popChar(stack); // Pop the '('
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            while (!isEmptyChar(stack) && getPrecedence(infix[i]) <= getPrecedence(stack->array[stack->top])) {
                postfix[j++] = popChar(stack);
                postfix[j++] = ' ';
            }
            pushChar(stack, infix[i]);
        }
    }

    while (!isEmptyChar(stack)) {
        postfix[j++] = popChar(stack);
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';

    free(stack->array);
    free(stack);
}

// Function to evaluate an expression
double evaluateExpression(char* expression) {
    Stack* stack = initializeStack(strlen(expression));
    int i;
   // printf("expression : %s \n", expression);
    for (i = 0; expression[i]; ++i) {
        if (isdigit(expression[i])) {
            double operand = 0;
            while (isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                ++i;
            }
            --i;
            push(stack, operand);
            //printf("firstOperand : %lf", operand);
           // printStack(stack);
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            double operand2 = pop(stack);
            double operand1 = pop(stack);

           // printStack(stack);

            switch (expression[i]) {
                case '+':
                    //printf("%lf + %lf = %lf\n", operand1, operand2, operand1 + operand2);
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0) {
                        push(stack, operand1 / operand2);
                    } else {
                        //printf("Error: Division by zero\n");
                        free(stack->array);
                        free(stack);
                        return -1;
                    }
                    break;
                //printStack(stack);
            }
        }
    }

    double result = pop(stack);
    //printStack(stack);

    //printf("result : %lf\n", result);
    if (!isEmpty(stack)) {
        printf("Error: Malformed expression\n");
        result = -1;
    }

    free(stack->array);
    free(stack);

    return result;
}

void insert(char * str,char *string){
  
   symbol_table[count].id_name=strdup(yytext);
   symbol_table[count].data_type=string;
}

const char* detectNumberType(double value) {
    
    // Check if the difference between the value and its rounded version is very small
    if (fabs(value - round(value)) < 1e-10) {
        return "int";
    } else {
        return "float";
    }
}

void addval(int x, char* expression) {
     int i,c,t;
     int j=0;
     char * nme = (char*)malloc((2 * 10 + 1) * sizeof(char));
     char* variableName = (char*)malloc((100 + 1) * sizeof(char));
      nme[0] = '\0';
        int q=0;
        int y;
    if (strcmp(symbol_table[Affvar].data_type, "bool") == 0) {
        // For boolean type, no need to evaluate the expression
        // printf("%d ligne: data_type %s (no evaluation for boolean type)\n", nb_ligne, symbol_table[Affvar].data_type);
        // Handle the assignment logic based on your requirements for boolean types
        // You might want to check if the expression is "true" or "false"
        symbol_table[Affvar].boolVal =strdup(expression) ;
    } else {
       
       
        char  tmp[100];
        for (i=0;i<strlen(expression);i++){
            j=0;
            y=0;
             
            if(expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '/' && expression[i] != '.' && !isdigit(expression[i])){
                
               while (j < strlen(expression) && (isalpha(expression[i]) || expression[i] == '_')){
                    variableName[j] = expression[i];
                    j++;
                    i++;
                    y=1;
                }
                if(y==1) i--;
                variableName[j] = '\0'; 
                //printf("\nhere %s\n",variableName);
            // Convert a single char to a string
            
               // printf("hey %s\n",nme);
                c=search(variableName);
               // printf("%d",c);
                if(c!=-1){
                int written = sprintf(tmp + q, "%lf", symbol_table[c].ValNUm);
                if (written < 0) {
                    // Handle conversion error if needed
                } else {
                    q += written;
                }  
                }
                else{
                   // printf("valeur du idf %s est null ;",symbol_table[c].id_name);
                }
            }
            else{
                tmp[q]=expression[i];
                q++;
            }
            
        }
        strcpy(expression, tmp);

    // Print or use the modified expression as needed
    //printf("\nModified Expression: %s\n", expression);
        expression = turnEXP(expression);
        
        infixToPostfix(expression, postfixExpression);
        //printf("%s",expression);
        double result = evaluateExpression(postfixExpression);

        //printf("%d ligne: data_type %s and result type %s\n", nb_ligne, symbol_table[Affvar].data_type, detectNumberType(result));

        if (strcmp(symbol_table[Affvar].data_type, "int") == 0 && strcmp(detectNumberType(result), "float") == 0) {
           errS=1; printf("%d ligne: Semantic error - assigning float to an integer\n", nb_ligne);
        }

        symbol_table[Affvar].ValNUm = result;
         symbol_table[Affvar].boolVal = "0";
    }
}
void insert_type() {
strcpy(type, yytext);
}
// bool checkConst(){
  
// }
void handleDecCst(char * cst){
  q=search(cst);
  // symbol_table[q].ValNUm=strdup(yytext);
  symbol_table[q].str=strdup(yytext);
  char * expression  ;
  
  if (strcmp(symbol_table[q].data_type, "bool") == 0) {
        // For boolean type, no need to evaluate the expression
        // printf("%d ligne: data_type %s (no evaluation for boolean type)\n", nb_ligne, symbol_table[q].data_type);
        // Handle the assignment logic based on your requirements for boolean types
        // You might want to check if the expression is "true" or "false"
        symbol_table[q].boolVal =strdup(yytext) ;
    } else {

        expression = turnEXP(yytext);
        
        infixToPostfix(expression, postfixExpression);
       // printf("\n exp %s \n",postfixExpression);
        double result = evaluateExpression(postfixExpression);

        //printf("%d ligne: data_type %s and result %lf type %s\n", nb_ligne, symbol_table[q].data_type, result,detectNumberType(result));

        if (strcmp(symbol_table[q].data_type, "int") == 0 && strcmp(detectNumberType(result), "float") == 0) {
            errS=1;
            printf("%d ligne: Semantic error - assigning float to an integer\n", nb_ligne);
        }

        symbol_table[q].ValNUm = result;
         symbol_table[q].boolVal = "0";
    }
}
void handleAffectation(){
    
  search(yytext);
  if(q==-1) {
    Affvar = -1;
    }
  else{
    Affvar =q;
    // printf("%d idf exist with index %d \n" , nb_ligne ,q) ;
    if( strcmp(strdup("Constante") ,symbol_table[q].type)==0){
      errS=1;
      printf("%d symentic error -> affectation to const "ANSI_COLOR_PINK  " %s "ANSI_COLOR_RESET " \n\n" , nb_ligne , symbol_table[q].id_name) ;
    } 
    
  }
  // if(checkConst()){printf('Changement de valeur d’une constante')} ;
}
// here fixed , adding to symbolic table only idf's in the declaration phase and keywords  
void add(char str) {
  q=search(yytext);
  
  if (q==-1) {
    if(declarationPhase ==0 && str!='K'){
        errS=1;
      printf("%d symentic error -> idf"ANSI_COLOR_PINK  " %s "ANSI_COLOR_RESET "not declared \n\n" ,nb_ligne,yytext) ;
    }
    if(str=='V' && declarationPhase==1){
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=nb_ligne;
			symbol_table[count].type=strdup("Variable");
      symbol_table[count].str="/";
 
			count++;
    }
    else if(str=='C' && declarationPhase==1){
      
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=nb_ligne;
			symbol_table[count].type=strdup("Constante");      
      symbol_table[count].str="/";
			count++;
    }
    else if(str == 'K') {
			
			symbol_table[count].data_type=strdup("N/A");
			symbol_table[count].line_no=nb_ligne;
			symbol_table[count].type=strdup("Keyword\t");
      symbol_table[count].str="/";
			count++;
		}
  }
  else{
    if(declarationPhase==1){
        errS=1;
      printf("line :%d symentic error --> IDF %s already declared\n" , nb_ligne , symbol_table[q].id_name);
    }
    
    // so here it does not mean it's symentic error if we didn't found it 
    // check if it's
    // printf("erreur SEMANTIQUE %c la ligne %d \n",yytext,nb_ligne);
  }
}
// fixed here -1 is also false in c 
int search(char* name) {
    int i;
   
    for (i = 0; i <= count-1; i++) {
        if (strcmp(symbol_table[i].id_name, name) == 0) {
          // if(symbol_table[i].str=="0") { symbol_table[i].ValNUm=0;}
            return i;  // Return the index of the found identifier
        }
    }
    return -1;  // Identifier not found
}

void afficher(){
  printf("\n\n");
  if(errS!=1){
	printf(ANSI_COLOR_YELLOW "\nNAME           DATATYPE         TYPE        LINE NUMBER           VALUE \n"ANSI_COLOR_RESET);
	printf("________________________________________________________________________________\n\n");
	int i=0;
	for (i = 0; i < count; i++) {
    if (symbol_table[i].boolVal != NULL && strcmp(symbol_table[i].boolVal, "0") != 0) {
        printf("%s\t\t%s\t\t%s\t\t%d\t\t%s\t\t \n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no, symbol_table[i].boolVal );
    } else {
        printf("%s\t\t%s\t\t%s\t\t%d\t\t%lf\t\t \n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no, symbol_table[i].ValNUm );
    }
  }
	for(i=0;i<count;i++) {
		free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}
	printf("\n\n");}
}
yywrap()
{}
void yyerror(const char* msg) {
  fprintf(stderr, "\nError: %s ligne %d\n ", msg,nb_ligne-1);
}
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = freopen(argv[1], "r", stdin);
    if (file == NULL) {
        perror("Error");
        return 1;
    }

    yyparse();
    afficher();
    fclose(file);
   
    return 0;
}

