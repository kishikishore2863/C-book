//
// Created by Kishi Kishore N on 16/08/25.
//
#include <stdio.h>
#include <stdlib.h>
// delete first node in a linked list


struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node n5 = {5,NULL};
    struct Node n4 = {4,&n5};
    struct Node n3 = {3,&n4};
    struct Node n2 = {2,&n3};
    struct Node n1 = {1,&n2};

    struct Node *head = &n1;


    struct node *trav = head;
    head = head->next;
    while (head !=NULL) {
        printf("%d\n",head->data);
        head=head->next;
    }
    // free(trav);
    return 0;
}

