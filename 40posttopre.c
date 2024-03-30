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

// Function to search for a value in the inorder traversal
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) {
            return i;
        }
    }
    return -1; // Not found
}

// Function to construct the binary tree from postorder and inorder traversals
struct Node* buildTreeUtil(int postorder[], int inorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    // Create a node with the current root (last element in postorder traversal)
    struct Node* root = createNode(postorder[*postIndex]);
    (*postIndex)--;

    if (inStart == inEnd) {
        return root;
    }

    // Find the index of the current root in the inorder traversal
    int inIndex = search(inorder, inStart, inEnd, root->data);

    // Construct the right subtree
    root->right = buildTreeUtil(postorder, inorder, inIndex + 1, inEnd, postIndex);
    // Construct the left subtree
    root->left = buildTreeUtil(postorder, inorder, inStart, inIndex - 1, postIndex);

    return root;
}

// Function to construct the binary tree from postorder and inorder traversals
struct Node* buildTree(int postorder[], int inorder[], int size) {
    int postIndex = size - 1;
    return buildTreeUtil(postorder, inorder, 0, size - 1, &postIndex);
}

// Function to perform preorder traversal of the binary tree
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Main function
int main() {
    // Postorder and inorder traversals of the binary tree
    int postorder[] = {4, 5, 2, 6, 7, 3, 1};
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int size = sizeof(postorder) / sizeof(postorder[0]);

    // Construct the binary tree
    struct Node* root = buildTree(postorder, inorder, size);

    // Print the preorder traversal of the binary tree
    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    return 0;
}
