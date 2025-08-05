//
// Created by Kishi Kishore N on 05/08/25.
//
#include <stdio.h>
//q8
void foo(int n,int sum) {
    int k=0,j=0;
    if (n==0)return;
    k=n%10;
    j=n/10;
    sum = sum+k;
    foo(j,sum);
    printf("%d",k);
}


void main() {
    int a = 2018,sum=0;
    foo(a,sum);
    printf("%d",sum);
}