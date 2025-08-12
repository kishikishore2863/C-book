//
// Created by Kishi Kishore N on 12/08/25.
//
#include <stdio.h>
// Given an array in which all element occurs even no of times except one element find that element;
void main() {
    int a[7] = {10,10,20,20,30,30,5};
    int x=0;
    for (int i=0; i<7; i++) {
        x = x^a[i];
    }
    printf("%d",x);
}