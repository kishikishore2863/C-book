#include <stdio.h>

struct student{
	char name[20];
	int age;
	float marks;

};

float average_marks(struct student arr[] ,int size );
int main(){
	struct student students[4] = {
    	{"kishore", 22, 80},
    	{"tony", 21, 99},
    	{"harry", 21, 95},
    	{"jhonny", 21, 90}
	};
	float res =  average_marks(students,4);
	printf("Average marks of students: %.2f",res);
	
	return 0;
}

float average_marks(struct student arr[] ,int size ){
	float sum =0;
	for(int i=0; i<size; i++){
		sum += arr[i].marks;
	}
	return sum/size;
} 