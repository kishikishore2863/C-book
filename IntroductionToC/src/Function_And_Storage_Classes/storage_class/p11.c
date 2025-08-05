//
// Created by Kishi Kishore N on 05/08/25.
//
#include <stdio.h>

static int i=0;
static int i;
void f1() {
    i++;
    i++;
}
void f2() {
    printf("%d\n",i);
}
void main() {
    f1();
    f2();

    printf("%d\n",i);
}