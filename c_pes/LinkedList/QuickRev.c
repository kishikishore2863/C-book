//
// Created by Kishi Kishore N on 06/02/26.
//
#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* create_Linkedlist(int* pointer, int size);
struct ListNode* insert_at_begin(struct ListNode* root, int newVal);
struct ListNode* insert_at_end(struct ListNode* root, int newVal);
struct ListNode* insert_at_position(struct ListNode* root, int newVal, int position);
struct ListNode* delete_at_first(struct ListNode* root);
struct ListNode* delete_at_end(struct ListNode* root) ;
struct ListNode* delete_at_position(struct ListNode* root,int position);
void plist(struct ListNode* res);
int main() {
    int arr[] = {1,2,3,4,5};
    struct ListNode* root =create_Linkedlist(arr,5);
    struct  ListNode* res = insert_at_begin(root,678);
    struct ListNode* result =insert_at_end( res, 999);
    plist(result);
    result = insert_at_position(result, 420, 3);
    plist(result);
    result = delete_at_first(result);
    plist(result);
    result = delete_at_end(result);
    plist(result);
    result  =  delete_at_position(result,3);
    plist(result);


    return 0;
}

struct ListNode* create_Linkedlist(int* pointer, int size) {
    struct ListNode Dummy;
    Dummy.next = NULL;
    Dummy.val = -999;

    struct ListNode* point = &Dummy;
    for (int i=0; i<size; i++) {
        struct ListNode* p = malloc(sizeof(struct ListNode));
        p->val =*(pointer+i);
        p->next=NULL;
        point->next = p;
        point = point->next;
    }
    return Dummy.next;
}

struct ListNode* insert_at_begin(struct ListNode* root, int newVal) {
    struct ListNode* nn = malloc(sizeof(struct ListNode));
    nn->val = newVal;
    nn->next = root;
    return nn;
}

void plist(struct ListNode* res) {
    while (res!=NULL) {
        printf("%d->",res->val);
        res = res->next;
    }
    printf("NULL\n");
}

struct ListNode* insert_at_end(struct ListNode* root, int newVal) {
    struct ListNode* nn = malloc(sizeof(struct ListNode));
    nn->val = newVal;
    nn->next = NULL;
    struct ListNode* trav = root;
    while (trav->next!=NULL) {
        trav = trav->next;
    }
    trav->next = nn;
    return root;
}

struct ListNode* insert_at_position(struct ListNode* root, int newVal, int position) {
    struct ListNode* nn = malloc(sizeof(struct ListNode));
    nn->next = NULL;
    nn->val = newVal;

    struct ListNode* trav = root;
    int i=0;
    while(trav !=NULL && i<position-1) {
        i++;
        trav = trav->next;
    }
    if (trav == NULL) {
        printf("Not a valid position");
        return root;
    }

    if (trav->next!= NULL) {
        nn->next = trav->next;
        trav->next = nn;

    }

    return root;

}


struct ListNode* delete_at_first(struct ListNode* root) {
    if (root!=NULL) {
        return root->next;
    }else{
        return NULL;
    }
}

struct ListNode* delete_at_end(struct ListNode* root) {
    if (root == NULL )return NULL;
    if (root->next == NULL)return NULL;

    struct ListNode* trav = root;
    while (trav->next !=NULL && trav->next->next !=NULL) {
        trav  = trav->next;
    }
    trav->next =NULL;
    return root;
}

struct ListNode* delete_at_position(struct ListNode* root,int position) {
    if (root == NULL)return NULL;
    struct ListNode* res = root;
    int i=0;
    while (i<position-1 && root !=NULL) {
        root = root->next;
        i++;
    }

    if (root == NULL) {
        printf("invalid position");
        return res;
    }

    if (root->next!=NULL && root->next->next !=NULL) {
        root->next =root->next->next;
    }else {
        root->next =NULL;
    }
    return res;
}






