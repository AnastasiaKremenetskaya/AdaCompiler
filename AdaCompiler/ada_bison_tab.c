
/*  A Bison parser, made from ada_bison.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	INTEGER	258
#define	BOOLEAN	259
#define	FLOAT	260
#define	CHARACTER	261
#define	STRING	262
#define	ARRAY	263
#define	ID	264
#define	CONST_STRING	265
#define	CONST_INTEGER	266
#define	CONST_FLOAT	267
#define	CONST_CHARACTER	268
#define	CONST_BOOL	269
#define	RANGE	270
#define	LENGTH	271
#define	NIL	272
#define	WHILE	273
#define	FOR	274
#define	IN	275
#define	OF	276
#define	LOOP	277
#define	IF	278
#define	THEN	279
#define	ELSIF	280
#define	ELSE	281
#define	FUNCTION	282
#define	PROCEDURE	283
#define	IS	284
#define	RETURN	285
#define	BEGINs	286
#define	END	287
#define	DOUBLE_DOT	288
#define	ASSIGNMENT	289
#define	OR	290
#define	AND	291
#define	NOT_EQUAL	292
#define	LESSER_EQUAL	293
#define	GREATER_EQUAL	294
#define	UMINUS	295
#define	UPLUS	296
#define	NOT	297

#line 1 "ada_bison.y"

	#include "tree_nodes.h"
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <conio.h>
	#include <malloc.h>
	
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

#line 52 "ada_bison.y"
typedef union {
	
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
} YYSTYPE;

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		209
#define	YYFLAG		-32768
#define	YYNTBASE	59

#define YYTRANSLATE(x) ((unsigned)(x) <= 297 ? yytranslate[x] : 83)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    50,    56,    58,
    57,    53,    48,    34,    49,     2,    54,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    37,    33,    44,
    42,    46,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    38,     2,    39,     2,     2,     2,     2,     2,     2,     2,
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
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    35,    36,    40,
    41,    43,    45,    47,    51,    52,    55
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     4,     8,    12,    16,    20,    23,    26,    29,    33,
    37,    41,    45,    49,    53,    57,    61,    66,    70,    75,
    77,    79,    81,    83,    85,    87,    91,    93,    95,    97,
    99,   101,   103,   105,   107,   109,   111,   113,   115,   117,
   120,   123,   127,   131,   136,   144,   154,   164,   173,   174,
   177,   182,   184,   187,   191,   194,   197,   199,   203,   207,
   216,   218,   222,   224,   228,   231,   233,   235,   238,   247,
   257,   269,   282,   293,   305,   319,   334,   336,   338,   341
};

static const short yyrhs[] = {    59,
    48,    59,     0,    59,    49,    59,     0,    59,    53,    59,
     0,    59,    54,    59,     0,    59,    50,    59,     0,    48,
    59,     0,    49,    59,     0,    55,    59,     0,    59,    44,
    59,     0,    59,    46,    59,     0,    59,    45,    59,     0,
    59,    47,    59,     0,    59,    42,    59,     0,    59,    43,
    59,     0,    59,    40,    59,     0,    59,    41,    59,     0,
     9,    58,    74,    57,     0,    58,    59,    57,     0,    59,
    38,    59,    39,     0,    11,     0,    12,     0,    10,     0,
    13,     0,    14,     0,     9,     0,     9,    56,    16,     0,
     3,     0,     5,     0,     7,     0,     6,     0,     4,     0,
    63,     0,    66,     0,    67,     0,    68,     0,    72,     0,
    73,     0,    65,     0,    61,     0,    62,    61,     0,    59,
    33,     0,    59,    35,    59,     0,     9,    56,    15,     0,
    59,    36,    59,    33,     0,    18,    59,    22,    62,    32,
    22,    33,     0,    19,     9,    20,    64,    22,    62,    32,
    22,    33,     0,    23,    59,    24,    62,    71,    69,    32,
    23,    33,     0,    23,    59,    24,    62,    69,    32,    23,
    33,     0,     0,    26,    62,     0,    25,    59,    24,    62,
     0,    70,     0,    71,    70,     0,    30,    59,    33,     0,
    30,    33,     0,    17,    33,     0,    59,     0,    74,    34,
    59,     0,    76,    37,    60,     0,    76,    37,     8,    58,
    64,    57,    21,    60,     0,     9,     0,    76,    34,     9,
     0,    75,     0,    77,    33,    75,     0,    75,    33,     0,
    80,     0,    78,     0,    79,    78,     0,    28,     9,    29,
    31,    62,    32,     9,    33,     0,    28,     9,    29,    79,
    31,    62,    32,     9,    33,     0,    28,     9,    58,    77,
    57,    29,    31,    62,    32,     9,    33,     0,    28,     9,
    58,    77,    57,    29,    79,    31,    62,    32,     9,    33,
     0,    27,     9,    30,    60,    29,    31,    62,    32,     9,
    33,     0,    27,     9,    30,    60,    29,    79,    31,    62,
    32,     9,    33,     0,    27,     9,    58,    77,    57,    30,
    60,    29,    31,    62,    32,     9,    33,     0,    27,     9,
    58,    77,    57,    30,    60,    29,    79,    31,    62,    32,
     9,    33,     0,     1,     0,    80,     0,    81,    80,     0,
    81,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   160,   161,   162,   163,   164,   166,   167,   169,   170,   171,
   172,   173,   174,   175,   177,   178,   180,   182,   184,   186,
   187,   188,   189,   190,   192,   193,   196,   197,   198,   199,
   200,   203,   204,   205,   206,   207,   208,   209,   212,   213,
   216,   219,   220,   223,   225,   228,   231,   232,   235,   236,
   239,   242,   243,   246,   247,   250,   253,   254,   257,   258,
   261,   262,   265,   266,   269,   270,   273,   274,   277,   278,
   280,   281,   283,   284,   286,   287,   289,   292,   293,   296
};

static const char * const yytname[] = {   "$","error","$undefined.","INTEGER",
"BOOLEAN","FLOAT","CHARACTER","STRING","ARRAY","ID","CONST_STRING","CONST_INTEGER",
"CONST_FLOAT","CONST_CHARACTER","CONST_BOOL","RANGE","LENGTH","NIL","WHILE",
"FOR","IN","OF","LOOP","IF","THEN","ELSIF","ELSE","FUNCTION","PROCEDURE","IS",
"RETURN","BEGINs","END","';'","','","DOUBLE_DOT","ASSIGNMENT","':'","'['","']'",
"OR","AND","'='","NOT_EQUAL","'<'","LESSER_EQUAL","'>'","GREATER_EQUAL","'+'",
"'-'","'&'","UMINUS","UPLUS","'*'","'/'","NOT","'\\''","')'","'('","expression",
"variable_type","statement","statement_list","expression_statement","range",
"assigment_statement","while_statement","for_statement","if_statement","else_statement",
"elsif_statement","elsif_statement_list","return_statement","empty_statement",
"expression_list","variable_declaration","variable_list","variable_declaration_list",
"declaration_statement","declaration_statement_list","program_block","program_list",
"program",""
};
#endif

static const short yyr1[] = {     0,
    59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
    59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
    59,    59,    59,    59,    59,    59,    60,    60,    60,    60,
    60,    61,    61,    61,    61,    61,    61,    61,    62,    62,
    63,    64,    64,    65,    66,    67,    68,    68,    69,    69,
    70,    71,    71,    72,    72,    73,    74,    74,    75,    75,
    76,    76,    77,    77,    78,    78,    79,    79,    80,    80,
    80,    80,    80,    80,    80,    80,    80,    81,    81,    82
};

static const short yyr2[] = {     0,
     3,     3,     3,     3,     3,     2,     2,     2,     3,     3,
     3,     3,     3,     3,     3,     3,     4,     3,     4,     1,
     1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
     2,     3,     3,     4,     7,     9,     9,     8,     0,     2,
     4,     1,     2,     3,     2,     2,     1,     3,     3,     8,
     1,     3,     1,     3,     2,     1,     1,     2,     8,     9,
    11,    12,    10,    11,    13,    14,     1,     1,     2,     1
};

static const short yydefact[] = {     0,
    77,     0,     0,    78,     0,     0,     0,    79,     0,     0,
     0,     0,    27,    31,    28,    30,    29,     0,    61,    63,
     0,     0,     0,     0,    67,     0,    66,     0,     0,     0,
     0,     0,     0,    25,    22,    20,    21,    23,    24,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
     0,    32,    38,    33,    34,    35,    36,    37,    65,     0,
    68,     0,     0,     0,    62,     0,    59,    64,     0,     0,
     0,    56,     0,     0,     0,    55,     0,     6,     7,     8,
     0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    40,     0,
     0,     0,     0,     0,     0,    26,    57,     0,     0,     0,
     0,    54,    18,     0,     0,    15,    16,    13,    14,     9,
    11,    10,    12,     1,     2,     5,     3,     4,     0,     0,
     0,     0,     0,     0,    25,     0,     0,     0,     0,    17,
     0,     0,    49,    44,    19,    69,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    58,     0,     0,     0,
     0,     0,    52,    49,    70,     0,     0,    73,     0,    43,
    42,     0,     0,     0,     0,     0,     0,    50,     0,     0,
    53,     0,     0,    74,    60,     0,     0,    45,     0,     0,
     0,     0,    71,     0,     0,     0,     0,    51,    48,     0,
    72,    75,     0,    46,    47,    76,     0,     0,     0
};

static const short yydefgoto[] = {    49,
    18,    50,    51,    52,   137,    53,    54,    55,    56,   162,
   163,   164,    57,    58,   108,    24,    21,    22,    25,    26,
    27,     5,   207
};

static const short yypact[] = {    49,
-32768,    18,    35,-32768,   112,   -13,   -15,-32768,   195,    47,
    73,    47,-32768,-32768,-32768,-32768,-32768,    55,-32768,-32768,
   -22,    -9,   422,    56,-32768,    79,-32768,    24,    93,    82,
   505,    47,    65,   -47,-32768,-32768,-32768,-32768,-32768,    76,
   473,    89,   473,   448,   473,   473,   473,   473,   550,-32768,
   161,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   422,
-32768,    88,   422,   110,-32768,    68,-32768,-32768,   195,   107,
   473,-32768,   -12,   113,   500,-32768,   568,    91,    91,   108,
   603,-32768,   473,   473,   473,   473,   473,   473,   473,   473,
   473,   473,   473,   473,   473,   473,   473,   134,-32768,   194,
   154,   218,   422,   481,   125,-32768,   657,    39,   422,   481,
   422,-32768,-32768,   586,   640,   670,   670,   425,   425,   425,
   425,   425,   425,    91,    91,    91,   108,   108,   126,   151,
   422,   441,   152,   245,    -4,   623,   109,   506,   473,-32768,
   269,   145,   139,-32768,-32768,-32768,   135,   296,   422,   143,
   168,    71,   473,   162,   422,   551,   657,   164,   422,   473,
   422,   157,-32768,   105,-32768,   181,   320,-32768,   159,-32768,
   657,   195,   347,   422,   163,   371,   527,   422,   172,   182,
-32768,   185,   206,-32768,-32768,   211,   398,-32768,   199,   422,
   189,   200,-32768,   192,   201,   224,   205,   422,-32768,   207,
-32768,-32768,   212,-32768,-32768,-32768,   239,   244,-32768
};

static const short yypgoto[] = {   -25,
   -30,   -51,   -56,-32768,   136,-32768,-32768,-32768,-32768,    83,
    87,-32768,-32768,-32768,-32768,    -7,-32768,   241,   -24,   -23,
     8,-32768,-32768
};


#define	YYLAST		724


static const short yytable[] = {    99,
    67,    61,    20,   100,    20,    64,   102,     4,    70,   109,
    71,    30,     8,    11,    31,    73,     9,    75,    77,    78,
    79,    80,    81,    32,    68,    84,     6,    85,    86,    87,
    88,    89,    90,    91,    92,    93,    94,    95,   105,    61,
    96,    97,    12,     7,    10,   107,   134,    33,    99,     1,
    99,   152,   141,    71,   143,    19,    32,   114,   115,   116,
   117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
   127,   128,   139,     1,   148,     2,     3,   132,   136,     1,
    62,    19,    99,    29,   136,   170,   106,    19,    59,    99,
    65,    99,   167,     1,    69,   140,    99,    74,   173,     2,
     3,    19,   176,    23,   178,     2,     3,    61,    72,    60,
     1,   -80,     1,   157,   156,    99,   101,   187,    19,     2,
     3,    99,   106,    63,    99,   104,    99,   171,    84,   160,
   161,    61,   110,   198,   177,    99,     2,     3,     2,     3,
   103,   185,   129,    96,    97,    84,    99,    34,    35,    36,
    37,    38,    39,   138,     1,    40,    41,    42,   146,   147,
   150,    43,    19,   160,   161,   154,   159,   165,    44,    34,
    35,    36,    37,    38,    39,   168,   169,    40,    41,    42,
     2,     3,   172,    43,   131,   175,    45,    46,   179,   182,
    44,   184,    98,    47,   191,   188,    48,    13,    14,    15,
    16,    17,    34,    35,    36,    37,    38,    39,    45,    46,
    40,    41,    42,   192,   194,    47,    43,   193,    48,   195,
   197,   199,   200,    44,   201,   130,    34,    35,    36,    37,
    38,    39,   203,   202,    40,    41,    42,   204,   208,   205,
    43,    45,    46,   209,   206,   142,   180,    44,    47,   133,
   181,    48,    28,    34,    35,    36,    37,    38,    39,     0,
     0,    40,    41,    42,     0,    45,    46,    43,     0,     0,
     0,     0,    47,     0,    44,    48,   151,    34,    35,    36,
    37,    38,    39,     0,     0,    40,    41,    42,     0,     0,
     0,    43,    45,    46,     0,     0,     0,     0,    44,    47,
   158,     0,    48,     0,    34,    35,    36,    37,    38,    39,
     0,     0,    40,    41,    42,     0,    45,    46,    43,     0,
     0,     0,     0,    47,     0,    44,    48,   166,    34,    35,
    36,    37,    38,    39,     0,     0,    40,    41,    42,     0,
     0,     0,    43,    45,    46,     0,     0,     0,     0,    44,
    47,   183,     0,    48,     0,    34,    35,    36,    37,    38,
    39,     0,     0,    40,    41,    42,     0,    45,    46,    43,
     0,     0,     0,     0,    47,     0,    44,    48,   186,    34,
    35,    36,    37,    38,    39,     0,     0,    40,    41,    42,
     0,     0,     0,    43,    45,    46,     0,     0,     0,     0,
    44,    47,   189,     0,    48,     0,    34,    35,    36,    37,
    38,    39,     0,     0,    40,    41,    42,     0,    45,    46,
    43,     0,     0,     0,     0,    47,     0,    44,    48,   196,
    34,    35,    36,    37,    38,    39,     0,     0,    40,    41,
    42,     1,     0,     0,    43,    45,    46,     0,     0,    19,
     0,    44,    47,     0,     0,    48,    34,    35,    36,    37,
    38,    39,    84,     0,     0,     0,     0,     2,     3,    45,
    46,   149,    93,    94,    95,     0,    47,    96,    97,    48,
    76,    34,    35,    36,    37,    38,    39,     0,     0,   135,
    35,    36,    37,    38,    39,    45,    46,     0,     0,     0,
     0,     0,    47,     0,     0,    48,     1,    13,    14,    15,
    16,    17,    66,     0,    19,     0,     0,     0,     0,     0,
    45,    46,     0,   111,     0,     0,     0,    47,    45,    46,
    48,     0,     2,     3,     0,    47,   155,    84,    48,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
   190,     1,    96,    97,     0,     0,     0,     0,     0,    19,
     0,     0,     0,     0,    84,     0,    85,    86,    87,    88,
    89,    90,    91,    92,    93,    94,    95,     2,     3,    96,
    97,   174,    82,     0,     0,    83,     0,    84,     0,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
   112,     0,    96,    97,     0,    84,     0,    85,    86,    87,
    88,    89,    90,    91,    92,    93,    94,    95,   144,     0,
    96,    97,     0,    84,     0,    85,    86,    87,    88,    89,
    90,    91,    92,    93,    94,    95,     0,     0,    96,    97,
    84,     0,    85,    86,    87,    88,    89,    90,    91,    92,
    93,    94,    95,     0,     0,    96,    97,   153,     0,   113,
    84,     0,    85,    86,    87,    88,    89,    90,    91,    92,
    93,    94,    95,     0,     0,    96,    97,    84,   145,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
     0,     0,    96,    97,    84,     0,    85,    86,    87,    88,
    89,    90,    91,    92,    93,    94,    95,    84,     0,    96,
    97,    87,    88,    89,    90,    91,    92,    93,    94,    95,
     0,     0,    96,    97
};

static const short yycheck[] = {    51,
    31,    26,    10,    60,    12,    29,    63,     0,    56,    22,
    58,    34,     5,    29,    37,    41,    30,    43,    44,    45,
    46,    47,    48,    33,    32,    38,     9,    40,    41,    42,
    43,    44,    45,    46,    47,    48,    49,    50,    69,    64,
    53,    54,    58,     9,    58,    71,   103,    57,   100,     1,
   102,    56,   109,    58,   111,     9,    33,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    34,     1,   131,    27,    28,   101,   104,     1,
    57,     9,   134,    29,   110,    15,    16,     9,    33,   141,
     9,   143,   149,     1,    30,    57,   148,     9,   155,    27,
    28,     9,   159,    31,   161,    27,    28,   132,    33,    31,
     1,     0,     1,   139,   138,   167,    29,   174,     9,    27,
    28,   173,    16,    31,   176,    58,   178,   153,    38,    25,
    26,   156,    20,   190,   160,   187,    27,    28,    27,    28,
    31,   172,     9,    53,    54,    38,   198,     9,    10,    11,
    12,    13,    14,    29,     1,    17,    18,    19,    33,     9,
     9,    23,     9,    25,    26,    57,    22,    33,    30,     9,
    10,    11,    12,    13,    14,    33,     9,    17,    18,    19,
    27,    28,    21,    23,    31,    22,    48,    49,    32,     9,
    30,    33,    32,    55,    23,    33,    58,     3,     4,     5,
     6,     7,     9,    10,    11,    12,    13,    14,    48,    49,
    17,    18,    19,    32,     9,    55,    23,    33,    58,     9,
    22,    33,    23,    30,    33,    32,     9,    10,    11,    12,
    13,    14,     9,    33,    17,    18,    19,    33,     0,    33,
    23,    48,    49,     0,    33,   110,   164,    30,    55,    32,
   164,    58,    12,     9,    10,    11,    12,    13,    14,    -1,
    -1,    17,    18,    19,    -1,    48,    49,    23,    -1,    -1,
    -1,    -1,    55,    -1,    30,    58,    32,     9,    10,    11,
    12,    13,    14,    -1,    -1,    17,    18,    19,    -1,    -1,
    -1,    23,    48,    49,    -1,    -1,    -1,    -1,    30,    55,
    32,    -1,    58,    -1,     9,    10,    11,    12,    13,    14,
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
    19,     1,    -1,    -1,    23,    48,    49,    -1,    -1,     9,
    -1,    30,    55,    -1,    -1,    58,     9,    10,    11,    12,
    13,    14,    38,    -1,    -1,    -1,    -1,    27,    28,    48,
    49,    31,    48,    49,    50,    -1,    55,    53,    54,    58,
    33,     9,    10,    11,    12,    13,    14,    -1,    -1,     9,
    10,    11,    12,    13,    14,    48,    49,    -1,    -1,    -1,
    -1,    -1,    55,    -1,    -1,    58,     1,     3,     4,     5,
     6,     7,     8,    -1,     9,    -1,    -1,    -1,    -1,    -1,
    48,    49,    -1,    24,    -1,    -1,    -1,    55,    48,    49,
    58,    -1,    27,    28,    -1,    55,    31,    38,    58,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    24,     1,    53,    54,    -1,    -1,    -1,    -1,    -1,     9,
    -1,    -1,    -1,    -1,    38,    -1,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    27,    28,    53,
    54,    31,    33,    -1,    -1,    36,    -1,    38,    -1,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    33,    -1,    53,    54,    -1,    38,    -1,    40,    41,    42,
    43,    44,    45,    46,    47,    48,    49,    50,    33,    -1,
    53,    54,    -1,    38,    -1,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    -1,    -1,    53,    54,
    38,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
    48,    49,    50,    -1,    -1,    53,    54,    35,    -1,    57,
    38,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
    48,    49,    50,    -1,    -1,    53,    54,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    -1,    -1,    53,    54,    38,    -1,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    38,    -1,    53,
    54,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    -1,    -1,    53,    54
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

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
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 160 "ada_bison.y"
{yyval.expr = createExpression(ET_PLUS, yyvsp[-2].expr, yyvsp[0].expr);;
    break;}
case 2:
#line 161 "ada_bison.y"
{yyval.expr = createExpression(ET_MINUS, yyvsp[-2].expr, yyvsp[0].expr);;
    break;}
case 3:
#line 162 "ada_bison.y"
{yyval.expr = createExpression(ET_MULT, yyvsp[-2].expr, yyvsp[0].expr);;
    break;}
case 4:
#line 163 "ada_bison.y"
{yyval.expr = createExpression(ET_DIV, yyvsp[-2].expr, yyvsp[0].expr);;
    break;}
case 5:
#line 164 "ada_bison.y"
{yyval.expr = createExpression(ET_CONCAT, yyvsp[-2].expr, yyvsp[0].expr);;
    break;}
case 6:
#line 166 "ada_bison.y"
{yyval.expr = createExpression(ET_PLUS, NULL, yyvsp[0].expr);;
    break;}
case 7:
#line 167 "ada_bison.y"
{yyval.expr = createExpression(ET_MINUS, NULL, yyvsp[0].expr);;
    break;}
case 8:
#line 169 "ada_bison.y"
{yyval.expr = createExpression(ET_NOT, NULL, yyvsp[0].expr);;
    break;}
case 9:
#line 170 "ada_bison.y"
{yyval.expr = createExpression(ET_LESSER, yyvsp[-2].expr, yyvsp[0].expr);;
    break;}
case 10:
#line 171 "ada_bison.y"
{yyval.expr = createExpression(ET_GREATER, yyvsp[-2].expr, yyvsp[0].expr);;
    break;}
case 11:
#line 172 "ada_bison.y"
{yyval.expr = createExpression(ET_LESSER_EQUAL, yyvsp[-2].expr, yyvsp[0].expr);;
    break;}
case 12:
#line 173 "ada_bison.y"
{yyval.expr = createExpression(ET_GREATER_EQUAL, yyvsp[-2].expr, yyvsp[0].expr);;
    break;}
case 13:
#line 174 "ada_bison.y"
{yyval.expr = createExpression(ET_EQUAL, yyvsp[-2].expr, yyvsp[0].expr);;
    break;}
case 14:
#line 175 "ada_bison.y"
{yyval.expr = createExpression(ET_NOT_EQUAL, yyvsp[-2].expr, yyvsp[0].expr);;
    break;}
case 15:
#line 177 "ada_bison.y"
{yyval.expr = createExpression(ET_LOGIC_OR, yyvsp[-2].expr, yyvsp[0].expr);;
    break;}
case 16:
#line 178 "ada_bison.y"
{yyval.expr = createExpression(ET_LOGIC_AND, yyvsp[-2].expr, yyvsp[0].expr);;
    break;}
case 17:
#line 180 "ada_bison.y"
{yyval.expr = createExpressionWithList(ET_ARRAY_OR_FUNC, (value){.string_val=yyvsp[-3].id_const}, yyvsp[-1].exprList);;
    break;}
case 18:
#line 182 "ada_bison.y"
{yyval.expr = yyvsp[-1].expr;;
    break;}
case 19:
#line 184 "ada_bison.y"
{yyval.expr = createExpression(ET_INDEXER, yyvsp[-3].expr, yyvsp[-1].expr);;
    break;}
case 20:
#line 186 "ada_bison.y"
{yyval.expr = createSimpleExpression(ET_INTEGER, (value){.int_val = yyvsp[0].int_const});;
    break;}
case 21:
#line 187 "ada_bison.y"
{yyval.expr = createSimpleExpression(ET_FLOAT, (value){.float_val=yyvsp[0].float_const});;
    break;}
case 22:
#line 188 "ada_bison.y"
{yyval.expr = createSimpleExpression(ET_STRING, (value){.string_val=yyvsp[0].string_const});;
    break;}
case 23:
#line 189 "ada_bison.y"
{yyval.expr = createSimpleExpression(ET_CHARACTER, (value){.char_val=yyvsp[0].char_const});;
    break;}
case 24:
#line 190 "ada_bison.y"
{yyval.expr = createSimpleExpression(ET_BOOL, (value){.int_val=yyvsp[0].int_const});;
    break;}
case 25:
#line 192 "ada_bison.y"
{yyval.expr = createSimpleExpression(ET_ID, (value){.string_val=yyvsp[0].id_const});;
    break;}
case 26:
#line 193 "ada_bison.y"
{yyval.expr = createSimpleExpression(ET_LENGTH_ARR_ATTR, (value){.string_val=yyvsp[-2].id_const});;
    break;}
case 27:
#line 196 "ada_bison.y"
{yyval.vt = VT_INTEGER;;
    break;}
case 28:
#line 197 "ada_bison.y"
{yyval.vt = VT_FLOAT;;
    break;}
case 29:
#line 198 "ada_bison.y"
{yyval.vt = VT_STRING;;
    break;}
case 30:
#line 199 "ada_bison.y"
{yyval.vt = VT_CHARACTER;;
    break;}
case 31:
#line 200 "ada_bison.y"
{yyval.vt = VT_BOOLEAN;;
    break;}
case 32:
#line 203 "ada_bison.y"
{yyval.stmt = yyvsp[0].stmt;;
    break;}
case 33:
#line 204 "ada_bison.y"
{yyval.stmt = createStatement(ST_WHILE, (stmtValue){.whileStmt=yyvsp[0].whileStmt});;
    break;}
case 34:
#line 205 "ada_bison.y"
{yyval.stmt = createStatement(ST_FOR, (stmtValue){.forStmt=yyvsp[0].forStmt});;
    break;}
case 35:
#line 206 "ada_bison.y"
{yyval.stmt = createStatement(ST_IF, (stmtValue){.ifStmt=yyvsp[0].ifStmt});;
    break;}
case 36:
#line 207 "ada_bison.y"
{yyval.stmt = yyvsp[0].stmt;;
    break;}
case 37:
#line 208 "ada_bison.y"
{yyval.stmt = yyvsp[0].stmt;;
    break;}
case 38:
#line 209 "ada_bison.y"
{yyval.stmt = createStatement(ST_ASSIGN, (stmtValue){.assigStmt=yyvsp[0].assigStmt});;
    break;}
case 39:
#line 212 "ada_bison.y"
{yyval.stmtList = createStatementList(yyvsp[0].stmt);;
    break;}
case 40:
#line 213 "ada_bison.y"
{yyval.stmtList = appendStatementToList(yyvsp[-1].stmtList,yyvsp[0].stmt);;
    break;}
case 41:
#line 216 "ada_bison.y"
{yyval.stmt = createStatement(ST_EXPRESSION, (stmtValue){.exprStmt=yyvsp[-1].expr});;
    break;}
case 42:
#line 219 "ada_bison.y"
{yyval.rangeStmt = createRange(yyvsp[-2].expr, yyvsp[0].expr, NULL);;
    break;}
case 43:
#line 220 "ada_bison.y"
{yyval.rangeStmt = createRange(NULL, NULL, yyvsp[-2].id_const);;
    break;}
case 44:
#line 223 "ada_bison.y"
{yyval.assigStmt = createAssigmentStmt(yyvsp[-3].expr, yyvsp[-1].expr);;
    break;}
case 45:
#line 225 "ada_bison.y"
{yyval.whileStmt = createWhile(yyvsp[-5].expr, yyvsp[-3].stmtList);;
    break;}
case 46:
#line 228 "ada_bison.y"
{yyval.forStmt = createFor(yyvsp[-7].id_const,yyvsp[-5].rangeStmt,yyvsp[-3].stmtList);;
    break;}
case 47:
#line 231 "ada_bison.y"
{yyval.ifStmt = createIf(yyvsp[-7].expr, yyvsp[-5].stmtList, yyvsp[-4].elseIfStmtList, yyvsp[-3].elseStmt);;
    break;}
case 48:
#line 232 "ada_bison.y"
{yyval.ifStmt = createIf(yyvsp[-6].expr, yyvsp[-4].stmtList, NULL, yyvsp[-3].elseStmt);;
    break;}
case 49:
#line 235 "ada_bison.y"
{yyval.elseStmt = NULL;;
    break;}
case 50:
#line 236 "ada_bison.y"
{yyval.elseStmt = createElse(yyvsp[0].stmtList);;
    break;}
case 51:
#line 239 "ada_bison.y"
{yyval.elseIfStmt = createElseIf(yyvsp[-2].expr, yyvsp[0].stmtList);;
    break;}
case 52:
#line 242 "ada_bison.y"
{yyval.elseIfStmtList = createElseIfStatementList(yyvsp[0].elseIfStmt);;
    break;}
case 53:
#line 243 "ada_bison.y"
{yyval.elseIfStmtList = appendElseIfToList(yyvsp[-1].elseIfStmtList, yyvsp[0].elseIfStmt);;
    break;}
case 54:
#line 246 "ada_bison.y"
{yyval.stmt = createStatement(ST_RETURN, (stmtValue){.exprStmt=yyvsp[-1].expr});;
    break;}
case 55:
#line 247 "ada_bison.y"
{yyval.stmt = createStatement(ST_RETURN, (stmtValue){});;
    break;}
case 56:
#line 250 "ada_bison.y"
{yyval.stmt = createStatement(ST_NULL, (stmtValue){});;
    break;}
case 57:
#line 253 "ada_bison.y"
{yyval.exprList = createExpressionList(yyvsp[0].expr);;
    break;}
case 58:
#line 254 "ada_bison.y"
{yyval.exprList = appendExpressionToList(yyvsp[-2].exprList,yyvsp[0].expr);;
    break;}
case 59:
#line 257 "ada_bison.y"
{yyval.varDecl = createVariableDeclaration(yyvsp[0].vt,yyvsp[-2].varList,NULL);;
    break;}
case 60:
#line 258 "ada_bison.y"
{yyval.varDecl = createVariableDeclaration(yyvsp[0].vt,yyvsp[-7].varList,yyvsp[-3].rangeStmt);;
    break;}
case 61:
#line 261 "ada_bison.y"
{yyval.varList = createVariableList(yyvsp[0].id_const);;
    break;}
case 62:
#line 262 "ada_bison.y"
{yyval.varList = appendToVariableList(yyvsp[-2].varList, yyvsp[0].id_const);;
    break;}
case 63:
#line 265 "ada_bison.y"
{yyval.varDeclList = createVariableDeclarationList(yyvsp[0].varDecl);;
    break;}
case 64:
#line 266 "ada_bison.y"
{yyval.varDeclList = appendVariableDeclarationList(yyvsp[-2].varDeclList,yyvsp[0].varDecl);;
    break;}
case 65:
#line 269 "ada_bison.y"
{yyval.declStmt = createDeclarationStatement(DT_VARIABLE, (declarationStmt){.varDecl=yyvsp[-1].varDecl});;
    break;}
case 66:
#line 270 "ada_bison.y"
{yyval.declStmt = createDeclarationStatement(DT_FUNCTION, (declarationStmt){.prog=yyvsp[0].prog});;
    break;}
case 67:
#line 273 "ada_bison.y"
{yyval.declStmtList = createDeclarationStatementList(yyvsp[0].declStmt);;
    break;}
case 68:
#line 274 "ada_bison.y"
{yyval.declStmtList = appendDeclarationStatementToList(yyvsp[-1].declStmtList, yyvsp[0].declStmt);;
    break;}
case 69:
#line 277 "ada_bison.y"
{yyval.prog = createProgram(yyvsp[-6].id_const,NULL,yyvsp[-3].stmtList,NULL,VT_VOID);;
    break;}
case 70:
#line 278 "ada_bison.y"
{yyval.prog = createProgram(yyvsp[-7].id_const,yyvsp[-5].declStmtList,yyvsp[-3].stmtList,NULL,VT_VOID);;
    break;}
case 71:
#line 280 "ada_bison.y"
{yyval.prog = createProgram(yyvsp[-9].id_const,NULL,yyvsp[-3].stmtList,yyvsp[-7].varDeclList,VT_VOID);;
    break;}
case 72:
#line 281 "ada_bison.y"
{yyval.prog = createProgram(yyvsp[-10].id_const,yyvsp[-5].declStmtList,yyvsp[-3].stmtList,yyvsp[-8].varDeclList,VT_VOID);;
    break;}
case 73:
#line 283 "ada_bison.y"
{yyval.prog = createProgram(yyvsp[-8].id_const,NULL,yyvsp[-3].stmtList,NULL,yyvsp[-6].vt);;
    break;}
case 74:
#line 284 "ada_bison.y"
{yyval.prog = createProgram(yyvsp[-9].id_const,yyvsp[-5].declStmtList,yyvsp[-3].stmtList,NULL,yyvsp[-7].vt);;
    break;}
case 75:
#line 286 "ada_bison.y"
{yyval.prog = createProgram(yyvsp[-11].id_const,NULL,yyvsp[-3].stmtList,yyvsp[-9].varDeclList,yyvsp[-6].vt);;
    break;}
case 76:
#line 287 "ada_bison.y"
{yyval.prog = createProgram(yyvsp[-12].id_const,yyvsp[-5].declStmtList,yyvsp[-3].stmtList,yyvsp[-10].varDeclList,yyvsp[-7].vt);;
    break;}
case 77:
#line 289 "ada_bison.y"
{yyval.prog = NULL;;
    break;}
case 78:
#line 292 "ada_bison.y"
{ yyval.progList = createProgramList(yyvsp[0].prog); ;
    break;}
case 79:
#line 293 "ada_bison.y"
{ yyval.progList = appentProgramToList(yyvsp[-1].progList,yyvsp[0].prog); ;
    break;}
case 80:
#line 296 "ada_bison.y"
{yyval.progList = root = yyvsp[0].progList;;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 299 "ada_bison.y"


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