%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <conio.h>
	#include "ada_bison_tab.h"
	extern int yyparse(void)
%}

%option noyywrap
%option never-interactive
%option yylineno
%option case-insensitive


ID				[a-z]+([_]?[a-z0-9]+)*
LINE_COMMENT	"--".* 
CHARACTER		\'.\'
STRING			\"([^"\n]|["]{2})*\"
INTEGER			[0-9]+
FLOAT          	[0-9]*\.{INTEGER}
EXPONENT	 	{FLOAT}[eE][+-]?{INTEGER}

SPACE           [[:space:]]*

%%

%{
	int s = 0;
	char symbol[2];
	char buf[100000];
	memset(buf, '\0', 100000);
%}

integer				{ printf("Found a type '%s' in line %d\n", yytext, yylineno); }
boolean				{ printf("Found a type '%s' in line %d\n", yytext, yylineno); }
float				{ printf("Found a type '%s' in line %d\n", yytext, yylineno); }
character			{ printf("Found a type '%s' in line %d\n", yytext, yylineno); }
string				{ printf("Found a type '%s' in line %d\n", yytext, yylineno); }
array				{ printf("Found a type '%s' in line %d\n", yytext, yylineno); }

then				{ printf("Found a keyword '%s' in line %d\n", yytext, yylineno); }	
loop				{ printf("Found a keyword '%s' in line %d\n", yytext, yylineno); }
for					{ printf("Found a keyword '%s' in line %d\n", yytext, yylineno); }
not					{ printf("Found a keyword '%s' in line %d\n", yytext, yylineno); }
reverse				{ printf("Found a keyword '%s' in line %d\n", yytext, yylineno); }
or					{ printf("Found a keyword '%s' in line %d\n", yytext, yylineno); }
true				{ printf("Found a keyword '%s' in line %d\n", yytext, yylineno); }
false				{ printf("Found a keyword '%s' in line %d\n", yytext, yylineno); }
procedure			{ printf("Found a keyword '%s' in line %d\n", yytext, yylineno); }
function			{ printf("Found a keyword '%s' in line %d\n", yytext, yylineno); }
elsif				{ printf("Found a keyword '%s' in line %d\n", yytext, yylineno); }
null				{ printf("Found a keyword '%s' in line %d\n", yytext, yylineno); }
in					{ printf("Found a keyword '%s' in line %d\n", yytext, yylineno); }
and					{ printf("Found a keyword '%s' in line %d\n", yytext, yylineno); }
begin				{ printf("Found a keyword '%s' in line %d\n", yytext, yylineno); }
end					{ printf("Found a keyword '%s' in line %d\n", yytext, yylineno); }
is					{ printf("Found a keyword '%s' in line %d\n", yytext, yylineno); }
return				{ printf("Found a keyword '%s' in line %d\n", yytext, yylineno); }
if					{ printf("Found a keyword '%s' in line %d\n", yytext, yylineno); }
while				{ printf("Found a keyword '%s' in line %d\n", yytext, yylineno); }
constant			{ printf("Found a keyword '%s' in line %d\n", yytext, yylineno); }
exit				{ printf("Found a keyword '%s' in line %d\n", yytext, yylineno); }

"+"					{ printf("Found an arithmetical operation '%s' in line %d\n", yytext, yylineno); }
"-"					{ printf("Found an arithmetical operation '%s' in line %d\n", yytext, yylineno); }
"*"					{ printf("Found an arithmetical operation '%s' in line %d\n", yytext, yylineno); }
"/"					{ printf("Found an arithmetical operation '%s' in line %d\n", yytext, yylineno); }
"**"				{ printf("Found an arithmetical operation '%s' in line %d\n", yytext, yylineno); }

"="					{ printf("Found a comparison operator '%s' in line %d\n", yytext, yylineno); }
"/="				{ printf("Found a comparison operator '%s' in line %d\n", yytext, yylineno); }
"<"					{ printf("Found a comparison operator '%s' in line %d\n", yytext, yylineno); }
">"					{ printf("Found a comparison operator '%s' in line %d\n", yytext, yylineno); }
"<="				{ printf("Found a comparison operator '%s' in line %d\n", yytext, yylineno); }
">="				{ printf("Found a comparison operator '%s' in line %d\n", yytext, yylineno); }

"'"Range			{ printf("Found an array attribyte '%s' in line %d\n", yytext, yylineno); }
"'"Length			{ printf("Found an array attribyte '%s' in line %d\n", yytext, yylineno); }

":="				{ printf("Found an assignment operator '%s' in line %d\n", yytext, yylineno); }
"&"					{ printf("Found a string operation '%s' in line %d\n", yytext, yylineno); }
".."				{ printf("Found a range operation '%s' in line %d\n", yytext, yylineno); }


"("					{ printf("Found a delimiter '%s' in line %d\n", yytext, yylineno); }
")"					{ printf("Found a delimiter '%s' in line %d\n", yytext, yylineno); }
","					{ printf("Found a delimiter '%s' in line %d\n", yytext, yylineno); }
";"					{ printf("Found a delimiter '%s' in line %d\n", yytext, yylineno); }
":"					{ printf("Found a delimiter '%s' in line %d\n", yytext, yylineno); }
"'"					{ printf("Found a delimiter '%s' in line %d\n", yytext, yylineno); }

{STRING} 		{ 	
					strncpy(buf, yytext+1,strlen(yytext)-2); 
					char* ptr = strstr(buf, "\"\"");

					while(ptr){
						strcpy(buf+(ptr-buf),ptr+1);
						ptr = strstr(buf+(ptr-buf+1), "\"\"");
					}
					
					printf("Found a string value '%s' in line %d\n", buf, yylineno);
					memset(buf, '\0', 100000);
				}
					
{CHARACTER} 	{ printf("Found a character value '%c' in line %d\n", strncpy(symbol, yytext+1,1)[0], yylineno);
						memset(symbol, '\0', 2);}
						
true			{ printf("Found a boolean value '%d' in line %d\n", yytext, yylineno); }
false			{ printf("Found a boolean value '%d' in line %d\n", yytext, yylineno); }

{INTEGER} 		{ printf("Found a integer value '%d' in line %d\n", atoi(yytext), yylineno); }
{FLOAT} 		{ printf("Found a float value '%f' in line %d\n", atof(yytext), yylineno); }
{EXPONENT} 		{ printf("Found an exponent value '%e' in line %d\n", atof(yytext), yylineno); }

{ID} 			{ printf("Found an identifier '%s' in line %d\n", yytext, yylineno); }

{LINE_COMMENT}	{ printf("Found single line comment in line %d\n", yylineno); }

\n				{ }
{SPACE}			{ }

%%

int main()
{
	int iterator = 0;
	const char* infname = "in\\test";
	const char* outfname = "out\\output";
	
	while(yyin = fileOpen(iterator, infname, ".adb", 'r'))
	{
		fileOpen(iterator, outfname, ".txt", 'w');
		yyparse();
		fclose (yyin);
		
		++iterator;
	}

	fclose (stdout);

	return 0;
}

FILE* fileOpen(int iter, const char* fname, const char* fprefix, const char key)
{
	char outname[51];
	char fnum[7];
	
	strcpy(outname, fname);
	_itoa(iter, fnum, 10);
	strcat(outname, fnum);
	strcat(outname, fprefix);
	
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
