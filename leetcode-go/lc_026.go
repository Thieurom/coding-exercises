//
// LeetCode
// 26. Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
//


func removeDuplicates(nums []int) int {
    if len(nums) <= 1 {
        return len(nums)
    }

    idx := 0
    for i:= 0; i < len(nums); i++ {
        if nums[i] != nums[idx] {
            idx++
            nums[idx] = nums[i]
        }
    }

    return idx + 1
}
