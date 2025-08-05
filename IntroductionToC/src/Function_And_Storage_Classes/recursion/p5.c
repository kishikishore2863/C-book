//
// Created by Kishi Kishore N on 05/08/25.
//
#include <stdio.h>
// decimal to binary using recursion

void f1(int n) {
    if (n==0 || n==1) {
        printf("%d",n);
        return ;
    }
    f1(n/2);
    printf("%d",n%2);
}

void main() {
   f1(2863);
}