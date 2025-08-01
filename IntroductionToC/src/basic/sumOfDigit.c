//
// Created by Kishi Kishore N on 01/08/25.
//
#include <stdio.h>

void main() {
    int n = 9992;
    int count = 0;
    while (n > 0) {
        int lastdigit = n % 10;
        count += lastdigit;
        n = n / 10;
    }
    printf("%d", count);
}
