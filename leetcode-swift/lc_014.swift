//
// LeetCode
// 14. Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/
//

class Solution {
    func longestCommonPrefix(_ strs: [String]) -> String {
        if strs.isEmpty {
            return ""
        }

        let text = strs.sorted {
            $0.count < $1.count
        }

        var prefix = text.first!
        var index = 0

        while index < text.count {
            if text[index].hasPrefix(prefix) {
                index += 1
            } else {
                prefix.removeLast()
            }
        }

        return prefix
    }
}
