//
// Created by Kishi Kishore N on 01/08/25.
//
#include <stdio.h>

void main() {
    int n;
    printf("calculation for factorial\n");
    printf("enter the value of n:");
    scanf("%d",&n);
    int prod =1;
    for (int i=1; i<=n; i++) {
        prod *= i;
    }
    printf("factorial of %d is:%d\n",n,prod);
}