#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct Node* createTree() {
    int data;
    char choice;

    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1)
        return NULL;

    struct Node* newNode = createNode(data);

    printf("Add left child of %d? (y/n): ", data);
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        newNode->left = createTree();
    }

    printf("Add right child of %d? (y/n): ", data);
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        newNode->right = createTree();
    }

    return newNode;
}


int main() {
    struct Node* root = NULL;

    printf("Create the binary tree:\n");
    root = createTree();

    

    return 0;
}
