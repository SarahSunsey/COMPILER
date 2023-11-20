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
"\".*\""       { return STR; }

"BEGIN"         { return BEGINN; }
"FLOAT"|"float" { return FLOATVAR; }
"BOOL"|"bool"   {returnBOOLL ; }
"true"|"false"  { return BOOL_VAL; }
"STRING"|"string" { return STRING; }
"int"|"INT"       { return INT; }
"CONST"|"const"   { return cst; }
"END"            { return ENDD; }
"CHAR"|"char"    { return CHARR; }
"void"|"VOID"    { return VOID; }
"for"            { return FOR; }
"if"             { return IF; }
"else"           { return ELSE; }
"printf"         { return PRINTFF; }
"while"          { return WHILE; }
"do"             { return DO; }
"function"       { return FUNCTIONN; }

{IDF} { if (strlen(yytext) <= 10 && yytext[strlen(yytext)-1] != '_') {/*yylval.stringg=strdup(yytext)*/return idf; }}
{INTNUM}       {return INT_NUM;}
{float}         { return FLOAT_NUM;}
{commentaire}       {return commentaire;}

"("     { return '('; }
")"     { return ')'; }
"{"     { return '{'; }
"}"     { return '}'; }
"<"     { return lt; }
">"     { return gt; }
"="     { return eq; }
":="    { return aff; }
";"     { return pvg; }
"=="    { return eqeq; }
"!="    { return neq; }
"+"     { return pl; }
"-"     { return min; }
"&&"    { return and; }
"*"     { return mul; }
"||"    { return orr; }
"++"    { return incr; }
"<="    { return lteq; }
">="    { return gteq; }
"!"     { return neq; }
"--"    { return decr; }
"/"     { return divv; }
","     { return virgule; }

\/\/.*   /* Ignore single-line comments */

\/\*(.*\n)*.*\*\/   /* Ignore multi-line comments */

[ \t]*   /* Ignore whitespace */

[\n]* {nb_ligne++;}
.	                    { printf("\nErreur lexicale  dans la ligne %d",nb_ligne); }
%%
