/*
 * stack.c
 * Implementation of Stack data structure
 */

#include <stdlib.h>
#include "linked_list.h"
#include "stack.h"


/*
 * Insert new node with the specified data onto the top of the stack.
 * Time comlexity is O(1)
 */
void stack_push(Stack *stack, void *data) {
    list_insert_next(stack, NULL, data);
}


/*
 * Remove the node off the top of a stack ant return it
 * Time comlexity is O(1)
 */
Node *stack_pop(Stack *stack) {
    void *data;

    Node *node = list_head(stack);

    list_remove_next(stack, NULL, (void **)&data);

    return node;
}
