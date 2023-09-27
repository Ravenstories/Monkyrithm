#include <stdio.h>
#include <stdlib.h>

// Main function to perform merge sort on an array
// arr[]: Array to be sorted, l: Left index, r: Right index 
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Find the middle point of the array
        int m = l + (r - l) / 2;

        // Recursively sort the first and second halves 
        //printf("Splitting: l=%d, m=%d, r=%d\n", l, m, r);
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves 
        //printf("Merging: l=%d, m=%d, r=%d\n", l, m, r);
        merge(arr, l, m, r);
    }
}

// Function to merge two subarrays of arr[]
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    // Merge the temporary arrays back into arr[l..r]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


////////////////////////////////////////////////////////////

void mergePointers(int *arr, int *left, int *middle, int *right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = left[i];
    for (int j = 0; j < n2; j++)
        R[j] = middle[j + 1];

    int *i = L;
    int *j = R;
    int *k = left;

    while (i - L < n1 && j - R < n2) {
        if (*i <= *j) {
            *k = *i;
            i++;
        } else {
            *k = *j;
            j++;
        }
        k++;
    }

    while (i - L < n1) {
        *k = *i;
        i++;
        k++;
    }

    while (j - R < n2) {
        *k = *j;
        j++;
        k++;
    }
}

// Main function to perform merge sort on an array
void mergeSortPointers(int *arr, int *left, int *right) {
    if (left < right) {
        int *middle = left + (right - left) / 2;

        mergeSortPointers(arr, left, middle);
        mergeSortPointers(arr, middle + 1, right);

        mergePointers(arr, left, middle, right);
    }
}
