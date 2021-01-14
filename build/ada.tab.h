/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 163 "ada.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

