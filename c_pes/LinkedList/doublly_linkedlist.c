//
// Created by Kishi Kishore N on 07/02/26.
//

#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
    struct ListNode* prev;
};


struct ListNode* insert_at_begin(struct ListNode* head,int val);
struct ListNode* insert_at_end(struct ListNode* head,int val);
struct ListNode* delete_at_end(struct ListNode* head);
void display(struct ListNode* head);
int main() {
    struct ListNode* head = insert_at_begin(NULL,9);
    head = insert_at_begin(head,8);
    head = insert_at_begin(head,7);
    head = insert_at_begin(head,6);
    display(head);
    head = insert_at_end(head,10);
    display(head);
    head = delete_at_end(head);
    display(head);


    return 0;

}

struct ListNode* insert_at_begin(struct ListNode* head,int val) {
    struct ListNode* nn = malloc(sizeof(struct  ListNode));
    nn->val = val;
    nn->next = NULL;
    nn->prev = NULL;
    if (head == NULL) {
        return nn;
    }
    head->prev = nn;
    nn->next = head;

    return nn;
}

struct ListNode* insert_at_end(struct ListNode* head,int val) {
    struct ListNode* nn = malloc(sizeof(struct  ListNode));
    nn->val = val;
    nn->next = NULL;
    nn->prev = NULL;
    struct ListNode* trav   = head;
    while (trav->next!=NULL) {
        trav = trav->next;
    }
    trav->next = nn;
    nn->prev = trav->next;
    return head;
}

struct ListNode* delete_at_end(struct ListNode* head) {
    if (head == NULL)return NULL;
    if (head->next == NULL) return NULL;
    struct ListNode* trav = head;
    while (trav->next->next!=NULL) {
        trav = trav->next;
    }
    trav->next = NULL;
    return head;
}

void display(struct ListNode* head) {
    struct ListNode* head1 = head;
    while (head1!=NULL) {
        printf("%d ->",head1->val);
        head1 = head1->next;
    }
    printf("\n");

}





