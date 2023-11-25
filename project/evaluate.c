#include <stdio.h>
#include <stdlib.h>

// Function to evaluate an arithmetic expression and return the type of the result
void evaluateExpression(char* expression) {
    char* endptr;  
    long longResult = strtol(expression, &endptr, 10);
    double doubleResult = strtod(expression, &endptr);

    if (*endptr == '\0') {
        printf("Expression: %s, Result: %lld, Type: int\n", expression, longResult);
    } else if (doubleResult != 0.0) {
        printf("Expression: %s, Result: %f, Type: float\n", expression, doubleResult);
    } else {
        printf("Expression: %s, Result: %s, Type: string\n", expression, expression);
    }
}

// Example usage
int main() {
    char expression1[] = "3 + 4 * 2";
    char expression2[] = "10 / 3.0";
    char expression3[] = "\"Hello\"";

    evaluateExpression(expression1);
    evaluateExpression(expression2);
    evaluateExpression(expression3);

    return 0;
}
