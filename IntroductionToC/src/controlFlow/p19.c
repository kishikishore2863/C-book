//
// Created by Kishi Kishore N on 01/08/25.
//
#include <stdio.h>

void main() {
    int n=2;
    for (int i=1; i<=n; i++) {
        for (int j=i; j<=3*i;j++) {
            printf("1");
        }
        printf("\n");
    }
}
// dependent nested loop
// to find out inner loop execution
// use loop unfolding
// when i=1; j=1 to 3 , 1,2,3  ->3-1+1 =3
// when i=2; j=2 to 6,  2,3,4,5,6  ->6-2+1 =5
// when i=3; j=3 to 9,  3,4,5,6,7,8,9 ->9-3+1 =7
// when i=n; j=n to n*3,  ->(3n-n+1) =2n+1
//using AP formula = n/2(first+last);
// d = 2;
// =n/d(3+2n+1)
