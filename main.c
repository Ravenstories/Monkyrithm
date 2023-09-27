#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialiserer tilfældig nummergenerator
    srand(time(0));

    // Antallet af elementer i arrayet
    int size = 100;

    // Allokerer hukommelse til arrayet
    int *arr = malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Hukommelse kunne ikke allokeres.\n");
        return 1;
    }

    // Definerer de nedre og øvre grænser for tilfældige tal
    int lower = 1, upper = 1000;

    // Genererer tilfældige tal og gemmer dem i arrayet
    generateRandomNumbers(arr, size, lower, upper);

    // Udskriver elementerne i arrayet
    printf("Tilfældige tal i arrayet: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Sorterer arrayet
    selectionSort(arr, size);
    printf("Sorterede tal i arrayet: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }

    // Frigør hukommelsen
    free(arr);

    return 0;
}

void generateRandomNumbers(int *arr, int size, int lower, int upper) {
    for (int i = 0; i < size; ++i) {
        arr[i] = (rand() % (upper - lower + 1)) + lower;
    }
}

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

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

