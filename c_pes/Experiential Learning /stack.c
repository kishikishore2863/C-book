//
// Created by Kishi Kishore N on 06/11/25.
//
#include <stdio.h>
#define MAX 10

struct stack {
    int top;
    int arr[MAX];
};

int isEmpty(struct stack *stack);

int isFull(struct stack *stack);

void push(struct stack *stack, int data);

int peek(struct stack *stack);

int pop(struct stack *stack);

void display(struct stack *stack);

void infixToPostfix(char* infix, char* postfix, struct stack* s);

int main() {
    struct stack s1;
    s1.top = -1;
    struct stack *stack = &s1;
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    display(stack);
    int res = pop(stack);
    display(stack);
    int peek1 = peek(stack);
    printf("%d\n", res);
    printf("%d", peek1);
    // Infix to Postfix conversion
    printf("\n");
    char infix[100], postfix[100];
    printf("Enter infix expression: ");
    scanf(" %[^\n]s", infix);
    struct stack s2;
    s2.top = -1;
    infixToPostfix(infix, postfix, &s2);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}


int isEmpty(struct stack *stack) {
    return stack->top == -1;
}

int isFull(struct stack *stack) {
    return stack->top == 9;
}

void push(struct stack *stack, int data) {
    if (!isFull(stack)) {
        stack->arr[++(stack->top)] = data;
    } else {
        printf("Stack overflow\n");
    }
}

int peek(struct stack *stack) {
    int elem = stack->arr[stack->top];
    return elem;
}

int pop(struct stack *stack) {
    if (!isEmpty(stack)) {
        int elem = stack->arr[stack->top];
        (stack->top)--;
        return elem;
    }
    printf("Stack underflow\n");

    return -1;
}

void display(struct stack *stack) {
    int temp = stack->top;
    while (temp >= 0) {
        printf("%d", stack->arr[temp]);
        temp--;
    }
    printf("\n");
}

// Helper functions for infix to postfix conversion
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void infixToPostfix(char* infix, char* postfix, struct stack* s) {
    int i = 0, j = 0;
    char ch;
    char opStack[MAX];
    s->top = -1;
    while ((ch = infix[i++]) != '\0') {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(s, ch);
        } else if (ch == ')') {
            while (!isEmpty(s) && peek(s) != '(') {
                postfix[j++] = pop(s);
            }
            if (!isEmpty(s) && peek(s) == '(') {
                pop(s); // Remove '('
            }
        } else if (isOperator(ch)) {
            while (!isEmpty(s) && isOperator(peek(s)) &&
                   ((precedence(ch) < precedence(peek(s))) ||
                    (precedence(ch) == precedence(peek(s)) && ch != '^'))) {
                postfix[j++] = pop(s);
            }
            push(s, ch);
        }
    }
    while (!isEmpty(s)) {
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
}
