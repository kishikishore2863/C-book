#include <stdio.h>

struct node{
	int data;
	struct node* next;

};

struct node* sort(struct node* head);
struct node* insertPos(struct node* head, struct node* iNode);

int main(){
	struct node n5 = {1,NULL};
	struct node n4 = {2,&n5};
	struct node n3 = {9,&n4};
	struct node n2 = {3,&n3};
	struct node n1 = {5,&n2};
	
	struct node* head = &n1;

	struct node* res = sort(head);
	
	while(res!=NULL){
		printf("%d",res->data);
		res = res->next;
	}

	return 0;
}


struct node* sort(struct node* head){
	struct node* curr = head;
	struct node* sorted = NULL;

	while(curr!=NULL){
		struct node* nextRef=curr->next;
		curr->next =NULL;
		sorted =insertPos( sorted,curr);
		curr = nextRef;
	}
	
	return sorted;
}

struct node* insertPos(struct node* head, struct node* iNode){
	if(head == NULL || iNode->data < head->data){
		iNode->next = head;
		return iNode;
	}

	struct node* curr = head;
	 while (curr->next != NULL && curr->next->data < iNode->data) {
            curr = curr->next;
        }
        
    struct node* ref = curr->next;
    curr->next = iNode;
    iNode->next = ref;

    return head;   
}


