//A Sparse Matrix is a special type of matrix where most of the elements are zero. In computer science, storing thousands of
//zeros is a waste of memory and processing power. To be more efficient,
// we only store the 'useful' information: the row index, the column index, and the non-zero value.




#include <stdio.h>

int main() {
    // A 4x4 matrix with only 3 non-zero elements
    int matrix[4][4] = {
        {0, 0, 0, 10},
        {0, 5, 0, 0},
        {0, 0, 0, 0},
        {7, 0, 0, 0}
    };

    printf("Representing the Sparse Matrix:\n");
    printf("Row\tColumn\tValue\n");
    printf("---\t------\t-----\n");

    // We loop through the matrix to find non-zero numbers
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matrix[i][j] != 0) {
                printf("%d\t%d\t%d\n", i, j, matrix[i][j]);
            }
        }
    }

    return 0;
}
