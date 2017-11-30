/*
 * queue.c
 * Header for Queue data structure
 */


#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

#include "linked_list.h"


typedef List Queue;

#define queue_create list_create
#define queue_destroy list_destroy
void queue_enqueue(Queue *queue, void *data);
Node *queue_dequeue(Queue *queue);
#define queue_peek(queue) ((queue)->head == NULL ? NULL : queue->head->data)
#define queue_size list_size

#endif    /* QUEUE_H */
