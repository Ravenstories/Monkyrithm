#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialiserer tilfældig nummergenerator
    srand(time(0));

    // Antallet af elementer i arrayet
    const int size = 100;

    // Definerer de nedre og øvre grænser for tilfældige tal
    int lower = 1, upper = 1000;

    //PointerFreeFunctions(lower, upper, size);
    PointerFunctions(lower, upper, size);

    return 0;
}

void PointerFreeFunctions(int lower, int upper, const int size) {
    int noPointerArr[100];

    generateRandomNumbersWithoutPointer(noPointerArr, size, lower, upper);

    // Udskriver elementerne i arrayet
    printf("Tilfældige tal i arrayet: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", noPointerArr[i]);
    }
    printf("\n\n");

    // Sorterer arrayet

    selectionSort(noPointerArr, size);
    printf("Sorterede tal i arrayet: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", noPointerArr[i]);
    }
    //*/


    // Frigør hukommelsen
    free(noPointerArr);
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

    printf("Tilfældige tal i arrayet: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    selectionSortPointers(arr, size);
    printf("Pointer-Selection-Sorted tal i arrayet:\n");
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

