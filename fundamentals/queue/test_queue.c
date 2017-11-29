/*
 * test_queue.c
 * Test for Queue
 */


#include <assert.h>
#include "queue.h"

void test_queue_enqueue() {
    Queue queue;

    queue_init(&queue);

    queue_enqueue(&queue, 100);
    assert(queue_size(&queue) == 1);

    queue_enqueue(&queue, 200);
    assert(queue_size(&queue) == 2);

    queue_destroy(&queue);
}

void test_queue_dequeue() {
    Queue queue;
    Node *node;

    queue_init(&queue);

    queue_enqueue(&queue, 100);
    queue_enqueue(&queue, 200);
    assert(queue_size(&queue) == 2);

    node = queue_dequeue(&queue);
    assert(node->value = 100);
    assert(queue_size(&queue) == 1);

    queue_destroy(&queue);
}


int main() {
    test_queue_enqueue();
    test_queue_dequeue();

    return 0;
}
