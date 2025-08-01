//
// Created by Kishi Kishore N on 01/08/25.
//
#include <math.h>
#include <stdio.h>

void main() {
    int number = 153;
    int clone = number;
    int clonePow = number;
    int digits = 0;

    while (clonePow > 0) {
        digits++;
        clonePow = clonePow / 10;
    }

    int sum = 0;
    while (clone > 0) {
        int lastDigit = clone % 10;
        sum = sum + (int) pow(lastDigit, digits);
        clone = clone / 10;
    }

    if (sum == number)printf("number is armstrong number ");
    else printf("not an armstrong number");

}
