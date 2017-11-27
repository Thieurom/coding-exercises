//
// UVa 10110 - Light, More Light
// https://uva.onlinejudge.org/external/101/10110.pdf
//


#include <stdio.h>
#include <math.h>

int main() {
    unsigned n, s;

    while (scanf("%u", &n) == 1 && n > 0) {
        s = sqrt(n);

        if (s * s == n)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
