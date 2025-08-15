//
// Created by Kishi Kishore N on 15/08/25.
//
#include <stdio.h>
// given a linked list, print the data of last node in linked list

struct Node {
    int data;
    struct Node *next;
};

int slove(struct Node *Head);

int main() {

    struct Node node3 = {3, NULL};
    struct Node node2 = {2, &node3};
    struct Node node1 = {1, &node2};
    struct Node *START = &node1;

    int Result = slove(START);
    printf("Last node data: %d\n", Result);
    return 0;
}

int slove(struct Node *Head) {
    if (Head == NULL) {
        return -1; // empty list case
    }
    int result =0;

    while (Head != NULL) {
        if (Head->next == NULL) {
            result = Head->data;
        }
        Head = Head->next;
    }

    return result;
}
