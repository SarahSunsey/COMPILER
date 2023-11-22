%{
#include <stdio.h>
int nb_ligne=1;
  int yylex();
  int yywrap();

extern void yyerror(const char* msg);
extern char* yytext;
    void add(char);
    void insert_type();
    void handleAffectation() ; 
    int search(char *);

    struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        int line_no;
        char * ValNUm;
       
    } symbol_table[100];
    int declarationPhase=1 ;
    int count=0;
    int q;
    char ValNumerique[10];
    char type[10];
    
%}
%token BEGINN aff pvg idf  cst  virgule
%token FLOAT_NUM INT BOOLL STRING  BOOL_VAL CHARR VOID STR PRINTFF
%token INT_NUM FLOATVAR real charr string BOOL_VAR
%token commentaire seulcommentaire
%token lt gt eq eqeq neq 
%token pl min and mul orr 
%token incr lteq gteq not decr divv  po pf ao af
%token ENDD
%token FOR IF ELSE  WHILE DO FUNCTIONN NAMEFUNCTION RETURN;

%start S
%%
datatype:
BOOLL { insert_type();  }
|INT { insert_type(); }
|FLOATVAR { insert_type(); }
|CHARR { insert_type(); }
;
//  i think we do not have functions in our language !!
return_type :INT|FLOATVAR|CHARR|VOID|BOOLL
COMP:lt|gt|eq|eqeq|neq 
unary:incr|decr

S: declarations   BEGINN { declarationPhase  = 0 ;} programme ENDD {printf("\nprogramme correct (syntaxiquement correcte)");}
;

declarations: declaration declarations 
|declaration
;

declaration:cst  datatype declarationCNST 
|INT { insert_type(); } declarationENTIER
|FLOATVAR { insert_type(); } declarationFLOAT
|BOOLL { insert_type();  } declarationBOOL
;

// when declaring an IDF check previous IDF's on symbolic table , if it's exist so double declare
declarationENTIER:IDF virgule declarationENTIER
|IDF  pvg 
|IDF eq INT_NUM  pvg // here when you add an INT_NUM  you should add a checker 
;
declarationFLOAT:IDF virgule declarationFLOAT
|IDF pvg
|IDF eq FLOAT_NUM  pvg // here when you add an FLOAT_NUM  you should add a checker 
;
declarationCNST:
IDF2 eq VALUE virgule declarationCNST
|IDF2 pvg 
|IDF2 eq INT_NUM {} pvg //here also , why CNST does not have Float ?
;

// handle identification of both Constants and Variables
// var
IDF:idf { add('V'); };
// const
IDF2:idf{add('C')}


// declarationBOOL handles boolean declarations.
declarationBOOL:IDF virgule declarationBOOL
|IDF pvg
|IDF eq BOOL_VAL {}  pvg
;


//  programme defines the structure of a program, including variable assignments,
//  printf statements, if-else constructs,
//  while and do-while loops, unary operations, comments, and for loops.
programme:
// here you should check if it's a const
IDF {handleAffectation();}  aff expression pvg 
|PRINTFF {add('K');}'(' STR ')' pvg
| IF {add('K');}  '(' condition ')' '{' programme '}' else
|WHILE {add('K');} '(' condition ')' '{' programme '}'
|DO {add('K');} '{' programme '}' WHILE{add('K');}'(' condition ')'
| IDF unary pvg
|commentaire
| unary IDF pvg
|FOR {add('K');}'(' statement pvg condition pvg statement ')' '{' programme '}'
|programme programme
;
// statement defines different types of statements, including variable
//  assignments and unary operations.
statement :
datatype IDF aff VALUE 
| IDF aff expression
|IDF unary
|unary IDF
;

// condition handles conditions, including comparisons and boolean literals.

condition: IDF COMP expression 
|BOOL_VAL
;

// else handles the optional else part of an if-else construct.

else: ELSE {add('K');} '{' programme '}'
|
;

term: expression OP term
|VALUE
;
expression: term
;

OP: min | pl | and | mul | orr
VALUE: INT_NUM | FLOAT_NUM  |IDF |BOOL_VAL {}

/*
function:
FUNCTIONN IDF '(' argument ')'
;
argument: argument virgule argument
datatype IDF 
;

return :
RETURN VALUE pvg 
|
;
*/
%%
void insert_type() {
strcpy(type, yytext);
}
// bool checkConst(){
  
// }
void handleAffectation(){
 
  search(yytext);
  if(q==-1) printf("%d erreur symentic cannot affect data to null \n" , nb_ligne);
  else{
    // printf("%d idf exist with index %d \n" , nb_ligne ,q) ;
    if( strcmp(strdup("Constante") ,symbol_table[q].type)==0){
      printf("%d symentic error -> affectation to const \n" , nb_ligne) ;
    } 
  }
  // if(checkConst()){printf('Changement de valeur d’une constante')} ;
}
// here fixed , adding to symbolic table only idf's in the declaration phase and keywords  
void add(char str) {
  q=search(yytext);


  if (q == -1) {
    if(declarationPhase ==0){
      printf("%d symentic error -> idf not declared \n" ,nb_ligne ) ;
    }
    if(str=='V' && declarationPhase==1){
      symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=nb_ligne;
			symbol_table[count].type=strdup("Variable");
            
 
			count++;
    }
    else if(str=='C' && declarationPhase==1){
      symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=nb_ligne;
			symbol_table[count].type=strdup("Constante");      
      symbol_table[count].ValNUm=ValNumerique;
			count++;
    }
    else if(str == 'K') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup("N/A");
			symbol_table[count].line_no=nb_ligne;
			symbol_table[count].type=strdup("Keyword\t");
			count++;
		}
  }
  else{
    if(declarationPhase==1){
      printf("%d symentic error --> IDF already declared\n" , nb_ligne);
    }
    
    // so here it does not mean it's symentic error if we didn't found it 
    // check if it's
    // printf("erreur SEMANTIQUE %c la ligne %d \n",yytext,nb_ligne);
  }
}
// fixed here -1 is also false in c 
int search(char* name) {
    int i;
   
    for (i = 0; i <= count-1; i++) {
        if (strcmp(symbol_table[i].id_name, name) == 0) {
            return i;  // Return the index of the found identifier
        }
    }
    return -1;  // Identifier not found
}

void afficher(){
  printf("\n\n");
	printf("\nNAME           DATATYPE         TYPE        LINE NUMBER       \n");
	printf("______________________________________________________________________\n\n");
	int i=0;
	for(i=0; i<count; i++) {
		printf("%s\t\t%s\t\t%s\t\t%d\t\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
	}
	for(i=0;i<count;i++) {
		free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}
	printf("\n\n");
}
yywrap()
{}
void yyerror(const char* msg) {
  fprintf(stderr, "\nError: %s ligne %d\n ", msg,nb_ligne);
}
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = freopen(argv[1], "r", stdin);
    if (file == NULL) {
        perror("Error");
        return 1;
    }

    yyparse();
    afficher();
    fclose(file);
   
    return 0;
}
