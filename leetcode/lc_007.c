//
// LeetCode
// 7. Reverse Integer
// https://leetcode.com/problems/reverse-interger
//


/* Assume we are dealing with an environment which could only hold integers
 * within the 32-bit signed integer range.
 */
#define INT32_MAX 2147483647
#define INT32_MIN (-INT32_MAX - 1)

int reverse(int x) {
    int digit;
    int sign;
    int result = 0;

    sign = (x < 0) ? -1 : 1;
    x *= sign;

    while (x != 0) {
        digit = x % 10;

        if ((sign > 0 && ((INT32_MAX - digit) / 10 < result)) ||
            ((INT32_MIN + digit) / 10 > sign * result))
            return 0;

        result = result * 10 + digit;
        x /= 10;
    }

    result *= sign;

    return result;
}
