#include <stdio.h>

// 1. Traversal: Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 2. Insertion: Adding an element at a specific index
void insertElement(int arr[], int *size, int element, int index) {
    // Shift elements to the right to make space
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    // Insert the new element
    arr[index] = element;
    // Increase the size of the array
    (*size)++;
}

// 3. Deletion: Removing an element from a specific index
void deleteElement(int arr[], int *size, int index) {
    // Shift elements to the left to fill the gap
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    // Decrease the size of the array
    (*size)--;
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int size = 5;

    printf("Original Array: ");
    printArray(arr, size);

    // Insert 25 at index 2
    insertElement(arr, &size, 25, 2);
    printf("After Insertion: ");
    printArray(arr, size);

    // Delete element at index 3
    deleteElement(arr, &size, 3);
    printf("After Deletion: ");
    printArray(arr, size);

    return 0;
}
