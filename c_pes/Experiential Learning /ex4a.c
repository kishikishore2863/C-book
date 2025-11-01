#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;

};

struct node* insert_front( struct node* head ,int data);
struct node* insert_rear(struct node* head, int data);
struct node* delete_front(struct node* head);
struct node* delete_rear(struct node* head);
void display(struct node* head);
int dashBoard();
int nextOption();
void optionSelector(int option,struct node** mainHead);
void display_reverse(struct node* head);

int main(){

    struct node *head = NULL;
    int option = dashBoard();

    while(option!=9){
       optionSelector(option,&head);
       option=nextOption();
    }

    return 0;
}

int dashBoard(){
    printf("\tWELCOME TO DOUBLY LINKED LIST PLAYGROUND\n");
    printf("\n");
    printf("option 1: Insert Node at FRONT\n");
    printf("option 2: Insert Node at REAR\n");
    printf("option 3: Delete Node at FRONT\n");
    printf("option 4: Delete Node at REAR\n");
    printf("option 5: Display the list\n");
    printf("option 6: Display the list(REVERSE) \n");
    printf("option 9: EXIT\n");
    int option;
    printf(">>");
    scanf("%d",&option);
    return option;
}

int nextOption(){
    int option;
    printf(">>");
    scanf("%d",&option);
    return option;
}

void optionSelector(int option,struct node** mainHead){
    if(option == 1){
        printf("enter a data:");
        int data;
        scanf("%d",&data);
        *mainHead =insert_front( *mainHead, data);
    }
    if(option ==2){
        printf("enter a data:");
        int data;
        scanf("%d",&data);
        *mainHead=insert_rear( *mainHead, data);
    }
    if(option ==3){
        *mainHead=delete_front(*mainHead);
    }
    if(option == 4){
        *mainHead=delete_rear(*mainHead);
    }
    if(option == 6){
        display_reverse(*mainHead);
    }

    if(option == 5){
        display(*mainHead);
    }
}



struct node* insert_front( struct node* head ,int data){
    struct node* nn = malloc(sizeof(struct node));
    if(head == NULL){
        nn->next =NULL;
        nn->prev =NULL;
        nn->data = data;
        return nn;
    }
    nn->next = head;
    nn->prev = NULL;
    head->prev =nn;
    nn->data = data;
    return nn;
}

struct node* insert_rear(struct node* head, int data){
    struct node* nn = malloc(sizeof(struct node));
        if(head == NULL){
        nn->next =NULL;
        nn->prev =NULL;
        nn->data = data;
        return nn;
    }
    struct node* curr = head;
    while(curr->next!=NULL){
        curr = curr->next;
    }
    curr->next = nn;
    nn->next = NULL;
    nn->prev = curr;
    nn->data = data;
    return head;
}


struct node* delete_front(struct node* head){
    if(head == NULL ){
        printf("EMPTY List\n");
        return NULL;
    }
    if(head->next == NULL){
        return NULL;
    }

    struct node* refHead = head->next;
    refHead->prev = NULL;
    return refHead;
}

struct node* delete_rear(struct node* head){
    if(head == NULL ){
        printf("EMPTY List\n");
        return NULL;
    }
    if(head->next == NULL){
        return NULL;
    }
    struct node* curr=head;
    while(curr->next->next!=NULL){
        curr = curr->next;
    }
    curr->next = NULL;
    return head;
}

void display(struct node* head){

    struct node* curr = head;
    while(curr!=NULL){
        printf(" %d <->",curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}


void display_reverse(struct node* head){
    struct node* curr = head;
    while(curr->next !=NULL){
        curr=curr->next;
    }
    while(curr!=NULL){
        printf("%d <->",curr->data);
        curr=curr->prev;
    }
    printf("NULL\n");
}

