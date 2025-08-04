//
// Created by Kishi Kishore N on 04/08/25.
//
#include <stdio.h>
int mul(int,int);

int main() {
    int a =10, b=20,ans;
    ans = mul(a,b);
    printf("%d",ans);
    return 0;
}

int mul(int a,int b) {
    int result;
    result = a*b;
    return result;
}