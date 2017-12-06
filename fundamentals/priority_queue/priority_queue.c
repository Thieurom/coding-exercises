/*
 * priority_queue.c
 *
 * Implementation for Priority Queue
 */

#include <stdlib.h>
#include <stdio.h>
#include "priority_queue.h"

/* Return the position of an element's parent given by position */
#define pq_parent(p) (((p) == 1) ? -1 : ((int) ((p) / 2)))

/* Return the position of an element's left child given by position */
#define pq_left_child(p) ((p) * 2)

/* Swap two elements in the queue specified by positions */
void pq_swap(PQueue *q, const int p1, const int p2);

/* Bubble up the element at the specified position if it dissatisfy its parent */
void pq_bubble_up(PQueue *q, const int p);

/* Bubble down the element at the specified position if it dissatisfy its children */
void pq_bubble_down(PQueue * q, const int p);


/*
 * Insert new element with the specified value into the queue
 * Time complexity is O(log(n)), where n is the total of the queue's elements.
 */
void pq_insert(PQueue *q, const int value) {
    if (pq_size(q) >= PQ_SIZE) {
        printf("Priority queue overflow inserting new element\n");
        exit(EXIT_FAILURE);

    } else {
        q->size++;
        q->elements[pq_size(q)] = value;
        pq_bubble_up(q, pq_size(q));
    }
}


/*
 * Return the minimum value from the queue
 * Time complexity is constant - O(1)
 */
int pq_minimum(PQueue *q) {
    return q->elements[1];
}


/*
 * Removing the top (minimum) element from the queue and return its key
 * Time complexity is O(log(n)), where n is the total elements of the queue
 */
int pq_extract_minimum(PQueue *q) {
    int min = -1;

    if (pq_size(q) == 0) {
        printf("Can\'t extract from the empty queue.\n");
        exit(EXIT_FAILURE);

    } else {
        min = q->elements[1];
        q->elements[1] = q->elements[pq_size(q)];
        q->size--;
        pq_bubble_down(q, 1);
    }

    return min;
}


/****************************************************************************/

void pq_bubble_up(PQueue *q, const int p) {
    if (pq_parent(p) == -1) return;

    if (q->elements[p] < q->elements[pq_parent(p)]) {
        pq_swap(q, p, pq_parent(p));
        pq_bubble_up(q, pq_parent(p));
    }
}


void pq_bubble_down(PQueue *q, const int p) {
    int c;
    int i;
    int min_index;

    c = pq_left_child(p);
    min_index = p;

    for (i = 0; i < 2; i++) {
        if ((c + i) <= pq_size(q))
            if (q->elements[min_index] > q->elements[c + i])
                min_index = c + i;
    }

    if (min_index != p) {
        pq_swap(q, min_index, p);
        pq_bubble_down(q, min_index);
    }
}


void pq_swap(PQueue *q, const int p1, const int p2) {
    int temp;

    temp = q->elements[p1];
    q->elements[p1] = q->elements[p2];
    q->elements[p2] = temp;
}
