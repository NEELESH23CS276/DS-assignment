#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function for postorder traversal of the binary tree
void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left); // Recursively traverse the left subtree
    postorderTraversal(root->right); // Recursively traverse the right subtree
    printf("%d ", root->data); // Print the data of the current node
}

// Main function
int main() {
    // Create the binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Perform postorder traversal and print the elements
    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
