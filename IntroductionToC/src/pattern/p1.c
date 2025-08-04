//
// Created by Kishi Kishore N on 04/08/25.
//
#include <stdio.h>

void main() {
    for (int i=0; i<5; i++) {
        for (int j=0; j<=i; j++) {
            printf("%d",j+1);
        }
        printf("\n");
    }
}