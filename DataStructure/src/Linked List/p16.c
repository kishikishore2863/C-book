//
// Created by Kishi Kishore N on 17/08/25.
//
#include <stdio.h>
//detect a loop in linked list
typedef struct node {
    int data;
    struct node *next;
}LinkedNode;

int detect(LinkedNode *head);

int main() {
    LinkedNode n5 = {5, NULL};
    LinkedNode n4 = {4, &n5};
    LinkedNode n3 = {3, &n4};
    LinkedNode n2 = {2, &n3};
    LinkedNode n1 = {1, &n2};

    LinkedNode *Head = &n1;
    n5.next = &n2;

    int result = detect(Head);

    result ==0?printf("LinkedList no loop detected"):printf(" LinkedList detected loop");

    return 0;
}

int detect(LinkedNode *head) {
    if (head == NULL || head->next == NULL)return 0;

    LinkedNode *slow = head;
    LinkedNode *fast = head;

   while (fast->next != NULL && fast->next->next != NULL ) {
       slow =slow ->next;
       fast =fast ->next->next;
       if (slow == fast)return 1;
   }

   return 0;
}