//
// Created by Kishi Kishore N on 05/08/25.

#include <stdio.h>

void main() {
    int a=10;
    ++a;
    {
        ++a;
        printf("%d",a);
        {
            int b=5;
            ++a;
            printf("%d",a+b);
        }
        printf("%d",a);
    }
    printf("%d",a);
}
//sub scope avr are not available to main scope