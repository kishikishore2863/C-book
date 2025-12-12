//
// Created by Kishi Kishore N on 12/12/25.
//
#include<stdio.h>
#define Max 30

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;

};

struct TreeNode* insertNode(struct TreeNode* root, struct TreeNode* newNode);
void DfsPre(struct TreeNode* root);


int main() {
    struct TreeNode fifteen ={15,NULL,NULL};
    struct TreeNode eight ={8,NULL,NULL};
    struct TreeNode nine ={9,&fifteen,&eight};
    struct TreeNode seven ={7,NULL,NULL};
    struct TreeNode eleven = {11,&seven,NULL};
    struct TreeNode ten ={10,&eleven,&nine};
    struct TreeNode* root  = &ten;
    struct TreeNode newNode = {200,NULL,NULL};

    struct TreeNode* res =  insertNode( root, &newNode);
    DfsPre(res);



    return 0;
}

struct TreeNode* insertNode(struct TreeNode* root, struct TreeNode* newNode) {
    if (root == NULL) {
        return newNode;
    }

    int front=0;
    int rear =-1;
    struct TreeNode* queue[Max];

    queue[++rear] = root;
    while (front<=rear) {
        struct TreeNode* temp = queue[front];
        if (queue[front]->left == NULL) {
            queue[front]->left = newNode;
            return root;
        }else {
            queue[++rear] = temp->left;
        }
        if (queue[front]->right == NULL) {
            queue[front]->right = newNode;
            return root;
        }else {
            queue[++rear] = temp->right;

        }
        front++;

    }
    return root;
}

void DfsPre(struct TreeNode* root) {
    if (root == NULL)return;

    printf("%d ,",root->val);
    DfsPre(root->left);
    DfsPre(root->right);
}

