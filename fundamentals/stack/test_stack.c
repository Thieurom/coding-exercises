/*
 * test_stack.c
 * Test for Stack
 */


#include <assert.h>
#include "stack.h"

void test_stack_push() {
    Stack stack;

    stack_init(&stack);

    stack_push(&stack, 100);
    assert(stack_size(&stack) == 1);

    stack_push(&stack, 200);
    assert(stack_size(&stack) == 2);
}


int main() {
    test_stack_push();

    return 0;
}
