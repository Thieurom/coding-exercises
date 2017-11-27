//
// UVa 847 - A Multiplication Game
// https://uva.onlinejudge.org/external/8/847.pdf
//


#include <stdio.h>

int main() {
    unsigned n, p;
    int turns;

    while (scanf("%u", &n) == 1 && (n > 1 && n < 4294967295)) {
        p = 1;
        turns = 0;

        while (p < n) {
            if (turns % 2 == 0)     // Stan's turn
                p *= 9;
            else                    // Ollie's turn
                p *= 2;

            turns++;
        }

        if (turns % 2 == 0)
            printf("Ollie wins.\n");
        else
            printf("Stan wins.\n");
    }

    return 0;
}
