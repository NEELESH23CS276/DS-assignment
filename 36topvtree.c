#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Structure to store the horizontal distance of a node from the root
struct QueueNode {
    struct Node* node;
    int hd; // Horizontal distance
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

// Function to insert a new node into the queue
void enqueue(struct QueueNode** queue, struct Node* node, int hd) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->node = node;
    newNode->hd = hd;
    newNode->next = NULL;

    if (*queue == NULL) {
        *queue = newNode;
    } else {
        struct QueueNode* temp = *queue;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to remove a node from the queue
struct QueueNode* dequeue(struct QueueNode** queue) {
    if (*queue == NULL) {
        return NULL;
    }
    struct QueueNode* temp = *queue;
    *queue = (*queue)->next;
    return temp;
}

// Function to print the top view of the binary tree
void topView(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct QueueNode* queue = NULL;
    enqueue(&queue, root, 0);

    bool *visited = (bool *)calloc(1000, sizeof(bool));

    printf("Top View: ");
    while (queue != NULL) {
        struct QueueNode* current = dequeue(&queue);
        int hd = current->hd;
        struct Node* node = current->node;

        if (!visited[hd]) {
            printf("%d ", node->data);
            visited[hd] = true;
        }

        if (node->left != NULL) {
            enqueue(&queue, node->left, hd - 1);
        }
        if (node->right != NULL) {
            enqueue(&queue, node->right, hd + 1);
        }

        free(current);
    }
    printf("\n");

    free(visited);
}

// Main function
int main() {
    // Create the binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(4);
    root->left->right->right = createNode(5);
    root->left->right->right->right = createNode(6);

    // Print the top view of the binary tree
    topView(root);

    return 0;
}
