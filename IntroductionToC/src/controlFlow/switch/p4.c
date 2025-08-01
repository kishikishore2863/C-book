//
// Created by Kishi Kishore N on 01/08/25.
//
#include <stdio.h>

void main() {
    //error
    int i=3,a=3,b=6;
    switch (i+3) {
        case a:printf("hello");
            break;
        case b:printf("lo");
            break;
        default: printf("default");
    }
    //case labels => literals
    //case labels != be variables
}