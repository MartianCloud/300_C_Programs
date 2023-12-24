#include <stdio.h>

// Function to toggle the 3rd and 5th bits of an 8-bit number
unsigned char toggle_bits(unsigned char number) {
    // Create a mask with bits 3 and 5 set to 1 and the rest set to 0
    unsigned char mask = (1 << 3) | (1 << 5);

    // Toggle the bits using XOR (^)
    return number ^ mask;
}

int main() {
    unsigned char input = 0b10100101;

    unsigned char result = toggle_bits(input);

    printf("Input: 0x%02X\n", input);
    printf("Output: 0x%02X\n", result);

    return 0;
}
