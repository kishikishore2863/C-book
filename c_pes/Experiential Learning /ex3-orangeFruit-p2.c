#include <stdio.h>

struct node{
	int data;
	struct node* next;

};

struct node* merge(struct node* list1, struct node* list2);

int main(){
	struct node n5 = {8,NULL};
	struct node n4 = {7,&n5};
	struct node n3 = {6,&n4};
	struct node n2 = {4,&n3};
	struct node n1 = {2,&n2};
	
	struct node* list1 = &n1;
	
	struct node m5 = {10,NULL};
	struct node m4 = {9,&m5};
	struct node m3 = {5,&m4};
	struct node m2 = {3,&m3};
	struct node m1 = {1,&m2};
	
	struct node* list2 = &m1;
	
	struct node* res =merge(list1,list2);
	
	while(res!=NULL){
		printf("%d",res->data);
		res = res->next;
	}

	return 0;
}

struct node* merge(struct node* list1, struct node* list2){
	if(list1 == NULL ){
		return list2;
	}
	if(list2 == NULL ){
		return list1;
	}
	struct node dummy = {-1,NULL};
	struct node* resNew = &dummy;
	struct node* res = resNew;
	
	while(list1 !=NULL && list2 !=NULL){
		if(list1->data < list2->data){
			res->next = list1;
			list1 = list1->next;
			res = res->next;
		}else{
			res->next = list2;
			list2 = list2->next;
			res = res->next;
		}
	}
	
	if(list1 == NULL){
		res->next = list2;
	}else{
		res->next = list1;
	}
	
	return resNew->next;
}

