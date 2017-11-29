/*
 * stack.c
 * Implementation of Stack
 */

#include <stdlib.h>
#include "linked_list.h"
#include "stack.h"


/*
 * Insert new node with the specified value onto the top of the stack.
 * Time comlexity is O(1)
 */
void stack_push(Stack *stack, int value) {
    list_insert_next(stack, NULL, value);
}


/*
 * Remove the node off the top of a stack ant return it
 * Time comlexity is O(1)
 */
Node *stack_pop(Stack *stack) {
    Node *node = list_head(stack);

    list_remove_next(stack, NULL);

    return node;
}
