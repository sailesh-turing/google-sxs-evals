/* Refractor the following code in "c_cpp/AayushTyagi1/c-programming-basics/array.c". Improve its readability and make it more organized. Include meaningful comments that explain each step of the code. Change the variable names to make the purpose of each variable clearer. Make sure you are following indentation and consistent formatting throughout the code. Also, only return code without directions, description, and justification.

This is the code:
*/
#include <stdio.h>

int main()
{
    /* int i;

    int z[4] = {1, 2, 3, 4};
    for (i=0;i<=3;i++)
    {
        printf("%d \n", z[i]);
    } */
    int j, k;
    int d[3][4] =
    {
        {1, 2, 3, 4},
        {4, 5, 6, 7},
        {67, 85, 5, 7}
    };
    for (j = 0; j < 3; j++)
    {
        for (k = 0; k < 4; k++)
        {
            printf("%d ", d[j][k]);
        }
        printf("\n");
    }
    return 0;
}