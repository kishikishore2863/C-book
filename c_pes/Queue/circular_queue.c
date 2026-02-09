//
// Created by Kishi Kishore N on 07/02/26.
//
#include <stdio.h>
#include<stdlib.h>
#define MAX 10

struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

void inita(struct Queue* q) {
    q->front = -1;
    q->rear =-1;
}

int isFull(struct Queue* q) {
    return (q->rear+1) %MAX == q->front;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enque(struct Queue* q,int val) {
    if (isFull(q)) {
        printf("queue is full ");
    }else {

        if (q->front == -1) {
            q->front =0;
        }
        q->rear = (q->rear+1) %MAX;
        q->arr[q->rear] = val;
    }
}

int deque(struct Queue* q) {
    if (!isEmpty(q)) {
        if (q->front == q->rear) {
            int temp =q->arr[q->front];
            q->front = -1;
            q->rear = -1;
            return temp;
        }
        int temp = q->arr[q->front];
        q->front = (q->front+1)%MAX;
        return temp;
    }else {
        printf("is empty");
        return -1;
    }
}

void displayQ(struct Queue *q){
    int i;
    for (i=q->front; i!=q->rear; i = (i+1)%MAX) {
        printf("%d ",q->arr[i]);
    }
    printf("%d",q->arr[i]);
    printf("\n");
}



int main() {
    struct  Queue q;
    inita(&q);

    enque(&q,1);
    enque(&q,2);
    enque(&q,3);
    enque(&q,4);
    enque(&q,5);
    enque(&q,6);
    enque(&q,7);
    enque(&q,8);
    enque(&q,9);
    enque(&q,10);
    deque(&q);
    enque(&q,12);






    displayQ(&q);


}
