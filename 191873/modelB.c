#include <stdio.h> // Standard input-output library

int main() {
    // Declare variables for row and column indices
    int rowIndex, colIndex;

    // Initialize a 2D array (matrix) with 3 rows and 4 columns
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {4, 5, 6, 7},
        {67, 85, 5, 7}
    };
    printf("Matrix is:\n");
    
    for (rowIndex = 0; rowIndex < 3; rowIndex++)// Loop through each row i.e 3 of the matrix
        {
        for (colIndex = 0; colIndex < 4; colIndex++)  // Loop through each column i.e 4 in the current row
        {
            printf("%d ", matrix[rowIndex][colIndex]);// Print the element at the current row and column
        }
        printf("\n");// Move to the next line after printing all elements in the row
    }
    return 0; // Program ends
}
