#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

// Function to detect and remove a cycle in the linked list
bool detectAndRemoveCycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    // Detect the cycle using Floyd's Cycle Detection Algorithm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    // If no cycle is detected, return false
    if (fast == NULL || fast->next == NULL)
        return false;

    // Move slow to the beginning of the list and find the start of the cycle
    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    // Remove the cycle by setting the next pointer of the last node in the cycle to NULL
    fast->next = NULL;

    return true;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Create a linked list with a cycle
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    head->next->next->next->next->next = head->next;

    // Detect and remove the cycle
    if (detectAndRemoveCycle(head))
        printf("Cycle detected and removed\n");
    else
        printf("No cycle detected\n");

    // Print the linked list after cycle removal
    printf("Linked list after cycle removal: ");
    printList(head);

    return 0;
}
