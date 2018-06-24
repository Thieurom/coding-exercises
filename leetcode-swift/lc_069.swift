//
// LeetCode
// 69. Sqrt(x)
// https://leetcode.com/problems/sqrtx/
//


class Solution {
    func mySqrt(_ x: Int) -> Int {
        var low = 1
        var high = x
        var guess: Int
        
        while low <= high {
            guess = low + (high - low) / 2
            
            if guess < x / guess {
                low = guess + 1
            } else if guess > x / guess {
                high = guess - 1
            } else {
                return guess
            }
        }
        
        return high
    }
}
