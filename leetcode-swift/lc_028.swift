//
// LeetCode
// 28. Implement strStr()
// https://leetcode.com/problems/implement-strstr/
//


class Solution {
    func strStr(_ haystack: String, _ needle: String) -> Int {
        let hLength = haystack.count
        let nLength = needle.count
        let max = hLength - nLength

        guard nLength > 0 else { return 0 }
        guard max >= 0 else { return -1 }

        for i in 0...max {
            var j = 0
            var index = haystack.index(haystack.startIndex, offsetBy: i)

            for character in needle {
                if character == haystack[index] {
                    j += 1
                    index = haystack.index(index, offsetBy: 1)
                } else {
                    break
                }
            }

            if j == nLength {
                return i
            }
        }

        return -1
    }
}
