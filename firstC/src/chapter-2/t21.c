//
// Created by Kishi Kishore N on 31/07/25.
//
#include <stdio.h>

void main() {
    int input;
    printf("enter a number");
    scanf("%d",&input);
    if (input>0) {
        printf("greater");
    }else if (input<0) {
        printf("lesser");
    }else {
        printf("0");
    }
}