#include <stdio.h>
#include "vm.h"

int main() {
    VM vm;
    initVM(&vm);
    
    // Example program: Push 5, Push 3, Add
    uint8_t program[] = {
        OP_PUSH, 5,
        OP_PUSH, 3,
        OP_ADD,
        OP_POP
    };
    
    loadProgram(&vm, program, sizeof(program));
    runVM(&vm);
    cleanupVM(&vm);
    
    return 0;
}
