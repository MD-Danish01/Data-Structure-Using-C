/*
Write a C program to search an element using Sequential (Linear) Search on a user-defined
list of integers. Display appropriate messages for success/failure.
*/

#include<stdio.h>
#include<stdlib.h>

int linearSearch(int arr[], int size, int key){
    for(int i = 0; i < size; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){
    int size, target, index;
    printf("Enter size of list :");
    scanf("%d", &size);

    int *list = (int *) malloc(size * sizeof(int));
    if(!list){
        printf("memory allocation failed.\n");
        exit(1);
    }

    printf("Enter list values :\n");
    for(int i = 0; i < size; i++){
        scanf("%d", (list + i));
    }

    printf("Enter target value to be search in list :");
    scanf("%d", &target);

    index = linearSearch(list, size, target);

    if(index == -1){
        printf("target value %d not found in list.\n", target);
    }else{
        printf("target value %d found on index %d in list.\n", target, index);
    }

    return 0;
}