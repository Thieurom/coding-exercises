/*
 * test_stack.c
 * Test for Stack
 */


#include <assert.h>
#include <stdio.h>
#include "stack.h"


int main() {
    Stack stack;
    int n;

    stack_init(&stack);
    assert(stack_is_empty(&stack) == true);

    stack_push(&stack, 100);
    assert(stack_is_empty(&stack) == false);
    assert(stack_size(&stack) == 1);
    assert(stack_top(&stack) == 100);

    stack_push(&stack, 200);
    assert(stack_size(&stack) == 2);

    n = stack_pop(&stack);
    assert(n == 200);
    assert(stack_size(&stack) == 1);
    assert(stack_top(&stack) == 100);

    n = stack_pop(&stack);
    assert(n == 100);
    assert(stack_is_empty(&stack) == true);

    printf("Tested OK.\n");

    return 0;
}
