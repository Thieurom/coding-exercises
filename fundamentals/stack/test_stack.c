/*
 * test_stack.c
 * Test for Stack
 */


#include <assert.h>
#include "stack.h"

void test_stack_push() {
    Stack *stack;
    int i1 = 100, i2 = 200;

    stack = stack_create();

    stack_push(stack, &i1);
    assert(stack_size(stack) == 1);

    stack_push(stack, &i2);
    assert(stack_size(stack) == 2);

    stack_destroy(stack);
}

void test_stack_pop() {
    Stack *stack;
    Node *node;
    int i1 = 100, i2 = 200;

    stack = stack_create();

    stack_push(stack, &i1);
    stack_push(stack, &i2);
    assert(stack_size(stack) == 2);

    node = stack_pop(stack);
    assert(node->data == &i2);
    assert(stack_size(stack) == 1);

    stack_destroy(stack);
}

void test_stack_peek() {
    Stack *stack;
    int i = 100;

    stack = stack_create();
    stack_push(stack, &i);
    assert(stack_peek(stack) == &i);
}


int main() {
    test_stack_push();
    test_stack_pop();
    test_stack_peek();

    return 0;
}
