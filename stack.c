#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

stack_t *createStack(int capacity) {
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int *)malloc(capacity * sizeof(int));
    return stack;
}

void pushStack(stack_t *stack, int value) {
    if (stack->top < stack->capacity - 1) {
        stack->arr[++stack->top] = value;
    }
}

int popStack(stack_t *stack) {
    if (stack->top >= 0) {
        return stack->arr[stack->top--];
    }
    return -1;
}

bool isEmptyStack(stack_t *stack) {
    return stack->top == -1;
}

void destroyStack(stack_t *stack) {
    free(stack->arr);
    free(stack);
}
