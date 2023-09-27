#include <stdio.h>
#include <stdlib.h>




void selectionSort(int *arr, int size){
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