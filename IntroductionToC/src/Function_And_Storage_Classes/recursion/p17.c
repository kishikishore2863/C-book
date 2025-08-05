//
// Created by Kishi Kishore N on 05/08/25.
//
#include <stdio.h>
//q11

int f(int x) {
    if (x%2==0) {
        return f(f(x-1));
    }
    else
        return (x++);
}

int main() {
    printf("%d",f(12));
    return 0;
}