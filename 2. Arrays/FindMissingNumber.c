#include <stdio.h>

int findMissingNumber(int arr[], int n) {
    // Calculate the sum of the first n natural numbers
    int expectedSum = (n * (n + 1)) / 2;

    // Calculate the actual sum of the array elements
    int actualSum = 0;
    for (int i = 0; i < n; i++) {
        actualSum += arr[i];
    }

    // The missing number is the difference between the expected and actual sums
    int missingNumber = expectedSum - actualSum;

    return missingNumber;
}

int main() {
    int arr[] = {1, 2, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int missingNumber = findMissingNumber(arr, n);

    printf("Missing number: %d\n", missingNumber);

    return 0;
}
