//
// Created by Kishi Kishore N on 05/08/25.
//
#include <stdio.h>
// recursion -> decimal to octal number


void f1(int n) {
    if (n<8) {
        printf("%d",n);
        return;
    }
    f1(n/8);
    printf("%d",n%8);

}

void main() {
    f1(28);
}