//
// LeetCode
// 26. Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
//


class Solution {
    func removeDuplicates(_ nums: inout [Int]) -> Int {
        if nums.count <= 1 {
            return nums.count
        }

        var lastIndex = 0
        for num in nums {
            if num != nums[lastIndex] {
                lastIndex += 1
                nums[lastIndex] = num
            }
        }

        return lastIndex + 1
    }
}
