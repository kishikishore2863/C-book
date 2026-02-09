//
// Created by Kishi Kishore N on 07/02/26.
//
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct Queue {
    int arr[MAX];
    int rear;
    int front;
};

void initial(struct Queue* queue) {
    queue->rear=-1;
    queue->front=-1;
}

int isFull(struct Queue* queue) {
    return queue->rear == MAX-1;
}

int isEmpty(struct  Queue* queue) {
    return queue->front == -1;
}

void enqueue(struct Queue* queue,int val) {
    if (!isFull(queue)) {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->arr[++(queue->rear)] = val;
    }else {
        printf("queue is FULL");
    }
}

int dequeue(struct Queue* queue) {
    if (!isEmpty(queue)) {
        return queue->arr[queue->front++];
    }else {
        printf("queue is empty");
        return -1;
    }
}

int peek(struct Queue* q) {
    if (!isEmpty(q)) {
        return q->arr[q->front];
    }else {
        printf("queue is empty");
        return -1;
    }
}


int main() {
    struct Queue q ;
    initial(&q);
.
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,5);

    int size = (q.rear - q.front)+1;
    int start = q.front;
    for (int i=0; i<size; i++) {
        printf("%d -",q.arr[start]);
        start++;
    }

    return 0;
}

