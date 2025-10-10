#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* link;
};

struct node* insert_data(struct node* head, int data);
int main(){
	struct node n5 = {5,NULL};
    struct node n4 = {4,&n5};
//    struct node n3 = {3,&n4};
    struct node n2 = {2,&n4};
    struct node n1 = {1,&n2};
	
	struct node* head = &n1;
	
	struct node* res =insert_data( head, 3);
	while(res!=NULL){
		printf("%d",res->data);
		res = res->link;
	}
	return 0;
}

struct node* insert_data(struct node* head, int data){
	if(head == NULL){
		struct node* newNode = malloc(sizeof(struct node));
		newNode->data = data;
		newNode->link = NULL;
		return newNode;
	}
	
	if(data < head->data){
		struct node* newNode = malloc(sizeof(struct node));
		newNode->data = data;
		newNode->link = head;
		return newNode;
	}
	
	struct node* curr = head;
	while(curr!=NULL){
		struct node* next = curr->link;
		
		if(next!=NULL && data < next->data && data>curr->data){
			struct node* newNode = malloc(sizeof(struct node));
			newNode->data = data;
			curr->link = newNode;
			newNode->link = next;
			return head;
			
		} else if(next == NULL){
			struct node* newNode = malloc(sizeof(struct node));
			newNode->data = data;
			newNode->link = NULL;
			curr->link = newNode;
			return head; 
		}
		curr = curr->link;
	}
	
	return head;	
	
}

