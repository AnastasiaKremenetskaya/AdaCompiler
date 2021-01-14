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


extern YYSTYPE yylval;
