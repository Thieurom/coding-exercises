/*
 * test_selection_sort.c
 * Test for Selection Sort
 */


#include <stdio.h>
#include "selection_sort.h"


void print_array(int s[], int n) {
    int i;

    printf("[ ");

    for (i = 0; i < n; i++)
        printf("%i ", s[i]);

    printf("]\n");
}

int is_sorted(int s[], int n) {
    int i;

    for (i = 0; i < n - 1; i++) {
        if (s[i] > s[i + 1])
            return 0;
    }

    return 1;
}

int main() {
    int numbers[] = {
        325432, 989,   547510, 3,   -93,  189019, 5042,  123,
        597,    42,    7506,   184, 184,  2409,   45,    824,
        4,      -2650, 9,      662, 3928, -170,   45358, 395,
        842,    7697,  110,    14,  99,   221
    };

    printf("Before sorting:\n");
    print_array(numbers, 30);

    selection_sort(numbers, 30);

    if (is_sorted(numbers, 30))
        printf("\nAfter sorting:\n");
    else
        printf("\nFail to sort, bad result:\n");

    print_array(numbers, 30);

    return 0;
}
