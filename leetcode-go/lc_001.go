//
// LeetCode
// 1. Two Sum
// https://leetcode.com/problems/two-sum
//


func twoSum(nums []int, target int) []int {
    indices := []int{-1, -1}

    for i:= 0; i < len(nums) - 1; i++ {
        for j := i + 1; j < len(nums); j++ {
            if nums[i] + nums[j] == target {
                indices[0] = i
                indices[1] = j
                break
            }
        }
    }

    return indices
}
