// expression_evaluator.h


#ifndef STACKK_H
#define STACKK_H
// Structure to represent a stack
typedef struct {
    int top;
    double* array;
} Stack;

// Structure to represent a character stack
typedef struct {
    int top;
    char* array;
} CharStack;

void printStack(Stack* stack);
void printCharStack(CharStack* stack);

Stack* initializeStack(int size);
int isEmpty(Stack* stack);
void push(Stack* stack, double item);
double pop(Stack* stack);

CharStack* initializeCharStack(int size);
int isEmptyChar(CharStack* stack);
void pushChar(CharStack* stack, char item);
char popChar(CharStack* stack);

int getPrecedence(char operatorr);

void infixToPostfix(char* infix, char* postfix);

double evaluateExpression(char* expression);

#endif // STACKK_H