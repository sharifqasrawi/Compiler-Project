/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     IDENTIFIER = 259,
     RETURN = 260,
     INTEGER = 261,
     DOUBLENUM = 262,
     CLASS = 263,
     FOR = 264,
     NEW = 265,
     IF = 266,
     WHILE = 267,
     DOUBLE = 268,
     BOOL = 269,
     VOID = 270,
     TRUE = 271,
     FALSE = 272,
     IFPREC = 273,
     ELSE = 274,
     OR = 275,
     AND = 276,
     NEQ = 277,
     EQ = 278,
     LOQ = 279,
     MOQ = 280,
     MINUS = 281,
     INCREMENT = 282,
     DECREMENT = 283,
     NOT = 284
   };
#endif
/* Tokens.  */
#define INT 258
#define IDENTIFIER 259
#define RETURN 260
#define INTEGER 261
#define DOUBLENUM 262
#define CLASS 263
#define FOR 264
#define NEW 265
#define IF 266
#define WHILE 267
#define DOUBLE 268
#define BOOL 269
#define VOID 270
#define TRUE 271
#define FALSE 272
#define IFPREC 273
#define ELSE 274
#define OR 275
#define AND 276
#define NEQ 277
#define EQ 278
#define LOQ 279
#define MOQ 280
#define MINUS 281
#define INCREMENT 282
#define DECREMENT 283
#define NOT 284




/* Copy the first part of user declarations.  */
#line 1 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"

	#include <iostream>
	#include "parser.h"
	using std::cout;
	using std::endl;
	
	extern int yylex();
	extern int yyerror(const char *);
	extern int column;
	extern int line;



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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 17 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
typedef union YYSTYPE {
	 Ident* tIdent;
	 IdentExpr* tIdExpr;
	 Expr* tExpr;
	 ExprList* tExprs;
	 Integer* tInt;
	 Double* tDouble;
	 Bool* tBool;
	 Minus* tMinus;
	 Variable* tVar;
	 Variables* tVars;
	 Type* tType;
	 Primitive_Type* tPtype;
	 Array_Type* tArrType;
	 Param* tParam;
	 Params* tParams;
	 Stmnt* tStmnt;
	 Stmnts* tStmnts;
	 Global* tGlobal;
	 Func* tFunc;
	 Field* tField;
	 Fields* tFields;
	 Class* tClass;
	 Root* tRoot;

} YYSTYPE;
/* Line 196 of yacc.c.  */
#line 183 "parser.cpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 195 "parser.cpp"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

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

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
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
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   372

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  21
/* YYNRULES -- Number of rules. */
#define YYNRULES  73
/* YYNRULES -- Number of states. */
#define YYNSTATES  154

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      42,    43,    31,    29,    41,    30,    37,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
      26,    20,    25,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    21,    22,    23,    24,    27,
      28,    33,    34,    35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     5,    11,    13,    15,    16,    19,    23,
      29,    30,    32,    36,    39,    44,    45,    55,    56,    66,
      67,    70,    74,    79,    82,    90,    94,   100,   106,   116,
     122,   126,   129,   132,   134,   136,   138,   140,   142,   147,
     153,   157,   161,   165,   169,   172,   176,   180,   184,   188,
     192,   196,   199,   202,   206,   210,   213,   218,   219,   221,
     222,   224,   228,   231,   232,   234,   238,   240,   242,   244,
     246,   248,   252,   256
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      47,     0,    -1,    48,    -1,     8,     4,    38,    50,    39,
      -1,    51,    -1,    54,    -1,    -1,    50,    49,    -1,    64,
       4,    40,    -1,    64,     4,    20,    59,    40,    -1,    -1,
      53,    -1,    52,    41,    53,    -1,    64,     4,    -1,    64,
       4,    20,    59,    -1,    -1,    64,     4,    55,    42,    63,
      43,    38,    57,    39,    -1,    -1,    15,     4,    56,    42,
      63,    43,    38,    57,    39,    -1,    -1,    57,    58,    -1,
       5,    59,    40,    -1,     4,    20,    59,    40,    -1,    52,
      40,    -1,     4,    44,    59,    45,    20,    59,    40,    -1,
      11,    59,    58,    -1,    11,    59,    58,    19,    58,    -1,
      12,    42,    59,    43,    58,    -1,     9,    42,    53,    40,
      60,    40,    60,    43,    58,    -1,     4,    42,    61,    43,
      40,    -1,    38,    57,    39,    -1,     4,    34,    -1,     4,
      35,    -1,     4,    -1,     6,    -1,     7,    -1,    16,    -1,
      17,    -1,     4,    44,    59,    45,    -1,    10,    65,    44,
       6,    45,    -1,    59,    29,    59,    -1,    59,    30,    59,
      -1,    59,    31,    59,    -1,    59,    32,    59,    -1,    30,
      59,    -1,    59,    26,    59,    -1,    59,    25,    59,    -1,
      59,    24,    59,    -1,    59,    23,    59,    -1,    59,    27,
      59,    -1,    59,    28,    59,    -1,     4,    34,    -1,     4,
      35,    -1,    59,    22,    59,    -1,    59,    21,    59,    -1,
      36,    59,    -1,     4,    42,    61,    43,    -1,    -1,    59,
      -1,    -1,    59,    -1,    61,    41,    59,    -1,    64,     4,
      -1,    -1,    62,    -1,    63,    41,    62,    -1,    65,    -1,
      66,    -1,     3,    -1,    13,    -1,    14,    -1,     3,    44,
      45,    -1,    13,    44,    45,    -1,    14,    44,    45,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   102,   102,   111,   119,   123,   130,   133,   140,   145,
     153,   156,   162,   169,   174,   182,   181,   191,   190,   204,
     207,   214,   218,   223,   227,   232,   236,   240,   244,   249,
     254,   258,   263,   272,   277,   281,   285,   289,   293,   298,
     304,   308,   312,   316,   320,   324,   328,   332,   336,   340,
     344,   348,   353,   357,   361,   365,   369,   376,   377,   384,
     387,   393,   400,   409,   412,   418,   426,   431,   439,   443,
     447,   453,   457,   461
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "IDENTIFIER", "RETURN", "INTEGER",
  "DOUBLENUM", "CLASS", "FOR", "NEW", "IF", "WHILE", "DOUBLE", "BOOL",
  "VOID", "TRUE", "FALSE", "IFPREC", "ELSE", "'='", "OR", "AND", "NEQ",
  "EQ", "'>'", "'<'", "LOQ", "MOQ", "'+'", "'-'", "'*'", "'/'", "MINUS",
  "INCREMENT", "DECREMENT", "NOT", "'.'", "'{'", "'}'", "';'", "','",
  "'('", "')'", "'['", "']'", "$accept", "file", "Class", "field",
  "fields", "Global", "variables", "variable", "function", "@1", "@2",
  "statements", "statement", "expression", "expr_empty",
  "expression_Or_No", "Param", "Params", "Data_Type", "primitive_type",
  "Array_type", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      61,   275,   276,   277,   278,    62,    60,   279,   280,    43,
      45,    42,    47,   281,   282,   283,   284,    46,   123,   125,
      59,    44,    40,    41,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    46,    47,    48,    49,    49,    50,    50,    51,    51,
      52,    52,    52,    53,    53,    55,    54,    56,    54,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    60,    61,
      61,    61,    62,    63,    63,    63,    64,    64,    65,    65,
      65,    66,    66,    66
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     5,     1,     1,     0,     2,     3,     5,
       0,     1,     3,     2,     4,     0,     9,     0,     9,     0,
       2,     3,     4,     2,     7,     3,     5,     5,     9,     5,
       3,     2,     2,     1,     1,     1,     1,     1,     4,     5,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     3,     2,     4,     0,     1,     0,
       1,     3,     2,     0,     1,     3,     1,     1,     1,     1,
       1,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,     0,     2,     0,     1,     6,     0,    68,    69,
      70,     0,     3,     7,     4,     5,     0,    66,    67,     0,
       0,     0,    17,    15,    71,    72,    73,     0,     0,     8,
       0,    63,    33,    34,    35,     0,    36,    37,     0,     0,
       0,    63,    64,     0,     0,    51,    52,    59,     0,    68,
      69,    70,     0,    44,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,     0,     0,
       0,    62,    60,     0,     0,     0,    54,    53,    48,    47,
      46,    45,    49,    50,    40,    41,    42,    43,     0,    65,
      19,     0,    56,    38,     0,    19,    10,    61,    39,    10,
       0,     0,     0,     0,     0,    19,    18,     0,    11,    20,
       0,    16,     0,    31,    32,    59,     0,     0,     0,    10,
       0,    10,    23,     0,    13,     0,     0,     0,    21,     0,
      25,     0,    30,    12,     0,    22,     0,     0,    57,    10,
      10,    14,    29,     0,    58,     0,    26,    27,     0,    57,
      24,     0,    10,    28
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     2,     3,    13,     7,    14,   107,   108,    15,    30,
      27,    96,   109,    72,   145,    73,    42,    43,   110,    17,
      18
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -116
static const short int yypact[] =
{
      -4,    22,    43,  -116,     2,  -116,  -116,     3,    12,    13,
      21,    47,  -116,  -116,  -116,  -116,    67,  -116,  -116,    37,
      42,    51,  -116,   -19,  -116,  -116,  -116,    44,   152,  -116,
      59,    -1,   312,  -116,  -116,    11,  -116,  -116,   152,   152,
     222,    -1,  -116,   -36,    81,  -116,  -116,   152,   152,  -116,
    -116,  -116,    58,  -116,  -116,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,  -116,    29,    -1,
      69,  -116,   302,    35,   149,   102,   313,   209,   332,   332,
     340,   340,   340,   340,    -9,    -9,  -116,  -116,    78,  -116,
    -116,   152,  -116,  -116,    72,  -116,    41,   302,  -116,    55,
     173,   152,    76,   152,    77,  -116,  -116,     7,  -116,  -116,
     116,  -116,   152,  -116,  -116,   152,   152,   242,    -1,   123,
     152,    86,  -116,    -1,   103,   262,    40,   174,  -116,    82,
     110,   199,  -116,  -116,   152,  -116,    90,   111,   152,   100,
     100,   302,  -116,   152,   302,    93,  -116,  -116,   282,   152,
    -116,    96,   100,  -116
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
    -116,  -116,  -116,  -116,  -116,  -116,  -116,  -115,  -116,  -116,
    -116,   -86,   -78,   -28,    -8,    25,    73,   119,     8,   108,
    -116
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const short int yytable[] =
{
      40,    28,     8,   129,     1,    69,     8,    70,   133,    99,
      53,    54,     9,    10,    49,    16,     9,    10,    11,   121,
      74,    29,    65,    66,    50,    51,     4,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    44,
       6,   130,    12,     5,     8,   100,   101,   122,   123,    44,
     102,    22,   103,   104,     9,    10,    19,    20,     8,   100,
     101,   146,   147,    97,   102,    21,   103,   104,     9,    10,
      69,    23,    88,   117,   153,   119,    91,    44,    92,   105,
     106,    91,    24,   136,   125,    71,    31,    25,   127,     8,
     100,   101,   131,   105,   111,   102,    26,   103,   104,     9,
      10,    41,    75,     8,   100,   101,   141,    90,    94,   102,
     144,   103,   104,     9,    10,   148,    95,    98,   118,   120,
     124,   144,   138,   134,   105,   132,     8,   100,   101,   139,
     142,   143,   102,   149,   103,   104,     9,    10,   105,   152,
     126,   151,    89,    52,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    32,     0,    33,    34,
      68,   105,    35,     0,     0,     0,     0,     0,    36,    37,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    38,     0,     0,     0,     0,     0,    39,     0,
       0,     0,     0,   112,    93,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,   113,   114,     0,
       0,     0,     0,     0,     0,   115,     0,   116,     0,   137,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,   140,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,     0,     0,     0,     0,
       0,     0,    67,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,     0,     0,     0,     0,
       0,     0,   128,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,     0,     0,     0,     0,
       0,     0,   135,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,     0,     0,     0,     0,
       0,     0,   150,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    45,    46,     0,     0,
       0,     0,     0,     0,    47,     0,    48,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    63,
      64,    65,    66
};

static const short int yycheck[] =
{
      28,    20,     3,   118,     8,    41,     3,    43,   123,    95,
      38,    39,    13,    14,     3,     7,    13,    14,    15,   105,
      48,    40,    31,    32,    13,    14,     4,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    31,
      38,   119,    39,     0,     3,     4,     5,    40,    41,    41,
       9,     4,    11,    12,    13,    14,    44,    44,     3,     4,
       5,   139,   140,    91,     9,    44,    11,    12,    13,    14,
      41,     4,    43,   101,   152,   103,    41,    69,    43,    38,
      39,    41,    45,    43,   112,     4,    42,    45,   116,     3,
       4,     5,   120,    38,    39,     9,    45,    11,    12,    13,
      14,    42,    44,     3,     4,     5,   134,    38,     6,     9,
     138,    11,    12,    13,    14,   143,    38,    45,    42,    42,
       4,   149,    40,    20,    38,    39,     3,     4,     5,    19,
      40,    20,     9,    40,    11,    12,    13,    14,    38,    43,
     115,   149,    69,    35,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     4,    -1,     6,     7,
      41,    38,    10,    -1,    -1,    -1,    -1,    -1,    16,    17,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    20,    45,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    44,    -1,    45,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    43,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    44,    25,    26,    27,
      28,    29,    30,    31,    32,    25,    26,    27,    28,    29,
      30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     8,    47,    48,     4,     0,    38,    50,     3,    13,
      14,    15,    39,    49,    51,    54,    64,    65,    66,    44,
      44,    44,     4,     4,    45,    45,    45,    56,    20,    40,
      55,    42,     4,     6,     7,    10,    16,    17,    30,    36,
      59,    42,    62,    63,    64,    34,    35,    42,    44,     3,
      13,    14,    65,    59,    59,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    40,    63,    41,
      43,     4,    59,    61,    59,    44,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    43,    62,
      38,    41,    43,    45,     6,    38,    57,    59,    45,    57,
       4,     5,     9,    11,    12,    38,    39,    52,    53,    58,
      64,    39,    20,    34,    35,    42,    44,    59,    42,    59,
      42,    57,    40,    41,     4,    59,    61,    59,    40,    53,
      58,    59,    39,    53,    20,    40,    43,    45,    40,    19,
      43,    59,    40,    20,    59,    60,    58,    58,    59,    40,
      40,    60,    43,    58
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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
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
    while (0)
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
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
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
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
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
      size_t yyn = 0;
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

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
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
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

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
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


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
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
#line 103 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
				(yyval.tRoot) = new Root((yyvsp[0].tClass), line, column);
				root = (yyval.tRoot);
				cout << "Parsing Done Successfully." << endl;
			;}
    break;

  case 3:
#line 112 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
				(yyval.tClass) = new Class((yyvsp[-3].tIdent), (yyvsp[-1].tFields), line, column);
			;}
    break;

  case 4:
#line 120 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
				(yyval.tField) = (yyvsp[0].tGlobal);
			;}
    break;

  case 5:
#line 124 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
				(yyval.tField) = (yyvsp[0].tFunc);
			;}
    break;

  case 6:
#line 130 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
				(yyval.tFields) = new Fields(line, column);
			;}
    break;

  case 7:
#line 134 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
				(yyvsp[-1].tFields)->addField((yyvsp[0].tField));
				(yyval.tFields) = (yyvsp[-1].tFields);
			;}
    break;

  case 8:
#line 141 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {	 
				(yyval.tGlobal) = new Global((yyvsp[-2].tType),(yyvsp[-1].tIdent),line,column); 
				symbolTable->addSymbol((yyvsp[-1].tIdent), (yyvsp[-2].tType)->t, "G");
			;}
    break;

  case 9:
#line 146 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
				(yyval.tGlobal) = new Global((yyvsp[-4].tType),(yyvsp[-3].tIdent),(yyvsp[-1].tExpr),line,column);
				symbolTable->addSymbol((yyvsp[-3].tIdent), (yyvsp[-4].tType)->t, "G");
			;}
    break;

  case 10:
#line 153 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
				(yyval.tVars) = new Variables(line, column);
			;}
    break;

  case 11:
#line 157 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
				Variables* vars = new Variables(line, column);
				vars->addVariable((yyvsp[0].tVar));
				(yyval.tVars) = vars;
			;}
    break;

  case 12:
#line 163 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
				(yyvsp[-2].tVars)->addVariable((yyvsp[0].tVar));
				(yyval.tVars) = (yyvsp[-2].tVars);
			;}
    break;

  case 13:
#line 170 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
				(yyval.tVar) = new Variable((yyvsp[-1].tType) ,(yyvsp[0].tIdent), NULL, line, column); 
				symbolTable->addSymbol((yyvsp[0].tIdent), (yyvsp[-1].tType)->t, "L");
			;}
    break;

  case 14:
#line 175 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
				(yyval.tVar) = new Variable((yyvsp[-3].tType), (yyvsp[-2].tIdent), (yyvsp[0].tExpr), line, column); 
				symbolTable->addSymbol((yyvsp[-2].tIdent), (yyvsp[-3].tType)->t, "L");
			;}
    break;

  case 15:
#line 182 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
				symbolTable->addScope();
			;}
    break;

  case 16:
#line 185 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
				(yyval.tFunc) = new Func((yyvsp[-8].tType), (yyvsp[-7].tIdent), (yyvsp[-4].tParams), (yyvsp[-1].tStmnts), line, column);
				symbolTable->closeScope();
				symbolTable->addFuncSymbol((yyvsp[-7].tIdent), (yyvsp[-8].tType)->t, (yyvsp[-4].tParams)->params, (yyval.tFunc));
			;}
    break;

  case 17:
#line 191 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
				symbolTable->addScope();
			;}
    break;

  case 18:
#line 194 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
				(yyval.tFunc) = new Func(NULL, (yyvsp[-7].tIdent), (yyvsp[-4].tParams), (yyvsp[-1].tStmnts), line, column);
				symbolTable->closeScope();
				symbolTable->addFuncSymbol((yyvsp[-7].tIdent), NULL, (yyvsp[-4].tParams)->params, (yyval.tFunc));
				
			;}
    break;

  case 19:
#line 204 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
				(yyval.tStmnts) = new Stmnts(line, column);
			;}
    break;

  case 20:
#line 208 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
				(yyvsp[-1].tStmnts)->addStmnt((yyvsp[0].tStmnt));
				(yyval.tStmnts) = (yyvsp[-1].tStmnts);
			;}
    break;

  case 21:
#line 215 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tStmnt) = new ReturnStmnt((yyvsp[-1].tExpr), line, column);
				;}
    break;

  case 22:
#line 219 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
					(yyval.tStmnt) = new Assign((yyvsp[-3].tIdent), (yyvsp[-1].tExpr), line, column);
					symbolTable->checkSymbol((yyvsp[-3].tIdent));
				;}
    break;

  case 23:
#line 224 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					
				;}
    break;

  case 24:
#line 228 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
					(yyval.tStmnt) = new ArrayAssign((yyvsp[-6].tIdent), (yyvsp[-4].tExpr), (yyvsp[-1].tExpr), line, column);
					symbolTable->checkSymbol((yyvsp[-6].tIdent));
				;}
    break;

  case 25:
#line 233 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
					(yyval.tStmnt) = new IfStmnt((yyvsp[-1].tExpr), (yyvsp[0].tStmnt), line, column);
				;}
    break;

  case 26:
#line 237 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
					(yyval.tStmnt) = new IfElseStmnt((yyvsp[-3].tExpr), (yyvsp[-2].tStmnt), (yyvsp[0].tStmnt), line, column);  
				;}
    break;

  case 27:
#line 241 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {  
					(yyval.tStmnt) = new WhileStmnt((yyvsp[-2].tExpr), (yyvsp[0].tStmnt), line, column);
				;}
    break;

  case 28:
#line 245 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {  
					(yyval.tStmnt) = new ForStmnt((yyvsp[-6].tVar), (yyvsp[-4].tExpr), (yyvsp[-2].tExpr), (yyvsp[0].tStmnt), line, column);
					symbolTable->checkSymbol((yyvsp[-6].tVar)->ident);
				;}
    break;

  case 29:
#line 250 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
				    (yyval.tStmnt) = new FuncCallStmnt((yyvsp[-4].tIdent), (yyvsp[-2].tExprs), line, column);
					//symbolTable->checkFunc($1,$3);
				;}
    break;

  case 30:
#line 255 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
					(yyval.tStmnt) = new Block((yyvsp[-1].tStmnts), line, column);
				;}
    break;

  case 31:
#line 259 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
					(yyval.tStmnt) = new IncrementStmnt((yyvsp[-1].tIdent), line, column);
					symbolTable->checkSymbol((yyvsp[-1].tIdent));
				;}
    break;

  case 32:
#line 264 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tStmnt) = new DecrementStmnt((yyvsp[-1].tIdent), line, column);
					symbolTable->checkSymbol((yyvsp[-1].tIdent));
				;}
    break;

  case 33:
#line 273 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tExpr) = new IdentExpr((yyvsp[0].tIdent), line, column); 
					symbolTable->checkSymbol((yyvsp[0].tIdent));
				;}
    break;

  case 34:
#line 278 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {	
					(yyval.tExpr) = (yyvsp[0].tInt);
				;}
    break;

  case 35:
#line 282 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tExpr) = (yyvsp[0].tDouble); 
				;}
    break;

  case 36:
#line 286 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tExpr) = (yyvsp[0].tBool); 
				;}
    break;

  case 37:
#line 290 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tExpr) = (yyvsp[0].tBool); 
				;}
    break;

  case 38:
#line 294 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tExpr) = new Array((yyvsp[-3].tIdent), (yyvsp[-1].tExpr), line, column); 
					symbolTable->checkSymbol((yyvsp[-3].tIdent));
				;}
    break;

  case 39:
#line 299 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {  
					newArray* arr = new newArray((yyvsp[-3].tPtype), (yyvsp[-1].tInt), line, column);
					arr->size = (yyvsp[-1].tInt);
					(yyval.tExpr) = arr;
				;}
    break;

  case 40:
#line 305 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tExpr) = new Add((yyvsp[-2].tExpr), (yyvsp[0].tExpr) , line , column); 
				;}
    break;

  case 41:
#line 309 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tExpr) = new Sub((yyvsp[-2].tExpr), (yyvsp[0].tExpr) , line , column); 
				;}
    break;

  case 42:
#line 313 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tExpr) = new Mult((yyvsp[-2].tExpr), (yyvsp[0].tExpr) , line , column); 
				;}
    break;

  case 43:
#line 317 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
					 (yyval.tExpr) = new Divid((yyvsp[-2].tExpr), (yyvsp[0].tExpr) , line , column); 
				;}
    break;

  case 44:
#line 321 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tExpr) = new Minus((yyvsp[0].tExpr), line, column); 
				;}
    break;

  case 45:
#line 325 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tExpr) = new LessThan((yyvsp[-2].tExpr), (yyvsp[0].tExpr) , line , column); 
				;}
    break;

  case 46:
#line 329 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
					(yyval.tExpr) = new GreaterThan((yyvsp[-2].tExpr), (yyvsp[0].tExpr) , line , column); 
				;}
    break;

  case 47:
#line 333 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tExpr) = new Equal((yyvsp[-2].tExpr), (yyvsp[0].tExpr) , line , column);
				;}
    break;

  case 48:
#line 337 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tExpr) = new NotEqual((yyvsp[-2].tExpr), (yyvsp[0].tExpr) , line , column); 
				;}
    break;

  case 49:
#line 341 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tExpr) = new LessOrEqual((yyvsp[-2].tExpr), (yyvsp[0].tExpr) , line , column); 
				;}
    break;

  case 50:
#line 345 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tExpr) = new MoreOrEqual((yyvsp[-2].tExpr), (yyvsp[0].tExpr) , line , column); 
				;}
    break;

  case 51:
#line 349 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
					(yyval.tExpr) = new Increment((yyvsp[-1].tIdent), line, column);
					symbolTable->checkSymbol((yyvsp[-1].tIdent));
				;}
    break;

  case 52:
#line 354 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tExpr) = new Decrement((yyvsp[-1].tIdent), line, column);
				;}
    break;

  case 53:
#line 358 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tExpr) = new And((yyvsp[-2].tExpr), (yyvsp[0].tExpr) , line , column); 
				;}
    break;

  case 54:
#line 362 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tExpr) = new Or((yyvsp[-2].tExpr), (yyvsp[0].tExpr) , line , column); 
				;}
    break;

  case 55:
#line 366 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tExpr) = new Not((yyvsp[0].tExpr), line, column); 
				;}
    break;

  case 56:
#line 370 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
					(yyval.tExpr) = new FuncCall((yyvsp[-3].tIdent), (yyvsp[-1].tExprs), line, column);

					//symbolTable->checkFunc($1, $3);					
				;}
    break;

  case 57:
#line 376 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {;}
    break;

  case 58:
#line 378 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
			
			;}
    break;

  case 59:
#line 384 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
					 (yyval.tExprs) = new ExprList( line, column); 
				;}
    break;

  case 60:
#line 388 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					ExprList* exprs = new ExprList(line, column);
					exprs->addExpr((yyvsp[0].tExpr));
					(yyval.tExprs) = exprs;
				;}
    break;

  case 61:
#line 394 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
					(yyvsp[-2].tExprs)->addExpr((yyvsp[0].tExpr));
					(yyval.tExprs) = (yyvsp[-2].tExprs);
				;}
    break;

  case 62:
#line 401 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
					 (yyval.tParam) = new Param((yyvsp[-1].tType), (yyvsp[0].tIdent), line, column); 
					 symbolTable->addSymbol((yyvsp[0].tIdent), (yyvsp[-1].tType)->t, "P");
				;}
    break;

  case 63:
#line 409 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
					(yyval.tParams) = new Params(line, column);
				;}
    break;

  case 64:
#line 413 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
					Params* prms = new Params(line, column);
					prms->addParam((yyvsp[0].tParam));
					(yyval.tParams) = prms;
				;}
    break;

  case 65:
#line 419 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyvsp[-2].tParams)->addParam((yyvsp[0].tParam));
					(yyval.tParams) = (yyvsp[-2].tParams);
				;}
    break;

  case 66:
#line 427 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tType) = (yyvsp[0].tPtype);
					(yyval.tType)->t = (yyvsp[0].tPtype)->type;
				;}
    break;

  case 67:
#line 432 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tType) = (yyvsp[0].tArrType);
					(yyval.tType)->t = (yyvsp[0].tArrType)->type;
				;}
    break;

  case 68:
#line 440 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tPtype) = new Primitive_Type(1,"Primitive",line, column); 
				;}
    break;

  case 69:
#line 444 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tPtype) = new Primitive_Type(2,"Primitive",line, column); 
				;}
    break;

  case 70:
#line 448 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tPtype) = new Primitive_Type(3,"Primitive",line, column); 
				;}
    break;

  case 71:
#line 454 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tArrType) = new Array_Type(4,"Array", line, column); 
				;}
    break;

  case 72:
#line 458 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    {
					(yyval.tArrType) = new Array_Type(5,"Array", line, column); 
				;}
    break;

  case 73:
#line 462 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"
    { 
					(yyval.tArrType) = new Array_Type(6,"Array", line, column); 
				;}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 1899 "parser.cpp"

  yyvsp -= yylen;
  yyssp -= yylen;


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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
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
	  int yychecklim = YYLAST - yyn;
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
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
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
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
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


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 467 "F:\\SVU\\Assginments\\S15\\CMPP\\ISE_CMPP_S15_Final\\ISE_CMPP_S15_Final\\ISE_CMPP_S15\\ISE_CMPP_S15\\parser.y"


int yyerror(const char * s)
{
	cout << "Parser Error, " << s << " at line: ["<< line << "] Column: [" << column <<"]" << endl;
	return 1;
}
