//
// Created by Kishi Kishore N on 05/08/25.
//
#include <stdio.h>
// a*b using recursion

int f1(int a,int b) {
    if (b==0) {
        return 0;
    }

    return a +f1(a,b-1);

}

void main() {
   int res = f1(2,6);
    printf("%d",res);
}