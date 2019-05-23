//
// LeetCode
// 6. ZigZag Conversion
// https://leetcode.com/problems/zigzag-conversion/
//

class Solution {
    func convert(_ s: String, _ numRows: Int) -> String {
        guard numRows > 1 && numRows < s.count else {
            return s
        }

        let distance = (numRows - 1) * 2
        var zigzag = ""

        for i in (0..<numRows) {
            var j = i

            while j < s.count {
                let index = s.index(s.startIndex, offsetBy: j)
                zigzag += String(s[index])

                if j % distance != 0 {
                    let max = distance - 2 * i
                    if max > 0 && max + j < s.count {
                        let end = s.index(index, offsetBy: max)
                        zigzag.append(s[end])
                    }
                }

                j += distance
            }
        }

        return zigzag
    }
}
