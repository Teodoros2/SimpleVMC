#include <stdio.h>
#include "vm.h"
#include "instructions.h"

void push(VM *vm, int value) {
    if (vm->stackPointer < STACK_SIZE - 1) {
        vm->stack[++vm->stackPointer] = value;
    } else {
        printf("Stack overflow!\n");
    }
}

int pop(VM *vm) {
    if (vm->stackPointer >= 0) {
        return vm->stack[vm->stackPointer--];
    } else {
        printf("Stack underflow!\n");
        return 0; // Return 0 or handle error appropriately
    }
}

void add(VM *vm) {
    int b = pop(vm);
    int a = pop(vm);
    push(vm, a + b);
}

void sub(VM *vm) {
    int b = pop(vm);
    int a = pop(vm);
    push(vm, a - b);
}
