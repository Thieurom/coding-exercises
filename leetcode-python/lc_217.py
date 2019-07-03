#
# LeetCode
# 217. Contains Duplicate
# https://leetcode.com/problems/contains-duplicate/
#

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        if len(nums) == 0:
            return False
        
        nums_dict = {}
        for num in nums:
            count = nums_dict.get(num, 0)
            if count > 1:
                return True
            
            nums_dict[num] = count + 1
            
        return len(nums_dict.keys()) != len(nums)
