/*
 * test_priority_queue.c
 *
 * Test for Priority Queue data structure
 */


#include <stdlib.h>
#include <assert.h>
#include "priority_queue.h"


int main() {
    PQueue q = { .size = 0 };

    pq_insert(&q, 11);
    pq_insert(&q, 16);
    pq_insert(&q, 18);
    pq_insert(&q, 15);
    pq_insert(&q, 14);
    pq_insert(&q, 19);
    pq_insert(&q, 12);
    pq_insert(&q, 17);
    pq_insert(&q, 13);
    pq_insert(&q, 10);

    assert(pq_size(&q) == 10);
    assert(pq_minimum(&q) == 10);

    assert(pq_extract_minimum(&q) == 10);
    assert(pq_size(&q) == 9);
    assert(pq_minimum(&q) == 11);

    assert(pq_extract_minimum(&q) == 11);
    assert(pq_size(&q) == 8);
    assert(pq_minimum(&q) == 12);

    assert(pq_extract_minimum(&q) == 12);
    assert(pq_extract_minimum(&q) == 13);
    assert(pq_extract_minimum(&q) == 14);
    assert(pq_extract_minimum(&q) == 15);
    assert(pq_extract_minimum(&q) == 16);
    assert(pq_extract_minimum(&q) == 17);
    assert(pq_extract_minimum(&q) == 18);
    assert(pq_extract_minimum(&q) == 19);
    assert(pq_size(&q) == 0);

    return EXIT_SUCCESS;
}
