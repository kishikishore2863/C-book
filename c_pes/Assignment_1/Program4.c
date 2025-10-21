#include<stdio.h>

void oneDAdd();
void twoDAdd();
int main(){
	oneDAdd();
	printf("\n");
	twoDAdd();
	return 0;
}

void oneDAdd(){
	int arr[5] = {1,2,3,4,5};
	int index =2;
	long base = (long)arr;
	long address;
	address =(long) arr+(index*sizeof(int));
	printf("Base Address of arr : %ld \n",base);
	printf("Address of element at index 2 in 1D Array: %ld \n",address);
}

void twoDAdd(){
	int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int row  = 1;
	int column = 2;
	int totalColumns = 3;
	 
	long base = (long)arr;
	long address;
	
	address = base + ((row * totalColumns) + column) * sizeof(int);
	
	printf("Base address of 2D arr : %ld \n",base);
	printf("Address of element at (1,2) in 2D Array: %ld", address);
}