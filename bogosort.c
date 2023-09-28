int number_of_comparisons = 0;

// Function to check if an array is sorted
int isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0; 
        }
    }
    // If the array is sorted
    return 1; 
}

// Function to shuffle an array randomly
void shuffle(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        // Swap arr[i] and arr[j]
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Function to perform bogosort
void bogoSort(int arr[], int n) {
    while (!isSorted(arr, n)) {
        number_of_comparisons++;
        printf("\033[A\33[2KT\rNumber of comparisons: %d\n", number_of_comparisons);
        shuffle(arr, n);
    }
}


