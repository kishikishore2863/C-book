//
// Created by Kishi Kishore N on 04/08/25.
//
#include <stdio.h>

void h() {
    printf("1");
}
void g() {
    printf("2");
    h();
    printf("3");
}

void f() {
    printf("4");
    g();
    printf("5");
}

void main() {
    f();
    g();
    h();
    f();
}
// 42135213142135