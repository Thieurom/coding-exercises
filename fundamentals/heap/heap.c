/*
 * heap.c
 * Implementation for Heap data structure
 */


#include <stdlib.h>
#include <stdio.h>
#include "heap.h"


void swap(int s[], const int i, const int j);
void heap_bubble_up(MinHeap *h, const int p);
void heap_bubble_down(MinHeap *h, const int p);


/*
 * Initialize the heap.
 * Time complexity is constant - O(1).
 */
void heap_init(MinHeap *h) {
    h->size = 0;
}


/*
 * Build the heap from given array.
 * Time complexity is O(n*log(n)), where n is the number of elements of the heap.
 */
void heap_build(MinHeap *h, int s[], const int n) {
    int i;

    for (i = 0; i < n; i++)
        heap_insert(h, s[i]);
}


/*
 * Insert new element with the specified value into the heap.
 * Time complexity is O(log(n)), where n is the total number of elements of the heap.
 */
void heap_insert(MinHeap *h, const int value) {
    if (heap_size(h) >= HEAP_SIZE) {
        printf("Heap overflow inserting new element.\n");
        exit(EXIT_FAILURE);

    } else {
        h->size++;
        h->elements[heap_size(h)] = value;
        heap_bubble_up(h, heap_size(h));
    }
}


/*
 * Remove the root element from the heap and return its value.
 * Time complexity is O(log(n)), where n is the total number of elements of the heap.
 */
int heap_remove(MinHeap *h) {
    int min = -1;

    if (heap_empty(h))
        printf("Warning: empty heap.\n");
    else {
        min = h->elements[1];
        h->elements[1] = h->elements[heap_size(h)];
        h->size--;
        heap_bubble_down(h, 1);
    }

    return min;
}


/*
 * Return true if the heap is empty, false otherwise.
 * Time complexity is constant, O(1).
 */
bool heap_empty(MinHeap *h) {
    return heap_size(h) == 0;
}


/*--------------------------------------------------------------------------*/

/* Bubble up the element at the specified position if it dissatisfies its parent */
void heap_bubble_up(MinHeap *h, const int p) {
    if (heap_parent(p) == -1) return;

    if (h->elements[p] < h->elements[heap_parent(p)]) {
        swap(h->elements, p, heap_parent(p));
        heap_bubble_up(h, heap_parent(p));
    }
}


/* Bubble down the element at the specified position if it dissatisfies its children */
void heap_bubble_down(MinHeap *h, const int p) {
    int c;
    int i;
    int min_index;

    c = heap_left_child(p);
    min_index = p;

    for (i = 0; i < 2; i++)
        if ((c + i) <= heap_size(h))
            if (h->elements[min_index] > h->elements[c + i])
                min_index = c + i;

    if (min_index != p) {
        swap(h->elements, min_index, p);
        heap_bubble_down(h, min_index);
    }
}


/* Swap two elements in the array */
void swap(int s[], const int i, const int j) {
    int temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}
