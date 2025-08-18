//
// Created by Kishi Kishore N on 18/08/25.
//
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// Intersection of Two Linked Lists


  struct ListNode {
      int val;
      struct ListNode *next;
  };

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB);

int main() {

    struct ListNode c2 = {10, NULL};
    struct ListNode c1 = {8, &c2};


    struct ListNode a2 = {7, &c1};
    struct ListNode a1 = {3, &a2};


    struct ListNode b3 = {3, &c1};
    struct ListNode b2 = {1, &b3};
    struct ListNode b1 = {99, &b2};

    struct ListNode *a = &a1;
    struct ListNode *b = &b1;

    struct ListNode* intersection = getIntersectionNode(a, b);

    if (intersection != NULL) {
        printf("Intersection at node with value: %d\n", intersection->val);
    } else {
        printf("No intersection found\n");
    }

    return 0;

}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

    struct ListNode *travA = headA;
    struct ListNode *travB = headB;
    int countA = 0;
    int countB = 0;

    while(travA != NULL){
        countA++;
        travA = travA->next;
    }
    while(travB != NULL){
        countB++;
        travB = travB->next;
    }

    travA = headA;
    travB = headB;

    printf("countA:%d , countB:%d\n",countA,countB);
    int absValue= abs(countA-countB);
    if (countA>countB){
        for (int i=0; i<absValue; i++) {
            travA= travA->next;
        }
    }else {
        for (int i=0; i<absValue; i++) {
            travB= travB->next;
        }
    }

    while (travA != NULL || travB != NULL ) {
        if (travA == travB)return travA;
        travA=travA->next;
        travB=travB->next;
    }


    return NULL;
}