//
// Created by Kishi Kishore N on 05/08/25.
//
#include <stdio.h>
//q4
int f1(int n) {
    if (n<=1) {
        return n;
    }
    return f1(n/2)+f1(n/2)+1;
}

void main() {
    int res =f1(5);
    printf("%d",res);
}