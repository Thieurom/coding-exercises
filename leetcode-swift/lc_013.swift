//
// LeetCode
// 13. Roman to Integer
// https://leetcode.com/problems/roman-to-integer/
//


class Solution {
    private enum RomanValue {
        static let M = 1000
        static let D = 500
        static let C = 100
        static let L = 50
        static let X = 10
        static let V = 5
        static let I = 1
    }

    func romanToInt(_ s: String) -> Int {
        var last = RomanValue.M
        var num: Int
        var result = 0

        for c in s {
            switch c {
            case "M":
                num = RomanValue.M
            case "D":
                num = RomanValue.D
            case "C":
                num = RomanValue.C
            case "L":
                num = RomanValue.L
            case "X":
                num = RomanValue.X
            case "V":
                num = RomanValue.V
            case "I":
                num = RomanValue.I
            default:
                return 0
            }

            result += num
            if num > last {
                result -= 2 * last
            }
            last = num
        }

        return result
    }
}
