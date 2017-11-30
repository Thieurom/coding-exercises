/*
 * test_queue.c
 * Test for Queue
 */


#include <assert.h>
#include "queue.h"

void test_queue_enqueue() {
    Queue *queue;
    int i1 = 100, i2 = 200;

    queue = queue_create();

    queue_enqueue(queue, &i1);
    assert(queue_size(queue) == 1);

    queue_enqueue(queue, &i2);
    assert(queue_size(queue) == 2);

    queue_destroy(queue);
}

void test_queue_dequeue() {
    Queue *queue;
    Node *node;
    int i1 = 100, i2 = 200;

    queue = queue_create();

    queue_enqueue(queue, &i1);
    queue_enqueue(queue, &i2);
    assert(queue_size(queue) == 2);

    node = queue_dequeue(queue);
    assert(node->data == &i1);
    assert(queue_size(queue) == 1);

    queue_destroy(queue);
}


int main() {
    test_queue_enqueue();
    test_queue_dequeue();

    return 0;
}
