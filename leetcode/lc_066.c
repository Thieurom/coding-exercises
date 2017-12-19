//
// LeetCode
// 66. Plus One
// https://leetcode.com/problems/plus-one/
//


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *result, i, j, n, carry;
    
    for (i = 0; i < digitsSize; i++)
        if (digits[i] != 9)
            break;
    
    *returnSize = (i == digitsSize ? digitsSize + 1 : digitsSize);
    if ((result = (int *) malloc((*returnSize + 1) * sizeof(int))) == NULL)
        exit(-1);

    j = *returnSize - 1;
    carry = 1;
    
    for (i = digitsSize - 1; i >= 0; i--) {
        n = digits[i] + carry;
        result[j--] = n % 10;
        carry = n / 10;
    }
    
    if (carry > 0)
        result[j] = carry;
    
    return result;
}
