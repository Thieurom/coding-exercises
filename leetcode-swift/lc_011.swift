//
// LeetCode
// 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water
//


class Solution {
    func maxArea(_ height: [Int]) -> Int {
        var maxArea = 0
        var leftIndex = 0
        var rightIndex = height.count - 1
        
        while leftIndex < rightIndex {
            let minHeight = min(height[leftIndex], height[rightIndex])
            let area = (rightIndex - leftIndex) * minHeight
            
            if area > maxArea {
                maxArea = area
            }
            
            if minHeight == height[leftIndex] {
                leftIndex += 1
            } else {
                rightIndex -= 1
            }
        }
        
        return maxArea
    }
}
