//
// Created by Kishi Kishore N on 06/02/26.
//
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct Stack {
    int top;
    char arr[MAX];
};

int isFull(struct Stack* stack) {
    return stack->top == MAX-1;
}

int isEmpty(struct Stack* stack) {
    return stack->top <=-1;
}

void push(struct Stack* stack,char c) {
    if (!isFull(stack))stack->arr[++(stack->top)]= c;
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack))return stack->arr[stack->top--];
}

char peek(struct  Stack* stack) {
    if (!isEmpty(stack))return stack->arr[stack->top];
}

void infix_to_prefix(char* s,int size);
int prece(char c);
int main() {
    char* s = "(a+b-c)*d-(e+f)\0";
    int size =0;
    for (int i=0; i<sizeof(s)/sizeof(char); i++) {
        size++;
    }
    size++;
    infix_to_prefix(s,15);


}


int prece(char c) {
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
}

void infix_to_prefix(char* s,int size){
    struct Stack* stack =malloc(sizeof(struct Stack));
    stack->top=-1;

    char prefix[100];
    int track =0;


    for (int i=0; i<size;i++) {
        char c = s[i];
        if (c == '(') {
            push(stack,c);
        }else if (c>='a'&&c<='z') {
            prefix[track++] = c;
        }else {
            while (!isEmpty(stack)&&
                prece(peek(stack))>prece(c) &&
                peek(stack)!='('
                ) {
                prefix[track++] = pop(stack);
            }
            push(stack,c);
        }
    }
    prefix[track] = '\0';
    while (!isEmpty(stack)) {
        char op = pop(stack);
        if (op!='(') {
            prefix[track++]= op;
        }
    }
    prefix[track] = '\0';
    printf("%s",prefix);
}

