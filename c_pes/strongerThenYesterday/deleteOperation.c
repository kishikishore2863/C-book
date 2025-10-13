#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* link; 
};

struct node* delete_begin(struct node* head);
struct node* delete_end(struct node* head);

int main(){
	struct node n5 ={5,NULL};
	struct node n4 ={4,&n5};
	struct node n3 ={3,&n4};
	struct node n2 ={2,&n3};
	struct node n1 ={1,&n2};
	
	struct node* head = &n1;
	
	struct node* res = delete_end(head);
	
	while(res!=NULL){
		printf("%d",res->data);
		res=res->link;
	}
	
	return 0;
}


struct node* delete_begin(struct node* head){
	struct node* next = head->link;
	return next;
}

struct node* delete_end(struct node* head){
	struct node* curr = head;
	struct node* prev = NULL;
	
	while(curr->link != NULL){
		prev =curr;
		curr = curr->link;
	}
	
	prev->link = NULL;
	return head;
}
