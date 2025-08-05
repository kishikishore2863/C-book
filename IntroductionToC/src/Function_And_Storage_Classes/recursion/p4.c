//
// Created by Kishi Kishore N on 05/08/25.
//
#include <stdio.h>
//a^b using recursion
int f1(int base,int pow) {
    if (pow == 1) {
        return base;
    }
    return base*f1(base,pow-1);
}

void main() {
    int res = f1(2,10);
    printf("res:%d",res);
}


