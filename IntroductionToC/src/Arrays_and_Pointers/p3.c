//
// Created by Kishi Kishore N on 06/08/25.
//
#include <stdio.h>

void main() {
    int a[5] = {10,20,30,40,50};
    printf("%u\n",a);
    printf("%u\n",&a);
    printf("%u\n",a+1);
    printf("%u\n",&a+1);
    printf("%u\n",*(a+1));
}