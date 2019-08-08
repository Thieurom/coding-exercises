//
// LeetCode
// 1. Two Sum
// https://leetcode.com/problems/two-sum
//


class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var numsDict: [Int: Int] = [:]

        for index in 0..<nums.count {
            let complement = target - nums[index]

            if let position = numsDict[complement] {
                return [position, index]
            }

            numsDict[nums[index]] = index
        }

        return [-1, -1]
    }
}
