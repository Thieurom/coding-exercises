//
// LeetCode
// 35. Search Insert Position
// https://leetcode.com/problems/search-insert-position/
//


class Solution {
    func searchInsert(_ nums: [Int], _ target: Int) -> Int {
        var low = 0
        var high = nums.count - 1
        var middle: Int
        
        while low <= high {
            middle = (low + high) / 2
            
            if nums[middle] > target {
                high = middle - 1
            } else if nums[middle] < target {
                low = middle + 1
            } else {
                return middle
            }
        }
        
        return low
    }
}
