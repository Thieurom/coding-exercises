//
// LeetCode
// 67. Add Binary
// https://leetcode.com/problems/add-binary/
//


class Solution {
    func addBinary(_ a: String, _ b: String) -> String {
        var result: String = ""
        var carry = 0
        var i = a.count - 1
        var j = b.count - 1
        
        while i >= 0 || j >= 0 {
            var sum = carry
            
            if i >= 0 {
                let aIndex = a.index(a.startIndex, offsetBy: i)
                sum += Int(String(a[aIndex]))!
            }
            
            if j >= 0 {
                let bIndex = b.index(b.startIndex, offsetBy: j)
                sum += Int(String(b[bIndex]))!
            }
            
            result = String(sum % 2) + result
            carry = sum / 2

            i -= 1
            j -= 1
        }
        
        if carry > 0 {
            result = String(carry) + result
        }
        
        return result
    }
}
