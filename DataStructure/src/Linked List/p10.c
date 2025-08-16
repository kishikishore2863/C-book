//
// Created by Kishi Kishore N on 16/08/25.
//
#include <stdio.h>
// Deletion of an element(node)

struct Node {
    int data;
    struct Node *next;
};
struct Node* deletion(struct Node *head, int nodeEle);

int main() {
    struct Node n5 ={5,NULL};
    struct Node n4 ={4,&n5};
    struct Node n3 ={3,&n4};
    struct Node n2 ={2,&n3};
    struct Node n1 ={1,&n2};

    struct Node *Head = &n1;


    struct Node *result = deletion(Head,5);

    while (result != NULL) {
        printf("%d\n", result->data);
        result = result->next;
    }


    return 0;
}

struct Node* deletion(struct Node *head, int nodeEle) {
    if (head == NULL) {
        return head;
    }

    struct Node *temp=head;

    while (head != NULL && head != NULL) {
        if (head->next->data == nodeEle) {
            break;
        }
        head = head->next;
    }


    if (head->next->next != NULL) {
        struct Node *ref = head->next->next;
        head->next = ref;
    }

    return temp;

}