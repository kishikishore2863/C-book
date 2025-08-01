//
// Created by Kishi Kishore N on 01/08/25.
//
#include <stdio.h>

void main() {
    int n;
    printf("enter a number:");
    scanf("%d",&n);
    switch (n) {
        case 1:printf("chosen 1");
            break;
        case 2:printf("chosen 2");
            break;
        default:printf("wrong guess ");
            break;
    }
}