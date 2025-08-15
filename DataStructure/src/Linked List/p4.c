//
// Created by Kishi Kishore N on 15/08/25.
//
#include <stdio.h>
// given a linked list, print data in second last node

struct Node {
    int data;
    struct Node *next;
};

int solve(struct Node *Head);

void main() {
    struct Node node4={4,NULL};
    struct Node node3={3,&node4};
    struct Node node2={2,&node3};
    struct Node node1={5,&node2};

    struct Node *HEAD = &node1;
    int result = solve(HEAD);
    printf("%d",result);
}

int solve(struct Node *Head) {
    if (Head == NULL || Head->next ==NULL) {
        return -1;
    }

    while (Head->next->next != NULL) {
        Head = Head->next;
    }

    return Head->data;
}



