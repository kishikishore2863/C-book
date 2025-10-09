#include <stdio.h>

int sumOfMatrix(int arr[][],int size);
int main(){
	int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int res = sumOfMatrix(arr,3);
	printf("%d",res);
	return 0;
}

int sumOfMatrix(int* arr, int size){
	int sum=0;
	for(int i=0; i<arr+(size*sizeof(int)); i++){
		for(int j=0; j<size; j++){
			sum = sum+arr[i][j];
		}
	}
	return sum;
}