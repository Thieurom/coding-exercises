#
# LeetCode
# 8. String to Integer (atoi)
# https://leetcode.com/problems/string-to-integer-atoi/
#

class Solution:
    def myAtoi(self, str: str) -> int:
        digits = []
        for c in str:
            if c == ' ':
                if len(digits) == 0:
                    continue
                else:
                    break

            if c != '-' and c != '+' and not c.isdigit():
                break

            if (c == '-' or c == '+') and len(digits) > 0:
                break

            digits.append(c)

        if len(digits) == 0:
            return 0

        num = 0
        negative = True if digits[0] == '-' else False
        min_int = -2**31
        max_int = 2**31 - 1

        for digit in digits:
            if digit == '-' or digit == '+':
                continue

            if not negative and (max_int - int(digit)) / 10 < num:
                return max_int
            if negative and (min_int + int(digit)) / 10 > -num:
                return min_int

            num = num * 10 + int(digit)

        return (-1 if negative else 1) * num
