#include <stdio.h>

// Function to print the tree elements as they appear in the array
void printTreeArray(int tree[], int size) {
    printf("Tree as an Array: ");
    for (int i = 0; i < size; i++) {
        if (tree[i] != -1) // -1 represents an empty node
            printf("%d ", tree[i]);
        else
            printf("_ ");
    }
    printf("\n");
}

int main() {


    int tree[10]; // Creating an array to act as a tree
    int size = 5;

    // Manually assigning values based on our formulas
    tree[0] = 10; // Root
    tree[1] = 20; // Left of 10 (2*0 + 1)
    tree[2] = 30; // Right of 10 (2*0 + 2)
    tree[3] = 40; // Left of 20 (2*1 + 1)
    tree[4] = 50; // Right of 20 (2*1 + 2)

    printTreeArray(tree, size);

    // Example of finding a child
    int rootIndex = 0;
    printf("The left child of root (%d) is: %d\n", tree[rootIndex], tree[2 * rootIndex + 1]);

    return 0;
}
