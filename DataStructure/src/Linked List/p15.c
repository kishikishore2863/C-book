//
// Created by Kishi Kishore N on 17/08/25.
//
#include <stdio.h>
//reverse a linked list
typedef struct node {
    int data;
    struct node *next;
}LinkedNode;

struct node* reverse(LinkedNode *head);

int main() {
    LinkedNode n5 ={5,NULL};
    LinkedNode n4 ={4,&n5};
    LinkedNode n3 ={3,&n4};
    LinkedNode n2 ={2,&n3};
    LinkedNode n1 ={1,&n2};

    LinkedNode *Head = &n1;
    LinkedNode *result = reverse(Head);

    while (result != NULL) {
        printf("%d\n",result->data );
        result = result->next;
    }

    return 0;
}

struct node* reverse(LinkedNode *head) {
    if (head == NULL)return head;

    LinkedNode *prev = NULL;
    LinkedNode *curr = head;
    while (curr != NULL) {
        LinkedNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}


