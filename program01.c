/*
Write a C program to create two matrices and perform addition, subtraction, and
multiplication operations with user-defined dimensions.
*/

#include <stdio.h>

void sumMatrices(int r1, int c1, int arr1[r1][c1], int r2, int c2, int arr2[r2][c2]);
void subtractionMatrices(int r1, int c1, int arr1[r1][c1], int r2, int c2, int arr2[r2][c2]);
void multiplicationMatrices(int r1, int c1, int arr1[r1][c1], int r2, int c2, int arr2[r2][c2]);

int main()
{
    int r = 0, c = 0, a = 0, b = 0;

    printf("Enter diemension of first Matrix.\nrow :");
    scanf("%d", &r);
    printf("Column :");
    scanf("%d", &c);

    int matrix1[r][c];

    printf("Enter diemension of second Matrix.\nrow :");
    scanf("%d", &a);
    printf("Column :");
    scanf("%d", &b);

    int matrix2[a][b];

    printf("Now enter values of first Matrix.\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("row = %d, column = %d :", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("\nNow enter values of second Matrix.\n");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("row = %d, column = %d :", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    sumMatrices(r, c, matrix1, a, b, matrix2);
    subtractionMatrices(r, c, matrix1, a, b, matrix2);
    multiplicationMatrices(r, c, matrix1, a, b, matrix2);

    return 0;
}

void sumMatrices(int r1, int c1, int arr1[r1][c1], int r2, int c2, int arr2[r2][c2])
{
    if (r1 == r2 && c1 == c2)
    {
        int sum[r1][c1];

        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                sum[i][j] = arr1[i][j] + arr2[i][j];
            }
        }

        printf("The sum of matrices is :\n");
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                printf("%d  ", sum[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("dissimilar matrix dimensions cannot be added.\n");
        return;
    }
}

void subtractionMatrices(int r1, int c1, int arr1[r1][c1], int r2, int c2, int arr2[r2][c2])
{
    if (r1 == r2 && c1 == c2)
    {
        int sub[r1][c1];
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                sub[i][j] = arr1[i][j] - arr2[i][j];
            }
        }

        printf("Subtraction of Matrices is :\n");
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                printf("%d  ", sub[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Can not subtract dissimilar dimensions matrices.\n");
        return;
    }
}

void multiplicationMatrices(int r1, int c1, int arr1[r1][c1], int r2, int c2, int arr2[r2][c2])
{
    if (r2 == c1)
    {
        int mul[r1][c2];
        for (int i = 0; i < c2; i++)
        {
            for (int j = 0; j < r1; j++)
            {
                mul[j][i] = 0;
                for (int k = 0; k < r2; k++)
                {
                    mul[j][i] += arr2[k][i] * arr1[j][k];
                }
            }
        }

        printf("multiplication of matrices is :\n");
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                printf("%d  ", mul[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("diemensions of matrices are not sutable for multiplication of matrices.\n");
        return;
    }
}
