#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* link;
};

struct node* insert_at_begin(struct node* newNode ,struct node* head);
struct node* insert_at_end(struct node* newnode, struct node* head);
struct node* insert_at_middle(struct node* newNode, struct node* head ,int pos);

int main(){
	struct node n4 = {4,NULL};
	struct node n3 = {3,&n4};
	struct node n2 = {2,&n3};
	struct node n1 = {1,&n2};
	
	struct node* head = &n1;
	
	struct node n0 = {0,NULL};
	struct node* newNode = &n0;
	
	struct node* res =  insert_at_middle(newNode ,head,2);
	
	while(res != NULL){
		printf("%d",res->data);
		res=res->link;
	}
	
	
	return 0;
}

struct node* insert_at_begin(struct node* newNode ,struct node* head){
	struct node* curr = head;
	newNode->link = head;
	head = newNode;
	return head;
}

struct node* insert_at_end(struct node* newNode, struct node* head){
	struct node* curr = head;
	
	while(curr->link != NULL){
		curr= curr->link;
	}
	curr->link = newNode;
	return head;
}

struct node* insert_at_middle(struct node* newNode, struct node* head ,int pos){
	if (head == NULL || pos <= 0) return head;
	
	struct node* curr = head;
	int p = pos-1;
	
	while(p>0){
		curr = curr->link;
		p--;
	}
	struct node* temp = curr->link;
	curr->link = newNode;
	newNode->link = temp;
	
	return head; 
}