//
// Created by Kishi Kishore N on 05/08/25.
//
#include <stdio.h>

void fun() {
    int a=0;
    static int b=0;
    ++a;
    ++b;
    printf("%d%d\n",a,b);

}

void main() {
    fun();
    int a=10;
    int b=0;
    ++a;
    ++b;
    printf("%d%d",a,b);
}
