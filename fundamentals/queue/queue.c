/*
 * queue.c
 * Implementation
 */


#include <stdlib.h>
#include "linked_list.h"
#include "queue.h"


/*
 * Insert new node with the specified data at the tail of the queue
 * Time complexity is O(1)
 */
void queue_enqueue(Queue *queue, void *data) {
    list_insert_next(queue, list_tail(queue), data);
}


/*
 * Remove the node at the head of the queue, and return it
 * Time complexity is O(1)
 */
Node *queue_dequeue(Queue *queue) {
    Node *node = list_head(queue);
    void *data;

    list_remove_next(queue, NULL, (void **)&data);

    return node;
}
