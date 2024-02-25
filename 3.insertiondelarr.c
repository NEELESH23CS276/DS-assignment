#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size, pos, i, choice;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Input array elements
    printf("Enter elements of the array: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

   
    printf("Enter 1 for insertion and 2 for deletion: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: // Insertion
            printf("Enter the position where you want to insert: ");
            scanf("%d", &pos);
            if (pos < 0 || pos > size) {
                printf("Invalid position!\n");
                return 1;
            }
            printf("Enter the element to insert: ");
            int element;
            scanf("%d", &element);
            
            // Shift elements to the right 
            for (i = size - 1; i >= pos; i--) {
                arr[i + 1] = arr[i];
            }
            arr[pos] = element;
            size++; // Increase the size of the array
            break;
        case 2: // Deletion
            printf("Enter the position of element to delete: ");
            scanf("%d", &pos);
            if (pos < 0 || pos >= size) {
                printf("Invalid position!\n");
                return 1;
            }
            // Shifting elements to the left to fill the gap created by deletion
            for (i = pos; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--; // Decrease the size of the array
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    // Printing final arr
    printf("Array after operation:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
