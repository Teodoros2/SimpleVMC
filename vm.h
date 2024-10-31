#ifndef VM_H
#define VM_H

#include <stdint.h>

#define STACK_SIZE 256

typedef struct {
    int *stack;
    int stackPointer;
    uint8_t *program;
    size_t programSize;
    size_t programCounter;
} VM;

void initVM(VM *vm);
void cleanupVM(VM *vm);
void loadProgram(VM *vm, uint8_t *program, size_t size);
void runVM(VM *vm);

#endif // VM_H
