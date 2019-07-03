//
// LeetCode
// 33. Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/ 
//

class Solution {
    func search(_ nums: [Int], _ target: Int) -> Int {
        var left = 0
        var right = nums.count - 1

        while left <= right {
            let medium = (left + right) / 2

            if nums[medium] == target {
                return medium
            }

            if nums[medium] < target {
                if nums[medium] < nums[left] && nums[right] < target {
                    right = medium - 1
                } else {
                    left = medium + 1
                }
            } else {
                if nums[medium] > nums[right] && nums[left] > target {
                    left = medium + 1
                } else {
                    right = medium - 1
                }
            }
        }

        return -1
    }
}
