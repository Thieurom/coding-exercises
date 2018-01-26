//
// LeetCode
// 13. Roman to Integer
// https://leetcode.com/problems/roman-to-integer/
//


func romanToInt(s string) int {
    romanVal := map[byte]int{
        'M': 1000,
        'D': 500,
        'C': 100,
        'L': 50,
        'X': 10,
        'V': 5,
        'I': 1,
    }

    last := romanVal['M']
    result := 0

    for i := 0; i < len(s); i++ {
        if val, ok := romanVal[s[i]]; ok {
            result += val

            if val > last {
                result -= 2 * last
            }

            last = val
        } else {
            return 0
        }
    }

    return result
}
