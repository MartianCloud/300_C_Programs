#include <stdio.h>
#include <stdint.h>

#define MEMORY_SIZE 100

// Structure to represent each allocation
struct Allocation {
    size_t size;
    void* address;
};

// Global memory pool
uint8_t memory[MEMORY_SIZE];
int stackTop = 0; // Initialize the stack top to the beginning of the memory pool

// Function to allocate memory
struct Allocation allocate(size_t size) {
    struct Allocation allocation;
    if (stackTop + size <= MEMORY_SIZE) {
        allocation.size = size;
        allocation.address = &memory[stackTop];
        stackTop += size;
    } else {
        allocation.size = 0; // Allocation failed
        allocation.address = NULL;
    }
    return allocation;
}

// Function to free memory
void free_memory(struct Allocation allocation) {
    // Check if the address to free matches the current stack top
    if (allocation.address == &memory[stackTop - allocation.size]) {
        stackTop -= allocation.size; // Move the stack top back
    } else {
        printf("Invalid free operation\n");
    }
}

int main() {
    struct Allocation alloc1 = allocate(10);
    struct Allocation alloc2 = allocate(20);
    struct Allocation alloc3 = allocate(15);

    printf("Allocated 10 bytes at address %p\n", alloc1.address);
    printf("Allocated 20 bytes at address %p\n", alloc2.address);
    printf("Allocated 15 bytes at address %p\n", alloc3.address);

    free_memory(alloc3);
    printf("Freed 15 bytes\n");

    // Next available address after freeing
    printf("Next available address after freeing: %p\n", &memory[stackTop]);

    return 0;
}
