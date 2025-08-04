//
// Created by Kishi Kishore N on 05/08/25.
//
#include <stdio.h>

void main() {
    int a=10;
    ++a;
    {
        ++a;
        printf("%d",a);
    }
    ++a;
    printf("%d",a);
}
//auto => scope and lifetime is same -b__block
//main.scope var are accessible in subscope;