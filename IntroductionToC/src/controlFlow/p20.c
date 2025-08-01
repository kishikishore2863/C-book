//
// Created by Kishi Kishore N on 01/08/25.
//
#include <stdio.h>

void main() {
    int n=100;
    int count =0;
    for (int i=1; i<=n; i=i*3) {
        printf("i=%d\n",i);
        for (int j=i; j<=n; j++) {
           count++;
        }
    }
    printf("%d",count);
}