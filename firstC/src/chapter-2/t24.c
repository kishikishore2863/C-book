//
// Created by Kishi Kishore N on 31/07/25.
//
#include <stdio.h>

void main() {
    int a,b,c;
    a=1,b=2,c=3;
    int largest = (a>b && a>c)?a:(b>c)?b:c;
    printf("%d",largest);
}