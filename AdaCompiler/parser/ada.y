%{
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
%}

%union {
	
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

%type <expr> expression
%type <stmt> empty_statement return_statement expression_statement
%type <exprList> expression_list
%type <varList> variable_list
%type <rangeStmt> range
%type <assigStmt> assigment_statement
%type <elseIfStmt> elsif_statement
%type <elseStmt> else_statement
%type <ifStmt> if_statement
%type <elseIfStmtList> elsif_statement_list
%type <forStmt> for_statement
%type <whileStmt> while_statement
%type <stmtList> statement_list
%type <stmt> statement
%type <vt> variable_type
%type <varDecl> variable_declaration
%type <varDeclList> variable_declaration_list
%type <declStmt> declaration_statement
%type <declStmtList> declaration_statement_list
%type <prog> program_block
%type <progList> program_list
%type <progList> program

%token INTEGER BOOLEAN FLOAT CHARACTER STRING
%token ARRAY

%token <id_const> ID
%token <string_const> CONST_STRING
%token <int_const> CONST_INTEGER
%token <float_const> CONST_FLOAT
%token <char_const> CONST_CHARACTER
%token <int_const> CONST_BOOL

%token RANGE
%token LENGTH

%token NIL

%token WHILE
%token FOR
%token IN
%token OF
%token LOOP

%token IF
%token THEN
%token ELSIF
%token ELSE

%token FUNCTION
%token PROCEDURE
%token IS
%token RETURN
%token BEGINs END


%token ';' 
%token ','
%token DOUBLE_DOT
%token ASSIGNMENT
%token  ':'
%token '['
%token ']'

%left OR AND
%left '=' NOT_EQUAL '<' LESSER_EQUAL '>' GREATER_EQUAL
%left '+' '-' '&'
%right UMINUS UPLUS
%left '*' '/'
%right NOT
%left '\''
%left '[' ']'
%nonassoc ')'

%start program

%%

expression : expression '+' expression	{$$ = createExpression(ET_PLUS, $1, $3);}
			|	expression '-' expression	{$$ = createExpression(ET_MINUS, $1, $3);}
			|	expression '*' expression	{$$ = createExpression(ET_MULT, $1, $3);}
			|	expression '/' expression	{$$ = createExpression(ET_DIV, $1, $3);}
			|	expression '&' expression	{$$ = createExpression(ET_CONCAT, $1, $3);}
			
			|	'+' expression %prec UPLUS	{$$ = createExpression(ET_PLUS, NULL, $2);}
			|	'-' expression %prec UMINUS	{$$ = createExpression(ET_MINUS, NULL, $2);}
			
			|	NOT expression						{$$ = createExpression(ET_NOT, NULL, $2);}
			|	expression '<' expression			{$$ = createExpression(ET_LESSER, $1, $3);}
			|	expression '>' expression			{$$ = createExpression(ET_GREATER, $1, $3);}
			|	expression LESSER_EQUAL expression	{$$ = createExpression(ET_LESSER_EQUAL, $1, $3);}
			|	expression GREATER_EQUAL expression	{$$ = createExpression(ET_GREATER_EQUAL, $1, $3);}
			|	expression '=' expression			{$$ = createExpression(ET_EQUAL, $1, $3);}
			|	expression NOT_EQUAL expression		{$$ = createExpression(ET_NOT_EQUAL, $1, $3);}
			
			|	expression OR expression	{$$ = createExpression(ET_LOGIC_OR, $1, $3);}
			|	expression AND expression	{$$ = createExpression(ET_LOGIC_AND, $1, $3);}
			
			|	ID '(' expression_list ')'	{$$ = createExpressionWithList(ET_ARRAY_OR_FUNC, (value){.string_val=$1}, $3);}
			
			|	'(' expression ')'	{$$ = $2;}
			
			|	expression '[' expression ']'	{$$ = createExpression(ET_INDEXER, $1, $3);}
			
			|	CONST_INTEGER	{$$ = createSimpleExpression(ET_INTEGER, (value){.int_val = $1});}
			|	CONST_FLOAT		{$$ = createSimpleExpression(ET_FLOAT, (value){.float_val=$1});}
			|	CONST_STRING	{$$ = createSimpleExpression(ET_STRING, (value){.string_val=$1});}
			|	CONST_CHARACTER	{$$ = createSimpleExpression(ET_CHARACTER, (value){.char_val=$1});}
			|	CONST_BOOL		{$$ = createSimpleExpression(ET_BOOL, (value){.int_val=$1});}
			
			|	ID				{$$ = createSimpleExpression(ET_ID, (value){.string_val=$1});}
			|	ID '\'' LENGTH	{$$ = createSimpleExpression(ET_LENGTH_ARR_ATTR, (value){.string_val=$1});}
			;	

variable_type : INTEGER	{$$ = VT_INTEGER;}
				| FLOAT		{$$ = VT_FLOAT;}
				| STRING	{$$ = VT_STRING;}
				| CHARACTER	{$$ = VT_CHARACTER;}
				| BOOLEAN	{$$ = VT_BOOLEAN;}
				;

statement : expression_statement	{$$ = $1;}
		  | while_statement			{$$ = createStatement(ST_WHILE, (stmtValue){.whileStmt=$1});}
		  | for_statement			{$$ = createStatement(ST_FOR, (stmtValue){.forStmt=$1});}
		  | if_statement			{$$ = createStatement(ST_IF, (stmtValue){.ifStmt=$1});}
		  | return_statement		{$$ = $1;}
		  | empty_statement			{$$ = $1;}
		  | assigment_statement		{$$ = createStatement(ST_ASSIGN, (stmtValue){.assigStmt=$1});}
		  ;
		
statement_list : statement					{$$ = createStatementList($1);}
				| statement_list statement	{$$ = appendStatementToList($1,$2);}
				;
				
expression_statement : expression ';'	{$$ = createStatement(ST_EXPRESSION, (stmtValue){.exprStmt=$1});}
					;
					
range : expression DOUBLE_DOT expression	{$$ = createRange($1, $3, NULL);}
				|	ID '\'' RANGE			{$$ = createRange(NULL, NULL, $1);}
				;
				
assigment_statement : expression ASSIGNMENT expression ';'	{$$ = createAssigmentStmt($1, $3);}
					
while_statement : WHILE expression LOOP statement_list END LOOP ';'	{$$ = createWhile($2, $4);}
				;

for_statement : FOR ID IN range LOOP statement_list END LOOP ';'	{$$ = createFor($2,$4,$6);}
				;
			
if_statement : IF expression THEN statement_list elsif_statement_list else_statement END IF ';'	{$$ = createIf($2, $4, $5, $6);}
			 | IF expression THEN statement_list else_statement END IF ';'	{$$ = createIf($2, $4, NULL, $5);}
				;
		
else_statement : 	/* empty */ 		{$$ = NULL;}
				| ELSE statement_list	{$$ = createElse($2);}
				;
				
elsif_statement : ELSIF expression THEN statement_list	{$$ = createElseIf($2, $4);}
				;
				
elsif_statement_list : elsif_statement					{$$ = createElseIfStatementList($1);}
				| elsif_statement_list elsif_statement	{$$ = appendElseIfToList($1, $2);}
				;
				
return_statement : RETURN expression ';'	{$$ = createStatement(ST_RETURN, (stmtValue){.exprStmt=$2});}
				| RETURN ';'				{$$ = createStatement(ST_RETURN, (stmtValue){});}
				;
		
empty_statement : NIL ';'	{$$ = createStatement(ST_NULL, (stmtValue){});}
				;
				
expression_list : expression		{$$ = createExpressionList($1);}
				| expression_list ',' expression {$$ = appendExpressionToList($1,$3);}
				;

variable_declaration : variable_list ':' variable_type	{$$ = createVariableDeclaration($3,$1,NULL);}
					| variable_list ':' ARRAY '(' range ')' OF variable_type	{$$ = createVariableDeclaration($8,$1,$5);}
					;
					
variable_list : ID {$$ = createVariableList($1);}
			| variable_list ',' ID {$$ = appendToVariableList($1, $3);}
			;

variable_declaration_list: variable_declaration	{$$ = createVariableDeclarationList($1);}
						| variable_declaration_list ';' variable_declaration {$$ = appendVariableDeclarationList($1,$3);}
						;
					
declaration_statement:	variable_declaration ';' {$$ = createDeclarationStatement(DT_VARIABLE, (declarationStmt){.varDecl=$1});}
					|	program_block {$$ = createDeclarationStatement(DT_FUNCTION, (declarationStmt){.prog=$1});}
					;
					
declaration_statement_list:	declaration_statement {$$ = createDeclarationStatementList($1);}
						|	declaration_statement_list declaration_statement {$$ = appendDeclarationStatementToList($1, $2);}
						;

program_block : PROCEDURE ID IS BEGINs statement_list END ID ';' {$$ = createProgram($2,NULL,$5,NULL,VT_VOID);}
				| PROCEDURE ID IS declaration_statement_list BEGINs statement_list END ID ';' {$$ = createProgram($2,$4,$6,NULL,VT_VOID);}
				
				| PROCEDURE ID '(' variable_declaration_list ')' IS BEGINs statement_list END ID ';' {$$ = createProgram($2,NULL,$8,$4,VT_VOID);}
				| PROCEDURE ID '(' variable_declaration_list ')' IS declaration_statement_list BEGINs statement_list END ID ';' {$$ = createProgram($2,$7,$9,$4,VT_VOID);}
				
				| FUNCTION ID RETURN variable_type IS BEGINs statement_list END ID ';' {$$ = createProgram($2,NULL,$7,NULL,$4);}
				| FUNCTION ID RETURN variable_type IS declaration_statement_list BEGINs statement_list END ID ';' {$$ = createProgram($2,$6,$8,NULL,$4);}
				
				| FUNCTION ID '(' variable_declaration_list ')' RETURN variable_type IS BEGINs statement_list END ID ';' {$$ = createProgram($2,NULL,$10,$4,$7);}
				| FUNCTION ID '(' variable_declaration_list ')' RETURN variable_type IS declaration_statement_list BEGINs statement_list END ID ';' {$$ = createProgram($2,$9,$11,$4,$7);}
				
				| error {$$ = NULL;}
				;
				
program_list : program_block				{ $$ = createProgramList($1); }
			 | program_list program_block	{ $$ = appentProgramToList($1,$2); }
			 ;
			 
program : program_list	{$$ = root = $1;}
		;
		
%%

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