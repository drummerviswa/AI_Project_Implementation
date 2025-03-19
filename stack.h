#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct {
    int *arr;
    int top;
    int capacity;
} stack_t;

stack_t *createStack(int capacity);
void pushStack(stack_t *stack, int value);
int popStack(stack_t *stack);
bool isEmptyStack(stack_t *stack);
void destroyStack(stack_t *stack);

#endif
