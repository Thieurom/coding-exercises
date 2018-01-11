//
// LeetCode
// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/
//


class Solution {
    func isValid(_ s: String) -> Bool {
        var parens = [Character]()

        for c in s {
            if c == "(" || c == "[" || c == "{" {
                parens.append(c)
            } else if (c == ")" && !parens.isEmpty && parens.last == "(") {
                parens.popLast()
            } else if (c == "]" && !parens.isEmpty && parens.last == "[") {
                parens.popLast()
            } else if (c == "}" && !parens.isEmpty && parens.last == "{") {
                parens.popLast()
            } else {
                return false
            }
        }

        return parens.isEmpty
    }
}
