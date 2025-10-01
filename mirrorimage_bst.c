#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* create(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return create(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}


void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


void mirrorImage(struct Node* tree) {
    if (tree != NULL) {
        
        mirrorImage(tree->left);
        mirrorImage(tree->right);

        
        struct Node* temp = tree->left;
        tree->left = tree->right;
        tree->right = temp;
    }
}


int main() {
    struct Node* root = NULL;
    int n, data;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("\nInorder traversal before mirroring: ");
    inorder(root);

    
    mirrorImage(root);

    printf("\nInorder traversal after mirroring: ");
    inorder(root);

    return 0;
}
