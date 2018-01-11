//
// LeetCode
// 27. Remove Element
// https://leetcode.com/problems/remove-element/
//


int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    
    numsSize--;
    while (i <= numsSize) {
        if (nums[i] == val) {
            nums[i] = nums[numsSize--];
        } else {
            i++;
        }
    }
    
    return numsSize + 1;
}
