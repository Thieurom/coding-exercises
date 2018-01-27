//
// LeetCode
// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/
//


func isValid(s string) bool {
    var parens []byte

    for i := 0; i < len(s); i++ {
        c := s[i]
        l := len(parens)

        switch {
        case c == '(' || c == '[' || c == '{':
            parens = append(parens, c)
        case c == ')' && l != 0 && parens[l-1] == '(':
            parens = parens[:l-1]
        case c == ']' && l != 0 && parens[l-1] == '[':
            parens = parens[:l-1]
        case c == '}' && l != 0 && parens[l-1] == '{':
            parens = parens[:l-1]
        default:
            return false
        }
    }

    return len(parens) == 0
}
