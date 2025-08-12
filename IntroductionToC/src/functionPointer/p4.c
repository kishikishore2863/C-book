//
// Created by Kishi Kishore N on 12/08/25.
//
#include <stdio.h>

void main() {
    int a = 256;
    char *p;
    p=(char*)&a;
    printf("%d",*p);
}