//
// Created by Kishi Kishore N on 29/07/25.
//

#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;
    b = (a + b) - (a=b);
    printf("%d\n",a);
    printf("%d\n", b);
}