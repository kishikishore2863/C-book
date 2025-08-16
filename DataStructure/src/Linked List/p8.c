//
// Created by Kishi Kishore N on 16/08/25.
//
#include <stdio.h>
#include <stdlib.h>

//insertion at end

struct Node {
    int data;
    struct Node *next;
};

struct Node* insert_at_end(struct Node *head, int data);

int main() {
    struct Node n5 = {5,NULL};
    struct Node n4 = {4,&n5};
    struct Node n3 = {3,&n4};
    struct Node n2 = {2,&n3};
    struct Node n1 = {1,&n2};
    struct Node *Head = &n1;

    struct Node *result = insert_at_end(Head,10);

    while (result != NULL) {
        printf("%d\n",result->data);
        result = result->next;
    }

    return 0;
}

struct Node* insert_at_end(struct Node *head, int data) {
    struct Node *result = head;
    struct Node *temp = malloc(sizeof( struct Node));
    if (temp != NULL) {
        while (head->next != NULL ) {
            head = head->next;
        }
        temp->data  = data;
        temp->next = NULL;
        head ->next = temp;
    }
    return result;
}