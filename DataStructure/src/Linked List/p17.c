//
// Created by Kishi Kishore N on 18/08/25.
//
//merge 2 sorted linked list
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
}ListNode;


void printList(ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
struct ListNode* mergeSortedList( ListNode *A, ListNode *B);
int main() {

    ListNode n3 = {5, NULL};
    ListNode n2 = {3, &n3};
    ListNode n1 = {1, &n2};

    ListNode m3 = {6, NULL};
    ListNode m2 = {4, &m3};
    ListNode m1 = {2, &m2};

    ListNode *result = mergeSortedList(&n1, &m1);

    printf("Merged Sorted List: ");
    printList(result);

    return 0;
}

struct ListNode* mergeSortedList( ListNode *A, ListNode *B) {

    ListNode *a = A;
    ListNode *b = B;

     ListNode dummy = {-1, NULL};
     ListNode *res = &dummy;

    while (a!=NULL && b!=NULL) {
        if (a->data <= b->data) {
            res->next = a;
            a = a->next;
        }else {
            res->next=b;
            b=b->next;
        }
        res = res->next;
    }

    if (a==NULL) {
        res->next=b;
    }else {
        res->next=a;
    }

    return dummy.next;

}
