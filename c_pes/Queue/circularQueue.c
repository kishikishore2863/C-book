//
// Created by Kishi Kishore N on 17/11/25.
//
#include <stdio.h>
#define Max 5
struct queue {
    int front;
    int rear;
    int arr[Max];
};

int isFull(struct queue* q);
int isEmpty(struct queue* q);
void enqueue(struct queue* q,int data);
int dequeue(struct queue* q);
void display(struct queue* q);


int main() {
    struct queue queue;
    struct queue* q = &queue;
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    dequeue(q);
    enqueue(q,9);
    display(q);
    return 0;
}

int isFull(struct queue* q) {
    return (q->rear+1)%Max == q->front;
}

int isEmpty(struct queue* q) {
    return q->front==-1;
}

void enqueue(struct queue* q,int data) {
    if (!isFull(q)) {
        q->rear =q ->rear+1%Max;
        q->arr[q->rear]=data;
    }else {
        printf("queue is full \n");
    }
}

int dequeue(struct queue* q) {
    if (!isEmpty(q)) {
        if (q->rear == q->front) {
            q->front =-1;
            q->rear =-1;
        }
        int element =q->arr[q->front];
        q->front = (q->front+1)%Max;
        return element;
    }else{
        printf("queue is empty\n");
        return -1;
    }
}

void display(struct queue* q) {
    int front = q->front;
    int rear = q->rear;
    while (rear!=front) {
        printf("%d",q->arr[front]);
        front = (front+1)%Max;
    }
    printf("\n");
}