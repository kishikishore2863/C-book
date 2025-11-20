#include <stdio.h>
#define Max 5

struct Queue{
  int front;
  int rear;
  int arr[Max];
    
};

int isFull(struct Queue* q);
int isEmpty(struct Queue* q);
void enque(struct Queue* q,int data);
int deque(struct Queue* q);
void display(struct Queue* q);


int main(){
    struct Queue queue;
    queue.front =-1;
    queue.rear = -1;
    struct Queue* q  = &queue;
    enque(q,1);
    enque(q,2);
    enque(q,3);
    enque(q,4);
    enque(q,5);
    deque(q);
    enque(q,6);
    display(q);
    
    return 0;
}

int isFull(struct Queue* q){
    return (q->rear+1)%Max == q->front;
}

int isEmpty(struct Queue* q){
    return q->front == -1;
}

void enque(struct Queue* q,int data){
    if(!isFull(q)){
        if(q->front == -1){
            q->front =0;
        }
        q->rear = (q->rear+1)%Max;
        q->arr[q->rear] = data;
    }else{
        printf("queue is full\n");
    }
    
}

int deque(struct Queue* q){
    if(!isEmpty(q)){
        if(q->rear == q->front){
            int ele = q->arr[q->front];
            q->rear = -1;
            q->front=-1;
            return ele;
        }else{
            int ele = q->arr[q->front];
            q->front =(q->front+1)%Max;
            return ele;
        }
    }else{
        printf("queue is empty!\n");
    }
}

void display(struct Queue* q){
    int front =q->front;
    int rear = q->rear;
    
    while(front != rear){
        printf("%d - ",q->arr[front]);
        front =(front+1)%Max;
    }
    printf("%d\n",q->arr[rear]);
    
}