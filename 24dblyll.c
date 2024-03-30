#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the doubly linked list
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
    } else {
        newNode->next = *head_ref;
        (*head_ref)->prev = newNode;
        *head_ref = newNode;
    }
}

// Function to insert a new node at the end of the doubly linked list
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
    } else {
        struct Node* temp = *head_ref;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to print the doubly linked list in forward direction
void printForward(struct Node* head) {
    printf("Doubly linked list (forward): ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to print the doubly linked list in reverse direction
void printReverse(struct Node* head) {
    printf("Doubly linked list (reverse): ");
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    // Print the doubly linked list in forward and reverse directions
    printForward(head);
    printReverse(head);

    // Insert nodes at the end
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // Print the doubly linked list in forward and reverse directions
    printForward(head);
    printReverse(head);

    return 0;
}
