#include <stdio.h>

struct node{
	int data;
	struct node* next;

};


int main(){
	struct node n5 = {1,NULL};
	struct node n4 = {2,&n5};
	struct node n3 = {9,&n4};
	struct node n2 = {3,&n3};
	struct node n1 = {5,&n2};
	
	struct node* head = &n1;


	
	while(res!=NULL){
		printf("%d",res->data);
		res = res->next;
	}

	return 0;
}


struct node* sort(struct node* head){
	
}


