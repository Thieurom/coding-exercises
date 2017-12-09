/*
 * insertion_sort.c
 * Implementation for Insertion Sort algorithm
 */


#include <stdio.h>
#include "common.h"
#include "insertion_sort.h"

/*
 * Sort given array of integers in ascending order.
 * Time comlexity if O(n^2), where n is the number of elements of array.
 */
void insertion_sort(int s[], int n) {
    int i, j;

    for (i = 1; i < n; i++) {
        j = i;

        while ((j > 0) && (s[j] < s[j - 1])) {
            swap(&s[j], &s[j - 1]);
            j--;
        }
    }
}
