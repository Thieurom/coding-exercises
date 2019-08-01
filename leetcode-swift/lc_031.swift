//
// LeetCode
// 31. Next Permutation
// https://leetcode.com/problems/next-permutation/
//


class Solution {
    func nextPermutation(_ nums: inout [Int]) {
        var k = nums.count - 2
        
        while k >= 0 && nums[k] >= nums[k+1] {
            k -=  1
        }
        
        if k == -1 {
            return nums.reverse()
        }
        
        for i in (k..<nums.count).reversed() {
            if nums[i] > nums[k] {
                nums.swapAt(i, k)
                break
            }
        }
        
        nums[k+1..<nums.count].reverse()
    }
}
