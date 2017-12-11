/*
 * stack.c
 * Implementation of Stack data structure, using linked list.
 */

#include <stdlib.h>
#include "linked_list.h"
#include "stack.h"


/*
 * Initialize stack.
 * Time complexity is O(1).
 */
void stack_init(Stack *stack) {
    list_init(&(stack->list));
}


/*
 * Insert new value onto the top of the stack.
 * Time complexity is O(1)
 */
void stack_push(Stack *stack, int value) {
    list_insert_next(&(stack->list), NULL, value);
}


/*
 * Remove the value at the top of a stack and return it.
 * Time pcomlexity is O(1)
 */
int stack_pop(Stack *stack) {
    int value;

    if (list_is_empty(&(stack->list)))
        exit(EXIT_FAILURE);

    value = list_value(list_head(&(stack->list)));
    list_remove_next(&(stack->list), NULL);

    return value;
}


/*
 * Return the value of the top of the stack.
 * Time complexity is O(1).
 */
int stack_top(Stack *stack) {
    return list_value(list_head(&(stack->list)));
}


/*
 * Return the size of the stack.
 */
int stack_size(Stack *stack) {
    return list_size(&(stack->list));
}


/*
 * Return true if stack is empty, false otherwise.
 */
bool stack_is_empty(Stack *stack) {
    return list_is_empty(&(stack->list));
}
