//
// Created by Kishi Kishore N on 29/07/25.
//
#include <stdio.h>

int main() {
    int a,b;
    a=99;
    b=88;
    a=a^b;
    b=a^b;
    a=a^b;
    printf("%d\n",a);
    printf("%d\n",b);
}
