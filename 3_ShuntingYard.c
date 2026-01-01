//In this code ýve used shunting yard algorithm and made conversions. . .




#include <stdio.h>
#include <ctype.h>

// Function to check the priority of operators
int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void convertToPostfix(char* infix) {
    char stack[100];
    int top = -1;

    printf("Postfix Expression: ");

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // If it's a letter or number, print it
        if (isalnum(c)) {
            printf("%c", c);
        }
        // If it's an operator
        else {
            while (top != -1 && priority(stack[top]) >= priority(c)) {
                printf("%c", stack[top--]);
            }
            stack[++top] = c;
        }
    }

    // Pop the remaining operators from the stack
    while (top != -1) {
        printf("%c", stack[top--]);
    }
    printf("\n");
}

int main() {
    char expression[] = "a+b*c"; // Infix
    printf("Infix Expression: %s\n", expression);
    convertToPostfix(expression); // Result should be abc*+
    return 0;
}
