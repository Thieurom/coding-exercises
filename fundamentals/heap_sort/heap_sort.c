/*
 * heap_sort.c
 * Implementation for Heapsort
 */


#include <stdio.h>
#include "heap.h"
#include "heap_sort.h"

/*
 * Sort given array of integers in ascending order.
 * Time complexity is O(n*log(n)), where n is the number of elements of array.
 */
void heap_sort(int s[], int n) {
    int i;
    MinHeap h;

    heap_init(&h);
    heap_build(&h, s, n);

    for (i = 0; i < n; i++)
        s[i] = heap_remove(&h);
}
