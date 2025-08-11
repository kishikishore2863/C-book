//
// Created by Kishi Kishore N on 11/08/25.
//
#include <stdio.h>


void fun(int(*p)[3]);
void main() {
    int a[2][3]={10,20,30,40,50,60};
    fun(a);
}

void fun(int(*p)[3]) {
    ++p;
    printf("%d",*((*p+1)+1));
}

