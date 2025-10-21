#include <stdio.h>

float averageArr(int arr[], int size);
int main(){
	int arr[5] = {10,20,30,40};
	float res = averageArr(arr,4);
	printf("Average of the array: %.2f", res);
	return 0;
}

float averageArr(int arr[], int size){
	float average;
	float sum=0;
	for(int i=0; i<size; i++){
		sum += arr[i];
	}
	
	average = (float)sum/size;
	return average;
}