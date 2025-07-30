//
// Created by Kishi Kishore N on 31/07/25.
//

#include <stdio.h>

void main() {
    int a,b,c;
    a=1,b=3,c=8;
    if (a>b &&a>c) {
        printf("largest is :%d",a);
    }
    if (b>a && b>c) {
        printf("largest is :%d",b);
    }
    if (c>a&& c>b) {
        printf("largest is :%d",c);
    }
}