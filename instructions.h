#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "vm.h"

#define OP_PUSH 0x01
#define OP_POP  0x02
#define OP_ADD  0x03
#define OP_SUB  0x04

void push(VM *vm, int value);
int pop(VM *vm);
void add(VM *vm);
void sub(VM *vm);

#endif // INSTRUCTIONS_H
