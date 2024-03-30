#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Function to reverse a linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to find the middle of the linked list
struct Node* findMiddle(struct Node* head) {
    struct Node* slow_ptr = head;
    struct Node* fast_ptr = head;

    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    return slow_ptr;
}

// Function to check if a linked list is palindrome or not
bool isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return true; // An empty list or a list with only one element is considered a palindrome
    }

    // Find the middle of the linked list
    struct Node* middle = findMiddle(head);

    // Reverse the second half of the linked list
    struct Node* second_half = reverseList(middle);

    // Compare the first half with the reversed second half
    struct Node* temp1 = head;
    struct Node* temp2 = second_half;
    while (temp1 != middle && temp2 != NULL) {
        if (temp1->data != temp2->data) {
            return false; // If data does not match, it's not a palindrome
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return true; // Linked list is palindrome
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
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 1);

    // Print the original linked list
    printf("Original linked list:\n");
    printList(head);

    // Check if the linked list is palindrome or not
    if (isPalindrome(head)) {
        printf("Linked list is a palindrome.\n");
    } else {
        printf("Linked list is not a palindrome.\n");
    }

    return 0;
}
