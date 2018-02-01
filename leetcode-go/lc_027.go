//
// LeetCode
// 27. Remove Element
// https://leetcode.com/problems/remove-element/
//


func removeElement(nums []int, val int) int {
    currentIndex := 0
    lastIndex := len(nums) - 1

    for currentIndex <= lastIndex {
        if nums[currentIndex] == val {
            nums[currentIndex] = nums[lastIndex]
            lastIndex--
        } else {
            currentIndex++
        }
    }

    return lastIndex + 1
}
