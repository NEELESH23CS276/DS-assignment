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

// Function to find the diameter of a binary tree
int diameter(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    // Compute the height of the left and right subtrees recursively
    int left_height = height(root->left);
    int right_height = height(root->right);

    // Calculate the diameter recursively for left and right subtrees
    int left_diameter = diameter(root->left);
    int right_diameter = diameter(root->right);

    // Return the maximum of the three values: diameter of left subtree, diameter of right subtree, and height of left subtree + height of right subtree + 1 (for root)
    return (left_height + right_height + 1 > left_diameter && left_height + right_height + 1 > right_diameter) ? left_height + right_height + 1 : (left_diameter > right_diameter) ? left_diameter : right_diameter;
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

    // Find the diameter of the binary tree
    int tree_diameter = diameter(root);
    printf("Diameter of the binary tree: %d\n", tree_diameter);

    return 0;
}
