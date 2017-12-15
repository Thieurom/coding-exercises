//
// LeetCode
// 26. Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
//


int removeDuplicates(int* nums, int numsSize) {
    int i = 0, j;

    if (numsSize == 0)
        return 0;

    for (j = 1; j < numsSize; j++)
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }

    return i + 1;
}
