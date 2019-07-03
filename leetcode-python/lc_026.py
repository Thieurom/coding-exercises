#
# LeetCode
# 26. Remove Duplicates from Sorted Array
# https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) == 0: return 0

        write_index = 0
        for i in range(len(nums)):
            if nums[write_index] != nums[i]:
                write_index += 1
                nums[write_index] = nums[i]

        return write_index + 1
