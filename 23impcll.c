#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the circular linked list
struct Node {
    int data;
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
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the circular linked list
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        newNode->next = newNode; // If the list is empty, set the next of the new node to itself
    } else {
        struct Node* last = *head_ref;
        while (last->next != *head_ref) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head_ref;
    }
    *head_ref = newNode;
}

// Function to insert a new node at the end of the circular linked list
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        newNode->next = newNode; // If the list is empty, set the next of the new node to itself
        *head_ref = newNode;
    } else {
        struct Node* last = *head_ref;
        while (last->next != *head_ref) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head_ref;
    }
}

// Function to print the circular linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert some nodes at the beginning
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    // Print the list
    printf("Circular linked list after insertion at the beginning: ");
    printList(head);

    // Insert some nodes at the end
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // Print the list
    printf("Circular linked list after insertion at the end: ");
    printList(head);

    return 0;
}
