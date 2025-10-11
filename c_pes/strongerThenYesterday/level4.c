#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* link;
};

int countNode(struct node* head);
int main(){
	struct node n4 = {4,NULL};
	struct node n3 = {3,&n4};
	struct node n2 = {2,&n3};
	struct node n1 = {1,&n2};
	
	struct node* head = &n1;
	
	int res = countNode(head);
	printf("%d",res);
	return 0;
	
}

int countNode(struct node* head){
	struct node* curr = head;
	
	int count = 0;
	while(curr != NULL){
		count++;
		curr=curr->link;
	}
	return count;
}
