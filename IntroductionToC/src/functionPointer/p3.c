//
// Created by Kishi Kishore N on 12/08/25.
//

#include <stdio.h>
#define   MAX(a, b) ((a) > (b) ? (a) : (b))
int f(int *p, int n) {
    if (n<=1)return 0;
    return MAX(f(p+1,n-1),p[0]-p[1]);
}

void main() {
    int a[] = {3,5,2,6,4};
    printf("%d",f(a,5));
}