//
// Created by Kishi Kishore N on 07/08/25.
//
#include <stdio.h>

void main() {
    int a[]= {1,2,3,4,5,6};
    int *p =a;
    int n =sizeof(a);
    while (n!=0) {
        n -= sizeof(int);
        printf("%u",*p++);
    }
    // printf("%u",p[1]);
}