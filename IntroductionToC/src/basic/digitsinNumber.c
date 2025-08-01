//
// Created by Kishi Kishore N on 01/08/25.
//
#include <stdio.h>

void main() {
    int n = 124;
    int count = 0;
    while (n > 0) {
        count++;
        n = n / 10;
    }
    printf("%d", count);
}