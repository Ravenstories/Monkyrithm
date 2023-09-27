#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int size){
    int i, j, min_idx;

    for (i = 0; i < size-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < size; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

void selectionSortPointers(int *arr, int size) {
    int i, j, *min_idx;

    for (i = 0; i < size-1; i++) {
        min_idx = arr + i;
        for (j = i+1; j < size; j++) {
            if (*(arr + j) < *(min_idx)){
                //printf("\nNo crash! I: %d, J: %d\n", i, j);
                min_idx = arr + j;
            }
        }
        swap(min_idx, arr+i);
    }
}
