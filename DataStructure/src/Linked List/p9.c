//
// Created by Kishi Kishore N on 16/08/25.
//
#include <stdio.h>
#include <stdlib.h>
// given a pointer to a node , insert an element after that node

struct Node {
    int data;
    struct Node *next;
};

struct Node* insertion(struct Node *head, int element);

int main() {
    struct Node n5 = {5,NULL};
    struct Node n4 = {4,&n5};
    struct Node n3 = {3,&n4};
    struct Node n2 = {2,&n3};
    struct Node n1 = {1,&n2};

    struct Node *Head = &n1;

    struct Node *result = insertion(Head,15);

    while (result != NULL) {
        printf("%d\n",result->data);
        result = result->next;
    }

    return 0;
}

struct Node* insertion(struct Node *head, int element) {
    struct Node *newNode= malloc(sizeof( struct Node));
    newNode ->data = element;


    struct Node *temp = head;
    struct Node *ref = temp->next;
    temp->next = newNode;
    newNode ->next = ref;

    return head;
}