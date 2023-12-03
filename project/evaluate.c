#include "stackk.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char expression[100];
    char postfixExpression[100];

    printf("Enter a mathematical expression: ");
    if (fgets(expression, sizeof(expression), stdin) != NULL) {
        // Remove newline character
        char* newline = strchr(expression, '\n');
        if (newline != NULL) {
            *newline = '\0';
        }

        infixToPostfix(expression, postfixExpression);

        printf("Infix Expression: %s\n", expression);
        printf("Postfix Expression: %s\n", postfixExpression);

        double result = evaluateExpression(postfixExpression);

        if (result != -1) {
            printf("Result: %lf\n", result);
        }
    } else {
        printf("Error reading input\n");
    }

    return 0;
}
