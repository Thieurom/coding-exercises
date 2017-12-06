//
// UVa 10038 - Jolly Jumpers
// https://uva.onlinejudge.org/external/100/10038.pdf
//


#include <stdio.h>

#define MAX 3000

int main() {
    int n, i, diff;
    int flag = 1;
    int input[MAX], diffs[MAX];

    scanf("%i", &n);

    for (i = 0; i < n; i++) {
        scanf("%i", &input[i]);
        diffs[i] = 0;
    }

    for (i = 0; i < n - 1; i++) {
        diff = input[i + 1] - input[i];
        if (diff < 0)
            diff = -diff;

        if ((diff < 1 || diff > n - 1) || diffs[diff] > 0) {
            flag = 0;
            break;
        } else {
            diffs[diff]++;
        }
    }

    if (flag == 1)
        printf("Jolley\n");
    else
        printf("Not jolley\n");

    return 0;
}
