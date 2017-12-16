//
// LeetCode
// 35. Search Insert Position
// https://leetcode.com/problems/search-insert-position/
//


int searchInsert(int* nums, int numsSize, int target) {
    int low, high, middle;
    
    low = 0;
    high = numsSize - 1;
    
    while (low <= high) {
        middle = (low + high) / 2;
        
        if (nums[middle] > target)
            high = middle - 1;
        else if (nums[middle] < target)
            low = middle + 1;
        else
            return middle;
    }
    
    return low;
}
