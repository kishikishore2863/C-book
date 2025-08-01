//
// Created by Kishi Kishore N on 01/08/25.
//
#include <stdio.h>

void main() {
    for (int i=1; i<=10; i++) {
        if (i%4 == 0) {
            break;
        }
        printf("%d",i);
    }
}