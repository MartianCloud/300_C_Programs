#include <stdio.h>

void optimized_bubble_sort(int arr[], int size) {
    int swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = 0;  // Initialize a flag to check if any swaps were made in this pass
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;  // Set the flag to indicate a swap was made
            }
        } 
        if (swapped == 0) {
            // If no swaps were made in this pass, the array is already sorted
            break;


        }
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    optimized_bubble_sort(arr, size);

    printf("\nSorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
