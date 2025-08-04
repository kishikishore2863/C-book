//
// Created by Kishi Kishore N on 05/08/25.
//
#include <stdio.h>

void fun() {
    static int i=0;
    ++i;
    printf("%d",i);
}
void main() {
    fun();
    fun();
    fun();
}