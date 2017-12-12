/*
 * merge_sort.c
 * Implementation for Merge Sort algorithm
 */

#include "queue.h"
#include "merge_sort.h"

void merge(int s[], int low, int middle, int high) {
    int i;
    Queue buffer1, buffer2;

    q_init(&buffer1);
    q_init(&buffer2);

    for (i = low; i <= middle; i++)
        q_enqueue(&buffer1, s[i]);

    for (i = middle + 1; i <= high; i++)
        q_enqueue(&buffer2, s[i]);

    i = low;
    while (!q_is_empty(&buffer1) && !q_is_empty(&buffer2)) {
        if (q_front(&buffer1) < q_front(&buffer2))
            s[i++] = q_dequeue(&buffer1);
        else
            s[i++] = q_dequeue(&buffer2);
    }

    while (!q_is_empty(&buffer1))
        s[i++] = q_dequeue(&buffer1);

    while (!q_is_empty(&buffer2))
        s[i++] = q_dequeue(&buffer2);
}


void merge_sort(int s[], int low, int high) {
    int middle;

    if (low < high) {
        middle = (low + high) / 2;
        merge_sort(s, low, middle);
        merge_sort(s, middle + 1, high);
        merge(s, low, middle, high);
    }
}
