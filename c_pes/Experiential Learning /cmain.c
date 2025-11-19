//
// Created by Kishi Kishore N on 12/11/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 10
#define StackMax 50

struct book{
  int book_id;
  char title[100];
  int available_copies;
  struct book* next;
};

struct request{
    char student_name[100];
    int book_id;
};

struct queue{

  int front;
  int rear;
  struct request arr[Max];
};

struct stack{
    char actions[StackMax][200];
    int top;
};

struct book* insert_end(struct book* head,int book_id,char title[100],int available_copies);
struct book* book_by_id(struct book* head,int book_id);
struct book* update_copy_issue(struct book* head,int book_id,int val,char title[100]);
void display(struct book* head);
int isFull(struct queue* q);
int isEmpty(struct queue* q);
void Enqueue_an_issue_request(struct queue* q,int book_id, char student_name[100]);
void dequeu_and_process(struct queue* q,struct book* head ,struct stack* s);
void pop(struct stack* st);
void display_stack(struct stack* st);
void push(struct stack* st,char actions[]);



int main(){
    struct book* head =NULL;
    struct queue q;
    q.front = q.rear =-1;

    struct stack s;
    s.top =-1;

    int choice,book_id,copies;
    char title[100],student[100];

    while(1){
        printf("\n ============ SMART LIBRARY ========\n");
        printf("1.ADD Book\n");
        printf("2. Search Book\n");
        printf("3. Request Issue\n");
        printf("4. Process Next Request\n");
        printf("5. View All Data Structures\n");
        printf("6. Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter Book In:");
                scanf("%d",&book_id);

                printf("Enter Title: ");
                scanf("%[^\n]",title);

                printf("Enter Copies: ");
                scanf("%d",&copies);

                head = insert_end(head,book_id,title,copies);

                char act1[200];
                sprintf(act1,"ADD_Book %d ",book_id);
                push(&s,act1);
                break;
            case 2:
                printf("Enter Book ID:");
                scanf("%d",&book_id);

                struct book* b = book_by_id(head,book_id);
                if(b)printf("FOUND: %s(%d copies)\n",b->title,b->available_copies);
                else printf("NOT FOUND\n");

                break;
            case 3:
                printf("Enter Student name:");
                scanf("%[^\n]",student);

                printf("Enter Book ID:");
                scanf("%d",&book_id);

                Enqueue_an_issue_request(&q,book_id,student);

                char act2[200];
                sprintf(act2,"ISSUE_REQUEST %d",book_id);
                push(&s,act2);
                break;
            case 4:
                dequeu_and_process(&q,head,&s);
                break;
            case 5:
                printf("\n -- BOOK CATALOG ---\n");
                display(head);
                printf("\n --- Queue -- \n");
                if(isEmpty(&q)){
                    printf("queue Empty\n");
                }else{
                    for(int i= q.front; i<=q.rear; i++){
                        printf("%s->%d\n",q.arr[i].student_name,q.arr[i].book_id);
                    }
                }
                display_stack(&s);
                break;
            case 6:
                exit(0);
        }

    }

    return 0;
}

struct book* insert_end(struct book* head,int book_id,char title[100],int available_copies){
    if(head==NULL){
        struct book* nn = malloc(sizeof(struct book));
        nn->book_id = book_id;
        strcpy(nn->title,title);
        nn->available_copies=available_copies;
        nn->next = NULL;
        return nn;
    }

    struct book* bk = book_by_id(head,book_id);

    if(bk != NULL){
        bk->available_copies += 1;
        return head;

    }else{
        struct book* nn = malloc(sizeof(struct book));
        nn->book_id = book_id;
        strcpy(nn->title,title);
        nn->available_copies=available_copies;
        nn->next = NULL;
        struct book* curr = head;
        while(curr->next !=NULL)curr= curr->next;
        curr->next = nn;
        return head;
    }

}

struct book* book_by_id(struct book* head,int book_id){
    if(head == NULL){
        printf("BOOK NOT FOUND!\n");
        return NULL;
    }

    struct book* curr = head;
    while( curr!=NULL){
        if(curr->book_id == book_id)return curr;
        curr = curr->next;
    }

    return NULL;
}

struct book* update_copy_issue(struct book* head,int book_id,int val,char title[100]){
    struct book* bk = book_by_id(head,book_id);

    if(bk == NULL){
         return insert_end(head,book_id,title, 1);
    }
    bk->available_copies += val;
    return head;
}

void display(struct book* head){
    struct book* curr = head;
    while(curr!=NULL){
        printf("ID:%d | Title:%s | Copies:%d\n",curr->book_id,curr->title,curr->available_copies);
        curr = curr->next;
    }
}

int isFull(struct queue* q){
    return q->rear == Max-1;
}

int isEmpty(struct queue* q){
    return q->front == -1;
}

void Enqueue_an_issue_request(struct queue* q,int book_id, char student_name[100]){
    if(!isFull(q)){
        struct request rq;
        strcpy(rq.student_name,student_name);
        rq.book_id = book_id;
        if(q->front == -1)q->front =0;
        q->rear++;
        strcpy(q->arr[q->rear].student_name,student_name);
        q->arr[q->rear].book_id = book_id;

    }else{
        printf("Queue is FULL !\n");
        return;
    }
}

void dequeu_and_process(struct queue* q,struct book* head ,struct stack* s){
    char act[200];
    if(!isEmpty(q)){
        struct request res = q->arr[q->front];
        int book_id = res.book_id;
        struct book* bk = book_by_id(head,book_id);
        if(bk!=NULL && bk->available_copies >0){
            (bk->available_copies)--;
            printf("Book issued: %d \n",book_id);
            push(s,act);
        }else{
            printf("books not Available!\n");
            push(s,act);
        }
        if(q->front == q->rear)q->front = q->rear =-1;
        else q->front++;
    }else{
        printf("Queue is Empty");
    }
}

void push(struct stack* st,char actions[]){
    if(st->top == StackMax-1){
        printf("Stack is Full\n");
        return;
    }
    strcpy(st->actions[++(st->top)],actions);
}

void pop(struct stack* st){
    if(st->top == -1){
        printf("stack empty!\n");
        return;
    }
    printf("UNDO -> %s\n",st->actions[st->top--]);
}

void display_stack(struct stack* st){
    printf("\n-- ACTIVITY HISTORY --\n");
    if(st->top == -1){
        printf("NO actions yet.\n");
        return;
    }
    for(int i=st->top; i>=0; i--){
        printf("%s\n",st->actions[i]);
    }
}
