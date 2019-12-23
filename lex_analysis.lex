%{
#include<string.h>
#include<string>
#include"node.h"
#include"parser.hpp"
#define SAVE_TOKEN yylval.str = new std::string(yytext, yyleng)
#define TOKEN(t) yylval.token = t
extern "C"{}
extern "C" int yywrap() { }
%}

%%
int {SAVE_TOKEN; return Int; }
float {SAVE_TOKEN;return Float; }
double      {SAVE_TOKEN; return Double; }
auto        {SAVE_TOKEN; return Auto; }
break       {SAVE_TOKEN; return Break; }
case        {SAVE_TOKEN; return Case; }
const       {SAVE_TOKEN; return Const; }
else        {SAVE_TOKEN; return Else; }
for         {SAVE_TOKEN; return For; }
if          {SAVE_TOKEN; return If; }
long        {SAVE_TOKEN; return Long; }
return      {SAVE_TOKEN; return Return; }
short       {SAVE_TOKEN; return Short; }
signed      {SAVE_TOKEN; return Signed; }
char        {SAVE_TOKEN; return Char; }
unsigned    {SAVE_TOKEN; return Unsigned; }
while	{ return TOKEN(While); }
[ \t\n]	;
[a-zA-Z_][a-zA-Z0-9_]*	{SAVE_TOKEN;return ID;}
[0-9]+	{SAVE_TOKEN;return INT;}
[0-9]+\.[0-9]*	{SAVE_TOKEN;return DOUBLE;}
"="	 {return TOKEN(EQ);}
">"	 {return TOKEN(GT);}
"<"	 {return TOKEN(LT);}
">="	 {return TOKEN(GE);}
"<="	 {return TOKEN(LE);}
"=="	 {return TOKEN(EQEQ);}
"!="	 {return TOKEN(NE);}
"*"	{return TOKEN(MUL);}
"/"	{return TOKEN(DIV);}
"+"	{return TOKEN(ADD);}
"-"	{return TOKEN(SUB);}
"("	{return TOKEN(LPAREN);}
")"	{return TOKEN(RPAREN);}
"{"	{return TOKEN(LBRACE);}
"}"	{return TOKEN(RBRACE);}
"["	{return TOKEN(LMBRA);}
"]"	{return TOKEN(RMBRA);}
";"	{return TOKEN(SEMI);}
","	{return TOKEN(COMMA);}
"\."	{return TOKEN(DOT);}
%%
