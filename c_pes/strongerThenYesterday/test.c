#include <stdio.h>
#include <ctype.h>
#include <string.h>  

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = value;
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Function to evaluate postfix expression
int evalPostfix(char exp[]) {
    int i, op1, op2;

    for (i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            op2 = pop();
            op1 = pop();
            switch (exp[i]) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
    }
    return pop();
}

// Function to evaluate prefix expression
int evalPrefix(char exp[]) {
    int i = strlen(exp) - 1;
    int op1, op2;

    for (; i >= 0; i--) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            op1 = pop();
            op2 = pop();
            switch (exp[i]) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
    }
    return pop();
}

int main() {
    char postfix[100], prefix[100];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    printf("Postfix Evaluation Result: %d\n", evalPostfix(postfix));

    top = -1; // Reset stack

    printf("Enter a prefix expression: ");
    scanf("%s", prefix);
    printf("Prefix Evaluation Result: %d\n", evalPrefix(prefix));

    return 0;
}