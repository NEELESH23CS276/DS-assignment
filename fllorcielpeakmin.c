#include <stdio.h>

// Function to find the largest element smaller than or equal to key
int findFloor(int arr[], int low, int high, int key) {
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return arr[mid];
        else if (arr[mid] < key) {
            result = arr[mid];
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return result;
}

// Function to find the smallest element greater than or equal to key
int findCeiling(int arr[], int low, int high, int key) {
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return arr[mid];
        else if (arr[mid] > key) {
            result = arr[mid];
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return result;
}

// Function to find the peak element in the array
int findPeak(int arr[], int low, int high) {
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid + 1])
            return arr[mid];
        else if (arr[mid] < arr[mid + 1])
            low = mid + 1;
        else
            high = mid;
    }
    return arr[low];
}

// Function to find the minimum element in the rotated sorted array
int findMinimum(int arr[], int low, int high) {
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[high])
            low = mid + 1;
        else if (arr[mid] < arr[high])
            high = mid;
        else // arr[mid] == arr[high]
            high--; // Move high pointer to the left
    }
    return arr[low];
}

// Main function
int main() {
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    printf("Floor of %d is: %d\n", key, findFloor(arr, 0, n - 1, key));
    printf("Ceiling of %d is: %d\n", key, findCeiling(arr, 0, n - 1, key));
    printf("Peak element is: %d\n", findPeak(arr, 0, n - 1));
    printf("Minimum element is: %d\n", findMinimum(arr, 0, n - 1));

    return 0;
}
