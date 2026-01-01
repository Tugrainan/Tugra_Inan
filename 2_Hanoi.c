//The Tower of Hanoi is a classic mathematical puzzle used to explain recursion
//in computer science. The goal is to move a stack of disks from one rod to another.
//There are only three simple rules: you can only move one disk at a time, you can
//only take the top disk from a stack, and you can never place a larger disk on top of a smaller one.




#include <stdio.h>

// n: number of disks
// from_rod: the rod we start with
// to_rod: the rod we want to go to
// aux_rod: the middle rod we use for help
void solveHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    // Base Case: If there is only 1 disk, just move it
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        return;
    }

    // Step 1: Move n-1 disks from start to middle rod
    solveHanoi(n - 1, from_rod, aux_rod, to_rod);

    // Step 2: Move the remaining disk to the target rod
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);

    // Step 3: Move the n-1 disks from middle to target rod
    solveHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int disks = 3;
    printf("Steps to solve Tower of Hanoi with %d disks:\n", disks);

    // A, B, and C are the names of the rods
    solveHanoi(disks, 'A', 'C', 'B');

    return 0;
}
