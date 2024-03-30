#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    // Assign data to the new node
    new_node->data = new_data;
    new_node->next = NULL;
    
    // If the list is empty, make the new node as the head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    
    // Traverse to the end of the list
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    
    // Connect the new node to the end of the list
    last->next = new_node;
}

// Function to delete the last node of the linked list
void deleteAtEnd(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    
    // If the list has only one node, delete it and set head to NULL
    if ((*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }
    
    // Traverse to the second last node
    struct Node* second_last = *head_ref;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }
    
    // Delete the last node and set second last's next to NULL
    free(second_last->next);
    second_last->next = NULL;
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
    
    // Insert some nodes at the end
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    
    // Print the initial list
    printf("Initial list: ");
    printList(head);
    
    // Delete the last node
    deleteAtEnd(&head);
    
    // Print the updated list
    printf("List after deletion: ");
    printList(head);
    
    return 0;
}
