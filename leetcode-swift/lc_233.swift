class Solution {
    func countDigitOne(_ n: Int) -> Int {
        var result = 0
        var position = 1

        while position <= n {
            var cycle = n / (position * 10)

            let currentDigit = (n / position) % 10
            if currentDigit > 1 {
                cycle += 1
            }

            result += cycle * position
            if currentDigit == 1 {
                result += n % position + 1
            }

            position *= 10
        }

        return result
    }
}
