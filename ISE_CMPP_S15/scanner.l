%{
	#include "parser.h"
	#include <iostream>
	using std::cout;
	using std::endl;
	
	int column = 0;
	int line = 1;
%}

%x myComment

Int [1-9]([0-9]*)|0
Double [0-9]+"."[0-9]*(("e"|"E")("-"|"+")?[0-9]+)?

%%

"class"					{column += yyleng;	return CLASS; } 
"if"					{column += yyleng;	return IF; }
"else"					{column += yyleng;	return ELSE; } 
"return"				{column += yyleng;	return RETURN; }
"int"					{column += yyleng;	return INT; }
"double"				{column += yyleng;	return DOUBLE; }
"true"					{
							yylval.tBool = new Bool(0, line, column);
							column += yyleng;	
							return TRUE; 
						}
"false"					{
							yylval.tBool = new Bool(1, line, column);
							column += yyleng;	
							return FALSE; 
						}
"bool"					{column += yyleng;	return BOOL; }
"void"					{column += yyleng;	return VOID; }
"while"					{column += yyleng;	return WHILE; }
"for"					{column += yyleng;	return FOR;}
"new"					{column += yyleng;	return NEW;}
[a-zA-Z_][a-zA-Z0-9_]*  {
							yylval.tIdent = new Ident(strdup(yytext),line,column);
							column += yyleng;	
							return IDENTIFIER;
						}
[(){}\-;=+*<>,\[\]/.]	{column += yyleng;	return *yytext;}
"=="					{column += yyleng;	return EQ; }
"!="					{column += yyleng;	return NEQ; }
"<="					{column += yyleng;	return LOQ; }
">="					{column += yyleng;	return MOQ; }
"++"					{column += yyleng;	return INCREMENT; }
"--"					{column += yyleng;	return DECREMENT; }
"&&"					{column += yyleng;	return AND; }
"||"					{column += yyleng;	return OR; }
"!"						{column += yyleng;	return NOT; }

[ ]						{column += yyleng;	/* IGNORE SPACES */}
[ \t]					{column += yyleng;	/* IGNORE tabs */}
\n						{column = 0; line++;		/* IGNORE NEW LINES */}

{Int}					{
							yylval.tInt = new Integer(atoi(yytext), line, column);
							column += yyleng;	
							return INTEGER;
						}
{Double}				{
							yylval.tDouble = new Double(atof(yytext), line, column);
							column += yyleng;	
							return DOUBLENUM; 
						}



"//"[^\n]* 						{ /* ignore short comments */line++; }

"/*"							BEGIN(myComment);
<myComment>[^*\n]*				{ /* ignore Long comments */ line++;}
<myComment>[^*\n]*\n			{ /* ignore Long comments */line++; }
<myComment>"*"+[^*/\n]*			{ /* ignore Long comments */line++; }
<myComment>"*"+[^*/\n]*\n		{ /* ignore Long comments */line++; }
<myComment>"*"+"/"				BEGIN(0);


.						{ /*Anything else is an error */
							cout<<"Lexical error, mystery character: <"<< yytext <<"> at line: ["
								<< line <<"] column: ["<<column<<"]"<<endl;
						}
	
							
%%
int yywrap()
{
	return 1;
}