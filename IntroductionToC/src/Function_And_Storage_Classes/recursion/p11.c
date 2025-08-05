//
// Created by Kishi Kishore N on 05/08/25.
//
#include <stdio.h>
//q5

int f(int n) {
    if (n<=1)return n;
    return f(n/2)+f(n/2);
}

void main() {
    int res = f(12);
    printf("%d",res);
}
