//
// Created by Kishi Kishore N on 07/08/25.
//
#include <stdio.h>
void fun(int*);
void main() {
    int a[4] ={10,20,30,40};
    fun(a);
    printf("%d%d",a[0],a[2]);
}

void fun(int *p) {
    ++*p++;
}