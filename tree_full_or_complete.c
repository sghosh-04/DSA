#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createnode(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}


struct Node* insertleft(struct Node* root,int data){
    root->left=createnode(data);
    return root->left;
}

struct Node* insertright(struct Node* root,int data){
    root->right=createnode(data);
    return root->right;
}


int isFull(struct Node* root) {
    if (root == NULL)
        return 1;

    if ((root->left == NULL && root->right == NULL) ||
        (root->left && root->right))
        return isFull(root->left) && isFull(root->right);

    return 0;
}


unsigned int countNodes(struct Node* root)
{
    if (root == NULL)
        return 0;

    return (1 + countNodes(root->left) + countNodes(root->right));
}


bool isComplete(struct Node* root, unsigned int index, unsigned int number_nodes)
{
    
    if (root == NULL)
        return true;

    
    if (index >= number_nodes)
        return false;

    
    return (isComplete(root->left, 2 * index + 1, number_nodes) &&
            isComplete(root->right, 2 * index + 2, number_nodes));
}


void inorder(struct Node* root){
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){
    struct Node* root=createnode(1);
    insertleft(root,2);
    insertright(root,3);
    insertleft(root->left, 4);
    insertright(root->left, 5);
    insertleft(root->right, 6);
    insertright(root->right, 7);
    inorder(root);
    printf("\n");
    if(isFull(root)){
        printf("The tree is full\n");
    } else {
        printf("The tree is not full\n");
    }

    unsigned int node_count = countNodes(root); 
    printf("%u\n", node_count);
    unsigned int index = 0;
    if (isComplete(root, index, node_count))
        printf("The tree is complete\n");
    else
        printf("The tree is not complete\n");

    return 0;
}