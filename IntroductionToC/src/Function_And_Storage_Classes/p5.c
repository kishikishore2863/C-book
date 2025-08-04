//
// Created by Kishi Kishore N on 04/08/25.
//
#include <stdio.h>

void swap(int ,int);

void main() {
    int a=10,b=20;
    printf("before swap\n");
    printf("a=%d,b=%d\n",a,b);
    swap(a,b);
    printf("a=%d,b=%d",a,b);
}

void swap(int x, int y) {
    auto int temp;
    temp =x;
    x=y;
    y= temp;
}