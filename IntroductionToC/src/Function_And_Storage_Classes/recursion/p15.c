//
// Created by Kishi Kishore N on 05/08/25.
//
#include <stdio.h>
//q9

void main() {
    static int var=5;
    printf("%d",var--);
    if (var)
    main();
}