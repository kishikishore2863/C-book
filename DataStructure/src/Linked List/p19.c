//
// Created by Kishi Kishore N on 18/08/25.
//
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* head);

int main() {
    struct ListNode b6 = {6, NULL};
    struct ListNode b5 = {5, &b6};
    struct ListNode b4 = {4, &b5};
    struct ListNode b3 = {3, &b4};
    struct ListNode b2 = {2, &b3};
    struct ListNode b1 = {1, &b2};

    struct ListNode *head = &b1;


    struct ListNode *result = oddEvenList(head);

    while (result!=NULL) {
        printf("%d",result->val);
        result = result->next;
    }

    return 0;
}


struct ListNode* oddEvenList(struct ListNode* head) {

    struct ListNode even = {-1,NULL};
    struct ListNode odd = {-1,NULL};

    struct ListNode *ep = &even;
    struct ListNode *op = &odd;

    struct ListNode *trav =head;

    while(trav!=NULL){
        if(trav->val %2 == 0){
            ep->next = trav;
            ep = ep->next;
            trav = trav->next;
        }else{
            op->next = trav;
            op = op->next;
            trav = trav->next;
        }
    }
    ep->next= NULL;

    op->next = even.next;

    return odd.next;

}