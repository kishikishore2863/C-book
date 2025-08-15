//
// Created by Kishi Kishore N on 15/08/25.
//
#include <stdio.h>

struct Node {
    int data;

}*;

void main() {
    struct Node *ptr;
    ptr = START;
    while (ptr != NULL) {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
}

void traverse(struct Node *ptr) {
    while (ptr != null) {
        printf("%d",ptr->data);
        ptr = ptr->next;
    }
}