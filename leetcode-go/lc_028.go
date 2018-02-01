//
// LeetCode
// 28. Implement strStr()
// https://leetcode.com/problems/implement-strstr/
//


func strStr(haystack string, needle string) int {
    lh := len(haystack)
    ln := len(needle)
    max := lh - ln

    for i := 0; i <= max; i++ {
        if haystack[i:i+ln] == needle {
            return i
        }
    }

    return -1
}
