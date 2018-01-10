//
// LeetCode
// 1. Two Sum
// https://leetcode.com/problems/two-sum
//


class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var result = [-1, -1]
        
        for i in 0..<nums.count-1 {
            for j in i+1..<nums.count {
                if nums[i] + nums[j] == target {
                    result[0] = i
                    result[1] = j
                    break
                }
            }
        }
        
        return result
    }
}
