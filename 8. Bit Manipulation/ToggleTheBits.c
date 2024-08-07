#include <stdio.h>

// Function to toggle the 3rd and 5th bits of an 8-bit number
unsigned char toggle_bits(unsigned char number) {
    // Create a mask with bits 3 and 5 set to 1 and the rest set to 0
    unsigned char mask = (1 << 2) | (1 << 4);

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


// // Online C compiler to run C program online
// #include <stdio.h>
// #include <stdint.h>
// int i=7;
// void printBin(uint8_t data){
//     while(i>=0){
//         printf("%d ",data>>i&1);
//         i--;
//     }
// }
// //XOR  1  0  1 0
// //     1  0  0 1 
// //     0  0  1 1

// int main() {
//     // Write C code here
//     uint8_t reg=0b10101010;
//     //printBin(reg);
//     uint8_t mask=0b00101000;
//     printBin(reg^mask);
    
//     return 0;
// }
