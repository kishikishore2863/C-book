//
// Created by Kishi Kishore N on 04/08/25.
//
#include <stdio.h>

void main() {
    for (int i=1; i<=5; i++) {
        for (int j=1; j<=i; j++) {
            printf("%d",i);
        }
        printf("\n");
    }
}