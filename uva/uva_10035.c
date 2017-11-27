//
// UVa 10035 - Primary Arithmetic
// https://uva.onlinejudge.org/external/100/10035.pdf
//


#include <stdio.h>

int main() {
    unsigned n1, n2;
    int carry, count, s;

    while ((scanf("%u%u", &n1, &n2) == 2) && (n1 > 0 || n2 > 0)) {
        carry = 0;
        count = 0;

        while (n1 > 0 || n2 > 0) {
            s = (n1 % 10) + (n2 % 10) + carry;

            if (s > 9) count++;
            carry = s / 10;
            n1 /= 10;
            n2 /= 10;
        }

        if (count == 0)
            printf("No carry operation.\n");
        else if (count == 1)
            printf("%i carry operation.\n", count);
        else
            printf("%i carry operations.\n", count);
    }

    return 0;
}
