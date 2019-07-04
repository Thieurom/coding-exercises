#
# LeetCode
# 38. Count and Say
# https://leetcode.com/problems/count-and-say/
#

class Solution:
    def countAndSay(self, n: int) -> str:
        # helper
        def next_number(s: str) -> str:
            i = 0
            res = []

            while i < len(s):
                count = 1
                j = i + 1
                while j < len(s) and s[i] == s[j]:
                    count += 1
                    j += 1

                res.append(str(count) + s[i])
                i = j

            return ''.join(res)

        s = '1'
        for _ in range(1, n):
            s = next_number(s)

        return s
