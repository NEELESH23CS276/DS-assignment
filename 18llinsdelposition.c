#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at a specified position in the linked list
void insertAtPosition(struct Node** head_ref, int new_data, int position) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    // Assign data to the new node
    new_node->data = new_data;
    
    // If position is 1, insert at the beginning
    if (position == 1) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    
    // Traverse to the node at position - 1
    struct Node* current = *head_ref;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    
    // Check if position is valid
    if (current == NULL) {
        printf("Invalid position!\n");
        return;
    }
    
    // Insert the new node after current
    new_node->next = current->next;
    current->next = new_node;
}

// Function to delete a node at a specified position in the linked list
void deleteAtPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    
    // If position is 1, delete the first node
    if (position == 1) {
        struct Node* temp = *head_ref;
        *head_ref = (*head_ref)->next;
        free(temp);
        return;
    }
    
    // Traverse to the node at position - 1
    struct Node* current = *head_ref;
    struct Node* prev = NULL;
    for (int i = 1; i < position && current != NULL; i++) {
        prev = current;
        current = current->next;
    }
    
    // Check if position is valid
    if (current == NULL) {
        printf("Invalid position!\n");
        return;
    }
    
    // Delete the node at the specified position
    prev->next = current->next;
    free(current);
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL; // Initialize an empty linked list
    
    // Insert some nodes at different positions
    insertAtPosition(&head, 10, 1); // Insert at beginning
    insertAtPosition(&head, 20, 2); // Insert at position 2
    insertAtPosition(&head, 30, 2); // Insert at position 2
    insertAtPosition(&head, 40, 4); // Insert at end
    
    // Print the initial list
    printf("Initial list: ");
    printList(head);
    
    // Delete nodes at different positions
    deleteAtPosition(&head, 2); // Delete node at position 2
    deleteAtPosition(&head, 3); // Delete node at position 3
    
    // Print the updated list
    printf("List after deletion: ");
    printList(head);
    
    return 0;
}
