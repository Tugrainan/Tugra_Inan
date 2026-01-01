#include <stdio.h>

// Traversal
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Taking reverse of array 
void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        // Swapping array elements
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Insertion of random element
void insertElement(int arr[], int *size, int element, int pos) {
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
    (*size)++;
}

// Deletion after spesific index
void deleteElement(int arr[], int *size, int pos) {
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

int main() {
    int arr[100] = {18, 34, 78, 14, 98}; 
    int size = 5; 

    printf("Array start: ");
    printArray(arr, size);

    //Insertion into 2nd index
    insertElement(arr, &size, 25, 2);
    printf("After add (2nd index 25): ");
    printArray(arr, size);

    // Removing 3rd index
    deleteElement(arr, &size, 3);
    printf("After removal (3rd index removed): ");
    printArray(arr, size);

    // Array traversal
    reverseArray(arr, size);
    printf("Traversed array: ");
    printArray(arr, size);

    return 0;
}