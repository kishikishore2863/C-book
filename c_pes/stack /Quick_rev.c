//
// Created by Kishi Kishore N on 06/02/26.
//
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct Stack {
    char arr[MAX];
    int top;
};

struct Postfix {
    char arr[MAX];
    int size;
};
int isFull(struct Stack* stack){
    return stack->top == MAX-1;
}
void push(struct Stack* stack, char val) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++(stack->top)] = val;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack)) return stack->arr[stack->top--];
    return '\0';
}

char peek(struct Stack* stack) {
    if (!isEmpty(stack)) return stack->arr[stack->top];
    return '\0';
}

struct Postfix* infix_to_postfix(char* s, int size);

int prec(const char c);
int main() {


    char* s = "(a+b-c)*d-(e+f)";
    infix_to_postfix(s,15);


}
int prec(const char c) {
    switch (c) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
    return -1;
}



struct Postfix* infix_to_postfix(char* s, int size) {
    char postfix[100];
    int track=0;

    struct Stack* stack = malloc(sizeof(struct Stack));
    stack->top = -1;


    for (int i=0; i<size; i++) {
        char c = s[i];
        if (c == '(') {
            push(stack,c);
        } else if (c == ')') {
            // pop until '(' is found
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[track++] = pop(stack);
            }
            // discard the '(' if present
            if (!isEmpty(stack) && peek(stack) == '(') {
                pop(stack);
            } else {
                printf("Mismatched parentheses\n");
            }
        } else if (c>='a' && c<='z') {
            postfix[track++] = c;
        } else {
            // pop operators with higher precedence, or equal precedence (except '^' which is right-associative)
            while (!isEmpty(stack) &&
                peek(stack) != '(' &&
                prec(peek(stack)) >= prec(c)) {
                postfix[track++] = pop(stack);
            }
            push(stack, c);
        }
    }

    // pop remaining operators
    while (!isEmpty(stack)) {
        char op = pop(stack);
        if (op != '(') {
            postfix[track++] = op;
        }
    }

    postfix[track] = '\0';
    printf("%s", postfix);

    free(stack);
    return NULL;
}