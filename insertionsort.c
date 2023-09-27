#include <stdio.h>
#include <stdlib.h>

void insertionSort (int arr[], int size) {

    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] < arr[j]) {
                moveIntDownArray(arr, j, i);
                break;
            }
        }
    }
}

void moveIntDownArray(int arr[], int insertIndex, int insertOrigin) {
    for (int i = insertOrigin; i > insertIndex; i--) {
        swap(&arr[i], &arr[i-1]);
    }
}


void insertionSortPointers(int *arr, int size) {
}