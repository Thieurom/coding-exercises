//
// LeetCode
// 9. Palindrome Number
// https://leetcode.com/problems/palindrome-number
//


class Solution {
    func isPalindrome(_ x: Int) -> Bool {
        if x < 0 || (x != 0 && x%10 == 0) {
            return false
        }
        
        var s = 0
        var num = x
        while num > s {
            s = s * 10 + num % 10
            num /= 10
        }
        
        return num == s || num == s / 10
    }
}
