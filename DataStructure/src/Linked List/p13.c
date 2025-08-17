//
// Created by Kishi Kishore N on 17/08/25.
//
#include <stdio.h>
// finding middle element in given linked list

struct Node {
    int data;
    struct Node *next;
};

struct Node* middle(struct Node *head);

int main() {
    // struct Node n6 ={6,NULL};
    struct Node n5 ={5,NULL};
    struct Node n4 ={4,&n5};
    struct Node n3 ={3,&n4};
    struct Node n2 ={2,&n3};
    struct Node n1 ={1,&n2};

    struct Node *Head = &n1;

    struct Node *middleptr = middle(Head);

    while (middleptr != NULL) {
        printf("%d\n",middleptr->data);
        middleptr = middleptr->next;
    }
    return 0;
}

struct Node* middle(struct Node *head) {
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}