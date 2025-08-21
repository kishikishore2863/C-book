//
// Created by Kishi Kishore N on 21/08/25.
//
#include <stdint.h>
#include <stdio.h>
#define SIZE 5

typedef struct {
    int arr[SIZE];
    int front;
    int rear;
}Queue;

void initialize(Queue *q) {
    q->front=-1;
    q->rear=-1;
}



void insert(Queue *q, int data) {
    if ((q->rear + 1) % SIZE == q->front) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % SIZE;
    q->arr[q->rear] = data;
}

int delete(Queue *q) {
    if (q->front == -1) {
        printf("Queue underflow\n");
        return INT32_MIN;
    }
    int res = q->arr[q->front];
    if (q->front == q->rear) {
        // Queue has only one element, reset after deletion
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % SIZE;
    }
    return res;
}

int main() {
    Queue q;
    initialize(&q);
    insert(&q,1);
    insert(&q,2);
    insert(&q,3);
    insert(&q,4);
    insert(&q,5);
    int res1 = delete(&q);
    int res2 = delete(&q);
    int res3 = delete(&q);
    int res4 = delete(&q);
    int res5 = delete(&q);
    printf("res1:%d\n",res1);
    printf("res2:%d\n",res2);
    printf("res3:%d\n",res3);
    printf("res4:%d\n",res4);
    printf("res5:%d\n",res5);
    insert(&q,1);
    insert(&q,2);
    insert(&q,3);
    insert(&q,4);
    insert(&q,5);
    insert(&q,6);


    return 0;
}

