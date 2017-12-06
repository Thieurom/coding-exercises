/*
 * priority_queue.h
 *
 * Header for Priority Queue data structure
 * The root element (the highest priority) is the smallest value (min heap)
 */


#ifndef PQUEUE_H
#define PQUEUE_H

#define PQ_SIZE 1000

typedef struct {
    int elements[PQ_SIZE + 1];
    int size;
} PQueue;

void pq_insert(PQueue *q, const int value);
int pq_minimum(PQueue *q);
int pq_extract_minimum(PQueue *q);
#define pq_size(q) ((q)->size)

#endif  /* PQUEUE_H */
