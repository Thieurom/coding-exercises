/*
 * queue.c
 * Header for Queue data structure
 */


#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include "linked_list.h"


typedef struct {
    List list;
} Queue;

void q_init(Queue *queue);
void q_enqueue(Queue *queue, int value);
int q_dequeue(Queue *queue);
int q_front(Queue *queue);
int q_size(Queue *queue);
bool q_is_empty(Queue *queue);

#endif    /* QUEUE_H */
