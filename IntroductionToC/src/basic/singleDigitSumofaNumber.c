//
// Created by Kishi Kishore N on 01/08/25.
//
#include <stdio.h>

void main() {
    int number = 9992;
    if (number % 9 == 0) {
        printf("9");
    } else {
        printf("%d", number % 9);
    }
}
