//
// Created by Kishi Kishore N on 15/08/25.
//
#include <stdio.h>
// given a linked list ,count the number of nodes in linkedlist

struct Node {
    int data;
    struct Node *next;
};
struct Node *START = NULL;

int counter(struct Node*);
int main() {
    int result = counter(START);
    printf("%d", result);
    return 0;
}

int counter(struct Node *ptr) {
    int count=0;
    while (ptr != NULL) {
        count++;
        ptr= ptr->next;
    }
    return count;
}