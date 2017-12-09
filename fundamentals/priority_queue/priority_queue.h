/*
 * priority_queue.h
 *
 * Header for Priority Queue data structure
 * The root element (the highest priority) is the smallest value (min heap)
 */


#ifndef PQUEUE_H
#define PQUEUE_H

#include "heap.h"

typedef MinHeap PQueue;

#define pq_init heap_init
#define pq_build heap_build
#define pq_insert heap_insert
#define pq_extract_minimum heap_remove
#define pq_minimum heap_peek
#define pq_size heap_size
#define pq_is_empty heap_is_empty

#endif  /* PQUEUE_H */
