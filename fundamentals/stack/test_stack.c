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

    stack_destroy(&stack);
}

void test_stack_pop() {
    Stack stack;
    Node *node;

    stack_init(&stack);

    stack_push(&stack, 100);
    stack_push(&stack, 200);
    assert(stack_size(&stack) == 2);

    node = stack_pop(&stack);
    assert(node->value == 200);
    assert(stack_size(&stack) == 1);

    stack_destroy(&stack);
}


int main() {
    test_stack_push();
    test_stack_pop();

    return 0;
}
