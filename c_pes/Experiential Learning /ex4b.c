#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
  struct node* prev;
};

struct node* insertion_front(struct node* head,int data);
struct node* insertion_rear(struct node* head,int data);
void display(struct node* head);
void display_reverse(struct node* head);
int people_count(struct node* head);

int main(){
    struct node n1,n2,n3,n4,n5;

    n5.data = 5;
    n4.data = 4;
    n3.data = 3;
    n2.data = 2;
    n1.data = 1;

    n5.next = &n1;
    n4.next = &n5;
    n3.next = &n4;
    n2.next = &n3;
    n1.next = &n2;

    n5.prev = &n4;
    n4.prev = &n3;
    n3.prev = &n2;
    n2.prev = &n1;
    n1.prev = &n5;

    struct node* head = &n1;
    printf("initial CLL :");
    display(head);


    printf("insertion front :");
    struct node* res = insertion_front(head,9);
    display(res);

    printf("insertion rear :");
    res = insertion_rear(res,10);
    display(res);

    printf("display reverse :");
    display_reverse(res);

    printf("***Number of people/Node:%d",people_count(res));




    return 0;
}

struct node* insertion_front(struct node* head,int data){
    struct node* nn = malloc(sizeof(struct node));
    struct node* tail =head->prev;
    nn->data = data;
    nn->next = head;
    nn->prev = tail;
    head->prev =nn;
    tail->next = nn;
    return nn;
}

struct node* insertion_rear(struct node* head,int data){
    struct node* nn = malloc(sizeof(struct node));
    struct node* tail = head->prev;
    nn->data = data;
    nn->prev = tail;
    nn->next = head;
    head->prev =nn;
    tail->next = nn;
    return head;
}

void display(struct node* head){
    struct node* curr = head->next;
    printf("%d <->",head->data);
    while(curr!=head){
        printf("%d <->",curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void display_reverse(struct node* head){
    struct node* curr = head->prev;
    while(curr!=head){
        printf("%d <->",curr->data);
        curr = curr->prev;
    }
    printf("%d",head->data);
    printf("\n");
}

int people_count(struct node* head){
    int count=1;
    struct node* curr = head->next;
    while(curr!=head){
        curr = curr->next;
        count++;
    }
    return count;
}

