//
// Created by Kishi Kishore N on 05/08/25.
//
#include <stdio.h>
//q7

void fun(int n) {
    if (n==0)return ;
    fun(n/2);
    printf("%d",n%2);
}

void main() {
    fun(11);
}