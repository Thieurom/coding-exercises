//
// LeetCode
// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
//

class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        var index = s.startIndex
        var sIndex = s.startIndex
        var substring = Set<Character>()
        var maxLength = 0

        while index < s.endIndex {
            let letter = s[index]

            if !substring.contains(letter) {
                substring.insert(letter)
                maxLength = max(maxLength, substring.count)
                index = s.index(after: index)
            } else {
                let sLetter = s[sIndex]
                substring.remove(sLetter)
                sIndex = s.index(after: sIndex)
            }
        }

        return maxLength
    }
}
