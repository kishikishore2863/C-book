#include <stdio.h>
#define Max 10

struct Deque{
  int front;
  int rear;
  int arr[Max];
};

int isEmpty(struct Deque* dq);
int isFull(struct Deque* dq);
void insertLeft(struct Deque* dq, int data);
void insertRight(struct Deque* dq, int data);
int deleteLeft(struct Deque * dq);
void display(struct Deque* dq);

int main(){
    struct Deque dq;
    dq.front =dq.rear-1;
    insertRight(&dq,10);
    insertRight(&dq,20);
    insertLeft(&dq,5);
    insertLeft(&dq,3);
    display(&dq);
    
    deleteLeft(&dq);
    
    insertRight(&dq,30);
    insertLeft(&dq,2);
    display(&dq);
    
    return 0;
}

int isFull(struct Deque* dq){
    return dq->rear == Max-1;
}

int isEmpty(struct Deque* dq){
    return dq->front == -1;
}

void insertLeft(struct Deque *dq, int data){
    if(isFull(dq)){
        dq->front =dq->rear =0;
    }else if(dq->front ==0){
        dq->front = Max-1;
    }else{
        dq->front--;
    }
    dq->arr[dq->front] =data;
}

void insertRight(struct Deque* dq, int data){
    if(isFull(dq)){
        printf("Deque is full!\n");
        return;
    }
    
    if(isEmpty(dq)){
        dq->front =dq->rear =0;
    }else if(dq->rear ==Max -1){
        dq->rear =0;
    }else{
        dq->rear++;
    }
    dq->arr[dq->rear]=data;
}

int deleteLeft(struct Deque * dq){
    if(isEmpty(dq)){
        printf("Deque is empty!\n");
        return -1;
    }
    int ele = dq->arr[dq->front];
    if(dq->front == dq->rear){
        dq->front =dq->rear=-1;
    }else if(dq->front == Max-1){
        dq->front =0;
    }else{
        dq->front++;
    }
    return ele;
}

void display(struct Deque* dq){
    if(isEmpty(dq)){
        printf("Deque is Empty!\n");
        return;
    }
    
    int i=dq->front;
    printf("Deque: ");
    while(i!=dq->rear){
        printf("%d\n",dq->arr[i]);
        i=(i+1)%Max;
    }
    printf("%d\n",dq->arr[dq->rear]);
}







