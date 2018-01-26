//
// LeetCode
// 9. Palindrome Number
// https://leetcode.com/problems/palindrome-number
//


func isPalindrome(x int) bool {
    if x < 0 || (x > 0 && x%10 == 0) {
        return false
    }

    s := 0
    num := x
    for num > s {
        s = s * 10 + num % 10
        num /= 10
    }

    return num == s || num == s / 10
}
