//
// Created by Kishi Kishore N on 01/08/25.
//
#include <stdio.h>

void main() {
    int n = 145;
    int a = n;
    int sum = 0;
    while (n > 0) {
        int lastDigit = n % 10;
        int prod = 1;
        for (int i = 1; i <= lastDigit; i++) {
            prod *= i;
        }
        sum = sum + prod;
        n = n / 10;
    }
    sum == a ? printf("%d is strong", a) : printf("%d is not strong", a);
}