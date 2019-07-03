#
# LeetCode
# 125. Valid Palindrome
# https://leetcode.com/problems/valid-palindrome/
#

class Solution:
    def isPalindrome(self, s: str) -> bool:
        t = [c.lower() for c in s if c.isalpha() or c.isdigit()]
        return all(t[i] == t[-(i+1)] for i in range(len(t) // 2))
