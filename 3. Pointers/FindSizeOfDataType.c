#include <stdio.h>

int main() {
    // Define the data type for which you want to find the size
    int data;

    // Declare a pointer to the data type
    int *ptr = &data;

    // Create a second pointer and set it to the next memory location
    int *ptr2 = ptr + 1;

    // Calculate the size by subtracting the original pointer from the incremented pointer
    size_t size = (char *)ptr2 - (char *)ptr;

    // Print the size
    printf("Size of int: %zu bytes\n", size);

    return 0;
}
