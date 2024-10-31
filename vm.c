#include <stdio.h>
#include <stdlib.h>
#include "vm.h"
#include "instructions.h"

void initVM(VM *vm) {
    vm->stack = malloc(sizeof(int) * STACK_SIZE);
    vm->stackPointer = -1;
}

void cleanupVM(VM *vm) {
    free(vm->stack);
}

void loadProgram(VM *vm, uint8_t *program, size_t size) {
    vm->program = program;
    vm->programSize = size;
    vm->programCounter = 0;
}

void runVM(VM *vm) {
    while (vm->programCounter < vm->programSize) {
        uint8_t instruction = vm->program[vm->programCounter++];
        switch (instruction) {
            case OP_PUSH:
                push(vm, vm->program[vm->programCounter++]);
                break;
            case OP_POP:
                pop(vm);
                break;
            case OP_ADD:
                add(vm);
                break;
            case OP_SUB:
                sub(vm);
                break;
            default:
                printf("Unknown instruction: %d\n", instruction);
                return;
        }
    }
}
