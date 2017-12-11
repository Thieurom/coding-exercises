/*
 * queue.c
 * Implementation for Queue data structure, using linked list.
 */


#include <stdlib.h>
#include "linked_list.h"
#include "queue.h"


/*
 * Initialize queue.
 */
void q_init(Queue *queue) {
    list_init(&(queue->list));
}


/*
 * Insert new value at the end of the queue
 * Time complexity is O(1)
 */
void q_enqueue(Queue *queue, int value) {
    list_insert_next(&(queue->list), list_tail(&(queue->list)), value);
}


/*
 * Remove the value at the beginning position from the queue, and return it.
 * Time complexity is O(1)
 */
int q_dequeue(Queue *queue) {
    int value;

    if (list_is_empty(&(queue->list)))
        exit(EXIT_FAILURE);

    value = list_value(list_head(&(queue->list)));
    list_remove_next(&(queue->list), NULL);

    return value;
}


/*
 * Return the value of the begining of the queue.
 * Time complexity is O(1).
 */
int q_front(Queue *queue) {
    return list_value(list_head(&(queue->list)));
}


/*
 * Return the size of the queue.
 */
int q_size(Queue *queue) {
    return list_size(&(queue->list));
}


/*
 * Return true if queue is empty, false otherwise.
 */
bool q_is_empty(Queue *queue) {
    return list_is_empty(&(queue->list));
}
