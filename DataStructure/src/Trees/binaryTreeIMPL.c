//
// Created by Kishi Kishore N on 23/08/25.
//
#include <stdio.h>

typedef struct TreeNode{
    struct TreeNode *right;
    int data;
    struct TreeNode *Left;
}TreeNode;

void preOder(TreeNode *root);
void inOrder(TreeNode *root);
void postOrder(TreeNode *root);
int main() {
    TreeNode three = {NULL,3,NULL};
    TreeNode two ={NULL,2,NULL};
    TreeNode one = {&three,1,&two};
    TreeNode *root = &one;
    preOder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    return 0;
}

void preOder(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    printf("%d",root->data);
    preOder(root->Left);
    preOder(root->right);

}

void postOrder(TreeNode *root) {
    if (root == NULL) {
        return;
    }

    postOrder(root->right);
    postOrder(root->Left);
    printf("%d",root->data);

}

void inOrder(TreeNode *root) {
    if (root ==NULL)return;

    inOrder(root->Left);
    printf("%d",root->data);
    inOrder(root->right);
}





