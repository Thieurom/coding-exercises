//
// LeetCode
// 34. Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
//


class Solution {
    func searchRange(_ nums: [Int], _ target: Int) -> [Int] {
        let position = binarySearch(nums, target: target)

        guard position >= 0 else {
            return [-1, -1]
        }

        var left = position
        var right = position

        while true {
            if left >= 0 && nums[left] == target {
                left -= 1
            } else if right < nums.count && nums[right] == target {
                right += 1
            } else {
                break
            }
        }

        return [left + 1, right - 1]
    }
    
    func binarySearch(_ nums: [Int], target: Int) -> Int {
        var left = 0
        var right = nums.count - 1
        var mid = 0

        while left <= right {
            mid = (left + right) / 2

            if nums[mid] > target {
                right = mid - 1
            } else if nums[mid] < target {
                left = mid + 1
            } else {
                return mid
            }
        }
        
        return -1
    }
}
