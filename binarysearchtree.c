#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create(int data){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct Node* insert(struct Node* root, int data){
    if(root==NULL){
        return create(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }

    return root;
}

void inorder(struct Node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        inorder(root->left);
        inorder(root->right);
    }
}

void preorder(struct Node* root){
    if (root !=NULL){
        preorder(root->left);
        printf("%d ",root->data);
        preorder(root->right);
    }
}

void postorder(struct Node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main(){
    struct Node* root=NULL;
    root=insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);

    printf("Inorder traversal: ");
    inorder(root);

    printf("\nPreorder traversal: ");
    preorder(root);

    printf("\nPostorder traversal: ");
    postorder(root);

    return 0;
}

