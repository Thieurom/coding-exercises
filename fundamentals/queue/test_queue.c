/*
 * test_queue.c
 * Test for Queue
 */


#include <assert.h>
#include <stdio.h>
#include "queue.h"


int main() {
    Queue queue;
    int n;

    q_init(&queue);
    assert(q_is_empty(&queue) == true);

    q_enqueue(&queue, 100);
    assert(q_is_empty(&queue) == false);
    assert(q_size(&queue) == 1);
    assert(q_front(&queue) == 100);

    q_enqueue(&queue, 200);
    assert(q_size(&queue) == 2);

    n = q_dequeue(&queue);
    assert(n == 100);
    assert(q_size(&queue) == 1);
    assert(q_front(&queue) == 200);

    n = q_dequeue(&queue);
    assert(n == 200);
    assert(q_is_empty(&queue) == true);

    printf("Tested OK.\n");

    return 0;
}
