/*
 * selection_sort.c
 * Implementation for Selection Sort
 */


#include <stdio.h>
#include "selection_sort.h"

void swap(int* m, int* n) {
    int temp;

    temp = *m;
    *m = *n;
    *n = temp;
}

/*
 * Sort given array of integers in ascending order
 * Time complexity is O(n^2), where n is the number of elements of array.
 */
void selection_sort(int s[], int n) {
    int i, j;
    int min;

    for (i = 0; i < n; i++) {
        min = i;

        for (j = i + 1; j < n; j++)
            if (s[j] < s[min])
                min = j;

        if (min != i)
            swap(&s[i], &s[min]);
    }
}
