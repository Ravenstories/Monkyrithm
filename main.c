#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialiserer tilfældig nummergenerator
    srand(time(0));

    // Antallet af elementer i arrayet
    int size = 400;

    // Definerer de nedre og øvre grænser for tilfældige tal
    int lower = 1, upper = 1000;
    
    printf("\nWithout Pointers\n");
    PointerFreeFunctions(lower, upper, size);
    printf("\n\nWith Pointers\n");
    PointerFunctions(lower, upper, size);

    return 0;
}


void PointerFreeFunctions(int lower, int upper, const int size) {
    int noPointerArr[size];

    generateRandomNumbersWithoutPointer(noPointerArr, size, lower, upper);

    // Udskriver elementerne i arrayet
    printf("Pre Sorting: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", noPointerArr[i]);
    }
    printf("\n\n");

   //Sorting algorithms:
        //selectionSort(noPointerArr, size);
    mergeSort(noPointerArr, 0, size - 1);
    
    printf("Sorted Without Pointers: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", noPointerArr[i]);
    }
    //*/
}

void PointerFunctions(int lower, int upper, const int size) {

    // Allokerer hukommelse til arrayet
    int *arr = malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Hukommelse kunne ikke allokeres.\n");
        return 1;
    }

    // Genererer tilfældige tal og gemmer dem i arrayet
    generateRandomNumbers(arr, size, lower, upper);

    printf("Pre-Sorting: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    //Sorting algorithms:
        //selectionSortPointers(arr, size);
    mergeSortPointers(arr, arr, arr + size - 1);
    //arr, arr, arr + arr_size - 1
    printf("Sorted With Pointers:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    //*/

    free(arr);
}

void generateRandomNumbers(int *arr, int size, int lower, int upper) {
    for (int i = 0; i < size; ++i) {
        arr[i] = (rand() % (upper - lower + 1)) + lower;
    }
}
void generateRandomNumbersWithoutPointer(int arr[], int size, int lower, int upper) {
    for (int i = 0; i < size; ++i) {
        arr[i] = (rand() % (upper - lower + 1)) + lower;
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

