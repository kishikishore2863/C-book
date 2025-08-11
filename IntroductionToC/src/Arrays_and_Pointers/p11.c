//
// Created by Kishi Kishore N on 11/08/25.
//
#include <stdio.h>

void main() {
    int a=160;
    char *p;
    p= (char*)&a;
    printf("%d",*p);
}