/*
 * stack.h
 * Header for Stack
 */

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#include "linked_list.h"

typedef List Stack;

#define stack_init list_init
#define stack_destroy list_destroy
void stack_push(Stack *stack, int value);
Node *stack_pop(Stack *stack);
#define stack_peek(stack) ((stack)->head == NULL ? NULL : (stack)->head->value)
#define stack_size list_size

#endif  /* STACK_H */
