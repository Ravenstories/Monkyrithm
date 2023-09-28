#include <stdio.h>
#include <stdlib.h>

void insertionSort (int arr[], int size) {
    // I is the main iteration, and we start at position 1, so we can always compare backwards (so we start comparing position 1 to position 0)
    for (int i = 1; i < size; i++) {
        // j is for iterating through the sorted part of the array, thus it does not exceed i.
        for (int j = 0; j < i; j++) {
            // The first time it encounters a value that is greater than itself, have it "inserted", aka. moved down the array to that position
            if (arr[i] < arr[j]) {
                moveIntDownArray(arr, j, i);
                break;
            }
        }
    }
}

void moveIntDownArray(int arr[], int insertIndex, int insertOrigin) {
    // i starts at the insertOrigin index, and will continue moving until it reaches the insertion index, swapping each pair value along the way
    for (int i = insertOrigin; i > insertIndex; i--) {
        swap(&arr[i], &arr[i-1]);
    }
}


void insertionSortPointers(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (*(arr + i) < *(arr + j)) {
                moveIntDownArrayPointers(arr, j, i);
                break;
            }
        }
    }
}

void moveIntDownArrayPointers(int *arr, int insertIndex, int insertOrigin) {
    for (int i = insertOrigin; i > insertIndex; i--) {
        swap(arr + i, arr + i - 1);
    }
}