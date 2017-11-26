//
// UVa 10137 - The Trip
// https://uva.onlinejudge.org/external/101/10137.pdf
//


#include <stdio.h>
#include <math.h>

float exchange(float a[], int n) {
    int i;
    float total = 0.0, average;
    float positive_diff = 0.0, negative_diff = 0.0, min_diff;

    for (i = 0; i < n; i++)
        total += a[i];

    average = total / n;
    for (i = 0; i < n; i++)
        if (a[i] > average)
            positive_diff += floorf((a[i] - average) * 100) / 100;
        else
            negative_diff += floorf((average - a[i]) * 100) / 100;

    min_diff = (positive_diff > negative_diff) ? negative_diff : positive_diff;

    return min_diff;
}

void clear(float a[], int n) {
    int i;

    for (i = 0; i < n; i++)
        a[i] = 0.0;
}

int main() {
    int n, i, j = 0;
    float expenses[1000], trips[20];

    while (j < 20 && (scanf("%i", &n) == 1 && n != 0)) {
        for (i = 0; i < n; i++)
            scanf("%f", &expenses[i]);

        trips[j] = exchange(expenses, n);
        clear(expenses, n);
        j++;
    }

    for (i = 0; i < j; i++)
        printf("$%.2f\n", trips[i]);

    return 0;
}
