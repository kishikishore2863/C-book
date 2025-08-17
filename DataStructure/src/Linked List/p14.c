//
// Created by Kishi Kishore N on 17/08/25.
//
#include <stdio.h>
//printing linked list in reverse order

typedef struct node{
    int data;
    struct node *next;
}Node;

void printer(Node *head);
int main() {
     Node n5 ={5,NULL};
     Node n4 ={4,&n5};
     Node n3 ={3,&n4};
     Node n2 ={2,&n3};
     Node n1 ={1,&n2};

     Node *Head = &n1;
    printer(Head);
    return 0;
}

void printer(Node *head) {
    if (head == NULL)return;
    printer(head->next);
    printf("%d\n",head->data);
}