//
// Created by Kishi Kishore N on 16/08/25.
//
#include <stdio.h>
#include <stdlib.h>
// insert node at the beginning

struct Node {
    int data;
    struct Node *next;
};

struct Node* Insert_at_begin(struct Node *start,int key);

int main() {
    struct Node n5 = {5,NULL};
    struct Node n4 = {4,&n5};
    struct Node n3 = {3,&n4};
    struct Node n2 = {2,&n3};
    struct Node n1 = {1,&n2};

    struct Node *start = &n1;

    int key =9;
    struct Node *result = Insert_at_begin(start,key);

    while (result != NULL) {
        printf("%d\n", result->data);
        result = result->next;
    }

}

struct Node* Insert_at_begin(struct Node *start,int key) {
    struct Node *temp = malloc(sizeof(struct  Node));

    if (temp != NULL) {
        temp->data = key;
        temp->next = start;
    }
    return temp;
}
