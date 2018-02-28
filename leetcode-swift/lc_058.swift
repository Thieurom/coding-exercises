//
// LeetCode
// 58. Length of Last Word
// https://leetcode.com/problems/length-of-last-word/
//


class Solution {
    func lengthOfLastWord(_ s: String) -> Int {   
        if s.count == 0 {
            return 0
        }
        
        var begin = 0
        var end = s.count - 1
        
        while end >= 0 {
            if s[s.index(s.startIndex, offsetBy: end)] != " " && end >= begin {
                begin = end
            }
            
            if s[s.index(s.startIndex, offsetBy: end)] == " " && end <= begin {
                break
            }
            
            end -= 1
        }
        
        return begin - end
    }
}
