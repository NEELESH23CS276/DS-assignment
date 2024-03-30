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

// Function to find the lowest common ancestor (LCA) of two nodes in a binary tree
struct Node* lowestCommonAncestor(struct Node* root, int value1, int value2) {
    if (root == NULL) {
        return NULL;
    }

    // If either value1 or value2 matches the root's data, then the root itself is the LCA
    if (root->data == value1 || root->data == value2) {
        return root;
    }

    // Recursively find LCA in left and right subtrees
    struct Node* left_LCA = lowestCommonAncestor(root->left, value1, value2);
    struct Node* right_LCA = lowestCommonAncestor(root->right, value1, value2);

    // If both left_LCA and right_LCA are non-null, then the current node is the LCA
    if (left_LCA != NULL && right_LCA != NULL) {
        return root;
    }

    // Otherwise, return the non-null LCA (if any) from left or right subtree
    return (left_LCA != NULL) ? left_LCA : right_LCA;
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

    // Find the lowest common ancestor of two nodes
    int value1 = 4, value2 = 5;
    struct Node* lca = lowestCommonAncestor(root, value1, value2);
    printf("Lowest Common Ancestor of %d and %d is %d\n", value1, value2, lca->data);

    return 0;
}
