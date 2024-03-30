#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    // Assign data to the new node
    new_node->data = new_data;
    
    // Set the next pointer of the new node to the current head
    new_node->next = *head_ref;
    
    // Update the head to point to the new node
    *head_ref = new_node;
}

// Function to delete the first node of the linked list
void deleteAtBeginning(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    
    // Store the current head node
    struct Node* temp = *head_ref;
    
    // Move head pointer to the next node
    *head_ref = (*head_ref)->next;
    
    // Free the memory of the old head node
    free(temp);
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
    
    // Insert some nodes at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    
    // Print the initial list
    printf("Initial list: ");
    printList(head);
    
    // Delete the first node
    deleteAtBeginning(&head);
    
    // Print the updated list
    printf("List after deletion: ");
    printList(head);
    
    return 0;
}
