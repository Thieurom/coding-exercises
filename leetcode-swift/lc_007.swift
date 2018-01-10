//
// LeetCode
// 7. Reverse Integer
// https://leetcode.com/problems/reverse-interger
//


class Solution {
    func reverse(_ x: Int) -> Int {
        var num = x
        var digit: Int
        var result = 0
        
        while num != 0 {
            digit = num % 10
            
            if num > 0 && Int32(result) > (Int32.max - Int32(digit)) / 10 {
                return 0
            }
            
            if num < 0 && Int32(result) < (Int32.min - Int32(digit)) / 10 {
                return 0
            }
            
            result = result * 10 + digit
            num /= 10
        }
        
        return result
    }
}
