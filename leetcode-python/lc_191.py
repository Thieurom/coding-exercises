class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        num_bits = 0
        
        while n > 0:
            num_bits += 1
            n &= n - 1
            
        return num_bits
        
