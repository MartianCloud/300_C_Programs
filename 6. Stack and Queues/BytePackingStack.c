#include <stdio.h>
#include <stdint.h>

#define STACK_SIZE 32  // Size of the stack in 32-bit words

// Structure to represent the packed stack
struct PackedStack {
    uint32_t stack[STACK_SIZE];
    int top;
};

// Initialize the packed stack
void initPackedStack(struct PackedStack *ps) {
    ps->top = -1;
}

// Push a byte onto the packed stack
void pushByte(struct PackedStack *ps, uint8_t data) {
    if (ps->top < STACK_SIZE - 1) {
        // Determine the index and shift value within a 32-bit word
        int index = ps->top / 4;
        int shift = (ps->top % 4) * 8;
        
        // Store the data in the corresponding 32-bit word
        ps->stack[index] |= ((uint32_t)data << shift);
        ps->top++;
    } else {
        printf("Stack overflow\n");
    }
}

// Pop a byte from the packed stack
uint8_t popByte(struct PackedStack *ps) {
    if (ps->top >= 0) {
        // Determine the index and shift value within a 32-bit word
        int index = ps->top / 4;
        int shift = (ps->top % 4) * 8;
        
        // Extract and return the byte
        uint8_t data = (ps->stack[index] >> shift) & 0xFF;
        ps->top--;
        return data;
    } else {
        printf("Stack underflow\n");
        return 0;
    }
}

int main() {
    struct PackedStack packedStack;
    initPackedStack(&packedStack);

    // Push 4 bytes onto the packed stack
    pushByte(&packedStack, 0x01);
    pushByte(&packedStack, 0x02);
    pushByte(&packedStack, 0x03);
    pushByte(&packedStack, 0x04);

    // Pop all 4 bytes and print them
    printf("Popped bytes: 0x%02X 0x%02X 0x%02X 0x%02X\n",
           popByte(&packedStack), popByte(&packedStack),
           popByte(&packedStack), popByte(&packedStack));

    return 0;
}
