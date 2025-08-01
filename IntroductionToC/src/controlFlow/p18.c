//
// Created by Kishi Kishore N on 01/08/25.
//
#include <stdio.h>

void main() {
    int n=1;
    for (int i=1; i<=n; i++) {
        for (int j=i; j<2*i; j++) {
            printf("kishi");
        }
        printf("\n");
    }
}


//dependent nested loop
// loop unfolding