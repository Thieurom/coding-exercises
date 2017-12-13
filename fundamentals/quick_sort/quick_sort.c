/*
 * quick_sort.c
 * Implementation for Quick Sort alorithm.
 */


#include <stdlib.h>
#include "common.h"
#include "quick_sort.h"

/* Dutch national flag partitioning */
void partition(int s[], int low, int high, int p_idx, int *smaller, int *larger) {
    int pivot = s[p_idx];
    int equal = low;

    while (equal <= high)
        if (s[equal] < pivot)
            swap(&s[equal++], &s[low++]);
        else if (s[equal] == pivot)
            equal++;
        else
            swap(&s[equal], &s[high--]);

    *smaller = low - 1;
    *larger = high + 1;
}


void quick_sort(int s[], int low, int high) {
    int i, j;
    int p_idx;

    if (low < high) {
        p_idx = rand() % (high - low + 1) + low;
        partition(s, low, high, p_idx, &i, &j);
        quick_sort(s, low, i);
        quick_sort(s, j, high);
    }
}
