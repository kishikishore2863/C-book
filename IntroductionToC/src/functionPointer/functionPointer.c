//
// Created by Kishi Kishore N on 11/08/25.
//
#include <stdio.h>

int Add(int a,int b) {
    return a+b;
}

int Sub(int a,int b) {
    return a-b;
}

int Prod(int a,int b) {
    return a*b;
}

void main() {
    int(*p)(int,int);
    p=Add;
    printf("%d\n",(*p)(10,20));
    p=Sub;
    printf("%d\n ",(*p)(10,20));
    p=Prod;
    printf("%d",(*p)(10,20));

}