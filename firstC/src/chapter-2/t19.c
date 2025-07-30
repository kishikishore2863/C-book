//
// Created by Kishi Kishore N on 31/07/25.
//
#include <stdio.h>

void main() {
    int kb;
    printf("Enter a key: ");
    scanf("%d", &kb);
    if (kb%2==0) {
        printf("1");
    }else {
        printf("0");
    }
}