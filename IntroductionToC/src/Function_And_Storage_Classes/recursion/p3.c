//
// Created by Kishi Kishore N on 05/08/25.
//
#include <stdio.h>
//a+b using recursion


int f1(int a, int b) {
    if (b == 0) {
        return a;
    }
    return f1(a+1,b-1);
}

void main() {
    int a =10;
    int b =20;
    int res =  f1(a,b);
    printf("res:%d",res);
}