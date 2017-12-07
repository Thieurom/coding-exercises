//
// LeetCode
// 1. Two Sum
// https://leetcode.com/problems/two-sum
//


int* twoSum(int* nums, int numsSize, int target) {
    int* result;
    int i, j;

    if ((result = (int*) malloc(2 * sizeof(int))) == NULL)
        exit(-1);

    for (i = 0; i < numsSize - 1; i++)
        for (j = 0; j < numsSize; j++)
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                break;
            }

    return result;
}


/*-----------------------------------------------------------------------------
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 *---------------------------------------------------------------------------*/
