#include <stdio.h>

struct node{
	int data;
	struct node* next;

};

struct node* Delete_Pos(struct node* header, int data, int pos);
struct node*  Delete_Content(struct node* Header, int Data);

int main(){
	struct node n5 = {5,NULL};
	struct node n4 = {4,&n5};
	struct node n3 = {3,&n4};
	struct node n2 = {2,&n3};
	struct node n1 = {1,&n2};
	
	struct node* head = &n1;
//	struct node* res = Delete_Pos(head, 2, 2);
	struct node* res = Delete_Content(head ,2);

	
	while(res!=NULL){
		printf("%d",res->data);
		res = res->next;
	}

	return 0;
}

struct node* Delete_Pos(struct node* header, int data, int pos){
	int i=0;
	struct node* curr =header;
	while(i<pos-1 && curr!=NULL){
		curr = curr->next;
		i++;
	}
	if(curr==NULL){
		curr->next = NULL;
	}else{
		curr->next = curr->next->next;
	}
	
	return header;
}

struct node*  Delete_Content(struct node* header, int data){
	struct node* curr = header;
	
	while(curr->next->data != data && curr!=NULL){
		curr= curr->next;
	}
	
	if(curr==NULL){
		curr->next = NULL;
	}else{
		curr->next = curr->next->next;
	}
	
	return header;
}



