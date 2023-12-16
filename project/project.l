%{
#include "project.tab.h"
#include <stdio.h>
extern nb_ligne;
extern YYSTYPE yylval;
%}
%option yylineno
IDF [A-Z]+[A-Za-z0-9]*(_[A-Za-z0-9]+)*
INTNUM [0-9]+
float [-]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?
commentaire "/*"[^/*]*"*/"


%%
{commentaire}   {}
\".*\"      { return STR; }
"BEGIN"         {  yylval.string=strdup(yytext); insert(yytext,"keyword");return BEGINN; }
"FLOAT"|"float" { return FLOATVAR; }
"BOOL"|"bool"   {return BOOLL ; }
"true"|"false"  { return BOOL_VAL; }
"STRING"|"string" { return STRING; }
"int"|"INT"       { return INT; }
"CONST"|"const"   { return cst; }
"END"            { yylval.string=strdup(yytext); insert(yytext,"keyword"); return ENDD; }
"CHAR"|"char"    { return CHARR; }
"void"|"VOID"    { return VOID; }
"for"            {  yylval.string=strdup(yytext); insert(yytext,"keyword");return FOR;}
"if"             { yylval.string=strdup(yytext); insert(yytext,"keyword");return IF; }
"else"           { yylval.string=strdup(yytext); insert(yytext,"keyword");return ELSE; }
"printf"         { yylval.string=strdup(yytext); insert(yytext,"keyword"); return PRINTFF;}
"while"          {yylval.string=strdup(yytext); insert(yytext,"keyword"); return WHILE; }
"do"             { yylval.string=strdup(yytext); insert(yytext,"keyword");return DO; }
"function"       {  yylval.string=strdup(yytext); insert(yytext,"keyword");return FUNCTIONN;}

{IDF} { if (strlen(yytext) <= 10 && yytext[strlen(yytext)-1] != '_') 
{yylval.string=strdup(yytext); insert(yytext,"idf");return idf; }}
{INTNUM}       { yylval.int_val   = atoi(yytext); return INT_NUM;}
{float}         {yylval.double_val = atof(yytext);  return FLOAT_NUM;}
    

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

[ \t]*   /* Ignore whitespace */

[\n]* {nb_ligne++;}
.	                    { printf("\nErreur lexicale  dans la ligne %d",nb_ligne); }
%%
