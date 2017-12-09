/*
 * heap.h
 * Header for MinHeap data structure
 */


#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <stdbool.h>

#define HEAP_SIZE 1000

typedef struct {
    int elements[HEAP_SIZE + 1];  // array start at index of 1
    int size;
} MinHeap;

void heap_init(MinHeap *h);
void heap_build(MinHeap *h, int s[], const int n);
void heap_insert(MinHeap *h, const int value);
int heap_remove(MinHeap *h);
bool heap_is_empty(MinHeap *h);

#define heap_peek(h) ((h)->elements[1])
#define heap_size(h) ((h)->size)
#define heap_parent(p) (((p) == 1) ? -1 : ((int) ((p) / 2)))
#define heap_left_child(p) ((p) * 2)
#define heap_right_child(p) (((p) * 2) + 1)

#endif  /* HEAP_H */
