class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        smaller = 0
        larger = len(numbers) - 1
        
        while smaller < larger:
            current_sum = numbers[smaller] + numbers[larger]
            if current_sum == target:
                break
            elif current_sum < target:
                smaller += 1
            else:
                larger -= 1
                
        return [smaller + 1, larger + 1]
