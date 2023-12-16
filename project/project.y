%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int nb_ligne=1;
  int yylex();
  int yywrap();
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_PINK    "\x1b[38;2;255;182;193m"    
#define ANSI_COLOR_RESET   "\x1b[0m"
extern void yyerror(const char* msg);
char * turnEXP(char * str);
char* endptr;
double result;
char* replaceStringIncrementDecrement(char* input);
void addvalinct(int x, char* expression);
int errS=0;
char tempStr[20];
char postfixExpression[100];
typedef struct {
    int top;
    double* array;
} Stack;

void printStack(Stack* stack);
Stack* initializeStack(int size);
int isEmpty(Stack* stack);
void push(Stack* stack, double item);
double pop(Stack* stack);
typedef struct {
    int top;
    char* array;
} CharStack;

void printCharStack(CharStack* stack);
CharStack* initializeCharStack(int size);
int isEmptyChar(CharStack* stack) ;
void pushChar(CharStack* stack, char item);
char popChar(CharStack* stack);
int getPrecedence(char operatorr);
void infixToPostfix(char* infix, char* postfix);
double evaluateExpression(char* expression);
extern void insert(char* str,char* strg);
extern char* yytext;
    void add(char);
    void insert_type();
    void handleAffectation() ; 
    void handleDecCst(char * cst);
    int search(char *);
    void addval(int x,char * str);
    struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        int line_no;
        double ValNUm ;
        char * str ;
        char * boolVal ; 
        
    } symbol_table[100];
    int declarationPhase=1 ;
    char exp[30];
    int count=0;
    int q;
    int y;
    char ValNumerique[10];
    char type[10];
    char decCST[10];
    int Affvar=-1;
   
%}
%union {
int int_val;
double double_val;
char* string;
}
%token BEGINN aff pvg <string> idf  cst  virgule
%token <double_val>FLOAT_NUM INT BOOLL STRING  BOOL_VAL CHARR VOID STR PRINTFF
%token <int_val>INT_NUM  FLOATVAR real charr string BOOL_VAR
%token commentaire seulcommentaire
%token lt gt eq eqeq neq 
%token pl min and mul orr 
%token incr lteq gteq not decr divv  po pf ao af
%token ENDD
%token FOR IF ELSE  WHILE DO FUNCTIONN NAMEFUNCTION RETURN;

%start S
%%


S:  declarations    BEGINN  { declarationPhase  = 0 ; add('K'); } programme   ENDD    { add('K'); printf("\nprogramme correct (syntaxiquement correcte)");}
| {printf(" error : programme vide");}
|BEGINN ENDD {printf("warning : programme semi vide");}
;

declarations: declaration   declarations 
| declaration 

;

declaration:cst  datatype declarationCNST 
|CHARR { insert_type(); } declarationCHAR
|STRING { insert_type(); } declarationSTRING
|INT { insert_type(); } declarationENTIER
|FLOATVAR { insert_type(); } declarationFLOAT
|BOOLL { insert_type();  } declarationBOOL
|cmnt
;
cmnt:
commentaire cmnt
|commentaire
;
declarationCHAR: IDF virgule declarationCHAR
|IDF pvg
;
declarationSTRING:IDF virgule declarationSTRING
|IDF pvg;
// when declaring an IDF check previous IDF's on symbolic table , if it's exist so double declare
declarationENTIER:IDF virgule declarationENTIER
|IDF  pvg 
//|IDF eq INT_NUM  pvg // here when you add an INT_NUM  you should add a checker 
;
declarationFLOAT:IDF virgule declarationFLOAT
|IDF pvg
//|IDF eq FLOAT_NUM  pvg // here when you add an FLOAT_NUM  you should add a checker 
;
declarationCNST:
IDF2 eq VALUEcst virgule declarationCNST
|IDF2 pvg 
|IDF2 eq VALUEcst  pvg 
;

// handle identification of both Constants and Variables
// var
IDF:idf {
 add('V'); };
// const
IDF2:idf{ add('C');strcpy(decCST,yytext);}

VALUEcst: INT_NUM  {
  handleDecCst(decCST);
}| FLOAT_NUM {
    //printf("\n dec cst %s\n",decCST);
    handleDecCst(decCST);} 
|idf {handleDecCst(decCST);} 
|BOOL_VAL{handleDecCst(decCST);}

// declarationBOOL handles boolean declarations.
declarationBOOL:IDF virgule declarationBOOL
|IDF pvg
|IDF eq BOOL_VAL {}  pvg
;


//  programme defines the structure of a program, including variable assignments,
//  printf statements, if-else constructs,
//  while and do-while loops, unary operations, comments, and for loops.
programme:
IDF {
  handleAffectation(); }
  aff expression { 
    strcpy(exp,"");} pvg 
|PRINTFF {add('K');}'(' STR ')' pvg
| IF {add('K');}  '(' condition ')' '{' programme '}' else
|WHILE {add('K');} '(' condition ')' '{' programme '}'
|DO {add('K');} '{' programme '}' WHILE{add('K');}'(' condition ')'
| IDF {handleAffectation(1);} unary {strcpy(exp,"");} pvg
|commentaire
| unary IDF pvg
|FOR  {add('K');}'(' statement pvg condition pvg statement ')' '{' programme '}'
|programme programme
;
// statement defines different types of statements, including variable
//  assignments and unary operations.
statement :
IDF {
  } aff VALUE
| IDF {
   } aff expression1
|IDF unary
|unary IDF

;

// condition handles conditions, including comparisons and boolean literals.

condition: IDF COMP expression1 
|BOOL_VAL
;

// else handles the optional else part of an if-else construct.

else: ELSE {add('K');} '{' programme '}'
|
;
term: expression OP1 term
| '(' expression ')' OP1 term
|VALUE1
;
expression: term 
;

term2: expression1 OP term2
|VALUE1
;
expression1: term2 
;

datatype:
BOOLL { insert_type();  }
|INT { insert_type(); }
|FLOATVAR { insert_type(); }
|CHARR { insert_type(); }
;
//  i think we do not have functions in our language !!
return_type :INT|FLOATVAR|CHARR|VOID|BOOLL
COMP:lt|gt|eq|eqeq|neq 
unary:incr{strcat(exp, yytext);
addvalinct(y,exp);}|decr

OP: min | pl | and | mul | orr | divv
VALUE: INT_NUM | FLOAT_NUM |idf |BOOL_VAL

OP1: min {strcat(exp, yytext);} | pl {strcat(exp, yytext);}| and {strcat(exp, yytext);}| divv {strcat(exp, yytext);}| mul {strcat(exp, yytext);}
VALUE1: INT_NUM {strcat(exp, yytext);
addval(y,exp);}| FLOAT_NUM {strcat(exp, yytext);addval(y,exp);} |IDF {strcat(exp, yytext);addval(y,exp);}  |BOOL_VAL {strcat(exp, yytext);addval(y,exp);}

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
void addvalinct(int x, char* expression){
    char *exp =replaceStringIncrementDecrement(expression);
    addval(x,exp);
}
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack contents: ");
    int i;
    for (i = 0; i <= stack->top; ++i) {
        printf("%lf ", stack->array[i]);
    }
    printf("\n");
}

// Initialize a stack
Stack* initializeStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->array = (double*)malloc(size * sizeof(double));
    return stack;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(Stack* stack, double item) {
    stack->array[++stack->top] = item;
}

// Pop an element from the stack
double pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return -1; // Error: Stack is empty
}


void printCharStack(CharStack* stack) {
    if (isEmptyChar(stack)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack contents: ");
    int i;
    for (i = 0; i <= stack->top; ++i) {
        printf("%c ", stack->array[i]);
    }
    printf("\n");
}

// Initialize a character stack
CharStack* initializeCharStack(int size) {
    CharStack* stack = (CharStack*)malloc(sizeof(CharStack));
    stack->top = -1;
    stack->array = (char*)malloc(size * sizeof(char));
    return stack;
}

// Check if the character stack is empty
int isEmptyChar(CharStack* stack) {
    return stack->top == -1;
}

// Push a character onto the character stack
void pushChar(CharStack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Pop a character from the character stack
char popChar(CharStack* stack) {
    if (!isEmptyChar(stack)) {
        return stack->array[stack->top--];
    }
    return '\0'; // Error: Stack is empty
}

char * turnEXP(char * str){
     int len = strlen(str);
    char* resultt =(char*)malloc((2 * len + 1) * sizeof(char));
    char * txt=(char*)malloc((2 * len + 1) * sizeof(char));
    char* tmp = (char*)malloc((2 * len + 1) * sizeof(char)); // Maximum size after transformation
    int i=0;
    int s=0;
    int nbr=1;
    int j=0;
   for(i=0;i<strlen(str);i++){
    if(isdigit(str[i]) && str[i+1]!='.'){
      
      tmp[j]=str[i];
      j++;
    }
    else if(str[i]=='+' || str[i]=='*' || str[i]=='-' || str[i]=='/'){
      
      tmp[j]=str[i];
      j++;
    }
    else if(isdigit(str[i]) && str[i+1] == '.'){
     
      tmp[j]=str[i];
      j++;
      i=i+2;
      nbr=1;
      while(isdigit(str[i])){
              tmp[j]=str[i];
                nbr=nbr*10;
                j++;
                i++;
                
            }
            
            tmp[j]='/';
            j++;
            char nbrStr[20]; // Assuming maximum digits for an integer

            
            sprintf(nbrStr, "%d", nbr);
            for (s = 0; s < strlen(nbrStr); s++) {
                tmp[j] = nbrStr[s];
                
                j++;
            }
            i--;
            
    }
   
   } //printf("%s\n",tmp);
    return tmp;

}
// Get the precedence of an operator
int getPrecedence(char operatorr) {
    if (operatorr == '+' || operatorr == '-')
        return 1;
    else if (operatorr == '*' || operatorr == '/')
        return 2;
    return 0; // For parentheses or other characters
}

// Convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    CharStack* stack = initializeCharStack(strlen(infix));
    int i, j = 0;

    for (i = 0; infix[i]; ++i) {
        if (isdigit(infix[i])) {
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            --i;
        } else if (infix[i] == '(') {
            pushChar(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmptyChar(stack) && stack->array[stack->top] != '(') {
                postfix[j++] = popChar(stack);
                postfix[j++] = ' ';
            }
            popChar(stack); // Pop the '('
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            while (!isEmptyChar(stack) && getPrecedence(infix[i]) <= getPrecedence(stack->array[stack->top])) {
                postfix[j++] = popChar(stack);
                postfix[j++] = ' ';
            }
            pushChar(stack, infix[i]);
        }
    }

    while (!isEmptyChar(stack)) {
        postfix[j++] = popChar(stack);
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';

    free(stack->array);
    free(stack);
}
char* replaceStringIncrementDecrement(char* input) {
    // printf("Input: %s\n", input);

    // Check if the input is valid
    if (input == NULL) {
        return NULL;
    }

    // Initialize an empty string
    char* output = (char*)malloc(strlen(input) * 3 + 1);
    output[0] = '\0';

    // Find occurrences of "+"
    if (input[0] == '+') {
        if (input[1] == '+') {
            printf("Affectation var %s\n", symbol_table[Affvar].id_name);
            strcat(output, symbol_table[Affvar].id_name);
            strcat(output, "+1");
            return output;
        }
    } else if (input[0] == '-') {
        if (input[1] == '-') {
            strcat(output, symbol_table[Affvar].id_name);
            strcat(output, "-1");
            return output;
        }
    } else {
        return input;
    }
}

// Function to evaluate an expression
double evaluateExpression(char* expression) {
    Stack* stack = initializeStack(strlen(expression));
    int i;
   // printf("expression : %s \n", expression);
    for (i = 0; expression[i]; ++i) {
        if (isdigit(expression[i])) {
            double operand = 0;
            while (isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                ++i;
            }
            --i;
            push(stack, operand);
            //printf("firstOperand : %lf", operand);
           // printStack(stack);
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            double operand2 = pop(stack);
            double operand1 = pop(stack);

           // printStack(stack);

            switch (expression[i]) {
                case '+':
                    //printf("%lf + %lf = %lf\n", operand1, operand2, operand1 + operand2);
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0) {
                        push(stack, operand1 / operand2);
                    } else {
                        //printf("Error: Division by zero\n");
                        free(stack->array);
                        free(stack);
                        return -1;
                    }
                    break;
                //printStack(stack);
            }
        }
    }

    double result = pop(stack);
    //printStack(stack);

    //printf("result : %lf\n", result);
    if (!isEmpty(stack)) {
        printf("Error: Malformed expression\n");
        result = -1;
    }

    free(stack->array);
    free(stack);

    return result;
}

void insert(char * str,char *string){
  
   symbol_table[count].id_name=strdup(yytext);
   symbol_table[count].data_type=string;
}

const char* detectNumberType(double value) {
    
    // Check if the difference between the value and its rounded version is very small
    if (fabs(value - round(value)) < 1e-10) {
        return "int";
    } else {
        return "float";
    }
}

void addval(int x, char* expression) {
     int i,c,t;
     int j=0;
     char * nme = (char*)malloc((2 * 10 + 1) * sizeof(char));
     char* variableName = (char*)malloc((100 + 1) * sizeof(char));
      nme[0] = '\0';
        int q=0;
        int y;
    if (strcmp(symbol_table[Affvar].data_type, "bool") == 0) {
        // For boolean type, no need to evaluate the expression
        // printf("%d ligne: data_type %s (no evaluation for boolean type)\n", nb_ligne, symbol_table[Affvar].data_type);
        // Handle the assignment logic based on your requirements for boolean types
        // You might want to check if the expression is "true" or "false"
        symbol_table[Affvar].boolVal =strdup(expression) ;
    } else {
       
       
        char  tmp[100];
        for (i=0;i<strlen(expression);i++){
            j=0;
            y=0;
             
            if(expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '/' && expression[i] != '.' && !isdigit(expression[i])){
                
               while (j < strlen(expression) && (isalpha(expression[i]) || expression[i] == '_')){
                    variableName[j] = expression[i];
                    j++;
                    i++;
                    y=1;
                }
                if(y==1) i--;
                variableName[j] = '\0'; 
                //printf("\nhere %s\n",variableName);
            // Convert a single char to a string
            
               // printf("hey %s\n",nme);
                c=search(variableName);
               // printf("%d",c);
                if(c!=-1){
                int written = sprintf(tmp + q, "%lf", symbol_table[c].ValNUm);
                if (written < 0) {
                    // Handle conversion error if needed
                } else {
                    q += written;
                }  
                }
                else{
                   // printf("valeur du idf %s est null ;",symbol_table[c].id_name);
                }
            }
            else{
                tmp[q]=expression[i];
                q++;
            }
            
        }
        strcpy(expression, tmp);

    // Print or use the modified expression as needed
    //printf("\nModified Expression: %s\n", expression);
        expression = turnEXP(expression);
        
        infixToPostfix(expression, postfixExpression);
        //printf("%s",expression);
        double result = evaluateExpression(postfixExpression);

        //printf("%d ligne: data_type %s and result type %s\n", nb_ligne, symbol_table[Affvar].data_type, detectNumberType(result));

        if (strcmp(symbol_table[Affvar].data_type, "int") == 0 && strcmp(detectNumberType(result), "float") == 0) {
           errS=1; printf("%d ligne: Semantic error - assigning float to an integer\n", nb_ligne);
        }

        symbol_table[Affvar].ValNUm = result;
         symbol_table[Affvar].boolVal = "0";
    }
}
void insert_type() {
strcpy(type, yytext);
}
// bool checkConst(){
  
// }
void handleDecCst(char * cst){
  q=search(cst);
  // symbol_table[q].ValNUm=strdup(yytext);
  symbol_table[q].str=strdup(yytext);
  char * expression  ;
  
  if (strcmp(symbol_table[q].data_type, "bool") == 0) {
        // For boolean type, no need to evaluate the expression
        // printf("%d ligne: data_type %s (no evaluation for boolean type)\n", nb_ligne, symbol_table[q].data_type);
        // Handle the assignment logic based on your requirements for boolean types
        // You might want to check if the expression is "true" or "false"
        symbol_table[q].boolVal =strdup(yytext) ;
    } else {

        expression = turnEXP(yytext);
        
        infixToPostfix(expression, postfixExpression);
       // printf("\n exp %s \n",postfixExpression);
        double result = evaluateExpression(postfixExpression);

        //printf("%d ligne: data_type %s and result %lf type %s\n", nb_ligne, symbol_table[q].data_type, result,detectNumberType(result));

        if (strcmp(symbol_table[q].data_type, "int") == 0 && strcmp(detectNumberType(result), "float") == 0) {
            errS=1;
            printf("%d ligne: Semantic error - assigning float to an integer\n", nb_ligne);
        }

        symbol_table[q].ValNUm = result;
         symbol_table[q].boolVal = "0";
    }
}
void handleAffectation(){
    
  search(yytext);
  if(q==-1) {
    Affvar = -1;
    }
  else{
    Affvar =q;
    // printf("%d idf exist with index %d \n" , nb_ligne ,q) ;
    if( strcmp(strdup("Constante") ,symbol_table[q].type)==0){
      errS=1;
      printf("%d symentic error -> affectation to const "ANSI_COLOR_PINK  " %s "ANSI_COLOR_RESET " \n\n" , nb_ligne , symbol_table[q].id_name) ;
    } 
    
  }
  // if(checkConst()){printf('Changement de valeur d’une constante')} ;
}
// here fixed , adding to symbolic table only idf's in the declaration phase and keywords  
void add(char str) {
  q=search(yytext);
  
  if (q==-1) {
    if(declarationPhase ==0 && str!='K'){
        errS=1;
      printf("%d symentic error -> idf"ANSI_COLOR_PINK  " %s "ANSI_COLOR_RESET "not declared \n\n" ,nb_ligne,yytext) ;
    }
    if(str=='V' && declarationPhase==1){
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=nb_ligne;
			symbol_table[count].type=strdup("Variable");
      symbol_table[count].str="/";
 
			count++;
    }
    else if(str=='C' && declarationPhase==1){
      
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=nb_ligne;
			symbol_table[count].type=strdup("Constante");      
      symbol_table[count].str="/";
			count++;
    }
    else if(str == 'K') {
			
			symbol_table[count].data_type=strdup("N/A");
			symbol_table[count].line_no=nb_ligne;
			symbol_table[count].type=strdup("Keyword\t");
      symbol_table[count].str="/";
			count++;
		}
  }
  else{
    if(declarationPhase==1){
        errS=1;
      printf("line :%d symentic error --> IDF %s already declared\n" , nb_ligne , symbol_table[q].id_name);
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
          // if(symbol_table[i].str=="0") { symbol_table[i].ValNUm=0;}
            return i;  // Return the index of the found identifier
        }
    }
    return -1;  // Identifier not found
}

void afficher(){
  printf("\n\n");
  if(errS!=1){
	printf(ANSI_COLOR_YELLOW "\nNAME           DATATYPE         TYPE        LINE NUMBER           VALUE \n"ANSI_COLOR_RESET);
	printf("________________________________________________________________________________\n\n");
	int i=0;
	for (i = 0; i < count; i++) {
    if (symbol_table[i].boolVal != NULL && strcmp(symbol_table[i].boolVal, "0") != 0) {
        printf("%s\t\t%s\t\t%s\t\t%d\t\t%s\t\t \n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no, symbol_table[i].boolVal );
    } else {
        printf("%s\t\t%s\t\t%s\t\t%d\t\t%lf\t\t \n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no, symbol_table[i].ValNUm );
    }
  }
	for(i=0;i<count;i++) {
		free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}
	printf("\n\n");}
}
yywrap()
{}
void yyerror(const char* msg) {
  fprintf(stderr, "\nError: %s ligne %d\n ", msg,nb_ligne-1);
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
