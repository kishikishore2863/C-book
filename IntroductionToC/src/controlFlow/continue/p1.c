//
// Created by Kishi Kishore N on 01/08/25.
//
#include <stdio.h>

//continue is used to skip the remaining code of current iteration and continue with the next iteration;
void main() {
    for (int i=1; i<=10; i++) {
        if (i%2==0)continue;
        printf("%d",i);
    }
}