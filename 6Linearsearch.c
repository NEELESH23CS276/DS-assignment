#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Key found at index i
        }
    }
    return -1; // Key not found
}

int main() {
    int arr[] = {3, 7, 9, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 9;
    
    int result = linearSearch(arr, size, key);
    
    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array\n", key);
    }
    
    return 0;
}
