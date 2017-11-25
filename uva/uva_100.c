//
// UVa 100 - The 3n + 1 problem
// https://uva.onlinejudge.org/external/1/100.pdf
//


#include <stdio.h>

int cycle_length(int n) {
    int length = 1;

    while (n > 1) {
        length++;

        if (n % 2 == 0)
            n = n / 2;
        else
            n = 3 * n + 1;
    };

    return length;
}

int main() {
    int i, j, i0, j0, max, temp;
    int k;
    int cycle_length(int n);

    while (scanf("%d %d", &i, &j) == 2) {
        i0 = i;
        j0 = j;
        
        if (i > j) {
            temp = i;
            i = j;
            j = temp;
        }

        max = cycle_length(i);
        for (k = i + 1; k <= j; k++) {
            temp = cycle_length(k);
            if (temp > max)
                max = temp;
        }

        printf("%d %d %d\n", i0, j0, max);
    }

    return 0;
}
