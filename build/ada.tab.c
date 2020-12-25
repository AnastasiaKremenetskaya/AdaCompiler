/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

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
#define YYBISON_VERSION "2.3"

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
     INTEGER = 258,
     BOOLEAN = 259,
     FLOAT = 260,
     CHARACTER = 261,
     STRING = 262,
     ARRAY = 263,
     ID = 264,
     CONST_STRING = 265,
     CONST_INTEGER = 266,
     CONST_FLOAT = 267,
     CONST_CHARACTER = 268,
     CONST_BOOL = 269,
     RANGE = 270,
     LENGTH = 271,
     NIL = 272,
     WHILE = 273,
     FOR = 274,
     IN = 275,
     OF = 276,
     LOOP = 277,
     IF = 278,
     THEN = 279,
     ELSIF = 280,
     ELSE = 281,
     FUNCTION = 282,
     PROCEDURE = 283,
     IS = 284,
     RETURN = 285,
     BEGINs = 286,
     END = 287,
     DOUBLE_DOT = 288,
     ASSIGNMENT = 289,
     AND = 290,
     OR = 291,
     GREATER_EQUAL = 292,
     LESSER_EQUAL = 293,
     NOT_EQUAL = 294,
     UPLUS = 295,
     UMINUS = 296,
     NOT = 297
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define BOOLEAN 259
#define FLOAT 260
#define CHARACTER 261
#define STRING 262
#define ARRAY 263
#define ID 264
#define CONST_STRING 265
#define CONST_INTEGER 266
#define CONST_FLOAT 267
#define CONST_CHARACTER 268
#define CONST_BOOL 269
#define RANGE 270
#define LENGTH 271
#define NIL 272
#define WHILE 273
#define FOR 274
#define IN 275
#define OF 276
#define LOOP 277
#define IF 278
#define THEN 279
#define ELSIF 280
#define ELSE 281
#define FUNCTION 282
#define PROCEDURE 283
#define IS 284
#define RETURN 285
#define BEGINs 286
#define END 287
#define DOUBLE_DOT 288
#define ASSIGNMENT 289
#define AND 290
#define OR 291
#define GREATER_EQUAL 292
#define LESSER_EQUAL 293
#define NOT_EQUAL 294
#define UPLUS 295
#define UMINUS 296
#define NOT 297




/* Copy the first part of user declarations.  */
#line 1 "../parser/ada.y"

	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>

	#if defined(__MACH__)
	#include <stdlib.h>
	#else
	#include <malloc.h>
	#endif
	
	#include "tree_nodes.h"
	#include "../build/ada.tab.h"

	extern int yylex(void);

	void yyerror(char const *s);

	Expression *createSimpleExpression(EXPR_TYPE type, value val);
	Expression *createExpressionWithList(EXPR_TYPE type, value val, ExpressionList *exprList);
	Expression *createExpression(EXPR_TYPE type, Expression *left, Expression *right);

	ExpressionList *appendExpressionToList(ExpressionList *list, Expression *expr);
	ExpressionList *createExpressionList(Expression *expr);

	WhileStatement *createWhile(Expression *condition, StatementList *whileBlock);
	Range *createRange(Expression *startIndex, Expression *lastIndex, char* id);
	ForStatement *createFor(char *iterID, Range *countIterations, StatementList *forBlock);
	StatementList *appendStatementToList(StatementList *list, Statement *stmt);
	StatementList *createStatementList(Statement *stmt);
	IfStatement *createIf(Expression *condition, StatementList *stmtList, ElseIfStatementList *elseIfStmtList, ElseStatement *elseStmt);
	ElseStatement *createElse(StatementList *stmtList);
	ElseIfStatement *createElseIf(Expression *condition, StatementList *stmtList);
	ElseIfStatementList *createElseIfStatementList(ElseIfStatement *stmt);
	ElseIfStatementList *appendElseIfToList(ElseIfStatementList *list, ElseIfStatement *stmt);
	Statement *createStatement(STMT_TYPE type, stmtValue val);

	VariableList *createVariableList(char* id);
	VariableList *appendToVariableList(VariableList *list, char* id);
	VariableDeclaration *createVariableDeclaration(VAR_TYPE type, VariableList *varList, Range *range);

	VariableDeclarationList *createVariableDeclarationList(VariableDeclaration *varDecl);
	VariableDeclarationList *appendVariableDeclarationList(VariableDeclarationList *list, VariableDeclaration *varDecl);

	AssigmentStatement *createAssigmentStmt(Expression *left, Expression *right);
	DeclarationStatement *createDeclarationStatement(DEC_TYPE type, declarationStmt stmt);
	DeclarationStatementList *createDeclarationStatementList(DeclarationStatement *stmt);
	DeclarationStatementList *appendDeclarationStatementToList(DeclarationStatementList *list, DeclarationStatement *stmt);

	Program *createProgram(char *id, DeclarationStatementList *declarationSection, StatementList *performSection,VariableDeclarationList *globalariables, VAR_TYPE returnType);

	ProgramList *createProgramList(Program *prog);
	ProgramList *appentProgramToList(ProgramList *list, Program *prog);

	ProgramList *root;


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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 58 "../parser/ada.y"
{

	int int_const;
	float float_const;
	char *string_const;
	char *id_const;
	char char_const;
	VAR_TYPE vt;

	Expression *expr;
	ExpressionList *exprList;
	Statement *stmt;
	StatementList *stmtList;
	WhileStatement *whileStmt;
	Range *rangeStmt;
	AssigmentStatement *assigStmt;
	ForStatement *forStmt;
	IfStatement *ifStmt;
	ElseStatement *elseStmt;
	ElseIfStatement *elseIfStmt;
	ElseIfStatementList *elseIfStmtList;
	VariableList *varList;
	VariableDeclaration *varDecl;
	VariableDeclarationList *varDeclList;
	DeclarationStatement *declStmt;
	DeclarationStatementList *declStmtList;
	Program *prog;
	ProgramList *progList;
}
/* Line 193 of yacc.c.  */
#line 267 "ada.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 280 "ada.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   724

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNRULES -- Number of states.  */
#define YYNSTATES  209

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,    56,
      58,    57,    53,    48,    34,    49,     2,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,    33,
      43,    42,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    35,    36,
      40,    41,    45,    46,    47,    51,    52,    55
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    15,    19,    23,    26,    29,
      32,    36,    40,    44,    48,    52,    56,    60,    64,    69,
      73,    78,    80,    82,    84,    86,    88,    90,    94,    96,
      98,   100,   102,   104,   106,   108,   110,   112,   114,   116,
     118,   120,   123,   126,   130,   134,   139,   147,   157,   167,
     176,   177,   180,   185,   187,   190,   194,   197,   200,   202,
     206,   210,   219,   221,   225,   227,   231,   234,   236,   238,
     241,   250,   260,   272,   285,   296,   308,   322,   337,   339,
     341,   344
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      83,     0,    -1,    60,    48,    60,    -1,    60,    49,    60,
      -1,    60,    53,    60,    -1,    60,    54,    60,    -1,    60,
      50,    60,    -1,    48,    60,    -1,    49,    60,    -1,    55,
      60,    -1,    60,    43,    60,    -1,    60,    44,    60,    -1,
      60,    46,    60,    -1,    60,    45,    60,    -1,    60,    42,
      60,    -1,    60,    47,    60,    -1,    60,    41,    60,    -1,
      60,    40,    60,    -1,     9,    58,    75,    57,    -1,    58,
      60,    57,    -1,    60,    38,    60,    39,    -1,    11,    -1,
      12,    -1,    10,    -1,    13,    -1,    14,    -1,     9,    -1,
       9,    56,    16,    -1,     3,    -1,     5,    -1,     7,    -1,
       6,    -1,     4,    -1,    64,    -1,    67,    -1,    68,    -1,
      69,    -1,    73,    -1,    74,    -1,    66,    -1,    62,    -1,
      63,    62,    -1,    60,    33,    -1,    60,    35,    60,    -1,
       9,    56,    15,    -1,    60,    36,    60,    33,    -1,    18,
      60,    22,    63,    32,    22,    33,    -1,    19,     9,    20,
      65,    22,    63,    32,    22,    33,    -1,    23,    60,    24,
      63,    72,    70,    32,    23,    33,    -1,    23,    60,    24,
      63,    70,    32,    23,    33,    -1,    -1,    26,    63,    -1,
      25,    60,    24,    63,    -1,    71,    -1,    72,    71,    -1,
      30,    60,    33,    -1,    30,    33,    -1,    17,    33,    -1,
      60,    -1,    75,    34,    60,    -1,    77,    37,    61,    -1,
      77,    37,     8,    58,    65,    57,    21,    61,    -1,     9,
      -1,    77,    34,     9,    -1,    76,    -1,    78,    33,    76,
      -1,    76,    33,    -1,    81,    -1,    79,    -1,    80,    79,
      -1,    28,     9,    29,    31,    63,    32,     9,    33,    -1,
      28,     9,    29,    80,    31,    63,    32,     9,    33,    -1,
      28,     9,    58,    78,    57,    29,    31,    63,    32,     9,
      33,    -1,    28,     9,    58,    78,    57,    29,    80,    31,
      63,    32,     9,    33,    -1,    27,     9,    30,    61,    29,
      31,    63,    32,     9,    33,    -1,    27,     9,    30,    61,
      29,    80,    31,    63,    32,     9,    33,    -1,    27,     9,
      58,    78,    57,    30,    61,    29,    31,    63,    32,     9,
      33,    -1,    27,     9,    58,    78,    57,    30,    61,    29,
      80,    31,    63,    32,     9,    33,    -1,     1,    -1,    81,
      -1,    82,    81,    -1,    82,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   166,   166,   167,   168,   169,   170,   172,   173,   175,
     176,   177,   178,   179,   180,   181,   183,   184,   186,   188,
     190,   192,   193,   194,   195,   196,   198,   199,   202,   203,
     204,   205,   206,   209,   210,   211,   212,   213,   214,   215,
     218,   219,   222,   225,   226,   229,   231,   234,   237,   238,
     241,   242,   245,   248,   249,   252,   253,   256,   259,   260,
     263,   264,   267,   268,   271,   272,   275,   276,   279,   280,
     283,   284,   286,   287,   289,   290,   292,   293,   295,   298,
     299,   302
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "BOOLEAN", "FLOAT",
  "CHARACTER", "STRING", "ARRAY", "ID", "CONST_STRING", "CONST_INTEGER",
  "CONST_FLOAT", "CONST_CHARACTER", "CONST_BOOL", "RANGE", "LENGTH", "NIL",
  "WHILE", "FOR", "IN", "OF", "LOOP", "IF", "THEN", "ELSIF", "ELSE",
  "FUNCTION", "PROCEDURE", "IS", "RETURN", "BEGINs", "END", "';'", "','",
  "DOUBLE_DOT", "ASSIGNMENT", "':'", "'['", "']'", "AND", "OR", "'='",
  "'<'", "'>'", "GREATER_EQUAL", "LESSER_EQUAL", "NOT_EQUAL", "'+'", "'-'",
  "'&'", "UPLUS", "UMINUS", "'*'", "'/'", "NOT", "'''", "')'", "'('",
  "$accept", "expression", "variable_type", "statement", "statement_list",
  "expression_statement", "range", "assigment_statement",
  "while_statement", "for_statement", "if_statement", "else_statement",
  "elsif_statement", "elsif_statement_list", "return_statement",
  "empty_statement", "expression_list", "variable_declaration",
  "variable_list", "variable_declaration_list", "declaration_statement",
  "declaration_statement_list", "program_block", "program_list", "program", 0
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
     285,   286,   287,    59,    44,   288,   289,    58,    91,    93,
     290,   291,    61,    60,    62,   292,   293,   294,    43,    45,
      38,   295,   296,    42,    47,   297,    39,    41,    40
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    61,    61,
      61,    61,    61,    62,    62,    62,    62,    62,    62,    62,
      63,    63,    64,    65,    65,    66,    67,    68,    69,    69,
      70,    70,    71,    72,    72,    73,    73,    74,    75,    75,
      76,    76,    77,    77,    78,    78,    79,    79,    80,    80,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    82,
      82,    83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     3,     3,     3,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     3,
       4,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     3,     4,     7,     9,     9,     8,
       0,     2,     4,     1,     2,     3,     2,     2,     1,     3,
       3,     8,     1,     3,     1,     3,     2,     1,     1,     2,
       8,     9,    11,    12,    10,    11,    13,    14,     1,     1,
       2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    78,     0,     0,    79,     0,     0,     0,     0,    80,
       1,     0,     0,     0,     0,    28,    32,    29,    31,    30,
       0,    62,    64,     0,     0,     0,     0,    68,     0,    67,
       0,     0,     0,     0,     0,     0,    26,    23,    21,    22,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    40,     0,    33,    39,    34,    35,    36,    37,
      38,    66,     0,    69,     0,     0,     0,    63,     0,    60,
      65,     0,     0,     0,    57,     0,     0,     0,    56,     0,
       7,     8,     9,     0,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,    27,    58,
       0,     0,     0,     0,    55,    19,     0,     0,    17,    16,
      14,    10,    11,    13,    12,    15,     2,     3,     6,     4,
       5,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       0,     0,    18,     0,     0,    50,    45,    20,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    59,
       0,     0,     0,     0,     0,    53,    50,    71,     0,     0,
      74,     0,    44,    43,     0,     0,     0,     0,     0,     0,
      51,     0,     0,    54,     0,     0,    75,    61,     0,     0,
      46,     0,     0,     0,     0,    72,     0,     0,     0,     0,
      52,    49,     0,    73,    76,     0,    47,    48,    77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    51,    20,    52,    53,    54,   139,    55,    56,    57,
      58,   164,   165,   166,    59,    60,   110,    26,    23,    24,
      27,    28,    29,     5,     6
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -59
static const yytype_int16 yypact[] =
{
      49,   -59,    16,    35,   -59,   112,     5,   -13,   -15,   -59,
     -59,   195,    72,    73,    72,   -59,   -59,   -59,   -59,   -59,
      55,   -59,   -59,   -22,   -30,   422,    53,   -59,    79,   -59,
      -9,    93,    82,   505,    72,    65,   -47,   -59,   -59,   -59,
     -59,   -59,    84,   473,    89,   473,   448,   473,   473,   473,
     473,   550,   -59,   161,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   422,   -59,    94,   422,   110,   -59,    68,   -59,
     -59,   195,   117,   473,   -59,   -12,   123,   500,   -59,   568,
      91,    91,   108,   603,   -59,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     145,   -59,   194,   154,   218,   422,   481,   130,   -59,   657,
      39,   422,   481,   422,   -59,   -59,   586,   640,   670,   670,
     425,   425,   425,   425,   425,   425,    91,    91,    91,   108,
     108,   127,   152,   422,   441,   157,   245,    -4,   623,   111,
     506,   473,   -59,   269,   155,   139,   -59,   -59,   -59,   134,
     296,   422,   143,   174,    41,   473,   165,   422,   551,   657,
     167,   422,   473,   422,   158,   -59,   105,   -59,   183,   320,
     -59,   162,   -59,   657,   195,   347,   422,   163,   371,   527,
     422,   191,   186,   -59,   182,   211,   -59,   -59,   212,   398,
     -59,   200,   422,   190,   202,   -59,   201,   205,   224,   206,
     422,   -59,   207,   -59,   -59,   213,   -59,   -59,   -59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -59,   -27,   -32,   -53,   -58,   -59,   132,   -59,   -59,   -59,
     -59,    81,    85,   -59,   -59,   -59,   -59,    75,   -59,   231,
     -26,   -25,     8,   -59,   -59
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -82
static const yytype_int16 yytable[] =
{
     101,    69,    63,    34,   102,    10,    66,   104,     4,    72,
     111,    73,    32,     9,    13,    33,    75,    11,    77,    79,
      80,    81,    82,    83,    34,     7,    86,    35,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,   107,
      63,    98,    99,    14,     8,    12,   109,   136,    64,   101,
       1,   101,   154,   143,    73,   145,   172,   108,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   141,     1,   150,     2,     3,   134,   138,
       1,    21,    21,   101,    31,   138,    61,    22,    21,    22,
     101,    67,   101,   169,     1,    71,   142,   101,    76,   175,
       2,     3,    21,   178,    25,   180,     2,     3,    63,    70,
      62,     1,   -81,     1,   159,   158,   101,    74,   189,    21,
       2,     3,   101,   103,    65,   101,   106,   101,   173,    86,
     162,   163,    63,   108,   200,   179,   101,     2,     3,     2,
       3,   105,   187,   112,    98,    99,    86,   101,    36,    37,
      38,    39,    40,    41,   131,     1,    42,    43,    44,   140,
     148,   149,    45,    21,   162,   163,   152,   167,   156,    46,
      36,    37,    38,    39,    40,    41,   170,   161,    42,    43,
      44,     2,     3,   171,    45,   133,   174,    47,    48,   177,
     181,    46,   184,   100,    49,   186,   190,    50,    15,    16,
      17,    18,    19,    36,    37,    38,    39,    40,    41,    47,
      48,    42,    43,    44,   193,   195,    49,    45,   194,    50,
     196,   197,   199,   201,    46,   202,   132,    36,    37,    38,
      39,    40,    41,   205,   203,    42,    43,    44,   204,   206,
     207,    45,    47,    48,   144,    30,   208,   182,    46,    49,
     135,   183,    50,     0,    36,    37,    38,    39,    40,    41,
       0,     0,    42,    43,    44,     0,    47,    48,    45,     0,
       0,     0,     0,    49,     0,    46,    50,   153,    36,    37,
      38,    39,    40,    41,     0,     0,    42,    43,    44,     0,
       0,     0,    45,    47,    48,     0,     0,     0,     0,    46,
      49,   160,     0,    50,     0,    36,    37,    38,    39,    40,
      41,     0,     0,    42,    43,    44,     0,    47,    48,    45,
       0,     0,     0,     0,    49,     0,    46,    50,   168,    36,
      37,    38,    39,    40,    41,     0,     0,    42,    43,    44,
       0,     0,     0,    45,    47,    48,     0,     0,     0,     0,
      46,    49,   185,     0,    50,     0,    36,    37,    38,    39,
      40,    41,     0,     0,    42,    43,    44,     0,    47,    48,
      45,     0,     0,     0,     0,    49,     0,    46,    50,   188,
      36,    37,    38,    39,    40,    41,     0,     0,    42,    43,
      44,     0,     0,     0,    45,    47,    48,     0,     0,     0,
       0,    46,    49,   191,     0,    50,     0,    36,    37,    38,
      39,    40,    41,     0,     0,    42,    43,    44,     0,    47,
      48,    45,     0,     0,     0,     0,    49,     0,    46,    50,
     198,    36,    37,    38,    39,    40,    41,     0,     0,    42,
      43,    44,     1,     0,     0,    45,    47,    48,     0,     0,
      21,     0,    46,    49,     0,     0,    50,    36,    37,    38,
      39,    40,    41,    86,     0,     0,     0,     0,     2,     3,
      47,    48,   151,    95,    96,    97,     0,    49,    98,    99,
      50,    78,    36,    37,    38,    39,    40,    41,     0,     0,
     137,    37,    38,    39,    40,    41,    47,    48,     0,     0,
       0,     0,     0,    49,     0,     0,    50,     1,    15,    16,
      17,    18,    19,    68,     0,    21,     0,     0,     0,     0,
       0,    47,    48,     0,   113,     0,     0,     0,    49,    47,
      48,    50,     0,     2,     3,     0,    49,   157,    86,    50,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,   192,     1,    98,    99,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,    86,     0,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,     2,     3,
      98,    99,   176,    84,     0,     0,    85,     0,    86,     0,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,   114,     0,    98,    99,     0,    86,     0,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,   146,
       0,    98,    99,     0,    86,     0,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,     0,     0,    98,
      99,    86,     0,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,     0,     0,    98,    99,   155,     0,
     115,    86,     0,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,     0,     0,    98,    99,    86,   147,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,     0,     0,    98,    99,    86,     0,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    86,     0,
      98,    99,    89,    90,    91,    92,    93,    94,    95,    96,
      97,     0,     0,    98,    99
};

static const yytype_int16 yycheck[] =
{
      53,    33,    28,    33,    62,     0,    31,    65,     0,    56,
      22,    58,    34,     5,    29,    37,    43,    30,    45,    46,
      47,    48,    49,    50,    33,     9,    38,    57,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    71,
      66,    53,    54,    58,     9,    58,    73,   105,    57,   102,
       1,   104,    56,   111,    58,   113,    15,    16,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,    34,     1,   133,    27,    28,   103,   106,
       1,     9,     9,   136,    29,   112,    33,    12,     9,    14,
     143,     9,   145,   151,     1,    30,    57,   150,     9,   157,
      27,    28,     9,   161,    31,   163,    27,    28,   134,    34,
      31,     1,     0,     1,   141,   140,   169,    33,   176,     9,
      27,    28,   175,    29,    31,   178,    58,   180,   155,    38,
      25,    26,   158,    16,   192,   162,   189,    27,    28,    27,
      28,    31,   174,    20,    53,    54,    38,   200,     9,    10,
      11,    12,    13,    14,     9,     1,    17,    18,    19,    29,
      33,     9,    23,     9,    25,    26,     9,    33,    57,    30,
       9,    10,    11,    12,    13,    14,    33,    22,    17,    18,
      19,    27,    28,     9,    23,    31,    21,    48,    49,    22,
      32,    30,     9,    32,    55,    33,    33,    58,     3,     4,
       5,     6,     7,     9,    10,    11,    12,    13,    14,    48,
      49,    17,    18,    19,    23,    33,    55,    23,    32,    58,
       9,     9,    22,    33,    30,    23,    32,     9,    10,    11,
      12,    13,    14,     9,    33,    17,    18,    19,    33,    33,
      33,    23,    48,    49,   112,    14,    33,   166,    30,    55,
      32,   166,    58,    -1,     9,    10,    11,    12,    13,    14,
      -1,    -1,    17,    18,    19,    -1,    48,    49,    23,    -1,
      -1,    -1,    -1,    55,    -1,    30,    58,    32,     9,    10,
      11,    12,    13,    14,    -1,    -1,    17,    18,    19,    -1,
      -1,    -1,    23,    48,    49,    -1,    -1,    -1,    -1,    30,
      55,    32,    -1,    58,    -1,     9,    10,    11,    12,    13,
      14,    -1,    -1,    17,    18,    19,    -1,    48,    49,    23,
      -1,    -1,    -1,    -1,    55,    -1,    30,    58,    32,     9,
      10,    11,    12,    13,    14,    -1,    -1,    17,    18,    19,
      -1,    -1,    -1,    23,    48,    49,    -1,    -1,    -1,    -1,
      30,    55,    32,    -1,    58,    -1,     9,    10,    11,    12,
      13,    14,    -1,    -1,    17,    18,    19,    -1,    48,    49,
      23,    -1,    -1,    -1,    -1,    55,    -1,    30,    58,    32,
       9,    10,    11,    12,    13,    14,    -1,    -1,    17,    18,
      19,    -1,    -1,    -1,    23,    48,    49,    -1,    -1,    -1,
      -1,    30,    55,    32,    -1,    58,    -1,     9,    10,    11,
      12,    13,    14,    -1,    -1,    17,    18,    19,    -1,    48,
      49,    23,    -1,    -1,    -1,    -1,    55,    -1,    30,    58,
      32,     9,    10,    11,    12,    13,    14,    -1,    -1,    17,
      18,    19,     1,    -1,    -1,    23,    48,    49,    -1,    -1,
       9,    -1,    30,    55,    -1,    -1,    58,     9,    10,    11,
      12,    13,    14,    38,    -1,    -1,    -1,    -1,    27,    28,
      48,    49,    31,    48,    49,    50,    -1,    55,    53,    54,
      58,    33,     9,    10,    11,    12,    13,    14,    -1,    -1,
       9,    10,    11,    12,    13,    14,    48,    49,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    58,     1,     3,     4,
       5,     6,     7,     8,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    48,    49,    -1,    24,    -1,    -1,    -1,    55,    48,
      49,    58,    -1,    27,    28,    -1,    55,    31,    38,    58,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    24,     1,    53,    54,    -1,    -1,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    27,    28,
      53,    54,    31,    33,    -1,    -1,    36,    -1,    38,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    33,    -1,    53,    54,    -1,    38,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    33,
      -1,    53,    54,    -1,    38,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    -1,    53,
      54,    38,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    53,    54,    35,    -1,
      57,    38,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    53,    54,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    53,    54,    38,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    38,    -1,
      53,    54,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    53,    54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    27,    28,    81,    82,    83,     9,     9,    81,
       0,    30,    58,    29,    58,     3,     4,     5,     6,     7,
      61,     9,    76,    77,    78,    31,    76,    79,    80,    81,
      78,    29,    34,    37,    33,    57,     9,    10,    11,    12,
      13,    14,    17,    18,    19,    23,    30,    48,    49,    55,
      58,    60,    62,    63,    64,    66,    67,    68,    69,    73,
      74,    33,    31,    79,    57,    31,    80,     9,     8,    61,
      76,    30,    56,    58,    33,    60,     9,    60,    33,    60,
      60,    60,    60,    60,    33,    36,    38,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    53,    54,
      32,    62,    63,    29,    63,    31,    58,    61,    16,    60,
      75,    22,    20,    24,    33,    57,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,     9,    32,    31,    80,    32,    63,     9,    60,    65,
      29,    34,    57,    63,    65,    63,    33,    39,    33,     9,
      63,    31,     9,    32,    56,    35,    57,    31,    80,    60,
      32,    22,    25,    26,    70,    71,    72,    33,    32,    63,
      33,     9,    15,    60,    21,    63,    31,    22,    63,    60,
      63,    32,    70,    71,     9,    32,    33,    61,    32,    63,
      33,    32,    24,    23,    32,    33,     9,     9,    32,    22,
      63,    33,    23,    33,    33,     9,    33,    33,    33
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

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

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 166 "../parser/ada.y"
    {(yyval.expr) = createExpression(ET_PLUS, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));;}
    break;

  case 3:
#line 167 "../parser/ada.y"
    {(yyval.expr) = createExpression(ET_MINUS, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));;}
    break;

  case 4:
#line 168 "../parser/ada.y"
    {(yyval.expr) = createExpression(ET_MULT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));;}
    break;

  case 5:
#line 169 "../parser/ada.y"
    {(yyval.expr) = createExpression(ET_DIV, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));;}
    break;

  case 6:
#line 170 "../parser/ada.y"
    {(yyval.expr) = createExpression(ET_CONCAT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));;}
    break;

  case 7:
#line 172 "../parser/ada.y"
    {(yyval.expr) = createExpression(ET_PLUS, NULL, (yyvsp[(2) - (2)].expr));;}
    break;

  case 8:
#line 173 "../parser/ada.y"
    {(yyval.expr) = createExpression(ET_MINUS, NULL, (yyvsp[(2) - (2)].expr));;}
    break;

  case 9:
#line 175 "../parser/ada.y"
    {(yyval.expr) = createExpression(ET_NOT, NULL, (yyvsp[(2) - (2)].expr));;}
    break;

  case 10:
#line 176 "../parser/ada.y"
    {(yyval.expr) = createExpression(ET_LESSER, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));;}
    break;

  case 11:
#line 177 "../parser/ada.y"
    {(yyval.expr) = createExpression(ET_GREATER, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));;}
    break;

  case 12:
#line 178 "../parser/ada.y"
    {(yyval.expr) = createExpression(ET_LESSER_EQUAL, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));;}
    break;

  case 13:
#line 179 "../parser/ada.y"
    {(yyval.expr) = createExpression(ET_GREATER_EQUAL, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));;}
    break;

  case 14:
#line 180 "../parser/ada.y"
    {(yyval.expr) = createExpression(ET_EQUAL, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));;}
    break;

  case 15:
#line 181 "../parser/ada.y"
    {(yyval.expr) = createExpression(ET_NOT_EQUAL, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));;}
    break;

  case 16:
#line 183 "../parser/ada.y"
    {(yyval.expr) = createExpression(ET_LOGIC_OR, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));;}
    break;

  case 17:
#line 184 "../parser/ada.y"
    {(yyval.expr) = createExpression(ET_LOGIC_AND, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));;}
    break;

  case 18:
#line 186 "../parser/ada.y"
    {(yyval.expr) = createExpressionWithList(ET_ARRAY_OR_FUNC, (value){.string_val=(yyvsp[(1) - (4)].id_const)}, (yyvsp[(3) - (4)].exprList));;}
    break;

  case 19:
#line 188 "../parser/ada.y"
    {(yyval.expr) = (yyvsp[(2) - (3)].expr);;}
    break;

  case 20:
#line 190 "../parser/ada.y"
    {(yyval.expr) = createExpression(ET_INDEXER, (yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr));;}
    break;

  case 21:
#line 192 "../parser/ada.y"
    {(yyval.expr) = createSimpleExpression(ET_INTEGER, (value){.int_val = (yyvsp[(1) - (1)].int_const)});;}
    break;

  case 22:
#line 193 "../parser/ada.y"
    {(yyval.expr) = createSimpleExpression(ET_FLOAT, (value){.float_val=(yyvsp[(1) - (1)].float_const)});;}
    break;

  case 23:
#line 194 "../parser/ada.y"
    {(yyval.expr) = createSimpleExpression(ET_STRING, (value){.string_val=(yyvsp[(1) - (1)].string_const)});;}
    break;

  case 24:
#line 195 "../parser/ada.y"
    {(yyval.expr) = createSimpleExpression(ET_CHARACTER, (value){.char_val=(yyvsp[(1) - (1)].char_const)});;}
    break;

  case 25:
#line 196 "../parser/ada.y"
    {(yyval.expr) = createSimpleExpression(ET_BOOL, (value){.int_val=(yyvsp[(1) - (1)].int_const)});;}
    break;

  case 26:
#line 198 "../parser/ada.y"
    {(yyval.expr) = createSimpleExpression(ET_ID, (value){.string_val=(yyvsp[(1) - (1)].id_const)});;}
    break;

  case 27:
#line 199 "../parser/ada.y"
    {(yyval.expr) = createSimpleExpression(ET_LENGTH_ARR_ATTR, (value){.string_val=(yyvsp[(1) - (3)].id_const)});;}
    break;

  case 28:
#line 202 "../parser/ada.y"
    {(yyval.vt) = VT_INTEGER;;}
    break;

  case 29:
#line 203 "../parser/ada.y"
    {(yyval.vt) = VT_FLOAT;;}
    break;

  case 30:
#line 204 "../parser/ada.y"
    {(yyval.vt) = VT_STRING;;}
    break;

  case 31:
#line 205 "../parser/ada.y"
    {(yyval.vt) = VT_CHARACTER;;}
    break;

  case 32:
#line 206 "../parser/ada.y"
    {(yyval.vt) = VT_BOOLEAN;;}
    break;

  case 33:
#line 209 "../parser/ada.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmt);;}
    break;

  case 34:
#line 210 "../parser/ada.y"
    {(yyval.stmt) = createStatement(ST_WHILE, (stmtValue){.whileStmt=(yyvsp[(1) - (1)].whileStmt)});;}
    break;

  case 35:
#line 211 "../parser/ada.y"
    {(yyval.stmt) = createStatement(ST_FOR, (stmtValue){.forStmt=(yyvsp[(1) - (1)].forStmt)});;}
    break;

  case 36:
#line 212 "../parser/ada.y"
    {(yyval.stmt) = createStatement(ST_IF, (stmtValue){.ifStmt=(yyvsp[(1) - (1)].ifStmt)});;}
    break;

  case 37:
#line 213 "../parser/ada.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmt);;}
    break;

  case 38:
#line 214 "../parser/ada.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmt);;}
    break;

  case 39:
#line 215 "../parser/ada.y"
    {(yyval.stmt) = createStatement(ST_ASSIGN, (stmtValue){.assigStmt=(yyvsp[(1) - (1)].assigStmt)});;}
    break;

  case 40:
#line 218 "../parser/ada.y"
    {(yyval.stmtList) = createStatementList((yyvsp[(1) - (1)].stmt));;}
    break;

  case 41:
#line 219 "../parser/ada.y"
    {(yyval.stmtList) = appendStatementToList((yyvsp[(1) - (2)].stmtList),(yyvsp[(2) - (2)].stmt));;}
    break;

  case 42:
#line 222 "../parser/ada.y"
    {(yyval.stmt) = createStatement(ST_EXPRESSION, (stmtValue){.exprStmt=(yyvsp[(1) - (2)].expr)});;}
    break;

  case 43:
#line 225 "../parser/ada.y"
    {(yyval.rangeStmt) = createRange((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr), NULL);;}
    break;

  case 44:
#line 226 "../parser/ada.y"
    {(yyval.rangeStmt) = createRange(NULL, NULL, (yyvsp[(1) - (3)].id_const));;}
    break;

  case 45:
#line 229 "../parser/ada.y"
    {(yyval.assigStmt) = createAssigmentStmt((yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr));;}
    break;

  case 46:
#line 231 "../parser/ada.y"
    {(yyval.whileStmt) = createWhile((yyvsp[(2) - (7)].expr), (yyvsp[(4) - (7)].stmtList));;}
    break;

  case 47:
#line 234 "../parser/ada.y"
    {(yyval.forStmt) = createFor((yyvsp[(2) - (9)].id_const),(yyvsp[(4) - (9)].rangeStmt),(yyvsp[(6) - (9)].stmtList));;}
    break;

  case 48:
#line 237 "../parser/ada.y"
    {(yyval.ifStmt) = createIf((yyvsp[(2) - (9)].expr), (yyvsp[(4) - (9)].stmtList), (yyvsp[(5) - (9)].elseIfStmtList), (yyvsp[(6) - (9)].elseStmt));;}
    break;

  case 49:
#line 238 "../parser/ada.y"
    {(yyval.ifStmt) = createIf((yyvsp[(2) - (8)].expr), (yyvsp[(4) - (8)].stmtList), NULL, (yyvsp[(5) - (8)].elseStmt));;}
    break;

  case 50:
#line 241 "../parser/ada.y"
    {(yyval.elseStmt) = NULL;;}
    break;

  case 51:
#line 242 "../parser/ada.y"
    {(yyval.elseStmt) = createElse((yyvsp[(2) - (2)].stmtList));;}
    break;

  case 52:
#line 245 "../parser/ada.y"
    {(yyval.elseIfStmt) = createElseIf((yyvsp[(2) - (4)].expr), (yyvsp[(4) - (4)].stmtList));;}
    break;

  case 53:
#line 248 "../parser/ada.y"
    {(yyval.elseIfStmtList) = createElseIfStatementList((yyvsp[(1) - (1)].elseIfStmt));;}
    break;

  case 54:
#line 249 "../parser/ada.y"
    {(yyval.elseIfStmtList) = appendElseIfToList((yyvsp[(1) - (2)].elseIfStmtList), (yyvsp[(2) - (2)].elseIfStmt));;}
    break;

  case 55:
#line 252 "../parser/ada.y"
    {(yyval.stmt) = createStatement(ST_RETURN, (stmtValue){.exprStmt=(yyvsp[(2) - (3)].expr)});;}
    break;

  case 56:
#line 253 "../parser/ada.y"
    {(yyval.stmt) = createStatement(ST_RETURN, (stmtValue){});;}
    break;

  case 57:
#line 256 "../parser/ada.y"
    {(yyval.stmt) = createStatement(ST_NULL, (stmtValue){});;}
    break;

  case 58:
#line 259 "../parser/ada.y"
    {(yyval.exprList) = createExpressionList((yyvsp[(1) - (1)].expr));;}
    break;

  case 59:
#line 260 "../parser/ada.y"
    {(yyval.exprList) = appendExpressionToList((yyvsp[(1) - (3)].exprList),(yyvsp[(3) - (3)].expr));;}
    break;

  case 60:
#line 263 "../parser/ada.y"
    {(yyval.varDecl) = createVariableDeclaration((yyvsp[(3) - (3)].vt),(yyvsp[(1) - (3)].varList),NULL);;}
    break;

  case 61:
#line 264 "../parser/ada.y"
    {(yyval.varDecl) = createVariableDeclaration((yyvsp[(8) - (8)].vt),(yyvsp[(1) - (8)].varList),(yyvsp[(5) - (8)].rangeStmt));;}
    break;

  case 62:
#line 267 "../parser/ada.y"
    {(yyval.varList) = createVariableList((yyvsp[(1) - (1)].id_const));;}
    break;

  case 63:
#line 268 "../parser/ada.y"
    {(yyval.varList) = appendToVariableList((yyvsp[(1) - (3)].varList), (yyvsp[(3) - (3)].id_const));;}
    break;

  case 64:
#line 271 "../parser/ada.y"
    {(yyval.varDeclList) = createVariableDeclarationList((yyvsp[(1) - (1)].varDecl));;}
    break;

  case 65:
#line 272 "../parser/ada.y"
    {(yyval.varDeclList) = appendVariableDeclarationList((yyvsp[(1) - (3)].varDeclList),(yyvsp[(3) - (3)].varDecl));;}
    break;

  case 66:
#line 275 "../parser/ada.y"
    {(yyval.declStmt) = createDeclarationStatement(DT_VARIABLE, (declarationStmt){.varDecl=(yyvsp[(1) - (2)].varDecl)});;}
    break;

  case 67:
#line 276 "../parser/ada.y"
    {(yyval.declStmt) = createDeclarationStatement(DT_FUNCTION, (declarationStmt){.prog=(yyvsp[(1) - (1)].prog)});;}
    break;

  case 68:
#line 279 "../parser/ada.y"
    {(yyval.declStmtList) = createDeclarationStatementList((yyvsp[(1) - (1)].declStmt));;}
    break;

  case 69:
#line 280 "../parser/ada.y"
    {(yyval.declStmtList) = appendDeclarationStatementToList((yyvsp[(1) - (2)].declStmtList), (yyvsp[(2) - (2)].declStmt));;}
    break;

  case 70:
#line 283 "../parser/ada.y"
    {(yyval.prog) = createProgram((yyvsp[(2) - (8)].id_const),NULL,(yyvsp[(5) - (8)].stmtList),NULL,VT_VOID);;}
    break;

  case 71:
#line 284 "../parser/ada.y"
    {(yyval.prog) = createProgram((yyvsp[(2) - (9)].id_const),(yyvsp[(4) - (9)].declStmtList),(yyvsp[(6) - (9)].stmtList),NULL,VT_VOID);;}
    break;

  case 72:
#line 286 "../parser/ada.y"
    {(yyval.prog) = createProgram((yyvsp[(2) - (11)].id_const),NULL,(yyvsp[(8) - (11)].stmtList),(yyvsp[(4) - (11)].varDeclList),VT_VOID);;}
    break;

  case 73:
#line 287 "../parser/ada.y"
    {(yyval.prog) = createProgram((yyvsp[(2) - (12)].id_const),(yyvsp[(7) - (12)].declStmtList),(yyvsp[(9) - (12)].stmtList),(yyvsp[(4) - (12)].varDeclList),VT_VOID);;}
    break;

  case 74:
#line 289 "../parser/ada.y"
    {(yyval.prog) = createProgram((yyvsp[(2) - (10)].id_const),NULL,(yyvsp[(7) - (10)].stmtList),NULL,(yyvsp[(4) - (10)].vt));;}
    break;

  case 75:
#line 290 "../parser/ada.y"
    {(yyval.prog) = createProgram((yyvsp[(2) - (11)].id_const),(yyvsp[(6) - (11)].declStmtList),(yyvsp[(8) - (11)].stmtList),NULL,(yyvsp[(4) - (11)].vt));;}
    break;

  case 76:
#line 292 "../parser/ada.y"
    {(yyval.prog) = createProgram((yyvsp[(2) - (13)].id_const),NULL,(yyvsp[(10) - (13)].stmtList),(yyvsp[(4) - (13)].varDeclList),(yyvsp[(7) - (13)].vt));;}
    break;

  case 77:
#line 293 "../parser/ada.y"
    {(yyval.prog) = createProgram((yyvsp[(2) - (14)].id_const),(yyvsp[(9) - (14)].declStmtList),(yyvsp[(11) - (14)].stmtList),(yyvsp[(4) - (14)].varDeclList),(yyvsp[(7) - (14)].vt));;}
    break;

  case 78:
#line 295 "../parser/ada.y"
    {(yyval.prog) = NULL;;}
    break;

  case 79:
#line 298 "../parser/ada.y"
    { (yyval.progList) = createProgramList((yyvsp[(1) - (1)].prog)); ;}
    break;

  case 80:
#line 299 "../parser/ada.y"
    { (yyval.progList) = appentProgramToList((yyvsp[(1) - (2)].progList),(yyvsp[(2) - (2)].prog)); ;}
    break;

  case 81:
#line 302 "../parser/ada.y"
    {(yyval.progList) = root = (yyvsp[(1) - (1)].progList);;}
    break;


/* Line 1267 of yacc.c.  */
#line 2155 "ada.tab.c"
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
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
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

  if (yyn == YYFINAL)
    YYACCEPT;

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


#line 305 "../parser/ada.y"


void yyerror(char const *s)
{
	printf("%s",s);
}

Expression *createSimpleExpression(EXPR_TYPE type, value val)
{
	Expression *result = (Expression *)malloc(sizeof(Expression));

	result->type = type;
	result->val = val;

	result->exprList = NULL;
	result->right = NULL;
	result->left = NULL;
	result->nextInList = NULL;

	return result;
}

Expression *createExpression(EXPR_TYPE type, Expression *left, Expression *right)
{
	Expression *result = (Expression *)malloc(sizeof(Expression));

	result->type = type;

	result->left = left;
	result->right = right;

	result->exprList = NULL;
	result->nextInList = NULL;

	return result;
}

AssigmentStatement *createAssigmentStmt(Expression *left, Expression *right)
{
	AssigmentStatement *result = (AssigmentStatement *)malloc(sizeof(AssigmentStatement));

	result->left = left;
	result->right = right;

	return result;
}

Expression *createExpressionWithList(EXPR_TYPE type, value val, ExpressionList *exprList)
{
	Expression *result = (Expression *)malloc(sizeof(Expression));

	result->type = type;
	result->val = val;
	result->exprList = exprList;

	result->right = NULL;
	result->left = NULL;
	result->nextInList = NULL;

	return result;
}

ExpressionList *appendExpressionToList(ExpressionList *list, Expression *expr)
{
	list->end->nextInList = expr;
	list->end = expr;

	return list;
}

ExpressionList *createExpressionList(Expression *expr)
{
	ExpressionList *result = (ExpressionList *)malloc(sizeof(ExpressionList));

	result->begin = expr;
	result->end = expr;

	return result;
}

WhileStatement *createWhile(Expression *condition, StatementList *whileBlock)
{
	WhileStatement *result = (WhileStatement *)malloc(sizeof(WhileStatement));

	result->condition = condition;
	result->whileBlock = whileBlock;

	return result;
}

Range *createRange(Expression *startIndex, Expression *lastIndex, char* id)
{
	struct Range *result = (Range *)malloc(sizeof(Range));

	result->startIndex = startIndex;
	result->lastIndex = lastIndex;
	result->id = id;
}

StatementList *appendStatementToList(StatementList *list, Statement *stmt)
{
	list->end->nextInList = stmt;
	list->end = stmt;
	return list;
}

StatementList *createStatementList(Statement *stmt)
{
	StatementList *result = (StatementList *)malloc(sizeof(StatementList));

	result->begin = stmt;
	result->end = stmt;
	return result;
}

ForStatement *createFor(char *iterID, Range *countIterations, StatementList *forBlock)
{
	ForStatement *result = (ForStatement *)malloc(sizeof(ForStatement));

	result->iterID = iterID;
	result->range = countIterations;
	result->stmtList = forBlock;

	return result;
}

IfStatement *createIf(Expression *condition, StatementList *stmtList, ElseIfStatementList *elseIfStmtList, ElseStatement *elseStmt)
{
	IfStatement *result = (IfStatement *)malloc(sizeof(IfStatement));

	result->condition = condition;
	result->stmtList = stmtList;
	result->elseIfStmtList = elseIfStmtList;
	result->elseStmt = elseStmt;

	return result;
}

ElseStatement *createElse(StatementList *stmtList)
{
	ElseStatement *result = (ElseStatement *)malloc(sizeof(ElseStatement));

	result->stmtList = stmtList;

	return result;
}

ElseIfStatement *createElseIf(Expression *condition, StatementList *stmtList)
{
	ElseIfStatement *result = (ElseIfStatement *)malloc(sizeof(ElseIfStatement));

	result->condition = condition;
	result->stmtList = stmtList;
	result->nextInList = NULL;

	return result;
}

ElseIfStatementList *createElseIfStatementList(ElseIfStatement *stmt)
{
	ElseIfStatementList *result = (ElseIfStatementList *)malloc(sizeof(ElseIfStatementList));

	result->begin = stmt;
	result->end = stmt;

	return result;
}

ElseIfStatementList *appendElseIfToList(ElseIfStatementList *list, ElseIfStatement *stmt)
{
	list->end->nextInList = stmt;
	list->end = stmt;
	return list;
}

Statement *createStatement(STMT_TYPE type, stmtValue val)
{
	Statement *result = (Statement *)malloc(sizeof(Statement));

	result->type = type;
	result->stmtVal = val;
	result->nextInList = NULL;

	return result;
}

VariableList *createVariableList(char* id)
{
	VariableList *result = (VariableList *)malloc(sizeof(VariableList));

	result->id = id;
	result->end = result;
	result->nextInList = NULL;

	return result;
}

VariableList *appendToVariableList(VariableList *list, char* id)
{
	VariableList *result = (VariableList *)malloc(sizeof(VariableList));

	result->id = id;
	result->nextInList = NULL;

	list->end->nextInList = result;
	list->end = result;

	return list;
}

VariableDeclaration *createVariableDeclaration(VAR_TYPE type, VariableList *varList, Range *range)
{
	VariableDeclaration *result = (VariableDeclaration *)malloc(sizeof(VariableDeclaration));

	result->type = type;
	result->varList = varList;

	result->isArray = range!=NULL;
	result->range=range;
	result->nextInList = NULL;

	return result;
}

VariableDeclarationList *createVariableDeclarationList(VariableDeclaration *varDecl)
{
	VariableDeclarationList *result = (VariableDeclarationList *)malloc(sizeof(VariableDeclarationList));

	result->begin = varDecl;
	result->end = varDecl;

	return result;
}

VariableDeclarationList *appendVariableDeclarationList(VariableDeclarationList *list, VariableDeclaration *varDecl)
{
	list->end->nextInList = varDecl;
	list->end = varDecl;

	return list;
}

DeclarationStatement *createDeclarationStatement(DEC_TYPE type, declarationStmt stmt)
{
	DeclarationStatement *result = (DeclarationStatement *)malloc(sizeof(DeclarationStatement));

	result->type = type;
	result->stmt = stmt;
	result->nextInList = NULL;

	return result;
}

DeclarationStatementList *createDeclarationStatementList(DeclarationStatement *stmt)
{
	DeclarationStatementList *result = (DeclarationStatementList *)malloc(sizeof(DeclarationStatementList));

	result->begin = stmt;
	result->end = stmt;

	return result;
}

DeclarationStatementList *appendDeclarationStatementToList(DeclarationStatementList *list, DeclarationStatement *stmt)
{
	list->end->nextInList = stmt;
	list->end = stmt;
	return list;
}

Program *createProgram(char *id, DeclarationStatementList *declarationSection, StatementList *performSection,VariableDeclarationList *globalariables, VAR_TYPE returnType)
{
	Program *result = (Program *)malloc(sizeof(Program));

	result->id = id;
	result->declarationSection = declarationSection;
	result->performSection = performSection;
	result->globalariables = globalariables;
	result->returnType = returnType;
	result->nextInList = NULL;

	return result;
}

ProgramList *createProgramList(Program *prog)
{
	ProgramList *result = (ProgramList *)malloc(sizeof(ProgramList));

	result->begin = prog;
	result->end = prog;

	return result;
}

ProgramList *appentProgramToList(ProgramList *list, Program *prog)
{
	list->end->nextInList = prog;
	list->end = prog;

	return list;
}

