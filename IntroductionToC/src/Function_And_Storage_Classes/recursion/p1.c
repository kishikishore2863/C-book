//
// Created by Kishi Kishore N on 05/08/25.
//
#include <stdio.h>
void f(int n) {
    if (n==0)
        return;
    f(n-1);
    printf("%d",n);
    f(n-1);
    printf("%d",n);
}
void main() {
    f(3);
}