//
// Created by Kishi Kishore N on 05/08/25.
//
#include <stdio.h>
//q10

void main() {
    static int i=5;
    if (--i) {
        main();
        printf("%d",i);
    }
}