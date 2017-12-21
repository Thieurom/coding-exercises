/*
 * test_binary_search.c
 */


#include <assert.h>
#include <stdio.h>
#include "binary_search.h"


int main()
{
    int i;
    int n = 10;
    int s[] = { 0, 12, 23, 53, 66, 81, 224, 1244, 9929, 10121 };

    for (i = 0; i < n; i++)
        assert(binary_search(s, s[i], 0, n) == i);

    for (i = 10; i <= 100; i = i + 10)
        assert(binary_search(s, i, 0, n) == -1);

    printf("Tested OK\n");

    return 0;
}
