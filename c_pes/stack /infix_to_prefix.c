//
// Created by Kishi Kishore N on 06/02/26.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

struct Stack {
    int top;
    char arr[MAX];
};

struct Prefix {
    char* arr;
    int size;
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
    if (!isEmpty(stack)) return stack->arr[stack->top--];
    return '\0';
}

char peek(struct  Stack* stack) {
    if (!isEmpty(stack)) return stack->arr[stack->top];
    return '\0';
}

struct Prefix* infix_to_prefix(char* s,int size);
int prece(char c);
void reverse(char* s,int size);

int main() {
    char s[] = "(a+b-c)*d-(e+f)";
    int size =strlen(s);

    reverse(s,size);
    for (int i=0; i<size; i++) {
        if (s[i] == '(') {
            s[i] = ')';
        }else if (s[i] == ')') {
            s[i] = '(';
        }
    }

    struct Prefix* prefix =  infix_to_prefix(s,size);
    // postfix of reversed expression -> reverse to get final prefix
    reverse(prefix->arr, prefix->size);
    printf("%s\n",prefix->arr);

    free(prefix->arr);
    free(prefix);

}

void reverse(char* s,int size) {
    int start = 0;
    int end = size-1;
    while (start<end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
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

struct Prefix* infix_to_prefix(char* s,int size){
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
        }else if (c == ')'){
            while (peek(stack)!='(') {
                prefix[track++] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) == '(') {
                pop(stack);
            }
        }else {
            while (!isEmpty(stack) && peek(stack) != '(' &&
                   (prece(peek(stack)) > prece(c) ||
                    (prece(peek(stack)) == prece(c) && c != '^'))) {
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
    // printf("%s",prefix);

    struct Prefix* prefix_p = malloc(sizeof(struct Prefix));
    prefix_p->size = (int)strlen(prefix);
    prefix_p->arr = (char*)malloc((size_t)prefix_p->size + 1);
    strcpy(prefix_p->arr, prefix);

    free(stack);
    return prefix_p;
}
