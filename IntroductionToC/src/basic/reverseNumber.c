//
// Created by Kishi Kishore N on 01/08/25.
//
#include <stdio.h>

void main() {
    int n=145;
    int rev=0;
    while (n!=0) {
        int lastDigit = n%10;
        rev = rev*10+lastDigit;
        n=n/10;
    }
    printf("reverse:%d",rev);
}