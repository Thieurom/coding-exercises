class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        max_sum = 0
        cur_sum = 0
        
        for i in range(len(nums)):
            if nums[i] == 1:
                cur_sum += 1
            else:
                max_sum = max(max_sum, cur_sum)
                cur_sum = 0
                
        return max(max_sum, cur_sum)
                
