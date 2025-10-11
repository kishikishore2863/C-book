#include <stdio.h>
#include <stdlib.h>

//int main(){
//	int a=10;
//	int* p =&a;
//	printf("%d",*p);
//}


//int main(){
//	int a=10;
//	int* p = &a;
//	int **pp=&p;
//	
//	printf("%d\n",a);
//	printf("%d\n",*p);
//	printf("%d\n",**pp);
//	return 0; 
//}



//int main(){
//	int *p = malloc(sizeof(int));
//	*p = 42;
//	printf("%d\n", *p);
//	free(p);
//	return 0;	
//
//}


//int main(){
//	int *a =malloc(sizeof(int));
//	int *b =a;
//	*a = 10;
//	*b = 20;
//	printf("%d\n",*b);
//
//}


struct node{
	int data;
	struct node* link;
};

//int main(){
//	struct node* head = malloc(sizeof(struct node*));
////	head->data=10;
////	head->link=NULL;
////	printf("%d\n",head->data);
//	head = NULL;
//	if(head == NULL){
//		printf("head is null");
//	}
//	free(head);
//	return 0;
//}


//int main(){
////	struct node n2 ={2,NULL}
//	struct node n1 = {1,NULL};
//	
//	struct node* head = &n1;
//	struct node* newNode = malloc(sizeof(struct node));
//	newNode->data = 2;
//	newNode->link = NULL;
//	
//	head->link = newNode;
//	
//	while(head != NULL){
//		printf("%d ->",head->data);
//		head = head->link;
//	}
//	return 0;
//}



int main(){
	struct node* n1 = malloc(sizeof(struct node));
	struct node* n2 = malloc(sizeof(struct node));
	struct node* n3 = malloc(sizeof(struct node));
	struct node* head = n1;
	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	
	n1->link = n2;
	n2->link = n3;
	n3->link = NULL;
	
	while(head != NULL){
		printf("%d ->", head->data);
		head = head->link;
	}
	return 0;
}






















