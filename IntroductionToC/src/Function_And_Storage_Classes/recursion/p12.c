//
// Created by Kishi Kishore N on 05/08/25.
//
#include <stdio.h>
//q6

int f(int n) {
    if (n<=1)return n;
    if (n%2)
        return f(n/2)+n;
    return f(n/3)+n;
}

void main() {
   int res = f(22);
    printf("%d",res);
}