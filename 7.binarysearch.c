#include <stdio.h>

int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid; // Key found at index mid
        }
        if (arr[mid] < key) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Key not found
}

int main() {
    int arr[] = {2, 5, 7, 9, 12, 15, 18};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 12;
    
    int result = binarySearch(arr, size, key);
    
    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array\n", key);
    }
    
    return 0;
}
