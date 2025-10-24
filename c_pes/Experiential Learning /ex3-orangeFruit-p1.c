#include <stdio.h>

struct node{
	int data;
	struct node* next;

};

struct node* reverse(struct node* head);
int main(){
	struct node n5 = {5,NULL};
	struct node n4 = {4,&n5};
	struct node n3 = {3,&n4};
	struct node n2 = {2,&n3};
	struct node n1 = {1,&n2};
	
	struct node* head = &n1;
	
	struct node* res = reverse(head);
	
	while(res!=NULL){
		printf("%d",res->data);
		res = res->next;
	}
	
	return 0;
}	

struct node* reverse(struct node* head){
	if(head == NULL )return head;
	
	struct node* curr = head;
	struct node* prev = NULL;
	while(curr!=NULL){
		struct node* ref = curr->next;
		curr->next = prev ;
		prev = curr;
		curr = ref;
	}
	
	return prev;
}