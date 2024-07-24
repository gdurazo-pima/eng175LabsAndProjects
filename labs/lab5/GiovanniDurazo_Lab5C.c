#include <stdio.h> // print

/*
Pseudocode
int matrixA[3][3], matrixB[3][3], matrixC[3][3] for matrices
int i for index
int j for second index

print matrisA and matrixB for reference
//adding
for i = 0; i < 3; i++
    print adding matrixA, matrixB
    for j = 0; j < 3; j++
    matrixC[i][j] = matrixA[i][j] + matrixB[i][j]
    print matrixC[i][j]

//subtracting
repeat but subtract lol

//multiplication
matrixC[i][j] = 

//sum of right diagonals
add diagonal of matrixA

//transpose of matrix
matrixA[i][j] = matrix [j][i]

*/

int main(void)
{
    int matrixA[3][3] = { // initialize matrix
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    int matrixB[3][3] = { // initialize matrix
        {0, -1, -2},
        {1, 0, -1},
        {2, 1, 0},
    };
    int matrixC[3][3] = { // initialize matrix
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
    };
    int i; // index
    int j; // index
    int sum = 0; // sum for diagonal

    // prints matrix
    printf("Matrix A\n");
    for (i = 0; i < 3; i++)
    {
        printf("{ "); // format stuff
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matrixA[i][j]);
            if (j == 2)
            {
                printf("}\n"); // format stuff
            }
        }
    }

    // prints matrix
    printf("\nMatrix B\n");
    for (i = 0; i < 3; i++)
    {
        printf("{ "); // format stuff
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matrixB[i][j]);
            if (j == 2)
            {
                printf("}\n"); // format stuff
            }
        }
    }
    printf("\n"); // format stuff

    // addition
    printf("Matrix A + Matrix B =\n");
    for (i = 0; i < 3; i++)
    {
        printf("{ "); // format stuff
        for (j = 0; j < 3; j++)
        {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
            printf("%d ", matrixC[i][j]);
            if (j == 2)
            {
                printf("}\n"); // format stuff
            }
        }
    }
    printf("\n"); // format stuff

    // subtraction
    printf("Matrix A - Matrix B =\n");
    for (i = 0; i < 3; i++)
    {
        printf("{ "); // format stuff
        for (j = 0; j < 3; j++)
        {
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
            printf("%d ", matrixC[i][j]);
            if (j == 2)
            {
                printf("}\n"); // format stuff
            }
        }
    }
    printf("\n"); // format stuff

    // multiplication (no loops for my own sanity) (praying this doesn't count as hardcoding)
    printf("Matrix A * Matrix B =\n");
    matrixC[0][0] = (matrixA[0][0] * matrixB[0][0]) + (matrixA[0][1] * matrixB[1][0]) + (matrixA[0][2] * matrixB[2][0]); // I was going insane trying to do this using loops
    matrixC[0][1] = (matrixA[0][0] * matrixB[0][1]) + (matrixA[0][1] * matrixB[1][1]) + (matrixA[0][2] * matrixB[2][1]); // I was going insane trying to do this using loops
    matrixC[0][2] = (matrixA[0][0] * matrixB[0][2]) + (matrixA[0][1] * matrixB[1][2]) + (matrixA[0][2] * matrixB[2][2]); // I was going insane trying to do this using loops
    matrixC[1][0] = (matrixA[1][0] * matrixB[0][0]) + (matrixA[1][1] * matrixB[1][0]) + (matrixA[1][2] * matrixB[2][0]); // I was going insane trying to do this using loops
    matrixC[1][1] = (matrixA[1][0] * matrixB[0][1]) + (matrixA[1][1] * matrixB[1][1]) + (matrixA[1][2] * matrixB[2][1]); // I was going insane trying to do this using loops
    matrixC[1][2] = (matrixA[1][0] * matrixB[0][2]) + (matrixA[1][1] * matrixB[1][2]) + (matrixA[1][2] * matrixB[2][2]); // I was going insane trying to do this using loops
    matrixC[2][0] = (matrixA[2][0] * matrixB[0][0]) + (matrixA[2][1] * matrixB[1][0]) + (matrixA[2][2] * matrixB[2][0]); // I was going insane trying to do this using loops
    matrixC[2][1] = (matrixA[2][0] * matrixB[0][1]) + (matrixA[2][1] * matrixB[1][1]) + (matrixA[2][2] * matrixB[2][1]); // I was going insane trying to do this using loops
    matrixC[2][2] = (matrixA[2][0] * matrixB[0][2]) + (matrixA[2][1] * matrixB[1][2]) + (matrixA[2][2] * matrixB[2][2]); // I was going insane trying to do this using loops
    for (i = 0; i < 3; i++) // prints matrix c
    {
        printf("{ "); // format stuff
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matrixC[i][j]);
            if (j == 2) // format stuff
            {
                printf("}\n");
            }
        }
    }

    printf("\n"); // format stuff

    // sum of right diagonal (I had to look up what a right diagonal was)
    printf("Sum of Right Diagonal of Matrix A:\n");
    sum = matrixA[0][0] + matrixA[1][1] + matrixA[2][2]; // sums diagonal
    printf("%d\n\n", sum);

    // transpose
    printf("Transpose of Matrix A:\n");
    for (i = 0; i < 3; i++)
    {
        printf("{ "); // format stuff
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matrixA[j][i]); // transposes matrix lol
            if (j == 2)
            {
                printf("}\n"); // format stuff
            }
        }
    }


    return 0;
}