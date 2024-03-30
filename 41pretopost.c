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

// Function to construct the binary tree from preorder and inorder traversals
struct Node* buildTreeUtil(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    // Create a node with the current root (first element in preorder traversal)
    struct Node* root = createNode(preorder[*preIndex]);
    (*preIndex)++;

    if (inStart == inEnd) {
        return root;
    }

    // Find the index of the current root in the inorder traversal
    int inIndex = search(inorder, inStart, inEnd, root->data);

    // Construct the left subtree
    root->left = buildTreeUtil(preorder, inorder, inStart, inIndex - 1, preIndex);
    // Construct the right subtree
    root->right = buildTreeUtil(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

// Function to construct the binary tree from preorder and inorder traversals
struct Node* buildTree(int preorder[], int inorder[], int size) {
    int preIndex = 0;
    return buildTreeUtil(preorder, inorder, 0, size - 1, &preIndex);
}

// Function to perform postorder traversal of the binary tree
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Main function
int main() {
    // Preorder and inorder traversals of the binary tree
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int size = sizeof(preorder) / sizeof(preorder[0]);

    // Construct the binary tree
    struct Node* root = buildTree(preorder, inorder, size);

    // Print the postorder traversal of the binary tree
    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
