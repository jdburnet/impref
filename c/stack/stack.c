#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"


struct Stack *init(int size)
{
    struct Stack *stack = (struct Stack *)
        malloc(sizeof(struct Stack) + sizeof(int) * size);
    stack->top = 0;
    stack->size = size;
    return stack;
}

int empty(struct Stack *stack)
{
    return stack->top == 0;
}

int full(struct Stack *stack)
{
    return stack->top + 1 > stack->size;
}

int push(int val, struct Stack *stack)
{
    if (full(stack))
    {
        return -1;
    }

    stack->top++;
    stack->arr[stack->top] = val;
    return 0;
}

int pop(struct Stack *stack)
{
    if (empty(stack))
    {
        return -1;
    }

    stack->top--;
    return stack->arr[stack->top + 1];
}

int main(int argc, char **argv)
{
    struct Stack *stack = init(1);
    assert(stack->top == 0);
    assert(stack->size == 1);
    assert(empty(stack));
    push(42, stack);
    assert(stack->top == 1);
    assert(full(stack));
    assert(push(42, stack) == -1);
    assert(pop(stack) == 42);
    assert(empty(stack));
}
