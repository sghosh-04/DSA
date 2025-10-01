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
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}


int main(){
    struct Node* root=NULL;
    int i,n,data;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Enter element %d: ",i);
        scanf("%d",&data);
        root=insert(root,data);
    }
    inorder(root);


    return 0;
}

