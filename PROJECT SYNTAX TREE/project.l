%{
#include "project.tab.h"
#include <stdio.h>
extern nb_ligne;
%}
%option yylineno
IDF [A-Z]+[A-Za-z0-9]*(_[A-Za-z0-9]+)*
INTNUM [0-9]+
float [-]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?
commentaire "/*"([^*]|\*+[^*/])*\*+"/"



%%
\".*\"      { strcpy(yylval.nd_obj.name,(yytext)); return STR; }
"BEGIN"         {strcpy(yylval.nd_obj.name,(yytext)); return BEGINN; yylval.string=strdup(yytext); insert(yytext,"keyword"); }
"FLOAT"|"float" {strcpy(yylval.nd_obj.name,(yytext)); return FLOATVAR; }
"BOOL"|"bool"   {strcpy(yylval.nd_obj.name,(yytext));return BOOLL ; }
"true"|"false"  {strcpy(yylval.nd_obj.name,(yytext)); return BOOL_VAL; }
"STRING"|"string" {strcpy(yylval.nd_obj.name,(yytext)); return STRING; }
"int"|"INT"       {strcpy(yylval.nd_obj.name,(yytext)); return INT; }
"CONST"|"const"   {strcpy(yylval.nd_obj.name,(yytext)); return cst; }
"END"            {strcpy(yylval.nd_obj.name,(yytext)); return ENDD; }
"CHAR"|"char"    {strcpy(yylval.nd_obj.name,(yytext)); return CHARR; }
"void"|"VOID"    {strcpy(yylval.nd_obj.name,(yytext)); return VOID; }
"for"            {strcpy(yylval.nd_obj.name,(yytext)); return FOR;}
"if"             { strcpy(yylval.nd_obj.name,(yytext));return IF; }
"else"           { strcpy(yylval.nd_obj.name,(yytext));return ELSE; }
"printf"         { strcpy(yylval.nd_obj.name,(yytext)); return PRINTFF;}
"while"          { strcpy(yylval.nd_obj.name,(yytext));return WHILE; }
"do"             { strcpy(yylval.nd_obj.name,(yytext));return DO; }
"function"       { strcpy(yylval.nd_obj.name,(yytext));return FUNCTIONN;}

{IDF} { if (strlen(yytext) <= 10 && yytext[strlen(yytext)-1] != '_') 
{strcpy(yylval.nd_obj.name,(yytext)); return idf; }}
{INTNUM}       { strcpy(yylval.nd_obj.name,(yytext)); return INT_NUM;}
{float}         {strcpy(yylval.nd_obj.name,(yytext)); return FLOAT_NUM;}
{commentaire}       {return commentaire;}

"("     { strcpy(yylval.nd_obj.name,(yytext)); return '('; }
")"     {strcpy(yylval.nd_obj.name,(yytext)); return ')'; }
"{"     {strcpy(yylval.nd_obj.name,(yytext)); return '{'; }
"}"     {strcpy(yylval.nd_obj.name,(yytext)); return '}'; }
"<"     {strcpy(yylval.nd_obj.name,(yytext)); return lt; }
">"     {strcpy(yylval.nd_obj.name,(yytext)); return gt; }
"="     {strcpy(yylval.nd_obj.name,(yytext)); return eq; }
":="    {strcpy(yylval.nd_obj.name,(yytext)); return aff; }
";"     {strcpy(yylval.nd_obj.name,(yytext)); return pvg; }
"=="    {strcpy(yylval.nd_obj.name,(yytext)); return eqeq; }
"!="    {strcpy(yylval.nd_obj.name,(yytext)); return neq; }
"+"     {strcpy(yylval.nd_obj.name,(yytext)); return pl; }
"-"     {strcpy(yylval.nd_obj.name,(yytext)); return min; }
"&&"    {strcpy(yylval.nd_obj.name,(yytext)); return and; }
"*"     {strcpy(yylval.nd_obj.name,(yytext)); return mul; }
"||"    {strcpy(yylval.nd_obj.name,(yytext)); return orr; }
"++"    {strcpy(yylval.nd_obj.name,(yytext)); return incr; }
"<="    {strcpy(yylval.nd_obj.name,(yytext)); return lteq; }
">="    {strcpy(yylval.nd_obj.name,(yytext)); return gteq; }
"!"     {strcpy(yylval.nd_obj.name,(yytext)); return neq; }
"--"    {strcpy(yylval.nd_obj.name,(yytext)); return decr; }
"/"     {strcpy(yylval.nd_obj.name,(yytext)); return divv; }
","     {strcpy(yylval.nd_obj.name,(yytext)); return virgule; }

\/\/.*   /* Ignore single-line comments */

\/\*(.*\n)*.*\*\/   /* Ignore multi-line comments */

[ \t]*   /* Ignore whitespace */

[\n]* {nb_ligne++;}
.	                    { printf("\nErreur lexicale  dans la ligne %d",nb_ligne); }
%%
