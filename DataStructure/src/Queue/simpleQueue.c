//
// Created by Kishi Kishore N on 21/08/25.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#define SIZE 10
//simple queue

typedef struct {
    int arr[SIZE];
    int front;
    int rear;
}queue;

void initialize(queue *q) {
    q->front=-1;
    q->rear=-1;
}

bool isEmpty(queue *q) {
   if (q->rear == SIZE - 1 ){
       return true;
   }
    return false;
}


void insert(queue *q,int data){
    if (!isEmpty(q)) {
        if (q->front == -1 && q->rear == -1) {
            q->front=0 ;
            q->rear=0;
            q->arr[q->rear]=data;
        }else {
            q->rear += 1;
            q->arr[q->rear]=data;
        }
    }else {
        printf("queue is full cant insert\n");
    }
}

int delete(queue *q){
    int res = INT32_MIN;
    if (q->rear != -1) {
        if (q->rear == q->front ) {
            res =q->arr[q->front];
            q->rear=-1;
            q->front=-1;
        }else {
            res =q->arr[q->front];
            q->front +=1;
        }
    }
    return res;
}

int main() {
    queue q;
    initialize(&q);
    insert(&q,1);
    insert(&q,2);
    insert(&q,3);


   int res1 = delete(&q);
   int res2 = delete(&q);
   int res3 = delete(&q);
   int res4 = delete(&q);

    printf("res1:%d\n",res1);
    printf("res2:%d\n",res2);
    printf("res3:%d\n",res3);
    printf("res4:%d\n",res4);



    return 0;
}