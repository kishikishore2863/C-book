//
// Created by Kishi Kishore N on 05/08/25.
//

#include <stdio.h>


void f1() {
    extern int x;
    ++x;
    printf("%d",x);
}

void f2() {
    extern int x;
    ++x;
}

int x;
void main() {
    f1();
    f2();
    ++x;
    printf("%d",x);
}
