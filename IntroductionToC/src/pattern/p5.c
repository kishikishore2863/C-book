//
// Created by Kishi Kishore N on 04/08/25.
//
#include <stdio.h>

void main() {
    for (int i=1; i<=4; i++) {
        for (int space=1; space<=4-i; space++) {
           printf(" ");
        }
        for (int star=1; star<=i*2-1; star++) {
            printf("*");
        }
        printf("\n");
    }
}