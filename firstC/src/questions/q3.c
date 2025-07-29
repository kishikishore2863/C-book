//
// Created by Kishi Kishore N on 29/07/25.
//

#include <stdio.h>

int main() {
    int a,b;
    a=10;
    b=20;
    int temp = a;
    a=b;
    b=temp;
    printf("%d\n",a);
    printf("%d\n",b);
    return 0;

}