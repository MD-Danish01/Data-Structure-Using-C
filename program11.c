/*
Write a C program to search an element using Binary Search (for sorted arrays only). Also,
count and display the number of comparisons made.
*/

#include<stdio.h>

int main(){
    int arr[] = {0, 1, 3, 5, 6, 8, 12, 14, 22, 27, 30};
    int key = 12, mid, start = 0, end = 10, found = -1, count = 0;
    
    while(start <= end){
        count++;
        mid = start + (end - start)/2;
        if(arr[mid] > key){
            end = mid - 1;
        }else if(arr[mid] < key){
            start = mid + 1;
        }else{
            found = mid;
            break;
        }
    }

    if(found == -1){
        printf("key %d not found in list.\n", key);
    }else{
        printf("key %d found at index %d.\n", key, found);
    }

    printf("Number of comparision made : %d", count);

    return 0;
}