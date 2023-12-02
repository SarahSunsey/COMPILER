#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to represent a stack
typedef struct {
    int top;
    double* array;
} Stack;

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

// Function to evaluate an expression
double evaluateExpression(char* expression) {
    Stack* stack = initializeStack(strlen(expression));
    int i;
    printf("expression : %s \n", expression);
    for (i = 0; expression[i]; ++i) {
        if (isdigit(expression[i])) {
            double operand = 0;
            while (isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                ++i;
            }
            --i;
            push(stack, operand);
            printf("firstOperand : %lf" , operand); 
            printStack(stack);
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            double operand2 = pop(stack);
            double operand1=pop(stack);

            // if (isEmpty(stack)) {
            //     // Handle the case when the stack is empty
            //     if (expression[i] == '+' || expression[i] == '-') {
            //         operand1 = 0;
            //     } else {
            //         operand1 = 1;
            //     }
            // } else {
            //     operand1 = pop(stack);
            // }

            printStack(stack);

            switch (expression[i]) {
                case '+':
                    printf("%lf + %lf = %lf\n" ,operand1 , operand2 ,operand1 + operand2) ; 
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
                        printf("Error: Division by zero\n");
                        free(stack->array);
                        free(stack);
                        return -1;
                    }
                    break;
                printStack(stack);
            }
        }
    }

    double result = pop(stack);
    printStack(stack);

    printf("result : %lf\n", result);
    if (!isEmpty(stack)) {
        printf("Error: Malformed expression\n");
        result = -1;
    }

    free(stack->array);
    free(stack);

    return result;
}

int main() {
    char expression[100];

    printf("Enter a mathematical expression: ");
    if (fgets(expression, sizeof(expression), stdin) != NULL) {
        // Remove newline character
        char* newline = strchr(expression, '\n');
        if (newline != NULL) {
            *newline = '\0';
        }

        double result = evaluateExpression(expression);

        if (result != -1) {
            printf("Result: %lf\n", result);
        }
    } else {
        printf("Error reading input\n");
    }

    return 0;
}
