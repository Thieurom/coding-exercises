//
// LeetCode
// 27. Remove Element
// https://leetcode.com/problems/remove-element/
//


class Solution {
    func removeElement(_ nums: inout [Int], _ val: Int) -> Int {
        var currentIndex = 0
        var lastIndex = nums.count - 1

        while currentIndex <= lastIndex {
            if nums[currentIndex] == val {
                nums[currentIndex] = nums[lastIndex]
                lastIndex -= 1
            } else {
                currentIndex += 1
            }
        }

        return lastIndex + 1
    }
}
