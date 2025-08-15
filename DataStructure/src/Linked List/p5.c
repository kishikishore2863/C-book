//
// Created by Kishi Kishore N on 15/08/25.
//
#include <stdio.h>
// Given a linked list and a key, find whether the key is present in the linked list or not

struct Node {
    int data;
    struct Node *next;
};

int search(struct Node *Head, int key);

int main(void) {
    struct Node n9 = {9,NULL};
    struct Node n8 = {8, &n9};
    struct Node n7 = {7, &n8};
    struct Node n6 = {6, &n7};
    struct Node n5 = {5, &n6};
    struct Node n4 = {4, &n5};
    struct Node n3 = {3, &n4};
    struct Node n2 = {2, &n3};
    struct Node n1 = {1, &n2};

    struct Node *START = &n1;
    int key = 8;
    int result = search(START,key);
    printf("%d",result);
    return 0;
}

int search(struct Node *Head, int key) {
    if (Head == NULL) {
        return 0;
    }

    while (Head != NULL) {
        if (Head->data == key)return 1;
        Head = Head->next;
    }

    return 0;
}