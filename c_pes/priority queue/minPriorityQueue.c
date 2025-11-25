//
// Created by Kishi Kishore N on 25/11/25.
//

#include <stdio.h>
#define Max 10

typedef struct {
    int element, priority;
}Node;

typedef struct PriorityQueue {
    Node arr[Max];
    int size;
}*PriorityQueue;

void InitialQueue(PriorityQueue queue) {
    queue->size =0;
}

int IsEmpty(PriorityQueue queue) {
    return queue->size == 0;
}

int Size(PriorityQueue queue) {
    return queue->size;
}

void Add(PriorityQueue queue, int element , int priority) {
    if (queue->size == Max) {
        printf("Error:Queue is full.\n");
        return;
    }
    Node newNode;
    newNode.element = element;
    newNode.priority = priority;

    int i;
    for (i=queue->size-1; (i>=0 && queue->arr[i].priority>priority); i--) {
        queue->arr[i+1] = queue->arr[i];
    }
    queue->arr[i+1] = newNode;
    queue->size++;
}

Node pop(PriorityQueue queue) {
    if (queue->size == 0) {
        printf("Error:Queue is empty.\n");
        return (Node){-1,-1};
    }
    Node popNode = queue->arr[0];
    for (int i =0; i<queue->size-1; i++) {
        queue->arr[i] = queue->arr[i+1];
    }
    queue->size--;
    return  popNode;
}