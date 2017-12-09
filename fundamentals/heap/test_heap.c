/*
 * test_heap.c
 * Test for Heap data structure
 */


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "heap.h"

int main() {
    MinHeap h;
    int s[] = { 11, 16, 15, 14, 19, 12, 17, 13 };

    heap_init(&h);
    assert(heap_size(&h) == 0);

    heap_build(&h, s, 8);
    assert(heap_size(&h) == 8);

    heap_insert(&h, 10);
    assert(heap_size(&h) == 9);

    heap_insert(&h, 18);
    assert(heap_size(&h) == 10);

    assert(heap_peek(&h) == 10);
    assert(heap_remove(&h) == 10);
    assert(heap_size(&h) == 9);

    assert(heap_peek(&h) == 11);
    assert(heap_remove(&h) == 11);
    assert(heap_size(&h) == 8);

    printf("Tested OK\n");

    return EXIT_SUCCESS;
}
