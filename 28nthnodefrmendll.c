#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
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

// Function to insert a new node at the end of the linked list
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
    }
}

// Function to find the Nth node from the end of the linked list
int findNthFromEnd(struct Node* head, int n) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return -1;
    }

    // Initialize two pointers
    struct Node* first_ptr = head;
    struct Node* second_ptr = head;

    // Move the second pointer ahead by n positions
    for (int i = 0; i < n; i++) {
        if (second_ptr == NULL) {
            printf("Invalid value of n.\n");
            return -1;
        }
        second_ptr = second_ptr->next;
    }

    // Move both pointers until the second pointer reaches the end
    while (second_ptr != NULL) {
        first_ptr = first_ptr->next;
        second_ptr = second_ptr->next;
    }

    // The first pointer will now be at the Nth node from the end
    return first_ptr->data;
}

// Function to print the linked list
void printList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // Print the original linked list
    printf("Original linked list:\n");
    printList(head);

    // Find the Nth node from the end of the linked list
    int n = 2;
    int nth_from_end = findNthFromEnd(head, n);
    if (nth_from_end != -1) {
        printf("The %dth node from the end is: %d\n", n, nth_from_end);
    }

    return 0;
}
