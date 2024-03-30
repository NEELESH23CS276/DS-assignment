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

// Function to find the height of a binary tree
int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        // Compute the height of the left and right subtrees recursively
        int left_height = height(root->left);
        int right_height = height(root->right);
        
        // Return the maximum of the heights of the left and right subtrees, plus 1 for the current node
        return (left_height > right_height) ? (left_height + 1) : (right_height + 1);
    }
}

// Main function
int main() {
    // Create the binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Find the height of the binary tree
    int tree_height = height(root);
    printf("Height of the binary tree: %d\n", tree_height);

    return 0;
}
