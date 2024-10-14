#include <stdio.h>

int main()
{
    int row, column;
    // Declare a 2D array with 3 rows and 4 columns
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {4, 5, 6, 7},
        {67, 85, 5, 7}
    };

    // Iterate through each row of the matrix
    for (row = 0; row < 3; row++)
    {
        // Iterate through each column of the current row
        for (column = 0; column < 4; column++)
        {
            // Print the element at the current row and column
            printf("%d ", matrix[row][column]);
        }
        // Move to the next line after printing each row
        printf("\n");
    }
    return 0;
}
