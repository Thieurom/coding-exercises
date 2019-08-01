//
// LeetCode
// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/
// 

class Solution {
    func minSubArrayLen(_ s: Int, _ nums: [Int]) -> Int {
        var sum = 0
        var result = Int.max
        var i = 0
        
        for j in 0..<nums.count {
            sum += nums[j]
            
            while sum >= s {
                result = min(result, j - i + 1)
                sum -= nums[i]
                i += 1
            }
        }
        
        return result == Int.max ? 0 : result
    }
}
