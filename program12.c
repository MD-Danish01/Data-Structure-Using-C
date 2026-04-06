/*
Write a C program to sort a list of integers using Bubble Sort and display the number of
passes and swaps performed.
*/
#include <stdio.h>

int main()
{
    int arr[] = {5, 3, 4, 2, 9, 12, 8, 11, 10, 0};

    int n = sizeof(arr) / sizeof(int);

    int pass = 0, swap = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            pass++;
            if (arr[j] > arr[j + 1])
            {
                swap++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted list : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }

    printf("\nNumber of pass is :%d\n", pass);
    printf("Number of swaps is :%d\n",swap);

    return 0;
}