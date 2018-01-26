//
// LeetCode
// 7. Reverse Integer
// https://leetcode.com/problems/reverse-interger
//


func reverse(x int) int {
    var digit int
    var result int

    for x != 0 {
        digit = x % 10

        if x > 0 && int32(result) > (math.MaxInt32 - int32(digit)) / 10 {
            return 0
        }

        if x < 0 && int32(result) < (math.MinInt32 - int32(digit)) / 10 {
            return 0
        }

        result = result * 10 + digit
        x /= 10
    }

    return result
}
