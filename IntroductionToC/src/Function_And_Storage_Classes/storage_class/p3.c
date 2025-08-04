//
// Created by Kishi Kishore N on 05/08/25.
//
#include <stdio.h>

void main() {
    int a=0;
    ++a;
    {
        int a =10;
        ++a;
        printf("%d",a);
    }
    ++a;
    printf("%d",a);
}