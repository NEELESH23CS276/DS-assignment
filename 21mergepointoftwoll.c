#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to find the length of a linked list
int length(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find the merge point of two linked lists
struct Node* findMergePoint(struct Node* head1, struct Node* head2) {
    int len1 = length(head1);
    int len2 = length(head2);
    
    int diff = abs(len1 - len2);
    
    // Traverse the longer list by the absolute difference
    if (len1 > len2) {
        for (int i = 0; i < diff; i++) {
            head1 = head1->next;
        }
    } else {
        for (int i = 0; i < diff; i++) {
            head2 = head2->next;
        }
    }
    
    // Traverse both lists simultaneously until a common node is found
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) {
            return head1; // Found the merge point
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    
    return NULL; // No merge point found
}

// Main function
int main() {
    // Creating linked list 1: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
    struct Node* head1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fifth1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* sixth1 = (struct Node*)malloc(sizeof(struct Node));

    head1->data = 1;
    head1->next = second1;
    second1->data = 2;
    second1->next = third1;
    third1->data = 3;
    third1->next = fourth1;
    fourth1->data = 4;
    fourth1->next = fifth1;
    fifth1->data = 5;
    fifth1->next = sixth1;
    sixth1->data = 6;
    sixth1->next = NULL;

    // Creating linked list 2: 9 -> 10 -> 11 -> 12 -> NULL
    struct Node* head2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth2 = (struct Node*)malloc(sizeof(struct Node));

    head2->data = 9;
    head2->next = second2;
    second2->data = 10;
    second2->next = third2;
    third2->data = 11;
    third2->next = fourth2;
    fourth2->data = 12;
    fourth2->next = NULL;

    // Creating a common node between the two lists
    fourth1->next = third2;

    // Find merge point
    struct Node* mergePoint = findMergePoint(head1, head2);

    if (mergePoint != NULL) {
        printf("Merge point data: %d\n", mergePoint->data);
    } else {
        printf("No merge point found.\n");
    }

    // Free allocated memory
    free(head1);
    free(second1);
    free(third1);
    free(fourth1);
    free(fifth1);
    free(sixth1);
    free(head2);
    free(second2);
    free(third2);
    free(fourth2);

    return 0;
}
