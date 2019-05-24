//
// LeetCode
// 15. 3Sum
// https://leetcode.com/problems/3sum/
//

class Solution {
    func threeSum(_ nums: [Int]) -> [[Int]] {
        guard nums.count >= 3 else {
            return []
        }

        var results = Set<[Int]>()
        let sortedNums = nums.sorted()

        for i in (0...sortedNums.count-3) {
            guard sortedNums[i] <= 0 else {
                continue
            }

            var left = i + 1
            var right = sortedNums.count - 1

            while left < right {
                let sum = sortedNums[i] + sortedNums[left] + sortedNums[right]

                if sum < 0 {
                    left += 1
                } else if sum > 0 {
                    right -= 1
                } else {
                    results.insert([sortedNums[i], sortedNums[left], sortedNums[right]])
                    left += 1
                }
            }
        }

        return Array(results)
    }
}

