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

// Function to print the right view of the binary tree
void rightViewUtil(struct Node* root, int level, int* max_level) {
    if (root == NULL) {
        return;
    }

    // If this is the first node of its level, print it and update max_level
    if (*max_level < level) {
        printf("%d ", root->data);
        *max_level = level;
    }

    // Recur for right subtree first to print the rightmost node at each level
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}

void rightView(struct Node* root) {
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
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

    // Print the right view of the binary tree
    printf("Right View: ");
    rightView(root);
    printf("\n");

    return 0;
}
