//
// LeetCode
// 18. 4Sum
// https://leetcode.com/problems/4sum/
//

class Solution {
    func fourSum(_ nums: [Int], _ target: Int) -> [[Int]] {
        guard nums.count >= 4 else {
            return []
        }

        let sortedNums = nums.sorted()
        var result = Set<[Int]>()

        for i in (0..<sortedNums.count - 3) {
            for j in (i + 1..<sortedNums.count - 2) {
                var left = j + 1
                var right = sortedNums.count - 1

                while left < right {
                    let sum = sortedNums[i] + sortedNums[j] + sortedNums[left] + sortedNums[right]

                    if sum < target {
                        left += 1
                    } else if sum > target {
                        right -= 1
                    } else {
                        result.insert([sortedNums[i], sortedNums[j], sortedNums[left], sortedNums[right]])
                        left += 1
                    }
                }
            }
        }

        return Array(result)
    }
}
