#include <stdio.h>

struct node{
	int data;
	struct node* link;
};

struct node* reverse(struct node* head );
int main(){
	struct node n5 = {5,NULL};
    struct node n4 = {4,&n5};
    struct node n3 = {3,&n4};
    struct node n2 = {2,&n3};
    struct node n1 = {1,&n2};

    struct node* Head = &n1;
    
    struct node* ref = Head;
    
        while( ref != NULL){
    	printf("%d",ref->data);
    	ref = ref->link;
    }	

	printf("\n");

    struct node* result =reverse(Head);
    
    while(result != NULL){
    	printf("%d",result->data);
    	result = result->link;
    }	
    
    return 0;
}

struct node* reverse(struct node* head ){
	if(head == NULL){
		return head;
	}
	
	struct node* prev = NULL;
	struct node* curr = head;
	while(curr!= NULL){
		struct node* nextRef = curr->link;
		curr->link = prev;
		prev = curr;
		curr = nextRef;
	}
	return prev;
}

