//
// Created by Kishi Kishore N on 11/08/25.
//
#include <stdio.h>

void fun(int*);

void main() {
    int arr[2][3]={10,20,30,40,50,60};
    printf("%d %d %d\n",arr[0][0], arr[0][1], arr[0][2]);
    fun(arr);
    printf("%d %d %d",arr[0][0], arr[0][1], arr[0][2]);
}

void fun(int *p) {
    p++;
    *p =12;

}