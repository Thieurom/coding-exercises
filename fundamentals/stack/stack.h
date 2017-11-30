/*
 * stack.h
 * Header for Stack data structure
 */

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#include "linked_list.h"

typedef List Stack;

#define stack_create list_create
#define stack_destroy list_destroy
void stack_push(Stack *stack, void *data);
Node *stack_pop(Stack *stack);
#define stack_peek(stack) ((stack)->head == NULL ? NULL : (stack)->head->data)
#define stack_size list_size

#endif  /* STACK_H */
