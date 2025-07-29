//
// Created by Kishi Kishore N on 29/07/25.
//

#include <stdio.h>

int main() {
    int y;
    int x=12;
    y=(x&1)?printf("Hello"):printf("everyone");
    printf("%d\n",y);
    return 0;
}