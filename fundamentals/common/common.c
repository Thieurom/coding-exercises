/*
 * common.c
 */


#include <stdio.h>
#include "common.h"

void print_array(int s[], int n) {
    int i;

    printf("[ ");

    for (i = 0; i < n; i++)
        printf("%i ", s[i]);

    printf("]\n");
}


bool is_sorted(int s[], int n) {
    int i;

    for (i = 0; i < n - 1; i++) {
        if (s[i] > s[i + 1])
            return false;
    }

    return true;
}
