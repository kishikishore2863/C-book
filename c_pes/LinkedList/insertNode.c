#include <stdio.h>
#include <stdlib.h>


struct node{
	int data;
	struct node* next;
};

struct node* insert_node(struct node *head, int data ,int pos);
int main(){
	struct node n5 = {5,NULL};
    struct node n4 = {4,&n5};
    struct node n3 = {3,&n4};
    struct node n2 = {2,&n3};
    struct node n1 = {1,&n2};

    struct node* Head = &n1;

    struct result = insert_node(Head, 13, 2);

    while (result != NULL) {
        printf("%d\n",result->data);
        result = result->next;
    }
	return 0;
}

struct node* insert_node(struct node* head, int data ,int pos){
	if(head == NULL){
		return head;
	}
	struct node* curr = head;
	int cpos = 0;
	while((cpos<(pos-1)) && (curr != NULL)){
		curr =curr->next;
		cpos++;
	}
	struct node *newNode = malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	if(curr==NULL){
		curr = newNode;
	}else{
		struct node* temp = curr->next->next;
		curr->next = newNode;
		newNode->next = temp;
	}
	return head;
}

