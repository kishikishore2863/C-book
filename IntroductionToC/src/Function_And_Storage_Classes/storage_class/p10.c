//
// Created by Kishi Kishore N on 05/08/25.
//

#include <stdio.h>

void f1() {
    extern int x;
    ++x;
}

void f2() {
    extern int x;
    ++x;
}

void main() {
    extern int x;
    f1();
    f2();
    ++x;
    printf("%d",x);
}
int x;