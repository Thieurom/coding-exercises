//
// LeetCode
// 53. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/ 
//

class Solution {
    func maxSubArray(_ nums: [Int]) -> Int {
        return maxSubArray(nums, from: 0, to: nums.count - 1)
    }

    func maxSubArray(_ nums: [Int], from start: Int, to end: Int) -> Int {
        if start == end {
            return nums[start]
        }

        let medium = start + (end - start) / 2
        let leftMax = maxSubArray(nums, from: start, to: medium)
        let rightMax = maxSubArray(nums, from: medium + 1, to: end)
        let crossMax = maxCrossToMedium(nums, left: start, right: end, medium: medium)

        return max(leftMax, rightMax, crossMax)
    }

    func maxCrossToMedium(_ nums: [Int], left: Int, right: Int, medium: Int) -> Int {
        var crossSum = 0
        var leftSum = Int.min
        var rightSum = Int.min

        var i = medium
        var j = medium + 1

        while i >= left {
            crossSum += nums[i]
            if crossSum > leftSum {
                leftSum = crossSum
            }

            i -= 1
        }

        crossSum = 0
        while j <= right {
            crossSum += nums[j]
            if crossSum > rightSum {
                rightSum = crossSum
            }

            j += 1
        }

        return leftSum + rightSum
    }
}

