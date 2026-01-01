//This code, I implemented nodes with preserving child parent relationship


#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to fix the heap after adding a new element
void heapify(int arr[], int size, int i) {
    int parent = (i - 1) / 2;

    if (parent >= 0) {
        // If child is bigger than parent, swap them (Max Heap rule)
        if (arr[i] > arr[parent]) {
            swap(&arr[i], &arr[parent]);
            // Check the parent's parent recursively
            heapify(arr, size, parent);
        }
    }
}

int main() {
    int heap[100];
    int size = 0;

    // Inserting values: 10, 20, 15
    heap[size] = 10; size++;
    heap[size] = 20; heapify(heap, size, size); size++;
    heap[size] = 15; heapify(heap, size, size); size++;

    printf("Max Heap Root (Largest): %d\n", heap[0]); // Should be 20

    return 0;
}
