/*
 * stack.h
 * Header for Stack data structure
 */

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "linked_list.h"

typedef struct {
    List list;
} Stack;

void stack_init(Stack *stack);
void stack_push(Stack *stack, int value);
int stack_pop(Stack *stack);
int stack_top(Stack *stack);
int stack_size(Stack *stack);
bool stack_is_empty(Stack *stack);

#endif  /* STACK_H */
