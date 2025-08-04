//
// Created by Kishi Kishore N on 05/08/25.
//
#include <stdio.h>

int x;
void f1() {
    ++x;
    printf("%d",x);
}

void f2() {
    ++x;
}

void main() {
    f1();
    f2();
    ++x;
    printf("%d",x);
}