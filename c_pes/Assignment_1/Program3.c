#include <stdio.h>

int sumOfMatrix(int arr[3][3],int size);

int main(){
	int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int sum=sumOfMatrix(arr, 3);
	printf("%d",sum);
	return 0;
}

int sumOfMatrix(int arr[3][3], int size){
	int sum=0;
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++)sum = sum+arr[i][j];
	}
	return sum;
}