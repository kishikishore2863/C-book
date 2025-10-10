#include <stdio.h>

int sumOfMatrix(int arr[][],int size);
int main(){
	int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
//	int res = sumOfMatrix(arr,3);
	int sum=sumOfMatrix(arr, 5);
//	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
//		for(int j=0; j<sizeof(arr[0])/sizeof(arr[0][0]); j++){
//			 sum = sum+arr[i][j];
//
//	}
//	}
	printf("%d",sum);
	return 0;
}

int sumOfMatrix(int* arr, int size){
	int sum=0;
//	for(int i=0; i<arr+(size*sizeof(int)); i++){
//		for(int j=0; j<size; j++){
//			sum = sum+arr[i][j];
//		}
//	}
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
		for(int j=0; j<sizeof(arr[0])/sizeof(arr[0][0]); j++){
			 sum = sum+arr[i][j];

	}
	}

	return sum;
}