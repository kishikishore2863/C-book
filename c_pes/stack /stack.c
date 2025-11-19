//
// Created by Kishi Kishore N on 17/11/25.
//
#include <stdio.h>
#include <stdlib.h>
#define Max 10

struct stack {
    int top;
    int arr[Max];
};

int isFull(struct stack* s);
int isEmpty(struct stack* s);
void push(struct stack* s,int data);
int peek(struct stack* s);
int pop(struct stack* s);

int main() {
    struct stack stack;
    stack.top = -1;
    struct stack* s = &stack;
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));



    return 0;
}

int isFull(struct stack* s) {
    return s->top == Max-1;
}

int isEmpty(struct stack* s) {
    return s->top == -1;
}

void push(struct stack* s,int data) {
    if (!isFull(s)) {
        s->arr[++(s->top)]=data;
    }else {
        printf("stack overflow\n");
    }
}

int peek(struct stack* s){
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }else {
        printf("stack is Empty\n");
        return -1;
    }
}

int pop(struct stack* s){
    if (!isEmpty(s)) {
        return  s->arr[(s->top)--];
    }else{
        printf("stack is Empty\n");
        return -1;
    }
}

