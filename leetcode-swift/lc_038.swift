//
// LeetCode
// 38. Count and Say
// https://leetcode.com/problems/count-and-say/
//


class Solution {
    func countAndSay(_ n: Int) -> String {
        precondition(n > 0, "Input must be a positive interger.")
        
        if n == 1 {
            return "1"
        }
        
        let seq = countAndSay(n - 1)
        var currentIndex = seq.startIndex
        var num = seq[currentIndex]
        var result = ""
        var count = 1
        
        for i in 1..<seq.count {
            let nextIndex = seq.index(seq.startIndex, offsetBy: i)
            
            if seq[nextIndex] == num {
                count += 1
            } else {
                result += "\(count)\(seq[currentIndex])"
                currentIndex = nextIndex
                num = seq[currentIndex]
                count = 1
            }
        }
        
        result += "\(count)\(seq[currentIndex])"
        
        return result
    }
}
