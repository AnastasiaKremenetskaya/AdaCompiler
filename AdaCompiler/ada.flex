%{
    #include "tree_nodes.h"
    #include "ada_bison_tab.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <conio.h>
    #include <malloc.h>
    
    extern ProgramList *root;
    extern int yyparse(void);
%}

%option noyywrap
%option never-interactive
%option yylineno
%option case-insensitive

ID              [a-z]+([_]?[a-z0-9]+)*
LINE_COMMENT    "--".* 

CHARACTER       \'.\'
STRING          \"([^"\n]|["]{2})*\"
INTEGER         [0-9]+
FLOAT           [0-9]*\.{INTEGER}
EXPONENT        {FLOAT}e[+-]?{INTEGER}

%%

%{
    int s = 0;
    char symbol[2];
    char buf[100000];
    memset(buf, '\0', 100000);
%}

integer         { yylval.vt = VT_INTEGER; return INTEGER;}
boolean         { yylval.vt = VT_BOOLEAN; return BOOLEAN;}
float           { yylval.vt = VT_FLOAT; return FLOAT;}
character       { yylval.vt = VT_CHARACTER; return CHARACTER;}
string          { yylval.vt = VT_STRING; return STRING;}
array               {return ARRAY;}

procedure           {return PROCEDURE;}
function            {return FUNCTION;}
begin               {return BEGINs;}
end                 {return END;}
is                  {return IS;}
return              {return RETURN;}
if                  {return IF;}
then                {return THEN;}
elsif               {return ELSIF;}
else				{return ELSE;}
while               {return WHILE;}
loop                {return LOOP;}
null                {return NIL;}
for                 {return FOR;}
in                  {return IN;}
and                 {return AND;}
or                  {return OR;}
not                 {return NOT;}
of                  {return OF;}

Range           {return RANGE;}
Length          {return LENGTH;}

"+"                 {return '+';}
"-"                 {return '-';}
"*"                 {return '*';}
"/"                 {return '/';}

"="                 {return '=';}
"/="                {return NOT_EQUAL;}
"<"                 {return '<';}
">"                 {return '>';}
"<="                {return LESSER_EQUAL;}
">="                {return GREATER_EQUAL;}

":="                {return ASSIGNMENT;}
"&"                 {return '&';}
".."                {return DOUBLE_DOT;}

"(" { return '('; }
")" { return ')'; }
"," { return ','; }
";" { return ';'; }
":" { return ':'; }
"'" { return '\''; }

{STRING}        {   
                    yylval.string_const = (char *) malloc(strlen(yytext)-1);
					strncpy(yylval.string_const, yytext+1,strlen(yytext)-2);
                    
                    return CONST_STRING;
                }
                    
{CHARACTER}     { yylval.char_const = *(yytext+1); return CONST_CHARACTER;}
                        
true            { yylval.int_const = 1; return CONST_BOOL;}
false           {   yylval.int_const = 0; return CONST_BOOL;}
{INTEGER}       { yylval.int_const = atoi(yytext); return CONST_INTEGER; }
{FLOAT}         { yylval.float_const = atof(yytext); return CONST_FLOAT; }
{EXPONENT}      { yylval.float_const = atof(yytext); return CONST_FLOAT; }

{ID}        {   yylval.id_const = (char *) malloc(strlen(yytext)+1);
                strcpy(yylval.id_const, yytext);
                
                return ID;
            }

{LINE_COMMENT} { }

%%

typedef struct TreeUnit TreeUnit;
struct TreeUnit
{
    char *label;
	char *edgeLabel;
	
    int num;
    int parentNum;
    
    TreeUnit *next;
};

typedef struct Tree Tree;
struct Tree
{
    TreeUnit * begin;
    TreeUnit * end;
};

FILE* fileOpen(int iter, const char* fname,const char* prefix, const char key);

void printTree(ProgramList *pr);
char *expr_type_str(EXPR_TYPE et);
char *stmt_type_str(STMT_TYPE et);
char *variable_type_str(VAR_TYPE et);


void print_node(int nodeNum, char *nodeName);
void print_edge(int numNode1, int numNode2, char* name);

TreeUnit *newTreeUnit(int parentNum, const char *label, const char *edgeLabel);
void addTreeUnit(Tree *tree, TreeUnit *element);

void programParse(Program *prog, Tree *tree, int parentNum);
void parseDeclarationStatementList(DeclarationStatementList *prog, Tree *tree, int parentNum);
void parseDeclarationStatement(DeclarationStatement *prog, Tree *tree, int parentNum);
void parseVariableDeclarationList(VariableDeclarationList *prog, Tree *tree, int parentNum);
void parseVariableDeclaration(VariableDeclaration *prog, Tree *tree, int parentNum);
void parseRange(Range *prog, Tree *tree, int parentNum);
void parseExpression(Expression *prog, Tree *tree, int parentNum);
void parseExpressionList(ExpressionList *prog, Tree *tree, int parentNum);
void parseVariableList(VariableList *prog, Tree *tree, int parentNum);
void parseStatementList(StatementList *prog, Tree *tree, int parentNum);
void parseStatement(Statement *prog, Tree *tree, int parentNum);
void parseWhileStatement(WhileStatement *whileStmt, Tree *tree, int parentNum);
void parseForStatement( ForStatement *prog, Tree *tree, int parentNum);
void parseIfStatement(IfStatement *prog, Tree *tree, int parentNum);
void parseElse(ElseStatement *prog, Tree *tree, int parentNum);
void parseElseIfStatementList(ElseIfStatementList *prog, Tree *tree, int parentNum);

void main()
{
    int iterator = 4;
    
    const char* infname = "in\\test";
    const char* outfname = "out\\output";
    
    if( yyin = fileOpen(iterator, infname, ".adb", 'r') )
    {
		yyparse();
		fclose (yyin);
		
		fileOpen(iterator, outfname, ".txt", 'w');
		printTree(root);
		fclose (stdout);
    }
}

FILE* fileOpen(int iter, const char* fname,const char* prefix, const char key)
{
    char outname[51];
    char fnum[7];
    
    strcpy(outname, fname);
    itoa(iter, fnum, 10);
    strcat(outname, fnum);
    strcat(outname, prefix);
    
    switch(key)
    {
        case 'r':
            return fopen(outname, "r");
        break;
    
        case 'w':
            return freopen(outname, "w", stdout);
        break;
    }
}

TreeUnit *newTreeUnit(int parentNum, const char *label, const char *edgeLabel)
{
    if(label!=NULL && edgeLabel!=NULL && parentNum>=0)
    {
        TreeUnit *unit = (TreeUnit *)malloc(sizeof(TreeUnit));
        
        unit->label = (char *)malloc( sizeof(char)*(strlen(label)+1) );
        strcpy(unit->label,label);
		
		unit->edgeLabel = (char *)malloc( sizeof(char)*(strlen(edgeLabel)+1) );
        strcpy(unit->edgeLabel,edgeLabel);
        
        unit->parentNum = parentNum;
		
		unit->next = NULL;
        
        return unit;
    }
    
    return NULL;
}

void addTreeUnit(Tree *tree, TreeUnit *element)
{
    if(tree!=NULL && element!=NULL )
    {
        if(tree->begin==NULL)
        {
            tree->begin = element;
            tree->end = element;
            element->num = 1;
        }
        else
        {
            tree->end->next = element;
            element->num = tree->end->num+1;
            tree->end = element;
        }
    }
}

//Tree print section


char *expr_type_str(EXPR_TYPE et)
{
    if(et==ET_INTEGER) return "ET_INTEGER";
    if(et==ET_FLOAT) return "ET_FLOAT";
    if(et==ET_STRING) return "ET_STRING";
    if(et==ET_CHARACTER) return "ET_CHARACTER";
    if(et==ET_ID) return "ET_ID";
    if(et==ET_ARRAY_OR_FUNC) return "ET_ARRAY_OR_FUNC";
    if(et==ET_BOOL) return "ET_BOOL";
    if(et==ET_EQUAL) return "=";
    if(et==ET_NOT_EQUAL) return "/=";
    if(et==ET_LESSER) return "<";
    if(et==ET_GREATER) return ">";
    if(et==ET_LESSER_EQUAL) return "<=";
    if(et==ET_GREATER_EQUAL) return ">=";
    if(et==ET_PLUS) return "+";
    if(et==ET_MINUS) return "-";
    if(et==ET_CONCAT) return "&";
    if(et==ET_MULT) return "*";
    if(et==ET_DIV) return "/";
    if(et==ET_LOGIC_OR) return "OR";
    if(et==ET_LOGIC_AND) return "AND";
    if(et==ET_ASSIGN) return ":=";
    if(et==ET_NOT) return "NOT";
    if(et==ET_RANGE_ARR_ATTR) return "ET_RANGE_ARR_ATTR";
    if(et==ET_LENGTH_ARR_ATTR) return "ET_LENGTH_ARR_ATTR";
    return "";
}

char *stmt_type_str(STMT_TYPE et)
{
    if(et==ST_EXPRESSION) return "ST_EXPRESSION";
    if(et==ST_RETURN) return "ST_RETURN";
    if(et==ST_NULL) return "ST_NULL";
    if(et==ST_WHILE) return "ST_WHILE";
    if(et==ST_FOR) return "ST_FOR";
    if(et==ST_IF) return "ST_IF";
    if(et==ST_ASSIGN) return ":=";
    return "";
}

char *variable_type_str(VAR_TYPE et)
{
    if(et==VT_INTEGER) return "INTEGER";
    if(et==VT_FLOAT) return "FLOAT";
    if(et==VT_BOOLEAN) return "BOOLEAN";
    if(et==VT_STRING) return "STRING";
    if(et==VT_CHARACTER) return "CHARACTER";
    if(et==VT_ARRAY) return "ARRAY";
    if(et==VT_VOID) return "VOID";
    return "";
}


void print_node(int nodeNum, char *nodeName)
{
    printf("%d  [label=\"%s\"];\n",nodeNum,nodeName);
}

void print_edge(int numNode1, int numNode2, char* name)
{
    printf("%d->%d[label=\"%s\"];\n",numNode1,numNode2,name);
}

void printTree(ProgramList *pr)
{
    if(pr!=NULL)
    {
        Tree *tree = (Tree *)malloc(sizeof(Tree));
        tree->begin = NULL;
        tree->end = NULL;
		
        programParse(pr->end, tree, 0);
        
		printf("digraph Program {\n");
		
			TreeUnit *i_units = tree->begin;
			while(i_units!=NULL)
			{
				print_node(i_units->num,i_units->label);
				i_units = i_units->next;
			}
			printf("\n");
			TreeUnit *i_parent = tree->begin;
			while(i_parent!=NULL)
			{
				TreeUnit *i_child = tree->begin;
				while(i_child!=NULL)
				{
					if(i_parent->num==i_child->parentNum)
					{
						print_edge(i_parent->num, i_child->num,i_child->edgeLabel);
					}
					
					i_child = i_child->next;
				}
				i_parent = i_parent->next;
			}
			
		printf("\n}");
    }
}

void programParse(Program *prog, Tree *tree, int parentNum)
{
    if(prog!=NULL)
    {
        //main title
        addTreeUnit(tree, newTreeUnit(parentNum,prog->id,"Function"));
		int currentIter = tree->end->num;
        
        //parts of program
        if(prog->declarationSection!=NULL)
        {
            parseDeclarationStatementList(prog->declarationSection,tree,currentIter);
        }
        
        if(prog->performSection!=NULL)
        {
            parseStatementList(prog->performSection,tree,currentIter);
        }
        
        if(prog->globalariables!=NULL)
        {
			parseVariableDeclarationList(prog->globalariables,tree,currentIter);
        }
        
        //type of function
        addTreeUnit(
			tree, 
			newTreeUnit(currentIter,variable_type_str(prog->returnType),
			"Return type"));
    }
}

void parseDeclarationStatementList(DeclarationStatementList *prog, Tree *tree, int parentNum)
{
	addTreeUnit(tree, newTreeUnit(parentNum,"DeclarationStatementList",""));
	int currentIter = tree->end->num;

    if(prog!=NULL)
    {
		DeclarationStatement *ds = prog->begin;
        for(; ds!=NULL; ds = ds->nextInList)
        {
            parseDeclarationStatement(ds,tree,currentIter);
        }
    }
}

void parseDeclarationStatement(DeclarationStatement *prog, Tree *tree, int parentNum)
{
	addTreeUnit(tree, newTreeUnit(parentNum,"DeclarationStatement",""));
	int currentIter = tree->end->num;

	if(prog!=NULL)
	{
		switch(prog->type)
		{
			case DT_FUNCTION:
				programParse(prog->stmt.prog, tree, currentIter);
			break;
			
			case DT_VARIABLE:
				parseVariableDeclaration(prog->stmt.varDecl, tree, currentIter);
			break;
		}
	}
}

void parseVariableDeclarationList(VariableDeclarationList *prog, Tree *tree, int parentNum)
{
	if(prog!=NULL)
    {
		addTreeUnit(tree, newTreeUnit(parentNum,"VariableDeclarationList",""));
		int currentIter = tree->end->num;
	
		VariableDeclaration *ds = prog->begin;
		for(; ds!=NULL; ds = ds->nextInList)
        {
			parseVariableDeclaration(ds, tree, currentIter);
        }
    }
}

void parseVariableDeclaration(VariableDeclaration *prog, Tree *tree, int parentNum)
{
    if(prog!=NULL)
    {
		addTreeUnit(tree, newTreeUnit(parentNum,"VariableDeclaration",""));
		int currentIter = tree->end->num;
        
		addTreeUnit(tree, newTreeUnit(currentIter,variable_type_str(prog->type),""));
		
        if(prog->isArray)
        {
			addTreeUnit(tree, newTreeUnit(currentIter,"Array",""));
			
            parseRange(prog->range, tree, currentIter);
        }
		
		if(prog->varList!=NULL)
		{
			parseVariableList(prog->varList, tree, currentIter);
		}
    }
}

void parseRange(Range *prog, Tree *tree, int parentNum)
{
    addTreeUnit(tree, newTreeUnit(parentNum,"Range",""));
	int currentIter = tree->end->num;
    
	if(prog!=NULL)
	{
		if(prog->id!=NULL)
		{
			addTreeUnit(tree, newTreeUnit(currentIter,prog->id,"iterator"));
		}
		
		if(prog->startIndex!=NULL)
		{
			parseExpression(prog->startIndex,tree,currentIter);
		}
		
		if(prog->lastIndex!=NULL)
		{
			parseExpression(prog->lastIndex,tree,currentIter);
		}
	}
}

void parseExpression(Expression *prog, Tree *tree, int parentNum)
{
	if(prog!=NULL)
	{
		addTreeUnit(tree, newTreeUnit(parentNum,expr_type_str(prog->type),"Expression"));
		int currentIter = tree->end->num;
		
		char buf[51];
		switch(prog->type)
		{
			case ET_INTEGER :
			case ET_BOOL:
			
				itoa(prog->val.int_val,buf,10);
				
				addTreeUnit(tree, newTreeUnit(currentIter,buf,expr_type_str(prog->type)));
			break;
			
			case ET_FLOAT:
			
				sprintf(buf, "%f", prog->val.float_val);
				
				addTreeUnit(tree, newTreeUnit(currentIter,buf,"float"));
			break;
			
			case ET_STRING:
			case ET_ID:
			case ET_LENGTH_ARR_ATTR:
			
				addTreeUnit(tree, 
							newTreeUnit(currentIter,prog->val.string_val,expr_type_str(prog->type)));
			break;
			
			case ET_ARRAY_OR_FUNC:
				addTreeUnit(tree, newTreeUnit(currentIter,prog->val.string_val,expr_type_str(prog->type)));
				parseExpressionList(prog->exprList, tree, currentIter);
				
			break;
			
			case ET_CHARACTER:
				buf[0]=prog->val.char_val;buf[1]='\0';
				addTreeUnit(tree, newTreeUnit(currentIter,buf,"character"));
			break;
			
			default:
				
				if(prog->left!=NULL){
					parseExpression(prog->left, tree, currentIter);
				}
				
				if(prog->right!=NULL){
					parseExpression(prog->right, tree, currentIter);
				}
		}
		
		//if(prog->exprList!=NULL)
		//{
		//	parseExpressionList(prog->exprList, tree, currentIter);
		//}
	}
}

void parseExpressionList(ExpressionList *prog, Tree *tree, int parentNum)
{
    if(prog!=NULL)
    {
		addTreeUnit(tree, newTreeUnit(parentNum,"ExpressionList",""));
		int currentIter = tree->end->num;
		
		Expression *ds = prog->begin;
		for(; ds!=NULL; ds = ds->nextInList)
        {
            parseExpression(ds,tree,currentIter);
        }
    }
}

void parseVariableList(VariableList *prog, Tree *tree, int parentNum)
{
	if(prog!=NULL)
	{
		addTreeUnit(tree, newTreeUnit(parentNum,"VariableList",""));
		int currentIter = tree->end->num;
		
		VariableList *ds = prog;
		for(; ds!=NULL; ds = ds->nextInList)
        {
			addTreeUnit(tree, newTreeUnit(currentIter,ds->id,"variable"));
        }
	}
}

void parseStatementList(StatementList *prog, Tree *tree, int parentNum)
{
    if(prog!=NULL)
    {
		addTreeUnit(tree, newTreeUnit(parentNum,"StatementList",""));
		int currentIter = tree->end->num;
		
		Statement *ds = prog->begin;
		for(; ds!=NULL; ds = ds->nextInList)
        {
            parseStatement(ds,tree,currentIter);
        }
    }   
}

void parseStatement(Statement *prog, Tree *tree, int parentNum)
{
	if(prog!=NULL)
	{
		addTreeUnit(tree, newTreeUnit(parentNum,stmt_type_str(prog->type),"Statement"));
		int currentIter = tree->end->num;
	
		switch(prog->type)
		{
			case ST_EXPRESSION:
				parseExpression(prog->stmtVal.exprStmt,tree,currentIter);
			break;
			
			case ST_RETURN:
				parseExpression(prog->stmtVal.exprStmt,tree,currentIter);
			break;
			
			case ST_NULL:
				addTreeUnit(tree, newTreeUnit(currentIter,"NULL",""));
			break;
			
			case ST_WHILE:
				parseWhileStatement(prog->stmtVal.whileStmt,tree,currentIter);
			break;
			
			case ST_FOR:
				parseForStatement( prog->stmtVal.forStmt, tree, currentIter);
			break;
			
			case ST_IF:
				parseIfStatement(prog->stmtVal.ifStmt, tree, currentIter);
			break;
			
			case ST_ASSIGN:
				parseExpression(prog->stmtVal.assigStmt->left,tree,currentIter);
				parseExpression(prog->stmtVal.assigStmt->right,tree,currentIter);
			break;
		}
	}
}

void parseWhileStatement(WhileStatement *whileStmt, Tree *tree, int parentNum)
{
    if(whileStmt!=NULL)
    {
		addTreeUnit(tree, newTreeUnit(parentNum,"WhileStatement",""));
		int currentIter = tree->end->num;
	
		parseExpression(whileStmt->condition,tree,currentIter);

        parseStatementList(whileStmt->whileBlock, tree, currentIter);
    }
}

void parseForStatement( ForStatement *prog, Tree *tree, int parentNum)
{
    if(prog!=NULL)
    {
		addTreeUnit(tree, newTreeUnit(parentNum,"ForStatement",""));
		int currentIter = tree->end->num;
		
		addTreeUnit(tree, newTreeUnit(currentIter,prog->iterID,"iterator"));
		parseStatementList(prog->stmtList, tree, currentIter);
		parseRange(prog->range, tree, currentIter);
    }
}

void parseIfStatement(IfStatement *prog, Tree *tree, int parentNum)
{
    if(prog!=NULL)
	{
		addTreeUnit(tree, newTreeUnit(parentNum,"IfStatement",""));
		int currentIter = tree->end->num;
	
		parseExpression(prog->condition,tree,currentIter);
		parseStatementList(prog->stmtList, tree, currentIter);
		parseElse(prog->elseStmt, tree, currentIter);
		parseElseIfStatementList(prog->elseIfStmtList, tree, currentIter);
	}
}

void parseElse(ElseStatement *prog, Tree *tree, int parentNum)
{
	if(prog!=NULL)
	{
		addTreeUnit(tree, newTreeUnit(parentNum,"ElseStatement",""));
		int currentIter = tree->end->num;
		
		parseStatementList(prog->stmtList, tree, currentIter);
	}
}

void parseElseIfStatementList(ElseIfStatementList *prog, Tree *tree, int parentNum)
{
	if(prog!=NULL)
    {
		addTreeUnit(tree, newTreeUnit(parentNum,"ElseIfStatementList",""));
		int currentIter = tree->end->num;
		
		ElseIfStatement *ds = prog->begin;
		for(; ds!=NULL; ds = ds->nextInList)
        {
			parseExpression(ds->condition,tree,currentIter);
			parseStatementList(ds->stmtList, tree, currentIter);
        }
    }
}