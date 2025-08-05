//
// Created by Kishi Kishore N on 05/08/25.
//
#include <stdio.h>
// recursion to calculate number of digits

int fun(int number) {
    if (number<=0) {
        return 0;
    }
    return fun(number/10)+1;
}

int f(int number) {
    if (number <=9) {
        return 1;
    }
    return 1+f(number/10);
}

void main() {
    int res = fun(74116);
    int res1 = f(74116);
    printf("res:%d\n",res);
    printf("res:%d",res1);

}