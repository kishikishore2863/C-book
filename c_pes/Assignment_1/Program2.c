#include <stdio.h>

int main(){
	int arr[5] = {10,20,30,40,50};
	int* ptr = arr;
	int i=0;
	printf("Array elements:");
	while(i<5){
		printf(" %d",*(ptr++));
		i++;
	}
	return 0;
}