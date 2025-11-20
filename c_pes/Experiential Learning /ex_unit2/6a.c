#include <stdio.h>
#define Max 5

struct queue{
    int front;
    int rear;
    int arr[Max];
};

int isFull(struct queue* q);
int isEmpty(struct queue* q);
void enque(struct queue* q,int data);
int deque(struct queue* q);
void display(struct queue* q);

int main(){
    struct queue queue;
    queue.front=-1;
    queue.rear =-1;
    
    struct queue* q = &queue;
    
    enque(q,1);
    enque(q,2);
    enque(q,3);
    enque(q,4);
    display(q);
    deque(q);
    deque(q);
    deque(q);
    deque(q);
    enque(q,1);
    enque(q,2);
    enque(q,3);
    display(q);
    
    
    return 0;
}

int isFull(struct queue* q){
    return q->rear == Max-1;
}

int isEmpty(struct queue* q){
    return q->front == -1;
}

void enque(struct queue* q,int data){
    if(!isFull(q)){
        if(q->front == -1 && q->rear == -1){
            q->front = 0;
        }
        q->arr[++(q->rear)] = data;
    }else{
        printf("queue is full !\n");
    }
}

int deque(struct queue* q){
    if(!isEmpty(q)){
        if(q->rear == q->front){
            int ele = q->arr[q->rear];
            q->rear = -1;
            q->front = -1;
            return ele;
        }else{
            int ele = q->arr[(q->front)++];
            return ele;
        }
    }else{
        printf("queue is empty\n");
        return -1;
    }
}

void display(struct queue* q){
    int n = q->rear;
    int i = q->front;
    while(i<=n){
        printf("%d-",q->arr[i]);
        i++;
    }
    printf("\n");
}
