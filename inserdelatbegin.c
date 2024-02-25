#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size = 0; // Initial size of array
    int choice, element;

    while (1) {
        // Display menu
        printf("\nArray Operations:\n");
        printf("1. Insertion at beginning\n");
        printf("2. Deletion from beginning\n");
        printf("3. Display array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insertion at beginning
                if (size == MAX_SIZE) {
                    printf("Array is full, insertion not possible.\n");
                } else {
                    printf("Enter the element to insert: ");
                    scanf("%d", &element);
                    // Shift elements to the right to make space for the new element
                    for (int i = size; i > 0; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[0] = element;
                    size++;
                    printf("Element inserted successfully.\n");
                }
                break;
            case 2: // Deletion from beginning
                if (size == 0) {
                    printf("Array is empty, deletion not possible.\n");
                } else {
                    printf("Deleted element: %d\n", arr[0]);
                    // Shift elements to the left to fill the gap created by deletion
                    for (int i = 0; i < size - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    size--;
                }
                break;
            case 3: // Display array
                if (size == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Array elements: ");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;
            case 4: // Exit
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    }

    return 0;
}
