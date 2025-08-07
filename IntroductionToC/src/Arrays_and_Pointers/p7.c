//
// Created by Kishi Kishore N on 07/08/25.
//
#include <stdio.h>
void sum(int*,int);
void main() {
    int a[4]={10,20,30,40};
    sum(a,4);
}

void sum(int *p, int n) {
    int sum =0;
    for (int i=0; i<n; i++) {
        sum =sum+*p++;
    }
    printf("%d",sum);
}