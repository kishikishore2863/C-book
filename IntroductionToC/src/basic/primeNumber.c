//
// Created by Kishi Kishore N on 01/08/25.
//
#include <stdio.h>

void main() {
    int number;
    printf("enter a number:");
    scanf("%d", &number);
    if (number <= 1) {
        printf("given number is not prime!");
    } else {
        for (int i = 2; i < number; i++) {
            if (number % i == 0) {
                printf("given number is not prime");
                return;
            }
        }
        printf("given number is prime!");
    }
}
