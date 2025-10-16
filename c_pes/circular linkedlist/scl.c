#include <stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};


int main(){
	

}



struct node* insert_front(struct node* head, int data){
	struct node* curr =head;
	while(curr->next != head){
		curr = curr->next;
	}
	struct node* nn = malloc(sizeof(struct node));
	nn->data = data;
	nn->next = head;
	curr->next = nn;
	
	return nn;
}


struct node* insert_end(struct node* head, int data){
	struct node* curr = head;
	while(curr->next != head){
		curr = curr->next;
	}
	struct node* nn = malloc(sizeof(struct node));
	nn->data = data;
	curr->next = nn;
	nn->next =head;
	return head
}

struct node* delete_front(struct node* head){
	struct node* curr = head;
	while(curr->next!=head){
		curr = curr->next;
	}
	struct node* first = head->next;
	free(head);
	curr->next = first;
	return head;
}



