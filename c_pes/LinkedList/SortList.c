#include <stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* link;
};

int main(){
	
	return 0;
}

struct node* sort(struct node* head){
	struct node* countPtr =head;
	int count =0;
	while(countPtr != NULL){
		count++;
		countPtr = countPtr->link;
	}
	struct node* curr = head;
	
	while(count>0){
		count--;
		struct node* first = head;
		curr = first->link;
		first->link = NULL;
		solve(first,curr);
	}
	
}

struct node* solve(struc node* fnode, struct node* head){

	struct node* prev = NULL;
	struct node* curr = head;
	while(curr!=NULL){
		prev = curr;
		curr = curr->link;
		if(curr != NULL &&(fnode->data > curr->data)){
			prev->link = fnode;
			fnode-> link = curr;
			return head;
		}if(curr == NULL){
			prev->link = fnode;
			fnode->link = NULL;
			return head;
		}
		
	}
	
	return NULL;
	
}




