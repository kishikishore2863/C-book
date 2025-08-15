//
// Created by Kishi Kishore N on 15/08/25.
//
#include <stdio.h>
// printing Alternates Nodes

struct Node {
    int data;
    struct Node *next;
};

void printer1(struct Node *Head);

int main(void) {
    struct Node n5 = {5,NULL};
    struct Node n4 = {4,&n5};
    struct Node n3 = {3,&n4};
    struct Node n2 = {2,&n3};
    struct Node n1 = {1,&n2};

    struct Node *START = &n1;
    printer1(START);
    return 0;
}

void printer1(struct Node *Head) {
    if (Head == NULL) {
        return;
    }
    int count=1;
    while (Head != NULL) {
        count++;
        if (count%2 == 0) {
            printf("%d\n",Head->data);
        }
        Head = Head->next;
    }
}