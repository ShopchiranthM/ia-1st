#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

// Function to perform arithmetic or mathematical operations
double compete(double op1, double op2, char sym) {
    switch (sym) {
        case '+': return (op1 + op2);
        case '-': return (op1 - op2);
        case '*': return (op1 * op2);
        case '/': return (op1 / op2);
        case '$': 
        case '^': return (pow(op1, op2));
        default: 
            printf("Invalid operator\n");
            exit(1);  // Exit the program on invalid operator
    }
}

int main() {
    int i, top = -1;
    char postfix[20], sym;
    double s[20], op1, op2, res;
    
    printf("\nEnter postfix expression: ");
    scanf("%s", postfix);  // Corrected input

    // Evaluate the postfix expression
    for (i = 0; i < strlen(postfix); i++) {
        sym = postfix[i];

        if (isdigit(sym)) {
            // Push number onto stack (convert char to double)
            s[++top] = sym - '0';
        } else {
            // Pop two operands from the stack
            op2 = s[top--];
            op1 = s[top--];

            // Perform the operation
            res = compete(op1, op2, sym);

            // Push result onto the stack
            s[++top] = res;
        }
    }

    // The final result is the only element left in the stack
    res = s[top--];
    printf("\nThe result of the expression is: %.4f\n", res);

    return 0;  // Return statement at the end
}

